.section .text
.set noat
.set noreorder
glabel func_004e43e8
    /* 3E43E8 004E43E8 7300033C */  lui        $3, %hi(D_00731C02)
    /* 3E43EC 004E43EC 09000224 */  addiu      $2, $0, 0x9
    /* 3E43F0 004E43F0 0800E003 */  jr         $31
    /* 3E43F4 004E43F4 021C62A0 */   sb        $2, %lo(D_00731C02)($3)
.size func_004e43e8, 0x10
