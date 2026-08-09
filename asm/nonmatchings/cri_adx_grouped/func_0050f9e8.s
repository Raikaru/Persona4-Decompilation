.section .text
.set noat
.set noreorder
glabel func_0050f9e8
    /* 40F9E8 0050F9E8 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 40F9EC 0050F9EC 0000B0FF */  sd         $16, 0x0($29)
    /* 40F9F0 0050F9F0 0800BFFF */  sd         $31, 0x8($29)
    /* 40F9F4 0050F9F4 0A35140C */  jal        func_0050d428
    /* 40F9F8 0050F9F8 2D808000 */   daddu     $16, $4, $0
    /* 40F9FC 0050F9FC 01000324 */  addiu      $3, $0, 0x1
    /* 40FA00 0050FA00 09004310 */  beq        $2, $3, .L0050FA28
    /* 40FA04 0050FA04 2D200002 */   daddu     $4, $16, $0
    /* 40FA08 0050FA08 7600043C */  lui        $4, %hi(D_0075FBD8)
    /* 40FA0C 0050FA0C 8844140C */  jal        func_00511220
    /* 40FA10 0050FA10 D8FB8424 */   addiu     $4, $4, %lo(D_0075FBD8)
    /* 40FA14 0050FA14 2D100000 */  daddu      $2, $0, $0
    /* 40FA18 0050FA18 0000B0DF */  ld         $16, 0x0($29)
    /* 40FA1C 0050FA1C 0800BFDF */  ld         $31, 0x8($29)
    /* 40FA20 0050FA20 0800E003 */  jr         $31
    /* 40FA24 0050FA24 1000BD27 */   addiu     $29, $29, 0x10
  .L0050FA28:
    /* 40FA28 0050FA28 2E39140C */  jal        func_0050e4b8
    /* 40FA2C 0050FA2C 00000000 */   nop
    /* 40FA30 0050FA30 0000B0DF */  ld         $16, 0x0($29)
    /* 40FA34 0050FA34 2D204000 */  daddu      $4, $2, $0
    /* 40FA38 0050FA38 0800BFDF */  ld         $31, 0x8($29)
    /* 40FA3C 0050FA3C A6AF1408 */  j          func_0052be98
    /* 40FA40 0050FA40 1000BD27 */   addiu     $29, $29, 0x10
    /* 40FA44 0050FA44 00000000 */  nop
.size func_0050f9e8, 0x60
