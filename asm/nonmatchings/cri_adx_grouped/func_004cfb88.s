.section .text
.set noat
.set noreorder
glabel func_004cfb88
    /* 3CFB88 004CFB88 2120A400 */  addu       $4, $5, $4
    /* 3CFB8C 004CFB8C 0800E003 */  jr         $31
    /* 3CFB90 004CFB90 580086A0 */   sb        $6, 0x58($4)
    /* 3CFB94 004CFB94 00000000 */  nop
.size func_004cfb88, 0x10
