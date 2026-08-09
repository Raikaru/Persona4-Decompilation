.section .text
.set noat
.set noreorder
glabel func_004e03b0
    /* 3E03B0 004E03B0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3E03B4 004E03B4 0000B0FF */  sd         $16, 0x0($29)
    /* 3E03B8 004E03B8 0800BFFF */  sd         $31, 0x8($29)
    /* 3E03BC 004E03BC E080130C */  jal        func_004e0380
    /* 3E03C0 004E03C0 00000000 */   nop
    /* 3E03C4 004E03C4 7300023C */  lui        $2, %hi(D_0072B678)
    /* 3E03C8 004E03C8 7300043C */  lui        $4, %hi(D_0072B680)
    /* 3E03CC 004E03CC 78B65024 */  addiu      $16, $2, %lo(D_0072B678)
    /* 3E03D0 004E03D0 80B68424 */  addiu      $4, $4, %lo(D_0072B680)
    /* 3E03D4 004E03D4 0000028E */  lw         $2, 0x0($16)
    /* 3E03D8 004E03D8 2D280000 */  daddu      $5, $0, $0
    /* 3E03DC 004E03DC 04004014 */  bnez       $2, .L004E03F0
    /* 3E03E0 004E03E0 70650624 */   addiu     $6, $0, 0x6570
    /* 3E03E4 004E03E4 72FE100C */  jal        func_0043f9c8
    /* 3E03E8 004E03E8 00000000 */   nop
    /* 3E03EC 004E03EC 0000028E */  lw         $2, 0x0($16)
  .L004E03F0:
    /* 3E03F0 004E03F0 01004224 */  addiu      $2, $2, 0x1
    /* 3E03F4 004E03F4 0800BFDF */  ld         $31, 0x8($29)
    /* 3E03F8 004E03F8 000002AE */  sw         $2, 0x0($16)
    /* 3E03FC 004E03FC 0000B0DF */  ld         $16, 0x0($29)
    /* 3E0400 004E0400 E6801308 */  j          func_004e0398
    /* 3E0404 004E0404 1000BD27 */   addiu     $29, $29, 0x10
.size func_004e03b0, 0x58
