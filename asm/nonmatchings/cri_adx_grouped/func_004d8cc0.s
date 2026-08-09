.section .text
.set noat
.set noreorder
glabel func_004d8cc0
    /* 3D8CC0 004D8CC0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3D8CC4 004D8CC4 7200033C */  lui        $3, %hi(D_00725294)
    /* 3D8CC8 004D8CC8 0000BFFF */  sd         $31, 0x0($29)
    /* 3D8CCC 004D8CCC 2D10A000 */  daddu      $2, $5, $0
    /* 3D8CD0 004D8CD0 2D288000 */  daddu      $5, $4, $0
    /* 3D8CD4 004D8CD4 9452648C */  lw         $4, %lo(D_00725294)($3)
    /* 3D8CD8 004D8CD8 0000BFDF */  ld         $31, 0x0($29)
    /* 3D8CDC 004D8CDC 2D38C000 */  daddu      $7, $6, $0
    /* 3D8CE0 004D8CE0 2D304000 */  daddu      $6, $2, $0
    /* 3D8CE4 004D8CE4 4A021308 */  j          func_004c0928
    /* 3D8CE8 004D8CE8 1000BD27 */   addiu     $29, $29, 0x10
    /* 3D8CEC 004D8CEC 00000000 */  nop
.size func_004d8cc0, 0x30
