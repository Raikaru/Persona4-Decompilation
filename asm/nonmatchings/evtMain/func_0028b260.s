.section .text
.set noat
.set noreorder
glabel func_0028b260
    /* 18B260 0028B260 E8B4828F */  lw         $2, -0x4B18($28)
    /* 18B264 0028B264 2B100200 */  sltu       $2, $0, $2
    /* 18B268 0028B268 0800E003 */  jr         $31
    /* 18B26C 0028B26C 00000000 */   nop
.size func_0028b260, 0x10
