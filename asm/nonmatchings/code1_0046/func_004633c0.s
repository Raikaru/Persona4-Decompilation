.section .text
.set noat
.set noreorder
glabel func_004633c0
    /* 3633C0 004633C0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3633C4 004633C4 0000BFFF */  sd         $31, 0x0($29)
    /* 3633C8 004633C8 2D30A000 */  daddu      $6, $5, $0
    /* 3633CC 004633CC 4600053C */  lui        $5, %hi(func_004632f0)
    /* 3633D0 004633D0 F032A524 */  addiu      $5, $5, %lo(func_004632f0)
    /* 3633D4 004633D4 CCFF0E0C */  jal        func_003bff30
    /* 3633D8 004633D8 00000000 */   nop
    /* 3633DC 004633DC 0000BFDF */  ld         $31, 0x0($29)
    /* 3633E0 004633E0 1000BD27 */  addiu      $29, $29, 0x10
    /* 3633E4 004633E4 0800E003 */  jr         $31
    /* 3633E8 004633E8 00000000 */   nop
    /* 3633EC 004633EC 00000000 */  nop
.size func_004633c0, 0x30
