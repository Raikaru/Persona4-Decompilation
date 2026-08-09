.section .text
.set noat
.set noreorder
glabel func_005112b8
    /* 4112B8 005112B8 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 4112BC 005112BC 06000424 */  addiu      $4, $0, 0x6
    /* 4112C0 005112C0 0000BFFF */  sd         $31, 0x0($29)
    /* 4112C4 005112C4 0000BFDF */  ld         $31, 0x0($29)
    /* 4112C8 005112C8 90C31308 */  j          func_004f0e40
    /* 4112CC 005112CC 1000BD27 */   addiu     $29, $29, 0x10
.size func_005112b8, 0x18
