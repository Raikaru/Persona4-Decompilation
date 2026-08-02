.section .text
.set noat
.set noreorder
glabel func_0014b990
    /* 4B990 0014B990 D0FFBD27 */  addiu      $29, $29, -0x30
    /* 4B994 0014B994 2000BFFF */  sd         $31, 0x20($29)
    /* 4B998 0014B998 1000B17F */  sq         $17, 0x10($29)
    /* 4B99C 0014B99C 0000B07F */  sq         $16, 0x0($29)
    /* 4B9A0 0014B9A0 2D888000 */  daddu      $17, $4, $0
    /* 4B9A4 0014B9A4 5F00043C */  lui        $4, %hi(D_005EFB28)
    /* 4B9A8 0014B9A8 28FB8424 */  addiu      $4, $4, %lo(D_005EFB28)
    /* 4B9AC 0014B9AC 78010524 */  addiu      $5, $0, 0x178
    /* 4B9B0 0014B9B0 A43A110C */  jal        func_0044ea90
    /* 4B9B4 0014B9B4 00000000 */   nop
    /* 4B9B8 0014B9B8 01000424 */  addiu      $4, $0, 0x1
    /* 4B9BC 0014B9BC 04000524 */  addiu      $5, $0, 0x4
    /* 4B9C0 0014B9C0 0400063C */  lui        $6, (0x40000 >> 16)
    /* 4B9C4 0014B9C4 8800023C */  lui        $2, %hi(D_008873F4)
    /* 4B9C8 0014B9C8 F473428C */  lw         $2, %lo(D_008873F4)($2)
    /* 4B9CC 0014B9CC 09F84000 */  jalr       $2
    /* 4B9D0 0014B9D0 00000000 */   nop
    /* 4B9D4 0014B9D4 2D804000 */  daddu      $16, $2, $0
    /* 4B9D8 0014B9D8 04000016 */  bnez       $16, .L0014B9EC
    /* 4B9DC 0014B9DC 00000000 */   nop
    /* 4B9E0 0014B9E0 2D100000 */  daddu      $2, $0, $0
    /* 4B9E4 0014B9E4 0F000010 */  b          .L0014BA24
    /* 4B9E8 0014B9E8 00000000 */   nop
  .L0014B9EC:
    /* 4B9EC 0014B9EC 2D200000 */  daddu      $4, $0, $0
    /* 4B9F0 0014B9F0 5F00053C */  lui        $5, %hi(D_005EFB60)
    /* 4B9F4 0014B9F4 60FBA524 */  addiu      $5, $5, %lo(D_005EFB60)
    /* 4B9F8 0014B9F8 0F000624 */  addiu      $6, $0, 0xF
    /* 4B9FC 0014B9FC 2D380000 */  daddu      $7, $0, $0
    /* 4BA00 0014BA00 2D400000 */  daddu      $8, $0, $0
    /* 4BA04 0014BA04 1500093C */  lui        $9, %hi(func_0014b930)
    /* 4BA08 0014BA08 30B92925 */  addiu      $9, $9, %lo(func_0014b930)
    /* 4BA0C 0014BA0C 15000A3C */  lui        $10, %hi(func_0014b960)
    /* 4BA10 0014BA10 60B94A25 */  addiu      $10, $10, %lo(func_0014b960)
    /* 4BA14 0014BA14 2D580002 */  daddu      $11, $16, $0
    /* 4BA18 0014BA18 F047110C */  jal        func_00451fc0
    /* 4BA1C 0014BA1C 00000000 */   nop
    /* 4BA20 0014BA20 000011AE */  sw         $17, 0x0($16)
  .L0014BA24:
    /* 4BA24 0014BA24 2000BFDF */  ld         $31, 0x20($29)
    /* 4BA28 0014BA28 1000B17B */  lq         $17, 0x10($29)
    /* 4BA2C 0014BA2C 0000B07B */  lq         $16, 0x0($29)
    /* 4BA30 0014BA30 3000BD27 */  addiu      $29, $29, 0x30
    /* 4BA34 0014BA34 0800E003 */  jr         $31
    /* 4BA38 0014BA38 00000000 */   nop
    /* 4BA3C 0014BA3C 00000000 */  nop
.size func_0014b990, 0xb0
