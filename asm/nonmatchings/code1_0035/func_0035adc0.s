.section .text
.set noat
.set noreorder
glabel func_0035adc0
    /* 25ADC0 0035ADC0 B0FFBD27 */  addiu      $29, $29, -0x50
    /* 25ADC4 0035ADC4 4000BFFF */  sd         $31, 0x40($29)
    /* 25ADC8 0035ADC8 3000B37F */  sq         $19, 0x30($29)
    /* 25ADCC 0035ADCC 2000B27F */  sq         $18, 0x20($29)
    /* 25ADD0 0035ADD0 1000B17F */  sq         $17, 0x10($29)
    /* 25ADD4 0035ADD4 0000B07F */  sq         $16, 0x0($29)
    /* 25ADD8 0035ADD8 2D908000 */  daddu      $18, $4, $0
    /* 25ADDC 0035ADDC 2D88A000 */  daddu      $17, $5, $0
    /* 25ADE0 0035ADE0 2D80C000 */  daddu      $16, $6, $0
    /* 25ADE4 0035ADE4 6500043C */  lui        $4, %hi(D_0064CC98)
    /* 25ADE8 0035ADE8 98CC8424 */  addiu      $4, $4, %lo(D_0064CC98)
    /* 25ADEC 0035ADEC ED060524 */  addiu      $5, $0, 0x6ED
    /* 25ADF0 0035ADF0 A43A110C */  jal        func_0044ea90
    /* 25ADF4 0035ADF4 00000000 */   nop
    /* 25ADF8 0035ADF8 01000424 */  addiu      $4, $0, 0x1
    /* 25ADFC 0035ADFC 44010524 */  addiu      $5, $0, 0x144
    /* 25AE00 0035AE00 0400063C */  lui        $6, (0x40000 >> 16)
    /* 25AE04 0035AE04 8800023C */  lui        $2, %hi(D_008873F4)
    /* 25AE08 0035AE08 F473428C */  lw         $2, %lo(D_008873F4)($2)
    /* 25AE0C 0035AE0C 09F84000 */  jalr       $2
    /* 25AE10 0035AE10 00000000 */   nop
    /* 25AE14 0035AE14 2D984000 */  daddu      $19, $2, $0
    /* 25AE18 0035AE18 06006016 */  bnez       $19, .L0035AE34
    /* 25AE1C 0035AE1C 00000000 */   nop
    /* 25AE20 0035AE20 6500043C */  lui        $4, %hi(D_0064CC98)
    /* 25AE24 0035AE24 98CC8424 */  addiu      $4, $4, %lo(D_0064CC98)
    /* 25AE28 0035AE28 EE060524 */  addiu      $5, $0, 0x6EE
    /* 25AE2C 0035AE2C CCB5110C */  jal        func_0046d730
    /* 25AE30 0035AE30 00000000 */   nop
  .L0035AE34:
    /* 25AE34 0035AE34 2D204002 */  daddu      $4, $18, $0
    /* 25AE38 0035AE38 6500053C */  lui        $5, %hi(D_0064CCD0)
    /* 25AE3C 0035AE3C D0CCA524 */  addiu      $5, $5, %lo(D_0064CCD0)
    /* 25AE40 0035AE40 C7000624 */  addiu      $6, $0, 0xC7
    /* 25AE44 0035AE44 2D380000 */  daddu      $7, $0, $0
    /* 25AE48 0035AE48 2D400000 */  daddu      $8, $0, $0
    /* 25AE4C 0035AE4C 3600093C */  lui        $9, %hi(func_0035aec0)
    /* 25AE50 0035AE50 C0AE2925 */  addiu      $9, $9, %lo(func_0035aec0)
    /* 25AE54 0035AE54 36000A3C */  lui        $10, %hi(func_0035af10)
    /* 25AE58 0035AE58 10AF4A25 */  addiu      $10, $10, %lo(func_0035af10)
    /* 25AE5C 0035AE5C 2D586002 */  daddu      $11, $19, $0
    /* 25AE60 0035AE60 F047110C */  jal        func_00451fc0
    /* 25AE64 0035AE64 00000000 */   nop
    /* 25AE68 0035AE68 2D904000 */  daddu      $18, $2, $0
    /* 25AE6C 0035AE6C 200060A2 */  sb         $0, 0x20($19)
    /* 25AE70 0035AE70 2C0060AE */  sw         $0, 0x2C($19)
    /* 25AE74 0035AE74 6500023C */  lui        $2, %hi(D_0064CCB0)
    /* 25AE78 0035AE78 B0CC4224 */  addiu      $2, $2, %lo(D_0064CCB0)
    /* 25AE7C 0035AE7C 400162AE */  sw         $2, 0x140($19)
    /* 25AE80 0035AE80 2D204002 */  daddu      $4, $18, $0
    /* 25AE84 0035AE84 2D282002 */  daddu      $5, $17, $0
    /* 25AE88 0035AE88 2D300002 */  daddu      $6, $16, $0
    /* 25AE8C 0035AE8C 046F0D0C */  jal        func_0035bc10
    /* 25AE90 0035AE90 00000000 */   nop
    /* 25AE94 0035AE94 2D104002 */  daddu      $2, $18, $0
    /* 25AE98 0035AE98 4000BFDF */  ld         $31, 0x40($29)
    /* 25AE9C 0035AE9C 3000B37B */  lq         $19, 0x30($29)
    /* 25AEA0 0035AEA0 2000B27B */  lq         $18, 0x20($29)
    /* 25AEA4 0035AEA4 1000B17B */  lq         $17, 0x10($29)
    /* 25AEA8 0035AEA8 0000B07B */  lq         $16, 0x0($29)
    /* 25AEAC 0035AEAC 5000BD27 */  addiu      $29, $29, 0x50
    /* 25AEB0 0035AEB0 0800E003 */  jr         $31
    /* 25AEB4 0035AEB4 00000000 */   nop
    /* 25AEB8 0035AEB8 00000000 */  nop
    /* 25AEBC 0035AEBC 00000000 */  nop
.size func_0035adc0, 0x100
