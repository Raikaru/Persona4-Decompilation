.section .text
.set noat
.set noreorder
glabel func_004d8d10
    /* 3D8D10 004D8D10 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3D8D14 004D8D14 7200023C */  lui        $2, %hi(D_00725294)
    /* 3D8D18 004D8D18 0000BFFF */  sd         $31, 0x0($29)
    /* 3D8D1C 004D8D1C 2D288000 */  daddu      $5, $4, $0
    /* 3D8D20 004D8D20 9452448C */  lw         $4, %lo(D_00725294)($2)
    /* 3D8D24 004D8D24 0000BFDF */  ld         $31, 0x0($29)
    /* 3D8D28 004D8D28 AE021308 */  j          func_004c0ab8
    /* 3D8D2C 004D8D2C 1000BD27 */   addiu     $29, $29, 0x10
.size func_004d8d10, 0x20
