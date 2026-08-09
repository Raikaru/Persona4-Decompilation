.section .text
.set noat
.set noreorder
glabel func_004cfb70
    /* 3CFB70 004CFB70 2128A400 */  addu       $5, $5, $4
    /* 3CFB74 004CFB74 02008010 */  beqz       $4, .L004CFB80
    /* 3CFB78 004CFB78 2D100000 */   daddu     $2, $0, $0
    /* 3CFB7C 004CFB7C 5800A280 */  lb         $2, 0x58($5)
  .L004CFB80:
    /* 3CFB80 004CFB80 0800E003 */  jr         $31
    /* 3CFB84 004CFB84 00000000 */   nop
.size func_004cfb70, 0x18
