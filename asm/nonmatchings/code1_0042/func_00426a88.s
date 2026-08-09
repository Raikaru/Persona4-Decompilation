.section .text
.set noat
.set noreorder
glabel func_00426a88
    /* 326A88 00426A88 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 326A8C 00426A8C 7100023C */  lui        $2, %hi(D_0070C67C)
    /* 326A90 00426A90 8900043C */  lui        $4, %hi(D_00890EA8)
    /* 326A94 00426A94 0000BFFF */  sd         $31, 0x0($29)
    /* 326A98 00426A98 7CC640AC */  sw         $0, %lo(D_0070C67C)($2)
    /* 326A9C 00426A9C A80E8424 */  addiu      $4, $4, %lo(D_00890EA8)
    /* 326AA0 00426AA0 2D280000 */  daddu      $5, $0, $0
    /* 326AA4 00426AA4 72FE100C */  jal        func_0043f9c8
    /* 326AA8 00426AA8 04000624 */   addiu     $6, $0, 0x4
    /* 326AAC 00426AAC 0000BFDF */  ld         $31, 0x0($29)
    /* 326AB0 00426AB0 2D100000 */  daddu      $2, $0, $0
    /* 326AB4 00426AB4 0800E003 */  jr         $31
    /* 326AB8 00426AB8 1000BD27 */   addiu     $29, $29, 0x10
    /* 326ABC 00426ABC 00000000 */  nop
.size func_00426a88, 0x38
