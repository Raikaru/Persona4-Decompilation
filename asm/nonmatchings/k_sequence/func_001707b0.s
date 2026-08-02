.section .text
.set noat
.set noreorder
glabel func_001707b0
    /* 707B0 001707B0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 707B4 001707B4 0000BFFF */  sd         $31, 0x0($29)
    /* 707B8 001707B8 2D108000 */  daddu      $2, $4, $0
    /* 707BC 001707BC 2D200000 */  daddu      $4, $0, $0
    /* 707C0 001707C0 0000458C */  lw         $5, 0x0($2)
    /* 707C4 001707C4 2D300000 */  daddu      $6, $0, $0
    /* 707C8 001707C8 A01F060C */  jal        func_00187e80
    /* 707CC 001707CC 00000000 */   nop
    /* 707D0 001707D0 0000BFDF */  ld         $31, 0x0($29)
    /* 707D4 001707D4 1000BD27 */  addiu      $29, $29, 0x10
    /* 707D8 001707D8 0800E003 */  jr         $31
    /* 707DC 001707DC 00000000 */   nop
.size func_001707b0, 0x30
