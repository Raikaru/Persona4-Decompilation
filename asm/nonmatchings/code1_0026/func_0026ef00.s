.section .text
.set noat
.set noreorder
glabel func_0026ef00
    /* 16EF00 0026EF00 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 16EF04 0026EF04 1000BFFF */  sd         $31, 0x10($29)
    /* 16EF08 0026EF08 0000B07F */  sq         $16, 0x0($29)
    /* 16EF0C 0026EF0C 2D80A000 */  daddu      $16, $5, $0
    /* 16EF10 0026EF10 A8D1090C */  jal        func_002746a0
    /* 16EF14 0026EF14 00000000 */   nop
    /* 16EF18 0026EF18 04004010 */  beqz       $2, .L0026EF2C
    /* 16EF1C 0026EF1C 00000000 */   nop
    /* 16EF20 0026EF20 2D100000 */  daddu      $2, $0, $0
    /* 16EF24 0026EF24 07000010 */  b          .L0026EF44
    /* 16EF28 0026EF28 00000000 */   nop
  .L0026EF2C:
    /* 16EF2C 0026EF2C 14000224 */  addiu      $2, $0, 0x14
    /* 16EF30 0026EF30 0F0002A2 */  sb         $2, 0xF($16)
    /* 16EF34 0026EF34 20000224 */  addiu      $2, $0, 0x20
    /* 16EF38 0026EF38 1E0002A6 */  sh         $2, 0x1E($16)
    /* 16EF3C 0026EF3C BCB480AF */  sw         $0, -0x4B44($28)
    /* 16EF40 0026EF40 2D100000 */  daddu      $2, $0, $0
  .L0026EF44:
    /* 16EF44 0026EF44 1000BFDF */  ld         $31, 0x10($29)
    /* 16EF48 0026EF48 0000B07B */  lq         $16, 0x0($29)
    /* 16EF4C 0026EF4C 2000BD27 */  addiu      $29, $29, 0x20
    /* 16EF50 0026EF50 0800E003 */  jr         $31
    /* 16EF54 0026EF54 00000000 */   nop
    /* 16EF58 0026EF58 00000000 */  nop
    /* 16EF5C 0026EF5C 00000000 */  nop
.size func_0026ef00, 0x60
