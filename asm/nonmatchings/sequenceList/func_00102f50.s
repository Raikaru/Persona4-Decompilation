.section .text
.set noat
.set noreorder
glabel func_00102f50
    /* 2F50 00102F50 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 2F54 00102F54 0000BFFF */  sd         $31, 0x0($29)
    /* 2F58 00102F58 5E00043C */  lui        $4, %hi(D_005DCBB0)
    /* 2F5C 00102F5C B0CB8424 */  addiu      $4, $4, %lo(D_005DCBB0)
    /* 2F60 00102F60 E048110C */  jal        func_00452380
    /* 2F64 00102F64 00000000 */   nop
    /* 2F68 00102F68 2B100200 */  sltu       $2, $0, $2
    /* 2F6C 00102F6C 0000BFDF */  ld         $31, 0x0($29)
    /* 2F70 00102F70 1000BD27 */  addiu      $29, $29, 0x10
    /* 2F74 00102F74 0800E003 */  jr         $31
    /* 2F78 00102F78 00000000 */   nop
    /* 2F7C 00102F7C 00000000 */  nop
.size func_00102f50, 0x30
