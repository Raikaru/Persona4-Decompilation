.section .text
.set noat
.set noreorder
glabel func_003bcfb0
    /* 2BCFB0 003BCFB0 80B6838F */  lw         $3, -0x4980($28)
    /* 2BCFB4 003BCFB4 2D100000 */  daddu      $2, $0, $0
    /* 2BCFB8 003BCFB8 21188300 */  addu       $3, $4, $3
    /* 2BCFBC 003BCFBC 0000648C */  lw         $4, 0x0($3)
    /* 2BCFC0 003BCFC0 2A080400 */  slt        $1, $0, $4
    /* 2BCFC4 003BCFC4 0A002010 */  beqz       $1, .L003BCFF0
    /* 2BCFC8 003BCFC8 2D300000 */   daddu     $6, $0, $0
    /* 2BCFCC 003BCFCC 0400658C */  lw         $5, 0x4($3)
  .L003BCFD0:
    /* 2BCFD0 003BCFD0 0C00A38C */  lw         $3, 0xC($5)
    /* 2BCFD4 003BCFD4 02006010 */  beqz       $3, .L003BCFE0
    /* 2BCFD8 003BCFD8 00000000 */   nop
    /* 2BCFDC 003BCFDC 01004224 */  addiu      $2, $2, 0x1
  .L003BCFE0:
    /* 2BCFE0 003BCFE0 0100C624 */  addiu      $6, $6, 0x1
    /* 2BCFE4 003BCFE4 2A18C400 */  slt        $3, $6, $4
    /* 2BCFE8 003BCFE8 F9FF6014 */  bnez       $3, .L003BCFD0
    /* 2BCFEC 003BCFEC 1000A524 */   addiu     $5, $5, 0x10
  .L003BCFF0:
    /* 2BCFF0 003BCFF0 0800E003 */  jr         $31
    /* 2BCFF4 003BCFF4 00000000 */   nop
    /* 2BCFF8 003BCFF8 00000000 */  nop
    /* 2BCFFC 003BCFFC 00000000 */  nop
.size func_003bcfb0, 0x50
