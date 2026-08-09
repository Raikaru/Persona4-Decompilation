.section .text
.set noat
.set noreorder
glabel func_003d3a80
    /* 2D3A80 003D3A80 7100023C */  lui        $2, %hi(D_0070B470)
    /* 2D3A84 003D3A84 0800E003 */  jr         $31
    /* 2D3A88 003D3A88 70B44224 */   addiu     $2, $2, %lo(D_0070B470)
    /* 2D3A8C 003D3A8C 00000000 */  nop
.size func_003d3a80, 0x10
