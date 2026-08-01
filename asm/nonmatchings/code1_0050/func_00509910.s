.section .text
.set noat
.set noreorder
glabel func_00509910
    /* 409910 00509910 7400023C */  lui        $2, %hi(D_0074428C)
    /* 409914 00509914 0800E003 */  jr         $31
    /* 409918 00509918 8C4244AC */   sw        $4, %lo(D_0074428C)($2)
    /* 40991C 0050991C 00000000 */  nop
.size func_00509910, 0x10
