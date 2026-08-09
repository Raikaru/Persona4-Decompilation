.section .text
.set noat
.set noreorder
glabel func_004ed3a8
    /* 3ED3A8 004ED3A8 7400023C */  lui        $2, %hi(D_0073DAB8)
    /* 3ED3AC 004ED3AC 0800E003 */  jr         $31
    /* 3ED3B0 004ED3B0 B8DA40AC */   sw        $0, %lo(D_0073DAB8)($2)
    /* 3ED3B4 004ED3B4 00000000 */  nop
.size func_004ed3a8, 0x10
