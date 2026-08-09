.section .text
.set noat
.set noreorder
glabel func_0033dc60
    /* 23DC60 0033DC60 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 23DC64 0033DC64 0000BFFF */  sd         $31, 0x0($29)
    /* 23DC68 0033DC68 3800848C */  lw         $4, 0x38($4)
    /* 23DC6C 0033DC6C 8800023C */  lui        $2, %hi(jtbl_008873EC)
    /* 23DC70 0033DC70 EC73428C */  lw         $2, %lo(jtbl_008873EC)($2)
    /* 23DC74 0033DC74 09F84000 */  jalr       $2
    /* 23DC78 0033DC78 00000000 */   nop
    /* 23DC7C 0033DC7C 0000BFDF */  ld         $31, 0x0($29)
    /* 23DC80 0033DC80 1000BD27 */  addiu      $29, $29, 0x10
    /* 23DC84 0033DC84 0800E003 */  jr         $31
    /* 23DC88 0033DC88 00000000 */   nop
    /* 23DC8C 0033DC8C 00000000 */  nop
.size func_0033dc60, 0x30
