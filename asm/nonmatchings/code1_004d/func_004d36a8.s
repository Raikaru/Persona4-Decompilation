.section .text
.set noat
.set noreorder
glabel func_004d36a8
    /* 3D36A8 004D36A8 7200023C */  lui        $2, %hi(D_00724E60)
    /* 3D36AC 004D36AC 0800E003 */  jr         $31
    /* 3D36B0 004D36B0 604E44AC */   sw        $4, %lo(D_00724E60)($2)
    /* 3D36B4 004D36B4 00000000 */  nop
.size func_004d36a8, 0x10
