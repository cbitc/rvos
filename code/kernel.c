#include "memory.h"
#include "os.h"

extern void uart_init();

void kernel_main() {
    uart_init();
    printf("hello,rvos!\n");
    printf("memstart:%p,memend:%p\nheapstart:%p,heapsize:%p\n", memory_start,
           memory_end, heap_start, heap_size);
    while (1) {
    };
}