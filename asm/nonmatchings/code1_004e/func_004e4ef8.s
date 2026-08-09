.section .text
.set noat
.set noreorder
glabel func_004e4ef8
    /* 3E4EF8 004E4EF8 7300033C */  lui        $3, %hi(D_00731C84)
    /* 3E4EFC 004E4EFC 841C6324 */  addiu      $3, $3, %lo(D_00731C84)
    /* 3E4F00 004E4F00 0000628C */  lw         $2, 0x0($3)
    /* 3E4F04 004E4F04 FFFF4224 */  addiu      $2, $2, -0x1
    /* 3E4F08 004E4F08 0800E003 */  jr         $31
    /* 3E4F0C 004E4F0C 000062AC */   sw        $2, 0x0($3)
.size func_004e4ef8, 0x18
