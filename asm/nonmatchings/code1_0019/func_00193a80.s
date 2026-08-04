.section .text
.set noat
.set noreorder
glabel func_00193a80
    /* 93A80 00193A80 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 93A84 00193A84 0000BFFF */  sd         $31, 0x0($29)
    /* 93A88 00193A88 30B480AF */  sw         $0, -0x4BD0($28)
    /* 93A8C 00193A8C 34B480AF */  sw         $0, -0x4BCC($28)
    /* 93A90 00193A90 38B480AF */  sw         $0, -0x4BC8($28)
    /* 93A94 00193A94 5F00053C */  lui        $5, %hi(D_005F6BF0)
    /* 93A98 00193A98 F06BA524 */  addiu      $5, $5, %lo(D_005F6BF0)
    /* 93A9C 00193A9C 10000624 */  addiu      $6, $0, 0x10
    /* 93AA0 00193AA0 2D380000 */  daddu      $7, $0, $0
    /* 93AA4 00193AA4 2D400000 */  daddu      $8, $0, $0
    /* 93AA8 00193AA8 1900093C */  lui        $9, %hi(func_001939e0)
    /* 93AAC 00193AAC E0392925 */  addiu      $9, $9, %lo(func_001939e0)
    /* 93AB0 00193AB0 2D500000 */  daddu      $10, $0, $0
    /* 93AB4 00193AB4 2D580000 */  daddu      $11, $0, $0
    /* 93AB8 00193AB8 F047110C */  jal        func_00451fc0
    /* 93ABC 00193ABC 00000000 */   nop
    /* 93AC0 00193AC0 0000BFDF */  ld         $31, 0x0($29)
    /* 93AC4 00193AC4 1000BD27 */  addiu      $29, $29, 0x10
    /* 93AC8 00193AC8 0800E003 */  jr         $31
    /* 93ACC 00193ACC 00000000 */   nop
.size func_00193a80, 0x50
