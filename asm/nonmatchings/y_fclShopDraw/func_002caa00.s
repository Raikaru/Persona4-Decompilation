.section .text
.set noat
.set noreorder
glabel func_002caa00
    /* 1CAA00 002CAA00 3800838C */  lw         $3, 0x38($4)
    /* 1CAA04 002CAA04 000065A0 */  sb         $5, 0x0($3)
    /* 1CAA08 002CAA08 0800E003 */  jr         $31
    /* 1CAA0C 002CAA0C 00000000 */   nop
.size func_002caa00, 0x10
