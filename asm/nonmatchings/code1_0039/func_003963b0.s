.section .text
.set noat
.set noreorder
glabel func_003963b0
    /* 2963B0 003963B0 0400828C */  lw         $2, 0x4($4)
    /* 2963B4 003963B4 24000324 */  addiu      $3, $0, 0x24
    /* 2963B8 003963B8 0800E003 */  jr         $31
    /* 2963BC 003963BC 18106200 */   mult      $2, $3, $2
.size func_003963b0, 0x10
