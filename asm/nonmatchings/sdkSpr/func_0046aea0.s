.section .text
.set noat
.set noreorder
glabel func_0046aea0
    /* 36AEA0 0046AEA0 D0FFBD27 */  addiu      $29, $29, -0x30
    /* 36AEA4 0046AEA4 2000BFFF */  sd         $31, 0x20($29)
    /* 36AEA8 0046AEA8 1000B17F */  sq         $17, 0x10($29)
    /* 36AEAC 0046AEAC 0000B07F */  sq         $16, 0x0($29)
    /* 36AEB0 0046AEB0 2D888000 */  daddu      $17, $4, $0
    /* 36AEB4 0046AEB4 7100043C */  lui        $4, %hi(D_007130C8)
    /* 36AEB8 0046AEB8 C8308424 */  addiu      $4, $4, %lo(D_007130C8)
    /* 36AEBC 0046AEBC 15010524 */  addiu      $5, $0, 0x115
    /* 36AEC0 0046AEC0 A43A110C */  jal        func_0044ea90
    /* 36AEC4 0046AEC4 00000000 */   nop
    /* 36AEC8 0046AEC8 01000424 */  addiu      $4, $0, 0x1
    /* 36AECC 0046AECC 40020524 */  addiu      $5, $0, 0x240
    /* 36AED0 0046AED0 0400063C */  lui        $6, (0x40000 >> 16)
    /* 36AED4 0046AED4 8800023C */  lui        $2, %hi(D_008873F4)
    /* 36AED8 0046AED8 F473428C */  lw         $2, %lo(D_008873F4)($2)
    /* 36AEDC 0046AEDC 09F84000 */  jalr       $2
    /* 36AEE0 0046AEE0 00000000 */   nop
    /* 36AEE4 0046AEE4 2D804000 */  daddu      $16, $2, $0
    /* 36AEE8 0046AEE8 000040A4 */  sh         $0, 0x0($2)
    /* 36AEEC 0046AEEC 02000426 */  addiu      $4, $16, 0x2
    /* 36AEF0 0046AEF0 2D282002 */  daddu      $5, $17, $0
    /* 36AEF4 0046AEF4 0C0A110C */  jal        func_00442830
    /* 36AEF8 0046AEF8 00000000 */   nop
    /* 36AEFC 0046AEFC 18BB838F */  lw         $3, -0x44E8($28)
    /* 36AF00 0046AF00 04006014 */  bnez       $3, .L0046AF14
    /* 36AF04 0046AF04 00000000 */   nop
    /* 36AF08 0046AF08 18BB90AF */  sw         $16, -0x44E8($28)
    /* 36AF0C 0046AF0C 0B000010 */  b          .L0046AF3C
    /* 36AF10 0046AF10 00000000 */   nop
  .L0046AF14:
    /* 36AF14 0046AF14 3802628C */  lw         $2, 0x238($3)
    /* 36AF18 0046AF18 05004014 */  bnez       $2, .L0046AF30
    /* 36AF1C 0046AF1C 00000000 */   nop
    /* 36AF20 0046AF20 380270AC */  sw         $16, 0x238($3)
    /* 36AF24 0046AF24 3C0203AE */  sw         $3, 0x23C($16)
    /* 36AF28 0046AF28 04000010 */  b          .L0046AF3C
    /* 36AF2C 0046AF2C 00000000 */   nop
  .L0046AF30:
    /* 36AF30 0046AF30 2D184000 */  daddu      $3, $2, $0
    /* 36AF34 0046AF34 F7FF0010 */  b          .L0046AF14
    /* 36AF38 0046AF38 00000000 */   nop
  .L0046AF3C:
    /* 36AF3C 0046AF3C 2D100002 */  daddu      $2, $16, $0
    /* 36AF40 0046AF40 2000BFDF */  ld         $31, 0x20($29)
    /* 36AF44 0046AF44 1000B17B */  lq         $17, 0x10($29)
    /* 36AF48 0046AF48 0000B07B */  lq         $16, 0x0($29)
    /* 36AF4C 0046AF4C 3000BD27 */  addiu      $29, $29, 0x30
    /* 36AF50 0046AF50 0800E003 */  jr         $31
    /* 36AF54 0046AF54 00000000 */   nop
    /* 36AF58 0046AF58 00000000 */  nop
    /* 36AF5C 0046AF5C 00000000 */  nop
.size func_0046aea0, 0xc0
