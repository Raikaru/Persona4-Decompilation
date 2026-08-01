.section .text
.set noat
.set noreorder
glabel func_003df870
    /* 2DF870 003DF870 0C00828C */  lw         $2, 0xC($4)
    /* 2DF874 003DF874 18184500 */  mult       $3, $2, $5
    /* 2DF878 003DF878 0000828C */  lw         $2, 0x0($4)
    /* 2DF87C 003DF87C 0800E003 */  jr         $31
    /* 2DF880 003DF880 21104300 */   addu      $2, $2, $3
    /* 2DF884 003DF884 00000000 */  nop
    /* 2DF888 003DF888 00000000 */  nop
    /* 2DF88C 003DF88C 00000000 */  nop
.size func_003df870, 0x20
