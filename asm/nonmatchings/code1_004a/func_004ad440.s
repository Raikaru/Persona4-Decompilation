.section .text
.set noat
.set noreorder
glabel func_004ad440
    /* 3AD440 004AD440 B8008290 */  lbu        $2, 0xB8($4)
    /* 3AD444 004AD444 2B100200 */  sltu       $2, $0, $2
    /* 3AD448 004AD448 0800E003 */  jr         $31
    /* 3AD44C 004AD44C 00000000 */   nop
.size func_004ad440, 0x10
