.section .text
.set noat
.set noreorder
glabel func_0050ebb8
    /* 40EBB8 0050EBB8 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 40EBBC 0050EBBC 0000B0FF */  sd         $16, 0x0($29)
    /* 40EBC0 0050EBC0 2D80A000 */  daddu      $16, $5, $0
    /* 40EBC4 0050EBC4 0800B1FF */  sd         $17, 0x8($29)
    /* 40EBC8 0050EBC8 2D888000 */  daddu      $17, $4, $0
    /* 40EBCC 0050EBCC 1000B2FF */  sd         $18, 0x10($29)
    /* 40EBD0 0050EBD0 1800BFFF */  sd         $31, 0x18($29)
    /* 40EBD4 0050EBD4 0A35140C */  jal        func_0050d428
    /* 40EBD8 0050EBD8 2D900002 */   daddu     $18, $16, $0
    /* 40EBDC 0050EBDC 01000324 */  addiu      $3, $0, 0x1
    /* 40EBE0 0050EBE0 09004310 */  beq        $2, $3, .L0050EC08
    /* 40EBE4 0050EBE4 7600043C */   lui       $4, %hi(D_0075F800)
    /* 40EBE8 0050EBE8 0000B0DF */  ld         $16, 0x0($29)
    /* 40EBEC 0050EBEC 0800B1DF */  ld         $17, 0x8($29)
    /* 40EBF0 0050EBF0 00F88424 */  addiu      $4, $4, %lo(D_0075F800)
    /* 40EBF4 0050EBF4 1000B2DF */  ld         $18, 0x10($29)
    /* 40EBF8 0050EBF8 1800BFDF */  ld         $31, 0x18($29)
    /* 40EBFC 0050EBFC 88441408 */  j          func_00511220
    /* 40EC00 0050EC00 2000BD27 */   addiu     $29, $29, 0x20
    /* 40EC04 0050EC04 00000000 */  nop
  .L0050EC08:
    /* 40EC08 0050EC08 7C01228E */  lw         $2, 0x17C($17)
    /* 40EC0C 0050EC0C 14004014 */  bnez       $2, .L0050EC60
    /* 40EC10 0050EC10 01010224 */   addiu     $2, $0, 0x101
    /* 40EC14 0050EC14 08000216 */  bne        $16, $2, .L0050EC38
    /* 40EC18 0050EC18 7600043C */   lui       $4, %hi(D_0075F838)
    /* 40EC1C 0050EC1C 0000B0DF */  ld         $16, 0x0($29)
    /* 40EC20 0050EC20 0800B1DF */  ld         $17, 0x8($29)
    /* 40EC24 0050EC24 38F88424 */  addiu      $4, $4, %lo(D_0075F838)
    /* 40EC28 0050EC28 1000B2DF */  ld         $18, 0x10($29)
    /* 40EC2C 0050EC2C 1800BFDF */  ld         $31, 0x18($29)
    /* 40EC30 0050EC30 88441408 */  j          func_00511220
    /* 40EC34 0050EC34 2000BD27 */   addiu     $29, $29, 0x20
  .L0050EC38:
    /* 40EC38 0050EC38 09000016 */  bnez       $16, .L0050EC60
    /* 40EC3C 0050EC3C 1800BFDF */   ld        $31, 0x18($29)
    /* 40EC40 0050EC40 7600043C */  lui        $4, %hi(D_0075F880)
    /* 40EC44 0050EC44 0000B0DF */  ld         $16, 0x0($29)
    /* 40EC48 0050EC48 0800B1DF */  ld         $17, 0x8($29)
    /* 40EC4C 0050EC4C 80F88424 */  addiu      $4, $4, %lo(D_0075F880)
    /* 40EC50 0050EC50 1000B2DF */  ld         $18, 0x10($29)
    /* 40EC54 0050EC54 88441408 */  j          func_00511220
    /* 40EC58 0050EC58 2000BD27 */   addiu     $29, $29, 0x20
    /* 40EC5C 0050EC5C 00000000 */  nop
  .L0050EC60:
    /* 40EC60 0050EC60 3435140C */  jal        func_0050d4d0
    /* 40EC64 0050EC64 2D202002 */   daddu     $4, $17, $0
    /* 40EC68 0050EC68 02000324 */  addiu      $3, $0, 0x2
    /* 40EC6C 0050EC6C 0A004354 */  bnel       $2, $3, .L0050EC98
    /* 40EC70 0050EC70 2D202002 */   daddu     $4, $17, $0
    /* 40EC74 0050EC74 08004056 */  bnel       $18, $0, .L0050EC98
    /* 40EC78 0050EC78 2D202002 */   daddu     $4, $17, $0
    /* 40EC7C 0050EC7C AA2B140C */  jal        func_0050aea8
    /* 40EC80 0050EC80 2D202002 */   daddu     $4, $17, $0
    /* 40EC84 0050EC84 11000324 */  addiu      $3, $0, 0x11
    /* 40EC88 0050EC88 2D804000 */  daddu      $16, $2, $0
    /* 40EC8C 0050EC8C 27101000 */  nor        $2, $0, $16
    /* 40EC90 0050EC90 0A806200 */  movz       $16, $3, $2
    /* 40EC94 0050EC94 2D202002 */  daddu      $4, $17, $0
  .L0050EC98:
    /* 40EC98 0050EC98 0800B1DF */  ld         $17, 0x8($29)
    /* 40EC9C 0050EC9C 2D280002 */  daddu      $5, $16, $0
    /* 40ECA0 0050ECA0 0000B0DF */  ld         $16, 0x0($29)
    /* 40ECA4 0050ECA4 1000B2DF */  ld         $18, 0x10($29)
    /* 40ECA8 0050ECA8 1800BFDF */  ld         $31, 0x18($29)
    /* 40ECAC 0050ECAC 2E3B1408 */  j          func_0050ecb8
    /* 40ECB0 0050ECB0 2000BD27 */   addiu     $29, $29, 0x20
    /* 40ECB4 0050ECB4 00000000 */  nop
.size func_0050ebb8, 0x100
