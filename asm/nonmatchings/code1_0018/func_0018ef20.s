.section .text
.set noat
.set noreorder
glabel func_0018ef20
    /* 8EF20 0018EF20 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 8EF24 0018EF24 0000BFFF */  sd         $31, 0x0($29)
    /* 8EF28 0018EF28 3800848C */  lw         $4, 0x38($4)
    /* 8EF2C 0018EF2C 8800023C */  lui        $2, %hi(jtbl_008873EC)
    /* 8EF30 0018EF30 EC73428C */  lw         $2, %lo(jtbl_008873EC)($2)
    /* 8EF34 0018EF34 09F84000 */  jalr       $2
    /* 8EF38 0018EF38 00000000 */   nop
    /* 8EF3C 0018EF3C 0000BFDF */  ld         $31, 0x0($29)
    /* 8EF40 0018EF40 1000BD27 */  addiu      $29, $29, 0x10
    /* 8EF44 0018EF44 0800E003 */  jr         $31
    /* 8EF48 0018EF48 00000000 */   nop
    /* 8EF4C 0018EF4C 00000000 */  nop
.size func_0018ef20, 0x30
