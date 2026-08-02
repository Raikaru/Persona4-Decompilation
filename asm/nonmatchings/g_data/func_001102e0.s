.section .text
.set noat
.set noreorder
glabel func_001102e0
    /* 102E0 001102E0 7A00023C */  lui        $2, %hi(D_0079B6A8)
    /* 102E4 001102E4 A8B64224 */  addiu      $2, $2, %lo(D_0079B6A8)
    /* 102E8 001102E8 0800E003 */  jr         $31
    /* 102EC 001102EC 00000000 */   nop
.size func_001102e0, 0x10
