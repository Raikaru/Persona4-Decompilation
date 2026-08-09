.section .text
.set noat
.set noreorder
glabel func_003eee70
    /* 2EEE70 003EEE70 00008380 */  lb         $3, 0x0($4)
    /* 2EEE74 003EEE74 2B100300 */  sltu       $2, $0, $3
    /* 2EEE78 003EEE78 01004238 */  xori       $2, $2, 0x1
    /* 2EEE7C 003EEE7C 2C004014 */  bnez       $2, .L003EEF30
    /* 2EEE80 003EEE80 00000000 */   nop
    /* 2EEE84 003EEE84 0000A280 */  lb         $2, 0x0($5)
    /* 2EEE88 003EEE88 29004010 */  beqz       $2, .L003EEF30
    /* 2EEE8C 003EEE8C 00000000 */   nop
    /* 2EEE90 003EEE90 3C3E0300 */  dsll32     $7, $3, 24
    /* 2EEE94 003EEE94 3C360200 */  dsll32     $6, $2, 24
    /* 2EEE98 003EEE98 3F3E0700 */  dsra32     $7, $7, 24
    /* 2EEE9C 003EEE9C 6100E228 */  slti       $2, $7, 0x61
    /* 2EEEA0 003EEEA0 07004014 */  bnez       $2, .L003EEEC0
    /* 2EEEA4 003EEEA4 3F360600 */   dsra32    $6, $6, 24
    /* 2EEEA8 003EEEA8 7B00E128 */  slti       $1, $7, 0x7B
    /* 2EEEAC 003EEEAC 04002010 */  beqz       $1, .L003EEEC0
    /* 2EEEB0 003EEEB0 00000000 */   nop
    /* 2EEEB4 003EEEB4 E0FFE224 */  addiu      $2, $7, -0x20
    /* 2EEEB8 003EEEB8 3C3E0200 */  dsll32     $7, $2, 24
    /* 2EEEBC 003EEEBC 3F3E0700 */  dsra32     $7, $7, 24
  .L003EEEC0:
    /* 2EEEC0 003EEEC0 3C1E0600 */  dsll32     $3, $6, 24
    /* 2EEEC4 003EEEC4 3F1E0300 */  dsra32     $3, $3, 24
    /* 2EEEC8 003EEEC8 61006228 */  slti       $2, $3, 0x61
    /* 2EEECC 003EEECC 08004014 */  bnez       $2, .L003EEEF0
    /* 2EEED0 003EEED0 00000000 */   nop
    /* 2EEED4 003EEED4 7B006128 */  slti       $1, $3, 0x7B
    /* 2EEED8 003EEED8 05002010 */  beqz       $1, .L003EEEF0
    /* 2EEEDC 003EEEDC 00000000 */   nop
    /* 2EEEE0 003EEEE0 E0FFC224 */  addiu      $2, $6, -0x20
    /* 2EEEE4 003EEEE4 3C360200 */  dsll32     $6, $2, 24
    /* 2EEEE8 003EEEE8 3F360600 */  dsra32     $6, $6, 24
    /* 2EEEEC 003EEEEC 00000000 */  nop
  .L003EEEF0:
    /* 2EEEF0 003EEEF0 3C1E0700 */  dsll32     $3, $7, 24
    /* 2EEEF4 003EEEF4 3C160600 */  dsll32     $2, $6, 24
    /* 2EEEF8 003EEEF8 3F1E0300 */  dsra32     $3, $3, 24
    /* 2EEEFC 003EEEFC 3F160200 */  dsra32     $2, $2, 24
    /* 2EEF00 003EEF00 05006214 */  bne        $3, $2, .L003EEF18
    /* 2EEF04 003EEF04 00000000 */   nop
    /* 2EEF08 003EEF08 01008424 */  addiu      $4, $4, 0x1
    .word 0x1000FFD8  /* 003EEF0C: data */
    /* 2EEF10 003EEF10 0100A524 */   addiu     $5, $5, 0x1
    /* 2EEF14 003EEF14 00000000 */  nop
  .L003EEF18:
    /* 2EEF18 003EEF18 0C000010 */  b          .L003EEF4C
    /* 2EEF1C 003EEF1C 2D100000 */   daddu     $2, $0, $0
  .L003EEF20:
    /* 2EEF20 003EEF20 0A000010 */  b          .L003EEF4C
    /* 2EEF24 003EEF24 01000224 */   addiu     $2, $0, 0x1
  .L003EEF28:
    /* 2EEF28 003EEF28 08000010 */  b          .L003EEF4C
    /* 2EEF2C 003EEF2C 2D100000 */   daddu     $2, $0, $0
  .L003EEF30:
    /* 2EEF30 003EEF30 0000A280 */  lb         $2, 0x0($5)
    /* 2EEF34 003EEF34 3C1E0300 */  dsll32     $3, $3, 24
    /* 2EEF38 003EEF38 3F1E0300 */  dsra32     $3, $3, 24
    /* 2EEF3C 003EEF3C FAFF6214 */  bne        $3, $2, .L003EEF28
    /* 2EEF40 003EEF40 00000000 */   nop
    /* 2EEF44 003EEF44 F6FF0010 */  b          .L003EEF20
    /* 2EEF48 003EEF48 00000000 */   nop
  .L003EEF4C:
    /* 2EEF4C 003EEF4C 0800E003 */  jr         $31
    /* 2EEF50 003EEF50 00000000 */   nop
    /* 2EEF54 003EEF54 00000000 */  nop
    /* 2EEF58 003EEF58 00000000 */  nop
    /* 2EEF5C 003EEF5C 00000000 */  nop
.size func_003eee70, 0xf0
