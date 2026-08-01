.section .text
.set noat
.set noreorder
glabel func_003bd560
    /* 2BD560 003BD560 6C00828C */  lw         $2, 0x6C($4)
    /* 2BD564 003BD564 06004010 */  beqz       $2, .L003BD580
    /* 2BD568 003BD568 00000000 */   nop
    /* 2BD56C 003BD56C 2C00428C */  lw         $2, 0x2C($2)
    /* 2BD570 003BD570 03004010 */  beqz       $2, .L003BD580
    /* 2BD574 003BD574 00000000 */   nop
    /* 2BD578 003BD578 02000010 */  b          .L003BD584
    /* 2BD57C 003BD57C 08000224 */   addiu     $2, $0, 0x8
  .L003BD580:
    /* 2BD580 003BD580 2D100000 */  daddu      $2, $0, $0
  .L003BD584:
    /* 2BD584 003BD584 0800E003 */  jr         $31
    /* 2BD588 003BD588 00000000 */   nop
    /* 2BD58C 003BD58C 00000000 */  nop
.size func_003bd560, 0x30
