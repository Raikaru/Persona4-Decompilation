.section .text
.set noat
.set noreorder
glabel func_004e3da8
    /* 3E3DA8 004E3DA8 7300033C */  lui        $3, %hi(D_00731C7C)
    /* 3E3DAC 004E3DAC 0800E003 */  jr         $31
    /* 3E3DB0 004E3DB0 7C1C6290 */   lbu       $2, %lo(D_00731C7C)($3)
    /* 3E3DB4 004E3DB4 00000000 */  nop
.size func_004e3da8, 0x10
