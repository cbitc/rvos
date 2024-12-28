#include "os.h"

extern void yield();
extern void task_create(void (*task)(void));

static void
user_task1() {
    printf("task1\n");
    u32 counter = 0;
    while (1) {
        printf("task1 : %d\n", counter++);
    }
}

static void
user_task2() {
    printf("task2\n");
    u32 counter = 0;
    while (1) {
        printf("task2 : %d\n", counter++);
    }
}

void
task_init() {
    task_create((void *)user_task1);
    task_create((void *)user_task2);
}