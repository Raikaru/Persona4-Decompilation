.section .text
.set noat
.set noreorder
glabel func_004f0728
    /* 3F0728 004F0728 7400033C */  lui        $3, %hi(D_00743984)
    /* 3F072C 004F072C 84396324 */  addiu      $3, $3, %lo(D_00743984)
    /* 3F0730 004F0730 0800E003 */  jr         $31
    /* 3F0734 004F0734 0000628C */   lw        $2, 0x0($3)
.size func_004f0728, 0x10
