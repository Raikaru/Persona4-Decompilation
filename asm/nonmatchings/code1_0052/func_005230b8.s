.section .text
.set noat
.set noreorder
glabel func_005230b8
    /* 4230B8 005230B8 7400023C */  lui        $2, %hi(D_00745ABC)
    /* 4230BC 005230BC 0800E003 */  jr         $31
    /* 4230C0 005230C0 BC5A44AC */   sw        $4, %lo(D_00745ABC)($2)
    /* 4230C4 005230C4 00000000 */  nop
.size func_005230b8, 0x10
