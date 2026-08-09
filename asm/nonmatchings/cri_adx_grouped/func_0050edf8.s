.section .text
.set noat
.set noreorder
glabel func_0050edf8
    /* 40EDF8 0050EDF8 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 40EDFC 0050EDFC 2D380000 */  daddu      $7, $0, $0
    /* 40EE00 0050EE00 0000BFFF */  sd         $31, 0x0($29)
    /* 40EE04 0050EE04 0000BFDF */  ld         $31, 0x0($29)
    /* 40EE08 0050EE08 8A3B1408 */  j          func_0050ee28
    /* 40EE0C 0050EE0C 1000BD27 */   addiu     $29, $29, 0x10
.size func_0050edf8, 0x18
