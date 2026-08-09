.section .text
.set noat
.set noreorder
glabel func_005159c0
    /* 4159C0 005159C0 D0FFBD27 */  addiu      $29, $29, -0x30
    /* 4159C4 005159C4 2000BFFF */  sd         $31, 0x20($29)
    /* 4159C8 005159C8 2A53140C */  jal        func_00514ca8
    /* 4159CC 005159CC 2D30A003 */   daddu     $6, $29, $0
    /* 4159D0 005159D0 0400A38F */  lw         $3, 0x4($29)
    /* 4159D4 005159D4 0C00A28F */  lw         $2, 0xC($29)
    /* 4159D8 005159D8 2000BFDF */  ld         $31, 0x20($29)
    /* 4159DC 005159DC 21106200 */  addu       $2, $3, $2
    /* 4159E0 005159E0 0800E003 */  jr         $31
    /* 4159E4 005159E4 3000BD27 */   addiu     $29, $29, 0x30
.size func_005159c0, 0x28
