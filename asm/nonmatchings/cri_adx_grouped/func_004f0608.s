.section .text
.set noat
.set noreorder
glabel func_004f0608
    /* 3F0608 004F0608 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3F060C 004F060C 01000424 */  addiu      $4, $0, 0x1
    /* 3F0610 004F0610 0000BFFF */  sd         $31, 0x0($29)
    /* 3F0614 004F0614 0000BFDF */  ld         $31, 0x0($29)
    /* 3F0618 004F0618 46C11308 */  j          func_004f0518
    /* 3F061C 004F061C 1000BD27 */   addiu     $29, $29, 0x10
.size func_004f0608, 0x18
