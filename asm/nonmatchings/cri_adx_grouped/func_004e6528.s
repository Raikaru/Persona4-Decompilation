.section .text
.set noat
.set noreorder
glabel func_004e6528
    /* 3E6528 004E6528 1400828C */  lw         $2, 0x14($4)
    /* 3E652C 004E652C F8120200 */  dsll       $2, $2, 11
    /* 3E6530 004E6530 0800E003 */  jr         $31
    /* 3E6534 004E6534 3F100200 */   dsra32    $2, $2, 0
.size func_004e6528, 0x10
