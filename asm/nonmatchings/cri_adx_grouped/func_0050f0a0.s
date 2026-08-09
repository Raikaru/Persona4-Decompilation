.section .text
.set noat
.set noreorder
glabel func_0050f0a0
    /* 40F0A0 0050F0A0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 40F0A4 0050F0A4 0000B0FF */  sd         $16, 0x0($29)
    /* 40F0A8 0050F0A8 2D808000 */  daddu      $16, $4, $0
    /* 40F0AC 0050F0AC 0800BFFF */  sd         $31, 0x8($29)
    /* 40F0B0 0050F0B0 1E3C140C */  jal        func_0050f078
    /* 40F0B4 0050F0B4 08000426 */   addiu     $4, $16, 0x8
    /* 40F0B8 0050F0B8 01000324 */  addiu      $3, $0, 0x1
    /* 40F0BC 0050F0BC 0B004314 */  bne        $2, $3, .L0050F0EC
    /* 40F0C0 0050F0C0 2D300000 */   daddu     $6, $0, $0
    /* 40F0C4 0050F0C4 8001048E */  lw         $4, 0x180($16)
    /* 40F0C8 0050F0C8 06B8130C */  jal        func_004ee018
    /* 40F0CC 0050F0CC 8401058E */   lw        $5, 0x184($16)
    /* 40F0D0 0050F0D0 7600043C */  lui        $4, %hi(D_0075FA60)
    /* 40F0D4 0050F0D4 06004014 */  bnez       $2, .L0050F0F0
    /* 40F0D8 0050F0D8 60FA8424 */   addiu     $4, $4, %lo(D_0075FA60)
    /* 40F0DC 0050F0DC 8844140C */  jal        func_00511220
    /* 40F0E0 0050F0E0 00000000 */   nop
    /* 40F0E4 0050F0E4 FA25140C */  jal        func_005097e8
    /* 40F0E8 0050F0E8 2D200002 */   daddu     $4, $16, $0
  .L0050F0EC:
    /* 40F0EC 0050F0EC 2D100000 */  daddu      $2, $0, $0
  .L0050F0F0:
    /* 40F0F0 0050F0F0 0000B0DF */  ld         $16, 0x0($29)
    /* 40F0F4 0050F0F4 0800BFDF */  ld         $31, 0x8($29)
    /* 40F0F8 0050F0F8 0800E003 */  jr         $31
    /* 40F0FC 0050F0FC 1000BD27 */   addiu     $29, $29, 0x10
.size func_0050f0a0, 0x60
