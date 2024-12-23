#define MAXNR_CPU 8

.equ STACK_SIZE,1024
.global _start

.text
_start:
	csrr t0 , mhartid
	mv 	 tp , t0
	bnez t0 , park

    slli t0 , t0 , 10
	la   sp , stacks + STACK_SIZE
    add  sp , sp , t0 

    j    kernel_main
park:
	wfi
	j park

.balign 16
stacks:
	.skip MAXNR_CPU * STACK_SIZE
	.end