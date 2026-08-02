.section .text
.set noat
.set noreorder
glabel func_001102c0
    /* 102C0 001102C0 7A00033C */  lui        $3, %hi(D_0079B6A4)
    /* 102C4 001102C4 A4B664A4 */  sh         $4, %lo(D_0079B6A4)($3)
    /* 102C8 001102C8 0800E003 */  jr         $31
    /* 102CC 001102CC 00000000 */   nop
.size func_001102c0, 0x10
