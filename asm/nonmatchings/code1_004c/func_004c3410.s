.section .text
.set noat
.set noreorder
glabel func_004c3410
    /* 3C3410 004C3410 7100033C */  lui        $3, %hi(D_00714C3C)
    /* 3C3414 004C3414 0800E003 */  jr         $31
    /* 3C3418 004C3418 3C4C628C */   lw        $2, %lo(D_00714C3C)($3)
    /* 3C341C 004C341C 00000000 */  nop
.size func_004c3410, 0x10
