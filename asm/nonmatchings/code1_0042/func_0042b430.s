.section .text
.set noat
.set noreorder
glabel func_0042b430
    /* 32B430 0042B430 57000324 */  addiu      $3, $0, 0x57
    /* 32B434 0042B434 0C000000 */  syscall    0 /* handwritten instruction */
    /* 32B438 0042B438 0800E003 */  jr         $31
    /* 32B43C 0042B43C 00000000 */   nop
.size func_0042b430, 0x10
