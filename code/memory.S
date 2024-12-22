.section .rodata
.global memory_start
memory_start: .word MEMORY_START

.global memory_end
memory_end: .word MEMORY_END

.global heap_start
heap_start: .word HEAP_START

.global heap_size 
heap_size: .word HEAP_SIZE