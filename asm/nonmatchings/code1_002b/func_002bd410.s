.section .text
.set noat
.set noreorder
glabel func_002bd410
    /* 1BD410 002BD410 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 1BD414 002BD414 0000BFFF */  sd         $31, 0x0($29)
    /* 1BD418 002BD418 01000424 */  addiu      $4, $0, 0x1
    /* 1BD41C 002BD41C 2D280000 */  daddu      $5, $0, $0
    /* 1BD420 002BD420 686A110C */  jal        func_0045a9a0
    /* 1BD424 002BD424 00000000 */   nop
    /* 1BD428 002BD428 10F50A0C */  jal        func_002bd440
    /* 1BD42C 002BD42C 00000000 */   nop
    /* 1BD430 002BD430 0000BFDF */  ld         $31, 0x0($29)
    /* 1BD434 002BD434 1000BD27 */  addiu      $29, $29, 0x10
    /* 1BD438 002BD438 0800E003 */  jr         $31
    /* 1BD43C 002BD43C 00000000 */   nop
.size func_002bd410, 0x30
