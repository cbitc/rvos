#define REGSIZE 4

.text
.global swtch
swtch:
    sw    ra,0*REGSIZE(a0)
    sw    sp,1*REGSIZE(a0)
    sw    s0,2*REGSIZE(a0)
    sw    s1,3*REGSIZE(a0)
    sw    s2,4*REGSIZE(a0)
    sw    s3,5*REGSIZE(a0)
    sw    s4,6*REGSIZE(a0)
    sw    s5,7*REGSIZE(a0)
    sw    s6,8*REGSIZE(a0)
    sw    s7,9*REGSIZE(a0)
    sw    s8,10*REGSIZE(a0)
    sw    s9,11*REGSIZE(a0)
    sw    s10,12*REGSIZE(a0)
    sw    s11,13*REGSIZE(a0)

    lw    ra,0*REGSIZE(a1)
    lw    sp,1*REGSIZE(a1)
    lw    s0,2*REGSIZE(a1)
    lw    s1,3*REGSIZE(a1)
    lw    s2,4*REGSIZE(a1)
    lw    s3,5*REGSIZE(a1)
    lw    s4,6*REGSIZE(a1)
    lw    s5,7*REGSIZE(a1)
    lw    s6,8*REGSIZE(a1)
    lw    s7,9*REGSIZE(a1)
    lw    s8,10*REGSIZE(a1)
    lw    s9,11*REGSIZE(a1)
    lw    s10,12*REGSIZE(a1)
    lw    s11,13*REGSIZE(a1)

    ret

.end