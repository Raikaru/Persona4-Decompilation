.section .text
.set noat
.set noreorder
glabel func_0052a498
    /* 42A498 0052A498 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 42A49C 0052A49C 0000B0FF */  sd         $16, 0x0($29)
    /* 42A4A0 0052A4A0 0800BFFF */  sd         $31, 0x8($29)
    /* 42A4A4 0052A4A4 3CA9140C */  jal        func_0052a4f0
    /* 42A4A8 0052A4A8 00000000 */   nop
    /* 42A4AC 0052A4AC 2D804000 */  daddu      $16, $2, $0
    /* 42A4B0 0052A4B0 0B000012 */  beqz       $16, .L0052A4E0
    /* 42A4B4 0052A4B4 2D200002 */   daddu     $4, $16, $0
    /* 42A4B8 0052A4B8 50A9140C */  jal        func_0052a540
    /* 42A4BC 0052A4BC 00000000 */   nop
    /* 42A4C0 0052A4C0 7400033C */  lui        $3, %hi(D_00745B40)
    /* 42A4C4 0052A4C4 405B6324 */  addiu      $3, $3, %lo(D_00745B40)
    /* 42A4C8 0052A4C8 01000524 */  addiu      $5, $0, 0x1
    /* 42A4CC 0052A4CC 0000648C */  lw         $4, 0x0($3)
    /* 42A4D0 0052A4D0 2D100002 */  daddu      $2, $16, $0
    /* 42A4D4 0052A4D4 01008424 */  addiu      $4, $4, 0x1
    /* 42A4D8 0052A4D8 000064AC */  sw         $4, 0x0($3)
    /* 42A4DC 0052A4DC 000005AE */  sw         $5, 0x0($16)
  .L0052A4E0:
    /* 42A4E0 0052A4E0 0000B0DF */  ld         $16, 0x0($29)
    /* 42A4E4 0052A4E4 0800BFDF */  ld         $31, 0x8($29)
    /* 42A4E8 0052A4E8 0800E003 */  jr         $31
    /* 42A4EC 0052A4EC 1000BD27 */   addiu     $29, $29, 0x10
.size func_0052a498, 0x58
