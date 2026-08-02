.section .text
.set noat
.set noreorder
glabel func_0035c7d0
    /* 25C7D0 0035C7D0 3800828C */  lw         $2, 0x38($4)
    /* 25C7D4 0035C7D4 04004290 */  lbu        $2, 0x4($2)
    /* 25C7D8 0035C7D8 01004230 */  andi       $2, $2, 0x1
    /* 25C7DC 0035C7DC 2B100200 */  sltu       $2, $0, $2
    /* 25C7E0 0035C7E0 0800E003 */  jr         $31
    /* 25C7E4 0035C7E4 00000000 */   nop
    /* 25C7E8 0035C7E8 00000000 */  nop
    /* 25C7EC 0035C7EC 00000000 */  nop
.size func_0035c7d0, 0x20
