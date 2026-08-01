.section .text
.set noat
.set noreorder
glabel func_00513a40
    /* 413A40 00513A40 7400033C */  lui        $3, %hi(D_00745AC0)
    /* 413A44 00513A44 2D100000 */  daddu      $2, $0, $0
    /* 413A48 00513A48 0800E003 */  jr         $31
    /* 413A4C 00513A4C C05A64AC */   sw        $4, %lo(D_00745AC0)($3)
.size func_00513a40, 0x10
