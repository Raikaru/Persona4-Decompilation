.section .text
.set noat
.set noreorder
glabel func_002e7190
    /* 1E7190 002E7190 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 1E7194 002E7194 0000BFFF */  sd         $31, 0x0($29)
    /* 1E7198 002E7198 8800023C */  lui        $2, %hi(jtbl_008873EC)
    /* 1E719C 002E719C EC73428C */  lw         $2, %lo(jtbl_008873EC)($2)
    /* 1E71A0 002E71A0 09F84000 */  jalr       $2
    /* 1E71A4 002E71A4 00000000 */   nop
    /* 1E71A8 002E71A8 0000BFDF */  ld         $31, 0x0($29)
    /* 1E71AC 002E71AC 1000BD27 */  addiu      $29, $29, 0x10
    /* 1E71B0 002E71B0 0800E003 */  jr         $31
    /* 1E71B4 002E71B4 00000000 */   nop
    /* 1E71B8 002E71B8 00000000 */  nop
    /* 1E71BC 002E71BC 00000000 */  nop
.size func_002e7190, 0x30
