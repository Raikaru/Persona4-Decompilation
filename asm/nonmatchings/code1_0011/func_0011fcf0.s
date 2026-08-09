.section .text
.set noat
.set noreorder
glabel func_0011fcf0
    /* 1FCF0 0011FCF0 3800828C */  lw         $2, 0x38($4)
    /* 1FCF4 0011FCF4 0800428C */  lw         $2, 0x8($2)
    /* 1FCF8 0011FCF8 08004238 */  xori       $2, $2, 0x8
    /* 1FCFC 0011FCFC 0100422C */  sltiu      $2, $2, 0x1
    /* 1FD00 0011FD00 0800E003 */  jr         $31
    /* 1FD04 0011FD04 00000000 */   nop
    /* 1FD08 0011FD08 00000000 */  nop
    /* 1FD0C 0011FD0C 00000000 */  nop
.size func_0011fcf0, 0x20
