.section .text
.set noat
.set noreorder
glabel func_004d3678
    /* 3D3678 004D3678 7200023C */  lui        $2, %hi(D_00724E58)
    /* 3D367C 004D367C 0800E003 */  jr         $31
    /* 3D3680 004D3680 584E44AC */   sw        $4, %lo(D_00724E58)($2)
    /* 3D3684 004D3684 00000000 */  nop
.size func_004d3678, 0x10
