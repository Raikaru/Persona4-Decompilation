.section .text
.set noat
.set noreorder
glabel func_00489ee0
    /* 389EE0 00489EE0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 389EE4 00489EE4 0000BFFF */  sd         $31, 0x0($29)
    /* 389EE8 00489EE8 4C00848C */  lw         $4, 0x4C($4)
    /* 389EEC 00489EEC 744B120C */  jal        func_00492dd0
    /* 389EF0 00489EF0 00000000 */   nop
    /* 389EF4 00489EF4 0000BFDF */  ld         $31, 0x0($29)
    /* 389EF8 00489EF8 1000BD27 */  addiu      $29, $29, 0x10
    /* 389EFC 00489EFC 0800E003 */  jr         $31
    /* 389F00 00489F00 00000000 */   nop
    /* 389F04 00489F04 00000000 */  nop
    /* 389F08 00489F08 00000000 */  nop
    /* 389F0C 00489F0C 00000000 */  nop
.size func_00489ee0, 0x30
