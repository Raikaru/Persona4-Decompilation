.section .text
.set noat
.set noreorder
glabel func_0050cce0
    /* 40CCE0 0050CCE0 7400023C */  lui        $2, %hi(D_00745884)
    /* 40CCE4 0050CCE4 0800E003 */  jr         $31
    /* 40CCE8 0050CCE8 845844AC */   sw        $4, %lo(D_00745884)($2)
    /* 40CCEC 0050CCEC 00000000 */  nop
.size func_0050cce0, 0x10
