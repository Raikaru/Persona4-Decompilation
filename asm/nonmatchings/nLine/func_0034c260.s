.section .text
.set noat
.set noreorder
glabel func_0034c260
    /* 24C260 0034C260 8800033C */  lui        $3, %hi(D_00884684)
    /* 24C264 0034C264 844664AC */  sw         $4, %lo(D_00884684)($3)
    /* 24C268 0034C268 0800E003 */  jr         $31
    /* 24C26C 0034C26C 00000000 */   nop
.size func_0034c260, 0x10
