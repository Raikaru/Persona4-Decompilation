.section .text
.set noat
.set noreorder
glabel func_004ceef8
    /* 3CEEF8 004CEEF8 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3CEEFC 004CEEFC 0000B0FF */  sd         $16, 0x0($29)
    /* 3CEF00 004CEF00 2D808000 */  daddu      $16, $4, $0
    /* 3CEF04 004CEF04 0800BFFF */  sd         $31, 0x8($29)
    /* 3CEF08 004CEF08 320F130C */  jal        func_004c3cc8
    /* 3CEF0C 004CEF0C 0400048E */   lw        $4, 0x4($16)
    /* 3CEF10 004CEF10 0B004018 */  blez       $2, .L004CEF40
    /* 3CEF14 004CEF14 2D100000 */   daddu     $2, $0, $0
    /* 3CEF18 004CEF18 01000292 */  lbu        $2, 0x1($16)
    /* 3CEF1C 004CEF1C FEFF4224 */  addiu      $2, $2, -0x2
    /* 3CEF20 004CEF20 0200422C */  sltiu      $2, $2, 0x2
    /* 3CEF24 004CEF24 06004050 */  beql       $2, $0, .L004CEF40
    /* 3CEF28 004CEF28 2D100000 */   daddu     $2, $0, $0
    /* 3CEF2C 004CEF2C 340F130C */  jal        func_004c3cd0
    /* 3CEF30 004CEF30 0400048E */   lw        $4, 0x4($16)
    /* 3CEF34 004CEF34 03000010 */  b          .L004CEF44
    /* 3CEF38 004CEF38 0000B0DF */   ld        $16, 0x0($29)
    /* 3CEF3C 004CEF3C 00000000 */  nop
  .L004CEF40:
    /* 3CEF40 004CEF40 0000B0DF */  ld         $16, 0x0($29)
  .L004CEF44:
    /* 3CEF44 004CEF44 0800BFDF */  ld         $31, 0x8($29)
    /* 3CEF48 004CEF48 0800E003 */  jr         $31
    /* 3CEF4C 004CEF4C 1000BD27 */   addiu     $29, $29, 0x10
.size func_004ceef8, 0x58
