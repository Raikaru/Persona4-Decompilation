.section .text
.set noat
.set noreorder
glabel func_00515b90
    /* 415B90 00515B90 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 415B94 00515B94 0000BFFF */  sd         $31, 0x0($29)
    /* 415B98 00515B98 0000838C */  lw         $3, 0x0($4)
    /* 415B9C 00515B9C 1000628C */  lw         $2, 0x10($3)
    /* 415BA0 00515BA0 09F84000 */  jalr       $2
    /* 415BA4 00515BA4 00000000 */   nop
    /* 415BA8 00515BA8 9300033C */  lui        $3, %hi(D_00932CB4)
    /* 415BAC 00515BAC B42C648C */  lw         $4, %lo(D_00932CB4)($3)
    /* 415BB0 00515BB0 0000BFDF */  ld         $31, 0x0($29)
    /* 415BB4 00515BB4 26104400 */  xor        $2, $2, $4
    /* 415BB8 00515BB8 0100422C */  sltiu      $2, $2, 0x1
    /* 415BBC 00515BBC 0800E003 */  jr         $31
    /* 415BC0 00515BC0 1000BD27 */   addiu     $29, $29, 0x10
    /* 415BC4 00515BC4 00000000 */  nop
.size func_00515b90, 0x38
