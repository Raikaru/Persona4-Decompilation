.section .text
.set noat
.set noreorder
glabel func_0036e8d0
    /* 26E8D0 0036E8D0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 26E8D4 0036E8D4 0000BFFF */  sd         $31, 0x0($29)
    /* 26E8D8 0036E8D8 6500043C */  lui        $4, %hi(D_0064E780)
    /* 26E8DC 0036E8DC 80E78424 */  addiu      $4, $4, %lo(D_0064E780)
    /* 26E8E0 0036E8E0 E048110C */  jal        func_00452380
    /* 26E8E4 0036E8E4 00000000 */   nop
    /* 26E8E8 0036E8E8 2B100200 */  sltu       $2, $0, $2
    /* 26E8EC 0036E8EC 0000BFDF */  ld         $31, 0x0($29)
    /* 26E8F0 0036E8F0 1000BD27 */  addiu      $29, $29, 0x10
    /* 26E8F4 0036E8F4 0800E003 */  jr         $31
    /* 26E8F8 0036E8F8 00000000 */   nop
    /* 26E8FC 0036E8FC 00000000 */  nop
.size func_0036e8d0, 0x30
