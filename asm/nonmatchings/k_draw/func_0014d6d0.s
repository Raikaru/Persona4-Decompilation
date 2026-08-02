.section .text
.set noat
.set noreorder
glabel func_0014d6d0
    /* 4D6D0 0014D6D0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 4D6D4 0014D6D4 0000BFFF */  sd         $31, 0x0($29)
    /* 4D6D8 0014D6D8 3800848C */  lw         $4, 0x38($4)
    /* 4D6DC 0014D6DC 8800023C */  lui        $2, %hi(jtbl_008873EC)
    /* 4D6E0 0014D6E0 EC73428C */  lw         $2, %lo(jtbl_008873EC)($2)
    /* 4D6E4 0014D6E4 09F84000 */  jalr       $2
    /* 4D6E8 0014D6E8 00000000 */   nop
    /* 4D6EC 0014D6EC 0000BFDF */  ld         $31, 0x0($29)
    /* 4D6F0 0014D6F0 1000BD27 */  addiu      $29, $29, 0x10
    /* 4D6F4 0014D6F4 0800E003 */  jr         $31
    /* 4D6F8 0014D6F8 00000000 */   nop
    /* 4D6FC 0014D6FC 00000000 */  nop
.size func_0014d6d0, 0x30
