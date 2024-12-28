#include "os.h"

#define UART_REG(reg) ((volatile u8 *)(UART0 + reg))

#define UART_READ_REG(reg) (*(UART_REG(reg)))
#define UART_WRITE_REG(reg, v) (*(UART_REG(reg)) = (v))

#define LSR_RX_READY (1 << 0)
#define LSR_TX_IDLE (1 << 5)

#define RHR 0 // Receive Holding Register (read mode)
#define THR 0 // Transmit Holding Register (write mode)
#define DLL 0 // LSB of Divisor Latch (write mode)
#define IER 1 // Interrupt Enable Register (write mode)
#define DLM 1 // MSB of Divisor Latch (write mode)
#define FCR 2 // FIFO Control Register (write mode)
#define ISR 2 // Interrupt Status Register (read mode)
#define LCR 3 // Line Control Register
#define MCR 4 // Modem Control Register
#define LSR 5 // Line Status Register
#define MSR 6 // Modem Status Register
#define SPR 7 // ScratchPad Register

void
uart_init() {
    UART_WRITE_REG(IER, 0x00);
    u8 lcr = UART_READ_REG(LCR);
    UART_WRITE_REG(LCR, lcr | (1 << 7));
    UART_WRITE_REG(DLL, 0x03);
    UART_WRITE_REG(DLM, 0x00);

    lcr = 0;
    UART_WRITE_REG(LCR, lcr | (3 << 0));

    u8 ier = UART_READ_REG(IER);
    UART_WRITE_REG(IER, ier | (1 << 0));
}

void
uart_putc(char ch) {
    while ((UART_READ_REG(LSR) & LSR_TX_IDLE) == 0)
        ;
    UART_WRITE_REG(THR, ch);
}

void
uart_puts(char *s) {
    while (*s) {
        uart_putc(*s++);
    }
}

int
uart_getc() {
    while ((UART_READ_REG(LSR) & LSR_RX_READY) == 0)
        ;
    return UART_READ_REG(RHR);
}
