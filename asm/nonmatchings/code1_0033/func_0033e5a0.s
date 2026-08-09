.section .text
.set noat
.set noreorder
glabel func_0033e5a0
    /* 23E5A0 0033E5A0 3800828C */  lw         $2, 0x38($4)
    /* 23E5A4 0033E5A4 00004280 */  lb         $2, 0x0($2)
    /* 23E5A8 0033E5A8 2B100200 */  sltu       $2, $0, $2
    /* 23E5AC 0033E5AC 0800E003 */  jr         $31
    /* 23E5B0 0033E5B0 00000000 */   nop
    /* 23E5B4 0033E5B4 00000000 */  nop
    /* 23E5B8 0033E5B8 00000000 */  nop
    /* 23E5BC 0033E5BC 00000000 */  nop
.size func_0033e5a0, 0x20
