.section .text
.set noat
.set noreorder
glabel func_00106310
    /* 6310 00106310 7900033C */  lui        $3, %hi(D_00797B86)
    /* 6314 00106314 867B64A0 */  sb         $4, %lo(D_00797B86)($3)
    /* 6318 00106318 0800E003 */  jr         $31
    /* 631C 0010631C 00000000 */   nop
.size func_00106310, 0x10
