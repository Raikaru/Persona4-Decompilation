.section .text
.set noat
.set noreorder
glabel func_00485ae0
    /* 385AE0 00485AE0 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 385AE4 00485AE4 1000BFFF */  sd         $31, 0x10($29)
    /* 385AE8 00485AE8 0000B07F */  sq         $16, 0x0($29)
    /* 385AEC 00485AEC 2D808000 */  daddu      $16, $4, $0
    /* 385AF0 00485AF0 8C15120C */  jal        func_00485630
    /* 385AF4 00485AF4 00000000 */   nop
    /* 385AF8 00485AF8 2D200002 */  daddu      $4, $16, $0
    /* 385AFC 00485AFC 1C16120C */  jal        func_00485870
    /* 385B00 00485B00 00000000 */   nop
    /* 385B04 00485B04 1000BFDF */  ld         $31, 0x10($29)
    /* 385B08 00485B08 0000B07B */  lq         $16, 0x0($29)
    /* 385B0C 00485B0C 2000BD27 */  addiu      $29, $29, 0x20
    /* 385B10 00485B10 0800E003 */  jr         $31
    /* 385B14 00485B14 00000000 */   nop
    /* 385B18 00485B18 00000000 */  nop
    /* 385B1C 00485B1C 00000000 */  nop
.size func_00485ae0, 0x40
