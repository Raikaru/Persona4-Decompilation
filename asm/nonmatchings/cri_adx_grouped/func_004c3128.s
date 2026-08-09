.section .text
.set noat
.set noreorder
glabel func_004c3128
    /* 3C3128 004C3128 7100023C */  lui        $2, %hi(D_00714C20)
    /* 3C312C 004C312C 7100033C */  lui        $3, %hi(D_00714C24)
    /* 3C3130 004C3130 204C44AC */  sw         $4, %lo(D_00714C20)($2)
    /* 3C3134 004C3134 2D100000 */  daddu      $2, $0, $0
    /* 3C3138 004C3138 0800E003 */  jr         $31
    /* 3C313C 004C313C 244C65AC */   sw        $5, %lo(D_00714C24)($3)
.size func_004c3128, 0x18
