.section .text
.set noat
.set noreorder
glabel func_0050ccf0
    /* 40CCF0 0050CCF0 7400033C */  lui        $3, %hi(D_00745884)
    /* 40CCF4 0050CCF4 0800E003 */  jr         $31
    /* 40CCF8 0050CCF8 8458628C */   lw        $2, %lo(D_00745884)($3)
    /* 40CCFC 0050CCFC 00000000 */  nop
.size func_0050ccf0, 0x10
