.section .text
.set noat
.set noreorder
glabel func_0050fae8
    /* 40FAE8 0050FAE8 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 40FAEC 0050FAEC 0000B0FF */  sd         $16, 0x0($29)
    /* 40FAF0 0050FAF0 0800BFFF */  sd         $31, 0x8($29)
    /* 40FAF4 0050FAF4 0A35140C */  jal        func_0050d428
    /* 40FAF8 0050FAF8 2D808000 */   daddu     $16, $4, $0
    /* 40FAFC 0050FAFC 01000324 */  addiu      $3, $0, 0x1
    /* 40FB00 0050FB00 09004310 */  beq        $2, $3, .L0050FB28
    /* 40FB04 0050FB04 2D200002 */   daddu     $4, $16, $0
    /* 40FB08 0050FB08 7600043C */  lui        $4, %hi(D_0075FC40)
    /* 40FB0C 0050FB0C 8844140C */  jal        func_00511220
    /* 40FB10 0050FB10 40FC8424 */   addiu     $4, $4, %lo(D_0075FC40)
    /* 40FB14 0050FB14 2D100000 */  daddu      $2, $0, $0
    /* 40FB18 0050FB18 0000B0DF */  ld         $16, 0x0($29)
    /* 40FB1C 0050FB1C 0800BFDF */  ld         $31, 0x8($29)
    /* 40FB20 0050FB20 0800E003 */  jr         $31
    /* 40FB24 0050FB24 1000BD27 */   addiu     $29, $29, 0x10
  .L0050FB28:
    /* 40FB28 0050FB28 2E39140C */  jal        func_0050e4b8
    /* 40FB2C 0050FB2C 00000000 */   nop
    /* 40FB30 0050FB30 0000B0DF */  ld         $16, 0x0($29)
    /* 40FB34 0050FB34 2D204000 */  daddu      $4, $2, $0
    /* 40FB38 0050FB38 0800BFDF */  ld         $31, 0x8($29)
    /* 40FB3C 0050FB3C 36AF1408 */  j          func_0052bcd8
    /* 40FB40 0050FB40 1000BD27 */   addiu     $29, $29, 0x10
    /* 40FB44 0050FB44 00000000 */  nop
.size func_0050fae8, 0x60
