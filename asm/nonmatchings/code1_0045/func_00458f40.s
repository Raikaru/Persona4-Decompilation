.section .text
.set noat
.set noreorder
glabel func_00458f40
    /* 358F40 00458F40 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 358F44 00458F44 0000BFFF */  sd         $31, 0x0($29)
    /* 358F48 00458F48 2D30A000 */  daddu      $6, $5, $0
    /* 358F4C 00458F4C 4600053C */  lui        $5, %hi(func_00458f00)
    /* 358F50 00458F50 008FA524 */  addiu      $5, $5, %lo(func_00458f00)
    /* 358F54 00458F54 CCFF0E0C */  jal        func_003bff30
    /* 358F58 00458F58 00000000 */   nop
    /* 358F5C 00458F5C 0000BFDF */  ld         $31, 0x0($29)
    /* 358F60 00458F60 1000BD27 */  addiu      $29, $29, 0x10
    /* 358F64 00458F64 0800E003 */  jr         $31
    /* 358F68 00458F68 00000000 */   nop
    /* 358F6C 00458F6C 00000000 */  nop
.size func_00458f40, 0x30
