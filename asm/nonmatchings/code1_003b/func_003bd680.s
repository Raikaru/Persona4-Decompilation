.section .text
.set noat
.set noreorder
glabel func_003bd680
    /* 2BD680 003BD680 7C00828C */  lw         $2, 0x7C($4)
    /* 2BD684 003BD684 06004010 */  beqz       $2, .L003BD6A0
    /* 2BD688 003BD688 00000000 */   nop
    /* 2BD68C 003BD68C 2C00428C */  lw         $2, 0x2C($2)
    /* 2BD690 003BD690 03004010 */  beqz       $2, .L003BD6A0
    /* 2BD694 003BD694 00000000 */   nop
    /* 2BD698 003BD698 02000010 */  b          .L003BD6A4
    /* 2BD69C 003BD69C 08000224 */   addiu     $2, $0, 0x8
  .L003BD6A0:
    /* 2BD6A0 003BD6A0 2D100000 */  daddu      $2, $0, $0
  .L003BD6A4:
    /* 2BD6A4 003BD6A4 0800E003 */  jr         $31
    /* 2BD6A8 003BD6A8 00000000 */   nop
    /* 2BD6AC 003BD6AC 00000000 */  nop
.size func_003bd680, 0x30
