.section .text
.set noat
.set noreorder
glabel func_002b5e20
    /* 1B5E20 002B5E20 3800838C */  lw         $3, 0x38($4)
    /* 1B5E24 002B5E24 30016CE4 */  swc1       $f12, 0x130($3)
    /* 1B5E28 002B5E28 0800E003 */  jr         $31
    /* 1B5E2C 002B5E2C 00000000 */   nop
.size func_002b5e20, 0x10
