#include "os.h"
#include "platform.h"
#include "riscv.h"

extern void trap_entry();
extern void timer_handle();

void trap_init() {
    w_mtvec((reg_t)trap_entry);
}

static void external_interrupt_handle() {
    int irq = plic_claim();
    if (irq == UART0_IRQ) {
        char c = (char)uart_getc();
        printf("input:%c\n", c);
    } else {
        panic("unknown irq \n");
    }
    plic_complete(irq);
}

void trap_handle(reg_t cause) {
    u32 kind = cause & 0x80000000;
    u32 code = cause & 0x7FFFFFFF;
    if (kind) {
        if (code == 11) {
            external_interrupt_handle();
        } else if (code == 7) {
            timer_handle();
        } else {
            panic("unknow intr code\n");
        }
    } else {
        printf("exception!!!: %d\n", code);
        panic("I dont known how to do!\n");
    }
}
