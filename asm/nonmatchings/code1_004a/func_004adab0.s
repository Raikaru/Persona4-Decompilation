.section .text
.set noat
.set noreorder
glabel func_004adab0
    /* 3ADAB0 004ADAB0 B0FFBD27 */  addiu      $29, $29, -0x50
    /* 3ADAB4 004ADAB4 4000BFFF */  sd         $31, 0x40($29)
    /* 3ADAB8 004ADAB8 3000B37F */  sq         $19, 0x30($29)
    /* 3ADABC 004ADABC 2000B27F */  sq         $18, 0x20($29)
    /* 3ADAC0 004ADAC0 1000B17F */  sq         $17, 0x10($29)
    /* 3ADAC4 004ADAC4 0000B07F */  sq         $16, 0x0($29)
    /* 3ADAC8 004ADAC8 2D988000 */  daddu      $19, $4, $0
    /* 3ADACC 004ADACC 9C00828C */  lw         $2, 0x9C($4)
    /* 3ADAD0 004ADAD0 0E004010 */  beqz       $2, .L004ADB0C
    /* 3ADAD4 004ADAD4 00000000 */   nop
    /* 3ADAD8 004ADAD8 2800708E */  lw         $16, 0x28($19)
    /* 3ADADC 004ADADC 9800728E */  lw         $18, 0x98($19)
    /* 3ADAE0 004ADAE0 2D880000 */  daddu      $17, $0, $0
    /* 3ADAE4 004ADAE4 06000010 */  b          .L004ADB00
    /* 3ADAE8 004ADAE8 00000000 */   nop
  .L004ADAEC:
    /* 3ADAEC 004ADAEC 0000448E */  lw         $4, 0x0($18)
    /* 3ADAF0 004ADAF0 F817120C */  jal        func_00485fe0
    /* 3ADAF4 004ADAF4 00000000 */   nop
    /* 3ADAF8 004ADAF8 04005226 */  addiu      $18, $18, 0x4
    /* 3ADAFC 004ADAFC 01003126 */  addiu      $17, $17, 0x1
  .L004ADB00:
    /* 3ADB00 004ADB00 2B103002 */  sltu       $2, $17, $16
    /* 3ADB04 004ADB04 F9FF4014 */  bnez       $2, .L004ADAEC
    /* 3ADB08 004ADB08 00000000 */   nop
  .L004ADB0C:
    /* 3ADB0C 004ADB0C 00608044 */  mtc1       $0, $f12
    /* 3ADB10 004ADB10 A000648E */  lw         $4, 0xA0($19)
    /* 3ADB14 004ADB14 2D280000 */  daddu      $5, $0, $0
    /* 3ADB18 004ADB18 98E7110C */  jal        func_00479e60
    /* 3ADB1C 004ADB1C 00000000 */   nop
    /* 3ADB20 004ADB20 2C0060AE */  sw         $0, 0x2C($19)
    /* 3ADB24 004ADB24 4000BFDF */  ld         $31, 0x40($29)
    /* 3ADB28 004ADB28 3000B37B */  lq         $19, 0x30($29)
    /* 3ADB2C 004ADB2C 2000B27B */  lq         $18, 0x20($29)
    /* 3ADB30 004ADB30 1000B17B */  lq         $17, 0x10($29)
    /* 3ADB34 004ADB34 0000B07B */  lq         $16, 0x0($29)
    /* 3ADB38 004ADB38 5000BD27 */  addiu      $29, $29, 0x50
    /* 3ADB3C 004ADB3C 0800E003 */  jr         $31
    /* 3ADB40 004ADB40 00000000 */   nop
    /* 3ADB44 004ADB44 00000000 */  nop
    /* 3ADB48 004ADB48 00000000 */  nop
    /* 3ADB4C 004ADB4C 00000000 */  nop
.size func_004adab0, 0xa0
