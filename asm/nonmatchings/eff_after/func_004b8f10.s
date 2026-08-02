.section .text
.set noat
.set noreorder
glabel func_004b8f10
    /* 3B8F10 004B8F10 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3B8F14 004B8F14 0000BFFF */  sd         $31, 0x0($29)
    /* 3B8F18 004B8F18 1000848C */  lw         $4, 0x10($4)
    /* 3B8F1C 004B8F1C 8800023C */  lui        $2, %hi(jtbl_008873EC)
    /* 3B8F20 004B8F20 EC73428C */  lw         $2, %lo(jtbl_008873EC)($2)
    /* 3B8F24 004B8F24 09F84000 */  jalr       $2
    /* 3B8F28 004B8F28 00000000 */   nop
    /* 3B8F2C 004B8F2C 0000BFDF */  ld         $31, 0x0($29)
    /* 3B8F30 004B8F30 1000BD27 */  addiu      $29, $29, 0x10
    /* 3B8F34 004B8F34 0800E003 */  jr         $31
    /* 3B8F38 004B8F38 00000000 */   nop
    /* 3B8F3C 004B8F3C 00000000 */  nop
.size func_004b8f10, 0x30
