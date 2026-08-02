.section .text
.set noat
.set noreorder
glabel func_002b3c60
    /* 1B3C60 002B3C60 3800838C */  lw         $3, 0x38($4)
    /* 1B3C64 002B3C64 210065A0 */  sb         $5, 0x21($3)
    /* 1B3C68 002B3C68 0800E003 */  jr         $31
    /* 1B3C6C 002B3C6C 00000000 */   nop
.size func_002b3c60, 0x10
