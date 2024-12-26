#include "schedule.h"
#include "os.h"
#include "platform.h"
#include "riscv.h"

#define MAXNR_TASK 8
#define TASK_STACK_SIZE 1024

static cpu_t cpus[MAXNR_CPU];
static process_t procs[MAXNR_TASK];
static int proc_nr = 0;

extern void swtch(switch_frame_t *prev, switch_frame_t *next);
extern void trap_return();

extern void user_task1();
extern void user_task2();

static void
task_create(void *target) {
    if (proc_nr >= MAXNR_TASK) {
        panic("out of number of task!\n");
    }

    process_t *p = procs + proc_nr;
    u32 stack_ptr = (u32)p + sizeof(process_t) - 1;
    p->magic = PROC_MAGIC;
    p->state = READY;
    p->switch_frame.ra = (reg_t)trap_return;
    p->switch_frame.sp = (reg_t)stack_ptr;
    p->trap_frame.pc = (reg_t)target;
    p->trap_frame.sp = stack_ptr;

    proc_nr++;
}

inline reg_t
cpuid() {
    return hart_id();
}

inline cpu_t *
mycpu() {
    return cpus + cpuid();
}

inline process_t *
myproc() {
    return mycpu()->cur_proc;
}

void
scheduler() {
    cpu_t *cpu = mycpu();
    while (true) {
        process_t *next = NULL;
        for (int i = 0; i < proc_nr; i++) {
            process_t *p = procs + i;
            if (p->state == READY) {
                next = p;
            }

            if (next) {
                assert(next->magic == PROC_MAGIC);
                next->state = RUNNING;
                cpu->cur_proc = next;
                w_mscratch((reg_t)&next->trap_frame);
                swtch(&cpu->scheduler_point, &next->switch_frame);
                cpu->cur_proc = NULL;
                next = NULL;
            }
        }
    }
}

void
sched() {
    cpu_t *cpu = mycpu();
    cpu->cur_proc->state = READY;
    swtch(&cpu->cur_proc->switch_frame, &cpu->scheduler_point);
}

void
yield() {
    cpu_t *cpu = mycpu();
    cpu->cur_proc->state = READY;
    swtch(&cpu->cur_proc->switch_frame, &cpu->scheduler_point);
}

void
task_init() {
    static process_t proc0;
    cpu_t *cpu = mycpu();
    cpu->cur_proc = &proc0;
    task_create((void *)user_task1);
    task_create((void *)user_task2);
}
