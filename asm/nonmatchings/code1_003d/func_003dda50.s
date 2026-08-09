.section .text
.set noat
.set noreorder
glabel func_003dda50
    /* 2DDA50 003DDA50 80FFBD27 */  addiu      $29, $29, -0x80
    /* 2DDA54 003DDA54 7000BFFF */  sd         $31, 0x70($29)
    /* 2DDA58 003DDA58 6000B67F */  sq         $22, 0x60($29)
    /* 2DDA5C 003DDA5C 5000B57F */  sq         $21, 0x50($29)
    /* 2DDA60 003DDA60 2DB0A000 */  daddu      $22, $5, $0
    /* 2DDA64 003DDA64 4000B47F */  sq         $20, 0x40($29)
    /* 2DDA68 003DDA68 2DA80001 */  daddu      $21, $8, $0
    /* 2DDA6C 003DDA6C 3000B37F */  sq         $19, 0x30($29)
    /* 2DDA70 003DDA70 2DA08000 */  daddu      $20, $4, $0
    /* 2DDA74 003DDA74 2000B27F */  sq         $18, 0x20($29)
    /* 2DDA78 003DDA78 2D98C000 */  daddu      $19, $6, $0
    /* 2DDA7C 003DDA7C 1000B17F */  sq         $17, 0x10($29)
    /* 2DDA80 003DDA80 2D90E000 */  daddu      $18, $7, $0
    /* 2DDA84 003DDA84 0000B07F */  sq         $16, 0x0($29)
    /* 2DDA88 003DDA88 4E008012 */  beqz       $20, .L003DDBC4
    /* 2DDA8C 003DDA8C 2D880000 */   daddu     $17, $0, $0
    /* 2DDA90 003DDA90 0886100C */  jal        func_00421820
    /* 2DDA94 003DDA94 54B7848F */   lw        $4, -0x48AC($28)
    /* 2DDA98 003DDA98 0400828E */  lw         $2, 0x4($20)
    /* 2DDA9C 003DDA9C 2A080200 */  slt        $1, $0, $2
    /* 2DDAA0 003DDAA0 13002010 */  beqz       $1, .L003DDAF0
    /* 2DDAA4 003DDAA4 2D800000 */   daddu     $16, $0, $0
  .L003DDAA8:
    /* 2DDAA8 003DDAA8 1400828E */  lw         $2, 0x14($20)
    /* 2DDAAC 003DDAAC 2D208002 */  daddu      $4, $20, $0
    /* 2DDAB0 003DDAB0 09F84000 */  jalr       $2
    /* 2DDAB4 003DDAB4 2D280002 */   daddu     $5, $16, $0
    /* 2DDAB8 003DDAB8 3800448C */  lw         $4, 0x38($2)
    /* 2DDABC 003DDABC 01000324 */  addiu      $3, $0, 0x1
    /* 2DDAC0 003DDAC0 05008314 */  bne        $4, $3, .L003DDAD8
    /* 2DDAC4 003DDAC4 00000000 */   nop
    /* 2DDAC8 003DDAC8 05000324 */  addiu      $3, $0, 0x5
    /* 2DDACC 003DDACC 2D884000 */  daddu      $17, $2, $0
    /* 2DDAD0 003DDAD0 07000010 */  b          .L003DDAF0
    /* 2DDAD4 003DDAD4 380043AC */   sw        $3, 0x38($2)
  .L003DDAD8:
    /* 2DDAD8 003DDAD8 0400828E */  lw         $2, 0x4($20)
    /* 2DDADC 003DDADC 01001026 */  addiu      $16, $16, 0x1
    /* 2DDAE0 003DDAE0 2A100202 */  slt        $2, $16, $2
    /* 2DDAE4 003DDAE4 F0FF4014 */  bnez       $2, .L003DDAA8
    /* 2DDAE8 003DDAE8 00000000 */   nop
    /* 2DDAEC 003DDAEC 00000000 */  nop
  .L003DDAF0:
    /* 2DDAF0 003DDAF0 0086100C */  jal        func_00421800
    /* 2DDAF4 003DDAF4 54B7848F */   lw        $4, -0x48AC($28)
    /* 2DDAF8 003DDAF8 19002012 */  beqz       $17, .L003DDB60
    /* 2DDAFC 003DDAFC 00000000 */   nop
    /* 2DDB00 003DDB00 10006232 */  andi       $2, $19, 0x10
    /* 2DDB04 003DDB04 21004014 */  bnez       $2, .L003DDB8C
    /* 2DDB08 003DDB08 00000000 */   nop
    /* 2DDB0C 003DDB0C 3000228E */  lw         $2, 0x30($17)
    /* 2DDB10 003DDB10 1E004014 */  bnez       $2, .L003DDB8C
    /* 2DDB14 003DDB14 00000000 */   nop
  .L003DDB18:
    /* 2DDB18 003DDB18 1000828E */  lw         $2, 0x10($20)
    /* 2DDB1C 003DDB1C 20004014 */  bnez       $2, .L003DDBA0
    /* 2DDB20 003DDB20 00000000 */   nop
  .L003DDB24:
    /* 2DDB24 003DDB24 2800828E */  lw         $2, 0x28($20)
    /* 2DDB28 003DDB28 2D30C002 */  daddu      $6, $22, $0
    /* 2DDB2C 003DDB2C 2D386002 */  daddu      $7, $19, $0
    /* 2DDB30 003DDB30 2D208002 */  daddu      $4, $20, $0
    /* 2DDB34 003DDB34 09F84000 */  jalr       $2
    /* 2DDB38 003DDB38 2D282002 */   daddu     $5, $17, $0
    /* 2DDB3C 003DDB3C 01000324 */  addiu      $3, $0, 0x1
    /* 2DDB40 003DDB40 1D004314 */  bne        $2, $3, .L003DDBB8
    /* 2DDB44 003DDB44 00000000 */   nop
  .L003DDB48:
    /* 2DDB48 003DDB48 03002012 */  beqz       $17, .L003DDB58
    /* 2DDB4C 003DDB4C 00000000 */   nop
    /* 2DDB50 003DDB50 02000224 */  addiu      $2, $0, 0x2
    /* 2DDB54 003DDB54 340022AE */  sw         $2, 0x34($17)
  .L003DDB58:
    /* 2DDB58 003DDB58 21000010 */  b          .L003DDBE0
    /* 2DDB5C 003DDB5C 2D102002 */   daddu     $2, $17, $0
  .L003DDB60:
    /* 2DDB60 003DDB60 04770F0C */  jal        func_003ddc10
    /* 2DDB64 003DDB64 08001024 */   addiu     $16, $0, 0x8
    /* 2DDB68 003DDB68 100050AC */  sw         $16, 0x10($2)
    /* 2DDB6C 003DDB6C 8800023C */  lui        $2, %hi(D_00887194)
    /* 2DDB70 003DDB70 9471428C */  lw         $2, %lo(D_00887194)($2)
    /* 2DDB74 003DDB74 03004010 */  beqz       $2, .L003DDB84
    /* 2DDB78 003DDB78 00000000 */   nop
    /* 2DDB7C 003DDB7C 09F84000 */  jalr       $2
    /* 2DDB80 003DDB80 2D200002 */   daddu     $4, $16, $0
  .L003DDB84:
    /* 2DDB84 003DDB84 16000010 */  b          .L003DDBE0
    /* 2DDB88 003DDB88 2D100000 */   daddu     $2, $0, $0
  .L003DDB8C:
    /* 2DDB8C 003DDB8C 02000224 */  addiu      $2, $0, 0x2
    /* 2DDB90 003DDB90 400022AE */  sw         $2, 0x40($17)
    /* 2DDB94 003DDB94 480032AE */  sw         $18, 0x48($17)
    /* 2DDB98 003DDB98 DFFF0010 */  b          .L003DDB18
    /* 2DDB9C 003DDB9C 4C0035AE */   sw        $21, 0x4C($17)
  .L003DDBA0:
    /* 2DDBA0 003DDBA0 02000224 */  addiu      $2, $0, 0x2
    /* 2DDBA4 003DDBA4 10007336 */  ori        $19, $19, 0x10
    /* 2DDBA8 003DDBA8 400022AE */  sw         $2, 0x40($17)
    /* 2DDBAC 003DDBAC 480032AE */  sw         $18, 0x48($17)
    /* 2DDBB0 003DDBB0 DCFF0010 */  b          .L003DDB24
    /* 2DDBB4 003DDBB4 4C0035AE */   sw        $21, 0x4C($17)
  .L003DDBB8:
    /* 2DDBB8 003DDBB8 380023AE */  sw         $3, 0x38($17)
    /* 2DDBBC 003DDBBC E2FF0010 */  b          .L003DDB48
    /* 2DDBC0 003DDBC0 2D880000 */   daddu     $17, $0, $0
  .L003DDBC4:
    /* 2DDBC4 003DDBC4 8800023C */  lui        $2, %hi(D_00887194)
    /* 2DDBC8 003DDBC8 9471428C */  lw         $2, %lo(D_00887194)($2)
    /* 2DDBCC 003DDBCC 03004010 */  beqz       $2, .L003DDBDC
    /* 2DDBD0 003DDBD0 00000000 */   nop
    /* 2DDBD4 003DDBD4 09F84000 */  jalr       $2
    /* 2DDBD8 003DDBD8 04000424 */   addiu     $4, $0, 0x4
  .L003DDBDC:
    /* 2DDBDC 003DDBDC 2D100000 */  daddu      $2, $0, $0
  .L003DDBE0:
    /* 2DDBE0 003DDBE0 7000BFDF */  ld         $31, 0x70($29)
    /* 2DDBE4 003DDBE4 6000B67B */  lq         $22, 0x60($29)
    /* 2DDBE8 003DDBE8 5000B57B */  lq         $21, 0x50($29)
    /* 2DDBEC 003DDBEC 4000B47B */  lq         $20, 0x40($29)
    /* 2DDBF0 003DDBF0 3000B37B */  lq         $19, 0x30($29)
    /* 2DDBF4 003DDBF4 2000B27B */  lq         $18, 0x20($29)
    /* 2DDBF8 003DDBF8 1000B17B */  lq         $17, 0x10($29)
    /* 2DDBFC 003DDBFC 0000B07B */  lq         $16, 0x0($29)
    /* 2DDC00 003DDC00 0800E003 */  jr         $31
    /* 2DDC04 003DDC04 8000BD27 */   addiu     $29, $29, 0x80
    /* 2DDC08 003DDC08 00000000 */  nop
    /* 2DDC0C 003DDC0C 00000000 */  nop
.size func_003dda50, 0x1c0
