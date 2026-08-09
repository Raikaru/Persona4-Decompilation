.section .text
.set noat
.set noreorder
glabel func_0052bad0
    /* 42BAD0 0052BAD0 80280500 */  sll        $5, $5, 2
    /* 42BAD4 0052BAD4 2128A400 */  addu       $5, $5, $4
    /* 42BAD8 0052BAD8 0800E003 */  jr         $31
    /* 42BADC 0052BADC 3800A28C */   lw        $2, 0x38($5)
.size func_0052bad0, 0x10
