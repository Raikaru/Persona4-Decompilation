.section .text
.set noat
.set noreorder
glabel func_0041dc00
    /* 31DC00 0041DC00 7500053C */  lui        $5, %hi(D_00753AF0)
    /* 31DC04 0041DC04 32831008 */  j          func_00420cc8
    /* 31DC08 0041DC08 F03AA524 */   addiu     $5, $5, %lo(D_00753AF0)
    /* 31DC0C 0041DC0C 00000000 */  nop
.size func_0041dc00, 0x10
