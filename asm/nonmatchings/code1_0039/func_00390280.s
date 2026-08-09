.section .text
.set noat
.set noreorder
glabel func_00390280
    /* 290280 00390280 21108500 */  addu       $2, $4, $5
    /* 290284 00390284 000040AC */  sw         $0, 0x0($2)
    /* 290288 00390288 0800E003 */  jr         $31
    /* 29028C 0039028C 2D108000 */   daddu     $2, $4, $0
.size func_00390280, 0x10
