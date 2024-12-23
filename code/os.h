#ifndef __OS_H
#define __OS_H

#include "types.h"
#include "platform.h"

int printf(const char *s, ...);
void panic(char *s);

void task_yield();
void task_delay(u32 ms);

#endif