.section .text
.set noat
.set noreorder
glabel func_0011e3e0
    /* 1E3E0 0011E3E0 3800828C */  lw         $2, 0x38($4)
    /* 1E3E4 0011E3E4 0000428C */  lw         $2, 0x0($2)
    /* 1E3E8 0011E3E8 03004238 */  xori       $2, $2, 0x3
    /* 1E3EC 0011E3EC 0100422C */  sltiu      $2, $2, 0x1
    /* 1E3F0 0011E3F0 0800E003 */  jr         $31
    /* 1E3F4 0011E3F4 00000000 */   nop
    /* 1E3F8 0011E3F8 00000000 */  nop
    /* 1E3FC 0011E3FC 00000000 */  nop
.size func_0011e3e0, 0x20
