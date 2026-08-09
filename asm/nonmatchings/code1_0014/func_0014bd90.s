.section .text
.set noat
.set noreorder
glabel func_0014bd90
    /* 4BD90 0014BD90 3800828C */  lw         $2, 0x38($4)
    /* 4BD94 0014BD94 0000428C */  lw         $2, 0x0($2)
    /* 4BD98 0014BD98 01004238 */  xori       $2, $2, 0x1
    /* 4BD9C 0014BD9C 0100422C */  sltiu      $2, $2, 0x1
    /* 4BDA0 0014BDA0 0800E003 */  jr         $31
    /* 4BDA4 0014BDA4 00000000 */   nop
    /* 4BDA8 0014BDA8 00000000 */  nop
    /* 4BDAC 0014BDAC 00000000 */  nop
.size func_0014bd90, 0x20
