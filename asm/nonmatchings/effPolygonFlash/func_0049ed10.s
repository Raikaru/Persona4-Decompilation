.section .text
.set noat
.set noreorder
glabel func_0049ed10
    /* 39ED10 0049ED10 C0FFBD27 */  addiu      $29, $29, -0x40
    /* 39ED14 0049ED14 3000BFFF */  sd         $31, 0x30($29)
    /* 39ED18 0049ED18 2000B27F */  sq         $18, 0x20($29)
    /* 39ED1C 0049ED1C 1000B17F */  sq         $17, 0x10($29)
    /* 39ED20 0049ED20 0000B07F */  sq         $16, 0x0($29)
    /* 39ED24 0049ED24 2D888000 */  daddu      $17, $4, $0
    /* 39ED28 0049ED28 2D80A000 */  daddu      $16, $5, $0
    /* 39ED2C 0049ED2C 3800838C */  lw         $3, 0x38($4)
    /* 39ED30 0049ED30 80100300 */  sll        $2, $3, 2
    /* 39ED34 0049ED34 21104300 */  addu       $2, $2, $3
    /* 39ED38 0049ED38 C0900200 */  sll        $18, $2, 3
    /* 39ED3C 0049ED3C 7100043C */  lui        $4, %hi(D_00713FF0)
    /* 39ED40 0049ED40 F03F8424 */  addiu      $4, $4, %lo(D_00713FF0)
    /* 39ED44 0049ED44 EC070524 */  addiu      $5, $0, 0x7EC
    /* 39ED48 0049ED48 A43A110C */  jal        func_0044ea90
    /* 39ED4C 0049ED4C 00000000 */   nop
    /* 39ED50 0049ED50 10004426 */  addiu      $4, $18, 0x10
    /* 39ED54 0049ED54 0400053C */  lui        $5, (0x40000 >> 16)
    /* 39ED58 0049ED58 8800023C */  lui        $2, %hi(jtbl_008873E8)
    /* 39ED5C 0049ED5C E873428C */  lw         $2, %lo(jtbl_008873E8)($2)
    /* 39ED60 0049ED60 09F84000 */  jalr       $2
    /* 39ED64 0049ED64 00000000 */   nop
    /* 39ED68 0049ED68 2D904000 */  daddu      $18, $2, $0
    /* 39ED6C 0049ED6C 06004016 */  bnez       $18, .L0049ED88
    /* 39ED70 0049ED70 00000000 */   nop
    /* 39ED74 0049ED74 7100043C */  lui        $4, %hi(D_00713FF0)
    /* 39ED78 0049ED78 F03F8424 */  addiu      $4, $4, %lo(D_00713FF0)
    /* 39ED7C 0049ED7C ED070524 */  addiu      $5, $0, 0x7ED
    /* 39ED80 0049ED80 CCB5110C */  jal        func_0046d730
    /* 39ED84 0049ED84 00000000 */   nop
  .L0049ED88:
    /* 39ED88 0049ED88 10004226 */  addiu      $2, $18, 0x10
    /* 39ED8C 0049ED8C 000042AE */  sw         $2, 0x0($18)
    /* 39ED90 0049ED90 080052AE */  sw         $18, 0x8($18)
    /* 39ED94 0049ED94 38002496 */  lhu        $4, 0x38($17)
    /* 39ED98 0049ED98 02000524 */  addiu      $5, $0, 0x2
    /* 39ED9C 0049ED9C 04000624 */  addiu      $6, $0, 0x4
    /* 39EDA0 0049EDA0 7100073C */  lui        $7, %hi(D_00713408)
    /* 39EDA4 0049EDA4 0834E724 */  addiu      $7, $7, %lo(D_00713408)
    /* 39EDA8 0049EDA8 4C000824 */  addiu      $8, $0, 0x4C
    /* 39EDAC 0049EDAC DC0B120C */  jal        func_00482f70
    /* 39EDB0 0049EDB0 00000000 */   nop
    /* 39EDB4 0049EDB4 040042AE */  sw         $2, 0x4($18)
    /* 39EDB8 0049EDB8 0B000016 */  bnez       $16, .L0049EDE8
    /* 39EDBC 0049EDBC 00000000 */   nop
    /* 39EDC0 0049EDC0 12000424 */  addiu      $4, $0, 0x12
    /* 39EDC4 0049EDC4 C004120C */  jal        func_00481300
    /* 39EDC8 0049EDC8 00000000 */   nop
    /* 39EDCC 0049EDCC 0400438E */  lw         $3, 0x4($18)
    /* 39EDD0 0049EDD0 1400648C */  lw         $4, 0x14($3)
    /* 39EDD4 0049EDD4 2D284000 */  daddu      $5, $2, $0
    /* 39EDD8 0049EDD8 AC100F0C */  jal        func_003c42b0
    /* 39EDDC 0049EDDC 00000000 */   nop
    /* 39EDE0 0049EDE0 05000010 */  b          .L0049EDF8
    /* 39EDE4 0049EDE4 00000000 */   nop
  .L0049EDE8:
    /* 39EDE8 0049EDE8 0400448E */  lw         $4, 0x4($18)
    /* 39EDEC 0049EDEC 2D280002 */  daddu      $5, $16, $0
    /* 39EDF0 0049EDF0 5C0E120C */  jal        func_00483970
    /* 39EDF4 0049EDF4 00000000 */   nop
  .L0049EDF8:
    /* 39EDF8 0049EDF8 2D204002 */  daddu      $4, $18, $0
    /* 39EDFC 0049EDFC 2D282002 */  daddu      $5, $17, $0
    /* 39EE00 0049EE00 F47A120C */  jal        func_0049ebd0
    /* 39EE04 0049EE04 00000000 */   nop
    /* 39EE08 0049EE08 2D104002 */  daddu      $2, $18, $0
    /* 39EE0C 0049EE0C 3000BFDF */  ld         $31, 0x30($29)
    /* 39EE10 0049EE10 2000B27B */  lq         $18, 0x20($29)
    /* 39EE14 0049EE14 1000B17B */  lq         $17, 0x10($29)
    /* 39EE18 0049EE18 0000B07B */  lq         $16, 0x0($29)
    /* 39EE1C 0049EE1C 4000BD27 */  addiu      $29, $29, 0x40
    /* 39EE20 0049EE20 0800E003 */  jr         $31
    /* 39EE24 0049EE24 00000000 */   nop
    /* 39EE28 0049EE28 00000000 */  nop
    /* 39EE2C 0049EE2C 00000000 */  nop
.size func_0049ed10, 0x120
