.section .text
.set noat
.set noreorder
glabel func_00421670
    /* 321670 00421670 29000324 */  addiu      $3, $0, 0x29
    /* 321674 00421674 0C000000 */  syscall    0 /* handwritten instruction */
    /* 321678 00421678 0800E003 */  jr         $31
    /* 32167C 0042167C 00000000 */   nop
.size func_00421670, 0x10
