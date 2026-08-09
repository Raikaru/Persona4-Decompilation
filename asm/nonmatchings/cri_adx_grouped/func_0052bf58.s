.section .text
.set noat
.set noreorder
glabel func_0052bf58
    /* 42BF58 0052BF58 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 42BF5C 0052BF5C 0000B0FF */  sd         $16, 0x0($29)
    /* 42BF60 0052BF60 0800BFFF */  sd         $31, 0x8($29)
    /* 42BF64 0052BF64 ECAF140C */  jal        func_0052bfb0
    /* 42BF68 0052BF68 00000000 */   nop
    /* 42BF6C 0052BF6C 2D804000 */  daddu      $16, $2, $0
    /* 42BF70 0052BF70 0B000012 */  beqz       $16, .L0052BFA0
    /* 42BF74 0052BF74 2D200002 */   daddu     $4, $16, $0
    /* 42BF78 0052BF78 00B0140C */  jal        func_0052c000
    /* 42BF7C 0052BF7C 00000000 */   nop
    /* 42BF80 0052BF80 7400033C */  lui        $3, %hi(D_00746138)
    /* 42BF84 0052BF84 38616324 */  addiu      $3, $3, %lo(D_00746138)
    /* 42BF88 0052BF88 01000524 */  addiu      $5, $0, 0x1
    /* 42BF8C 0052BF8C 0000648C */  lw         $4, 0x0($3)
    /* 42BF90 0052BF90 2D100002 */  daddu      $2, $16, $0
    /* 42BF94 0052BF94 01008424 */  addiu      $4, $4, 0x1
    /* 42BF98 0052BF98 000064AC */  sw         $4, 0x0($3)
    /* 42BF9C 0052BF9C 000005AE */  sw         $5, 0x0($16)
  .L0052BFA0:
    /* 42BFA0 0052BFA0 0000B0DF */  ld         $16, 0x0($29)
    /* 42BFA4 0052BFA4 0800BFDF */  ld         $31, 0x8($29)
    /* 42BFA8 0052BFA8 0800E003 */  jr         $31
    /* 42BFAC 0052BFAC 1000BD27 */   addiu     $29, $29, 0x10
.size func_0052bf58, 0x58
