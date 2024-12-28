#ifndef __RISCV_H
#define __RISCV_H

#include "types.h"

#define MIE_MEIE (1 << 11)
#define MIE_MTIE (1 << 7)
#define MIE_MSIE (1 << 3)
#define MSTATUS_MIE (1 << 3)

typedef u32 reg_t;

reg_t r_mhartid();

reg_t r_tp();

reg_t r_mscratch();
void w_mscratch(reg_t v);

void w_mtvec(reg_t v);

reg_t r_mstatus();
void w_mstatus(reg_t v);

reg_t r_mie();
void w_mie(reg_t v);

reg_t r_mcause();


#endif