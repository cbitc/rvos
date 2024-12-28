#include "include/os.h"
#include "include/usys.h"

extern void yield();
extern void task_create(void (*task)(void));

static void
idle_task() {
    while (true) {
        yield();
    }
}

static void
user_task1() {
    while (true) {
        printf("user task1\n");
    }
}

static void
user_task2() {
    while (true) {
    }
}

void
task_init() {
    task_create((void *)idle_task);
    task_create((void *)user_task1);
    // task_create((void *)user_task2);
}