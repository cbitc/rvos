#ifndef __PLATFORM_H
#define __PLATFORM_H


#define MAXNR_CPU 8

#define UART0 0x10000000L


#define UART0_IRQ 10
#define PLIC_BASE 0x0C000000L
#define PLIC_PRIORITY(id) (PLIC_BASE + (id) * 4)
#define PLIC_PENDING(id) (PLIC_BASE + 0x1000 + ((id) / 32) * 4)
#define PLIC_MENABLE(hart, id) (PLIC_BASE + 0x2000 + (hart) * 0x80 + ((id) / 32) * 4)
#define PLIC_MTHRESHOLD(hart) (PLIC_BASE + 0x200000 + (hart) * 0x1000)
#define PLIC_MCLAIM(hart) (PLIC_BASE + 0x200004 + (hart) * 0x1000)
#define PLIC_MCOMPLETE(hart) (PLIC_BASE + 0x200004 + (hart) * 0x1000)

#define CLINT_BASE 0x2000000L
#define CLINT_MTIME (CLINT_BASE + 0xBFF8)
#define CLINT_MTIMECMP(hart) (CLINT_BASE + 0x4000 + (hart) * 8)

int plic_claim();
void plic_complete();


void uart_putc(char ch);
void uart_puts(char *s);
int uart_getc();


#endif