.section .text
.set noat
.set noreorder
glabel func_004e8e90
    /* 3E8E90 004E8E90 7300023C */  lui        $2, %hi(D_00734490)
    /* 3E8E94 004E8E94 0800E003 */  jr         $31
    /* 3E8E98 004E8E98 90444224 */   addiu     $2, $2, %lo(D_00734490)
    /* 3E8E9C 004E8E9C 00000000 */  nop
.size func_004e8e90, 0x10
