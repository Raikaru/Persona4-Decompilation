.section .text
.set noat
.set noreorder
glabel func_003bcc80
    /* 2BCC80 003BCC80 A0FFBD27 */  addiu      $29, $29, -0x60
    /* 2BCC84 003BCC84 5000BFFF */  sd         $31, 0x50($29)
    /* 2BCC88 003BCC88 4000B47F */  sq         $20, 0x40($29)
    /* 2BCC8C 003BCC8C 3000B37F */  sq         $19, 0x30($29)
    /* 2BCC90 003BCC90 2DA08000 */  daddu      $20, $4, $0
    /* 2BCC94 003BCC94 2000B27F */  sq         $18, 0x20($29)
    /* 2BCC98 003BCC98 1000B17F */  sq         $17, 0x10($29)
    /* 2BCC9C 003BCC9C 0000B07F */  sq         $16, 0x0($29)
    /* 2BCCA0 003BCCA0 21888602 */  addu       $17, $20, $6
    /* 2BCCA4 003BCCA4 2180A600 */  addu       $16, $5, $6
    /* 2BCCA8 003BCCA8 D0F10E0C */  jal        func_003bc740
    /* 2BCCAC 003BCCAC 2D202002 */   daddu     $4, $17, $0
    /* 2BCCB0 003BCCB0 0000028E */  lw         $2, 0x0($16)
    /* 2BCCB4 003BCCB4 000022AE */  sw         $2, 0x0($17)
    /* 2BCCB8 003BCCB8 0000228E */  lw         $2, 0x0($17)
    /* 2BCCBC 003BCCBC 0300401C */  bgtz       $2, .L003BCCCC
    /* 2BCCC0 003BCCC0 00000000 */   nop
  .L003BCCC4:
    /* 2BCCC4 003BCCC4 1A000010 */  b          .L003BCD30
    /* 2BCCC8 003BCCC8 2D108002 */   daddu     $2, $20, $0
  .L003BCCCC:
    /* 2BCCCC 003BCCCC 00210200 */  sll        $4, $2, 4
    /* 2BCCD0 003BCCD0 0300023C */  lui        $2, (0x3011F >> 16)
    /* 2BCCD4 003BCCD4 1F014534 */  ori        $5, $2, (0x3011F & 0xFFFF)
    /* 2BCCD8 003BCCD8 8800023C */  lui        $2, %hi(jtbl_008873E8)
    /* 2BCCDC 003BCCDC E873428C */  lw         $2, %lo(jtbl_008873E8)($2)
    /* 2BCCE0 003BCCE0 09F84000 */  jalr       $2
    /* 2BCCE4 003BCCE4 00000000 */   nop
    /* 2BCCE8 003BCCE8 040022AE */  sw         $2, 0x4($17)
    /* 2BCCEC 003BCCEC 0000228E */  lw         $2, 0x0($17)
    /* 2BCCF0 003BCCF0 2A080200 */  slt        $1, $0, $2
    /* 2BCCF4 003BCCF4 F3FF2010 */  beqz       $1, .L003BCCC4
    /* 2BCCF8 003BCCF8 2D980000 */   daddu     $19, $0, $0
    /* 2BCCFC 003BCCFC 2D900000 */  daddu      $18, $0, $0
  .L003BCD00:
    /* 2BCD00 003BCD00 0400238E */  lw         $3, 0x4($17)
    /* 2BCD04 003BCD04 0400028E */  lw         $2, 0x4($16)
    /* 2BCD08 003BCD08 21207200 */  addu       $4, $3, $18
    /* 2BCD0C 003BCD0C E0EF0E0C */  jal        func_003bbf80
    /* 2BCD10 003BCD10 21285200 */   addu      $5, $2, $18
    /* 2BCD14 003BCD14 0000228E */  lw         $2, 0x0($17)
    /* 2BCD18 003BCD18 01007326 */  addiu      $19, $19, 0x1
    /* 2BCD1C 003BCD1C 2A106202 */  slt        $2, $19, $2
    /* 2BCD20 003BCD20 F7FF4014 */  bnez       $2, .L003BCD00
    /* 2BCD24 003BCD24 10005226 */   addiu     $18, $18, 0x10
    /* 2BCD28 003BCD28 E6FF0010 */  b          .L003BCCC4
    /* 2BCD2C 003BCD2C 00000000 */   nop
  .L003BCD30:
    /* 2BCD30 003BCD30 5000BFDF */  ld         $31, 0x50($29)
    /* 2BCD34 003BCD34 4000B47B */  lq         $20, 0x40($29)
    /* 2BCD38 003BCD38 3000B37B */  lq         $19, 0x30($29)
    /* 2BCD3C 003BCD3C 2000B27B */  lq         $18, 0x20($29)
    /* 2BCD40 003BCD40 1000B17B */  lq         $17, 0x10($29)
    /* 2BCD44 003BCD44 0000B07B */  lq         $16, 0x0($29)
    /* 2BCD48 003BCD48 0800E003 */  jr         $31
    /* 2BCD4C 003BCD4C 6000BD27 */   addiu     $29, $29, 0x60
.size func_003bcc80, 0xd0
