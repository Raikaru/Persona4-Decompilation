.section .text
.set noat
.set noreorder
glabel func_003cbe80
    /* 2CBE80 003CBE80 D0FFBD27 */  addiu      $29, $29, -0x30
    /* 2CBE84 003CBE84 2000BFFF */  sd         $31, 0x20($29)
    /* 2CBE88 003CBE88 1000B17F */  sq         $17, 0x10($29)
    /* 2CBE8C 003CBE8C 0000B07F */  sq         $16, 0x0($29)
    /* 2CBE90 003CBE90 2D888000 */  daddu      $17, $4, $0
    /* 2CBE94 003CBE94 14B7828F */  lw         $2, -0x48EC($28)
    /* 2CBE98 003CBE98 2D80A000 */  daddu      $16, $5, $0
    /* 2CBE9C 003CBE9C 21100202 */  addu       $2, $16, $2
    /* 2CBEA0 003CBEA0 000051AC */  sw         $17, 0x0($2)
    /* 2CBEA4 003CBEA4 0100A290 */  lbu        $2, 0x1($5)
    /* 2CBEA8 003CBEA8 80004228 */  slti       $2, $2, 0x80
    /* 2CBEAC 003CBEAC 10004014 */  bnez       $2, .L003CBEF0
    /* 2CBEB0 003CBEB0 00000000 */   nop
    /* 2CBEB4 003CBEB4 0400048E */  lw         $4, 0x4($16)
    /* 2CBEB8 003CBEB8 03008010 */  beqz       $4, .L003CBEC8
    /* 2CBEBC 003CBEBC 00000000 */   nop
    /* 2CBEC0 003CBEC0 A0A50F0C */  jal        func_003e9680
    /* 2CBEC4 003CBEC4 00000000 */   nop
  .L003CBEC8:
    /* 2CBEC8 003CBEC8 3400248E */  lw         $4, 0x34($17)
    /* 2CBECC 003CBECC 34002226 */  addiu      $2, $17, 0x34
    /* 2CBED0 003CBED0 34000326 */  addiu      $3, $16, 0x34
    /* 2CBED4 003CBED4 340004AE */  sw         $4, 0x34($16)
    /* 2CBED8 003CBED8 380002AE */  sw         $2, 0x38($16)
    /* 2CBEDC 003CBEDC 3400228E */  lw         $2, 0x34($17)
    /* 2CBEE0 003CBEE0 040043AC */  sw         $3, 0x4($2)
    /* 2CBEE4 003CBEE4 340023AE */  sw         $3, 0x34($17)
  .L003CBEE8:
    /* 2CBEE8 003CBEE8 0A000010 */  b          .L003CBF14
    /* 2CBEEC 003CBEEC 2D102002 */   daddu     $2, $17, $0
  .L003CBEF0:
    /* 2CBEF0 003CBEF0 3C00248E */  lw         $4, 0x3C($17)
    /* 2CBEF4 003CBEF4 3C002226 */  addiu      $2, $17, 0x3C
    /* 2CBEF8 003CBEF8 34000326 */  addiu      $3, $16, 0x34
    /* 2CBEFC 003CBEFC 340004AE */  sw         $4, 0x34($16)
    /* 2CBF00 003CBF00 380002AE */  sw         $2, 0x38($16)
    /* 2CBF04 003CBF04 3C00228E */  lw         $2, 0x3C($17)
    /* 2CBF08 003CBF08 040043AC */  sw         $3, 0x4($2)
    /* 2CBF0C 003CBF0C F6FF0010 */  b          .L003CBEE8
    /* 2CBF10 003CBF10 3C0023AE */   sw        $3, 0x3C($17)
  .L003CBF14:
    /* 2CBF14 003CBF14 2000BFDF */  ld         $31, 0x20($29)
    /* 2CBF18 003CBF18 1000B17B */  lq         $17, 0x10($29)
    /* 2CBF1C 003CBF1C 0000B07B */  lq         $16, 0x0($29)
    /* 2CBF20 003CBF20 0800E003 */  jr         $31
    /* 2CBF24 003CBF24 3000BD27 */   addiu     $29, $29, 0x30
    /* 2CBF28 003CBF28 00000000 */  nop
    /* 2CBF2C 003CBF2C 00000000 */  nop
.size func_003cbe80, 0xb0
