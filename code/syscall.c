#include "include/syscall.h"
#include "include/os.h"
#include "include/process.h"

u32
sys_os_magic() {
    return 0x20241111;
}

u32
sys_test(u32 number) {
    return number;
}

void
syscall_handle(trap_frame_t *context) {
    u32 call_nr = context->a7;
    switch (call_nr) {
    case SYS_TEST:
        context->a0 = sys_test(context->a0);
        break;
    case SYS_OSMAGIC:
        context->a0 = sys_os_magic();
        break;
    default:
        panic("unknown syscall number %d\n", call_nr);
    }
    context->pc += 4;
}
