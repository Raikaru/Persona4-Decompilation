.section .text
.set noat
.set noreorder
glabel func_004eea88
    /* 3EEA88 004EEA88 40280500 */  sll        $5, $5, 1
    /* 3EEA8C 004EEA8C 2128A600 */  addu       $5, $5, $6
    /* 3EEA90 004EEA90 80280500 */  sll        $5, $5, 2
    /* 3EEA94 004EEA94 2128A400 */  addu       $5, $5, $4
    /* 3EEA98 004EEA98 0800E003 */  jr         $31
    /* 3EEA9C 004EEA9C 2800A7AC */   sw        $7, 0x28($5)
.size func_004eea88, 0x18
