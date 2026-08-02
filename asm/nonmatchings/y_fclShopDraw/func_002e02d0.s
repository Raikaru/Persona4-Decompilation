.section .text
.set noat
.set noreorder
glabel func_002e02d0
    /* 1E02D0 002E02D0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 1E02D4 002E02D4 0000BFFF */  sd         $31, 0x0($29)
    /* 1E02D8 002E02D8 3800848C */  lw         $4, 0x38($4)
    /* 1E02DC 002E02DC 8800023C */  lui        $2, %hi(jtbl_008873EC)
    /* 1E02E0 002E02E0 EC73428C */  lw         $2, %lo(jtbl_008873EC)($2)
    /* 1E02E4 002E02E4 09F84000 */  jalr       $2
    /* 1E02E8 002E02E8 00000000 */   nop
    /* 1E02EC 002E02EC 0000BFDF */  ld         $31, 0x0($29)
    /* 1E02F0 002E02F0 1000BD27 */  addiu      $29, $29, 0x10
    /* 1E02F4 002E02F4 0800E003 */  jr         $31
    /* 1E02F8 002E02F8 00000000 */   nop
    /* 1E02FC 002E02FC 00000000 */  nop
.size func_002e02d0, 0x30
