.section .text
.set noat
.set noreorder
glabel func_00421610
    /* 321610 00421610 23000324 */  addiu      $3, $0, 0x23
    /* 321614 00421614 0C000000 */  syscall    0 /* handwritten instruction */
    /* 321618 00421618 0800E003 */  jr         $31
    /* 32161C 0042161C 00000000 */   nop
.size func_00421610, 0x10
