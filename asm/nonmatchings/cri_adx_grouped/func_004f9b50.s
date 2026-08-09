.section .text
.set noat
.set noreorder
glabel func_004f9b50
    /* 3F9B50 004F9B50 7400023C */  lui        $2, %hi(D_00743C70)
    /* 3F9B54 004F9B54 0800E003 */  jr         $31
    /* 3F9B58 004F9B58 703C4224 */   addiu     $2, $2, %lo(D_00743C70)
    /* 3F9B5C 004F9B5C 00000000 */  nop
.size func_004f9b50, 0x10
