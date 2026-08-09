.section .text
.set noat
.set noreorder
glabel func_003bfe90
    /* 2BFE90 003BFE90 B0FFBD27 */  addiu      $29, $29, -0x50
    /* 2BFE94 003BFE94 4000BFFF */  sd         $31, 0x40($29)
    /* 2BFE98 003BFE98 3000B37F */  sq         $19, 0x30($29)
    /* 2BFE9C 003BFE9C 2000B27F */  sq         $18, 0x20($29)
    /* 2BFEA0 003BFEA0 1000B17F */  sq         $17, 0x10($29)
    /* 2BFEA4 003BFEA4 08009224 */  addiu      $18, $4, 0x8
    /* 2BFEA8 003BFEA8 0000B07F */  sq         $16, 0x0($29)
    /* 2BFEAC 003BFEAC 0800908C */  lw         $16, 0x8($4)
    /* 2BFEB0 003BFEB0 09001212 */  beq        $16, $18, .L003BFED8
    /* 2BFEB4 003BFEB4 2D888000 */   daddu     $17, $4, $0
  .L003BFEB8:
    /* 2BFEB8 003BFEB8 C2FF0292 */  lbu        $2, -0x3E($16)
    /* 2BFEBC 003BFEBC 04004230 */  andi       $2, $2, 0x4
    /* 2BFEC0 003BFEC0 07004014 */  bnez       $2, .L003BFEE0
    /* 2BFEC4 003BFEC4 C0FF1326 */   addiu     $19, $16, -0x40
  .L003BFEC8:
    /* 2BFEC8 003BFEC8 0000108E */  lw         $16, 0x0($16)
    /* 2BFECC 003BFECC FAFF1216 */  bne        $16, $18, .L003BFEB8
    /* 2BFED0 003BFED0 00000000 */   nop
    /* 2BFED4 003BFED4 00000000 */  nop
  .L003BFED8:
    /* 2BFED8 003BFED8 0B000010 */  b          .L003BFF08
    /* 2BFEDC 003BFEDC 2D102002 */   daddu     $2, $17, $0
  .L003BFEE0:
    /* 2BFEE0 003BFEE0 C0A50F0C */  jal        func_003e9700
    /* 2BFEE4 003BFEE4 0400648E */   lw        $4, 0x4($19)
    /* 2BFEE8 003BFEE8 4800628E */  lw         $2, 0x48($19)
    /* 2BFEEC 003BFEEC 09F84000 */  jalr       $2
    /* 2BFEF0 003BFEF0 2D206002 */   daddu     $4, $19, $0
    /* 2BFEF4 003BFEF4 F4FF4014 */  bnez       $2, .L003BFEC8
    /* 2BFEF8 003BFEF8 00000000 */   nop
    /* 2BFEFC 003BFEFC F2FF0010 */  b          .L003BFEC8
    /* 2BFF00 003BFF00 2D880000 */   daddu     $17, $0, $0
    /* 2BFF04 003BFF04 00000000 */  nop
  .L003BFF08:
    /* 2BFF08 003BFF08 4000BFDF */  ld         $31, 0x40($29)
    /* 2BFF0C 003BFF0C 3000B37B */  lq         $19, 0x30($29)
    /* 2BFF10 003BFF10 2000B27B */  lq         $18, 0x20($29)
    /* 2BFF14 003BFF14 1000B17B */  lq         $17, 0x10($29)
    /* 2BFF18 003BFF18 0000B07B */  lq         $16, 0x0($29)
    /* 2BFF1C 003BFF1C 0800E003 */  jr         $31
    /* 2BFF20 003BFF20 5000BD27 */   addiu     $29, $29, 0x50
    /* 2BFF24 003BFF24 00000000 */  nop
    /* 2BFF28 003BFF28 00000000 */  nop
    /* 2BFF2C 003BFF2C 00000000 */  nop
.size func_003bfe90, 0xa0
