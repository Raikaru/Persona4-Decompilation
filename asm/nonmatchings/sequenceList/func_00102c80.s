.section .text
.set noat
.set noreorder
glabel func_00102c80
    /* 2C80 00102C80 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 2C84 00102C84 0000BFFF */  sd         $31, 0x0($29)
    /* 2C88 00102C88 5E00043C */  lui        $4, %hi(D_005DCB80)
    /* 2C8C 00102C8C 80CB8424 */  addiu      $4, $4, %lo(D_005DCB80)
    /* 2C90 00102C90 E048110C */  jal        func_00452380
    /* 2C94 00102C94 00000000 */   nop
    /* 2C98 00102C98 2B100200 */  sltu       $2, $0, $2
    /* 2C9C 00102C9C 0000BFDF */  ld         $31, 0x0($29)
    /* 2CA0 00102CA0 1000BD27 */  addiu      $29, $29, 0x10
    /* 2CA4 00102CA4 0800E003 */  jr         $31
    /* 2CA8 00102CA8 00000000 */   nop
    /* 2CAC 00102CAC 00000000 */  nop
.size func_00102c80, 0x30
