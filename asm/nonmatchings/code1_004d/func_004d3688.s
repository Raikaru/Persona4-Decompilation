.section .text
.set noat
.set noreorder
glabel func_004d3688
    /* 3D3688 004D3688 7200033C */  lui        $3, %hi(D_00724E58)
    /* 3D368C 004D368C 0800E003 */  jr         $31
    /* 3D3690 004D3690 584E628C */   lw        $2, %lo(D_00724E58)($3)
    /* 3D3694 004D3694 00000000 */  nop
.size func_004d3688, 0x10
