.section .text
.set noat
.set noreorder
glabel func_0038ed30
    /* 28ED30 0038ED30 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 28ED34 0038ED34 1000BFFF */  sd         $31, 0x10($29)
    /* 28ED38 0038ED38 0000B07F */  sq         $16, 0x0($29)
    /* 28ED3C 0038ED3C B0B5828F */  lw         $2, -0x4A50($28)
    /* 28ED40 0038ED40 06004014 */  bnez       $2, .L0038ED5C
    /* 28ED44 0038ED44 00000000 */   nop
    /* 28ED48 0038ED48 6500043C */  lui        $4, %hi(D_0064F220)
    /* 28ED4C 0038ED4C 20F28424 */  addiu      $4, $4, %lo(D_0064F220)
    /* 28ED50 0038ED50 6B000524 */  addiu      $5, $0, 0x6B
    /* 28ED54 0038ED54 CCB5110C */  jal        func_0046d730
    /* 28ED58 0038ED58 00000000 */   nop
  .L0038ED5C:
    /* 28ED5C 0038ED5C B0B5908F */  lw         $16, -0x4A50($28)
    /* 28ED60 0038ED60 543E0E0C */  jal        func_0038f950
    /* 28ED64 0038ED64 00000000 */   nop
    /* 28ED68 0038ED68 2D204000 */  daddu      $4, $2, $0
    /* 28ED6C 0038ED6C 783D0E0C */  jal        func_0038f5e0
    /* 28ED70 0038ED70 00000000 */   nop
    /* 28ED74 0038ED74 0C12058E */  lw         $5, 0x120C($16)
    /* 28ED78 0038ED78 21184500 */  addu       $3, $2, $5
    /* 28ED7C 0038ED7C 00006490 */  lbu        $4, 0x0($3)
    /* 28ED80 0038ED80 04000324 */  addiu      $3, $0, 0x4
    /* 28ED84 0038ED84 1A008310 */  beq        $4, $3, .L0038EDF0
    /* 28ED88 0038ED88 00000000 */   nop
    /* 28ED8C 0038ED8C 03000324 */  addiu      $3, $0, 0x3
    /* 28ED90 0038ED90 13008310 */  beq        $4, $3, .L0038EDE0
    /* 28ED94 0038ED94 00000000 */   nop
    /* 28ED98 0038ED98 02000324 */  addiu      $3, $0, 0x2
    /* 28ED9C 0038ED9C 0C008310 */  beq        $4, $3, .L0038EDD0
    /* 28EDA0 0038EDA0 00000000 */   nop
    /* 28EDA4 0038EDA4 01000324 */  addiu      $3, $0, 0x1
    /* 28EDA8 0038EDA8 05008310 */  beq        $4, $3, .L0038EDC0
    /* 28EDAC 0038EDAC 00000000 */   nop
    /* 28EDB0 0038EDB0 11008010 */  beqz       $4, .L0038EDF8
    /* 28EDB4 0038EDB4 00000000 */   nop
    /* 28EDB8 0038EDB8 0F000010 */  b          .L0038EDF8
    /* 28EDBC 0038EDBC 00000000 */   nop
  .L0038EDC0:
    /* 28EDC0 0038EDC0 0100A324 */  addiu      $3, $5, 0x1
    /* 28EDC4 0038EDC4 0C1203AE */  sw         $3, 0x120C($16)
    /* 28EDC8 0038EDC8 0B000010 */  b          .L0038EDF8
    /* 28EDCC 0038EDCC 00000000 */   nop
  .L0038EDD0:
    /* 28EDD0 0038EDD0 0100A324 */  addiu      $3, $5, 0x1
    /* 28EDD4 0038EDD4 0C1203AE */  sw         $3, 0x120C($16)
    /* 28EDD8 0038EDD8 07000010 */  b          .L0038EDF8
    /* 28EDDC 0038EDDC 00000000 */   nop
  .L0038EDE0:
    /* 28EDE0 0038EDE0 0200A324 */  addiu      $3, $5, 0x2
    /* 28EDE4 0038EDE4 0C1203AE */  sw         $3, 0x120C($16)
    /* 28EDE8 0038EDE8 03000010 */  b          .L0038EDF8
    /* 28EDEC 0038EDEC 00000000 */   nop
  .L0038EDF0:
    /* 28EDF0 0038EDF0 0100A324 */  addiu      $3, $5, 0x1
    /* 28EDF4 0038EDF4 0C1203AE */  sw         $3, 0x120C($16)
  .L0038EDF8:
    /* 28EDF8 0038EDF8 1000BFDF */  ld         $31, 0x10($29)
    /* 28EDFC 0038EDFC 0000B07B */  lq         $16, 0x0($29)
    /* 28EE00 0038EE00 2000BD27 */  addiu      $29, $29, 0x20
    /* 28EE04 0038EE04 0800E003 */  jr         $31
    /* 28EE08 0038EE08 00000000 */   nop
    /* 28EE0C 0038EE0C 00000000 */  nop
.size func_0038ed30, 0xe0
