.section .text
.set noat
.set noreorder
glabel func_004f85a8
    /* 3F85A8 004F85A8 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3F85AC 004F85AC 0000BFFF */  sd         $31, 0x0($29)
    /* 3F85B0 004F85B0 0000BFDF */  ld         $31, 0x0($29)
    /* 3F85B4 004F85B4 DCC81308 */  j          func_004f2370
    /* 3F85B8 004F85B8 1000BD27 */   addiu     $29, $29, 0x10
    /* 3F85BC 004F85BC 00000000 */  nop
.size func_004f85a8, 0x18
