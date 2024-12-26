#ifndef __PROCESS_H
#define __PROCESS_H

#include "os.h"
#include "riscv.h"
#include "types.h"
#include "trap.h"

#define PROC_MAGIC 0x20241111
#define STACK_SIZE 1024

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

#endif