.section .text
.set noat
.set noreorder
glabel func_00421620
    /* 321620 00421620 24000324 */  addiu      $3, $0, 0x24
    /* 321624 00421624 0C000000 */  syscall    0 /* handwritten instruction */
    /* 321628 00421628 0800E003 */  jr         $31
    /* 32162C 0042162C 00000000 */   nop
.size func_00421620, 0x10
