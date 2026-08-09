.section .text
.set noat
.set noreorder
glabel func_003c8da0
    /* 2C8DA0 003C8DA0 0000A28C */  lw         $2, 0x0($5)
    /* 2C8DA4 003C8DA4 03004410 */  beq        $2, $4, .L003C8DB4
    /* 2C8DA8 003C8DA8 00000000 */   nop
    /* 2C8DAC 003C8DAC 04000010 */  b          .L003C8DC0
    /* 2C8DB0 003C8DB0 2D108000 */   daddu     $2, $4, $0
  .L003C8DB4:
    /* 2C8DB4 003C8DB4 01000324 */  addiu      $3, $0, 0x1
    /* 2C8DB8 003C8DB8 2D100000 */  daddu      $2, $0, $0
    /* 2C8DBC 003C8DBC 0400A3AC */  sw         $3, 0x4($5)
  .L003C8DC0:
    /* 2C8DC0 003C8DC0 0800E003 */  jr         $31
    /* 2C8DC4 003C8DC4 00000000 */   nop
    /* 2C8DC8 003C8DC8 00000000 */  nop
    /* 2C8DCC 003C8DCC 00000000 */  nop
.size func_003c8da0, 0x30
