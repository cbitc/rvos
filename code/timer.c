#include "os.h"
#include "platform.h"
#include "riscv.h"
#include "types.h"

#define TIMER_INTERVAL 1000000L

static u64 tick = 0;

extern void sched();

static void
timer_load(u64 interval) {
    u32 hart = hart_id();
    *(u64 *)CLINT_MTIMECMP(hart) = (*(u64 *)CLINT_MTIME) + interval;
}

void
timer_init() {
    timer_load(TIMER_INTERVAL);
    w_mie(r_mie() | MIE_MTIE);
}

void
timer_handle() {
    tick++;
    timer_load(TIMER_INTERVAL);
    sched();
}