.section .text
.set noat
.set noreorder
glabel func_00106300
    /* 6300 00106300 7900033C */  lui        $3, %hi(D_00797B84)
    /* 6304 00106304 847B64A4 */  sh         $4, %lo(D_00797B84)($3)
    /* 6308 00106308 0800E003 */  jr         $31
    /* 630C 0010630C 00000000 */   nop
.size func_00106300, 0x10
