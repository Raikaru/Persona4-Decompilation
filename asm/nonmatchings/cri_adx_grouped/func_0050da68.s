.section .text
.set noat
.set noreorder
glabel func_0050da68
    /* 40DA68 0050DA68 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 40DA6C 0050DA6C 0800B1FF */  sd         $17, 0x8($29)
    /* 40DA70 0050DA70 0000B0FF */  sd         $16, 0x0($29)
    /* 40DA74 0050DA74 1000BFFF */  sd         $31, 0x10($29)
    /* 40DA78 0050DA78 0A35140C */  jal        func_0050d428
    /* 40DA7C 0050DA7C 2D888000 */   daddu     $17, $4, $0
    /* 40DA80 0050DA80 7600043C */  lui        $4, %hi(D_0075F488)
    /* 40DA84 0050DA84 01000324 */  addiu      $3, $0, 0x1
    /* 40DA88 0050DA88 05004310 */  beq        $2, $3, .L0050DAA0
    /* 40DA8C 0050DA8C 88F48424 */   addiu     $4, $4, %lo(D_0075F488)
    /* 40DA90 0050DA90 8844140C */  jal        func_00511220
    /* 40DA94 0050DA94 00000000 */   nop
    /* 40DA98 0050DA98 0E000010 */  b          .L0050DAD4
    /* 40DA9C 0050DA9C 2D100000 */   daddu     $2, $0, $0
  .L0050DAA0:
    /* 40DAA0 0050DAA0 3C00238E */  lw         $3, 0x3C($17)
    /* 40DAA4 0050DAA4 0B006010 */  beqz       $3, .L0050DAD4
    /* 40DAA8 0050DAA8 2D100000 */   daddu     $2, $0, $0
    /* 40DAAC 0050DAAC 3232140C */  jal        func_0050c8c8
    /* 40DAB0 0050DAB0 2D202002 */   daddu     $4, $17, $0
    /* 40DAB4 0050DAB4 80022426 */  addiu      $4, $17, 0x280
    /* 40DAB8 0050DAB8 D642140C */  jal        func_00510b58
    /* 40DABC 0050DABC 2D804000 */   daddu     $16, $2, $0
    /* 40DAC0 0050DAC0 2D184000 */  daddu      $3, $2, $0
    /* 40DAC4 0050DAC4 2D100002 */  daddu      $2, $16, $0
    /* 40DAC8 0050DAC8 26200302 */  xor        $4, $16, $3
    /* 40DACC 0050DACC 0A106200 */  movz       $2, $3, $2
    /* 40DAD0 0050DAD0 0A100402 */  movz       $2, $16, $4
  .L0050DAD4:
    /* 40DAD4 0050DAD4 0000B0DF */  ld         $16, 0x0($29)
    /* 40DAD8 0050DAD8 0800B1DF */  ld         $17, 0x8($29)
    /* 40DADC 0050DADC 1000BFDF */  ld         $31, 0x10($29)
    /* 40DAE0 0050DAE0 0800E003 */  jr         $31
    /* 40DAE4 0050DAE4 2000BD27 */   addiu     $29, $29, 0x20
.size func_0050da68, 0x80
