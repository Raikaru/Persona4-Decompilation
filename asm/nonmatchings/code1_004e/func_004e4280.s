.section .text
.set noat
.set noreorder
glabel func_004e4280
    /* 3E4280 004E4280 7300033C */  lui        $3, %hi(D_00731C01)
    /* 3E4284 004E4284 0800E003 */  jr         $31
    /* 3E4288 004E4288 011C6280 */   lb        $2, %lo(D_00731C01)($3)
    /* 3E428C 004E428C 00000000 */  nop
.size func_004e4280, 0x10
