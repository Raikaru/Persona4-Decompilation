.section .text
.set noat
.set noreorder
glabel func_005207f8
    /* 4207F8 005207F8 7400023C */  lui        $2, %hi(D_00745AF8)
    /* 4207FC 005207FC 0800E003 */  jr         $31
    /* 420800 00520800 F85A44AC */   sw        $4, %lo(D_00745AF8)($2)
    /* 420804 00520804 00000000 */  nop
.size func_005207f8, 0x10
