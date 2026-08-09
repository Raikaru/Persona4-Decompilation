.section .text
.set noat
.set noreorder
glabel func_003ed2d0
    /* 2ED2D0 003ED2D0 C0FFBD27 */  addiu      $29, $29, -0x40
    /* 2ED2D4 003ED2D4 3000BFFF */  sd         $31, 0x30($29)
    /* 2ED2D8 003ED2D8 2000B27F */  sq         $18, 0x20($29)
    /* 2ED2DC 003ED2DC 2D908000 */  daddu      $18, $4, $0
    /* 2ED2E0 003ED2E0 1000B17F */  sq         $17, 0x10($29)
    /* 2ED2E4 003ED2E4 2D20A000 */  daddu      $4, $5, $0
    /* 2ED2E8 003ED2E8 0000B07F */  sq         $16, 0x0($29)
    /* 2ED2EC 003ED2EC 2D28C000 */  daddu      $5, $6, $0
    /* 2ED2F0 003ED2F0 B0A80F0C */  jal        func_003ea2c0
    /* 2ED2F4 003ED2F4 20000624 */   addiu     $6, $0, 0x20
    /* 2ED2F8 003ED2F8 2D884000 */  daddu      $17, $2, $0
    /* 2ED2FC 003ED2FC 39002012 */  beqz       $17, .L003ED3E4
    /* 2ED300 003ED300 00000000 */   nop
    /* 2ED304 003ED304 F8A80F0C */  jal        func_003ea3e0
    /* 2ED308 003ED308 2D202002 */   daddu     $4, $17, $0
    /* 2ED30C 003ED30C 37004010 */  beqz       $2, .L003ED3EC
    /* 2ED310 003ED310 00000000 */   nop
    /* 2ED314 003ED314 0C00428E */  lw         $2, 0xC($18)
    /* 2ED318 003ED318 20000624 */  addiu      $6, $0, 0x20
    /* 2ED31C 003ED31C 23004610 */  beq        $2, $6, .L003ED3AC
    /* 2ED320 003ED320 00000000 */   nop
    /* 2ED324 003ED324 0800458E */  lw         $5, 0x8($18)
    /* 2ED328 003ED328 B0A80F0C */  jal        func_003ea2c0
    /* 2ED32C 003ED32C 0400448E */   lw        $4, 0x4($18)
    /* 2ED330 003ED330 2D804000 */  daddu      $16, $2, $0
    /* 2ED334 003ED334 31000012 */  beqz       $16, .L003ED3FC
    /* 2ED338 003ED338 00000000 */   nop
    /* 2ED33C 003ED33C F8A80F0C */  jal        func_003ea3e0
    /* 2ED340 003ED340 2D200002 */   daddu     $4, $16, $0
    /* 2ED344 003ED344 33004010 */  beqz       $2, .L003ED414
    /* 2ED348 003ED348 00000000 */   nop
    /* 2ED34C 003ED34C 2D284002 */  daddu      $5, $18, $0
    /* 2ED350 003ED350 B0AE0F0C */  jal        func_003ebac0
    /* 2ED354 003ED354 2D200002 */   daddu     $4, $16, $0
    /* 2ED358 003ED358 2D202002 */  daddu      $4, $17, $0
    /* 2ED35C 003ED35C 2CB40F0C */  jal        func_003ed0b0
    /* 2ED360 003ED360 2D280002 */   daddu     $5, $16, $0
    /* 2ED364 003ED364 0B004014 */  bnez       $2, .L003ED394
    /* 2ED368 003ED368 00000000 */   nop
    /* 2ED36C 003ED36C 44A90F0C */  jal        func_003ea510
    /* 2ED370 003ED370 2D200002 */   daddu     $4, $16, $0
    /* 2ED374 003ED374 DCA80F0C */  jal        func_003ea370
    /* 2ED378 003ED378 2D200002 */   daddu     $4, $16, $0
    /* 2ED37C 003ED37C 44A90F0C */  jal        func_003ea510
    /* 2ED380 003ED380 2D202002 */   daddu     $4, $17, $0
    /* 2ED384 003ED384 DCA80F0C */  jal        func_003ea370
    /* 2ED388 003ED388 2D202002 */   daddu     $4, $17, $0
    /* 2ED38C 003ED38C 28000010 */  b          .L003ED430
    /* 2ED390 003ED390 2D100000 */   daddu     $2, $0, $0
  .L003ED394:
    /* 2ED394 003ED394 44A90F0C */  jal        func_003ea510
    /* 2ED398 003ED398 2D200002 */   daddu     $4, $16, $0
    /* 2ED39C 003ED39C DCA80F0C */  jal        func_003ea370
    /* 2ED3A0 003ED3A0 2D200002 */   daddu     $4, $16, $0
    /* 2ED3A4 003ED3A4 0D000010 */  b          .L003ED3DC
    /* 2ED3A8 003ED3A8 2D102002 */   daddu     $2, $17, $0
  .L003ED3AC:
    /* 2ED3AC 003ED3AC 2D284002 */  daddu      $5, $18, $0
    /* 2ED3B0 003ED3B0 2CB40F0C */  jal        func_003ed0b0
    /* 2ED3B4 003ED3B4 2D202002 */   daddu     $4, $17, $0
    /* 2ED3B8 003ED3B8 07004014 */  bnez       $2, .L003ED3D8
    /* 2ED3BC 003ED3BC 00000000 */   nop
    /* 2ED3C0 003ED3C0 44A90F0C */  jal        func_003ea510
    /* 2ED3C4 003ED3C4 2D202002 */   daddu     $4, $17, $0
    /* 2ED3C8 003ED3C8 DCA80F0C */  jal        func_003ea370
    /* 2ED3CC 003ED3CC 2D202002 */   daddu     $4, $17, $0
    /* 2ED3D0 003ED3D0 17000010 */  b          .L003ED430
    /* 2ED3D4 003ED3D4 2D100000 */   daddu     $2, $0, $0
  .L003ED3D8:
    /* 2ED3D8 003ED3D8 2D102002 */  daddu      $2, $17, $0
  .L003ED3DC:
    /* 2ED3DC 003ED3DC 15000010 */  b          .L003ED434
    /* 2ED3E0 003ED3E0 3000BFDF */   ld        $31, 0x30($29)
  .L003ED3E4:
    /* 2ED3E4 003ED3E4 12000010 */  b          .L003ED430
    /* 2ED3E8 003ED3E8 2D100000 */   daddu     $2, $0, $0
  .L003ED3EC:
    /* 2ED3EC 003ED3EC DCA80F0C */  jal        func_003ea370
    /* 2ED3F0 003ED3F0 2D202002 */   daddu     $4, $17, $0
    /* 2ED3F4 003ED3F4 0E000010 */  b          .L003ED430
    /* 2ED3F8 003ED3F8 2D100000 */   daddu     $2, $0, $0
  .L003ED3FC:
    /* 2ED3FC 003ED3FC 44A90F0C */  jal        func_003ea510
    /* 2ED400 003ED400 2D202002 */   daddu     $4, $17, $0
    /* 2ED404 003ED404 DCA80F0C */  jal        func_003ea370
    /* 2ED408 003ED408 2D202002 */   daddu     $4, $17, $0
    /* 2ED40C 003ED40C 08000010 */  b          .L003ED430
    /* 2ED410 003ED410 2D100000 */   daddu     $2, $0, $0
  .L003ED414:
    /* 2ED414 003ED414 DCA80F0C */  jal        func_003ea370
    /* 2ED418 003ED418 2D200002 */   daddu     $4, $16, $0
    /* 2ED41C 003ED41C 44A90F0C */  jal        func_003ea510
    /* 2ED420 003ED420 2D202002 */   daddu     $4, $17, $0
    /* 2ED424 003ED424 DCA80F0C */  jal        func_003ea370
    /* 2ED428 003ED428 2D202002 */   daddu     $4, $17, $0
    /* 2ED42C 003ED42C 2D100000 */  daddu      $2, $0, $0
  .L003ED430:
    /* 2ED430 003ED430 3000BFDF */  ld         $31, 0x30($29)
  .L003ED434:
    /* 2ED434 003ED434 2000B27B */  lq         $18, 0x20($29)
    /* 2ED438 003ED438 1000B17B */  lq         $17, 0x10($29)
    /* 2ED43C 003ED43C 0000B07B */  lq         $16, 0x0($29)
    /* 2ED440 003ED440 0800E003 */  jr         $31
    /* 2ED444 003ED444 4000BD27 */   addiu     $29, $29, 0x40
    /* 2ED448 003ED448 00000000 */  nop
    /* 2ED44C 003ED44C 00000000 */  nop
.size func_003ed2d0, 0x180
