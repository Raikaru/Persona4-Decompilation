.section .text
.set noat
.set noreorder
glabel func_004f0680
    /* 3F0680 004F0680 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3F0684 004F0684 05000424 */  addiu      $4, $0, 0x5
    /* 3F0688 004F0688 0000BFFF */  sd         $31, 0x0($29)
    /* 3F068C 004F068C 0000BFDF */  ld         $31, 0x0($29)
    /* 3F0690 004F0690 46C11308 */  j          func_004f0518
    /* 3F0694 004F0694 1000BD27 */   addiu     $29, $29, 0x10
.size func_004f0680, 0x18
