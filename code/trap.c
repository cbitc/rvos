#include "trap.h"
#include "os.h"
#include "platform.h"
#include "riscv.h"

extern void trap_entry();
extern void trap_exit();
extern void timer_handle();

static trap_frame_t trap_frame0;

void
trap_init() {
    w_mtvec((reg_t)trap_entry);
    w_mscratch((reg_t)&trap_frame0);
}

static void
external_interrupt_handle() {
    int irq = plic_claim();
    if (irq == UART0_IRQ) {
        char c = (char)uart_getc();
        printf("input:%c\n", c);
    } else {
        panic("unknown irq \n");
    }
    plic_complete(irq);
}

void inline intr_on() {
    w_mstatus(r_mstatus() | MSTATUS_MIE);
}

void inline intr_off() {
    w_mstatus(r_mstatus() & ~MSTATUS_MIE);
}

void
trap_return() {
    trap_exit();
}

void
trap_handle() {
    reg_t cause = r_mcause();
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
    trap_return();
}
