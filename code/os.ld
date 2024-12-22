OUTPUT_ARCH("riscv")

ENTRY(_start)


MEMORY
{
    ram (wax!ri) : ORIGIN = 0x80000000,LENGTH = 128M
}

SECTIONS
{
    .text : {
        PROVIDE(TEXT_START = .);
        build/start.o(.text)
        *(.text .text.*)
        PROVIDE(TEXT_END = .);
    } >ram

    .rodata : {
        PROVIDE(RODATA_START = .);
        *(.rodata .rodata.*)
        PROVIDE(RODATA_END = .);
    } >ram

    .data : {
        . = ALIGN(4096);
        PROVIDE(DATA_START = .);
        *(.sdata .sdata.*)
        *(.data .data.*)
        PROVIDE(DATA_END = .);
    } >ram

    .bss : {
        PROVIDE(BSS_START = .);
        *(.sbss .sbss.*)
        *(.bss .bss.* )
        *(COMMON)
        PROVIDE(BSS_END = .);
    } >ram


    PROVIDE(MEMORY_START = ORIGIN(ram));
    PROVIDE(MEMORY_END = ORIGIN(ram) + LENGTH(ram));
    PROVIDE(HEAP_START = BSS_END);
    PROVIDE(HEAP_SIZE = MEMORY_END - HEAP_START);
}