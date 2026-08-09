.section .text
.set noat
.set noreorder
glabel func_0050ac08
    /* 40AC08 0050AC08 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 40AC0C 0050AC0C 0800B1FF */  sd         $17, 0x8($29)
    /* 40AC10 0050AC10 2D88C000 */  daddu      $17, $6, $0
    /* 40AC14 0050AC14 1000B2FF */  sd         $18, 0x10($29)
    /* 40AC18 0050AC18 2D90A000 */  daddu      $18, $5, $0
    /* 40AC1C 0050AC1C 0000B0FF */  sd         $16, 0x0($29)
    /* 40AC20 0050AC20 2D808000 */  daddu      $16, $4, $0
    /* 40AC24 0050AC24 1800BFFF */  sd         $31, 0x18($29)
    /* 40AC28 0050AC28 000040AE */  sw         $0, 0x0($18)
    /* 40AC2C 0050AC2C 0A35140C */  jal        func_0050d428
    /* 40AC30 0050AC30 000020AE */   sw        $0, 0x0($17)
    /* 40AC34 0050AC34 01000324 */  addiu      $3, $0, 0x1
    /* 40AC38 0050AC38 09004310 */  beq        $2, $3, .L0050AC60
    /* 40AC3C 0050AC3C 2D200002 */   daddu     $4, $16, $0
    /* 40AC40 0050AC40 7600043C */  lui        $4, %hi(D_0075E7E0)
    /* 40AC44 0050AC44 0000B0DF */  ld         $16, 0x0($29)
    /* 40AC48 0050AC48 0800B1DF */  ld         $17, 0x8($29)
    /* 40AC4C 0050AC4C E0E78424 */  addiu      $4, $4, %lo(D_0075E7E0)
    /* 40AC50 0050AC50 1000B2DF */  ld         $18, 0x10($29)
    /* 40AC54 0050AC54 1800BFDF */  ld         $31, 0x18($29)
    /* 40AC58 0050AC58 88441408 */  j          func_00511220
    /* 40AC5C 0050AC5C 2000BD27 */   addiu     $29, $29, 0x20
  .L0050AC60:
    /* 40AC60 0050AC60 9833140C */  jal        func_0050ce60
    /* 40AC64 0050AC64 00000000 */   nop
    /* 40AC68 0050AC68 2D284002 */  daddu      $5, $18, $0
    /* 40AC6C 0050AC6C 2D302002 */  daddu      $6, $17, $0
    /* 40AC70 0050AC70 0C004010 */  beqz       $2, .L0050ACA4
    /* 40AC74 0050AC74 2D204000 */   daddu     $4, $2, $0
    /* 40AC78 0050AC78 227E140C */  jal        func_0051f888
    /* 40AC7C 0050AC7C 00000000 */   nop
    /* 40AC80 0050AC80 0000228E */  lw         $2, 0x0($17)
    /* 40AC84 0050AC84 FCFF4324 */  addiu      $3, $2, -0x4
    /* 40AC88 0050AC88 04004228 */  slti       $2, $2, 0x4
    /* 40AC8C 0050AC8C 06004014 */  bnez       $2, .L0050ACA8
    /* 40AC90 0050AC90 0000B0DF */   ld        $16, 0x0($29)
    /* 40AC94 0050AC94 0000428E */  lw         $2, 0x0($18)
    /* 40AC98 0050AC98 000023AE */  sw         $3, 0x0($17)
    /* 40AC9C 0050AC9C 04004224 */  addiu      $2, $2, 0x4
    /* 40ACA0 0050ACA0 000042AE */  sw         $2, 0x0($18)
  .L0050ACA4:
    /* 40ACA4 0050ACA4 0000B0DF */  ld         $16, 0x0($29)
  .L0050ACA8:
    /* 40ACA8 0050ACA8 0800B1DF */  ld         $17, 0x8($29)
    /* 40ACAC 0050ACAC 1000B2DF */  ld         $18, 0x10($29)
    /* 40ACB0 0050ACB0 1800BFDF */  ld         $31, 0x18($29)
    /* 40ACB4 0050ACB4 0800E003 */  jr         $31
    /* 40ACB8 0050ACB8 2000BD27 */   addiu     $29, $29, 0x20
    /* 40ACBC 0050ACBC 00000000 */  nop
.size func_0050ac08, 0xb8
