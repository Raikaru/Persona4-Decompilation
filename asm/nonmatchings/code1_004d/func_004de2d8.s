.section .text
.set noat
.set noreorder
glabel func_004de2d8
    /* 3DE2D8 004DE2D8 7300023C */  lui        $2, %hi(D_0072ACC0)
    /* 3DE2DC 004DE2DC 0800E003 */  jr         $31
    /* 3DE2E0 004DE2E0 C0AC44AC */   sw        $4, %lo(D_0072ACC0)($2)
    /* 3DE2E4 004DE2E4 00000000 */  nop
.size func_004de2d8, 0x10
