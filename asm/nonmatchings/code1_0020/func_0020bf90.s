.section .text
.set noat
.set noreorder
glabel func_0020bf90
    /* 10BF90 0020BF90 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 10BF94 0020BF94 0000BFFF */  sd         $31, 0x0($29)
    /* 10BF98 0020BF98 5849110C */  jal        func_00452560
    /* 10BF9C 0020BF9C 00000000 */   nop
    /* 10BFA0 0020BFA0 10074394 */  lhu        $3, 0x710($2)
    /* 10BFA4 0020BFA4 FEFF6330 */  andi       $3, $3, 0xFFFE
    /* 10BFA8 0020BFA8 100743A4 */  sh         $3, 0x710($2)
    /* 10BFAC 0020BFAC 0000BFDF */  ld         $31, 0x0($29)
    /* 10BFB0 0020BFB0 1000BD27 */  addiu      $29, $29, 0x10
    /* 10BFB4 0020BFB4 0800E003 */  jr         $31
    /* 10BFB8 0020BFB8 00000000 */   nop
    /* 10BFBC 0020BFBC 00000000 */  nop
.size func_0020bf90, 0x30
