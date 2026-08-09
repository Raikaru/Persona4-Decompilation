.section .text
.set noat
.set noreorder
glabel func_0052d7e8
    /* 42D7E8 0052D7E8 7400033C */  lui        $3, %hi(D_007463B0)
    /* 42D7EC 0052D7EC B06362DC */  ld         $2, %lo(D_007463B0)($3)
    /* 42D7F0 0052D7F0 0800E003 */  jr         $31
    /* 42D7F4 0052D7F4 0200422C */   sltiu     $2, $2, 0x2
.size func_0052d7e8, 0x10
