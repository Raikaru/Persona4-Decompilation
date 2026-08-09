.section .text
.set noat
.set noreorder
glabel func_0025ec50
    /* 15EC50 0025EC50 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 15EC54 0025EC54 1000BFFF */  sd         $31, 0x10($29)
    /* 15EC58 0025EC58 0000B07F */  sq         $16, 0x0($29)
    /* 15EC5C 0025EC5C 2D80A000 */  daddu      $16, $5, $0
    /* 15EC60 0025EC60 2D200002 */  daddu      $4, $16, $0
    /* 15EC64 0025EC64 2D280000 */  daddu      $5, $0, $0
    /* 15EC68 0025EC68 E0AC110C */  jal        func_0046b380
    /* 15EC6C 0025EC6C 00000000 */   nop
    /* 15EC70 0025EC70 2D200002 */  daddu      $4, $16, $0
    /* 15EC74 0025EC74 A0B4110C */  jal        func_0046d280
    /* 15EC78 0025EC78 00000000 */   nop
    /* 15EC7C 0025EC7C 1000BFDF */  ld         $31, 0x10($29)
    /* 15EC80 0025EC80 0000B07B */  lq         $16, 0x0($29)
    /* 15EC84 0025EC84 2000BD27 */  addiu      $29, $29, 0x20
    /* 15EC88 0025EC88 0800E003 */  jr         $31
    /* 15EC8C 0025EC8C 00000000 */   nop
.size func_0025ec50, 0x40
