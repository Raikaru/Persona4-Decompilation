.section .text
.set noat
.set noreorder
glabel func_003bcf10
    /* 2BCF10 003BCF10 68B6838F */  lw         $3, -0x4998($28)
    /* 2BCF14 003BCF14 2D100000 */  daddu      $2, $0, $0
    /* 2BCF18 003BCF18 21188300 */  addu       $3, $4, $3
    /* 2BCF1C 003BCF1C 0000648C */  lw         $4, 0x0($3)
    /* 2BCF20 003BCF20 2A080400 */  slt        $1, $0, $4
    /* 2BCF24 003BCF24 0A002010 */  beqz       $1, .L003BCF50
    /* 2BCF28 003BCF28 2D300000 */   daddu     $6, $0, $0
    /* 2BCF2C 003BCF2C 0400658C */  lw         $5, 0x4($3)
  .L003BCF30:
    /* 2BCF30 003BCF30 0C00A38C */  lw         $3, 0xC($5)
    /* 2BCF34 003BCF34 02006010 */  beqz       $3, .L003BCF40
    /* 2BCF38 003BCF38 00000000 */   nop
    /* 2BCF3C 003BCF3C 01004224 */  addiu      $2, $2, 0x1
  .L003BCF40:
    /* 2BCF40 003BCF40 0100C624 */  addiu      $6, $6, 0x1
    /* 2BCF44 003BCF44 2A18C400 */  slt        $3, $6, $4
    /* 2BCF48 003BCF48 F9FF6014 */  bnez       $3, .L003BCF30
    /* 2BCF4C 003BCF4C 1000A524 */   addiu     $5, $5, 0x10
  .L003BCF50:
    /* 2BCF50 003BCF50 0800E003 */  jr         $31
    /* 2BCF54 003BCF54 00000000 */   nop
    /* 2BCF58 003BCF58 00000000 */  nop
    /* 2BCF5C 003BCF5C 00000000 */  nop
.size func_003bcf10, 0x50
