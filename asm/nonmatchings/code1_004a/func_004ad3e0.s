.section .text
.set noat
.set noreorder
glabel func_004ad3e0
    /* 3AD3E0 004AD3E0 0000A0C4 */  lwc1       $f0, 0x0($5)
    /* 3AD3E4 004AD3E4 000080E4 */  swc1       $f0, 0x0($4)
    /* 3AD3E8 004AD3E8 0400A0C4 */  lwc1       $f0, 0x4($5)
    /* 3AD3EC 004AD3EC 040080E4 */  swc1       $f0, 0x4($4)
    /* 3AD3F0 004AD3F0 0800E003 */  jr         $31
    /* 3AD3F4 004AD3F4 00000000 */   nop
    /* 3AD3F8 004AD3F8 00000000 */  nop
    /* 3AD3FC 004AD3FC 00000000 */  nop
.size func_004ad3e0, 0x20
