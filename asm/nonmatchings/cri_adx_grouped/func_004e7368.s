.section .text
.set noat
.set noreorder
glabel func_004e7368
    /* 3E7368 004E7368 7300023C */  lui        $2, %hi(D_00733DD0)
    /* 3E736C 004E736C 0800E003 */  jr         $31
    /* 3E7370 004E7370 D03D4224 */   addiu     $2, $2, %lo(D_00733DD0)
    /* 3E7374 004E7374 00000000 */  nop
.size func_004e7368, 0x10
