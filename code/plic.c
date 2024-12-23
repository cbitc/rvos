#include "platform.h"
#include "riscv.h"

int plic_claim() {
    int hart = hart_id();
    int irq = *(u32 *)PLIC_MCLAIM(hart);
    return irq;
}

void plic_complete(int irq) {
    int hart = hart_id();
    *(u32 *)PLIC_MCOMPLETE(hart) = irq;
}

void plic_init() {
    u32 hart = hart_id();
    *(u32 *)PLIC_PRIORITY(UART0_IRQ) = 1;
    *(u32 *)PLIC_MENABLE(hart, UART0_IRQ) = 1 << (UART0_IRQ % 32);
    *(u32 *)PLIC_MTHRESHOLD(hart) = 0;

    w_mie(r_mie() | MIE_MEIE);
    w_mstatus(r_mstatus() | MSTATUS_MIE);
}
