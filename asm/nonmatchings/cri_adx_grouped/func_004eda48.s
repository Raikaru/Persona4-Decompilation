.section .text
.set noat
.set noreorder
glabel func_004eda48
    /* 3EDA48 004EDA48 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3EDA4C 004EDA4C 2D408000 */  daddu      $8, $4, $0
    /* 3EDA50 004EDA50 09000015 */  bnez       $8, .L004EDA78
    /* 3EDA54 004EDA54 0000BFFF */   sd        $31, 0x0($29)
    /* 3EDA58 004EDA58 7600043C */  lui        $4, %hi(D_0075CCF0)
    /* 3EDA5C 004EDA5C 7600053C */  lui        $5, %hi(D_0075CC40)
    /* 3EDA60 004EDA60 0000BFDF */  ld         $31, 0x0($29)
    /* 3EDA64 004EDA64 F0CC8424 */  addiu      $4, $4, %lo(D_0075CCF0)
    /* 3EDA68 004EDA68 40CCA524 */  addiu      $5, $5, %lo(D_0075CC40)
    /* 3EDA6C 004EDA6C 2EB51308 */  j          func_004ed4b8
    /* 3EDA70 004EDA70 1000BD27 */   addiu     $29, $29, 0x10
    /* 3EDA74 004EDA74 00000000 */  nop
  .L004EDA78:
    /* 3EDA78 004EDA78 0400028D */  lw         $2, 0x4($8)
    /* 3EDA7C 004EDA7C 08004014 */  bnez       $2, .L004EDAA0
    /* 3EDA80 004EDA80 7600043C */   lui       $4, %hi(D_0075CD00)
    /* 3EDA84 004EDA84 7600053C */  lui        $5, %hi(D_0075CC70)
    /* 3EDA88 004EDA88 0000BFDF */  ld         $31, 0x0($29)
    /* 3EDA8C 004EDA8C 00CD8424 */  addiu      $4, $4, %lo(D_0075CD00)
    /* 3EDA90 004EDA90 70CCA524 */  addiu      $5, $5, %lo(D_0075CC70)
    /* 3EDA94 004EDA94 2EB51308 */  j          func_004ed4b8
    /* 3EDA98 004EDA98 1000BD27 */   addiu     $29, $29, 0x10
    /* 3EDA9C 004EDA9C 00000000 */  nop
  .L004EDAA0:
    /* 3EDAA0 004EDAA0 0500A014 */  bnez       $5, .L004EDAB8
    /* 3EDAA4 004EDAA4 01000224 */   addiu     $2, $0, 0x1
    /* 3EDAA8 004EDAA8 0000E0AC */  sw         $0, 0x0($7)
    /* 3EDAAC 004EDAAC 1A000010 */  b          .L004EDB18
    /* 3EDAB0 004EDAB0 0400E0AC */   sw        $0, 0x4($7)
    /* 3EDAB4 004EDAB4 00000000 */  nop
  .L004EDAB8:
    /* 3EDAB8 004EDAB8 1100A254 */  bnel       $5, $2, .L004EDB00
    /* 3EDABC 004EDABC 1C00028D */   lw        $2, 0x1C($8)
    /* 3EDAC0 004EDAC0 0C00028D */  lw         $2, 0xC($8)
    /* 3EDAC4 004EDAC4 1400058D */  lw         $5, 0x14($8)
    /* 3EDAC8 004EDAC8 2A184600 */  slt        $3, $2, $6
    /* 3EDACC 004EDACC 0A10C300 */  movz       $2, $6, $3
    /* 3EDAD0 004EDAD0 0400E2AC */  sw         $2, 0x4($7)
    /* 3EDAD4 004EDAD4 1000048D */  lw         $4, 0x10($8)
    /* 3EDAD8 004EDAD8 0C00038D */  lw         $3, 0xC($8)
    /* 3EDADC 004EDADC 21108200 */  addu       $2, $4, $2
    /* 3EDAE0 004EDAE0 2128A400 */  addu       $5, $5, $4
    /* 3EDAE4 004EDAE4 100002AD */  sw         $2, 0x10($8)
    /* 3EDAE8 004EDAE8 0000E5AC */  sw         $5, 0x0($7)
    /* 3EDAEC 004EDAEC 0400E28C */  lw         $2, 0x4($7)
    /* 3EDAF0 004EDAF0 23186200 */  subu       $3, $3, $2
    /* 3EDAF4 004EDAF4 08000010 */  b          .L004EDB18
    /* 3EDAF8 004EDAF8 0C0003AD */   sw        $3, 0xC($8)
    /* 3EDAFC 004EDAFC 00000000 */  nop
  .L004EDB00:
    /* 3EDB00 004EDB00 0000E0AC */  sw         $0, 0x0($7)
    /* 3EDB04 004EDB04 04004010 */  beqz       $2, .L004EDB18
    /* 3EDB08 004EDB08 0400E0AC */   sw        $0, 0x4($7)
    /* 3EDB0C 004EDB0C 2000048D */  lw         $4, 0x20($8)
    /* 3EDB10 004EDB10 09F84000 */  jalr       $2
    /* 3EDB14 004EDB14 FDFF0524 */   addiu     $5, $0, -0x3
  .L004EDB18:
    /* 3EDB18 004EDB18 0000BFDF */  ld         $31, 0x0($29)
    /* 3EDB1C 004EDB1C 0800E003 */  jr         $31
    /* 3EDB20 004EDB20 1000BD27 */   addiu     $29, $29, 0x10
    /* 3EDB24 004EDB24 00000000 */  nop
.size func_004eda48, 0xe0
