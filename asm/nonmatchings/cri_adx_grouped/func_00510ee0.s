.section .text
.set noat
.set noreorder
glabel func_00510ee0
    /* 410EE0 00510EE0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 410EE4 00510EE4 0000BFFF */  sd         $31, 0x0($29)
    /* 410EE8 00510EE8 0000BFDF */  ld         $31, 0x0($29)
    /* 410EEC 00510EEC 88C41308 */  j          func_004f1220
    /* 410EF0 00510EF0 1000BD27 */   addiu     $29, $29, 0x10
    /* 410EF4 00510EF4 00000000 */  nop
.size func_00510ee0, 0x18
