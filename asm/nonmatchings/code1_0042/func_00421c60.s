.section .text
.set noat
.set noreorder
glabel func_00421c60
    /* 321C60 00421C60 7100023C */  lui        $2, %hi(D_0070C5D0)
    /* 321C64 00421C64 0800E003 */  jr         $31
    /* 321C68 00421C68 D0C540AC */   sw        $0, %lo(D_0070C5D0)($2)
    /* 321C6C 00421C6C 00000000 */  nop
.size func_00421c60, 0x10
