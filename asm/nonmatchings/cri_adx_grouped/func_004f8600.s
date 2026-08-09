.section .text
.set noat
.set noreorder
glabel func_004f8600
    /* 3F8600 004F8600 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3F8604 004F8604 0000BFFF */  sd         $31, 0x0($29)
    /* 3F8608 004F8608 0000BFDF */  ld         $31, 0x0($29)
    /* 3F860C 004F860C 82C61308 */  j          func_004f1a08
    /* 3F8610 004F8610 1000BD27 */   addiu     $29, $29, 0x10
    /* 3F8614 004F8614 00000000 */  nop
.size func_004f8600, 0x18
