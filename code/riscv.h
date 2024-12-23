#ifndef __RISCV_H
#define __RISCV_H

#include "types.h"

#define MIE_MEIE (1 << 11)
#define MIE_MTIE (1 << 7)
#define MSTATUS_MIE (1 << 3)

typedef u32 reg_t;

typedef struct context_s {
    reg_t ra;
    reg_t sp;
    reg_t gp;
    reg_t tp;
    reg_t t0,t1,t2;
    reg_t s0,s1;
    reg_t a0,a1,a2,a3,a4,a5,a6,a7;
    reg_t s2,s3,s4,s5,s6,s7,s8,s9,s10,s11;
    reg_t t3,t4,t5,t6;
}context_t;

u32 hart_id();


reg_t r_mscratch();
void w_mscratch(reg_t v);

void w_mtvec(reg_t v);

reg_t r_mstatus();
void w_mstatus(reg_t v);

reg_t r_mie();
void w_mie(reg_t v);


#endif