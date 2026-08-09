.section .text
.set noat
.set noreorder
glabel func_00432ee8
    /* 332EE8 00432EE8 2D30A000 */  daddu      $6, $5, $0
    /* 332EEC 00432EEC F0FFBD27 */  addiu      $29, $29, -0x10
    /* 332EF0 00432EF0 2D288000 */  daddu      $5, $4, $0
    /* 332EF4 00432EF4 0000BFFF */  sd         $31, 0x0($29)
    /* 332EF8 00432EF8 86CB100C */  jal        func_00432e18
    /* 332EFC 00432EFC 2D200000 */   daddu     $4, $0, $0
    /* 332F00 00432F00 0000BFDF */  ld         $31, 0x0($29)
    /* 332F04 00432F04 0800E003 */  jr         $31
    /* 332F08 00432F08 1000BD27 */   addiu     $29, $29, 0x10
    /* 332F0C 00432F0C 00000000 */  nop
.size func_00432ee8, 0x28
