.section .text
.set noat
.set noreorder
glabel func_00421730
    /* 321730 00421730 35000324 */  addiu      $3, $0, 0x35
    /* 321734 00421734 0C000000 */  syscall    0 /* handwritten instruction */
    /* 321738 00421738 0800E003 */  jr         $31
    /* 32173C 0042173C 00000000 */   nop
.size func_00421730, 0x10
