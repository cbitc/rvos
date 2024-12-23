#include "os.h"
#include "platform.h"
#include "riscv.h"
#include "types.h"

#define TIMER_INTERVAL 100000L

static u64 tick = 0;

static void timer_load(u64 interval) {
    u32 hart = hart_id();
    *(u64 *)CLINT_MTIMECMP(hart) = (*(u64 *)CLINT_MTIME) + interval;
}

void timer_init() {
    timer_load(TIMER_INTERVAL);

    w_mie(r_mie() | MIE_MTIE);

    w_mstatus(r_mstatus() | MSTATUS_MIE);
}

void timer_handle() {
    tick++;
    timer_load(TIMER_INTERVAL);
}