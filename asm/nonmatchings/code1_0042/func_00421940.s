.section .text
.set noat
.set noreorder
glabel func_00421940
    /* 321940 00421940 56000324 */  addiu      $3, $0, 0x56
    /* 321944 00421944 0C000000 */  syscall    0 /* handwritten instruction */
    /* 321948 00421948 0800E003 */  jr         $31
    /* 32194C 0042194C 00000000 */   nop
.size func_00421940, 0x10
