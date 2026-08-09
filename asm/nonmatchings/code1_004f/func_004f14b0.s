.section .text
.set noat
.set noreorder
glabel func_004f14b0
    /* 3F14B0 004F14B0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3F14B4 004F14B4 0000BFFF */  sd         $31, 0x0($29)
    /* 3F14B8 004F14B8 0000BFDF */  ld         $31, 0x0($29)
    /* 3F14BC 004F14BC A4891308 */  j          func_004e2690
    /* 3F14C0 004F14C0 1000BD27 */   addiu     $29, $29, 0x10
    /* 3F14C4 004F14C4 00000000 */  nop
.size func_004f14b0, 0x18
