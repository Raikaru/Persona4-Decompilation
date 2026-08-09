.section .text
.set noat
.set noreorder
glabel func_003c4bc0
    /* 2C4BC0 003C4BC0 0400838C */  lw         $3, 0x4($4)
    /* 2C4BC4 003C4BC4 0C006018 */  blez       $3, .L003C4BF8
    /* 2C4BC8 003C4BC8 FFFF6224 */   addiu     $2, $3, -0x1
    /* 2C4BCC 003C4BCC 0000838C */  lw         $3, 0x0($4)
    /* 2C4BD0 003C4BD0 80200200 */  sll        $4, $2, 2
    /* 2C4BD4 003C4BD4 21206400 */  addu       $4, $3, $4
  .L003C4BD8:
    /* 2C4BD8 003C4BD8 0000838C */  lw         $3, 0x0($4)
    /* 2C4BDC 003C4BDC 06006510 */  beq        $3, $5, .L003C4BF8
    /* 2C4BE0 003C4BE0 00000000 */   nop
    /* 2C4BE4 003C4BE4 2D184000 */  daddu      $3, $2, $0
    /* 2C4BE8 003C4BE8 FCFF8424 */  addiu      $4, $4, -0x4
    /* 2C4BEC 003C4BEC FAFF601C */  bgtz       $3, .L003C4BD8
    /* 2C4BF0 003C4BF0 FFFF4224 */   addiu     $2, $2, -0x1
    /* 2C4BF4 003C4BF4 00000000 */  nop
  .L003C4BF8:
    /* 2C4BF8 003C4BF8 0800E003 */  jr         $31
    /* 2C4BFC 003C4BFC 00000000 */   nop
.size func_003c4bc0, 0x40
