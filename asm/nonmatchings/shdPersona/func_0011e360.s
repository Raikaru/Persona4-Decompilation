.section .text
.set noat
.set noreorder
glabel func_0011e360
    /* 1E360 0011E360 3800838C */  lw         $3, 0x38($4)
    /* 1E364 0011E364 140065AC */  sw         $5, 0x14($3)
    /* 1E368 0011E368 0800E003 */  jr         $31
    /* 1E36C 0011E36C 00000000 */   nop
.size func_0011e360, 0x10
