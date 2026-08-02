.section .text
.set noat
.set noreorder
glabel func_0046d280
    /* 36D280 0046D280 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 36D284 0046D284 0000BFFF */  sd         $31, 0x0($29)
    /* 36D288 0046D288 8800023C */  lui        $2, %hi(jtbl_008873EC)
    /* 36D28C 0046D28C EC73428C */  lw         $2, %lo(jtbl_008873EC)($2)
    /* 36D290 0046D290 09F84000 */  jalr       $2
    /* 36D294 0046D294 00000000 */   nop
    /* 36D298 0046D298 0000BFDF */  ld         $31, 0x0($29)
    /* 36D29C 0046D29C 1000BD27 */  addiu      $29, $29, 0x10
    /* 36D2A0 0046D2A0 0800E003 */  jr         $31
    /* 36D2A4 0046D2A4 00000000 */   nop
    /* 36D2A8 0046D2A8 00000000 */  nop
    /* 36D2AC 0046D2AC 00000000 */  nop
.size func_0046d280, 0x30
