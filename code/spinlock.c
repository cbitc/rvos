#include "include/spinlock.h"
#include "include/process.h"

static void
push_off() {
    int prev = intr_get();
    intr_off();
    cpu_t *c = mycpu();
    if (c->nr_off == 0) {
        c->is_intr_on = prev;
    }
    c->nr_off++;
}

static void
pop_off() {
    cpu_t *c = mycpu();
    c->nr_off--;
    if (c->nr_off == 0 && c->is_intr_on) {
        intr_on();
    }
}

void
spinlock_init(spinlock_t *lock) {
    lock->locked = 0;
    lock->cpu = NULL;
}

void
spinlock_aquire(spinlock_t *lock) {
    push_off();
    assert(lock->cpu != mycpu());
    while (__sync_lock_test_and_set(&lock->locked, 1) == 1)
        ;
    __sync_synchronize();
    lock->cpu = mycpu();
}

void
spinlock_release(spinlock_t *lock) {
    assert(intr_get() == 0);
    lock->cpu = NULL;
    __sync_synchronize();
    __sync_lock_release(&lock->locked);
    pop_off();
}
