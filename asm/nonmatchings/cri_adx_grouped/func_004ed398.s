.section .text
.set noat
.set noreorder
glabel func_004ed398
    /* 3ED398 004ED398 7400023C */  lui        $2, %hi(D_0073DAB8)
    /* 3ED39C 004ED39C 0800E003 */  jr         $31
    /* 3ED3A0 004ED3A0 B8DA40AC */   sw        $0, %lo(D_0073DAB8)($2)
    /* 3ED3A4 004ED3A4 00000000 */  nop
.size func_004ed398, 0x10
