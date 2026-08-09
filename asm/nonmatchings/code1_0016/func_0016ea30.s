.section .text
.set noat
.set noreorder
glabel func_0016ea30
    /* 6EA30 0016EA30 3800838C */  lw         $3, 0x38($4)
    /* 6EA34 0016EA34 24006CE4 */  swc1       $f12, 0x24($3)
    /* 6EA38 0016EA38 0800E003 */  jr         $31
    /* 6EA3C 0016EA3C 00000000 */   nop
.size func_0016ea30, 0x10
