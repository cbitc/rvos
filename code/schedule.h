#ifndef __SCHEDULE_H
#define __SCHEDULE_H

#include "riscv.h"
#include "trap.h"
#include "process.h"


typedef struct cpu_s {
    switch_frame_t scheduler_point;
    process_t* cur_proc;
}cpu_t;

reg_t cpuid();
cpu_t* mycpu();
process_t* myproc();
void yield();

#endif