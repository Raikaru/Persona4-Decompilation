.section .text
.set noat
.set noreorder
glabel func_0050ace8
    /* 40ACE8 0050ACE8 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 40ACEC 0050ACEC 0000B0FF */  sd         $16, 0x0($29)
    /* 40ACF0 0050ACF0 0800BFFF */  sd         $31, 0x8($29)
    /* 40ACF4 0050ACF4 0A35140C */  jal        func_0050d428
    /* 40ACF8 0050ACF8 2D808000 */   daddu     $16, $4, $0
    /* 40ACFC 0050ACFC 7600043C */  lui        $4, %hi(D_0075E818)
    /* 40AD00 0050AD00 01000324 */  addiu      $3, $0, 0x1
    /* 40AD04 0050AD04 06004310 */  beq        $2, $3, .L0050AD20
    /* 40AD08 0050AD08 18E88424 */   addiu     $4, $4, %lo(D_0075E818)
    /* 40AD0C 0050AD0C 8844140C */  jal        func_00511220
    /* 40AD10 0050AD10 00000000 */   nop
    /* 40AD14 0050AD14 03000010 */  b          .L0050AD24
    /* 40AD18 0050AD18 2D100000 */   daddu     $2, $0, $0
    /* 40AD1C 0050AD1C 00000000 */  nop
  .L0050AD20:
    /* 40AD20 0050AD20 8400028E */  lw         $2, 0x84($16)
  .L0050AD24:
    /* 40AD24 0050AD24 0000B0DF */  ld         $16, 0x0($29)
    /* 40AD28 0050AD28 0800BFDF */  ld         $31, 0x8($29)
    /* 40AD2C 0050AD2C 0800E003 */  jr         $31
    /* 40AD30 0050AD30 1000BD27 */   addiu     $29, $29, 0x10
    /* 40AD34 0050AD34 00000000 */  nop
.size func_0050ace8, 0x50
