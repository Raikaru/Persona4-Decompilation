.section .text
.set noat
.set noreorder
glabel func_0052c870
    /* 42C870 0052C870 7400023C */  lui        $2, %hi(D_0074613C)
    /* 42C874 0052C874 0800E003 */  jr         $31
    /* 42C878 0052C878 3C6144AC */   sw        $4, %lo(D_0074613C)($2)
    /* 42C87C 0052C87C 00000000 */  nop
.size func_0052c870, 0x10
