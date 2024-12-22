#include "os.h"

void user_task1() {
    printf("task1\n");
    u32 counter = 0;
    while (1) {
        printf("task1 counter: %d\n", counter++);
        task_delay(1000);
        task_yield();
    }
}

void user_task2() {
    printf("task2\n");
    u32 counter = 0;
    while (1) {
        printf("task2 counter: %d\n", counter++);
        task_delay(1000);
        task_yield();
    }
}