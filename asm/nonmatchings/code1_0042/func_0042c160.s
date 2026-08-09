.section .text
.set noat
.set noreorder
glabel func_0042c160
    /* 32C160 0042C160 5A000324 */  addiu      $3, $0, 0x5A
    /* 32C164 0042C164 0C000000 */  syscall    0 /* handwritten instruction */
    /* 32C168 0042C168 0800E003 */  jr         $31
    /* 32C16C 0042C16C 00000000 */   nop
.size func_0042c160, 0x10
