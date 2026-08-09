.section .text
.set noat
.set noreorder
glabel func_004cee80
    /* 3CEE80 004CEE80 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3CEE84 004CEE84 2D100000 */  daddu      $2, $0, $0
    /* 3CEE88 004CEE88 05008010 */  beqz       $4, .L004CEEA0
    /* 3CEE8C 004CEE8C 0000BFFF */   sd        $31, 0x0($29)
    /* 3CEE90 004CEE90 0400848C */  lw         $4, 0x4($4)
    /* 3CEE94 004CEE94 0000BFDF */  ld         $31, 0x0($29)
    /* 3CEE98 004CEE98 280F1308 */  j          func_004c3ca0
    /* 3CEE9C 004CEE9C 1000BD27 */   addiu     $29, $29, 0x10
  .L004CEEA0:
    /* 3CEEA0 004CEEA0 0000BFDF */  ld         $31, 0x0($29)
    /* 3CEEA4 004CEEA4 0800E003 */  jr         $31
    /* 3CEEA8 004CEEA8 1000BD27 */   addiu     $29, $29, 0x10
    /* 3CEEAC 004CEEAC 00000000 */  nop
.size func_004cee80, 0x30
