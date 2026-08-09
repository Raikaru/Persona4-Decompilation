.section .text
.set noat
.set noreorder
glabel func_004f8630
    /* 3F8630 004F8630 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3F8634 004F8634 0000BFFF */  sd         $31, 0x0($29)
    /* 3F8638 004F8638 0000BFDF */  ld         $31, 0x0($29)
    /* 3F863C 004F863C F8C81308 */  j          func_004f23e0
    /* 3F8640 004F8640 1000BD27 */   addiu     $29, $29, 0x10
    /* 3F8644 004F8644 00000000 */  nop
.size func_004f8630, 0x18
