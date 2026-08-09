.section .text
.set noat
.set noreorder
glabel func_003bea60
    /* 2BEA60 003BEA60 B0FFBD27 */  addiu      $29, $29, -0x50
    /* 2BEA64 003BEA64 3000BFFF */  sd         $31, 0x30($29)
    /* 2BEA68 003BEA68 2000B27F */  sq         $18, 0x20($29)
    /* 2BEA6C 003BEA6C 1000B17F */  sq         $17, 0x10($29)
    /* 2BEA70 003BEA70 2D908000 */  daddu      $18, $4, $0
    /* 2BEA74 003BEA74 2D88A000 */  daddu      $17, $5, $0
    /* 2BEA78 003BEA78 E8000F0C */  jal        func_003c03a0
    /* 2BEA7C 003BEA7C 0000B07F */   sq        $16, 0x0($29)
    /* 2BEA80 003BEA80 2D804000 */  daddu      $16, $2, $0
    /* 2BEA84 003BEA84 0C000012 */  beqz       $16, .L003BEAB8
    /* 2BEA88 003BEA88 00000000 */   nop
    /* 2BEA8C 003BEA8C 0400428E */  lw         $2, 0x4($18)
    /* 2BEA90 003BEA90 0C004010 */  beqz       $2, .L003BEAC4
    /* 2BEA94 003BEA94 00000000 */   nop
    /* 2BEA98 003BEA98 A000458C */  lw         $5, 0xA0($2)
    /* 2BEA9C 003BEA9C E4060F0C */  jal        func_003c1b90
    /* 2BEAA0 003BEAA0 2D200002 */   daddu     $4, $16, $0
    /* 2BEAA4 003BEAA4 0400248E */  lw         $4, 0x4($17)
    /* 2BEAA8 003BEAA8 14020F0C */  jal        func_003c0850
    /* 2BEAAC 003BEAAC 2D280002 */   daddu     $5, $16, $0
    /* 2BEAB0 003BEAB0 0E000010 */  b          .L003BEAEC
    /* 2BEAB4 003BEAB4 2D104002 */   daddu     $2, $18, $0
  .L003BEAB8:
    /* 2BEAB8 003BEAB8 080020AE */  sw         $0, 0x8($17)
    /* 2BEABC 003BEABC 0B000010 */  b          .L003BEAEC
    /* 2BEAC0 003BEAC0 2D100000 */   daddu     $2, $0, $0
  .L003BEAC4:
    /* 2BEAC4 003BEAC4 B8000F0C */  jal        func_003c02e0
    /* 2BEAC8 003BEAC8 2D200002 */   daddu     $4, $16, $0
    /* 2BEACC 003BEACC 02000224 */  addiu      $2, $0, 0x2
    /* 2BEAD0 003BEAD0 05000424 */  addiu      $4, $0, 0x5
    /* 2BEAD4 003BEAD4 647D0F0C */  jal        func_003df590
    /* 2BEAD8 003BEAD8 4800A2AF */   sw        $2, 0x48($29)
    /* 2BEADC 003BEADC 4C00A2AF */  sw         $2, 0x4C($29)
    /* 2BEAE0 003BEAE0 347D0F0C */  jal        func_003df4d0
    /* 2BEAE4 003BEAE4 4800A427 */   addiu     $4, $29, 0x48
    /* 2BEAE8 003BEAE8 2D100000 */  daddu      $2, $0, $0
  .L003BEAEC:
    /* 2BEAEC 003BEAEC 3000BFDF */  ld         $31, 0x30($29)
    /* 2BEAF0 003BEAF0 2000B27B */  lq         $18, 0x20($29)
    /* 2BEAF4 003BEAF4 1000B17B */  lq         $17, 0x10($29)
    /* 2BEAF8 003BEAF8 0000B07B */  lq         $16, 0x0($29)
    /* 2BEAFC 003BEAFC 0800E003 */  jr         $31
    /* 2BEB00 003BEB00 5000BD27 */   addiu     $29, $29, 0x50
    /* 2BEB04 003BEB04 00000000 */  nop
    /* 2BEB08 003BEB08 00000000 */  nop
    /* 2BEB0C 003BEB0C 00000000 */  nop
.size func_003bea60, 0xb0
