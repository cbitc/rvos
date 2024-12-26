#ifndef __OS_H
#define __OS_H

#include "types.h"
#include "platform.h"

#define assert(expr)                                                           \
    if (expr)                                                                  \
        ;                                                                      \
    else                                                                       \
        assertion_failure(#expr)


int printf(const char *s, ...);

void assertion_failure(char* expr);
void panic(const char *s,...);




#endif