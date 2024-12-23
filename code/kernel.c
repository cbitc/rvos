#include "memory.h"
#include "os.h"

extern void uart_init();
extern void task_init();
extern void trap_init();
extern void plic_init();
extern void schedule();

void kernel_main() {
    uart_init();
    task_init();
    trap_init();
    plic_init();

    printf("not go here");
    while (1) {
    };
}