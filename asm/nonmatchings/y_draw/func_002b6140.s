.section .text
.set noat
.set noreorder
glabel func_002b6140
    /* 1B6140 002B6140 3800838C */  lw         $3, 0x38($4)
    /* 1B6144 002B6144 840165A0 */  sb         $5, 0x184($3)
    /* 1B6148 002B6148 0800E003 */  jr         $31
    /* 1B614C 002B614C 00000000 */   nop
.size func_002b6140, 0x10
