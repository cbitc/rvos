#include "include/usys.h"

inline static reg_t
syscall0(reg_t number) {
    reg_t res = 0;
    asm volatile("mv a7,%1\r\n"
                 "ecall\r\n"
                 "mv %0,a0\r\n"
                 : "=r"(res)
                 : "r"(number));
    return res;
}

inline static reg_t
syscall1(reg_t number, reg_t arg1) {
    reg_t res = 0;
    asm volatile("mv a7,%1\r\n"
                 "mv a0,%2\r\n"
                 "ecall\r\n"
                 "mv %0,a0\r\n"
                 : "=r"(res)
                 : "r"(number), "r"(arg1));
    return res;
}

u32
get_osmagic() {
    return syscall0(SYS_OSMAGIC);
}

u32
call_test(u32 number) {
    return syscall1(SYS_TEST, number);
}