.section .text
.set noat
.set noreorder
glabel func_0052d408
    /* 42D408 0052D408 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 42D40C 0052D40C 0000BFFF */  sd         $31, 0x0($29)
    /* 42D410 0052D410 0000BFDF */  ld         $31, 0x0($29)
    /* 42D414 0052D414 16111108 */  j          func_00444458
    /* 42D418 0052D418 1000BD27 */   addiu     $29, $29, 0x10
    /* 42D41C 0052D41C 00000000 */  nop
.size func_0052d408, 0x18
