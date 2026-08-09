.section .text
.set noat
.set noreorder
glabel func_004be418
    /* 3BE418 004BE418 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3BE41C 004BE41C D000A52C */  sltiu      $5, $5, 0xD0
    /* 3BE420 004BE420 0000B0FF */  sd         $16, 0x0($29)
    /* 3BE424 004BE424 2D808000 */  daddu      $16, $4, $0
    /* 3BE428 004BE428 05000016 */  bnez       $16, .L004BE440
    /* 3BE42C 004BE42C 0800BFFF */   sd        $31, 0x8($29)
    /* 3BE430 004BE430 7500043C */  lui        $4, %hi(D_00756B78)
    /* 3BE434 004BE434 06000010 */  b          .L004BE450
    /* 3BE438 004BE438 786B8424 */   addiu     $4, $4, %lo(D_00756B78)
    /* 3BE43C 004BE43C 00000000 */  nop
  .L004BE440:
    /* 3BE440 004BE440 0700A010 */  beqz       $5, .L004BE460
    /* 3BE444 004BE444 00000000 */   nop
    /* 3BE448 004BE448 7500043C */  lui        $4, %hi(D_00756BB0)
    /* 3BE44C 004BE44C B06B8424 */  addiu      $4, $4, %lo(D_00756BB0)
  .L004BE450:
    /* 3BE450 004BE450 A8F5120C */  jal        func_004bd6a0
    /* 3BE454 004BE454 00000000 */   nop
    /* 3BE458 004BE458 04000010 */  b          .L004BE46C
    /* 3BE45C 004BE45C 2D100000 */   daddu     $2, $0, $0
  .L004BE460:
    /* 3BE460 004BE460 E8FE120C */  jal        func_004bfba0
    /* 3BE464 004BE464 00000000 */   nop
    /* 3BE468 004BE468 2D100002 */  daddu      $2, $16, $0
  .L004BE46C:
    /* 3BE46C 004BE46C 0000B0DF */  ld         $16, 0x0($29)
    /* 3BE470 004BE470 0800BFDF */  ld         $31, 0x8($29)
    /* 3BE474 004BE474 0800E003 */  jr         $31
    /* 3BE478 004BE478 1000BD27 */   addiu     $29, $29, 0x10
    /* 3BE47C 004BE47C 00000000 */  nop
.size func_004be418, 0x68
