.section .text
.set noat
.set noreorder
glabel func_0052ac98
    /* 42AC98 0052AC98 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 42AC9C 0052AC9C 0000B0FF */  sd         $16, 0x0($29)
    /* 42ACA0 0052ACA0 2D808000 */  daddu      $16, $4, $0
    /* 42ACA4 0052ACA4 0800B1FF */  sd         $17, 0x8($29)
    /* 42ACA8 0052ACA8 2D88A000 */  daddu      $17, $5, $0
    /* 42ACAC 0052ACAC 1000BFFF */  sd         $31, 0x10($29)
    /* 42ACB0 0052ACB0 10B2140C */  jal        func_0052c840
    /* 42ACB4 0052ACB4 2400048E */   lw        $4, 0x24($16)
    /* 42ACB8 0052ACB8 7600063C */  lui        $6, %hi(D_00760C68)
    /* 42ACBC 0052ACBC 01000324 */  addiu      $3, $0, 0x1
    /* 42ACC0 0052ACC0 2D200002 */  daddu      $4, $16, $0
    /* 42ACC4 0052ACC4 20000524 */  addiu      $5, $0, 0x20
    /* 42ACC8 0052ACC8 07004310 */  beq        $2, $3, .L0052ACE8
    /* 42ACCC 0052ACCC 680CC624 */   addiu     $6, $6, %lo(D_00760C68)
    /* 42ACD0 0052ACD0 2D282002 */  daddu      $5, $17, $0
    /* 42ACD4 0052ACD4 0800B1DF */  ld         $17, 0x8($29)
    /* 42ACD8 0052ACD8 0000B0DF */  ld         $16, 0x0($29)
    /* 42ACDC 0052ACDC 1000BFDF */  ld         $31, 0x10($29)
    /* 42ACE0 0052ACE0 68AE1408 */  j          func_0052b9a0
    /* 42ACE4 0052ACE4 2000BD27 */   addiu     $29, $29, 0x20
  .L0052ACE8:
    /* 42ACE8 0052ACE8 5EB3140C */  jal        func_0052cd78
    /* 42ACEC 0052ACEC 00000000 */   nop
    /* 42ACF0 0052ACF0 2D200002 */  daddu      $4, $16, $0
    /* 42ACF4 0052ACF4 2D282002 */  daddu      $5, $17, $0
    /* 42ACF8 0052ACF8 0800B1DF */  ld         $17, 0x8($29)
    /* 42ACFC 0052ACFC 0000B0DF */  ld         $16, 0x0($29)
    /* 42AD00 0052AD00 1000BFDF */  ld         $31, 0x10($29)
    /* 42AD04 0052AD04 AAAA1408 */  j          func_0052aaa8
    /* 42AD08 0052AD08 2000BD27 */   addiu     $29, $29, 0x20
    /* 42AD0C 0052AD0C 00000000 */  nop
.size func_0052ac98, 0x78
