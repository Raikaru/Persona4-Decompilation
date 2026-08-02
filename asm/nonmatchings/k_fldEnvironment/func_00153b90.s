.section .text
.set noat
.set noreorder
glabel func_00153b90
    /* 53B90 00153B90 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 53B94 00153B94 0000BFFF */  sd         $31, 0x0($29)
    /* 53B98 00153B98 2D30A000 */  daddu      $6, $5, $0
    /* 53B9C 00153B9C 3800828C */  lw         $2, 0x38($4)
    /* 53BA0 00153BA0 100046AC */  sw         $6, 0x10($2)
    /* 53BA4 00153BA4 0400448C */  lw         $4, 0x4($2)
    /* 53BA8 00153BA8 0800458C */  lw         $5, 0x8($2)
    /* 53BAC 00153BAC 1885050C */  jal        func_00161460
    /* 53BB0 00153BB0 00000000 */   nop
    /* 53BB4 00153BB4 0000BFDF */  ld         $31, 0x0($29)
    /* 53BB8 00153BB8 1000BD27 */  addiu      $29, $29, 0x10
    /* 53BBC 00153BBC 0800E003 */  jr         $31
    /* 53BC0 00153BC0 00000000 */   nop
    /* 53BC4 00153BC4 00000000 */  nop
    /* 53BC8 00153BC8 00000000 */  nop
    /* 53BCC 00153BCC 00000000 */  nop
.size func_00153b90, 0x40
