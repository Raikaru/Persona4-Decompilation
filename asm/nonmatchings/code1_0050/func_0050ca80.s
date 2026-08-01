.section .text
.set noat
.set noreorder
glabel func_0050ca80
    /* 40CA80 0050CA80 7400033C */  lui        $3, %hi(D_00745878)
    /* 40CA84 0050CA84 0800E003 */  jr         $31
    /* 40CA88 0050CA88 7858628C */   lw        $2, %lo(D_00745878)($3)
    /* 40CA8C 0050CA8C 00000000 */  nop
.size func_0050ca80, 0x10
