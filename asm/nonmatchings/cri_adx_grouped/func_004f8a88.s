.section .text
.set noat
.set noreorder
glabel func_004f8a88
    /* 3F8A88 004F8A88 7400023C */  lui        $2, %hi(D_00743C34)
    /* 3F8A8C 004F8A8C 7400033C */  lui        $3, %hi(D_00743C38)
    /* 3F8A90 004F8A90 343C44AC */  sw         $4, %lo(D_00743C34)($2)
    /* 3F8A94 004F8A94 2D100000 */  daddu      $2, $0, $0
    /* 3F8A98 004F8A98 0800E003 */  jr         $31
    /* 3F8A9C 004F8A9C 383C65AC */   sw        $5, %lo(D_00743C38)($3)
.size func_004f8a88, 0x18
