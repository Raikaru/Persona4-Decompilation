.section .text
.set noat
.set noreorder
glabel func_004e8e18
    /* 3E8E18 004E8E18 7300023C */  lui        $2, %hi(D_00734388)
    /* 3E8E1C 004E8E1C 0800E003 */  jr         $31
    /* 3E8E20 004E8E20 88434224 */   addiu     $2, $2, %lo(D_00734388)
    /* 3E8E24 004E8E24 00000000 */  nop
.size func_004e8e18, 0x10
