.section .text
.set noat
.set noreorder
glabel func_005070a8
    /* 4070A8 005070A8 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 4070AC 005070AC 0000BFFF */  sd         $31, 0x0($29)
    /* 4070B0 005070B0 3C1D140C */  jal        func_005074f0
    /* 4070B4 005070B4 00000000 */   nop
    /* 4070B8 005070B8 9200023C */  lui        $2, %hi(D_009270D0)
    /* 4070BC 005070BC 0000BFDF */  ld         $31, 0x0($29)
    /* 4070C0 005070C0 D070448C */  lw         $4, %lo(D_009270D0)($2)
    /* 4070C4 005070C4 E01B0524 */  addiu      $5, $0, 0x1BE0
    /* 4070C8 005070C8 B21C1408 */  j          func_005072c8
    /* 4070CC 005070CC 1000BD27 */   addiu     $29, $29, 0x10
.size func_005070a8, 0x28
