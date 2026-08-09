.section .text
.set noat
.set noreorder
glabel func_0018bb20
    /* 8BB20 0018BB20 C0FFBD27 */  addiu      $29, $29, -0x40
    /* 8BB24 0018BB24 3000BFFF */  sd         $31, 0x30($29)
    /* 8BB28 0018BB28 2000B27F */  sq         $18, 0x20($29)
    /* 8BB2C 0018BB2C 1000B17F */  sq         $17, 0x10($29)
    /* 8BB30 0018BB30 0000B07F */  sq         $16, 0x0($29)
    /* 8BB34 0018BB34 2D888000 */  daddu      $17, $4, $0
    /* 8BB38 0018BB38 2D90A000 */  daddu      $18, $5, $0
    /* 8BB3C 0018BB3C 5F00043C */  lui        $4, %hi(D_005F5340)
    /* 8BB40 0018BB40 40538424 */  addiu      $4, $4, %lo(D_005F5340)
    /* 8BB44 0018BB44 E6020524 */  addiu      $5, $0, 0x2E6
    /* 8BB48 0018BB48 A43A110C */  jal        func_0044ea90
    /* 8BB4C 0018BB4C 00000000 */   nop
    /* 8BB50 0018BB50 01000424 */  addiu      $4, $0, 0x1
    /* 8BB54 0018BB54 58000524 */  addiu      $5, $0, 0x58
    /* 8BB58 0018BB58 0400063C */  lui        $6, (0x40000 >> 16)
    /* 8BB5C 0018BB5C 8800023C */  lui        $2, %hi(D_008873F4)
    /* 8BB60 0018BB60 F473428C */  lw         $2, %lo(D_008873F4)($2)
    /* 8BB64 0018BB64 09F84000 */  jalr       $2
    /* 8BB68 0018BB68 00000000 */   nop
    /* 8BB6C 0018BB6C 2D804000 */  daddu      $16, $2, $0
    /* 8BB70 0018BB70 04000016 */  bnez       $16, .L0018BB84
    /* 8BB74 0018BB74 00000000 */   nop
    /* 8BB78 0018BB78 2D100000 */  daddu      $2, $0, $0
    /* 8BB7C 0018BB7C 15000010 */  b          .L0018BBD4
    /* 8BB80 0018BB80 00000000 */   nop
  .L0018BB84:
    /* 8BB84 0018BB84 2D202002 */  daddu      $4, $17, $0
    /* 8BB88 0018BB88 5F00053C */  lui        $5, %hi(D_005F5350)
    /* 8BB8C 0018BB8C 5053A524 */  addiu      $5, $5, %lo(D_005F5350)
    /* 8BB90 0018BB90 0F000624 */  addiu      $6, $0, 0xF
    /* 8BB94 0018BB94 2D380000 */  daddu      $7, $0, $0
    /* 8BB98 0018BB98 2D400000 */  daddu      $8, $0, $0
    /* 8BB9C 0018BB9C 1900093C */  lui        $9, %hi(func_0018a200)
    /* 8BBA0 0018BBA0 00A22925 */  addiu      $9, $9, %lo(func_0018a200)
    /* 8BBA4 0018BBA4 19000A3C */  lui        $10, %hi(func_0018bad0)
    /* 8BBA8 0018BBA8 D0BA4A25 */  addiu      $10, $10, %lo(func_0018bad0)
    /* 8BBAC 0018BBAC 2D580002 */  daddu      $11, $16, $0
    /* 8BBB0 0018BBB0 F047110C */  jal        func_00451fc0
    /* 8BBB4 0018BBB4 00000000 */   nop
    /* 8BBB8 0018BBB8 2D884000 */  daddu      $17, $2, $0
    /* 8BBBC 0018BBBC 0C0012AE */  sw         $18, 0xC($16)
    /* 8BBC0 0018BBC0 485C110C */  jal        func_00457120
    /* 8BBC4 0018BBC4 00000000 */   nop
    /* 8BBC8 0018BBC8 800040C4 */  lwc1       $f0, 0x80($2)
    /* 8BBCC 0018BBCC 480000E6 */  swc1       $f0, 0x48($16)
    /* 8BBD0 0018BBD0 2D102002 */  daddu      $2, $17, $0
  .L0018BBD4:
    /* 8BBD4 0018BBD4 3000BFDF */  ld         $31, 0x30($29)
    /* 8BBD8 0018BBD8 2000B27B */  lq         $18, 0x20($29)
    /* 8BBDC 0018BBDC 1000B17B */  lq         $17, 0x10($29)
    /* 8BBE0 0018BBE0 0000B07B */  lq         $16, 0x0($29)
    /* 8BBE4 0018BBE4 4000BD27 */  addiu      $29, $29, 0x40
    /* 8BBE8 0018BBE8 0800E003 */  jr         $31
    /* 8BBEC 0018BBEC 00000000 */   nop
.size func_0018bb20, 0xd0
