.section .text
.set noat
.set noreorder
glabel func_00102bb0
    /* 2BB0 00102BB0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 2BB4 00102BB4 0000BFFF */  sd         $31, 0x0($29)
    /* 2BB8 00102BB8 5E00043C */  lui        $4, %hi(D_005DCB58)
    /* 2BBC 00102BBC 58CB8424 */  addiu      $4, $4, %lo(D_005DCB58)
    /* 2BC0 00102BC0 E048110C */  jal        func_00452380
    /* 2BC4 00102BC4 00000000 */   nop
    /* 2BC8 00102BC8 2B100200 */  sltu       $2, $0, $2
    /* 2BCC 00102BCC 0000BFDF */  ld         $31, 0x0($29)
    /* 2BD0 00102BD0 1000BD27 */  addiu      $29, $29, 0x10
    /* 2BD4 00102BD4 0800E003 */  jr         $31
    /* 2BD8 00102BD8 00000000 */   nop
    /* 2BDC 00102BDC 00000000 */  nop
.size func_00102bb0, 0x30
