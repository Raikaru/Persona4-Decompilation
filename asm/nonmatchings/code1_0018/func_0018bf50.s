.section .text
.set noat
.set noreorder
glabel func_0018bf50
    /* 8BF50 0018BF50 3800858C */  lw         $5, 0x38($4)
    /* 8BF54 0018BF54 2D100000 */  daddu      $2, $0, $0
    /* 8BF58 0018BF58 0000A48C */  lw         $4, 0x0($5)
    /* 8BF5C 0018BF5C 05000324 */  addiu      $3, $0, 0x5
    /* 8BF60 0018BF60 04008310 */  beq        $4, $3, .L0018BF74
    /* 8BF64 0018BF64 00000000 */   nop
    /* 8BF68 0018BF68 06000324 */  addiu      $3, $0, 0x6
    /* 8BF6C 0018BF6C 02008314 */  bne        $4, $3, .L0018BF78
    /* 8BF70 0018BF70 00000000 */   nop
  .L0018BF74:
    /* 8BF74 0018BF74 01000224 */  addiu      $2, $0, 0x1
  .L0018BF78:
    /* 8BF78 0018BF78 0C00A38C */  lw         $3, 0xC($5)
    /* 8BF7C 0018BF7C 20026494 */  lhu        $4, 0x220($3)
    /* 8BF80 0018BF80 03000324 */  addiu      $3, $0, 0x3
    /* 8BF84 0018BF84 05008314 */  bne        $4, $3, .L0018BF9C
    /* 8BF88 0018BF88 00000000 */   nop
    /* 8BF8C 0018BF8C 2400A38C */  lw         $3, 0x24($5)
    /* 8BF90 0018BF90 02006018 */  blez       $3, .L0018BF9C
    /* 8BF94 0018BF94 00000000 */   nop
    /* 8BF98 0018BF98 01000224 */  addiu      $2, $0, 0x1
  .L0018BF9C:
    /* 8BF9C 0018BF9C 0800E003 */  jr         $31
    /* 8BFA0 0018BFA0 00000000 */   nop
    /* 8BFA4 0018BFA4 00000000 */  nop
    /* 8BFA8 0018BFA8 00000000 */  nop
    /* 8BFAC 0018BFAC 00000000 */  nop
.size func_0018bf50, 0x60
