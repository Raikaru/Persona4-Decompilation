.section .text
.set noat
.set noreorder
glabel func_0038d280
    /* 28D280 0038D280 3800838C */  lw         $3, 0x38($4)
    /* 28D284 0038D284 B00160AC */  sw         $0, 0x1B0($3)
    /* 28D288 0038D288 A00160A4 */  sh         $0, 0x1A0($3)
    /* 28D28C 0038D28C 0800E003 */  jr         $31
    /* 28D290 0038D290 00000000 */   nop
    /* 28D294 0038D294 00000000 */  nop
    /* 28D298 0038D298 00000000 */  nop
    /* 28D29C 0038D29C 00000000 */  nop
.size func_0038d280, 0x20
