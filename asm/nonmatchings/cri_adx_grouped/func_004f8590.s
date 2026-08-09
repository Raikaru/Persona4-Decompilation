.section .text
.set noat
.set noreorder
glabel func_004f8590
    /* 3F8590 004F8590 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3F8594 004F8594 0000BFFF */  sd         $31, 0x0($29)
    /* 3F8598 004F8598 0000BFDF */  ld         $31, 0x0($29)
    /* 3F859C 004F859C 98C81308 */  j          func_004f2260
    /* 3F85A0 004F85A0 1000BD27 */   addiu     $29, $29, 0x10
    /* 3F85A4 004F85A4 00000000 */  nop
.size func_004f8590, 0x18
