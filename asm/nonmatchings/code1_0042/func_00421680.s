.section .text
.set noat
.set noreorder
glabel func_00421680
    /* 321680 00421680 D6FF0324 */  addiu      $3, $0, -0x2A
    /* 321684 00421684 0C000000 */  syscall    0 /* handwritten instruction */
    /* 321688 00421688 0800E003 */  jr         $31
    /* 32168C 0042168C 00000000 */   nop
.size func_00421680, 0x10
