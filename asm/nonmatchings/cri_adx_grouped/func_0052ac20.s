.section .text
.set noat
.set noreorder
glabel func_0052ac20
    /* 42AC20 0052AC20 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 42AC24 0052AC24 0000B0FF */  sd         $16, 0x0($29)
    /* 42AC28 0052AC28 2D808000 */  daddu      $16, $4, $0
    /* 42AC2C 0052AC2C 0800B1FF */  sd         $17, 0x8($29)
    /* 42AC30 0052AC30 2D88A000 */  daddu      $17, $5, $0
    /* 42AC34 0052AC34 1000BFFF */  sd         $31, 0x10($29)
    /* 42AC38 0052AC38 10B2140C */  jal        func_0052c840
    /* 42AC3C 0052AC3C 2400048E */   lw        $4, 0x24($16)
    /* 42AC40 0052AC40 7600063C */  lui        $6, %hi(D_00760C38)
    /* 42AC44 0052AC44 01000324 */  addiu      $3, $0, 0x1
    /* 42AC48 0052AC48 2D200002 */  daddu      $4, $16, $0
    /* 42AC4C 0052AC4C 10000524 */  addiu      $5, $0, 0x10
    /* 42AC50 0052AC50 07004310 */  beq        $2, $3, .L0052AC70
    /* 42AC54 0052AC54 380CC624 */   addiu     $6, $6, %lo(D_00760C38)
    /* 42AC58 0052AC58 2D282002 */  daddu      $5, $17, $0
    /* 42AC5C 0052AC5C 0800B1DF */  ld         $17, 0x8($29)
    /* 42AC60 0052AC60 0000B0DF */  ld         $16, 0x0($29)
    /* 42AC64 0052AC64 1000BFDF */  ld         $31, 0x10($29)
    /* 42AC68 0052AC68 68AE1408 */  j          func_0052b9a0
    /* 42AC6C 0052AC6C 2000BD27 */   addiu     $29, $29, 0x20
  .L0052AC70:
    /* 42AC70 0052AC70 5EB3140C */  jal        func_0052cd78
    /* 42AC74 0052AC74 00000000 */   nop
    /* 42AC78 0052AC78 2D200002 */  daddu      $4, $16, $0
    /* 42AC7C 0052AC7C 2D282002 */  daddu      $5, $17, $0
    /* 42AC80 0052AC80 0800B1DF */  ld         $17, 0x8($29)
    /* 42AC84 0052AC84 0000B0DF */  ld         $16, 0x0($29)
    /* 42AC88 0052AC88 1000BFDF */  ld         $31, 0x10($29)
    /* 42AC8C 0052AC8C AAAA1408 */  j          func_0052aaa8
    /* 42AC90 0052AC90 2000BD27 */   addiu     $29, $29, 0x20
    /* 42AC94 0052AC94 00000000 */  nop
.size func_0052ac20, 0x78
