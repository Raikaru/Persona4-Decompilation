.section .text
.set noat
.set noreorder
glabel func_002b10d0
    /* 1B10D0 002B10D0 3800838C */  lw         $3, 0x38($4)
    /* 1B10D4 002B10D4 5A0165A0 */  sb         $5, 0x15A($3)
    /* 1B10D8 002B10D8 0800E003 */  jr         $31
    /* 1B10DC 002B10DC 00000000 */   nop
.size func_002b10d0, 0x10
