#ifndef __OS_H
#define __OS_H

#include "types.h"
#include "platform.h"
#include "riscv.h"

#define assert(expr)                                                           \
    if (expr)                                                                  \
        ;                                                                      \
    else                                                                       \
        assertion_failure(#expr)


int printf(const char *s, ...);

void assertion_failure(char* expr);
void panic(const char *s,...);


u32 hart_id();

void intr_on();
void intr_off();

int intr_get();


#endif