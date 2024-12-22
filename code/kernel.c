#include "memory.h"
#include "os.h"

extern void uart_init();
extern void task_init();
extern void schedule();

void kernel_main() {
    uart_init();
    task_init();
    schedule();
    
    printf("not go here");
    while (1) {
    };
}