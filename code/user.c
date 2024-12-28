#include "include/os.h"

extern void yield();
extern void task_create(void (*task)(void));

static int nrtwc = 0;

static void
idle_task() {
    while (true) {
        printf("idle ... %d\n", nrtwc);
        yield();
    }
}

static void
user_task1() {
    while (true) {
        printf("hello,this is user task1\n");
    }
}

static void
user_task2() {
    while (true) {
        printf("hello,this is user task2\n");
    }
}

void
task_init() {
    task_create((void *)idle_task);
    task_create((void *)user_task1);
    task_create((void *)user_task2);
}