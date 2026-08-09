.section .text
.set noat
.set noreorder
glabel func_004da448
    /* 3DA448 004DA448 A5018380 */  lb         $3, 0x1A5($4)
    /* 3DA44C 004DA44C 02006010 */  beqz       $3, .L004DA458
    /* 3DA450 004DA450 2D100000 */   daddu     $2, $0, $0
    /* 3DA454 004DA454 E801828C */  lw         $2, 0x1E8($4)
  .L004DA458:
    /* 3DA458 004DA458 0800E003 */  jr         $31
    /* 3DA45C 004DA45C 00000000 */   nop
.size func_004da448, 0x18
