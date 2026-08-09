.section .text
.set noat
.set noreorder
glabel func_00421880
    /* 321880 00421880 4A000324 */  addiu      $3, $0, 0x4A
    /* 321884 00421884 0C000000 */  syscall    0 /* handwritten instruction */
    /* 321888 00421888 0800E003 */  jr         $31
    /* 32188C 0042188C 00000000 */   nop
.size func_00421880, 0x10
