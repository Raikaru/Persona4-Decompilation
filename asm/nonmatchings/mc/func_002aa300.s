.section .text
.set noat
.set noreorder
glabel func_002aa300
    /* 1AA300 002AA300 C0FFBD27 */  addiu      $29, $29, -0x40
    /* 1AA304 002AA304 3000BFFF */  sd         $31, 0x30($29)
    /* 1AA308 002AA308 2000B27F */  sq         $18, 0x20($29)
    /* 1AA30C 002AA30C 1000B17F */  sq         $17, 0x10($29)
    /* 1AA310 002AA310 0000B07F */  sq         $16, 0x0($29)
    /* 1AA314 002AA314 2D908000 */  daddu      $18, $4, $0
    /* 1AA318 002AA318 2D88A000 */  daddu      $17, $5, $0
    /* 1AA31C 002AA31C 44B580AF */  sw         $0, -0x4ABC($28)
    /* 1AA320 002AA320 08A88427 */  addiu      $4, $28, -0x57F8
    /* 1AA324 002AA324 FF080524 */  addiu      $5, $0, 0x8FF
    /* 1AA328 002AA328 A43A110C */  jal        func_0044ea90
    /* 1AA32C 002AA32C 00000000 */   nop
    /* 1AA330 002AA330 01000424 */  addiu      $4, $0, 0x1
    /* 1AA334 002AA334 6C050524 */  addiu      $5, $0, 0x56C
    /* 1AA338 002AA338 0400063C */  lui        $6, (0x40000 >> 16)
    /* 1AA33C 002AA33C 8800023C */  lui        $2, %hi(D_008873F4)
    /* 1AA340 002AA340 F473428C */  lw         $2, %lo(D_008873F4)($2)
    /* 1AA344 002AA344 09F84000 */  jalr       $2
    /* 1AA348 002AA348 00000000 */   nop
    /* 1AA34C 002AA34C 2D804000 */  daddu      $16, $2, $0
    /* 1AA350 002AA350 05000016 */  bnez       $16, .L002AA368
    /* 1AA354 002AA354 00000000 */   nop
    /* 1AA358 002AA358 08A88427 */  addiu      $4, $28, -0x57F8
    /* 1AA35C 002AA35C E8000524 */  addiu      $5, $0, 0xE8
    /* 1AA360 002AA360 CCB5110C */  jal        func_0046d730
    /* 1AA364 002AA364 00000000 */   nop
  .L002AA368:
    /* 1AA368 002AA368 48B5828F */  lw         $2, -0x4AB8($28)
    /* 1AA36C 002AA36C AC0302AE */  sw         $2, 0x3AC($16)
    /* 1AA370 002AA370 48B5828F */  lw         $2, -0x4AB8($28)
    /* 1AA374 002AA374 00140200 */  sll        $2, $2, 16
    /* 1AA378 002AA378 B40302AE */  sw         $2, 0x3B4($16)
    /* 1AA37C 002AA37C 000000A6 */  sh         $0, 0x0($16)
    /* 1AA380 002AA380 020000A6 */  sh         $0, 0x2($16)
    /* 1AA384 002AA384 01000224 */  addiu      $2, $0, 0x1
    /* 1AA388 002AA388 04002216 */  bne        $17, $2, .L002AA39C
    /* 1AA38C 002AA38C 00000000 */   nop
    /* 1AA390 002AA390 0400028E */  lw         $2, 0x4($16)
    /* 1AA394 002AA394 02004234 */  ori        $2, $2, 0x2
    /* 1AA398 002AA398 040002AE */  sw         $2, 0x4($16)
  .L002AA39C:
    /* 1AA39C 002AA39C 2D204002 */  daddu      $4, $18, $0
    /* 1AA3A0 002AA3A0 28A88527 */  addiu      $5, $28, -0x57D8
    /* 1AA3A4 002AA3A4 0F000624 */  addiu      $6, $0, 0xF
    /* 1AA3A8 002AA3A8 2D380000 */  daddu      $7, $0, $0
    /* 1AA3AC 002AA3AC 2D400000 */  daddu      $8, $0, $0
    /* 1AA3B0 002AA3B0 2A00093C */  lui        $9, %hi(func_002a4b10)
    /* 1AA3B4 002AA3B4 104B2925 */  addiu      $9, $9, %lo(func_002a4b10)
    /* 1AA3B8 002AA3B8 2A000A3C */  lui        $10, %hi(func_002a4cb0)
    /* 1AA3BC 002AA3BC B04C4A25 */  addiu      $10, $10, %lo(func_002a4cb0)
    /* 1AA3C0 002AA3C0 2D580002 */  daddu      $11, $16, $0
    /* 1AA3C4 002AA3C4 F047110C */  jal        func_00451fc0
    /* 1AA3C8 002AA3C8 00000000 */   nop
    /* 1AA3CC 002AA3CC 3000BFDF */  ld         $31, 0x30($29)
    /* 1AA3D0 002AA3D0 2000B27B */  lq         $18, 0x20($29)
    /* 1AA3D4 002AA3D4 1000B17B */  lq         $17, 0x10($29)
    /* 1AA3D8 002AA3D8 0000B07B */  lq         $16, 0x0($29)
    /* 1AA3DC 002AA3DC 4000BD27 */  addiu      $29, $29, 0x40
    /* 1AA3E0 002AA3E0 0800E003 */  jr         $31
    /* 1AA3E4 002AA3E4 00000000 */   nop
    /* 1AA3E8 002AA3E8 00000000 */  nop
    /* 1AA3EC 002AA3EC 00000000 */  nop
.size func_002aa300, 0xf0
