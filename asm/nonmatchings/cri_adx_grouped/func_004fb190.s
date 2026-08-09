.section .text
.set noat
.set noreorder
glabel func_004fb190
    /* 3FB190 004FB190 7400033C */  lui        $3, %hi(D_00743C78)
    /* 3FB194 004FB194 0800E003 */  jr         $31
    /* 3FB198 004FB198 783C628C */   lw        $2, %lo(D_00743C78)($3)
    /* 3FB19C 004FB19C 00000000 */  nop
.size func_004fb190, 0x10
