#include "memory.h"
#include "os.h"
#include "riscv.h"

extern void uart_init();
extern void task_init();
extern void trap_init();
extern void plic_init();
extern void timer_init();
extern void task_init();
extern void schedule();

void kernel_main() {
    uart_init();
    trap_init();
    plic_init();
    timer_init();
    task_init();

    set_global_interrupt(1);
    printf("not go here");
    
    while (1) {
    };
}