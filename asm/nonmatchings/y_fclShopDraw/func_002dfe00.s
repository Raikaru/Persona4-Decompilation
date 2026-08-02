.section .text
.set noat
.set noreorder
glabel func_002dfe00
    /* 1DFE00 002DFE00 C0FFBD27 */  addiu      $29, $29, -0x40
    /* 1DFE04 002DFE04 2000BFFF */  sd         $31, 0x20($29)
    /* 1DFE08 002DFE08 1000B17F */  sq         $17, 0x10($29)
    /* 1DFE0C 002DFE0C 0000B07F */  sq         $16, 0x0($29)
    /* 1DFE10 002DFE10 2D888000 */  daddu      $17, $4, $0
    /* 1DFE14 002DFE14 3800908C */  lw         $16, 0x38($4)
    /* 1DFE18 002DFE18 180C0286 */  lh         $2, 0xC18($16)
    /* 1DFE1C 002DFE1C 40100200 */  sll        $2, $2, 1
    /* 1DFE20 002DFE20 21105000 */  addu       $2, $2, $16
    /* 1DFE24 002DFE24 16004484 */  lh         $4, 0x16($2)
    /* 1DFE28 002DFE28 C81A040C */  jal        func_00106b20
    /* 1DFE2C 002DFE2C 00000000 */   nop
    /* 1DFE30 002DFE30 0F00033C */  lui        $3, (0xFFF00 >> 16)
    /* 1DFE34 002DFE34 00FF6334 */  ori        $3, $3, (0xFFF00 & 0xFFFF)
    /* 1DFE38 002DFE38 24104300 */  and        $2, $2, $3
    /* 1DFE3C 002DFE3C 03120200 */  sra        $2, $2, 8
    /* 1DFE40 002DFE40 FFFF4430 */  andi       $4, $2, 0xFFFF
    /* 1DFE44 002DFE44 3800A4AF */  sw         $4, 0x38($29)
    /* 1DFE48 002DFE48 3C00A0AF */  sw         $0, 0x3C($29)
    /* 1DFE4C 002DFE4C 407F0B0C */  jal        func_002dfd00
    /* 1DFE50 002DFE50 00000000 */   nop
    /* 1DFE54 002DFE54 0A004014 */  bnez       $2, .L002DFE80
    /* 1DFE58 002DFE58 00000000 */   nop
    /* 1DFE5C 002DFE5C 2D202002 */  daddu      $4, $17, $0
    /* 1DFE60 002DFE60 07000524 */  addiu      $5, $0, 0x7
    /* 1DFE64 002DFE64 3800A627 */  addiu      $6, $29, 0x38
    /* 1DFE68 002DFE68 2D380000 */  daddu      $7, $0, $0
    /* 1DFE6C 002DFE6C B07F0B0C */  jal        func_002dfec0
    /* 1DFE70 002DFE70 00000000 */   nop
    /* 1DFE74 002DFE74 100002A2 */  sb         $2, 0x10($16)
    /* 1DFE78 002DFE78 08000010 */  b          .L002DFE9C
    /* 1DFE7C 002DFE7C 00000000 */   nop
  .L002DFE80:
    /* 1DFE80 002DFE80 2D202002 */  daddu      $4, $17, $0
    /* 1DFE84 002DFE84 08000524 */  addiu      $5, $0, 0x8
    /* 1DFE88 002DFE88 3800A627 */  addiu      $6, $29, 0x38
    /* 1DFE8C 002DFE8C 2D380000 */  daddu      $7, $0, $0
    /* 1DFE90 002DFE90 B07F0B0C */  jal        func_002dfec0
    /* 1DFE94 002DFE94 00000000 */   nop
    /* 1DFE98 002DFE98 100002A2 */  sb         $2, 0x10($16)
  .L002DFE9C:
    /* 1DFE9C 002DFE9C 2000BFDF */  ld         $31, 0x20($29)
    /* 1DFEA0 002DFEA0 1000B17B */  lq         $17, 0x10($29)
    /* 1DFEA4 002DFEA4 0000B07B */  lq         $16, 0x0($29)
    /* 1DFEA8 002DFEA8 4000BD27 */  addiu      $29, $29, 0x40
    /* 1DFEAC 002DFEAC 0800E003 */  jr         $31
    /* 1DFEB0 002DFEB0 00000000 */   nop
    /* 1DFEB4 002DFEB4 00000000 */  nop
    /* 1DFEB8 002DFEB8 00000000 */  nop
    /* 1DFEBC 002DFEBC 00000000 */  nop
.size func_002dfe00, 0xc0
