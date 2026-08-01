.section .text
.set noat
.set noreorder
glabel func_004e3d88
    /* 3E3D88 004E3D88 7300023C */  lui        $2, %hi(D_00731C7C)
    /* 3E3D8C 004E3D8C 0800E003 */  jr         $31
    /* 3E3D90 004E3D90 7C1C44A0 */   sb        $4, %lo(D_00731C7C)($2)
    /* 3E3D94 004E3D94 00000000 */  nop
.size func_004e3d88, 0x10
