.section .text
.set noat
.set noreorder
glabel func_0011f560
    /* 1F560 0011F560 3800828C */  lw         $2, 0x38($4)
    /* 1F564 0011F564 1400428C */  lw         $2, 0x14($2)
    /* 1F568 0011F568 0E004238 */  xori       $2, $2, 0xE
    /* 1F56C 0011F56C 0100422C */  sltiu      $2, $2, 0x1
    /* 1F570 0011F570 0800E003 */  jr         $31
    /* 1F574 0011F574 00000000 */   nop
    /* 1F578 0011F578 00000000 */  nop
    /* 1F57C 0011F57C 00000000 */  nop
.size func_0011f560, 0x20
