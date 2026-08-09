.section .text
.set noat
.set noreorder
glabel func_004f9ae8
    /* 3F9AE8 004F9AE8 7400023C */  lui        $2, %hi(D_00743C68)
    /* 3F9AEC 004F9AEC 0800E003 */  jr         $31
    /* 3F9AF0 004F9AF0 683C44AC */   sw        $4, %lo(D_00743C68)($2)
    /* 3F9AF4 004F9AF4 00000000 */  nop
.size func_004f9ae8, 0x10
