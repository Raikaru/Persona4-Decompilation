.section .text
.set noat
.set noreorder
glabel func_004f9b18
    /* 3F9B18 004F9B18 7400033C */  lui        $3, %hi(D_00743C6C)
    /* 3F9B1C 004F9B1C 0800E003 */  jr         $31
    /* 3F9B20 004F9B20 6C3C628C */   lw        $2, %lo(D_00743C6C)($3)
    /* 3F9B24 004F9B24 00000000 */  nop
.size func_004f9b18, 0x10
