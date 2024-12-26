#include "memory.h"
#include "os.h"
#include "riscv.h"
#include "trap.h"

extern void uart_init();
extern void trap_init();
extern void plic_init();
extern void timer_init();

void
kernel_main() {
    uart_init();
    trap_init();
    plic_init();
    timer_init();
    intr_on();
    while (true)
        ;
    panic("not go here!!!\n");
}