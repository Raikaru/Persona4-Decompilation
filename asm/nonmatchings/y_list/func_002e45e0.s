.section .text
.set noat
.set noreorder
glabel func_002e45e0
    /* 1E45E0 002E45E0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 1E45E4 002E45E4 0000BFFF */  sd         $31, 0x0($29)
    /* 1E45E8 002E45E8 3800848C */  lw         $4, 0x38($4)
    /* 1E45EC 002E45EC 8800023C */  lui        $2, %hi(jtbl_008873EC)
    /* 1E45F0 002E45F0 EC73428C */  lw         $2, %lo(jtbl_008873EC)($2)
    /* 1E45F4 002E45F4 09F84000 */  jalr       $2
    /* 1E45F8 002E45F8 00000000 */   nop
    /* 1E45FC 002E45FC 0000BFDF */  ld         $31, 0x0($29)
    /* 1E4600 002E4600 1000BD27 */  addiu      $29, $29, 0x10
    /* 1E4604 002E4604 0800E003 */  jr         $31
    /* 1E4608 002E4608 00000000 */   nop
    /* 1E460C 002E460C 00000000 */  nop
.size func_002e45e0, 0x30
