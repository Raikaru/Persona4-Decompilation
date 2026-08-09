.section .text
.set noat
.set noreorder
glabel func_004e5a68
    /* 3E5A68 004E5A68 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 3E5A6C 004E5A6C 0000B0FF */  sd         $16, 0x0($29)
    /* 3E5A70 004E5A70 2D808000 */  daddu      $16, $4, $0
    /* 3E5A74 004E5A74 00800434 */  ori        $4, $0, 0x8000
    /* 3E5A78 004E5A78 0800B1FF */  sd         $17, 0x8($29)
    /* 3E5A7C 004E5A7C 1000BFFF */  sd         $31, 0x10($29)
    /* 3E5A80 004E5A80 8691130C */  jal        func_004e4618
    /* 3E5A84 004E5A84 2D88A000 */   daddu     $17, $5, $0
    /* 3E5A88 004E5A88 7300023C */  lui        $2, %hi(D_007330CC)
    /* 3E5A8C 004E5A8C CC30468C */  lw         $6, %lo(D_007330CC)($2)
    /* 3E5A90 004E5A90 2D282002 */  daddu      $5, $17, $0
    /* 3E5A94 004E5A94 AEB8100C */  jal        func_0042e2b8
    /* 3E5A98 004E5A98 2D200002 */   daddu     $4, $16, $0
    /* 3E5A9C 004E5A9C 01800434 */  ori        $4, $0, 0x8001
    /* 3E5AA0 004E5AA0 8691130C */  jal        func_004e4618
    /* 3E5AA4 004E5AA4 2D804000 */   daddu     $16, $2, $0
    /* 3E5AA8 004E5AA8 0800B1DF */  ld         $17, 0x8($29)
    /* 3E5AAC 004E5AAC 2D100002 */  daddu      $2, $16, $0
    /* 3E5AB0 004E5AB0 1000BFDF */  ld         $31, 0x10($29)
    /* 3E5AB4 004E5AB4 0000B0DF */  ld         $16, 0x0($29)
    /* 3E5AB8 004E5AB8 0800E003 */  jr         $31
    /* 3E5ABC 004E5ABC 2000BD27 */   addiu     $29, $29, 0x20
.size func_004e5a68, 0x58
