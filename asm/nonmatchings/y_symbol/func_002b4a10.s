.section .text
.set noat
.set noreorder
glabel func_002b4a10
    /* 1B4A10 002B4A10 C0FFBD27 */  addiu      $29, $29, -0x40
    /* 1B4A14 002B4A14 3000BFFF */  sd         $31, 0x30($29)
    /* 1B4A18 002B4A18 2000B27F */  sq         $18, 0x20($29)
    /* 1B4A1C 002B4A1C 1000B17F */  sq         $17, 0x10($29)
    /* 1B4A20 002B4A20 0000B07F */  sq         $16, 0x0($29)
    /* 1B4A24 002B4A24 2D908000 */  daddu      $18, $4, $0
    /* 1B4A28 002B4A28 2D88A000 */  daddu      $17, $5, $0
    /* 1B4A2C 002B4A2C 6400043C */  lui        $4, %hi(D_0063F120)
    /* 1B4A30 002B4A30 20F18424 */  addiu      $4, $4, %lo(D_0063F120)
    /* 1B4A34 002B4A34 15020524 */  addiu      $5, $0, 0x215
    /* 1B4A38 002B4A38 A43A110C */  jal        func_0044ea90
    /* 1B4A3C 002B4A3C 00000000 */   nop
    /* 1B4A40 002B4A40 01000424 */  addiu      $4, $0, 0x1
    /* 1B4A44 002B4A44 0C000524 */  addiu      $5, $0, 0xC
    /* 1B4A48 002B4A48 0400063C */  lui        $6, (0x40000 >> 16)
    /* 1B4A4C 002B4A4C 8800023C */  lui        $2, %hi(D_008873F4)
    /* 1B4A50 002B4A50 F473428C */  lw         $2, %lo(D_008873F4)($2)
    /* 1B4A54 002B4A54 09F84000 */  jalr       $2
    /* 1B4A58 002B4A58 00000000 */   nop
    /* 1B4A5C 002B4A5C 2D804000 */  daddu      $16, $2, $0
    /* 1B4A60 002B4A60 2D204002 */  daddu      $4, $18, $0
    /* 1B4A64 002B4A64 6400053C */  lui        $5, %hi(D_0063F150)
    /* 1B4A68 002B4A68 50F1A524 */  addiu      $5, $5, %lo(D_0063F150)
    /* 1B4A6C 002B4A6C 0F000624 */  addiu      $6, $0, 0xF
    /* 1B4A70 002B4A70 2D380000 */  daddu      $7, $0, $0
    /* 1B4A74 002B4A74 2D400000 */  daddu      $8, $0, $0
    /* 1B4A78 002B4A78 2B00093C */  lui        $9, %hi(func_002b4250)
    /* 1B4A7C 002B4A7C 50422925 */  addiu      $9, $9, %lo(func_002b4250)
    /* 1B4A80 002B4A80 2B000A3C */  lui        $10, %hi(func_002b49e0)
    /* 1B4A84 002B4A84 E0494A25 */  addiu      $10, $10, %lo(func_002b49e0)
    /* 1B4A88 002B4A88 2D580002 */  daddu      $11, $16, $0
    /* 1B4A8C 002B4A8C F047110C */  jal        func_00451fc0
    /* 1B4A90 002B4A90 00000000 */   nop
    /* 1B4A94 002B4A94 010011A2 */  sb         $17, 0x1($16)
    /* 1B4A98 002B4A98 3000BFDF */  ld         $31, 0x30($29)
    /* 1B4A9C 002B4A9C 2000B27B */  lq         $18, 0x20($29)
    /* 1B4AA0 002B4AA0 1000B17B */  lq         $17, 0x10($29)
    /* 1B4AA4 002B4AA4 0000B07B */  lq         $16, 0x0($29)
    /* 1B4AA8 002B4AA8 4000BD27 */  addiu      $29, $29, 0x40
    /* 1B4AAC 002B4AAC 0800E003 */  jr         $31
    /* 1B4AB0 002B4AB0 00000000 */   nop
    /* 1B4AB4 002B4AB4 00000000 */  nop
    /* 1B4AB8 002B4AB8 00000000 */  nop
    /* 1B4ABC 002B4ABC 00000000 */  nop
.size func_002b4a10, 0xb0
