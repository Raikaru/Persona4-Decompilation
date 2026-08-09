.section .text
.set noat
.set noreorder
glabel func_004e4608
    /* 3E4608 004E4608 7300033C */  lui        $3, %hi(D_00731C58)
    /* 3E460C 004E460C 581C6324 */  addiu      $3, $3, %lo(D_00731C58)
    /* 3E4610 004E4610 0800E003 */  jr         $31
    /* 3E4614 004E4614 0000628C */   lw        $2, 0x0($3)
.size func_004e4608, 0x10
