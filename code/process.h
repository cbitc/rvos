#ifndef __PROCESS_H
#define __PROCESS_H

#include "os.h"
#include "riscv.h"
#include "types.h"
#include "trap.h"

typedef struct process_s {
    trap_frame_t* trap_frame;
    
}process_t;

#endif