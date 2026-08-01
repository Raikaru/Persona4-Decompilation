.section .text
.set noat
.set noreorder
glabel func_004d3190
    /* 3D3190 004D3190 7200033C */  lui        $3, %hi(D_00723F20)
    /* 3D3194 004D3194 0800E003 */  jr         $31
    /* 3D3198 004D3198 203F628C */   lw        $2, %lo(D_00723F20)($3)
    /* 3D319C 004D319C 00000000 */  nop
.size func_004d3190, 0x10
