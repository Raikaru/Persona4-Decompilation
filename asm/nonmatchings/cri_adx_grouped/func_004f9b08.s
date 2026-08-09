.section .text
.set noat
.set noreorder
glabel func_004f9b08
    /* 3F9B08 004F9B08 7400023C */  lui        $2, %hi(D_00743C6C)
    /* 3F9B0C 004F9B0C 0800E003 */  jr         $31
    /* 3F9B10 004F9B10 6C3C44AC */   sw        $4, %lo(D_00743C6C)($2)
    /* 3F9B14 004F9B14 00000000 */  nop
.size func_004f9b08, 0x10
