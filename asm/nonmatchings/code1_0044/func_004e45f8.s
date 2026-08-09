.section .text
.set noat
.set noreorder
glabel func_004e45f8
    /* 3E45F8 004E45F8 7300033C */  lui        $3, %hi(D_00731C5C)
    /* 3E45FC 004E45FC 5C1C6324 */  addiu      $3, $3, %lo(D_00731C5C)
    /* 3E4600 004E4600 0800E003 */  jr         $31
    /* 3E4604 004E4604 0000628C */   lw        $2, 0x0($3)
.size func_004e45f8, 0x10
