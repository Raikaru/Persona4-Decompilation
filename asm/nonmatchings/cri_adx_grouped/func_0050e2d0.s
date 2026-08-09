.section .text
.set noat
.set noreorder
glabel func_0050e2d0
    /* 40E2D0 0050E2D0 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 40E2D4 0050E2D4 0000B0FF */  sd         $16, 0x0($29)
    /* 40E2D8 0050E2D8 2D808000 */  daddu      $16, $4, $0
    /* 40E2DC 0050E2DC 0800B1FF */  sd         $17, 0x8($29)
    /* 40E2E0 0050E2E0 2D88A000 */  daddu      $17, $5, $0
    /* 40E2E4 0050E2E4 1000BFFF */  sd         $31, 0x10($29)
    /* 40E2E8 0050E2E8 4E000524 */  addiu      $5, $0, 0x4E
    /* 40E2EC 0050E2EC 6493140C */  jal        func_00524d90
    /* 40E2F0 0050E2F0 3C00048E */   lw        $4, 0x3C($16)
    /* 40E2F4 0050E2F4 3C00048E */  lw         $4, 0x3C($16)
    /* 40E2F8 0050E2F8 2D302002 */  daddu      $6, $17, $0
    /* 40E2FC 0050E2FC 0800B1DF */  ld         $17, 0x8($29)
    /* 40E300 0050E300 0000B0DF */  ld         $16, 0x0($29)
    /* 40E304 0050E304 4D000524 */  addiu      $5, $0, 0x4D
    /* 40E308 0050E308 1000BFDF */  ld         $31, 0x10($29)
    /* 40E30C 0050E30C 64931408 */  j          func_00524d90
    /* 40E310 0050E310 2000BD27 */   addiu     $29, $29, 0x20
    /* 40E314 0050E314 00000000 */  nop
.size func_0050e2d0, 0x48
