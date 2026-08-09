.section .text
.set noat
.set noreorder
glabel func_0043ae60
    /* 33AE60 0043AE60 B0FFBD27 */  addiu      $29, $29, -0x50
    /* 33AE64 0043AE64 7100033C */  lui        $3, %hi(D_0070FC40)
    /* 33AE68 0043AE68 2000B1FF */  sd         $17, 0x20($29)
    /* 33AE6C 0043AE6C 40FC628C */  lw         $2, %lo(D_0070FC40)($3)
    /* 33AE70 0043AE70 2D888000 */  daddu      $17, $4, $0
    /* 33AE74 0043AE74 4000BFFF */  sd         $31, 0x40($29)
    /* 33AE78 0043AE78 3000B2FF */  sd         $18, 0x30($29)
    /* 33AE7C 0043AE7C 03004014 */  bnez       $2, .L0043AE8C
    /* 33AE80 0043AE80 1000B0FF */   sd        $16, 0x10($29)
    /* 33AE84 0043AE84 1F000010 */  b          .L0043AF04
    /* 33AE88 0043AE88 2D100000 */   daddu     $2, $0, $0
  .L0043AE8C:
    /* 33AE8C 0043AE8C 8C00123C */  lui        $18, %hi(D_008BE280)
    /* 33AE90 0043AE90 0886100C */  jal        func_00421820
    /* 33AE94 0043AE94 80E2448E */   lw        $4, %lo(D_008BE280)($18)
    /* 33AE98 0043AE98 8C00033C */  lui        $3, %hi(D_008BDAC0)
    /* 33AE9C 0043AE9C 8C00043C */  lui        $4, %hi(D_008BD9C0)
    /* 33AEA0 0043AEA0 C0DA7024 */  addiu      $16, $3, %lo(D_008BDAC0)
    /* 33AEA4 0043AEA4 0080053C */  lui        $5, (0x80001302 >> 16)
    /* 33AEA8 0043AEA8 C0DA71AC */  sw         $17, %lo(D_008BDAC0)($3)
    /* 33AEAC 0043AEAC C0D98424 */  addiu      $4, $4, %lo(D_008BD9C0)
    /* 33AEB0 0043AEB0 0000A0AF */  sw         $0, 0x0($29)
    /* 33AEB4 0043AEB4 0213A534 */  ori        $5, $5, (0x80001302 & 0xFFFF)
    /* 33AEB8 0043AEB8 2D300000 */  daddu      $6, $0, $0
    /* 33AEBC 0043AEBC 2D380002 */  daddu      $7, $16, $0
    /* 33AEC0 0043AEC0 90000824 */  addiu      $8, $0, 0x90
    /* 33AEC4 0043AEC4 2D480002 */  daddu      $9, $16, $0
    /* 33AEC8 0043AEC8 90000A24 */  addiu      $10, $0, 0x90
    /* 33AECC 0043AECC 2C96100C */  jal        func_004258b0
    /* 33AED0 0043AED0 2D580000 */   daddu     $11, $0, $0
    /* 33AED4 0043AED4 08004104 */  bgez       $2, .L0043AEF8
    /* 33AED8 0043AED8 80E2448E */   lw        $4, %lo(D_008BE280)($18)
    /* 33AEDC 0043AEDC 7500043C */  lui        $4, %hi(D_00754B40)
    /* 33AEE0 0043AEE0 D2EE100C */  jal        func_0043bb48
    /* 33AEE4 0043AEE4 404B8424 */   addiu     $4, $4, %lo(D_00754B40)
    /* 33AEE8 0043AEE8 0086100C */  jal        func_00421800
    /* 33AEEC 0043AEEC 80E2448E */   lw        $4, %lo(D_008BE280)($18)
    /* 33AEF0 0043AEF0 04000010 */  b          .L0043AF04
    /* 33AEF4 0043AEF4 2D100000 */   daddu     $2, $0, $0
  .L0043AEF8:
    /* 33AEF8 0043AEF8 0086100C */  jal        func_00421800
    /* 33AEFC 0043AEFC 0400108E */   lw        $16, 0x4($16)
    /* 33AF00 0043AF00 2D100002 */  daddu      $2, $16, $0
  .L0043AF04:
    /* 33AF04 0043AF04 4000BFDF */  ld         $31, 0x40($29)
    /* 33AF08 0043AF08 3000B2DF */  ld         $18, 0x30($29)
    /* 33AF0C 0043AF0C 2000B1DF */  ld         $17, 0x20($29)
    /* 33AF10 0043AF10 1000B0DF */  ld         $16, 0x10($29)
    /* 33AF14 0043AF14 0800E003 */  jr         $31
    /* 33AF18 0043AF18 5000BD27 */   addiu     $29, $29, 0x50
    /* 33AF1C 0043AF1C 00000000 */  nop
.size func_0043ae60, 0xc0
