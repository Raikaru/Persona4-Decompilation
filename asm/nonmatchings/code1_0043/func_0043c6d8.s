.section .text
.set noat
.set noreorder
glabel func_0043c6d8
    /* 33C6D8 0043C6D8 FFFFA524 */  addiu      $5, $5, -0x1
    /* 33C6DC 0043C6DC FFFF0F24 */  addiu      $15, $0, -0x1
    /* 33C6E0 0043C6E0 0800AF10 */  beq        $5, $15, .L0043C704
    /* 33C6E4 0043C6E4 00000000 */   nop
  .L0043C6E8:
    /* 33C6E8 0043C6E8 000080A0 */  sb         $0, 0x0($4)
    /* 33C6EC 0043C6EC FFFFA524 */  addiu      $5, $5, -0x1
    /* 33C6F0 0043C6F0 00000000 */  nop
    /* 33C6F4 0043C6F4 00000000 */  nop
    /* 33C6F8 0043C6F8 00000000 */  nop
    /* 33C6FC 0043C6FC FAFFAF14 */  bne        $5, $15, .L0043C6E8
    /* 33C700 0043C700 01008424 */   addiu     $4, $4, 0x1
  .L0043C704:
    /* 33C704 0043C704 0800E003 */  jr         $31
    /* 33C708 0043C708 00000000 */   nop
    /* 33C70C 0043C70C 00000000 */  nop
.size func_0043c6d8, 0x38
