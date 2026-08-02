.section .text
.set noat
.set noreorder
glabel func_00102dc0
    /* 2DC0 00102DC0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 2DC4 00102DC4 0000BFFF */  sd         $31, 0x0($29)
    /* 2DC8 00102DC8 780E040C */  jal        func_001039e0
    /* 2DCC 00102DCC 00000000 */   nop
    /* 2DD0 00102DD0 0000BFDF */  ld         $31, 0x0($29)
    /* 2DD4 00102DD4 1000BD27 */  addiu      $29, $29, 0x10
    /* 2DD8 00102DD8 0800E003 */  jr         $31
    /* 2DDC 00102DDC 00000000 */   nop
.size func_00102dc0, 0x20
