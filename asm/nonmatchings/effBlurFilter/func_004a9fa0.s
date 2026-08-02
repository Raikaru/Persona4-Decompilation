.section .text
.set noat
.set noreorder
glabel func_004a9fa0
    /* 3A9FA0 004A9FA0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3A9FA4 004A9FA4 0000BFFF */  sd         $31, 0x0($29)
    /* 3A9FA8 004A9FA8 8800023C */  lui        $2, %hi(jtbl_008873EC)
    /* 3A9FAC 004A9FAC EC73428C */  lw         $2, %lo(jtbl_008873EC)($2)
    /* 3A9FB0 004A9FB0 09F84000 */  jalr       $2
    /* 3A9FB4 004A9FB4 00000000 */   nop
    /* 3A9FB8 004A9FB8 0000BFDF */  ld         $31, 0x0($29)
    /* 3A9FBC 004A9FBC 1000BD27 */  addiu      $29, $29, 0x10
    /* 3A9FC0 004A9FC0 0800E003 */  jr         $31
    /* 3A9FC4 004A9FC4 00000000 */   nop
    /* 3A9FC8 004A9FC8 00000000 */  nop
    /* 3A9FCC 004A9FCC 00000000 */  nop
.size func_004a9fa0, 0x30
