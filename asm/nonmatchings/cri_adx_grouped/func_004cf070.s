.section .text
.set noat
.set noreorder
glabel func_004cf070
    /* 3CF070 004CF070 7200023C */  lui        $2, %hi(D_00721D6C)
    /* 3CF074 004CF074 7200033C */  lui        $3, %hi(D_00721D70)
    /* 3CF078 004CF078 6C1D44AC */  sw         $4, %lo(D_00721D6C)($2)
    /* 3CF07C 004CF07C 2D100000 */  daddu      $2, $0, $0
    /* 3CF080 004CF080 0800E003 */  jr         $31
    /* 3CF084 004CF084 701D65AC */   sw        $5, %lo(D_00721D70)($3)
.size func_004cf070, 0x18
