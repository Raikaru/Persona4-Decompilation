.section .text
.set noat
.set noreorder
glabel func_0050ece8
    /* 40ECE8 0050ECE8 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 40ECEC 0050ECEC 0000B0FF */  sd         $16, 0x0($29)
    /* 40ECF0 0050ECF0 0800BFFF */  sd         $31, 0x8($29)
    /* 40ECF4 0050ECF4 0A35140C */  jal        func_0050d428
    /* 40ECF8 0050ECF8 2D808000 */   daddu     $16, $4, $0
    /* 40ECFC 0050ECFC 01000324 */  addiu      $3, $0, 0x1
    /* 40ED00 0050ED00 07004310 */  beq        $2, $3, .L0050ED20
    /* 40ED04 0050ED04 2D200002 */   daddu     $4, $16, $0
    /* 40ED08 0050ED08 7600043C */  lui        $4, %hi(D_0075F8D0)
    /* 40ED0C 0050ED0C 8844140C */  jal        func_00511220
    /* 40ED10 0050ED10 D0F88424 */   addiu     $4, $4, %lo(D_0075F8D0)
    /* 40ED14 0050ED14 0E000010 */  b          .L0050ED50
    /* 40ED18 0050ED18 2D100000 */   daddu     $2, $0, $0
    /* 40ED1C 0050ED1C 00000000 */  nop
  .L0050ED20:
    /* 40ED20 0050ED20 2E39140C */  jal        func_0050e4b8
    /* 40ED24 0050ED24 00000000 */   nop
    /* 40ED28 0050ED28 92AE140C */  jal        func_0052ba48
    /* 40ED2C 0050ED2C 2D204000 */   daddu     $4, $2, $0
    /* 40ED30 0050ED30 2D184000 */  daddu      $3, $2, $0
    /* 40ED34 0050ED34 51000224 */  addiu      $2, $0, 0x51
    /* 40ED38 0050ED38 03006210 */  beq        $3, $2, .L0050ED48
    /* 40ED3C 0050ED3C 61000424 */   addiu     $4, $0, 0x61
    /* 40ED40 0050ED40 03006414 */  bne        $3, $4, .L0050ED50
    /* 40ED44 0050ED44 2D106000 */   daddu     $2, $3, $0
  .L0050ED48:
    /* 40ED48 0050ED48 41000324 */  addiu      $3, $0, 0x41
    /* 40ED4C 0050ED4C 2D106000 */  daddu      $2, $3, $0
  .L0050ED50:
    /* 40ED50 0050ED50 0000B0DF */  ld         $16, 0x0($29)
    /* 40ED54 0050ED54 0800BFDF */  ld         $31, 0x8($29)
    /* 40ED58 0050ED58 0800E003 */  jr         $31
    /* 40ED5C 0050ED5C 1000BD27 */   addiu     $29, $29, 0x10
.size func_0050ece8, 0x78
