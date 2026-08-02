.section .text
.set noat
.set noreorder
glabel func_00153bd0
    /* 53BD0 00153BD0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 53BD4 00153BD4 0000BFFF */  sd         $31, 0x0($29)
    /* 53BD8 00153BD8 3800828C */  lw         $2, 0x38($4)
    /* 53BDC 00153BDC 0C0045AC */  sw         $5, 0xC($2)
    /* 53BE0 00153BE0 2D20A000 */  daddu      $4, $5, $0
    /* 53BE4 00153BE4 4085050C */  jal        func_00161500
    /* 53BE8 00153BE8 00000000 */   nop
    /* 53BEC 00153BEC 0000BFDF */  ld         $31, 0x0($29)
    /* 53BF0 00153BF0 1000BD27 */  addiu      $29, $29, 0x10
    /* 53BF4 00153BF4 0800E003 */  jr         $31
    /* 53BF8 00153BF8 00000000 */   nop
    /* 53BFC 00153BFC 00000000 */  nop
.size func_00153bd0, 0x30
