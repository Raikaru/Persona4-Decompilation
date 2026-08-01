.section .text
.set noat
.set noreorder
glabel func_004d3698
    /* 3D3698 004D3698 7200033C */  lui        $3, %hi(D_00724E60)
    /* 3D369C 004D369C 0800E003 */  jr         $31
    /* 3D36A0 004D36A0 604E628C */   lw        $2, %lo(D_00724E60)($3)
    /* 3D36A4 004D36A4 00000000 */  nop
.size func_004d3698, 0x10
