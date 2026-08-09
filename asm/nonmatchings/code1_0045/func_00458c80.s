.section .text
.set noat
.set noreorder
glabel func_00458c80
    /* 358C80 00458C80 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 358C84 00458C84 0000BFFF */  sd         $31, 0x0($29)
    /* 358C88 00458C88 2D30A000 */  daddu      $6, $5, $0
    /* 358C8C 00458C8C 4600053C */  lui        $5, %hi(func_00458c40)
    /* 358C90 00458C90 408CA524 */  addiu      $5, $5, %lo(func_00458c40)
    /* 358C94 00458C94 CCFF0E0C */  jal        func_003bff30
    /* 358C98 00458C98 00000000 */   nop
    /* 358C9C 00458C9C 0000BFDF */  ld         $31, 0x0($29)
    /* 358CA0 00458CA0 1000BD27 */  addiu      $29, $29, 0x10
    /* 358CA4 00458CA4 0800E003 */  jr         $31
    /* 358CA8 00458CA8 00000000 */   nop
    /* 358CAC 00458CAC 00000000 */  nop
.size func_00458c80, 0x30
