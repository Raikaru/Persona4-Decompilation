.section .text
.set noat
.set noreorder
glabel func_004de3f0
    /* 3DE3F0 004DE3F0 D0FFBD27 */  addiu      $29, $29, -0x30
    /* 3DE3F4 004DE3F4 7300033C */  lui        $3, %hi(D_0072ACB4)
    /* 3DE3F8 004DE3F8 0000B0FF */  sd         $16, 0x0($29)
    /* 3DE3FC 004DE3FC B4AC6324 */  addiu      $3, $3, %lo(D_0072ACB4)
    /* 3DE400 004DE400 0800B1FF */  sd         $17, 0x8($29)
    /* 3DE404 004DE404 1000B2FF */  sd         $18, 0x10($29)
    /* 3DE408 004DE408 1800B3FF */  sd         $19, 0x18($29)
    /* 3DE40C 004DE40C 2000BFFF */  sd         $31, 0x20($29)
    /* 3DE410 004DE410 0000628C */  lw         $2, 0x0($3)
    /* 3DE414 004DE414 FFFF4224 */  addiu      $2, $2, -0x1
    /* 3DE418 004DE418 21004014 */  bnez       $2, .L004DE4A0
    /* 3DE41C 004DE41C 000062AC */   sw        $2, 0x0($3)
    /* 3DE420 004DE420 7300133C */  lui        $19, %hi(D_0072ACC8)
    /* 3DE424 004DE424 01001224 */  addiu      $18, $0, 0x1
    /* 3DE428 004DE428 C8AC7026 */  addiu      $16, $19, %lo(D_0072ACC8)
    /* 3DE42C 004DE42C 03001124 */  addiu      $17, $0, 0x3
  .L004DE430:
    /* 3DE430 004DE430 00000282 */  lb         $2, 0x0($16)
    /* 3DE434 004DE434 04005254 */  bnel       $2, $18, .L004DE448
    /* 3DE438 004DE438 FFFF3126 */   addiu     $17, $17, -0x1
    /* 3DE43C 004DE43C 187A130C */  jal        func_004de860
    /* 3DE440 004DE440 2D200002 */   daddu     $4, $16, $0
    /* 3DE444 004DE444 FFFF3126 */  addiu      $17, $17, -0x1
  .L004DE448:
    /* 3DE448 004DE448 F9FF2106 */  bgez       $17, .L004DE430
    /* 3DE44C 004DE44C 6C021026 */   addiu     $16, $16, 0x26C
    /* 3DE450 004DE450 B0090624 */  addiu      $6, $0, 0x9B0
    /* 3DE454 004DE454 C8AC6426 */  addiu      $4, $19, %lo(D_0072ACC8)
    /* 3DE458 004DE458 72FE100C */  jal        func_0043f9c8
    /* 3DE45C 004DE45C 2D280000 */   daddu     $5, $0, $0
    /* 3DE460 004DE460 02000424 */  addiu      $4, $0, 0x2
    /* 3DE464 004DE464 E2C2130C */  jal        func_004f0b88
    /* 3DE468 004DE468 2D280000 */   daddu     $5, $0, $0
    /* 3DE46C 004DE46C 7300023C */  lui        $2, %hi(D_0072ACB8)
    /* 3DE470 004DE470 B8AC458C */  lw         $5, %lo(D_0072ACB8)($2)
    /* 3DE474 004DE474 E2C2130C */  jal        func_004f0b88
    /* 3DE478 004DE478 05000424 */   addiu     $4, $0, 0x5
    /* 3DE47C 004DE47C 0281130C */  jal        func_004e0408
    /* 3DE480 004DE480 00000000 */   nop
    /* 3DE484 004DE484 0000B0DF */  ld         $16, 0x0($29)
    /* 3DE488 004DE488 0800B1DF */  ld         $17, 0x8($29)
    /* 3DE48C 004DE48C 1000B2DF */  ld         $18, 0x10($29)
    /* 3DE490 004DE490 1800B3DF */  ld         $19, 0x18($29)
    /* 3DE494 004DE494 2000BFDF */  ld         $31, 0x20($29)
    /* 3DE498 004DE498 2C2A1308 */  j          func_004ca8b0
    /* 3DE49C 004DE49C 3000BD27 */   addiu     $29, $29, 0x30
  .L004DE4A0:
    /* 3DE4A0 004DE4A0 0000B0DF */  ld         $16, 0x0($29)
    /* 3DE4A4 004DE4A4 0800B1DF */  ld         $17, 0x8($29)
    /* 3DE4A8 004DE4A8 1000B2DF */  ld         $18, 0x10($29)
    /* 3DE4AC 004DE4AC 1800B3DF */  ld         $19, 0x18($29)
    /* 3DE4B0 004DE4B0 2000BFDF */  ld         $31, 0x20($29)
    /* 3DE4B4 004DE4B4 0800E003 */  jr         $31
    /* 3DE4B8 004DE4B8 3000BD27 */   addiu     $29, $29, 0x30
    /* 3DE4BC 004DE4BC 00000000 */  nop
.size func_004de3f0, 0xd0
