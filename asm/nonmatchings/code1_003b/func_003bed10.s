.section .text
.set noat
.set noreorder
glabel func_003bed10
    /* 2BED10 003BED10 90FFBD27 */  addiu      $29, $29, -0x70
    /* 2BED14 003BED14 0400828C */  lw         $2, 0x4($4)
    /* 2BED18 003BED18 5000BFFF */  sd         $31, 0x50($29)
    /* 2BED1C 003BED1C 4000B47F */  sq         $20, 0x40($29)
    /* 2BED20 003BED20 3000B37F */  sq         $19, 0x30($29)
    /* 2BED24 003BED24 10001424 */  addiu      $20, $0, 0x10
    /* 2BED28 003BED28 2000B27F */  sq         $18, 0x20($29)
    /* 2BED2C 003BED2C 2D980000 */  daddu      $19, $0, $0
    /* 2BED30 003BED30 1000B17F */  sq         $17, 0x10($29)
    /* 2BED34 003BED34 0000B07F */  sq         $16, 0x0($29)
    /* 2BED38 003BED38 2A080200 */  slt        $1, $0, $2
    /* 2BED3C 003BED3C 2D80A000 */  daddu      $16, $5, $0
    /* 2BED40 003BED40 0D002010 */  beqz       $1, .L003BED78
    /* 2BED44 003BED44 2D888000 */   daddu     $17, $4, $0
    /* 2BED48 003BED48 2D900000 */  daddu      $18, $0, $0
  .L003BED4C:
    /* 2BED4C 003BED4C 0000228E */  lw         $2, 0x0($17)
    /* 2BED50 003BED50 21105200 */  addu       $2, $2, $18
    /* 2BED54 003BED54 240B0F0C */  jal        func_003c2c90
    /* 2BED58 003BED58 0000448C */   lw        $4, 0x0($2)
    /* 2BED5C 003BED5C 0C004224 */  addiu      $2, $2, 0xC
    /* 2BED60 003BED60 01007326 */  addiu      $19, $19, 0x1
    /* 2BED64 003BED64 21A08202 */  addu       $20, $20, $2
    /* 2BED68 003BED68 0400228E */  lw         $2, 0x4($17)
    /* 2BED6C 003BED6C 2A106202 */  slt        $2, $19, $2
    /* 2BED70 003BED70 F6FF4014 */  bnez       $2, .L003BED4C
    /* 2BED74 003BED74 04005226 */   addiu     $18, $18, 0x4
  .L003BED78:
    /* 2BED78 003BED78 0300023C */  lui        $2, (0x37002 >> 16)
    /* 2BED7C 003BED7C 2D308002 */  daddu      $6, $20, $0
    /* 2BED80 003BED80 2D200002 */  daddu      $4, $16, $0
    /* 2BED84 003BED84 1A000524 */  addiu      $5, $0, 0x1A
    /* 2BED88 003BED88 37000824 */  addiu      $8, $0, 0x37
    /* 2BED8C 003BED8C FC7B0F0C */  jal        func_003deff0
    /* 2BED90 003BED90 02704734 */   ori       $7, $2, (0x37002 & 0xFFFF)
    /* 2BED94 003BED94 03004014 */  bnez       $2, .L003BEDA4
    /* 2BED98 003BED98 00000000 */   nop
    /* 2BED9C 003BED9C 2D000010 */  b          .L003BEE54
    /* 2BEDA0 003BEDA0 2D100000 */   daddu     $2, $0, $0
  .L003BEDA4:
    /* 2BEDA4 003BEDA4 0300023C */  lui        $2, (0x37002 >> 16)
    /* 2BEDA8 003BEDA8 2D200002 */  daddu      $4, $16, $0
    /* 2BEDAC 003BEDAC 01000524 */  addiu      $5, $0, 0x1
    /* 2BEDB0 003BEDB0 04000624 */  addiu      $6, $0, 0x4
    /* 2BEDB4 003BEDB4 02704734 */  ori        $7, $2, (0x37002 & 0xFFFF)
    /* 2BEDB8 003BEDB8 FC7B0F0C */  jal        func_003deff0
    /* 2BEDBC 003BEDBC 37000824 */   addiu     $8, $0, 0x37
    /* 2BEDC0 003BEDC0 03004014 */  bnez       $2, .L003BEDD0
    /* 2BEDC4 003BEDC4 00000000 */   nop
    /* 2BEDC8 003BEDC8 22000010 */  b          .L003BEE54
    /* 2BEDCC 003BEDCC 2D100000 */   daddu     $2, $0, $0
  .L003BEDD0:
    /* 2BEDD0 003BEDD0 0400228E */  lw         $2, 0x4($17)
    /* 2BEDD4 003BEDD4 2D200002 */  daddu      $4, $16, $0
    /* 2BEDD8 003BEDD8 6C00A527 */  addiu      $5, $29, 0x6C
    /* 2BEDDC 003BEDDC 04000624 */  addiu      $6, $0, 0x4
    /* 2BEDE0 003BEDE0 AC8A0F0C */  jal        func_003e2ab0
    /* 2BEDE4 003BEDE4 6C00A2AF */   sw        $2, 0x6C($29)
    /* 2BEDE8 003BEDE8 07004010 */  beqz       $2, .L003BEE08
    /* 2BEDEC 003BEDEC 00000000 */   nop
    /* 2BEDF0 003BEDF0 0400228E */  lw         $2, 0x4($17)
    /* 2BEDF4 003BEDF4 2A100200 */  slt        $2, $0, $2
    /* 2BEDF8 003BEDF8 05004014 */  bnez       $2, .L003BEE10
    /* 2BEDFC 003BEDFC 2D980000 */   daddu     $19, $0, $0
  .L003BEE00:
    /* 2BEE00 003BEE00 14000010 */  b          .L003BEE54
    /* 2BEE04 003BEE04 2D102002 */   daddu     $2, $17, $0
  .L003BEE08:
    /* 2BEE08 003BEE08 12000010 */  b          .L003BEE54
    /* 2BEE0C 003BEE0C 2D100000 */   daddu     $2, $0, $0
  .L003BEE10:
    /* 2BEE10 003BEE10 2D900000 */  daddu      $18, $0, $0
  .L003BEE14:
    /* 2BEE14 003BEE14 0000228E */  lw         $2, 0x0($17)
    /* 2BEE18 003BEE18 21105200 */  addu       $2, $2, $18
    /* 2BEE1C 003BEE1C 0000448C */  lw         $4, 0x0($2)
    /* 2BEE20 003BEE20 3C0B0F0C */  jal        func_003c2cf0
    /* 2BEE24 003BEE24 2D280002 */   daddu     $5, $16, $0
    /* 2BEE28 003BEE28 03004014 */  bnez       $2, .L003BEE38
    /* 2BEE2C 003BEE2C 00000000 */   nop
    /* 2BEE30 003BEE30 08000010 */  b          .L003BEE54
    /* 2BEE34 003BEE34 2D100000 */   daddu     $2, $0, $0
  .L003BEE38:
    /* 2BEE38 003BEE38 0400228E */  lw         $2, 0x4($17)
    /* 2BEE3C 003BEE3C 01007326 */  addiu      $19, $19, 0x1
    /* 2BEE40 003BEE40 2A106202 */  slt        $2, $19, $2
    /* 2BEE44 003BEE44 F3FF4014 */  bnez       $2, .L003BEE14
    /* 2BEE48 003BEE48 04005226 */   addiu     $18, $18, 0x4
    /* 2BEE4C 003BEE4C ECFF0010 */  b          .L003BEE00
    /* 2BEE50 003BEE50 00000000 */   nop
  .L003BEE54:
    /* 2BEE54 003BEE54 5000BFDF */  ld         $31, 0x50($29)
    /* 2BEE58 003BEE58 4000B47B */  lq         $20, 0x40($29)
    /* 2BEE5C 003BEE5C 3000B37B */  lq         $19, 0x30($29)
    /* 2BEE60 003BEE60 2000B27B */  lq         $18, 0x20($29)
    /* 2BEE64 003BEE64 1000B17B */  lq         $17, 0x10($29)
    /* 2BEE68 003BEE68 0000B07B */  lq         $16, 0x0($29)
    /* 2BEE6C 003BEE6C 0800E003 */  jr         $31
    /* 2BEE70 003BEE70 7000BD27 */   addiu     $29, $29, 0x70
    /* 2BEE74 003BEE74 00000000 */  nop
    /* 2BEE78 003BEE78 00000000 */  nop
    /* 2BEE7C 003BEE7C 00000000 */  nop
.size func_003bed10, 0x170
