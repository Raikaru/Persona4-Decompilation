.section .text
.set noat
.set noreorder
glabel func_0016e8c0
    /* 6E8C0 0016E8C0 3800828C */  lw         $2, 0x38($4)
    /* 6E8C4 0016E8C4 0C00428C */  lw         $2, 0xC($2)
    /* 6E8C8 0016E8C8 40004224 */  addiu      $2, $2, 0x40
    /* 6E8CC 0016E8CC 0800E003 */  jr         $31
    /* 6E8D0 0016E8D0 00000000 */   nop
    /* 6E8D4 0016E8D4 00000000 */  nop
    /* 6E8D8 0016E8D8 00000000 */  nop
    /* 6E8DC 0016E8DC 00000000 */  nop
.size func_0016e8c0, 0x20
