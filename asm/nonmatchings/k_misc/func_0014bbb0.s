.section .text
.set noat
.set noreorder
glabel func_0014bbb0
    /* 4BBB0 0014BBB0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 4BBB4 0014BBB4 0000BFFF */  sd         $31, 0x0($29)
    /* 4BBB8 0014BBB8 3800848C */  lw         $4, 0x38($4)
    /* 4BBBC 0014BBBC 8800023C */  lui        $2, %hi(jtbl_008873EC)
    /* 4BBC0 0014BBC0 EC73428C */  lw         $2, %lo(jtbl_008873EC)($2)
    /* 4BBC4 0014BBC4 09F84000 */  jalr       $2
    /* 4BBC8 0014BBC8 00000000 */   nop
    /* 4BBCC 0014BBCC 0000BFDF */  ld         $31, 0x0($29)
    /* 4BBD0 0014BBD0 1000BD27 */  addiu      $29, $29, 0x10
    /* 4BBD4 0014BBD4 0800E003 */  jr         $31
    /* 4BBD8 0014BBD8 00000000 */   nop
    /* 4BBDC 0014BBDC 00000000 */  nop
.size func_0014bbb0, 0x30
