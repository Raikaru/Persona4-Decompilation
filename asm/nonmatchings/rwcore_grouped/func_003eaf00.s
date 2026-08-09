.section .text
.set noat
.set noreorder
glabel func_003eaf00
    /* 2EAF00 003EAF00 D0FFBD27 */  addiu      $29, $29, -0x30
    /* 2EAF04 003EAF04 2000BFFF */  sd         $31, 0x20($29)
    /* 2EAF08 003EAF08 1000B17F */  sq         $17, 0x10($29)
    /* 2EAF0C 003EAF0C 0000B07F */  sq         $16, 0x0($29)
    /* 2EAF10 003EAF10 2D888000 */  daddu      $17, $4, $0
    /* 2EAF14 003EAF14 44780F0C */  jal        func_003de110
    /* 2EAF18 003EAF18 2D80A000 */   daddu     $16, $5, $0
    /* 2EAF1C 003EAF1C 03004014 */  bnez       $2, .L003EAF2C
    /* 2EAF20 003EAF20 00000000 */   nop
  .L003EAF24:
    /* 2EAF24 003EAF24 09000010 */  b          .L003EAF4C
    /* 2EAF28 003EAF28 2D102002 */   daddu     $2, $17, $0
  .L003EAF2C:
    /* 2EAF2C 003EAF2C 0000028E */  lw         $2, 0x0($16)
    /* 2EAF30 003EAF30 09F84000 */  jalr       $2
    /* 2EAF34 003EAF34 2D202002 */   daddu     $4, $17, $0
    /* 2EAF38 003EAF38 040002AE */  sw         $2, 0x4($16)
    /* 2EAF3C 003EAF3C 0400028E */  lw         $2, 0x4($16)
    /* 2EAF40 003EAF40 F8FF4010 */  beqz       $2, .L003EAF24
    /* 2EAF44 003EAF44 00000000 */   nop
    /* 2EAF48 003EAF48 2D100000 */  daddu      $2, $0, $0
  .L003EAF4C:
    /* 2EAF4C 003EAF4C 2000BFDF */  ld         $31, 0x20($29)
    /* 2EAF50 003EAF50 1000B17B */  lq         $17, 0x10($29)
    /* 2EAF54 003EAF54 0000B07B */  lq         $16, 0x0($29)
    /* 2EAF58 003EAF58 0800E003 */  jr         $31
    /* 2EAF5C 003EAF5C 3000BD27 */   addiu     $29, $29, 0x30
.size func_003eaf00, 0x60
