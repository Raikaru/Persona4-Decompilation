.section .text
.set noat
.set noreorder
glabel func_004f54c0
    /* 3F54C0 004F54C0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3F54C4 004F54C4 0000BFFF */  sd         $31, 0x0($29)
    /* 3F54C8 004F54C8 0000BFDF */  ld         $31, 0x0($29)
    /* 3F54CC 004F54CC 2CD51308 */  j          func_004f54b0
    /* 3F54D0 004F54D0 1000BD27 */   addiu     $29, $29, 0x10
    /* 3F54D4 004F54D4 00000000 */  nop
.size func_004f54c0, 0x18
