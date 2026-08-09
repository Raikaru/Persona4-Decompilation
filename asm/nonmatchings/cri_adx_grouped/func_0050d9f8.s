.section .text
.set noat
.set noreorder
glabel func_0050d9f8
    /* 40D9F8 0050D9F8 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 40D9FC 0050D9FC 0000B0FF */  sd         $16, 0x0($29)
    /* 40DA00 0050DA00 2D808000 */  daddu      $16, $4, $0
    /* 40DA04 0050DA04 0800B1FF */  sd         $17, 0x8($29)
    /* 40DA08 0050DA08 1000BFFF */  sd         $31, 0x10($29)
    /* 40DA0C 0050DA0C 0A35140C */  jal        func_0050d428
    /* 40DA10 0050DA10 2D88A000 */   daddu     $17, $5, $0
    /* 40DA14 0050DA14 01000324 */  addiu      $3, $0, 0x1
    /* 40DA18 0050DA18 2D200002 */  daddu      $4, $16, $0
    /* 40DA1C 0050DA1C 08004310 */  beq        $2, $3, .L0050DA40
    /* 40DA20 0050DA20 2D282002 */   daddu     $5, $17, $0
    /* 40DA24 0050DA24 7600043C */  lui        $4, %hi(D_0075F458)
    /* 40DA28 0050DA28 0000B0DF */  ld         $16, 0x0($29)
    /* 40DA2C 0050DA2C 0800B1DF */  ld         $17, 0x8($29)
    /* 40DA30 0050DA30 58F48424 */  addiu      $4, $4, %lo(D_0075F458)
    /* 40DA34 0050DA34 1000BFDF */  ld         $31, 0x10($29)
    /* 40DA38 0050DA38 88441408 */  j          func_00511220
    /* 40DA3C 0050DA3C 2000BD27 */   addiu     $29, $29, 0x20
  .L0050DA40:
    /* 40DA40 0050DA40 2C32140C */  jal        func_0050c8b0
    /* 40DA44 0050DA44 00000000 */   nop
    /* 40DA48 0050DA48 80020426 */  addiu      $4, $16, 0x280
    /* 40DA4C 0050DA4C 2D282002 */  daddu      $5, $17, $0
    /* 40DA50 0050DA50 0800B1DF */  ld         $17, 0x8($29)
    /* 40DA54 0050DA54 0000B0DF */  ld         $16, 0x0($29)
    /* 40DA58 0050DA58 1000BFDF */  ld         $31, 0x10($29)
    /* 40DA5C 0050DA5C BE421408 */  j          func_00510af8
    /* 40DA60 0050DA60 2000BD27 */   addiu     $29, $29, 0x20
    /* 40DA64 0050DA64 00000000 */  nop
.size func_0050d9f8, 0x70
