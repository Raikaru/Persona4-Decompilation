.section .text
.set noat
.set noreorder
glabel func_002bc9e0
    /* 1BC9E0 002BC9E0 A0FFBD27 */  addiu      $29, $29, -0x60
    /* 1BC9E4 002BC9E4 3000BFFF */  sd         $31, 0x30($29)
    /* 1BC9E8 002BC9E8 2000B27F */  sq         $18, 0x20($29)
    /* 1BC9EC 002BC9EC 1000B17F */  sq         $17, 0x10($29)
    /* 1BC9F0 002BC9F0 0000B07F */  sq         $16, 0x0($29)
    /* 1BC9F4 002BC9F4 2D808000 */  daddu      $16, $4, $0
    /* 1BC9F8 002BC9F8 06000016 */  bnez       $16, .L002BCA14
    /* 1BC9FC 002BC9FC 00000000 */   nop
    /* 1BCA00 002BCA00 6400043C */  lui        $4, %hi(D_0063F2A0)
    /* 1BCA04 002BCA04 A0F28424 */  addiu      $4, $4, %lo(D_0063F2A0)
    /* 1BCA08 002BCA08 58050524 */  addiu      $5, $0, 0x558
    /* 1BCA0C 002BCA0C CCB5110C */  jal        func_0046d730
    /* 1BCA10 002BCA10 00000000 */   nop
  .L002BCA14:
    /* 1BCA14 002BCA14 1800028E */  lw         $2, 0x18($16)
    /* 1BCA18 002BCA18 0400528C */  lw         $18, 0x4($2)
    /* 1BCA1C 002BCA1C 38004012 */  beqz       $18, .L002BCB00
    /* 1BCA20 002BCA20 00000000 */   nop
    /* 1BCA24 002BCA24 1400518E */  lw         $17, 0x14($18)
    /* 1BCA28 002BCA28 0800248E */  lw         $4, 0x8($17)
    /* 1BCA2C 002BCA2C 28008014 */  bnez       $4, .L002BCAD0
    /* 1BCA30 002BCA30 00000000 */   nop
    /* 1BCA34 002BCA34 0400228E */  lw         $2, 0x4($17)
    /* 1BCA38 002BCA38 08004014 */  bnez       $2, .L002BCA5C
    /* 1BCA3C 002BCA3C 00000000 */   nop
    /* 1BCA40 002BCA40 4000A427 */  addiu      $4, $29, 0x40
    /* 1BCA44 002BCA44 6400053C */  lui        $5, %hi(D_0063F340)
    /* 1BCA48 002BCA48 40F3A524 */  addiu      $5, $5, %lo(D_0063F340)
    /* 1BCA4C 002BCA4C 2208110C */  jal        func_00442088
    /* 1BCA50 002BCA50 00000000 */   nop
    /* 1BCA54 002BCA54 18000010 */  b          .L002BCAB8
    /* 1BCA58 002BCA58 00000000 */   nop
  .L002BCA5C:
    /* 1BCA5C 002BCA5C 2C18040C */  jal        func_001060b0
    /* 1BCA60 002BCA60 00000000 */   nop
    /* 1BCA64 002BCA64 3C240200 */  dsll32     $4, $2, 16
    /* 1BCA68 002BCA68 3F240400 */  dsra32     $4, $4, 16
    /* 1BCA6C 002BCA6C 5843040C */  jal        func_00110d60
    /* 1BCA70 002BCA70 00000000 */   nop
    /* 1BCA74 002BCA74 01004230 */  andi       $2, $2, 0x1
    /* 1BCA78 002BCA78 09004010 */  beqz       $2, .L002BCAA0
    /* 1BCA7C 002BCA7C 00000000 */   nop
    /* 1BCA80 002BCA80 4000A427 */  addiu      $4, $29, 0x40
    /* 1BCA84 002BCA84 6400053C */  lui        $5, %hi(D_0063F360)
    /* 1BCA88 002BCA88 60F3A524 */  addiu      $5, $5, %lo(D_0063F360)
    /* 1BCA8C 002BCA8C 0400268E */  lw         $6, 0x4($17)
    /* 1BCA90 002BCA90 2208110C */  jal        func_00442088
    /* 1BCA94 002BCA94 00000000 */   nop
    /* 1BCA98 002BCA98 07000010 */  b          .L002BCAB8
    /* 1BCA9C 002BCA9C 00000000 */   nop
  .L002BCAA0:
    /* 1BCAA0 002BCAA0 4000A427 */  addiu      $4, $29, 0x40
    /* 1BCAA4 002BCAA4 6400053C */  lui        $5, %hi(D_0063F380)
    /* 1BCAA8 002BCAA8 80F3A524 */  addiu      $5, $5, %lo(D_0063F380)
    /* 1BCAAC 002BCAAC 0400268E */  lw         $6, 0x4($17)
    /* 1BCAB0 002BCAB0 2208110C */  jal        func_00442088
    /* 1BCAB4 002BCAB4 00000000 */   nop
  .L002BCAB8:
    /* 1BCAB8 002BCAB8 4000A427 */  addiu      $4, $29, 0x40
    /* 1BCABC 002BCABC A8AB110C */  jal        func_0046aea0
    /* 1BCAC0 002BCAC0 00000000 */   nop
    /* 1BCAC4 002BCAC4 080022AE */  sw         $2, 0x8($17)
    /* 1BCAC8 002BCAC8 0D000010 */  b          .L002BCB00
    /* 1BCACC 002BCACC 00000000 */   nop
  .L002BCAD0:
    /* 1BCAD0 002BCAD0 D4A9110C */  jal        func_0046a750
    /* 1BCAD4 002BCAD4 00000000 */   nop
    /* 1BCAD8 002BCAD8 09004010 */  beqz       $2, .L002BCB00
    /* 1BCADC 002BCADC 00000000 */   nop
    /* 1BCAE0 002BCAE0 0000228E */  lw         $2, 0x0($17)
    /* 1BCAE4 002BCAE4 02004234 */  ori        $2, $2, 0x2
    /* 1BCAE8 002BCAE8 000022AE */  sw         $2, 0x0($17)
    /* 1BCAEC 002BCAEC 1800048E */  lw         $4, 0x18($16)
    /* 1BCAF0 002BCAF0 04008524 */  addiu      $5, $4, 0x4
    /* 1BCAF4 002BCAF4 2D304002 */  daddu      $6, $18, $0
    /* 1BCAF8 002BCAF8 90880B0C */  jal        func_002e2240
    /* 1BCAFC 002BCAFC 00000000 */   nop
  .L002BCB00:
    /* 1BCB00 002BCB00 1C001026 */  addiu      $16, $16, 0x1C
    /* 1BCB04 002BCB04 2D880000 */  daddu      $17, $0, $0
    /* 1BCB08 002BCB08 21000010 */  b          .L002BCB90
    /* 1BCB0C 002BCB0C 00000000 */   nop
  .L002BCB10:
    /* 1BCB10 002BCB10 0000038E */  lw         $3, 0x0($16)
    /* 1BCB14 002BCB14 04006230 */  andi       $2, $3, 0x4
    /* 1BCB18 002BCB18 1B004010 */  beqz       $2, .L002BCB88
    /* 1BCB1C 002BCB1C 00000000 */   nop
    /* 1BCB20 002BCB20 0800048E */  lw         $4, 0x8($16)
    /* 1BCB24 002BCB24 12008010 */  beqz       $4, .L002BCB70
    /* 1BCB28 002BCB28 00000000 */   nop
    /* 1BCB2C 002BCB2C D4A9110C */  jal        func_0046a750
    /* 1BCB30 002BCB30 00000000 */   nop
    /* 1BCB34 002BCB34 14004010 */  beqz       $2, .L002BCB88
    /* 1BCB38 002BCB38 00000000 */   nop
    /* 1BCB3C 002BCB3C 0000038E */  lw         $3, 0x0($16)
    /* 1BCB40 002BCB40 FBFF0224 */  addiu      $2, $0, -0x5
    /* 1BCB44 002BCB44 24186200 */  and        $3, $3, $2
    /* 1BCB48 002BCB48 000003AE */  sw         $3, 0x0($16)
    /* 1BCB4C 002BCB4C FDFF0224 */  addiu      $2, $0, -0x3
    /* 1BCB50 002BCB50 24106200 */  and        $2, $3, $2
    /* 1BCB54 002BCB54 000002AE */  sw         $2, 0x0($16)
    /* 1BCB58 002BCB58 0800048E */  lw         $4, 0x8($16)
    /* 1BCB5C 002BCB5C 34AC110C */  jal        func_0046b0d0
    /* 1BCB60 002BCB60 00000000 */   nop
    /* 1BCB64 002BCB64 080000AE */  sw         $0, 0x8($16)
    /* 1BCB68 002BCB68 07000010 */  b          .L002BCB88
    /* 1BCB6C 002BCB6C 00000000 */   nop
  .L002BCB70:
    /* 1BCB70 002BCB70 FBFF0224 */  addiu      $2, $0, -0x5
    /* 1BCB74 002BCB74 24186200 */  and        $3, $3, $2
    /* 1BCB78 002BCB78 000003AE */  sw         $3, 0x0($16)
    /* 1BCB7C 002BCB7C FDFF0224 */  addiu      $2, $0, -0x3
    /* 1BCB80 002BCB80 24106200 */  and        $2, $3, $2
    /* 1BCB84 002BCB84 000002AE */  sw         $2, 0x0($16)
  .L002BCB88:
    /* 1BCB88 002BCB88 0C001026 */  addiu      $16, $16, 0xC
    /* 1BCB8C 002BCB8C 01003126 */  addiu      $17, $17, 0x1
  .L002BCB90:
    /* 1BCB90 002BCB90 0B00222A */  slti       $2, $17, 0xB
    /* 1BCB94 002BCB94 DEFF4014 */  bnez       $2, .L002BCB10
    /* 1BCB98 002BCB98 00000000 */   nop
    /* 1BCB9C 002BCB9C 2D100000 */  daddu      $2, $0, $0
    /* 1BCBA0 002BCBA0 3000BFDF */  ld         $31, 0x30($29)
    /* 1BCBA4 002BCBA4 2000B27B */  lq         $18, 0x20($29)
    /* 1BCBA8 002BCBA8 1000B17B */  lq         $17, 0x10($29)
    /* 1BCBAC 002BCBAC 0000B07B */  lq         $16, 0x0($29)
    /* 1BCBB0 002BCBB0 6000BD27 */  addiu      $29, $29, 0x60
    /* 1BCBB4 002BCBB4 0800E003 */  jr         $31
    /* 1BCBB8 002BCBB8 00000000 */   nop
    /* 1BCBBC 002BCBBC 00000000 */  nop
.size func_002bc9e0, 0x1e0
