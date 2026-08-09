.section .text
.set noat
.set noreorder
glabel func_003d48c0
    /* 2D48C0 003D48C0 21108500 */  addu       $2, $4, $5
    /* 2D48C4 003D48C4 000040AC */  sw         $0, 0x0($2)
    /* 2D48C8 003D48C8 0800E003 */  jr         $31
    /* 2D48CC 003D48CC 2D108000 */   daddu     $2, $4, $0
.size func_003d48c0, 0x10
