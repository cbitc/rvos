#ifndef __PROCESS_H
#define __PROCESS_H

#include "os.h"

#define PROC_MAGIC 0x20241111
#define STACK_SIZE 1024

typedef struct trap_frame_s {
    reg_t ra;
    reg_t sp;
    reg_t gp;
    reg_t tp;
    reg_t t0,t1,t2;
    reg_t s0,s1;
    reg_t a0,a1,a2,a3,a4,a5,a6,a7;
    reg_t s2,s3,s4,s5,s6,s7,s8,s9,s10,s11;
    reg_t t3,t4,t5,t6;
    reg_t pc;
}trap_frame_t;

typedef struct switch_frame_s {
    reg_t ra;
    reg_t sp;
    reg_t s0,s1,s2,s3,s4,s5,s6,s7,s8,s9,s10,s11;
}switch_frame_t;


typedef enum process_state_e {
    READY = 0,
    RUNNING = 1,
    BLOCK = 2,
}process_state_t;

typedef struct process_s {
    trap_frame_t trap_frame;
    switch_frame_t switch_frame;
    process_state_t state;
    u32 magic;
    u8 stack[STACK_SIZE];
}process_t;

typedef struct cpu_s {
    switch_frame_t scheduler_point;
    process_t* cur_proc;
    int nr_off;
    bool is_intr_on; 
}cpu_t;

cpu_t* mycpu();
process_t* myproc();

#endif