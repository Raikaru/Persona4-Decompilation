.section .text
.set noat
.set noreorder
glabel func_004f14c8
    /* 3F14C8 004F14C8 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3F14CC 004F14CC 0000BFFF */  sd         $31, 0x0($29)
    /* 3F14D0 004F14D0 0000BFDF */  ld         $31, 0x0($29)
    /* 3F14D4 004F14D4 D4891308 */  j          func_004e2750
    /* 3F14D8 004F14D8 1000BD27 */   addiu     $29, $29, 0x10
    /* 3F14DC 004F14DC 00000000 */  nop
.size func_004f14c8, 0x18
