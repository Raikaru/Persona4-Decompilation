.section .text
.set noat
.set noreorder
glabel func_0017cc90
    /* 7CC90 0017CC90 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 7CC94 0017CC94 0000BFFF */  sd         $31, 0x0($29)
    /* 7CC98 0017CC98 3800848C */  lw         $4, 0x38($4)
    /* 7CC9C 0017CC9C 8800023C */  lui        $2, %hi(jtbl_008873EC)
    /* 7CCA0 0017CCA0 EC73428C */  lw         $2, %lo(jtbl_008873EC)($2)
    /* 7CCA4 0017CCA4 09F84000 */  jalr       $2
    /* 7CCA8 0017CCA8 00000000 */   nop
    /* 7CCAC 0017CCAC 0000BFDF */  ld         $31, 0x0($29)
    /* 7CCB0 0017CCB0 1000BD27 */  addiu      $29, $29, 0x10
    /* 7CCB4 0017CCB4 0800E003 */  jr         $31
    /* 7CCB8 0017CCB8 00000000 */   nop
    /* 7CCBC 0017CCBC 00000000 */  nop
.size func_0017cc90, 0x30
