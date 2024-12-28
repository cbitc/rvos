#ifndef __SPINLOCK_H
#define __SPINLOCK_H

#include "process.h"

typedef struct spinlock_s {
    int locked;
    cpu_t* cpu;
}spinlock_t;

void spinlock_init(spinlock_t* lock);

void spinlock_aquire(spinlock_t* lock);
void spinlock_release(spinlock_t* lock);

#endif