.section .text
.set noat
.set noreorder
glabel func_004d8cf0
    /* 3D8CF0 004D8CF0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3D8CF4 004D8CF4 7200023C */  lui        $2, %hi(D_00725294)
    /* 3D8CF8 004D8CF8 0000BFFF */  sd         $31, 0x0($29)
    /* 3D8CFC 004D8CFC 2D288000 */  daddu      $5, $4, $0
    /* 3D8D00 004D8D00 9452448C */  lw         $4, %lo(D_00725294)($2)
    /* 3D8D04 004D8D04 0000BFDF */  ld         $31, 0x0($29)
    /* 3D8D08 004D8D08 90021308 */  j          func_004c0a40
    /* 3D8D0C 004D8D0C 1000BD27 */   addiu     $29, $29, 0x10
.size func_004d8cf0, 0x20
