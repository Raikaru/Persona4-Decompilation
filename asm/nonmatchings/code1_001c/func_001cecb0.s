.section .text
.set noat
.set noreorder
glabel func_001cecb0
    /* CECB0 001CECB0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* CECB4 001CECB4 0000BFFF */  sd         $31, 0x0($29)
    /* CECB8 001CECB8 80C1023C */  lui        $2, (0xC1800000 >> 16)
    /* CECBC 001CECBC 00608244 */  mtc1       $2, $f12
    /* CECC0 001CECC0 98818DC7 */  lwc1       $f13, -0x7E68($28)
    /* CECC4 001CECC4 FC808EC7 */  lwc1       $f14, -0x7F04($28)
    /* CECC8 001CECC8 303A070C */  jal        func_001ce8c0
    /* CECCC 001CECCC 00000000 */   nop
    /* CECD0 001CECD0 0000BFDF */  ld         $31, 0x0($29)
    /* CECD4 001CECD4 1000BD27 */  addiu      $29, $29, 0x10
    /* CECD8 001CECD8 0800E003 */  jr         $31
    /* CECDC 001CECDC 00000000 */   nop
.size func_001cecb0, 0x30
