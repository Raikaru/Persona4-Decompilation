.section .text
.set noat
.set noreorder
glabel func_001030c0
    /* 30C0 001030C0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 30C4 001030C4 0000BFFF */  sd         $31, 0x0($29)
    /* 30C8 001030C8 5E00043C */  lui        $4, %hi(D_005DCBC0)
    /* 30CC 001030CC C0CB8424 */  addiu      $4, $4, %lo(D_005DCBC0)
    /* 30D0 001030D0 E048110C */  jal        func_00452380
    /* 30D4 001030D4 00000000 */   nop
    /* 30D8 001030D8 2B100200 */  sltu       $2, $0, $2
    /* 30DC 001030DC 0000BFDF */  ld         $31, 0x0($29)
    /* 30E0 001030E0 1000BD27 */  addiu      $29, $29, 0x10
    /* 30E4 001030E4 0800E003 */  jr         $31
    /* 30E8 001030E8 00000000 */   nop
    /* 30EC 001030EC 00000000 */  nop
.size func_001030c0, 0x30
