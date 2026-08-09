.section .text
.set noat
.set noreorder
glabel func_0052b1a8
    /* 42B1A8 0052B1A8 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 42B1AC 0052B1AC 2D380000 */  daddu      $7, $0, $0
    /* 42B1B0 0052B1B0 0000B0FF */  sd         $16, 0x0($29)
    /* 42B1B4 0052B1B4 2D808000 */  daddu      $16, $4, $0
    /* 42B1B8 0052B1B8 0800B1FF */  sd         $17, 0x8($29)
    /* 42B1BC 0052B1BC 2D88A000 */  daddu      $17, $5, $0
    /* 42B1C0 0052B1C0 1000B2FF */  sd         $18, 0x10($29)
    /* 42B1C4 0052B1C4 1800BFFF */  sd         $31, 0x18($29)
    /* 42B1C8 0052B1C8 ECAB140C */  jal        func_0052afb0
    /* 42B1CC 0052B1CC 2D90C000 */   daddu     $18, $6, $0
    /* 42B1D0 0052B1D0 1800BFDF */  ld         $31, 0x18($29)
    /* 42B1D4 0052B1D4 2D200002 */  daddu      $4, $16, $0
    /* 42B1D8 0052B1D8 2D282002 */  daddu      $5, $17, $0
    /* 42B1DC 0052B1DC 0800B1DF */  ld         $17, 0x8($29)
    /* 42B1E0 0052B1E0 2D304002 */  daddu      $6, $18, $0
    /* 42B1E4 0052B1E4 1000B2DF */  ld         $18, 0x10($29)
    /* 42B1E8 0052B1E8 0000B0DF */  ld         $16, 0x0($29)
    /* 42B1EC 0052B1EC 7EAC1408 */  j          func_0052b1f8
    /* 42B1F0 0052B1F0 2000BD27 */   addiu     $29, $29, 0x20
    /* 42B1F4 0052B1F4 00000000 */  nop
.size func_0052b1a8, 0x50
