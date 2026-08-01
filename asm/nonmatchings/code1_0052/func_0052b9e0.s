.section .text
.set noat
.set noreorder
glabel func_0052b9e0
    /* 42B9E0 0052B9E0 7400023C */  lui        $2, %hi(D_00745C84)
    /* 42B9E4 0052B9E4 0800E003 */  jr         $31
    /* 42B9E8 0052B9E8 845C44AC */   sw        $4, %lo(D_00745C84)($2)
    /* 42B9EC 0052B9EC 00000000 */  nop
.size func_0052b9e0, 0x10
