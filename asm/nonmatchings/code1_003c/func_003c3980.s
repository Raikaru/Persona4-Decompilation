.section .text
.set noat
.set noreorder
glabel func_003c3980
    /* 2C3980 003C3980 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 2C3984 003C3984 2D288000 */  daddu      $5, $4, $0
    /* 2C3988 003C3988 1000BFFF */  sd         $31, 0x10($29)
    /* 2C398C 003C398C 7100043C */  lui        $4, %hi(D_0070AFD0)
    /* 2C3990 003C3990 0000B07F */  sq         $16, 0x0($29)
    /* 2C3994 003C3994 D0AF8424 */  addiu      $4, $4, %lo(D_0070AFD0)
    /* 2C3998 003C3998 DC8C0F0C */  jal        func_003e3370
    /* 2C399C 003C399C 24001024 */   addiu     $16, $0, 0x24
    /* 2C39A0 003C39A0 0C004224 */  addiu      $2, $2, 0xC
    /* 2C39A4 003C39A4 1000BFDF */  ld         $31, 0x10($29)
    /* 2C39A8 003C39A8 21100202 */  addu       $2, $16, $2
    /* 2C39AC 003C39AC 0000B07B */  lq         $16, 0x0($29)
    /* 2C39B0 003C39B0 0800E003 */  jr         $31
    /* 2C39B4 003C39B4 2000BD27 */   addiu     $29, $29, 0x20
    /* 2C39B8 003C39B8 00000000 */  nop
    /* 2C39BC 003C39BC 00000000 */  nop
.size func_003c3980, 0x40
