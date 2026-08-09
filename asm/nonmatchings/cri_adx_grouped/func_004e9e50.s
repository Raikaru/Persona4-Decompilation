.section .text
.set noat
.set noreorder
glabel func_004e9e50
    /* 3E9E50 004E9E50 7400033C */  lui        $3, %hi(D_00738CF0)
    /* 3E9E54 004E9E54 7400023C */  lui        $2, %hi(D_00738D00)
    /* 3E9E58 004E9E58 F08C6324 */  addiu      $3, $3, %lo(D_00738CF0)
    /* 3E9E5C 004E9E5C 008D4224 */  addiu      $2, $2, %lo(D_00738D00)
    /* 3E9E60 004E9E60 0800E003 */  jr         $31
    /* 3E9E64 004E9E64 0000648C */   lw        $4, 0x0($3)
.size func_004e9e50, 0x18
