.section .text
.set noat
.set noreorder
glabel func_00510e40
    /* 410E40 00510E40 7400033C */  lui        $3, %hi(D_00745888)
    /* 410E44 00510E44 0800E003 */  jr         $31
    /* 410E48 00510E48 8858628C */   lw        $2, %lo(D_00745888)($3)
    /* 410E4C 00510E4C 00000000 */  nop
.size func_00510e40, 0x10
