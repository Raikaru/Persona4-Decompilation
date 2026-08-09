.section .text
.set noat
.set noreorder
glabel func_002aabf0
    /* 1AABF0 002AABF0 70FFBD27 */  addiu      $29, $29, -0x90
    /* 1AABF4 002AABF4 6000BFFF */  sd         $31, 0x60($29)
    /* 1AABF8 002AABF8 5000B47F */  sq         $20, 0x50($29)
    /* 1AABFC 002AABFC 4000B37F */  sq         $19, 0x40($29)
    /* 1AAC00 002AAC00 3000B27F */  sq         $18, 0x30($29)
    /* 1AAC04 002AAC04 2000B17F */  sq         $17, 0x20($29)
    /* 1AAC08 002AAC08 1000B07F */  sq         $16, 0x10($29)
    /* 1AAC0C 002AAC0C 0000B4E7 */  swc1       $f20, 0x0($29)
    /* 1AAC10 002AAC10 2DA0A000 */  daddu      $20, $5, $0
    /* 1AAC14 002AAC14 1400A690 */  lbu        $6, 0x14($5)
    /* 1AAC18 002AAC18 1500A490 */  lbu        $4, 0x15($5)
    /* 1AAC1C 002AAC1C 1600A390 */  lbu        $3, 0x16($5)
    /* 1AAC20 002AAC20 1700A290 */  lbu        $2, 0x17($5)
    /* 1AAC24 002AAC24 8C00A6A3 */  sb         $6, 0x8C($29)
    /* 1AAC28 002AAC28 8D00A4A3 */  sb         $4, 0x8D($29)
    /* 1AAC2C 002AAC2C 8E00A3A3 */  sb         $3, 0x8E($29)
    /* 1AAC30 002AAC30 8F00A2A3 */  sb         $2, 0x8F($29)
    /* 1AAC34 002AAC34 0000A3C4 */  lwc1       $f3, 0x0($5)
    /* 1AAC38 002AAC38 0400A2C4 */  lwc1       $f2, 0x4($5)
    /* 1AAC3C 002AAC3C 0800A1C4 */  lwc1       $f1, 0x8($5)
    /* 1AAC40 002AAC40 0C00A0C4 */  lwc1       $f0, 0xC($5)
    /* 1AAC44 002AAC44 7000A3E7 */  swc1       $f3, 0x70($29)
    /* 1AAC48 002AAC48 7400A2E7 */  swc1       $f2, 0x74($29)
    /* 1AAC4C 002AAC4C 7800A1E7 */  swc1       $f1, 0x78($29)
    /* 1AAC50 002AAC50 7C00A0E7 */  swc1       $f0, 0x7C($29)
    /* 1AAC54 002AAC54 1000B4C4 */  lwc1       $f20, 0x10($5)
    /* 1AAC58 002AAC58 1800B38C */  lw         $19, 0x18($5)
    /* 1AAC5C 002AAC5C 00017232 */  andi       $18, $19, 0x100
    /* 1AAC60 002AAC60 05004012 */  beqz       $18, .L002AAC78
    /* 1AAC64 002AAC64 00000000 */   nop
    /* 1AAC68 002AAC68 03000424 */  addiu      $4, $0, 0x3
    /* 1AAC6C 002AAC6C 8800A527 */  addiu      $5, $29, 0x88
    /* 1AAC70 002AAC70 A4D90F0C */  jal        func_003f6690
    /* 1AAC74 002AAC74 00000000 */   nop
  .L002AAC78:
    /* 1AAC78 002AAC78 00027132 */  andi       $17, $19, 0x200
    /* 1AAC7C 002AAC7C 05002012 */  beqz       $17, .L002AAC94
    /* 1AAC80 002AAC80 00000000 */   nop
    /* 1AAC84 002AAC84 02000424 */  addiu      $4, $0, 0x2
    /* 1AAC88 002AAC88 8400A527 */  addiu      $5, $29, 0x84
    /* 1AAC8C 002AAC8C A4D90F0C */  jal        func_003f6690
    /* 1AAC90 002AAC90 00000000 */   nop
  .L002AAC94:
    /* 1AAC94 002AAC94 05004012 */  beqz       $18, .L002AACAC
    /* 1AAC98 002AAC98 00000000 */   nop
    /* 1AAC9C 002AAC9C 03000424 */  addiu      $4, $0, 0x3
    /* 1AACA0 002AACA0 8800A527 */  addiu      $5, $29, 0x88
    /* 1AACA4 002AACA4 A4D90F0C */  jal        func_003f6690
    /* 1AACA8 002AACA8 00000000 */   nop
  .L002AACAC:
    /* 1AACAC 002AACAC 8800103C */  lui        $16, %hi(D_00887300)
    /* 1AACB0 002AACB0 00731026 */  addiu      $16, $16, %lo(D_00887300)
    /* 1AACB4 002AACB4 0A000424 */  addiu      $4, $0, 0xA
    /* 1AACB8 002AACB8 05000524 */  addiu      $5, $0, 0x5
    /* 1AACBC 002AACBC 0000028E */  lw         $2, 0x0($16)
    /* 1AACC0 002AACC0 09F84000 */  jalr       $2
    /* 1AACC4 002AACC4 00000000 */   nop
    /* 1AACC8 002AACC8 0B000424 */  addiu      $4, $0, 0xB
    /* 1AACCC 002AACCC 06000524 */  addiu      $5, $0, 0x6
    /* 1AACD0 002AACD0 0000028E */  lw         $2, 0x0($16)
    /* 1AACD4 002AACD4 09F84000 */  jalr       $2
    /* 1AACD8 002AACD8 00000000 */   nop
    /* 1AACDC 002AACDC 0E000424 */  addiu      $4, $0, 0xE
    /* 1AACE0 002AACE0 2D280000 */  daddu      $5, $0, $0
    /* 1AACE4 002AACE4 0000028E */  lw         $2, 0x0($16)
    /* 1AACE8 002AACE8 09F84000 */  jalr       $2
    /* 1AACEC 002AACEC 00000000 */   nop
    /* 1AACF0 002AACF0 0C000424 */  addiu      $4, $0, 0xC
    /* 1AACF4 002AACF4 01000524 */  addiu      $5, $0, 0x1
    /* 1AACF8 002AACF8 0000028E */  lw         $2, 0x0($16)
    /* 1AACFC 002AACFC 09F84000 */  jalr       $2
    /* 1AAD00 002AAD00 00000000 */   nop
    /* 1AAD04 002AAD04 07000424 */  addiu      $4, $0, 0x7
    /* 1AAD08 002AAD08 02000524 */  addiu      $5, $0, 0x2
    /* 1AAD0C 002AAD0C 0000028E */  lw         $2, 0x0($16)
    /* 1AAD10 002AAD10 09F84000 */  jalr       $2
    /* 1AAD14 002AAD14 00000000 */   nop
    /* 1AAD18 002AAD18 09000424 */  addiu      $4, $0, 0x9
    /* 1AAD1C 002AAD1C 02000524 */  addiu      $5, $0, 0x2
    /* 1AAD20 002AAD20 0000028E */  lw         $2, 0x0($16)
    /* 1AAD24 002AAD24 09F84000 */  jalr       $2
    /* 1AAD28 002AAD28 00000000 */   nop
    /* 1AAD2C 002AAD2C 02000424 */  addiu      $4, $0, 0x2
    /* 1AAD30 002AAD30 04000524 */  addiu      $5, $0, 0x4
    /* 1AAD34 002AAD34 0000028E */  lw         $2, 0x0($16)
    /* 1AAD38 002AAD38 09F84000 */  jalr       $2
    /* 1AAD3C 002AAD3C 00000000 */   nop
    /* 1AAD40 002AAD40 14000424 */  addiu      $4, $0, 0x14
    /* 1AAD44 002AAD44 01000524 */  addiu      $5, $0, 0x1
    /* 1AAD48 002AAD48 0000028E */  lw         $2, 0x0($16)
    /* 1AAD4C 002AAD4C 09F84000 */  jalr       $2
    /* 1AAD50 002AAD50 00000000 */   nop
    /* 1AAD54 002AAD54 06000424 */  addiu      $4, $0, 0x6
    /* 1AAD58 002AAD58 2D280000 */  daddu      $5, $0, $0
    /* 1AAD5C 002AAD5C 0000028E */  lw         $2, 0x0($16)
    /* 1AAD60 002AAD60 09F84000 */  jalr       $2
    /* 1AAD64 002AAD64 00000000 */   nop
    /* 1AAD68 002AAD68 08000424 */  addiu      $4, $0, 0x8
    /* 1AAD6C 002AAD6C 2D280000 */  daddu      $5, $0, $0
    /* 1AAD70 002AAD70 0000028E */  lw         $2, 0x0($16)
    /* 1AAD74 002AAD74 09F84000 */  jalr       $2
    /* 1AAD78 002AAD78 00000000 */   nop
    /* 1AAD7C 002AAD7C 03000424 */  addiu      $4, $0, 0x3
    /* 1AAD80 002AAD80 0500023C */  lui        $2, (0x50003 >> 16)
    /* 1AAD84 002AAD84 03004534 */  ori        $5, $2, (0x50003 & 0xFFFF)
    /* 1AAD88 002AAD88 10D90F0C */  jal        func_003f6440
    /* 1AAD8C 002AAD8C 00000000 */   nop
    /* 1AAD90 002AAD90 02000424 */  addiu      $4, $0, 0x2
    /* 1AAD94 002AAD94 44000524 */  addiu      $5, $0, 0x44
    /* 1AAD98 002AAD98 10D90F0C */  jal        func_003f6440
    /* 1AAD9C 002AAD9C 00000000 */   nop
    /* 1AADA0 002AADA0 01000424 */  addiu      $4, $0, 0x1
    /* 1AADA4 002AADA4 2D280000 */  daddu      $5, $0, $0
    /* 1AADA8 002AADA8 0000028E */  lw         $2, 0x0($16)
    /* 1AADAC 002AADAC 09F84000 */  jalr       $2
    /* 1AADB0 002AADB0 00000000 */   nop
    /* 1AADB4 002AADB4 05004012 */  beqz       $18, .L002AADCC
    /* 1AADB8 002AADB8 00000000 */   nop
    /* 1AADBC 002AADBC 03000424 */  addiu      $4, $0, 0x3
    /* 1AADC0 002AADC0 8800A58F */  lw         $5, 0x88($29)
    /* 1AADC4 002AADC4 10D90F0C */  jal        func_003f6440
    /* 1AADC8 002AADC8 00000000 */   nop
  .L002AADCC:
    /* 1AADCC 002AADCC 05002012 */  beqz       $17, .L002AADE4
    /* 1AADD0 002AADD0 00000000 */   nop
    /* 1AADD4 002AADD4 02000424 */  addiu      $4, $0, 0x2
    /* 1AADD8 002AADD8 8400A58F */  lw         $5, 0x84($29)
    /* 1AADDC 002AADDC 10D90F0C */  jal        func_003f6440
    /* 1AADE0 002AADE0 00000000 */   nop
  .L002AADE4:
    /* 1AADE4 002AADE4 01006232 */  andi       $2, $19, 0x1
    /* 1AADE8 002AADE8 06004010 */  beqz       $2, .L002AAE04
    /* 1AADEC 002AADEC 00000000 */   nop
    /* 1AADF0 002AADF0 06000424 */  addiu      $4, $0, 0x6
    /* 1AADF4 002AADF4 01000524 */  addiu      $5, $0, 0x1
    /* 1AADF8 002AADF8 0000028E */  lw         $2, 0x0($16)
    /* 1AADFC 002AADFC 09F84000 */  jalr       $2
    /* 1AAE00 002AAE00 00000000 */   nop
  .L002AAE04:
    /* 1AAE04 002AAE04 02006232 */  andi       $2, $19, 0x2
    /* 1AAE08 002AAE08 06004010 */  beqz       $2, .L002AAE24
    /* 1AAE0C 002AAE0C 00000000 */   nop
    /* 1AAE10 002AAE10 08000424 */  addiu      $4, $0, 0x8
    /* 1AAE14 002AAE14 01000524 */  addiu      $5, $0, 0x1
    /* 1AAE18 002AAE18 0000028E */  lw         $2, 0x0($16)
    /* 1AAE1C 002AAE1C 09F84000 */  jalr       $2
    /* 1AAE20 002AAE20 00000000 */   nop
  .L002AAE24:
    /* 1AAE24 002AAE24 04006232 */  andi       $2, $19, 0x4
    /* 1AAE28 002AAE28 06004010 */  beqz       $2, .L002AAE44
    /* 1AAE2C 002AAE2C 00000000 */   nop
    /* 1AAE30 002AAE30 03000424 */  addiu      $4, $0, 0x3
    /* 1AAE34 002AAE34 0500023C */  lui        $2, (0x5000D >> 16)
    /* 1AAE38 002AAE38 0D004534 */  ori        $5, $2, (0x5000D & 0xFFFF)
    /* 1AAE3C 002AAE3C 10D90F0C */  jal        func_003f6440
    /* 1AAE40 002AAE40 00000000 */   nop
  .L002AAE44:
    /* 1AAE44 002AAE44 08006232 */  andi       $2, $19, 0x8
    /* 1AAE48 002AAE48 05004010 */  beqz       $2, .L002AAE60
    /* 1AAE4C 002AAE4C 00000000 */   nop
    /* 1AAE50 002AAE50 02000424 */  addiu      $4, $0, 0x2
    /* 1AAE54 002AAE54 54000524 */  addiu      $5, $0, 0x54
    /* 1AAE58 002AAE58 10D90F0C */  jal        func_003f6440
    /* 1AAE5C 002AAE5C 00000000 */   nop
  .L002AAE60:
    /* 1AAE60 002AAE60 20006232 */  andi       $2, $19, 0x20
    /* 1AAE64 002AAE64 05004010 */  beqz       $2, .L002AAE7C
    /* 1AAE68 002AAE68 00000000 */   nop
    /* 1AAE6C 002AAE6C 02000424 */  addiu      $4, $0, 0x2
    /* 1AAE70 002AAE70 58000524 */  addiu      $5, $0, 0x58
    /* 1AAE74 002AAE74 10D90F0C */  jal        func_003f6440
    /* 1AAE78 002AAE78 00000000 */   nop
  .L002AAE7C:
    /* 1AAE7C 002AAE7C 40007132 */  andi       $17, $19, 0x40
    /* 1AAE80 002AAE80 03002012 */  beqz       $17, .L002AAE90
    /* 1AAE84 002AAE84 00000000 */   nop
    /* 1AAE88 002AAE88 14930D0C */  jal        func_00364c50
    /* 1AAE8C 002AAE8C 00000000 */   nop
  .L002AAE90:
    /* 1AAE90 002AAE90 10007032 */  andi       $16, $19, 0x10
    /* 1AAE94 002AAE94 03000012 */  beqz       $16, .L002AAEA4
    /* 1AAE98 002AAE98 00000000 */   nop
    /* 1AAE9C 002AAE9C E027120C */  jal        func_00489f80
    /* 1AAEA0 002AAEA0 00000000 */   nop
  .L002AAEA4:
    /* 1AAEA4 002AAEA4 8C00A427 */  addiu      $4, $29, 0x8C
    /* 1AAEA8 002AAEA8 7000A527 */  addiu      $5, $29, 0x70
    /* 1AAEAC 002AAEAC 06A30046 */  mov.s      $f12, $f20
    /* 1AAEB0 002AAEB0 2D300000 */  daddu      $6, $0, $0
    /* 1AAEB4 002AAEB4 B875110C */  jal        func_0045d6e0
    /* 1AAEB8 002AAEB8 00000000 */   nop
    /* 1AAEBC 002AAEBC 03000012 */  beqz       $16, .L002AAECC
    /* 1AAEC0 002AAEC0 00000000 */   nop
    /* 1AAEC4 002AAEC4 0028120C */  jal        func_0048a000
    /* 1AAEC8 002AAEC8 00000000 */   nop
  .L002AAECC:
    /* 1AAECC 002AAECC 03002012 */  beqz       $17, .L002AAEDC
    /* 1AAED0 002AAED0 00000000 */   nop
    /* 1AAED4 002AAED4 1C930D0C */  jal        func_00364c70
    /* 1AAED8 002AAED8 00000000 */   nop
  .L002AAEDC:
    /* 1AAEDC 002AAEDC 2D208002 */  daddu      $4, $20, $0
    /* 1AAEE0 002AAEE0 8800023C */  lui        $2, %hi(jtbl_008873EC)
    /* 1AAEE4 002AAEE4 EC73428C */  lw         $2, %lo(jtbl_008873EC)($2)
    /* 1AAEE8 002AAEE8 09F84000 */  jalr       $2
    /* 1AAEEC 002AAEEC 00000000 */   nop
    /* 1AAEF0 002AAEF0 6000BFDF */  ld         $31, 0x60($29)
    /* 1AAEF4 002AAEF4 5000B47B */  lq         $20, 0x50($29)
    /* 1AAEF8 002AAEF8 4000B37B */  lq         $19, 0x40($29)
    /* 1AAEFC 002AAEFC 3000B27B */  lq         $18, 0x30($29)
    /* 1AAF00 002AAF00 2000B17B */  lq         $17, 0x20($29)
    /* 1AAF04 002AAF04 1000B07B */  lq         $16, 0x10($29)
    /* 1AAF08 002AAF08 0000B4C7 */  lwc1       $f20, 0x0($29)
    /* 1AAF0C 002AAF0C 9000BD27 */  addiu      $29, $29, 0x90
    /* 1AAF10 002AAF10 0800E003 */  jr         $31
    /* 1AAF14 002AAF14 00000000 */   nop
    /* 1AAF18 002AAF18 00000000 */  nop
    /* 1AAF1C 002AAF1C 00000000 */  nop
.size func_002aabf0, 0x330
