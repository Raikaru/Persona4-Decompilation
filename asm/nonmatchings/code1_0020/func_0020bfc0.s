.section .text
.set noat
.set noreorder
glabel func_0020bfc0
    /* 10BFC0 0020BFC0 000085A4 */  sh         $5, 0x0($4)
    /* 10BFC4 0020BFC4 020080A4 */  sh         $0, 0x2($4)
    /* 10BFC8 0020BFC8 0800E003 */  jr         $31
    /* 10BFCC 0020BFCC 00000000 */   nop
.size func_0020bfc0, 0x10
