.section .text
.set noat
.set noreorder
glabel func_0047a1c0
    /* 37A1C0 0047A1C0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 37A1C4 0047A1C4 0000BFFF */  sd         $31, 0x0($29)
    /* 37A1C8 0047A1C8 88830F0C */  jal        func_003e0e20
    /* 37A1CC 0047A1CC 00000000 */   nop
    /* 37A1D0 0047A1D0 0000BFDF */  ld         $31, 0x0($29)
    /* 37A1D4 0047A1D4 1000BD27 */  addiu      $29, $29, 0x10
    /* 37A1D8 0047A1D8 0800E003 */  jr         $31
    /* 37A1DC 0047A1DC 00000000 */   nop
.size func_0047a1c0, 0x20
