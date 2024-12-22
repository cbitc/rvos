CROSS_COMPILE := riscv64-unknown-elf-

CC := ${CROSS_COMPILE}gcc
CFLAGS += -nostdlib -fno-builtin -g -Wall
CFLAGS += -march=rv32g -mabi=ilp32

QEMU := qemu-system-riscv32
QFLAGS := -nographic -smp 1 -machine virt -bios none

GDB := gdb-multiarch
OBJCOPY := ${CROSS_COMPILE}objcopy
OBJDUMP := ${CROSS_COMPILE}objdump
LDFLAGS := -T os.ld

OUTPUT_PATH := build

SRCS_C := \
kernel.c \
uart.c \
printf.c \


SRCS_S := \
start.S \
memory.S

OBJS_S := $(addprefix ${OUTPUT_PATH}/,$(patsubst %.S,%.o,${SRCS_S}))
OBJS_C := $(addprefix ${OUTPUT_PATH}/,$(patsubst %.c,%.o,${SRCS_C}))
OBJS := ${OBJS_C} ${OBJS_S}


ELF := ${OUTPUT_PATH}/os.elf
BIN := ${OUTPUT_PATH}/os.bin


.PHONY: clangd
clangd:
	@bear -- make all

.PHONY: all
all: ${OUTPUT_PATH} ${ELF}

${OUTPUT_PATH}:
	@echo ${OBJS}
	@mkdir -p $@

${ELF}: ${OBJS}
	${CC} ${CFLAGS} ${LDFLAGS} -o ${ELF} $^
	${OBJCOPY} -O binary ${ELF} ${BIN}

${OUTPUT_PATH}/%.o: %.S
	${CC} ${CFLAGS} -c -o $@ $<

${OUTPUT_PATH}/%.o: %.c
	${CC} ${CFLAGS} -c -o $@ $<


.PHONY: run
run: all
	@${QEMU} -M ? | grep virt >/dev/null || exit
	@echo "Press Ctrl-A and then X to exit QEMU"
	@echo "------------------------------------"
	@${QEMU} ${QFLAGS} -kernel ${ELF}

.PHONY: debug
debug: all
	@echo "Press Ctrl-A and then X to exit QEMU"
	@echo "------------------------------------"
	@${QEMU} ${QFLAGS} -kernel ${ELF} -s -S 

.PHONY: code
code: all
	@${OBJDUMP} -S ${ELF} > ${OUTPUT_PATH}/elftext.txt && nm ${ELF} > ${OUTPUT_PATH}/elfsymbol.txt

.PHONY: clean
clean:
	@rm -rf ${OUTPUT_PATH}


