.section .text
.set noat
.set noreorder
glabel func_0050c590
    /* 40C590 0050C590 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 40C594 0050C594 0000B0FF */  sd         $16, 0x0($29)
    /* 40C598 0050C598 2D808000 */  daddu      $16, $4, $0
    /* 40C59C 0050C59C 1000BFFF */  sd         $31, 0x10($29)
    /* 40C5A0 0050C5A0 0800B1FF */  sd         $17, 0x8($29)
    /* 40C5A4 0050C5A4 C801118E */  lw         $17, 0x1C8($16)
    /* 40C5A8 0050C5A8 9639110C */  jal        func_0044e658
    /* 40C5AC 0050C5AC 2D202002 */   daddu     $4, $17, $0
    /* 40C5B0 0050C5B0 7600013C */  lui        $1, %hi(D_0075EF70)
    /* 40C5B4 0050C5B4 70EF25DC */  ld         $5, %lo(D_0075EF70)($1)
    /* 40C5B8 0050C5B8 5A38110C */  jal        func_0044e168
    /* 40C5BC 0050C5BC 2D204000 */   daddu     $4, $2, $0
    /* 40C5C0 0050C5C0 C239110C */  jal        func_0044e708
    /* 40C5C4 0050C5C4 2D204000 */   daddu     $4, $2, $0
    /* 40C5C8 0050C5C8 2D200002 */  daddu      $4, $16, $0
    /* 40C5CC 0050C5CC 2D302002 */  daddu      $6, $17, $0
    /* 40C5D0 0050C5D0 0800B1DF */  ld         $17, 0x8($29)
    /* 40C5D4 0050C5D4 0000B0DF */  ld         $16, 0x0($29)
    /* 40C5D8 0050C5D8 2D284000 */  daddu      $5, $2, $0
    /* 40C5DC 0050C5DC 1000BFDF */  ld         $31, 0x10($29)
    /* 40C5E0 0050C5E0 E0341408 */  j          func_0050d380
    /* 40C5E4 0050C5E4 2000BD27 */   addiu     $29, $29, 0x20
.size func_0050c590, 0x58
