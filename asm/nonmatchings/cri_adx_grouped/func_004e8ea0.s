.section .text
.set noat
.set noreorder
glabel func_004e8ea0
    /* 3E8EA0 004E8EA0 7300033C */  lui        $3, %hi(D_00734380)
    /* 3E8EA4 004E8EA4 0800E003 */  jr         $31
    /* 3E8EA8 004E8EA8 8043628C */   lw        $2, %lo(D_00734380)($3)
    /* 3E8EAC 004E8EAC 00000000 */  nop
.size func_004e8ea0, 0x10
