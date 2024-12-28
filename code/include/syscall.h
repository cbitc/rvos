#ifndef __SYSCALL_H
#define __SYSCALL_H

#include "os.h"

typedef enum syscall_number_e {
    SYS_TEST = 0,
    SYS_OSMAGIC = 1,
    SYS_HARTID = 10,
}syscall_number_t;


#endif