.section .text
.set noat
.set noreorder
glabel func_00110460
    /* 10460 00110460 7A00023C */  lui        $2, %hi(D_0079BEF4)
    /* 10464 00110464 F4BE428C */  lw         $2, %lo(D_0079BEF4)($2)
    /* 10468 00110468 0800E003 */  jr         $31
    /* 1046C 0011046C 00000000 */   nop
.size func_00110460, 0x10
