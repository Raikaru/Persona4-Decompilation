.section .text
.set noat
.set noreorder
glabel func_00388de0
    /* 288DE0 00388DE0 3800828C */  lw         $2, 0x38($4)
    /* 288DE4 00388DE4 04004294 */  lhu        $2, 0x4($2)
    /* 288DE8 00388DE8 01004230 */  andi       $2, $2, 0x1
    /* 288DEC 00388DEC 2B100200 */  sltu       $2, $0, $2
    /* 288DF0 00388DF0 0800E003 */  jr         $31
    /* 288DF4 00388DF4 00000000 */   nop
    /* 288DF8 00388DF8 00000000 */  nop
    /* 288DFC 00388DFC 00000000 */  nop
.size func_00388de0, 0x20
