.section .text
.set noat
.set noreorder
glabel func_0026ed00
    /* 16ED00 0026ED00 D0FFBD27 */  addiu      $29, $29, -0x30
    /* 16ED04 0026ED04 2000BFFF */  sd         $31, 0x20($29)
    /* 16ED08 0026ED08 1000B17F */  sq         $17, 0x10($29)
    /* 16ED0C 0026ED0C 0000B07F */  sq         $16, 0x0($29)
    /* 16ED10 0026ED10 2D888000 */  daddu      $17, $4, $0
    /* 16ED14 0026ED14 2D80A000 */  daddu      $16, $5, $0
    /* 16ED18 0026ED18 A8D1090C */  jal        func_002746a0
    /* 16ED1C 0026ED1C 00000000 */   nop
    /* 16ED20 0026ED20 04004010 */  beqz       $2, .L0026ED34
    /* 16ED24 0026ED24 00000000 */   nop
    /* 16ED28 0026ED28 2D100000 */  daddu      $2, $0, $0
    /* 16ED2C 0026ED2C 2B000010 */  b          .L0026EDDC
    /* 16ED30 0026ED30 00000000 */   nop
  .L0026ED34:
    /* 16ED34 0026ED34 1400038E */  lw         $3, 0x14($16)
    /* 16ED38 0026ED38 3400628C */  lw         $2, 0x34($3)
    /* 16ED3C 0026ED3C 03004010 */  beqz       $2, .L0026ED4C
    /* 16ED40 0026ED40 00000000 */   nop
    /* 16ED44 0026ED44 01000224 */  addiu      $2, $0, 0x1
    /* 16ED48 0026ED48 380062AC */  sw         $2, 0x38($3)
  .L0026ED4C:
    /* 16ED4C 0026ED4C 1400028E */  lw         $2, 0x14($16)
    /* 16ED50 0026ED50 300051AC */  sw         $17, 0x30($2)
    /* 16ED54 0026ED54 3A000424 */  addiu      $4, $0, 0x3A
    /* 16ED58 0026ED58 CC18040C */  jal        func_00106330
    /* 16ED5C 0026ED5C 00000000 */   nop
    /* 16ED60 0026ED60 06004014 */  bnez       $2, .L0026ED7C
    /* 16ED64 0026ED64 00000000 */   nop
    /* 16ED68 0026ED68 23000324 */  addiu      $3, $0, 0x23
    /* 16ED6C 0026ED6C 1400028E */  lw         $2, 0x14($16)
    /* 16ED70 0026ED70 3C0043AC */  sw         $3, 0x3C($2)
    /* 16ED74 0026ED74 18000010 */  b          .L0026EDD8
    /* 16ED78 0026ED78 00000000 */   nop
  .L0026ED7C:
    /* 16ED7C 0026ED7C 1800038E */  lw         $3, 0x18($16)
    /* 16ED80 0026ED80 1000028E */  lw         $2, 0x10($16)
    /* 16ED84 0026ED84 21184300 */  addu       $3, $2, $3
    /* 16ED88 0026ED88 00006290 */  lbu        $2, 0x0($3)
    /* 16ED8C 0026ED8C FFFF4224 */  addiu      $2, $2, -0x1
    /* 16ED90 0026ED90 FF004430 */  andi       $4, $2, 0xFF
    /* 16ED94 0026ED94 01006390 */  lbu        $3, 0x1($3)
    /* 16ED98 0026ED98 FF000224 */  addiu      $2, $0, 0xFF
    /* 16ED9C 0026ED9C 04006214 */  bne        $3, $2, .L0026EDB0
    /* 16EDA0 0026EDA0 00000000 */   nop
    /* 16EDA4 0026EDA4 2D100000 */  daddu      $2, $0, $0
    /* 16EDA8 0026EDA8 03000010 */  b          .L0026EDB8
    /* 16EDAC 0026EDAC 00000000 */   nop
  .L0026EDB0:
    /* 16EDB0 0026EDB0 FFFF6224 */  addiu      $2, $3, -0x1
    /* 16EDB4 0026EDB4 FF004230 */  andi       $2, $2, 0xFF
  .L0026EDB8:
    /* 16EDB8 0026EDB8 FF004230 */  andi       $2, $2, 0xFF
    /* 16EDBC 0026EDBC 001A0200 */  sll        $3, $2, 8
    /* 16EDC0 0026EDC0 FF008230 */  andi       $2, $4, 0xFF
    /* 16EDC4 0026EDC4 25106200 */  or         $2, $3, $2
    /* 16EDC8 0026EDC8 3C1C0200 */  dsll32     $3, $2, 16
    /* 16EDCC 0026EDCC 3F1C0300 */  dsra32     $3, $3, 16
    /* 16EDD0 0026EDD0 1400028E */  lw         $2, 0x14($16)
    /* 16EDD4 0026EDD4 3C0043AC */  sw         $3, 0x3C($2)
  .L0026EDD8:
    /* 16EDD8 0026EDD8 2D100000 */  daddu      $2, $0, $0
  .L0026EDDC:
    /* 16EDDC 0026EDDC 2000BFDF */  ld         $31, 0x20($29)
    /* 16EDE0 0026EDE0 1000B17B */  lq         $17, 0x10($29)
    /* 16EDE4 0026EDE4 0000B07B */  lq         $16, 0x0($29)
    /* 16EDE8 0026EDE8 3000BD27 */  addiu      $29, $29, 0x30
    /* 16EDEC 0026EDEC 0800E003 */  jr         $31
    /* 16EDF0 0026EDF0 00000000 */   nop
    /* 16EDF4 0026EDF4 00000000 */  nop
    /* 16EDF8 0026EDF8 00000000 */  nop
    /* 16EDFC 0026EDFC 00000000 */  nop
.size func_0026ed00, 0x100
