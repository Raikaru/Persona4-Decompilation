.section .text
.set noat
.set noreorder
glabel func_001033b0
    /* 33B0 001033B0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 33B4 001033B4 0000BFFF */  sd         $31, 0x0($29)
    /* 33B8 001033B8 5E00043C */  lui        $4, %hi(D_005DCC00)
    /* 33BC 001033BC 00CC8424 */  addiu      $4, $4, %lo(D_005DCC00)
    /* 33C0 001033C0 E048110C */  jal        func_00452380
    /* 33C4 001033C4 00000000 */   nop
    /* 33C8 001033C8 2B100200 */  sltu       $2, $0, $2
    /* 33CC 001033CC 0000BFDF */  ld         $31, 0x0($29)
    /* 33D0 001033D0 1000BD27 */  addiu      $29, $29, 0x10
    /* 33D4 001033D4 0800E003 */  jr         $31
    /* 33D8 001033D8 00000000 */   nop
    /* 33DC 001033DC 00000000 */  nop
.size func_001033b0, 0x30
