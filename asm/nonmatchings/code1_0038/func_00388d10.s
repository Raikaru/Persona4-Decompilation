.section .text
.set noat
.set noreorder
glabel func_00388d10
    /* 288D10 00388D10 3800838C */  lw         $3, 0x38($4)
    /* 288D14 00388D14 4C0060A4 */  sh         $0, 0x4C($3)
    /* 288D18 00388D18 0800E003 */  jr         $31
    /* 288D1C 00388D1C 00000000 */   nop
.size func_00388d10, 0x10
