.section .text
.set noat
.set noreorder
glabel func_0022b0b0
    /* 12B0B0 0022B0B0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 12B0B4 0022B0B4 0000BFFF */  sd         $31, 0x0($29)
    /* 12B0B8 0022B0B8 2D000424 */  addiu      $4, $0, 0x2D
    /* 12B0BC 0022B0BC 5CDD070C */  jal        func_001f7570
    /* 12B0C0 0022B0C0 00000000 */   nop
    /* 12B0C4 0022B0C4 01000224 */  addiu      $2, $0, 0x1
    /* 12B0C8 0022B0C8 0000BFDF */  ld         $31, 0x0($29)
    /* 12B0CC 0022B0CC 1000BD27 */  addiu      $29, $29, 0x10
    /* 12B0D0 0022B0D0 0800E003 */  jr         $31
    /* 12B0D4 0022B0D4 00000000 */   nop
    /* 12B0D8 0022B0D8 00000000 */  nop
    /* 12B0DC 0022B0DC 00000000 */  nop
.size func_0022b0b0, 0x30
