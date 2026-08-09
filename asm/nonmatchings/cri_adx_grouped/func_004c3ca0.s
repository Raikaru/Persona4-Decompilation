.section .text
.set noat
.set noreorder
glabel func_004c3ca0
    /* 3C3CA0 004C3CA0 02008010 */  beqz       $4, .L004C3CAC
    /* 3C3CA4 004C3CA4 2D100000 */   daddu     $2, $0, $0
    /* 3C3CA8 004C3CA8 2C00828C */  lw         $2, 0x2C($4)
  .L004C3CAC:
    /* 3C3CAC 004C3CAC 0800E003 */  jr         $31
    /* 3C3CB0 004C3CB0 00000000 */   nop
    /* 3C3CB4 004C3CB4 00000000 */  nop
.size func_004c3ca0, 0x18
