.section .text
.set noat
.set noreorder
glabel func_003b85b0
    /* 2B85B0 003B85B0 6C00848C */  lw         $4, 0x6C($4)
    /* 2B85B4 003B85B4 16010224 */  addiu      $2, $0, 0x116
    /* 2B85B8 003B85B8 2C00838C */  lw         $3, 0x2C($4)
    /* 2B85BC 003B85BC 03006214 */  bne        $3, $2, .L003B85CC
    /* 2B85C0 003B85C0 00000000 */   nop
    /* 2B85C4 003B85C4 02000010 */  b          .L003B85D0
    /* 2B85C8 003B85C8 3000828C */   lw        $2, 0x30($4)
  .L003B85CC:
    /* 2B85CC 003B85CC 2D100000 */  daddu      $2, $0, $0
  .L003B85D0:
    /* 2B85D0 003B85D0 0800E003 */  jr         $31
    /* 2B85D4 003B85D4 00000000 */   nop
    /* 2B85D8 003B85D8 00000000 */  nop
    /* 2B85DC 003B85DC 00000000 */  nop
.size func_003b85b0, 0x30
