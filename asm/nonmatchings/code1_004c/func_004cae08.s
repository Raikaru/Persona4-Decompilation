.section .text
.set noat
.set noreorder
glabel func_004cae08
    /* 3CAE08 004CAE08 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 3CAE0C 004CAE0C 0000B0FF */  sd         $16, 0x0($29)
    /* 3CAE10 004CAE10 2D808000 */  daddu      $16, $4, $0
    /* 3CAE14 004CAE14 0800B1FF */  sd         $17, 0x8($29)
    /* 3CAE18 004CAE18 1000BFFF */  sd         $31, 0x10($29)
    /* 3CAE1C 004CAE1C 08000016 */  bnez       $16, .L004CAE40
    /* 3CAE20 004CAE20 9400118E */   lw        $17, 0x94($16)
    /* 3CAE24 004CAE24 7600043C */  lui        $4, %hi(D_007587B8)
    /* 3CAE28 004CAE28 0000B0DF */  ld         $16, 0x0($29)
    /* 3CAE2C 004CAE2C 0800B1DF */  ld         $17, 0x8($29)
    /* 3CAE30 004CAE30 B8878424 */  addiu      $4, $4, %lo(D_007587B8)
    /* 3CAE34 004CAE34 1000BFDF */  ld         $31, 0x10($29)
    /* 3CAE38 004CAE38 A61A1308 */  j          func_004c6a98
    /* 3CAE3C 004CAE3C 2000BD27 */   addiu     $29, $29, 0x20
  .L004CAE40:
    /* 3CAE40 004CAE40 8E50130C */  jal        func_004d4238
    /* 3CAE44 004CAE44 00000000 */   nop
    /* 3CAE48 004CAE48 2A15130C */  jal        func_004c54a8
    /* 3CAE4C 004CAE4C 00000000 */   nop
    /* 3CAE50 004CAE50 1000058E */  lw         $5, 0x10($16)
    /* 3CAE54 004CAE54 EA4F130C */  jal        func_004d3fa8
    /* 3CAE58 004CAE58 2D200002 */   daddu     $4, $16, $0
    /* 3CAE5C 004CAE5C 1400048E */  lw         $4, 0x14($16)
    /* 3CAE60 004CAE60 0000838C */  lw         $3, 0x0($4)
    /* 3CAE64 004CAE64 1400628C */  lw         $2, 0x14($3)
    /* 3CAE68 004CAE68 09F84000 */  jalr       $2
    /* 3CAE6C 004CAE6C 00000000 */   nop
    /* 3CAE70 004CAE70 04000324 */  addiu      $3, $0, 0x4
    /* 3CAE74 004CAE74 3E000586 */  lh         $5, 0x3E($16)
    /* 3CAE78 004CAE78 2D202002 */  daddu      $4, $17, $0
    /* 3CAE7C 004CAE7C 020003A2 */  sb         $3, 0x2($16)
    /* 3CAE80 004CAE80 B6A5130C */  jal        func_004e96d8
    /* 3CAE84 004CAE84 C02A0500 */   sll       $5, $5, 11
    /* 3CAE88 004CAE88 3015130C */  jal        func_004c54c0
    /* 3CAE8C 004CAE8C 00000000 */   nop
    /* 3CAE90 004CAE90 A4A4130C */  jal        func_004e9290
    /* 3CAE94 004CAE94 2D202002 */   daddu     $4, $17, $0
    /* 3CAE98 004CAE98 2D200002 */  daddu      $4, $16, $0
    /* 3CAE9C 004CAE9C 0800B1DF */  ld         $17, 0x8($29)
    /* 3CAEA0 004CAEA0 01000524 */  addiu      $5, $0, 0x1
    /* 3CAEA4 004CAEA4 0000B0DF */  ld         $16, 0x0($29)
    /* 3CAEA8 004CAEA8 1000BFDF */  ld         $31, 0x10($29)
    /* 3CAEAC 004CAEAC 6E591308 */  j          func_004d65b8
    /* 3CAEB0 004CAEB0 2000BD27 */   addiu     $29, $29, 0x20
    /* 3CAEB4 004CAEB4 00000000 */  nop
.size func_004cae08, 0xb0
