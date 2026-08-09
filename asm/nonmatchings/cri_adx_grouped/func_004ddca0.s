.section .text
.set noat
.set noreorder
glabel func_004ddca0
    /* 3DDCA0 004DDCA0 80280500 */  sll        $5, $5, 2
    /* 3DDCA4 004DDCA4 2128A400 */  addu       $5, $5, $4
    /* 3DDCA8 004DDCA8 0800E003 */  jr         $31
    /* 3DDCAC 004DDCAC 1400A6AC */   sw        $6, 0x14($5)
.size func_004ddca0, 0x10
