#include "include/riscv.h"

inline reg_t
r_mhartid() {
    reg_t x;
    asm volatile("csrr %0,mhartid" : "=r"(x));
    return x;
}

inline reg_t
r_tp() {
    reg_t x;
    asm volatile("mv %0,tp" : "=r"(x));
    return x;
}

inline void
w_mtvec(reg_t v) {
    asm volatile("csrw mtvec,%0" : : "r"(v));
}

inline reg_t
r_mscratch() {
    reg_t x;
    asm volatile("csrr %0,mscratch" : "=r"(x));
    return x;
}

inline void
w_mscratch(reg_t v) {
    asm volatile("csrw mscratch,%0" ::"r"(v));
}

inline reg_t
r_mstatus() {
    reg_t x;
    asm volatile("csrr %0,mstatus" : "=r"(x));
    return x;
}

inline void
w_mstatus(reg_t v) {
    asm volatile("csrw mstatus,%0" ::"r"(v));
}

inline reg_t
r_mie() {
    reg_t x;
    asm volatile("csrr %0,mie" : "=r"(x));
    return x;
}

inline void
w_mie(reg_t v) {
    asm volatile("csrw mie,%0" ::"r"(v));
}

inline reg_t
r_mcause() {
    reg_t x;
    asm volatile("csrr %0,mcause" : "=r"(x) :);
    return x;
}
