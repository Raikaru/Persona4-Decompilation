.section .text
.set noat
.set noreorder
glabel func_004cf350
    /* 3CF350 004CF350 7600023C */  lui        $2, %hi(D_00758AA8)
    /* 3CF354 004CF354 0800E003 */  jr         $31
    /* 3CF358 004CF358 A88A4224 */   addiu     $2, $2, %lo(D_00758AA8)
    /* 3CF35C 004CF35C 00000000 */  nop
.size func_004cf350, 0x10
