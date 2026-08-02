.section .text
.set noat
.set noreorder
glabel func_002b4240
    /* 1B4240 002B4240 3800838C */  lw         $3, 0x38($4)
    /* 1B4244 002B4244 000065A0 */  sb         $5, 0x0($3)
    /* 1B4248 002B4248 0800E003 */  jr         $31
    /* 1B424C 002B424C 00000000 */   nop
.size func_002b4240, 0x10
