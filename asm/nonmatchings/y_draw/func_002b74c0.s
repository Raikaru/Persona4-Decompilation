.section .text
.set noat
.set noreorder
glabel func_002b74c0
    /* 1B74C0 002B74C0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 1B74C4 002B74C4 0000BFFF */  sd         $31, 0x0($29)
    /* 1B74C8 002B74C8 3800848C */  lw         $4, 0x38($4)
    /* 1B74CC 002B74CC 8800023C */  lui        $2, %hi(jtbl_008873EC)
    /* 1B74D0 002B74D0 EC73428C */  lw         $2, %lo(jtbl_008873EC)($2)
    /* 1B74D4 002B74D4 09F84000 */  jalr       $2
    /* 1B74D8 002B74D8 00000000 */   nop
    /* 1B74DC 002B74DC 0000BFDF */  ld         $31, 0x0($29)
    /* 1B74E0 002B74E0 1000BD27 */  addiu      $29, $29, 0x10
    /* 1B74E4 002B74E4 0800E003 */  jr         $31
    /* 1B74E8 002B74E8 00000000 */   nop
    /* 1B74EC 002B74EC 00000000 */  nop
.size func_002b74c0, 0x30
