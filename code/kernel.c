#include "memory.h"
#include "os.h"
#include "riscv.h"
#include "trap.h"

extern void uart_init();
extern void trap_init();
extern void plic_init();
extern void timer_init();
extern void task_init();
extern void scheduler();

void
kernel_main() {
    uart_init();
    trap_init();
    plic_init();
    timer_init();
    task_init();
    scheduler();
    panic("not go here!!!\n");
}