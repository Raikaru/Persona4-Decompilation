.section .text
.set noat
.set noreorder
glabel func_0043eb20
    /* 33EB20 0043EB20 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 33EB24 0043EB24 71000F3C */  lui        $15, %hi(D_00710070)
    /* 33EB28 0043EB28 0000BFFF */  sd         $31, 0x0($29)
    /* 33EB2C 0043EB2C 7000E48D */  lw         $4, %lo(D_00710070)($15)
    /* 33EB30 0043EB30 0000BFDF */  ld         $31, 0x0($29)
    /* 33EB34 0043EB34 BAFA1008 */  j          func_0043eae8
    /* 33EB38 0043EB38 1000BD27 */   addiu     $29, $29, 0x10
    /* 33EB3C 0043EB3C 00000000 */  nop
.size func_0043eb20, 0x20
