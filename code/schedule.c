#include "os.h"
#include "riscv.h"

#define MAXNR_TASK 8
#define TASK_STACK_SIZE 1024

static context_t task0_ctx;

static context_t task_ctxs[MAXNR_TASK];
static u8 __attribute__((aligned(16))) task_stack[MAXNR_TASK][TASK_STACK_SIZE];
static int task_sn = -1;
static int task_nr = 0;

extern void switch_to(context_t *next);
extern void user_task1();
extern void user_task2();

static void task_create(void *target) {
    context_t *ctx = task_ctxs + task_nr;
    ctx->pc = (reg_t)target;
    ctx->sp = (reg_t)(task_stack[task_nr]) + TASK_STACK_SIZE - 1;
    ++task_nr;
}

void schedule() {
    task_sn = (task_sn + 1) % task_nr;
    context_t *next_ctx = task_ctxs + task_sn;
    asm volatile("csrw mscratch,%0" : "=r"(next_ctx) :);
}

void task_init() {
    task_create(user_task1);
    task_create(user_task2);
    w_mscratch((reg_t)&task0_ctx);
}

void task_delay(u32 ms) {
    ms *= 100000;
    while (ms--)
        ;
}

void task_yield() {
    schedule();
}
