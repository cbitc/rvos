#include "riscv.h"

reg_t inline r_mscratch() {
    asm volatile("csrr a0,mscratch");
}

void inline w_mscratch(reg_t v) {
    asm volatile("csrw mscratch,a0");
}