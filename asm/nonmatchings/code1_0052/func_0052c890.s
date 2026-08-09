.section .text
.set noat
.set noreorder
glabel func_0052c890
    /* 42C890 0052C890 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 42C894 0052C894 0800B1FF */  sd         $17, 0x8($29)
    /* 42C898 0052C898 2D88A000 */  daddu      $17, $5, $0
    /* 42C89C 0052C89C 10000524 */  addiu      $5, $0, 0x10
    /* 42C8A0 0052C8A0 0000B0FF */  sd         $16, 0x0($29)
    /* 42C8A4 0052C8A4 1000B2FF */  sd         $18, 0x10($29)
    /* 42C8A8 0052C8A8 2D90C000 */  daddu      $18, $6, $0
    /* 42C8AC 0052C8AC 1800BFFF */  sd         $31, 0x18($29)
    /* 42C8B0 0052C8B0 5EB3140C */  jal        func_0052cd78
    /* 42C8B4 0052C8B4 2D808000 */   daddu     $16, $4, $0
    /* 42C8B8 0052C8B8 2D200002 */  daddu      $4, $16, $0
    /* 42C8BC 0052C8BC 2D282002 */  daddu      $5, $17, $0
    /* 42C8C0 0052C8C0 0800B1DF */  ld         $17, 0x8($29)
    /* 42C8C4 0052C8C4 2D384002 */  daddu      $7, $18, $0
    /* 42C8C8 0052C8C8 1000B2DF */  ld         $18, 0x10($29)
    /* 42C8CC 0052C8CC 0000B0DF */  ld         $16, 0x0($29)
    /* 42C8D0 0052C8D0 10000624 */  addiu      $6, $0, 0x10
    /* 42C8D4 0052C8D4 1800BFDF */  ld         $31, 0x18($29)
    /* 42C8D8 0052C8D8 60B21408 */  j          func_0052c980
    /* 42C8DC 0052C8DC 2000BD27 */   addiu     $29, $29, 0x20
.size func_0052c890, 0x50
