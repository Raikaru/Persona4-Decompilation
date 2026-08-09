.section .text
.set noat
.set noreorder
glabel func_004d7d78
    /* 3D7D78 004D7D78 7200033C */  lui        $3, %hi(D_00724EB8)
    /* 3D7D7C 004D7D7C B84E6324 */  addiu      $3, $3, %lo(D_00724EB8)
    /* 3D7D80 004D7D80 0000628C */  lw         $2, 0x0($3)
    /* 3D7D84 004D7D84 0800E003 */  jr         $31
    /* 3D7D88 004D7D88 000064AC */   sw        $4, 0x0($3)
    /* 3D7D8C 004D7D8C 00000000 */  nop
.size func_004d7d78, 0x18
