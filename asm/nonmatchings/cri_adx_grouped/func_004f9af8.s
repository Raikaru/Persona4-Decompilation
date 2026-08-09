.section .text
.set noat
.set noreorder
glabel func_004f9af8
    /* 3F9AF8 004F9AF8 7400033C */  lui        $3, %hi(D_00743C68)
    /* 3F9AFC 004F9AFC 0800E003 */  jr         $31
    /* 3F9B00 004F9B00 683C628C */   lw        $2, %lo(D_00743C68)($3)
    /* 3F9B04 004F9B04 00000000 */  nop
.size func_004f9af8, 0x10
