.section .text
.set noat
.set noreorder
glabel func_004d9a90
    /* 3D9A90 004D9A90 7300023C */  lui        $2, %hi(D_007286F4)
    /* 3D9A94 004D9A94 7300033C */  lui        $3, %hi(D_007286F8)
    /* 3D9A98 004D9A98 F48644AC */  sw         $4, %lo(D_007286F4)($2)
    /* 3D9A9C 004D9A9C 2D100000 */  daddu      $2, $0, $0
    /* 3D9AA0 004D9AA0 0800E003 */  jr         $31
    /* 3D9AA4 004D9AA4 F88665AC */   sw        $5, %lo(D_007286F8)($3)
.size func_004d9a90, 0x18
