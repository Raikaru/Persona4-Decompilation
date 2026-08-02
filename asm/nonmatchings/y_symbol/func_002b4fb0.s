.section .text
.set noat
.set noreorder
glabel func_002b4fb0
    /* 1B4FB0 002B4FB0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 1B4FB4 002B4FB4 0000BFFF */  sd         $31, 0x0($29)
    /* 1B4FB8 002B4FB8 3800848C */  lw         $4, 0x38($4)
    /* 1B4FBC 002B4FBC 8800023C */  lui        $2, %hi(jtbl_008873EC)
    /* 1B4FC0 002B4FC0 EC73428C */  lw         $2, %lo(jtbl_008873EC)($2)
    /* 1B4FC4 002B4FC4 09F84000 */  jalr       $2
    /* 1B4FC8 002B4FC8 00000000 */   nop
    /* 1B4FCC 002B4FCC 0000BFDF */  ld         $31, 0x0($29)
    /* 1B4FD0 002B4FD0 1000BD27 */  addiu      $29, $29, 0x10
    /* 1B4FD4 002B4FD4 0800E003 */  jr         $31
    /* 1B4FD8 002B4FD8 00000000 */   nop
    /* 1B4FDC 002B4FDC 00000000 */  nop
.size func_002b4fb0, 0x30
