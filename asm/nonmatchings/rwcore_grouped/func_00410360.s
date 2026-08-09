.section .text
.set noat
.set noreorder
glabel func_00410360
    /* 310360 00410360 7100023C */  lui        $2, %hi(D_0070C35C)
    /* 310364 00410364 0800E003 */  jr         $31
    /* 310368 00410368 5CC3428C */   lw        $2, %lo(D_0070C35C)($2)
    /* 31036C 0041036C 00000000 */  nop
.size func_00410360, 0x10
