.section .text
.set noat
.set noreorder
glabel func_001102d0
    /* 102D0 001102D0 7A00023C */  lui        $2, %hi(D_0079B6A4)
    /* 102D4 001102D4 A4B64294 */  lhu        $2, %lo(D_0079B6A4)($2)
    /* 102D8 001102D8 0800E003 */  jr         $31
    /* 102DC 001102DC 00000000 */   nop
.size func_001102d0, 0x10
