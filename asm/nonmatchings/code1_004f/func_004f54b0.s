.section .text
.set noat
.set noreorder
glabel func_004f54b0
    /* 3F54B0 004F54B0 7400033C */  lui        $3, %hi(D_00743A54)
    /* 3F54B4 004F54B4 0800E003 */  jr         $31
    /* 3F54B8 004F54B8 543A628C */   lw        $2, %lo(D_00743A54)($3)
    /* 3F54BC 004F54BC 00000000 */  nop
.size func_004f54b0, 0x10
