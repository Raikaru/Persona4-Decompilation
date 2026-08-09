.section .text
.set noat
.set noreorder
glabel func_004a6b90
    /* 3A6B90 004A6B90 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3A6B94 004A6B94 0000BFFF */  sd         $31, 0x0($29)
    /* 3A6B98 004A6B98 2C00828C */  lw         $2, 0x2C($4)
    /* 3A6B9C 004A6B9C 01004224 */  addiu      $2, $2, 0x1
    /* 3A6BA0 004A6BA0 2C0082AC */  sw         $2, 0x2C($4)
    /* 3A6BA4 004A6BA4 F097120C */  jal        func_004a5fc0
    /* 3A6BA8 004A6BA8 00000000 */   nop
    /* 3A6BAC 004A6BAC 0000BFDF */  ld         $31, 0x0($29)
    /* 3A6BB0 004A6BB0 1000BD27 */  addiu      $29, $29, 0x10
    /* 3A6BB4 004A6BB4 0800E003 */  jr         $31
    /* 3A6BB8 004A6BB8 00000000 */   nop
    /* 3A6BBC 004A6BBC 00000000 */  nop
.size func_004a6b90, 0x30
