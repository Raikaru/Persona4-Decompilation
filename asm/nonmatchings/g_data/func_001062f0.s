.section .text
.set noat
.set noreorder
glabel func_001062f0
    /* 62F0 001062F0 7900033C */  lui        $3, %hi(D_00797B7C)
    /* 62F4 001062F4 7C7B64A0 */  sb         $4, %lo(D_00797B7C)($3)
    /* 62F8 001062F8 0800E003 */  jr         $31
    /* 62FC 001062FC 00000000 */   nop
.size func_001062f0, 0x10
