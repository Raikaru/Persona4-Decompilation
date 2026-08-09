.section .text
.set noat
.set noreorder
glabel func_004d2e80
    /* 3D2E80 004D2E80 0000A0AC */  sw         $0, 0x0($5)
    /* 3D2E84 004D2E84 0800E003 */  jr         $31
    /* 3D2E88 004D2E88 01000224 */   addiu     $2, $0, 0x1
    /* 3D2E8C 004D2E8C 00000000 */  nop
.size func_004d2e80, 0x10
