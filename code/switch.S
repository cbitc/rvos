#define STORE sw
#define LOAD  lw
#define REGSIZE 4


.macro save_regs base
    STORE ra,0*REGSIZE(\base)
    STORE sp,1*REGSIZE(\base)
    STORE gp,2*REGSIZE(\base)
    STORE tp,3*REGSIZE(\base)
    STORE t0,4*REGSIZE(\base)
    STORE t1,5*REGSIZE(\base)
    STORE t2,6*REGSIZE(\base)
    STORE s0,7*REGSIZE(\base)
    STORE s1,8*REGSIZE(\base)
    STORE a0,9*REGSIZE(\base)
    STORE a1,10*REGSIZE(\base)
    STORE a2,11*REGSIZE(\base)
    STORE a3,12*REGSIZE(\base)
    STORE a4,13*REGSIZE(\base)
    STORE a5,14*REGSIZE(\base)
    STORE a6,15*REGSIZE(\base)
    STORE a7,16*REGSIZE(\base)
    STORE s2,17*REGSIZE(\base)
    STORE s3,18*REGSIZE(\base)
    STORE s4,19*REGSIZE(\base)
    STORE s5,20*REGSIZE(\base)
    STORE s6,21*REGSIZE(\base)
    STORE s7,22*REGSIZE(\base)
    STORE s8,23*REGSIZE(\base)
    STORE s9,24*REGSIZE(\base)
    STORE s10,25*REGSIZE(\base)
    STORE s11,26*REGSIZE(\base)
    STORE t3,27*REGSIZE(\base)
    STORE t4,28*REGSIZE(\base)
    STORE t5,29*REGSIZE(\base)
    STORE t6,30*REGSIZE(\base)
.endm

.macro load_regs base
    LOAD ra,0*REGSIZE(\base)
    LOAD sp,1*REGSIZE(\base)
    LOAD gp,2*REGSIZE(\base)
    LOAD tp,3*REGSIZE(\base)
    LOAD t0,4*REGSIZE(\base)
    LOAD t1,5*REGSIZE(\base)
    LOAD t2,6*REGSIZE(\base)
    LOAD s0,7*REGSIZE(\base)
    LOAD s1,8*REGSIZE(\base)
    LOAD a0,9*REGSIZE(\base)
    LOAD a1,10*REGSIZE(\base)
    LOAD a2,11*REGSIZE(\base)
    LOAD a3,12*REGSIZE(\base)
    LOAD a4,13*REGSIZE(\base)
    LOAD a5,14*REGSIZE(\base)
    LOAD a6,15*REGSIZE(\base)
    LOAD a7,16*REGSIZE(\base)
    LOAD s2,17*REGSIZE(\base)
    LOAD s3,18*REGSIZE(\base)
    LOAD s4,19*REGSIZE(\base)
    LOAD s5,20*REGSIZE(\base)
    LOAD s6,21*REGSIZE(\base)
    LOAD s7,22*REGSIZE(\base)
    LOAD s8,23*REGSIZE(\base)
    LOAD s9,24*REGSIZE(\base)
    LOAD s10,25*REGSIZE(\base)
    LOAD s11,26*REGSIZE(\base)
    LOAD t3,27*REGSIZE(\base)
    LOAD t4,28*REGSIZE(\base)
    LOAD t5,29*REGSIZE(\base)
    LOAD t6,30*REGSIZE(\base)
.endm


.text
.global switch_to
.balign 4
switch_to:
    csrrw     t6,mscratch,t6
    save_regs t6
    mv        t5,t6
    csrr      t6,mscratch
    STORE     t6,30*REGSIZE(t5)
    
    csrw      mscratch,a0
    mv        t6,a0
    load_regs t6

    ret
    
.end