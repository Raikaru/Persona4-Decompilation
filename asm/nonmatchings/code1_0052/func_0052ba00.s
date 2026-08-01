.section .text
.set noat
.set noreorder
glabel func_0052ba00
    /* 42BA00 0052BA00 7400023C */  lui        $2, %hi(D_00745C6C)
    /* 42BA04 0052BA04 0800E003 */  jr         $31
    /* 42BA08 0052BA08 6C5C44AC */   sw        $4, %lo(D_00745C6C)($2)
    /* 42BA0C 0052BA0C 00000000 */  nop
.size func_0052ba00, 0x10
