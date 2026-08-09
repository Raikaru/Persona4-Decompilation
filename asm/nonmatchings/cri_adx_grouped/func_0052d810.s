.section .text
.set noat
.set noreorder
glabel func_0052d810
    /* 42D810 0052D810 7400033C */  lui        $3, %hi(D_007463B0)
    /* 42D814 0052D814 0800E003 */  jr         $31
    /* 42D818 0052D818 B06362DC */   ld        $2, %lo(D_007463B0)($3)
    /* 42D81C 0052D81C 00000000 */  nop
.size func_0052d810, 0x10
