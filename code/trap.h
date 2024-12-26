#ifndef __TRAP_H
#define __TRAP_H

#include "riscv.h"

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

void intr_on();
void intr_off();

#endif