.section .text
.set noat
.set noreorder
glabel func_0052c880
    /* 42C880 0052C880 7400033C */  lui        $3, %hi(D_0074613C)
    /* 42C884 0052C884 0800E003 */  jr         $31
    /* 42C888 0052C888 3C61628C */   lw        $2, %lo(D_0074613C)($3)
    /* 42C88C 0052C88C 00000000 */  nop
.size func_0052c880, 0x10
