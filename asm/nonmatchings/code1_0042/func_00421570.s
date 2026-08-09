.section .text
.set noat
.set noreorder
glabel func_00421570
    /* 321570 00421570 FD000324 */  addiu      $3, $0, 0xFD
    /* 321574 00421574 0C000000 */  syscall    0 /* handwritten instruction */
    /* 321578 00421578 0800E003 */  jr         $31
    /* 32157C 0042157C 00000000 */   nop
.size func_00421570, 0x10
