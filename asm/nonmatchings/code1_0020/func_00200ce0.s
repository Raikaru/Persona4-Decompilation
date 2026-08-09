.section .text
.set noat
.set noreorder
glabel func_00200ce0
    /* 100CE0 00200CE0 ACB3828F */  lw         $2, -0x4C54($28)
    /* 100CE4 00200CE4 2B100200 */  sltu       $2, $0, $2
    /* 100CE8 00200CE8 0800E003 */  jr         $31
    /* 100CEC 00200CEC 00000000 */   nop
.size func_00200ce0, 0x10
