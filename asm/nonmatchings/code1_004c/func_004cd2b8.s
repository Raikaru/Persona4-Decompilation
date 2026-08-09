.section .text
.set noat
.set noreorder
glabel func_004cd2b8
    /* 3CD2B8 004CD2B8 7200033C */  lui        $3, %hi(D_007212D0)
    /* 3CD2BC 004CD2BC 0800E003 */  jr         $31
    /* 3CD2C0 004CD2C0 D012628C */   lw        $2, %lo(D_007212D0)($3)
    /* 3CD2C4 004CD2C4 00000000 */  nop
.size func_004cd2b8, 0x10
