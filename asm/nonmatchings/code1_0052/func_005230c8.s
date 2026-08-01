.section .text
.set noat
.set noreorder
glabel func_005230c8
    /* 4230C8 005230C8 7400033C */  lui        $3, %hi(D_00745ABC)
    /* 4230CC 005230CC 0800E003 */  jr         $31
    /* 4230D0 005230D0 BC5A628C */   lw        $2, %lo(D_00745ABC)($3)
    /* 4230D4 005230D4 00000000 */  nop
.size func_005230c8, 0x10
