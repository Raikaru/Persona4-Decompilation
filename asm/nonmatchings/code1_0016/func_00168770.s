.section .text
.set noat
.set noreorder
glabel func_00168770
    /* 68770 00168770 3800828C */  lw         $2, 0x38($4)
    /* 68774 00168774 240040C4 */  lwc1       $f0, 0x24($2)
    /* 68778 00168778 0800E003 */  jr         $31
    /* 6877C 0016877C 00000000 */   nop
.size func_00168770, 0x10
