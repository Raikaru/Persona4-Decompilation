.section .text
.set noat
.set noreorder
glabel func_004e4638
    /* 3E4638 004E4638 7300033C */  lui        $3, %hi(D_00731C6C)
    /* 3E463C 004E463C 6C1C6324 */  addiu      $3, $3, %lo(D_00731C6C)
    /* 3E4640 004E4640 0800E003 */  jr         $31
    /* 3E4644 004E4644 0000628C */   lw        $2, 0x0($3)
.size func_004e4638, 0x10
