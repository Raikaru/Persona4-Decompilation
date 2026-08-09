.section .text
.set noat
.set noreorder
glabel func_0050e288
    /* 40E288 0050E288 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 40E28C 0050E28C 0000B0FF */  sd         $16, 0x0($29)
    /* 40E290 0050E290 2D808000 */  daddu      $16, $4, $0
    /* 40E294 0050E294 0800B1FF */  sd         $17, 0x8($29)
    /* 40E298 0050E298 2D88C000 */  daddu      $17, $6, $0
    /* 40E29C 0050E29C 1000BFFF */  sd         $31, 0x10($29)
    /* 40E2A0 0050E2A0 2D30A000 */  daddu      $6, $5, $0
    /* 40E2A4 0050E2A4 5D000524 */  addiu      $5, $0, 0x5D
    /* 40E2A8 0050E2A8 6493140C */  jal        func_00524d90
    /* 40E2AC 0050E2AC 3C00048E */   lw        $4, 0x3C($16)
    /* 40E2B0 0050E2B0 3C00048E */  lw         $4, 0x3C($16)
    /* 40E2B4 0050E2B4 2D302002 */  daddu      $6, $17, $0
    /* 40E2B8 0050E2B8 0800B1DF */  ld         $17, 0x8($29)
    /* 40E2BC 0050E2BC 0000B0DF */  ld         $16, 0x0($29)
    /* 40E2C0 0050E2C0 5E000524 */  addiu      $5, $0, 0x5E
    /* 40E2C4 0050E2C4 1000BFDF */  ld         $31, 0x10($29)
    /* 40E2C8 0050E2C8 64931408 */  j          func_00524d90
    /* 40E2CC 0050E2CC 2000BD27 */   addiu     $29, $29, 0x20
.size func_0050e288, 0x48
