.section .text
.set noat
.set noreorder
glabel func_004b1ab0
    /* 3B1AB0 004B1AB0 0800838C */  lw         $3, 0x8($4)
    /* 3B1AB4 004B1AB4 01006324 */  addiu      $3, $3, 0x1
    /* 3B1AB8 004B1AB8 080083AC */  sw         $3, 0x8($4)
    /* 3B1ABC 004B1ABC 0800E003 */  jr         $31
    /* 3B1AC0 004B1AC0 00000000 */   nop
    /* 3B1AC4 004B1AC4 00000000 */  nop
    /* 3B1AC8 004B1AC8 00000000 */  nop
    /* 3B1ACC 004B1ACC 00000000 */  nop
.size func_004b1ab0, 0x20
