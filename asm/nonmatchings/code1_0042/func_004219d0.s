.section .text
.set noat
.set noreorder
glabel func_004219d0
    /* 3219D0 004219D0 A3FF0324 */  addiu      $3, $0, -0x5D
    /* 3219D4 004219D4 0C000000 */  syscall    0 /* handwritten instruction */
    /* 3219D8 004219D8 0800E003 */  jr         $31
    /* 3219DC 004219DC 00000000 */   nop
.size func_004219d0, 0x10
