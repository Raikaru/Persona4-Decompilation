.section .text
.set noat
.set noreorder
glabel func_004e3d98
    /* 3E3D98 004E3D98 7300023C */  lui        $2, %hi(D_00731C78)
    /* 3E3D9C 004E3D9C 0800E003 */  jr         $31
    /* 3E3DA0 004E3DA0 781C44AC */   sw        $4, %lo(D_00731C78)($2)
    /* 3E3DA4 004E3DA4 00000000 */  nop
.size func_004e3d98, 0x10
