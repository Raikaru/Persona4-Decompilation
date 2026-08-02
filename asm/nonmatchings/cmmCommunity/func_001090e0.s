.section .text
.set noat
.set noreorder
glabel func_001090e0
    /* 90E0 001090E0 7900023C */  lui        $2, %hi(D_00797560)
    /* 90E4 001090E4 6075428C */  lw         $2, %lo(D_00797560)($2)
    /* 90E8 001090E8 0800E003 */  jr         $31
    /* 90EC 001090EC 00000000 */   nop
.size func_001090e0, 0x10
