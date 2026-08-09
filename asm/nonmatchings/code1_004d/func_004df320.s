.section .text
.set noat
.set noreorder
glabel func_004df320
    /* 3DF320 004DF320 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3DF324 004DF324 0000B0FF */  sd         $16, 0x0($29)
    /* 3DF328 004DF328 2D808000 */  daddu      $16, $4, $0
    /* 3DF32C 004DF32C 06000016 */  bnez       $16, .L004DF348
    /* 3DF330 004DF330 0800BFFF */   sd        $31, 0x8($29)
    /* 3DF334 004DF334 7600043C */  lui        $4, %hi(D_00759A50)
    /* 3DF338 004DF338 B078130C */  jal        func_004de2c0
    /* 3DF33C 004DF33C 509A8424 */   addiu     $4, $4, %lo(D_00759A50)
    /* 3DF340 004DF340 1B000010 */  b          .L004DF3B0
    /* 3DF344 004DF344 FFFF0224 */   addiu     $2, $0, -0x1
  .L004DF348:
    /* 3DF348 004DF348 01000292 */  lbu        $2, 0x1($16)
    /* 3DF34C 004DF34C FFFF4224 */  addiu      $2, $2, -0x1
    /* 3DF350 004DF350 0300422C */  sltiu      $2, $2, 0x3
    /* 3DF354 004DF354 16004050 */  beql       $2, $0, .L004DF3B0
    /* 3DF358 004DF358 2D100000 */   daddu     $2, $0, $0
    /* 3DF35C 004DF35C CA81130C */  jal        func_004e0728
    /* 3DF360 004DF360 0400048E */   lw        $4, 0x4($16)
    /* 3DF364 004DF364 06004010 */  beqz       $2, .L004DF380
    /* 3DF368 004DF368 01000324 */   addiu     $3, $0, 0x1
    /* 3DF36C 004DF36C 0A004310 */  beq        $2, $3, .L004DF398
    /* 3DF370 004DF370 2D100000 */   daddu     $2, $0, $0
    /* 3DF374 004DF374 0F000010 */  b          .L004DF3B4
    /* 3DF378 004DF378 0000B0DF */   ld        $16, 0x0($29)
    /* 3DF37C 004DF37C 00000000 */  nop
  .L004DF380:
    /* 3DF380 004DF380 0400048E */  lw         $4, 0x4($16)
    /* 3DF384 004DF384 0800BFDF */  ld         $31, 0x8($29)
    /* 3DF388 004DF388 0000B0DF */  ld         $16, 0x0($29)
    /* 3DF38C 004DF38C BC811308 */  j          func_004e06f0
    /* 3DF390 004DF390 1000BD27 */   addiu     $29, $29, 0x10
    /* 3DF394 004DF394 00000000 */  nop
  .L004DF398:
    /* 3DF398 004DF398 0C00048E */  lw         $4, 0xC($16)
    /* 3DF39C 004DF39C 0800BFDF */  ld         $31, 0x8($29)
    /* 3DF3A0 004DF3A0 0000B0DF */  ld         $16, 0x0($29)
    /* 3DF3A4 004DF3A4 D2521308 */  j          func_004d4b48
    /* 3DF3A8 004DF3A8 1000BD27 */   addiu     $29, $29, 0x10
    /* 3DF3AC 004DF3AC 00000000 */  nop
  .L004DF3B0:
    /* 3DF3B0 004DF3B0 0000B0DF */  ld         $16, 0x0($29)
  .L004DF3B4:
    /* 3DF3B4 004DF3B4 0800BFDF */  ld         $31, 0x8($29)
    /* 3DF3B8 004DF3B8 0800E003 */  jr         $31
    /* 3DF3BC 004DF3BC 1000BD27 */   addiu     $29, $29, 0x10
.size func_004df320, 0xa0
