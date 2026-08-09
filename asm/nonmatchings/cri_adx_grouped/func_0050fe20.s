.section .text
.set noat
.set noreorder
glabel func_0050fe20
    /* 40FE20 0050FE20 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 40FE24 0050FE24 0000B0FF */  sd         $16, 0x0($29)
    /* 40FE28 0050FE28 0800BFFF */  sd         $31, 0x8($29)
    /* 40FE2C 0050FE2C 0A35140C */  jal        func_0050d428
    /* 40FE30 0050FE30 2D808000 */   daddu     $16, $4, $0
    /* 40FE34 0050FE34 01000324 */  addiu      $3, $0, 0x1
    /* 40FE38 0050FE38 01000524 */  addiu      $5, $0, 0x1
    /* 40FE3C 0050FE3C 08004310 */  beq        $2, $3, .L0050FE60
    /* 40FE40 0050FE40 2D200002 */   daddu     $4, $16, $0
    /* 40FE44 0050FE44 7600043C */  lui        $4, %hi(D_0075FD08)
    /* 40FE48 0050FE48 0000B0DF */  ld         $16, 0x0($29)
    /* 40FE4C 0050FE4C 0800BFDF */  ld         $31, 0x8($29)
    /* 40FE50 0050FE50 08FD8424 */  addiu      $4, $4, %lo(D_0075FD08)
    /* 40FE54 0050FE54 88441408 */  j          func_00511220
    /* 40FE58 0050FE58 1000BD27 */   addiu     $29, $29, 0x10
    /* 40FE5C 0050FE5C 00000000 */  nop
  .L0050FE60:
    /* 40FE60 0050FE60 3041140C */  jal        func_005104c0
    /* 40FE64 0050FE64 00000000 */   nop
    /* 40FE68 0050FE68 2D200002 */  daddu      $4, $16, $0
    /* 40FE6C 0050FE6C 8630140C */  jal        func_0050c218
    /* 40FE70 0050FE70 C001058E */   lw        $5, 0x1C0($16)
    /* 40FE74 0050FE74 6431140C */  jal        func_0050c590
    /* 40FE78 0050FE78 2D200002 */   daddu     $4, $16, $0
    /* 40FE7C 0050FE7C A4A4130C */  jal        func_004e9290
    /* 40FE80 0050FE80 4800048E */   lw        $4, 0x48($16)
    /* 40FE84 0050FE84 BC01028E */  lw         $2, 0x1BC($16)
    /* 40FE88 0050FE88 05004010 */  beqz       $2, .L0050FEA0
    /* 40FE8C 0050FE8C 2D204000 */   daddu     $4, $2, $0
    /* 40FE90 0050FE90 0000428C */  lw         $2, 0x0($2)
    /* 40FE94 0050FE94 1400438C */  lw         $3, 0x14($2)
    /* 40FE98 0050FE98 09F86000 */  jalr       $3
    /* 40FE9C 0050FE9C 00000000 */   nop
  .L0050FEA0:
    /* 40FEA0 0050FEA0 F020140C */  jal        func_005083c0
    /* 40FEA4 0050FEA4 2D200002 */   daddu     $4, $16, $0
    /* 40FEA8 0050FEA8 A80200AE */  sw         $0, 0x2A8($16)
    /* 40FEAC 0050FEAC 0800BFDF */  ld         $31, 0x8($29)
    /* 40FEB0 0050FEB0 0000B0DF */  ld         $16, 0x0($29)
    /* 40FEB4 0050FEB4 0800E003 */  jr         $31
    /* 40FEB8 0050FEB8 1000BD27 */   addiu     $29, $29, 0x10
    /* 40FEBC 0050FEBC 00000000 */  nop
.size func_0050fe20, 0xa0
