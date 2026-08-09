.section .text
.set noat
.set noreorder
glabel func_00511110
    /* 411110 00511110 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 411114 00511114 0000BFFF */  sd         $31, 0x0($29)
    /* 411118 00511118 0000BFDF */  ld         $31, 0x0($29)
    /* 41111C 0051111C 6C331408 */  j          func_0050cdb0
    /* 411120 00511120 1000BD27 */   addiu     $29, $29, 0x10
    /* 411124 00511124 00000000 */  nop
.size func_00511110, 0x18
