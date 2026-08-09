.section .text
.set noat
.set noreorder
glabel func_003cdfa0
    /* 2CDFA0 003CDFA0 B0FFBD27 */  addiu      $29, $29, -0x50
    /* 2CDFA4 003CDFA4 4000BFFF */  sd         $31, 0x40($29)
    /* 2CDFA8 003CDFA8 3000B37F */  sq         $19, 0x30($29)
    /* 2CDFAC 003CDFAC 2000B27F */  sq         $18, 0x20($29)
    /* 2CDFB0 003CDFB0 1000B17F */  sq         $17, 0x10($29)
    /* 2CDFB4 003CDFB4 2D908000 */  daddu      $18, $4, $0
    /* 2CDFB8 003CDFB8 0000B07F */  sq         $16, 0x0($29)
    /* 2CDFBC 003CDFBC 0000828C */  lw         $2, 0x0($4)
    /* 2CDFC0 003CDFC0 17004010 */  beqz       $2, .L003CE020
    /* 2CDFC4 003CDFC4 FFFF5124 */   addiu     $17, $2, -0x1
    /* 2CDFC8 003CDFC8 80101100 */  sll        $2, $17, 2
    /* 2CDFCC 003CDFCC 21804202 */  addu       $16, $18, $2
  .L003CDFD0:
    /* 2CDFD0 003CDFD0 0400138E */  lw         $19, 0x4($16)
    /* 2CDFD4 003CDFD4 0E006012 */  beqz       $19, .L003CE010
    /* 2CDFD8 003CDFD8 00000000 */   nop
    /* 2CDFDC 003CDFDC 0000628E */  lw         $2, 0x0($19)
    /* 2CDFE0 003CDFE0 03004010 */  beqz       $2, .L003CDFF0
    /* 2CDFE4 003CDFE4 00000000 */   nop
  .L003CDFE8:
    /* 2CDFE8 003CDFE8 09000010 */  b          .L003CE010
    /* 2CDFEC 003CDFEC 100060AE */   sw        $0, 0x10($19)
  .L003CDFF0:
    /* 2CDFF0 003CDFF0 0400628E */  lw         $2, 0x4($19)
    /* 2CDFF4 003CDFF4 FCFF4014 */  bnez       $2, .L003CDFE8
    /* 2CDFF8 003CDFF8 00000000 */   nop
    /* 2CDFFC 003CDFFC B8310F0C */  jal        func_003cc6e0
    /* 2CE000 003CE000 2D206002 */   daddu     $4, $19, $0
    /* 2CE004 003CE004 A8870F0C */  jal        func_003e1ea0
    /* 2CE008 003CE008 2D206002 */   daddu     $4, $19, $0
    /* 2CE00C 003CE00C 00000000 */  nop
  .L003CE010:
    /* 2CE010 003CE010 2D102002 */  daddu      $2, $17, $0
    /* 2CE014 003CE014 FCFF1026 */  addiu      $16, $16, -0x4
    /* 2CE018 003CE018 EDFF4014 */  bnez       $2, .L003CDFD0
    /* 2CE01C 003CE01C FFFF3126 */   addiu     $17, $17, -0x1
  .L003CE020:
    /* 2CE020 003CE020 8800023C */  lui        $2, %hi(jtbl_008873EC)
    /* 2CE024 003CE024 EC73428C */  lw         $2, %lo(jtbl_008873EC)($2)
    /* 2CE028 003CE028 09F84000 */  jalr       $2
    /* 2CE02C 003CE02C 2D204002 */   daddu     $4, $18, $0
    /* 2CE030 003CE030 4000BFDF */  ld         $31, 0x40($29)
    /* 2CE034 003CE034 3000B37B */  lq         $19, 0x30($29)
    /* 2CE038 003CE038 2000B27B */  lq         $18, 0x20($29)
    /* 2CE03C 003CE03C 1000B17B */  lq         $17, 0x10($29)
    /* 2CE040 003CE040 0000B07B */  lq         $16, 0x0($29)
    /* 2CE044 003CE044 0800E003 */  jr         $31
    /* 2CE048 003CE048 5000BD27 */   addiu     $29, $29, 0x50
    /* 2CE04C 003CE04C 00000000 */  nop
.size func_003cdfa0, 0xb0
