.section .text
.set noat
.set noreorder
glabel func_002b10f0
    /* 1B10F0 002B10F0 3800838C */  lw         $3, 0x38($4)
    /* 1B10F4 002B10F4 440165A0 */  sb         $5, 0x144($3)
    /* 1B10F8 002B10F8 0800E003 */  jr         $31
    /* 1B10FC 002B10FC 00000000 */   nop
.size func_002b10f0, 0x10
