.section .text
.set noat
.set noreorder
glabel func_0050ef38
    /* 40EF38 0050EF38 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 40EF3C 0050EF3C 0000B0FF */  sd         $16, 0x0($29)
    /* 40EF40 0050EF40 0800BFFF */  sd         $31, 0x8($29)
    /* 40EF44 0050EF44 0A35140C */  jal        func_0050d428
    /* 40EF48 0050EF48 2D808000 */   daddu     $16, $4, $0
    /* 40EF4C 0050EF4C 01000324 */  addiu      $3, $0, 0x1
    /* 40EF50 0050EF50 09004310 */  beq        $2, $3, .L0050EF78
    /* 40EF54 0050EF54 2D200002 */   daddu     $4, $16, $0
    /* 40EF58 0050EF58 7600043C */  lui        $4, %hi(D_0075F9B8)
    /* 40EF5C 0050EF5C 8844140C */  jal        func_00511220
    /* 40EF60 0050EF60 B8F98424 */   addiu     $4, $4, %lo(D_0075F9B8)
    /* 40EF64 0050EF64 2D100000 */  daddu      $2, $0, $0
    /* 40EF68 0050EF68 0000B0DF */  ld         $16, 0x0($29)
    /* 40EF6C 0050EF6C 0800BFDF */  ld         $31, 0x8($29)
    /* 40EF70 0050EF70 0800E003 */  jr         $31
    /* 40EF74 0050EF74 1000BD27 */   addiu     $29, $29, 0x10
  .L0050EF78:
    /* 40EF78 0050EF78 2E39140C */  jal        func_0050e4b8
    /* 40EF7C 0050EF7C 00000000 */   nop
    /* 40EF80 0050EF80 0000B0DF */  ld         $16, 0x0($29)
    /* 40EF84 0050EF84 2D204000 */  daddu      $4, $2, $0
    /* 40EF88 0050EF88 0800BFDF */  ld         $31, 0x8($29)
    /* 40EF8C 0050EF8C F0AE1408 */  j          func_0052bbc0
    /* 40EF90 0050EF90 1000BD27 */   addiu     $29, $29, 0x10
    /* 40EF94 0050EF94 00000000 */  nop
.size func_0050ef38, 0x60
