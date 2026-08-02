.section .text
.set noat
.set noreorder
glabel func_00108ed0
    /* 8ED0 00108ED0 7900033C */  lui        $3, %hi(D_0079740C)
    /* 8ED4 00108ED4 0C7464A4 */  sh         $4, %lo(D_0079740C)($3)
    /* 8ED8 00108ED8 0800E003 */  jr         $31
    /* 8EDC 00108EDC 00000000 */   nop
.size func_00108ed0, 0x10
