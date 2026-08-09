.section .text
.set noat
.set noreorder
glabel func_005143b0
    /* 4143B0 005143B0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 4143B4 005143B4 0000BFFF */  sd         $31, 0x0($29)
    /* 4143B8 005143B8 0000BFDF */  ld         $31, 0x0($29)
    /* 4143BC 005143BC B2561408 */  j          func_00515ac8
    /* 4143C0 005143C0 1000BD27 */   addiu     $29, $29, 0x10
    /* 4143C4 005143C4 00000000 */  nop
.size func_005143b0, 0x18
