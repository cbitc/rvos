#include "os.h"

extern void yield();

void user_task1() {
    printf("task1\n");
    u32 counter = 0;
    while (1) {
        printf("task1 : %d\n", counter++);
    }
}

void user_task2() {
    printf("task2\n");
    u32 counter = 0;
    while (1) {
        printf("task2 : %d\n", counter++);
    }
}