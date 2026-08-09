.section .text
.set noat
.set noreorder
glabel func_00120f00
    /* 20F00 00120F00 01000524 */  addiu      $5, $0, 0x1
    /* 20F04 00120F04 3800838C */  lw         $3, 0x38($4)
    /* 20F08 00120F08 140065AC */  sw         $5, 0x14($3)
    /* 20F0C 00120F0C 0800E003 */  jr         $31
    /* 20F10 00120F10 00000000 */   nop
    /* 20F14 00120F14 00000000 */  nop
    /* 20F18 00120F18 00000000 */  nop
    /* 20F1C 00120F1C 00000000 */  nop
.size func_00120f00, 0x20
