.section .text
.set noat
.set noreorder
glabel func_004f8578
    /* 3F8578 004F8578 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3F857C 004F857C 0000BFFF */  sd         $31, 0x0($29)
    /* 3F8580 004F8580 0000BFDF */  ld         $31, 0x0($29)
    /* 3F8584 004F8584 18C91308 */  j          func_004f2460
    /* 3F8588 004F8588 1000BD27 */   addiu     $29, $29, 0x10
    /* 3F858C 004F858C 00000000 */  nop
.size func_004f8578, 0x18
