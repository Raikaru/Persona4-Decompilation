.section .text
.set noat
.set noreorder
glabel func_004f06b0
    /* 3F06B0 004F06B0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3F06B4 004F06B4 02000424 */  addiu      $4, $0, 0x2
    /* 3F06B8 004F06B8 0000BFFF */  sd         $31, 0x0($29)
    /* 3F06BC 004F06BC 0000BFDF */  ld         $31, 0x0($29)
    /* 3F06C0 004F06C0 5EC11308 */  j          func_004f0578
    /* 3F06C4 004F06C4 1000BD27 */   addiu     $29, $29, 0x10
.size func_004f06b0, 0x18
