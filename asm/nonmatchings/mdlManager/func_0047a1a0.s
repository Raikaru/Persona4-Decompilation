.section .text
.set noat
.set noreorder
glabel func_0047a1a0
    /* 37A1A0 0047A1A0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 37A1A4 0047A1A4 0000BFFF */  sd         $31, 0x0($29)
    /* 37A1A8 0047A1A8 1C820F0C */  jal        func_003e0870
    /* 37A1AC 0047A1AC 00000000 */   nop
    /* 37A1B0 0047A1B0 0000BFDF */  ld         $31, 0x0($29)
    /* 37A1B4 0047A1B4 1000BD27 */  addiu      $29, $29, 0x10
    /* 37A1B8 0047A1B8 0800E003 */  jr         $31
    /* 37A1BC 0047A1BC 00000000 */   nop
.size func_0047a1a0, 0x20
