#ifndef __OS_H
#define __OS_H

#include "types.h"
#include "platform.h"

extern void uart_putc(char ch);
extern void uart_puts(char *s);

int printf(const char *s, ...);
void panic(char *s);

#endif