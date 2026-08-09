.section .text
.set noat
.set noreorder
glabel func_00458f70
    /* 358F70 00458F70 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 358F74 00458F74 0000BFFF */  sd         $31, 0x0($29)
    /* 358F78 00458F78 2D30A000 */  daddu      $6, $5, $0
    /* 358F7C 00458F7C 4600053C */  lui        $5, %hi(func_00458ce0)
    /* 358F80 00458F80 E08CA524 */  addiu      $5, $5, %lo(func_00458ce0)
    /* 358F84 00458F84 9C280F0C */  jal        func_003ca270
    /* 358F88 00458F88 00000000 */   nop
    /* 358F8C 00458F8C 0000BFDF */  ld         $31, 0x0($29)
    /* 358F90 00458F90 1000BD27 */  addiu      $29, $29, 0x10
    /* 358F94 00458F94 0800E003 */  jr         $31
    /* 358F98 00458F98 00000000 */   nop
    /* 358F9C 00458F9C 00000000 */  nop
.size func_00458f70, 0x30
