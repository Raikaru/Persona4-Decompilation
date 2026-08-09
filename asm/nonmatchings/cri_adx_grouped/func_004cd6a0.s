.section .text
.set noat
.set noreorder
glabel func_004cd6a0
    /* 3CD6A0 004CD6A0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3CD6A4 004CD6A4 2D280000 */  daddu      $5, $0, $0
    /* 3CD6A8 004CD6A8 0000B0FF */  sd         $16, 0x0($29)
    /* 3CD6AC 004CD6AC 0800BFFF */  sd         $31, 0x8($29)
    /* 3CD6B0 004CD6B0 6CB2130C */  jal        func_004ec9b0
    /* 3CD6B4 004CD6B4 2D808000 */   daddu     $16, $4, $0
    /* 3CD6B8 004CD6B8 2D200002 */  daddu      $4, $16, $0
    /* 3CD6BC 004CD6BC 46B2130C */  jal        func_004ec918
    /* 3CD6C0 004CD6C0 2D280000 */   daddu     $5, $0, $0
    /* 3CD6C4 004CD6C4 2D200002 */  daddu      $4, $16, $0
    /* 3CD6C8 004CD6C8 0800BFDF */  ld         $31, 0x8($29)
    /* 3CD6CC 004CD6CC 0000B0DF */  ld         $16, 0x0($29)
    /* 3CD6D0 004CD6D0 E2B11308 */  j          func_004ec788
    /* 3CD6D4 004CD6D4 1000BD27 */   addiu     $29, $29, 0x10
.size func_004cd6a0, 0x38
