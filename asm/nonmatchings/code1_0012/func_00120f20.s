.section .text
.set noat
.set noreorder
glabel func_00120f20
    /* 20F20 00120F20 01000524 */  addiu      $5, $0, 0x1
    /* 20F24 00120F24 3800838C */  lw         $3, 0x38($4)
    /* 20F28 00120F28 100065AC */  sw         $5, 0x10($3)
    /* 20F2C 00120F2C 0800E003 */  jr         $31
    /* 20F30 00120F30 00000000 */   nop
    /* 20F34 00120F34 00000000 */  nop
    /* 20F38 00120F38 00000000 */  nop
    /* 20F3C 00120F3C 00000000 */  nop
.size func_00120f20, 0x20
