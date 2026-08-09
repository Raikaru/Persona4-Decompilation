.section .text
.set noat
.set noreorder
glabel func_00421890
    /* 321890 00421890 4B000324 */  addiu      $3, $0, 0x4B
    /* 321894 00421894 0C000000 */  syscall    0 /* handwritten instruction */
    /* 321898 00421898 0800E003 */  jr         $31
    /* 32189C 0042189C 00000000 */   nop
.size func_00421890, 0x10
