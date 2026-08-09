.section .text
.set noat
.set noreorder
glabel func_0018bea0
    /* 8BEA0 0018BEA0 3800838C */  lw         $3, 0x38($4)
    /* 8BEA4 0018BEA4 2D100000 */  daddu      $2, $0, $0
    /* 8BEA8 0018BEA8 0000648C */  lw         $4, 0x0($3)
    /* 8BEAC 0018BEAC 05000324 */  addiu      $3, $0, 0x5
    /* 8BEB0 0018BEB0 04008310 */  beq        $4, $3, .L0018BEC4
    /* 8BEB4 0018BEB4 00000000 */   nop
    /* 8BEB8 0018BEB8 06000324 */  addiu      $3, $0, 0x6
    /* 8BEBC 0018BEBC 02008314 */  bne        $4, $3, .L0018BEC8
    /* 8BEC0 0018BEC0 00000000 */   nop
  .L0018BEC4:
    /* 8BEC4 0018BEC4 01000224 */  addiu      $2, $0, 0x1
  .L0018BEC8:
    /* 8BEC8 0018BEC8 0800E003 */  jr         $31
    /* 8BECC 0018BECC 00000000 */   nop
.size func_0018bea0, 0x30
