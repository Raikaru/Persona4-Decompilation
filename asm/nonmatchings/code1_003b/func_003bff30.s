.section .text
.set noat
.set noreorder
glabel func_003bff30
    /* 2BFF30 003BFF30 A0FFBD27 */  addiu      $29, $29, -0x60
    /* 2BFF34 003BFF34 5000BFFF */  sd         $31, 0x50($29)
    /* 2BFF38 003BFF38 4000B47F */  sq         $20, 0x40($29)
    /* 2BFF3C 003BFF3C 3000B37F */  sq         $19, 0x30($29)
    /* 2BFF40 003BFF40 2DA08000 */  daddu      $20, $4, $0
    /* 2BFF44 003BFF44 2000B27F */  sq         $18, 0x20($29)
    /* 2BFF48 003BFF48 2D98A000 */  daddu      $19, $5, $0
    /* 2BFF4C 003BFF4C 1000B17F */  sq         $17, 0x10($29)
    /* 2BFF50 003BFF50 0000B07F */  sq         $16, 0x0($29)
    /* 2BFF54 003BFF54 08009126 */  addiu      $17, $20, 0x8
    /* 2BFF58 003BFF58 0800828C */  lw         $2, 0x8($4)
    /* 2BFF5C 003BFF5C 0C005110 */  beq        $2, $17, .L003BFF90
    /* 2BFF60 003BFF60 2D90C000 */   daddu     $18, $6, $0
  .L003BFF64:
    /* 2BFF64 003BFF64 0000508C */  lw         $16, 0x0($2)
    /* 2BFF68 003BFF68 C0FF4424 */  addiu      $4, $2, -0x40
    /* 2BFF6C 003BFF6C 09F86002 */  jalr       $19
    /* 2BFF70 003BFF70 2D284002 */   daddu     $5, $18, $0
    /* 2BFF74 003BFF74 03004014 */  bnez       $2, .L003BFF84
    /* 2BFF78 003BFF78 00000000 */   nop
    /* 2BFF7C 003BFF7C 05000010 */  b          .L003BFF94
    /* 2BFF80 003BFF80 2D108002 */   daddu     $2, $20, $0
  .L003BFF84:
    /* 2BFF84 003BFF84 F7FF1116 */  bne        $16, $17, .L003BFF64
    /* 2BFF88 003BFF88 2D100002 */   daddu     $2, $16, $0
    /* 2BFF8C 003BFF8C 00000000 */  nop
  .L003BFF90:
    /* 2BFF90 003BFF90 2D108002 */  daddu      $2, $20, $0
  .L003BFF94:
    /* 2BFF94 003BFF94 5000BFDF */  ld         $31, 0x50($29)
    /* 2BFF98 003BFF98 4000B47B */  lq         $20, 0x40($29)
    /* 2BFF9C 003BFF9C 3000B37B */  lq         $19, 0x30($29)
    /* 2BFFA0 003BFFA0 2000B27B */  lq         $18, 0x20($29)
    /* 2BFFA4 003BFFA4 1000B17B */  lq         $17, 0x10($29)
    /* 2BFFA8 003BFFA8 0000B07B */  lq         $16, 0x0($29)
    /* 2BFFAC 003BFFAC 0800E003 */  jr         $31
    /* 2BFFB0 003BFFB0 6000BD27 */   addiu     $29, $29, 0x60
    /* 2BFFB4 003BFFB4 00000000 */  nop
    /* 2BFFB8 003BFFB8 00000000 */  nop
    /* 2BFFBC 003BFFBC 00000000 */  nop
.size func_003bff30, 0x90
