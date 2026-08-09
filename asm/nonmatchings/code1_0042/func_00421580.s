.section .text
.set noat
.set noreorder
glabel func_00421580
    /* 321580 00421580 E6FF0324 */  addiu      $3, $0, -0x1A
    /* 321584 00421584 0C000000 */  syscall    0 /* handwritten instruction */
    /* 321588 00421588 0800E003 */  jr         $31
    /* 32158C 0042158C 00000000 */   nop
.size func_00421580, 0x10
