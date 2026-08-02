.section .text
.set noat
.set noreorder
glabel func_002b10e0
    /* 1B10E0 002B10E0 3800838C */  lw         $3, 0x38($4)
    /* 1B10E4 002B10E4 430165A0 */  sb         $5, 0x143($3)
    /* 1B10E8 002B10E8 0800E003 */  jr         $31
    /* 1B10EC 002B10EC 00000000 */   nop
.size func_002b10e0, 0x10
