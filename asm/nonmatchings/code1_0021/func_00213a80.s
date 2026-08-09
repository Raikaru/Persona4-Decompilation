.section .text
.set noat
.set noreorder
glabel func_00213a80
    /* 113A80 00213A80 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 113A84 00213A84 0000BFFF */  sd         $31, 0x0($29)
    /* 113A88 00213A88 6200043C */  lui        $4, %hi(D_00626C80)
    /* 113A8C 00213A8C 806C8424 */  addiu      $4, $4, %lo(D_00626C80)
    /* 113A90 00213A90 E048110C */  jal        func_00452380
    /* 113A94 00213A94 00000000 */   nop
    /* 113A98 00213A98 2B100200 */  sltu       $2, $0, $2
    /* 113A9C 00213A9C 0000BFDF */  ld         $31, 0x0($29)
    /* 113AA0 00213AA0 1000BD27 */  addiu      $29, $29, 0x10
    /* 113AA4 00213AA4 0800E003 */  jr         $31
    /* 113AA8 00213AA8 00000000 */   nop
    /* 113AAC 00213AAC 00000000 */  nop
.size func_00213a80, 0x30
