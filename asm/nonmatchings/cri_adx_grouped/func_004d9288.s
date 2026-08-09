.section .text
.set noat
.set noreorder
glabel func_004d9288
    /* 3D9288 004D9288 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3D928C 004D928C 7200023C */  lui        $2, %hi(D_00725294)
    /* 3D9290 004D9290 0000BFFF */  sd         $31, 0x0($29)
    /* 3D9294 004D9294 2D288000 */  daddu      $5, $4, $0
    /* 3D9298 004D9298 9452448C */  lw         $4, %lo(D_00725294)($2)
    /* 3D929C 004D929C 0000BFDF */  ld         $31, 0x0($29)
    /* 3D92A0 004D92A0 58031308 */  j          func_004c0d60
    /* 3D92A4 004D92A4 1000BD27 */   addiu     $29, $29, 0x10
.size func_004d9288, 0x20
