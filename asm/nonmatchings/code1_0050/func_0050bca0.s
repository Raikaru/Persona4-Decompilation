.section .text
.set noat
.set noreorder
glabel func_0050bca0
    /* 40BCA0 0050BCA0 7400033C */  lui        $3, %hi(D_0074586C)
    /* 40BCA4 0050BCA4 0800E003 */  jr         $31
    /* 40BCA8 0050BCA8 6C58628C */   lw        $2, %lo(D_0074586C)($3)
    /* 40BCAC 0050BCAC 00000000 */  nop
.size func_0050bca0, 0x10
