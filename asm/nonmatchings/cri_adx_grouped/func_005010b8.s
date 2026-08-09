.section .text
.set noat
.set noreorder
glabel func_005010b8
    /* 4010B8 005010B8 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 4010BC 005010BC 0000BFFF */  sd         $31, 0x0($29)
    /* 4010C0 005010C0 0000BFDF */  ld         $31, 0x0($29)
    /* 4010C4 005010C4 04FE1008 */  j          func_0043f810
    /* 4010C8 005010C8 1000BD27 */   addiu     $29, $29, 0x10
    /* 4010CC 005010CC 00000000 */  nop
.size func_005010b8, 0x18
