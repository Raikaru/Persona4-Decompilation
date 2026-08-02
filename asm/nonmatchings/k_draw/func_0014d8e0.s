.section .text
.set noat
.set noreorder
glabel func_0014d8e0
    /* 4D8E0 0014D8E0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 4D8E4 0014D8E4 0000BFFF */  sd         $31, 0x0($29)
    /* 4D8E8 0014D8E8 3800848C */  lw         $4, 0x38($4)
    /* 4D8EC 0014D8EC 8800023C */  lui        $2, %hi(jtbl_008873EC)
    /* 4D8F0 0014D8F0 EC73428C */  lw         $2, %lo(jtbl_008873EC)($2)
    /* 4D8F4 0014D8F4 09F84000 */  jalr       $2
    /* 4D8F8 0014D8F8 00000000 */   nop
    /* 4D8FC 0014D8FC 0000BFDF */  ld         $31, 0x0($29)
    /* 4D900 0014D900 1000BD27 */  addiu      $29, $29, 0x10
    /* 4D904 0014D904 0800E003 */  jr         $31
    /* 4D908 0014D908 00000000 */   nop
    /* 4D90C 0014D90C 00000000 */  nop
.size func_0014d8e0, 0x30
