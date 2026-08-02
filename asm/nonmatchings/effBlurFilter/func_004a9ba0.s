.section .text
.set noat
.set noreorder
glabel func_004a9ba0
    /* 3A9BA0 004A9BA0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3A9BA4 004A9BA4 0000BFFF */  sd         $31, 0x0($29)
    /* 3A9BA8 004A9BA8 8800023C */  lui        $2, %hi(jtbl_008873EC)
    /* 3A9BAC 004A9BAC EC73428C */  lw         $2, %lo(jtbl_008873EC)($2)
    /* 3A9BB0 004A9BB0 09F84000 */  jalr       $2
    /* 3A9BB4 004A9BB4 00000000 */   nop
    /* 3A9BB8 004A9BB8 0000BFDF */  ld         $31, 0x0($29)
    /* 3A9BBC 004A9BBC 1000BD27 */  addiu      $29, $29, 0x10
    /* 3A9BC0 004A9BC0 0800E003 */  jr         $31
    /* 3A9BC4 004A9BC4 00000000 */   nop
    /* 3A9BC8 004A9BC8 00000000 */  nop
    /* 3A9BCC 004A9BCC 00000000 */  nop
.size func_004a9ba0, 0x30
