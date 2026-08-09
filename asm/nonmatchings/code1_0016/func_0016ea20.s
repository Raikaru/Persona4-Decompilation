.section .text
.set noat
.set noreorder
glabel func_0016ea20
    /* 6EA20 0016EA20 3800838C */  lw         $3, 0x38($4)
    /* 6EA24 0016EA24 20006CE4 */  swc1       $f12, 0x20($3)
    /* 6EA28 0016EA28 0800E003 */  jr         $31
    /* 6EA2C 0016EA2C 00000000 */   nop
.size func_0016ea20, 0x10
