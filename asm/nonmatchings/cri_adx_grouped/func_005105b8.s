.section .text
.set noat
.set noreorder
glabel func_005105b8
    /* 4105B8 005105B8 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 4105BC 005105BC 2D20A003 */  daddu      $4, $29, $0
    /* 4105C0 005105C0 0400A527 */  addiu      $5, $29, 0x4
    /* 4105C4 005105C4 1000BFFF */  sd         $31, 0x10($29)
    /* 4105C8 005105C8 8C41140C */  jal        func_00510630
    /* 4105CC 005105CC 0800A627 */   addiu     $6, $29, 0x8
    /* 4105D0 005105D0 1000BFDF */  ld         $31, 0x10($29)
    /* 4105D4 005105D4 0800E003 */  jr         $31
    /* 4105D8 005105D8 2000BD27 */   addiu     $29, $29, 0x20
    /* 4105DC 005105DC 00000000 */  nop
.size func_005105b8, 0x28
