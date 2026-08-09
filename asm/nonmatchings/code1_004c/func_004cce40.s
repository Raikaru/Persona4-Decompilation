.section .text
.set noat
.set noreorder
glabel func_004cce40
    /* 3CCE40 004CCE40 B0FFBD27 */  addiu      $29, $29, -0x50
    /* 3CCE44 004CCE44 7200023C */  lui        $2, %hi(D_00719990)
    /* 3CCE48 004CCE48 4000B2FF */  sd         $18, 0x40($29)
    /* 3CCE4C 004CCE4C 7200123C */  lui        $18, %hi(D_00719994)
    /* 3CCE50 004CCE50 3800B1FF */  sd         $17, 0x38($29)
    /* 3CCE54 004CCE54 2D888000 */  daddu      $17, $4, $0
    /* 3CCE58 004CCE58 3000B0FF */  sd         $16, 0x30($29)
    /* 3CCE5C 004CCE5C 90994224 */  addiu      $2, $2, %lo(D_00719990)
    /* 3CCE60 004CCE60 4800BFFF */  sd         $31, 0x48($29)
    /* 3CCE64 004CCE64 9499438E */  lw         $3, %lo(D_00719994)($18)
    /* 3CCE68 004CCE68 0000458C */  lw         $5, 0x0($2)
    /* 3CCE6C 004CCE6C 66006054 */  bnel       $3, $0, .L004CD008
    /* 3CCE70 004CCE70 94994326 */   addiu     $3, $18, %lo(D_00719994)
    /* 3CCE74 004CCE74 78C4130C */  jal        func_004f11e0
    /* 3CCE78 004CCE78 00000000 */   nop
    /* 3CCE7C 004CCE7C 4D00043C */  lui        $4, %hi(func_004cb548)
    /* 3CCE80 004CCE80 48B58424 */  addiu      $4, $4, %lo(func_004cb548)
    /* 3CCE84 004CCE84 B0C3130C */  jal        func_004f0ec0
    /* 3CCE88 004CCE88 2D280000 */   daddu     $5, $0, $0
    /* 3CCE8C 004CCE8C 4D00043C */  lui        $4, %hi(func_004cb5d0)
    /* 3CCE90 004CCE90 D0B58424 */  addiu      $4, $4, %lo(func_004cb5d0)
    /* 3CCE94 004CCE94 B6C3130C */  jal        func_004f0ed8
    /* 3CCE98 004CCE98 2D280000 */   daddu     $5, $0, $0
    /* 3CCE9C 004CCE9C 18002056 */  bnel       $17, $0, .L004CCF00
    /* 3CCEA0 004CCEA0 1400238E */   lw        $3, 0x14($17)
    /* 3CCEA4 004CCEA4 7200103C */  lui        $16, %hi(D_007199A0)
    /* 3CCEA8 004CCEA8 18000A24 */  addiu      $10, $0, 0x18
    /* 3CCEAC 004CCEAC A0990226 */  addiu      $2, $16, %lo(D_007199A0)
    /* 3CCEB0 004CCEB0 01000324 */  addiu      $3, $0, 0x1
    /* 3CCEB4 004CCEB4 08000424 */  addiu      $4, $0, 0x8
    /* 3CCEB8 004CCEB8 0F000524 */  addiu      $5, $0, 0xF
    /* 3CCEBC 004CCEBC 10000624 */  addiu      $6, $0, 0x10
    /* 3CCEC0 004CCEC0 12000724 */  addiu      $7, $0, 0x12
    /* 3CCEC4 004CCEC4 19000824 */  addiu      $8, $0, 0x19
    /* 3CCEC8 004CCEC8 1A000924 */  addiu      $9, $0, 0x1A
    /* 3CCECC 004CCECC 14004AAC */  sw         $10, 0x14($2)
    /* 3CCED0 004CCED0 000043AC */  sw         $3, 0x0($2)
    /* 3CCED4 004CCED4 040044AC */  sw         $4, 0x4($2)
    /* 3CCED8 004CCED8 080045AC */  sw         $5, 0x8($2)
    /* 3CCEDC 004CCEDC 0C0046AC */  sw         $6, 0xC($2)
    /* 3CCEE0 004CCEE0 100047AC */  sw         $7, 0x10($2)
    /* 3CCEE4 004CCEE4 180048AC */  sw         $8, 0x18($2)
    /* 3CCEE8 004CCEE8 1C0049AC */  sw         $9, 0x1C($2)
    /* 3CCEEC 004CCEEC 2C0040AC */  sw         $0, 0x2C($2)
    /* 3CCEF0 004CCEF0 200040AC */  sw         $0, 0x20($2)
    /* 3CCEF4 004CCEF4 240040AC */  sw         $0, 0x24($2)
    /* 3CCEF8 004CCEF8 1A000010 */  b          .L004CCF64
    /* 3CCEFC 004CCEFC 280040AC */   sw        $0, 0x28($2)
  .L004CCF00:
    /* 3CCF00 004CCF00 7200103C */  lui        $16, %hi(D_007199A0)
    /* 3CCF04 004CCF04 A0990426 */  addiu      $4, $16, %lo(D_007199A0)
    /* 3CCF08 004CCF08 2000228E */  lw         $2, 0x20($17)
    /* 3CCF0C 004CCF0C 140083AC */  sw         $3, 0x14($4)
    /* 3CCF10 004CCF10 200082AC */  sw         $2, 0x20($4)
    /* 3CCF14 004CCF14 0000238E */  lw         $3, 0x0($17)
    /* 3CCF18 004CCF18 2800258E */  lw         $5, 0x28($17)
    /* 3CCF1C 004CCF1C 000083AC */  sw         $3, 0x0($4)
    /* 3CCF20 004CCF20 280085AC */  sw         $5, 0x28($4)
    /* 3CCF24 004CCF24 0400228E */  lw         $2, 0x4($17)
    /* 3CCF28 004CCF28 040082AC */  sw         $2, 0x4($4)
    /* 3CCF2C 004CCF2C 0800238E */  lw         $3, 0x8($17)
    /* 3CCF30 004CCF30 080083AC */  sw         $3, 0x8($4)
    /* 3CCF34 004CCF34 0C00228E */  lw         $2, 0xC($17)
    /* 3CCF38 004CCF38 0C0082AC */  sw         $2, 0xC($4)
    /* 3CCF3C 004CCF3C 1000238E */  lw         $3, 0x10($17)
    /* 3CCF40 004CCF40 100083AC */  sw         $3, 0x10($4)
    /* 3CCF44 004CCF44 1800228E */  lw         $2, 0x18($17)
    /* 3CCF48 004CCF48 180082AC */  sw         $2, 0x18($4)
    /* 3CCF4C 004CCF4C 1C00238E */  lw         $3, 0x1C($17)
    /* 3CCF50 004CCF50 1C0083AC */  sw         $3, 0x1C($4)
    /* 3CCF54 004CCF54 2400228E */  lw         $2, 0x24($17)
    /* 3CCF58 004CCF58 240082AC */  sw         $2, 0x24($4)
    /* 3CCF5C 004CCF5C 2C00238E */  lw         $3, 0x2C($17)
    /* 3CCF60 004CCF60 2C0083AC */  sw         $3, 0x2C($4)
  .L004CCF64:
    /* 3CCF64 004CCF64 B485100C */  jal        func_004216d0
    /* 3CCF68 004CCF68 7200113C */   lui       $17, %hi(D_00719A38)
    /* 3CCF6C 004CCF6C 389A3126 */  addiu      $17, $17, %lo(D_00719A38)
    /* 3CCF70 004CCF70 2D28A003 */  daddu      $5, $29, $0
    /* 3CCF74 004CCF74 000022AE */  sw         $2, 0x0($17)
    /* 3CCF78 004CCF78 A0991026 */  addiu      $16, $16, %lo(D_007199A0)
    /* 3CCF7C 004CCF7C B885100C */  jal        func_004216e0
    /* 3CCF80 004CCF80 0000248E */   lw        $4, 0x0($17)
    /* 3CCF84 004CCF84 7200033C */  lui        $3, %hi(D_007212C8)
    /* 3CCF88 004CCF88 1800A28F */  lw         $2, 0x18($29)
    /* 3CCF8C 004CCF8C 822F130C */  jal        func_004cbe08
    /* 3CCF90 004CCF90 C81262AC */   sw        $2, %lo(D_007212C8)($3)
    /* 3CCF94 004CCF94 2000048E */  lw         $4, 0x20($16)
    /* 3CCF98 004CCF98 AC2F130C */  jal        func_004cbeb0
    /* 3CCF9C 004CCF9C 2400058E */   lw        $5, 0x24($16)
    /* 3CCFA0 004CCFA0 DA2F130C */  jal        func_004cbf68
    /* 3CCFA4 004CCFA4 00000000 */   nop
    /* 3CCFA8 004CCFA8 FC2F130C */  jal        func_004cbff0
    /* 3CCFAC 004CCFAC 00000000 */   nop
    /* 3CCFB0 004CCFB0 1E30130C */  jal        func_004cc078
    /* 3CCFB4 004CCFB4 00000000 */   nop
    /* 3CCFB8 004CCFB8 2800048E */  lw         $4, 0x28($16)
    /* 3CCFBC 004CCFBC 4430130C */  jal        func_004cc110
    /* 3CCFC0 004CCFC0 2C00058E */   lw        $5, 0x2C($16)
    /* 3CCFC4 004CCFC4 0000248E */  lw         $4, 0x0($17)
    /* 3CCFC8 004CCFC8 9C85100C */  jal        func_00421670
    /* 3CCFCC 004CCFCC 1400058E */   lw        $5, 0x14($16)
    /* 3CCFD0 004CCFD0 4D00053C */  lui        $5, %hi(func_004cb728)
    /* 3CCFD4 004CCFD4 28B7A524 */  addiu      $5, $5, %lo(func_004cb728)
    /* 3CCFD8 004CCFD8 06000424 */  addiu      $4, $0, 0x6
    /* 3CCFDC 004CCFDC 7AC3130C */  jal        func_004f0de8
    /* 3CCFE0 004CCFE0 2D300000 */   daddu     $6, $0, $0
    /* 3CCFE4 004CCFE4 4D00053C */  lui        $5, %hi(func_004cb750)
    /* 3CCFE8 004CCFE8 50B7A524 */  addiu      $5, $5, %lo(func_004cb750)
    /* 3CCFEC 004CCFEC 07000424 */  addiu      $4, $0, 0x7
    /* 3CCFF0 004CCFF0 7AC3130C */  jal        func_004f0de8
    /* 3CCFF4 004CCFF4 2D300000 */   daddu     $6, $0, $0
    /* 3CCFF8 004CCFF8 7200033C */  lui        $3, %hi(D_00719998)
    /* 3CCFFC 004CCFFC 01000224 */  addiu      $2, $0, 0x1
    /* 3CD000 004CD000 989962AC */  sw         $2, %lo(D_00719998)($3)
    /* 3CD004 004CD004 94994326 */  addiu      $3, $18, %lo(D_00719994)
  .L004CD008:
    /* 3CD008 004CD008 4000B2DF */  ld         $18, 0x40($29)
    /* 3CD00C 004CD00C 0000628C */  lw         $2, 0x0($3)
    /* 3CD010 004CD010 3000B0DF */  ld         $16, 0x30($29)
    /* 3CD014 004CD014 3800B1DF */  ld         $17, 0x38($29)
    /* 3CD018 004CD018 01004224 */  addiu      $2, $2, 0x1
    /* 3CD01C 004CD01C 4800BFDF */  ld         $31, 0x48($29)
    /* 3CD020 004CD020 000062AC */  sw         $2, 0x0($3)
    /* 3CD024 004CD024 0800E003 */  jr         $31
    /* 3CD028 004CD028 5000BD27 */   addiu     $29, $29, 0x50
    /* 3CD02C 004CD02C 00000000 */  nop
.size func_004cce40, 0x1f0
