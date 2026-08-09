.section .text
.set noat
.set noreorder
glabel func_001fae80
    /* FAE80 001FAE80 90FFBD27 */  addiu      $29, $29, -0x70
    /* FAE84 001FAE84 2000BFFF */  sd         $31, 0x20($29)
    /* FAE88 001FAE88 1000B17F */  sq         $17, 0x10($29)
    /* FAE8C 001FAE8C 0000B07F */  sq         $16, 0x0($29)
    /* FAE90 001FAE90 2D888000 */  daddu      $17, $4, $0
    /* FAE94 001FAE94 0400A01C */  bgtz       $5, .L001FAEA8
    /* FAE98 001FAE98 00000000 */   nop
    /* FAE9C 001FAE9C 2D100000 */  daddu      $2, $0, $0
    /* FAEA0 001FAEA0 2B000010 */  b          .L001FAF50
    /* FAEA4 001FAEA4 00000000 */   nop
  .L001FAEA8:
    /* FAEA8 001FAEA8 80100500 */  sll        $2, $5, 2
    /* FAEAC 001FAEAC 21104500 */  addu       $2, $2, $5
    /* FAEB0 001FAEB0 C0800200 */  sll        $16, $2, 3
    /* FAEB4 001FAEB4 B8B3828F */  lw         $2, -0x4C48($28)
    /* FAEB8 001FAEB8 21185000 */  addu       $3, $2, $16
    /* FAEBC 001FAEBC 00006290 */  lbu        $2, 0x0($3)
    /* FAEC0 001FAEC0 08004230 */  andi       $2, $2, 0x8
    /* FAEC4 001FAEC4 04004014 */  bnez       $2, .L001FAED8
    /* FAEC8 001FAEC8 00000000 */   nop
    /* FAECC 001FAECC 2D100000 */  daddu      $2, $0, $0
    /* FAED0 001FAED0 1F000010 */  b          .L001FAF50
    /* FAED4 001FAED4 00000000 */   nop
  .L001FAED8:
    /* FAED8 001FAED8 0C006894 */  lhu        $8, 0xC($3)
    /* FAEDC 001FAEDC 3000A527 */  addiu      $5, $29, 0x30
    /* FAEE0 001FAEE0 09006690 */  lbu        $6, 0x9($3)
    /* FAEE4 001FAEE4 0A006790 */  lbu        $7, 0xA($3)
    /* FAEE8 001FAEE8 185F070C */  jal        func_001d7c60
    /* FAEEC 001FAEEC 00000000 */   nop
    /* FAEF0 001FAEF0 6800A297 */  lhu        $2, 0x68($29)
    /* FAEF4 001FAEF4 04004014 */  bnez       $2, .L001FAF08
    /* FAEF8 001FAEF8 00000000 */   nop
    /* FAEFC 001FAEFC 02000224 */  addiu      $2, $0, 0x2
    /* FAF00 001FAF00 13000010 */  b          .L001FAF50
    /* FAF04 001FAF04 00000000 */   nop
  .L001FAF08:
    /* FAF08 001FAF08 B8B3828F */  lw         $2, -0x4C48($28)
    /* FAF0C 001FAF0C 21100202 */  addu       $2, $16, $2
    /* FAF10 001FAF10 24004390 */  lbu        $3, 0x24($2)
    /* FAF14 001FAF14 02000224 */  addiu      $2, $0, 0x2
    /* FAF18 001FAF18 03006210 */  beq        $3, $2, .L001FAF28
    /* FAF1C 001FAF1C 00000000 */   nop
    /* FAF20 001FAF20 0A000010 */  b          .L001FAF4C
    /* FAF24 001FAF24 00000000 */   nop
  .L001FAF28:
    /* FAF28 001FAF28 2D202002 */  daddu      $4, $17, $0
    /* FAF2C 001FAF2C 2D280000 */  daddu      $5, $0, $0
    /* FAF30 001FAF30 4C68070C */  jal        func_001da130
    /* FAF34 001FAF34 00000000 */   nop
    /* FAF38 001FAF38 04004014 */  bnez       $2, .L001FAF4C
    /* FAF3C 001FAF3C 00000000 */   nop
    /* FAF40 001FAF40 06000224 */  addiu      $2, $0, 0x6
    /* FAF44 001FAF44 02000010 */  b          .L001FAF50
    /* FAF48 001FAF48 00000000 */   nop
  .L001FAF4C:
    /* FAF4C 001FAF4C 2D100000 */  daddu      $2, $0, $0
  .L001FAF50:
    /* FAF50 001FAF50 2000BFDF */  ld         $31, 0x20($29)
    /* FAF54 001FAF54 1000B17B */  lq         $17, 0x10($29)
    /* FAF58 001FAF58 0000B07B */  lq         $16, 0x0($29)
    /* FAF5C 001FAF5C 7000BD27 */  addiu      $29, $29, 0x70
    /* FAF60 001FAF60 0800E003 */  jr         $31
    /* FAF64 001FAF64 00000000 */   nop
    /* FAF68 001FAF68 00000000 */  nop
    /* FAF6C 001FAF6C 00000000 */  nop
.size func_001fae80, 0xf0
