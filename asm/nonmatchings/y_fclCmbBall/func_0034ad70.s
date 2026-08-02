.section .text
.set noat
.set noreorder
glabel func_0034ad70
    /* 24AD70 0034AD70 B0FFBD27 */  addiu      $29, $29, -0x50
    /* 24AD74 0034AD74 4000BFFF */  sd         $31, 0x40($29)
    /* 24AD78 0034AD78 3000B37F */  sq         $19, 0x30($29)
    /* 24AD7C 0034AD7C 2000B27F */  sq         $18, 0x20($29)
    /* 24AD80 0034AD80 1000B17F */  sq         $17, 0x10($29)
    /* 24AD84 0034AD84 0000B07F */  sq         $16, 0x0($29)
    /* 24AD88 0034AD88 2D988000 */  daddu      $19, $4, $0
    /* 24AD8C 0034AD8C 2D90A000 */  daddu      $18, $5, $0
    /* 24AD90 0034AD90 2D88C000 */  daddu      $17, $6, $0
    /* 24AD94 0034AD94 6500043C */  lui        $4, %hi(D_0064A740)
    /* 24AD98 0034AD98 40A78424 */  addiu      $4, $4, %lo(D_0064A740)
    /* 24AD9C 0034AD9C 98000524 */  addiu      $5, $0, 0x98
    /* 24ADA0 0034ADA0 A43A110C */  jal        func_0044ea90
    /* 24ADA4 0034ADA4 00000000 */   nop
    /* 24ADA8 0034ADA8 01000424 */  addiu      $4, $0, 0x1
    /* 24ADAC 0034ADAC 10180524 */  addiu      $5, $0, 0x1810
    /* 24ADB0 0034ADB0 0400063C */  lui        $6, (0x40000 >> 16)
    /* 24ADB4 0034ADB4 8800023C */  lui        $2, %hi(D_008873F4)
    /* 24ADB8 0034ADB8 F473428C */  lw         $2, %lo(D_008873F4)($2)
    /* 24ADBC 0034ADBC 09F84000 */  jalr       $2
    /* 24ADC0 0034ADC0 00000000 */   nop
    /* 24ADC4 0034ADC4 2D804000 */  daddu      $16, $2, $0
    /* 24ADC8 0034ADC8 2D206002 */  daddu      $4, $19, $0
    /* 24ADCC 0034ADCC 6500053C */  lui        $5, %hi(D_0064A750)
    /* 24ADD0 0034ADD0 50A7A524 */  addiu      $5, $5, %lo(D_0064A750)
    /* 24ADD4 0034ADD4 0F000624 */  addiu      $6, $0, 0xF
    /* 24ADD8 0034ADD8 2D380000 */  daddu      $7, $0, $0
    /* 24ADDC 0034ADDC 2D400000 */  daddu      $8, $0, $0
    /* 24ADE0 0034ADE0 3500093C */  lui        $9, %hi(func_0034ac00)
    /* 24ADE4 0034ADE4 00AC2925 */  addiu      $9, $9, %lo(func_0034ac00)
    /* 24ADE8 0034ADE8 35000A3C */  lui        $10, %hi(func_0034ad40)
    /* 24ADEC 0034ADEC 40AD4A25 */  addiu      $10, $10, %lo(func_0034ad40)
    /* 24ADF0 0034ADF0 2D580002 */  daddu      $11, $16, $0
    /* 24ADF4 0034ADF4 F047110C */  jal        func_00451fc0
    /* 24ADF8 0034ADF8 00000000 */   nop
    /* 24ADFC 0034ADFC 2D200000 */  daddu      $4, $0, $0
    /* 24AE00 0034AE00 06000010 */  b          .L0034AE1C
    /* 24AE04 0034AE04 00000000 */   nop
  .L0034AE08:
    /* 24AE08 0034AE08 401A0400 */  sll        $3, $4, 9
    /* 24AE0C 0034AE0C 21180302 */  addu       $3, $16, $3
    /* 24AE10 0034AE10 040160A4 */  sh         $0, 0x104($3)
    /* 24AE14 0034AE14 000171A4 */  sh         $17, 0x100($3)
    /* 24AE18 0034AE18 01008424 */  addiu      $4, $4, 0x1
  .L0034AE1C:
    /* 24AE1C 0034AE1C 0C008328 */  slti       $3, $4, 0xC
    /* 24AE20 0034AE20 F9FF6014 */  bnez       $3, .L0034AE08
    /* 24AE24 0034AE24 00000000 */   nop
    /* 24AE28 0034AE28 001812A2 */  sb         $18, 0x1800($16)
    /* 24AE2C 0034AE2C 4000BFDF */  ld         $31, 0x40($29)
    /* 24AE30 0034AE30 3000B37B */  lq         $19, 0x30($29)
    /* 24AE34 0034AE34 2000B27B */  lq         $18, 0x20($29)
    /* 24AE38 0034AE38 1000B17B */  lq         $17, 0x10($29)
    /* 24AE3C 0034AE3C 0000B07B */  lq         $16, 0x0($29)
    /* 24AE40 0034AE40 5000BD27 */  addiu      $29, $29, 0x50
    /* 24AE44 0034AE44 0800E003 */  jr         $31
    /* 24AE48 0034AE48 00000000 */   nop
    /* 24AE4C 0034AE4C 00000000 */  nop
.size func_0034ad70, 0xe0
