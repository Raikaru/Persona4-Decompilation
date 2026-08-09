.section .text
.set noat
.set noreorder
glabel func_0020bf60
    /* 10BF60 0020BF60 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 10BF64 0020BF64 0000BFFF */  sd         $31, 0x0($29)
    /* 10BF68 0020BF68 5849110C */  jal        func_00452560
    /* 10BF6C 0020BF6C 00000000 */   nop
    /* 10BF70 0020BF70 10074394 */  lhu        $3, 0x710($2)
    /* 10BF74 0020BF74 01006334 */  ori        $3, $3, 0x1
    /* 10BF78 0020BF78 100743A4 */  sh         $3, 0x710($2)
    /* 10BF7C 0020BF7C 0000BFDF */  ld         $31, 0x0($29)
    /* 10BF80 0020BF80 1000BD27 */  addiu      $29, $29, 0x10
    /* 10BF84 0020BF84 0800E003 */  jr         $31
    /* 10BF88 0020BF88 00000000 */   nop
    /* 10BF8C 0020BF8C 00000000 */  nop
.size func_0020bf60, 0x30
