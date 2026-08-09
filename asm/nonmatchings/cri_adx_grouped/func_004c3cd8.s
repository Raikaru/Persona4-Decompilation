.section .text
.set noat
.set noreorder
glabel func_004c3cd8
    /* 3C3CD8 004C3CD8 40280500 */  sll        $5, $5, 1
    /* 3C3CDC 004C3CDC 2128A400 */  addu       $5, $5, $4
    /* 3C3CE0 004C3CE0 0800E003 */  jr         $31
    /* 3C3CE4 004C3CE4 E200A284 */   lh        $2, 0xE2($5)
.size func_004c3cd8, 0x10
