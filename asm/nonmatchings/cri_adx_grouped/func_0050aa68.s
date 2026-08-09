.section .text
.set noat
.set noreorder
glabel func_0050aa68
    /* 40AA68 0050AA68 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 40AA6C 0050AA6C 0000B0FF */  sd         $16, 0x0($29)
    /* 40AA70 0050AA70 2D808000 */  daddu      $16, $4, $0
    /* 40AA74 0050AA74 0800B1FF */  sd         $17, 0x8($29)
    /* 40AA78 0050AA78 1000BFFF */  sd         $31, 0x10($29)
    /* 40AA7C 0050AA7C 0A35140C */  jal        func_0050d428
    /* 40AA80 0050AA80 2D88A000 */   daddu     $17, $5, $0
    /* 40AA84 0050AA84 01000324 */  addiu      $3, $0, 0x1
    /* 40AA88 0050AA88 02000524 */  addiu      $5, $0, 0x2
    /* 40AA8C 0050AA8C 08004310 */  beq        $2, $3, .L0050AAB0
    /* 40AA90 0050AA90 2D200002 */   daddu     $4, $16, $0
    /* 40AA94 0050AA94 7600043C */  lui        $4, %hi(D_0075E748)
    /* 40AA98 0050AA98 0000B0DF */  ld         $16, 0x0($29)
    /* 40AA9C 0050AA9C 0800B1DF */  ld         $17, 0x8($29)
    /* 40AAA0 0050AAA0 48E78424 */  addiu      $4, $4, %lo(D_0075E748)
    /* 40AAA4 0050AAA4 1000BFDF */  ld         $31, 0x10($29)
    /* 40AAA8 0050AAA8 88441408 */  j          func_00511220
    /* 40AAAC 0050AAAC 2000BD27 */   addiu     $29, $29, 0x20
  .L0050AAB0:
    /* 40AAB0 0050AAB0 CA28140C */  jal        func_0050a328
    /* 40AAB4 0050AAB4 00000000 */   nop
    /* 40AAB8 0050AAB8 9833140C */  jal        func_0050ce60
    /* 40AABC 0050AABC 2D200002 */   daddu     $4, $16, $0
    /* 40AAC0 0050AAC0 2D282002 */  daddu      $5, $17, $0
    /* 40AAC4 0050AAC4 0000B0DF */  ld         $16, 0x0($29)
    /* 40AAC8 0050AAC8 2D204000 */  daddu      $4, $2, $0
    /* 40AACC 0050AACC 0800B1DF */  ld         $17, 0x8($29)
    /* 40AAD0 0050AAD0 1000BFDF */  ld         $31, 0x10($29)
    /* 40AAD4 0050AAD4 068E1408 */  j          func_00523818
    /* 40AAD8 0050AAD8 2000BD27 */   addiu     $29, $29, 0x20
    /* 40AADC 0050AADC 00000000 */  nop
.size func_0050aa68, 0x78
