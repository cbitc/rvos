#include "riscv.h"

u32 inline hart_id() {
    reg_t v;
    asm volatile("mv %0,tp " : "=r"(v));
    return v;
}

void inline w_mtvec(reg_t v) {
    asm volatile("csrw mtvec,%0" : : "r"(v));
}

reg_t inline r_mscratch() {
    reg_t x;
    asm volatile("csrr %0,mscratch" : "=r"(x));
    return x;
}

void inline w_mscratch(reg_t v) {
    asm volatile("csrw mscratch,%0" ::"r"(v));
}

reg_t r_mstatus() {
    reg_t x;
    asm volatile("csrr %0,mstatus" : "=r"(x));
    return x;
}

void w_mstatus(reg_t v) {
    asm volatile("csrw mstatus,%0" ::"r"(v));
}

reg_t r_mie() {
    reg_t x;
    asm volatile("csrr %0,mie" : "=r"(x));
    return x;
}

void w_mie(reg_t v) {
    asm volatile("csrw mie,%0" ::"r"(v));
}