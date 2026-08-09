.section .text
.set noat
.set noreorder
glabel func_00120ee0
    /* 20EE0 00120EE0 3800828C */  lw         $2, 0x38($4)
    /* 20EE4 00120EE4 0000428C */  lw         $2, 0x0($2)
    /* 20EE8 00120EE8 02004238 */  xori       $2, $2, 0x2
    /* 20EEC 00120EEC 0100422C */  sltiu      $2, $2, 0x1
    /* 20EF0 00120EF0 0800E003 */  jr         $31
    /* 20EF4 00120EF4 00000000 */   nop
    /* 20EF8 00120EF8 00000000 */  nop
    /* 20EFC 00120EFC 00000000 */  nop
.size func_00120ee0, 0x20
