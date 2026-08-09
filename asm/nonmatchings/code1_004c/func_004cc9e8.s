.section .text
.set noat
.set noreorder
glabel func_004cc9e8
    /* 3CC9E8 004CC9E8 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3CC9EC 004CC9EC 0000BFFF */  sd         $31, 0x0($29)
    /* 3CC9F0 004CC9F0 0000BFDF */  ld         $31, 0x0($29)
    /* 3CC9F4 004CC9F4 88C11308 */  j          func_004f0620
    /* 3CC9F8 004CC9F8 1000BD27 */   addiu     $29, $29, 0x10
    /* 3CC9FC 004CC9FC 00000000 */  nop
.size func_004cc9e8, 0x18
