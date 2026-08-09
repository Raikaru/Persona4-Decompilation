.section .text
.set noat
.set noreorder
glabel func_005111b8
    /* 4111B8 005111B8 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 4111BC 005111BC 0000BFFF */  sd         $31, 0x0($29)
    /* 4111C0 005111C0 0000BFDF */  ld         $31, 0x0($29)
    /* 4111C4 005111C4 B8C11308 */  j          func_004f06e0
    /* 4111C8 005111C8 1000BD27 */   addiu     $29, $29, 0x10
    /* 4111CC 005111CC 00000000 */  nop
.size func_005111b8, 0x18
