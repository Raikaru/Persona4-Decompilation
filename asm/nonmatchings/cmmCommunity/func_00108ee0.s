.section .text
.set noat
.set noreorder
glabel func_00108ee0
    /* 8EE0 00108EE0 7900023C */  lui        $2, %hi(D_0079740C)
    /* 8EE4 00108EE4 0C744294 */  lhu        $2, %lo(D_0079740C)($2)
    /* 8EE8 00108EE8 0800E003 */  jr         $31
    /* 8EEC 00108EEC 00000000 */   nop
.size func_00108ee0, 0x10
