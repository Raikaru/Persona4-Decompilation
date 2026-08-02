.section .text
.set noat
.set noreorder
glabel func_0033e0f0
    /* 23E0F0 0033E0F0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 23E0F4 0033E0F4 0000BFFF */  sd         $31, 0x0($29)
    /* 23E0F8 0033E0F8 3800848C */  lw         $4, 0x38($4)
    /* 23E0FC 0033E0FC 8800023C */  lui        $2, %hi(jtbl_008873EC)
    /* 23E100 0033E100 EC73428C */  lw         $2, %lo(jtbl_008873EC)($2)
    /* 23E104 0033E104 09F84000 */  jalr       $2
    /* 23E108 0033E108 00000000 */   nop
    /* 23E10C 0033E10C 0000BFDF */  ld         $31, 0x0($29)
    /* 23E110 0033E110 1000BD27 */  addiu      $29, $29, 0x10
    /* 23E114 0033E114 0800E003 */  jr         $31
    /* 23E118 0033E118 00000000 */   nop
    /* 23E11C 0033E11C 00000000 */  nop
.size func_0033e0f0, 0x30
