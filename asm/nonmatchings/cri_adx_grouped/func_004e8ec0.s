.section .text
.set noat
.set noreorder
glabel func_004e8ec0
    /* 3E8EC0 004E8EC0 7300033C */  lui        $3, %hi(D_00734384)
    /* 3E8EC4 004E8EC4 0800E003 */  jr         $31
    /* 3E8EC8 004E8EC8 8443628C */   lw        $2, %lo(D_00734384)($3)
    /* 3E8ECC 004E8ECC 00000000 */  nop
.size func_004e8ec0, 0x10
