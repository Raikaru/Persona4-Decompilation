.section .text
.set noat
.set noreorder
glabel func_002aaa10
    /* 1AAA10 002AAA10 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 1AAA14 002AAA14 0000BFFF */  sd         $31, 0x0($29)
    /* 1AAA18 002AAA18 8800043C */  lui        $4, %hi(D_00882F20)
    /* 1AAA1C 002AAA1C 202F8424 */  addiu      $4, $4, %lo(D_00882F20)
    /* 1AAA20 002AAA20 2D280000 */  daddu      $5, $0, $0
    /* 1AAA24 002AAA24 10000624 */  addiu      $6, $0, 0x10
    /* 1AAA28 002AAA28 72FE100C */  jal        func_0043f9c8
    /* 1AAA2C 002AAA2C 00000000 */   nop
    /* 1AAA30 002AAA30 2D200000 */  daddu      $4, $0, $0
    /* 1AAA34 002AAA34 6400053C */  lui        $5, %hi(D_0063EE40)
    /* 1AAA38 002AAA38 40EEA524 */  addiu      $5, $5, %lo(D_0063EE40)
    /* 1AAA3C 002AAA3C 0F000624 */  addiu      $6, $0, 0xF
    /* 1AAA40 002AAA40 2D380000 */  daddu      $7, $0, $0
    /* 1AAA44 002AAA44 2D400000 */  daddu      $8, $0, $0
    /* 1AAA48 002AAA48 2B00093C */  lui        $9, %hi(func_002aa890)
    /* 1AAA4C 002AAA4C 90A82925 */  addiu      $9, $9, %lo(func_002aa890)
    /* 1AAA50 002AAA50 2B000A3C */  lui        $10, %hi(func_002aaa00)
    /* 1AAA54 002AAA54 00AA4A25 */  addiu      $10, $10, %lo(func_002aaa00)
    /* 1AAA58 002AAA58 2D580000 */  daddu      $11, $0, $0
    /* 1AAA5C 002AAA5C F047110C */  jal        func_00451fc0
    /* 1AAA60 002AAA60 00000000 */   nop
    /* 1AAA64 002AAA64 0000BFDF */  ld         $31, 0x0($29)
    /* 1AAA68 002AAA68 1000BD27 */  addiu      $29, $29, 0x10
    /* 1AAA6C 002AAA6C 0800E003 */  jr         $31
    /* 1AAA70 002AAA70 00000000 */   nop
    /* 1AAA74 002AAA74 00000000 */  nop
    /* 1AAA78 002AAA78 00000000 */  nop
    /* 1AAA7C 002AAA7C 00000000 */  nop
.size func_002aaa10, 0x70
