.section .text
.set noat
.set noreorder
glabel func_004db250
    /* 3DB250 004DB250 C0FFBD27 */  addiu      $29, $29, -0x40
    /* 3DB254 004DB254 0000B0FF */  sd         $16, 0x0($29)
    /* 3DB258 004DB258 2D808000 */  daddu      $16, $4, $0
    /* 3DB25C 004DB25C 0800B1FF */  sd         $17, 0x8($29)
    /* 3DB260 004DB260 1000B2FF */  sd         $18, 0x10($29)
    /* 3DB264 004DB264 18001226 */  addiu      $18, $16, 0x18
    /* 3DB268 004DB268 1800B3FF */  sd         $19, 0x18($29)
    /* 3DB26C 004DB26C 2D98A000 */  daddu      $19, $5, $0
    /* 3DB270 004DB270 2000B4FF */  sd         $20, 0x20($29)
    /* 3DB274 004DB274 2800B5FF */  sd         $21, 0x28($29)
    /* 3DB278 004DB278 3000BFFF */  sd         $31, 0x30($29)
    /* 3DB27C 004DB27C C250130C */  jal        func_004d4308
    /* 3DB280 004DB280 2DA0C000 */   daddu     $20, $6, $0
    /* 3DB284 004DB284 E66C130C */  jal        func_004db398
    /* 3DB288 004DB288 2D200002 */   daddu     $4, $16, $0
    /* 3DB28C 004DB28C 7276130C */  jal        func_004dd9c8
    /* 3DB290 004DB290 00000000 */   nop
    /* 3DB294 004DB294 1000118E */  lw         $17, 0x10($16)
    /* 3DB298 004DB298 0400158E */  lw         $21, 0x4($16)
    /* 3DB29C 004DB29C 7432130C */  jal        func_004cc9d0
    /* 3DB2A0 004DB2A0 0400B08E */   lw        $16, 0x4($21)
    /* 3DB2A4 004DB2A4 2D202002 */  daddu      $4, $17, $0
    /* 3DB2A8 004DB2A8 01000524 */  addiu      $5, $0, 0x1
    /* 3DB2AC 004DB2AC 2D304002 */  daddu      $6, $18, $0
    /* 3DB2B0 004DB2B0 2D386002 */  daddu      $7, $19, $0
    /* 3DB2B4 004DB2B4 B076130C */  jal        func_004ddac0
    /* 3DB2B8 004DB2B8 2D408002 */   daddu     $8, $20, $0
    /* 3DB2BC 004DB2BC 4E00033C */  lui        $3, %hi(func_004db460)
    /* 3DB2C0 004DB2C0 4E00053C */  lui        $5, %hi(func_004db430)
    /* 3DB2C4 004DB2C4 2D404000 */  daddu      $8, $2, $0
    /* 3DB2C8 004DB2C8 4E00043C */  lui        $4, %hi(func_004db448)
    /* 3DB2CC 004DB2CC 4E00063C */  lui        $6, %hi(func_004ddc98)
    /* 3DB2D0 004DB2D0 4E00023C */  lui        $2, %hi(func_004db3c0)
    /* 3DB2D4 004DB2D4 4E00073C */  lui        $7, %hi(func_004de290)
    /* 3DB2D8 004DB2D8 30B4AC24 */  addiu      $12, $5, %lo(func_004db430)
    /* 3DB2DC 004DB2DC 7600053C */  lui        $5, %hi(D_00759578)
    /* 3DB2E0 004DB2E0 48B48B24 */  addiu      $11, $4, %lo(func_004db448)
    /* 3DB2E4 004DB2E4 2D200001 */  daddu      $4, $8, $0
    /* 3DB2E8 004DB2E8 C0B34924 */  addiu      $9, $2, %lo(func_004db3c0)
    /* 3DB2EC 004DB2EC 60B46A24 */  addiu      $10, $3, %lo(func_004db460)
    /* 3DB2F0 004DB2F0 98DCC624 */  addiu      $6, $6, %lo(func_004ddc98)
    /* 3DB2F4 004DB2F4 90E2E724 */  addiu      $7, $7, %lo(func_004de290)
    /* 3DB2F8 004DB2F8 0D000015 */  bnez       $8, .L004DB330
    /* 3DB2FC 004DB2FC 7895A524 */   addiu     $5, $5, %lo(D_00759578)
    /* 3DB300 004DB300 7600043C */  lui        $4, %hi(D_00759560)
    /* 3DB304 004DB304 0000B0DF */  ld         $16, 0x0($29)
    /* 3DB308 004DB308 0800B1DF */  ld         $17, 0x8($29)
    /* 3DB30C 004DB30C 60958424 */  addiu      $4, $4, %lo(D_00759560)
    /* 3DB310 004DB310 1000B2DF */  ld         $18, 0x10($29)
    /* 3DB314 004DB314 1800B3DF */  ld         $19, 0x18($29)
    /* 3DB318 004DB318 2000B4DF */  ld         $20, 0x20($29)
    /* 3DB31C 004DB31C 2800B5DF */  ld         $21, 0x28($29)
    /* 3DB320 004DB320 3000BFDF */  ld         $31, 0x30($29)
    /* 3DB324 004DB324 BC1A1308 */  j          func_004c6af0
    /* 3DB328 004DB328 4000BD27 */   addiu     $29, $29, 0x40
    /* 3DB32C 004DB32C 00000000 */  nop
  .L004DB330:
    /* 3DB330 004DB330 7200023C */  lui        $2, %hi(D_00724E74)
    /* 3DB334 004DB334 7100033C */  lui        $3, %hi(D_00714A14)
    /* 3DB338 004DB338 B40008AE */  sw         $8, 0xB4($16)
    /* 3DB33C 004DB33C 744E49AC */  sw         $9, %lo(D_00724E74)($2)
    /* 3DB340 004DB340 7100023C */  lui        $2, %hi(D_00714A10)
    /* 3DB344 004DB344 144A6AAC */  sw         $10, %lo(D_00714A14)($3)
    /* 3DB348 004DB348 7100033C */  lui        $3, %hi(D_00714A0C)
    /* 3DB34C 004DB34C 104A4BAC */  sw         $11, %lo(D_00714A10)($2)
    /* 3DB350 004DB350 7100023C */  lui        $2, %hi(D_00714A08)
    /* 3DB354 004DB354 0C4A6CAC */  sw         $12, %lo(D_00714A0C)($3)
    /* 3DB358 004DB358 7100033C */  lui        $3, %hi(D_00714C28)
    /* 3DB35C 004DB35C 084A46AC */  sw         $6, %lo(D_00714A08)($2)
    /* 3DB360 004DB360 284C67AC */  sw         $7, %lo(D_00714C28)($3)
    /* 3DB364 004DB364 5400A68E */  lw         $6, 0x54($21)
    /* 3DB368 004DB368 4478130C */  jal        func_004de110
    /* 3DB36C 004DB36C 5000A58E */   lw        $5, 0x50($21)
    /* 3DB370 004DB370 0000B0DF */  ld         $16, 0x0($29)
    /* 3DB374 004DB374 0800B1DF */  ld         $17, 0x8($29)
    /* 3DB378 004DB378 1000B2DF */  ld         $18, 0x10($29)
    /* 3DB37C 004DB37C 1800B3DF */  ld         $19, 0x18($29)
    /* 3DB380 004DB380 2000B4DF */  ld         $20, 0x20($29)
    /* 3DB384 004DB384 2800B5DF */  ld         $21, 0x28($29)
    /* 3DB388 004DB388 3000BFDF */  ld         $31, 0x30($29)
    /* 3DB38C 004DB38C 7A321308 */  j          func_004cc9e8
    /* 3DB390 004DB390 4000BD27 */   addiu     $29, $29, 0x40
    /* 3DB394 004DB394 00000000 */  nop
.size func_004db250, 0x148
