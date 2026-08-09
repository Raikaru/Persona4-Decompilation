.section .text
.set noat
.set noreorder
glabel func_004d8b10
    /* 3D8B10 004D8B10 7200033C */  lui        $3, %hi(D_00724EC8)
    /* 3D8B14 004D8B14 01000224 */  addiu      $2, $0, 0x1
    /* 3D8B18 004D8B18 0800E003 */  jr         $31
    /* 3D8B1C 004D8B1C C84E62AC */   sw        $2, %lo(D_00724EC8)($3)
.size func_004d8b10, 0x10
