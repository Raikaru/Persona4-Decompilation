.section .text
.set noat
.set noreorder
glabel func_002eb270
    /* 1EB270 002EB270 20FDBD27 */  addiu      $29, $29, -0x2E0
    /* 1EB274 002EB274 A000BFFF */  sd         $31, 0xA0($29)
    /* 1EB278 002EB278 9000BE7F */  sq         $30, 0x90($29)
    /* 1EB27C 002EB27C 8000B77F */  sq         $23, 0x80($29)
    /* 1EB280 002EB280 7000B67F */  sq         $22, 0x70($29)
    /* 1EB284 002EB284 6000B57F */  sq         $21, 0x60($29)
    /* 1EB288 002EB288 5000B47F */  sq         $20, 0x50($29)
    /* 1EB28C 002EB28C 4000B37F */  sq         $19, 0x40($29)
    /* 1EB290 002EB290 3000B27F */  sq         $18, 0x30($29)
    /* 1EB294 002EB294 2000B17F */  sq         $17, 0x20($29)
    /* 1EB298 002EB298 1000B07F */  sq         $16, 0x10($29)
    /* 1EB29C 002EB29C 0000B4E7 */  swc1       $f20, 0x0($29)
    /* 1EB2A0 002EB2A0 2DA88000 */  daddu      $21, $4, $0
    /* 1EB2A4 002EB2A4 2DB8A000 */  daddu      $23, $5, $0
    /* 1EB2A8 002EB2A8 3800938C */  lw         $19, 0x38($4)
    /* 1EB2AC 002EB2AC B5006482 */  lb         $4, 0xB5($19)
    /* 1EB2B0 002EB2B0 01008330 */  andi       $3, $4, 0x1
    /* 1EB2B4 002EB2B4 04008104 */  bgez       $4, .L002EB2C8
    /* 1EB2B8 002EB2B8 00000000 */   nop
    /* 1EB2BC 002EB2BC 02006010 */  beqz       $3, .L002EB2C8
    /* 1EB2C0 002EB2C0 00000000 */   nop
    /* 1EB2C4 002EB2C4 FEFF6324 */  addiu      $3, $3, -0x2
  .L002EB2C8:
    /* 1EB2C8 002EB2C8 C6026014 */  bnez       $3, .L002EBDE4
    /* 1EB2CC 002EB2CC 00000000 */   nop
    /* 1EB2D0 002EB2D0 06000324 */  addiu      $3, $0, 0x6
    /* 1EB2D4 002EB2D4 78018314 */  bne        $4, $3, .L002EB8B8
    /* 1EB2D8 002EB2D8 00000000 */   nop
    /* 1EB2DC 002EB2DC 2D900000 */  daddu      $18, $0, $0
    /* 1EB2E0 002EB2E0 3C8E1700 */  dsll32     $17, $23, 24
    /* 1EB2E4 002EB2E4 3F8E1100 */  dsra32     $17, $17, 24
    /* 1EB2E8 002EB2E8 6B000010 */  b          .L002EB498
    /* 1EB2EC 002EB2EC 00000000 */   nop
  .L002EB2F0:
    /* 1EB2F0 002EB2F0 01008326 */  addiu      $3, $20, 0x1
    /* 1EB2F4 002EB2F4 40100300 */  sll        $2, $3, 1
    /* 1EB2F8 002EB2F8 21104300 */  addu       $2, $2, $3
    /* 1EB2FC 002EB2FC 80180200 */  sll        $3, $2, 2
    /* 1EB300 002EB300 6400023C */  lui        $2, %hi(D_00640760)
    /* 1EB304 002EB304 60074224 */  addiu      $2, $2, %lo(D_00640760)
    /* 1EB308 002EB308 21804300 */  addu       $16, $2, $3
    /* 1EB30C 002EB30C 34002016 */  bnez       $17, .L002EB3E0
    /* 1EB310 002EB310 00000000 */   nop
    /* 1EB314 002EB314 3CA41200 */  dsll32     $20, $18, 16
    /* 1EB318 002EB318 3FA41400 */  dsra32     $20, $20, 16
    /* 1EB31C 002EB31C 48C3023C */  lui        $2, (0xC3480000 >> 16)
    /* 1EB320 002EB320 00608244 */  mtc1       $2, $f12
    /* 1EB324 002EB324 040001C6 */  lwc1       $f1, 0x4($16)
    /* 1EB328 002EB328 C842023C */  lui        $2, (0x42C80000 >> 16)
    /* 1EB32C 002EB32C 00008244 */  mtc1       $2, $f0
    /* 1EB330 002EB330 00000000 */  nop
    /* 1EB334 002EB334 40030146 */  add.s      $f13, $f0, $f1
    /* 1EB338 002EB338 D802A427 */  addiu      $4, $29, 0x2D8
    /* 1EB33C 002EB33C 5CCA0A0C */  jal        func_002b2970
    /* 1EB340 002EB340 00000000 */   nop
    /* 1EB344 002EB344 D002A427 */  addiu      $4, $29, 0x2D0
    /* 1EB348 002EB348 00000CC6 */  lwc1       $f12, 0x0($16)
    /* 1EB34C 002EB34C 04000DC6 */  lwc1       $f13, 0x4($16)
    /* 1EB350 002EB350 5CCA0A0C */  jal        func_002b2970
    /* 1EB354 002EB354 00000000 */   nop
    /* 1EB358 002EB358 3C3E1200 */  dsll32     $7, $18, 24
    /* 1EB35C 002EB35C 3F3E0700 */  dsra32     $7, $7, 24
    /* 1EB360 002EB360 80101400 */  sll        $2, $20, 2
    /* 1EB364 002EB364 3C440200 */  dsll32     $8, $2, 16
    /* 1EB368 002EB368 3F440800 */  dsra32     $8, $8, 16
    /* 1EB36C 002EB36C 08000386 */  lh         $3, 0x8($16)
    /* 1EB370 002EB370 40100300 */  sll        $2, $3, 1
    /* 1EB374 002EB374 21104300 */  addu       $2, $2, $3
    /* 1EB378 002EB378 3E004224 */  addiu      $2, $2, 0x3E
    /* 1EB37C 002EB37C 3C4C0200 */  dsll32     $9, $2, 16
    /* 1EB380 002EB380 3F4C0900 */  dsra32     $9, $9, 16
    /* 1EB384 002EB384 0A000286 */  lh         $2, 0xA($16)
    /* 1EB388 002EB388 57004224 */  addiu      $2, $2, 0x57
    /* 1EB38C 002EB38C 3C540200 */  dsll32     $10, $2, 16
    /* 1EB390 002EB390 3F540A00 */  dsra32     $10, $10, 16
    /* 1EB394 002EB394 2D20A002 */  daddu      $4, $21, $0
    /* 1EB398 002EB398 D802A5DF */  ld         $5, 0x2D8($29)
    /* 1EB39C 002EB39C D002A6DF */  ld         $6, 0x2D0($29)
    /* 1EB3A0 002EB3A0 405E0C0C */  jal        func_00317900
    /* 1EB3A4 002EB3A4 00000000 */   nop
    /* 1EB3A8 002EB3A8 80101400 */  sll        $2, $20, 2
    /* 1EB3AC 002EB3AC 21105400 */  addu       $2, $2, $20
    /* 1EB3B0 002EB3B0 40100200 */  sll        $2, $2, 1
    /* 1EB3B4 002EB3B4 21206202 */  addu       $4, $19, $2
    /* 1EB3B8 002EB3B8 08000386 */  lh         $3, 0x8($16)
    /* 1EB3BC 002EB3BC 40100300 */  sll        $2, $3, 1
    /* 1EB3C0 002EB3C0 21104300 */  addu       $2, $2, $3
    /* 1EB3C4 002EB3C4 3E004224 */  addiu      $2, $2, 0x3E
    /* 1EB3C8 002EB3C8 CA0082A4 */  sh         $2, 0xCA($4)
    /* 1EB3CC 002EB3CC 0A000286 */  lh         $2, 0xA($16)
    /* 1EB3D0 002EB3D0 57004224 */  addiu      $2, $2, 0x57
    /* 1EB3D4 002EB3D4 CC0082A4 */  sh         $2, 0xCC($4)
    /* 1EB3D8 002EB3D8 2C000010 */  b          .L002EB48C
    /* 1EB3DC 002EB3DC 00000000 */   nop
  .L002EB3E0:
    /* 1EB3E0 002EB3E0 18DC0E0C */  jal        func_003b7060
    /* 1EB3E4 002EB3E4 00000000 */   nop
    /* 1EB3E8 002EB3E8 2C010324 */  addiu      $3, $0, 0x12C
    /* 1EB3EC 002EB3EC 1B004300 */  divu       $0, $2, $3
    /* 1EB3F0 002EB3F0 10100000 */  mfhi       $2
    /* 1EB3F4 002EB3F4 6AFF4224 */  addiu      $2, $2, -0x96
    /* 1EB3F8 002EB3F8 3CB40200 */  dsll32     $22, $2, 16
    /* 1EB3FC 002EB3FC 3FB41600 */  dsra32     $22, $22, 16
    /* 1EB400 002EB400 C802A427 */  addiu      $4, $29, 0x2C8
    /* 1EB404 002EB404 00000CC6 */  lwc1       $f12, 0x0($16)
    /* 1EB408 002EB408 04000DC6 */  lwc1       $f13, 0x4($16)
    /* 1EB40C 002EB40C 5CCA0A0C */  jal        func_002b2970
    /* 1EB410 002EB410 00000000 */   nop
    /* 1EB414 002EB414 040001C6 */  lwc1       $f1, 0x4($16)
    /* 1EB418 002EB418 00009644 */  mtc1       $22, $f0
    /* 1EB41C 002EB41C 00000000 */  nop
    /* 1EB420 002EB420 20008046 */  cvt.s.w    $f0, $f0
    /* 1EB424 002EB424 400B0046 */  add.s      $f13, $f1, $f0
    /* 1EB428 002EB428 96C3023C */  lui        $2, (0xC3960000 >> 16)
    /* 1EB42C 002EB42C 00608244 */  mtc1       $2, $f12
    /* 1EB430 002EB430 C002A427 */  addiu      $4, $29, 0x2C0
    /* 1EB434 002EB434 5CCA0A0C */  jal        func_002b2970
    /* 1EB438 002EB438 00000000 */   nop
    /* 1EB43C 002EB43C 3C3E1200 */  dsll32     $7, $18, 24
    /* 1EB440 002EB440 3F3E0700 */  dsra32     $7, $7, 24
    /* 1EB444 002EB444 40101400 */  sll        $2, $20, 1
    /* 1EB448 002EB448 3C440200 */  dsll32     $8, $2, 16
    /* 1EB44C 002EB44C 3F440800 */  dsra32     $8, $8, 16
    /* 1EB450 002EB450 08000386 */  lh         $3, 0x8($16)
    /* 1EB454 002EB454 40100300 */  sll        $2, $3, 1
    /* 1EB458 002EB458 21104300 */  addu       $2, $2, $3
    /* 1EB45C 002EB45C 3E004224 */  addiu      $2, $2, 0x3E
    /* 1EB460 002EB460 3C4C0200 */  dsll32     $9, $2, 16
    /* 1EB464 002EB464 3F4C0900 */  dsra32     $9, $9, 16
    /* 1EB468 002EB468 0A000286 */  lh         $2, 0xA($16)
    /* 1EB46C 002EB46C 57004224 */  addiu      $2, $2, 0x57
    /* 1EB470 002EB470 3C540200 */  dsll32     $10, $2, 16
    /* 1EB474 002EB474 3F540A00 */  dsra32     $10, $10, 16
    /* 1EB478 002EB478 2D20A002 */  daddu      $4, $21, $0
    /* 1EB47C 002EB47C C802A5DF */  ld         $5, 0x2C8($29)
    /* 1EB480 002EB480 C002A6DF */  ld         $6, 0x2C0($29)
    /* 1EB484 002EB484 405E0C0C */  jal        func_00317900
    /* 1EB488 002EB488 00000000 */   nop
  .L002EB48C:
    /* 1EB48C 002EB48C 01004226 */  addiu      $2, $18, 0x1
    /* 1EB490 002EB490 3C940200 */  dsll32     $18, $2, 16
    /* 1EB494 002EB494 3F941200 */  dsra32     $18, $18, 16
  .L002EB498:
    /* 1EB498 002EB498 3CA41200 */  dsll32     $20, $18, 16
    /* 1EB49C 002EB49C 3FA41400 */  dsra32     $20, $20, 16
    /* 1EB4A0 002EB4A0 0300822A */  slti       $2, $20, 0x3
    /* 1EB4A4 002EB4A4 92FF4014 */  bnez       $2, .L002EB2F0
    /* 1EB4A8 002EB4A8 00000000 */   nop
    /* 1EB4AC 002EB4AC 6400123C */  lui        $18, %hi(D_006407A8)
    /* 1EB4B0 002EB4B0 A8075226 */  addiu      $18, $18, %lo(D_006407A8)
    /* 1EB4B4 002EB4B4 2C002016 */  bnez       $17, .L002EB568
    /* 1EB4B8 002EB4B8 00000000 */   nop
    /* 1EB4BC 002EB4BC 2F44023C */  lui        $2, (0x442F0000 >> 16)
    /* 1EB4C0 002EB4C0 00A08244 */  mtc1       $2, $f20
    /* 1EB4C4 002EB4C4 040041C6 */  lwc1       $f1, 0x4($18)
    /* 1EB4C8 002EB4C8 C842023C */  lui        $2, (0x42C80000 >> 16)
    /* 1EB4CC 002EB4CC 00008244 */  mtc1       $2, $f0
    /* 1EB4D0 002EB4D0 00000000 */  nop
    /* 1EB4D4 002EB4D4 40030146 */  add.s      $f13, $f0, $f1
    /* 1EB4D8 002EB4D8 B802A427 */  addiu      $4, $29, 0x2B8
    /* 1EB4DC 002EB4DC 06A30046 */  mov.s      $f12, $f20
    /* 1EB4E0 002EB4E0 5CCA0A0C */  jal        func_002b2970
    /* 1EB4E4 002EB4E4 00000000 */   nop
    /* 1EB4E8 002EB4E8 B002A427 */  addiu      $4, $29, 0x2B0
    /* 1EB4EC 002EB4EC 00004CC6 */  lwc1       $f12, 0x0($18)
    /* 1EB4F0 002EB4F0 04004DC6 */  lwc1       $f13, 0x4($18)
    /* 1EB4F4 002EB4F4 5CCA0A0C */  jal        func_002b2970
    /* 1EB4F8 002EB4F8 00000000 */   nop
    /* 1EB4FC 002EB4FC 08004386 */  lh         $3, 0x8($18)
    /* 1EB500 002EB500 40100300 */  sll        $2, $3, 1
    /* 1EB504 002EB504 21104300 */  addu       $2, $2, $3
    /* 1EB508 002EB508 3E004224 */  addiu      $2, $2, 0x3E
    /* 1EB50C 002EB50C 3C4C0200 */  dsll32     $9, $2, 16
    /* 1EB510 002EB510 3F4C0900 */  dsra32     $9, $9, 16
    /* 1EB514 002EB514 0A004286 */  lh         $2, 0xA($18)
    /* 1EB518 002EB518 57004224 */  addiu      $2, $2, 0x57
    /* 1EB51C 002EB51C 3C540200 */  dsll32     $10, $2, 16
    /* 1EB520 002EB520 3F540A00 */  dsra32     $10, $10, 16
    /* 1EB524 002EB524 2D20A002 */  daddu      $4, $21, $0
    /* 1EB528 002EB528 B802A5DF */  ld         $5, 0x2B8($29)
    /* 1EB52C 002EB52C B002A6DF */  ld         $6, 0x2B0($29)
    /* 1EB530 002EB530 08000724 */  addiu      $7, $0, 0x8
    /* 1EB534 002EB534 02000824 */  addiu      $8, $0, 0x2
    /* 1EB538 002EB538 405E0C0C */  jal        func_00317900
    /* 1EB53C 002EB53C 00000000 */   nop
    /* 1EB540 002EB540 08004386 */  lh         $3, 0x8($18)
    /* 1EB544 002EB544 40100300 */  sll        $2, $3, 1
    /* 1EB548 002EB548 21104300 */  addu       $2, $2, $3
    /* 1EB54C 002EB54C 3E004224 */  addiu      $2, $2, 0x3E
    /* 1EB550 002EB550 FC0062A6 */  sh         $2, 0xFC($19)
    /* 1EB554 002EB554 0A004286 */  lh         $2, 0xA($18)
    /* 1EB558 002EB558 57004224 */  addiu      $2, $2, 0x57
    /* 1EB55C 002EB55C FE0062A6 */  sh         $2, 0xFE($19)
    /* 1EB560 002EB560 2B000010 */  b          .L002EB610
    /* 1EB564 002EB564 00000000 */   nop
  .L002EB568:
    /* 1EB568 002EB568 18DC0E0C */  jal        func_003b7060
    /* 1EB56C 002EB56C 00000000 */   nop
    /* 1EB570 002EB570 2C010324 */  addiu      $3, $0, 0x12C
    /* 1EB574 002EB574 1B004300 */  divu       $0, $2, $3
    /* 1EB578 002EB578 10100000 */  mfhi       $2
    /* 1EB57C 002EB57C 6AFF4224 */  addiu      $2, $2, -0x96
    /* 1EB580 002EB580 3C840200 */  dsll32     $16, $2, 16
    /* 1EB584 002EB584 3F841000 */  dsra32     $16, $16, 16
    /* 1EB588 002EB588 2F44023C */  lui        $2, (0x442F0000 >> 16)
    /* 1EB58C 002EB58C 00A08244 */  mtc1       $2, $f20
    /* 1EB590 002EB590 A802A427 */  addiu      $4, $29, 0x2A8
    /* 1EB594 002EB594 00004CC6 */  lwc1       $f12, 0x0($18)
    /* 1EB598 002EB598 04004DC6 */  lwc1       $f13, 0x4($18)
    /* 1EB59C 002EB59C 5CCA0A0C */  jal        func_002b2970
    /* 1EB5A0 002EB5A0 00000000 */   nop
    /* 1EB5A4 002EB5A4 040041C6 */  lwc1       $f1, 0x4($18)
    /* 1EB5A8 002EB5A8 00009044 */  mtc1       $16, $f0
    /* 1EB5AC 002EB5AC 00000000 */  nop
    /* 1EB5B0 002EB5B0 20008046 */  cvt.s.w    $f0, $f0
    /* 1EB5B4 002EB5B4 400B0046 */  add.s      $f13, $f1, $f0
    /* 1EB5B8 002EB5B8 2F44023C */  lui        $2, (0x442F0000 >> 16)
    /* 1EB5BC 002EB5BC 00608244 */  mtc1       $2, $f12
    /* 1EB5C0 002EB5C0 A002A427 */  addiu      $4, $29, 0x2A0
    /* 1EB5C4 002EB5C4 5CCA0A0C */  jal        func_002b2970
    /* 1EB5C8 002EB5C8 00000000 */   nop
    /* 1EB5CC 002EB5CC 08004386 */  lh         $3, 0x8($18)
    /* 1EB5D0 002EB5D0 40100300 */  sll        $2, $3, 1
    /* 1EB5D4 002EB5D4 21104300 */  addu       $2, $2, $3
    /* 1EB5D8 002EB5D8 3E004224 */  addiu      $2, $2, 0x3E
    /* 1EB5DC 002EB5DC 3C4C0200 */  dsll32     $9, $2, 16
    /* 1EB5E0 002EB5E0 3F4C0900 */  dsra32     $9, $9, 16
    /* 1EB5E4 002EB5E4 0A004286 */  lh         $2, 0xA($18)
    /* 1EB5E8 002EB5E8 57004224 */  addiu      $2, $2, 0x57
    /* 1EB5EC 002EB5EC 3C540200 */  dsll32     $10, $2, 16
    /* 1EB5F0 002EB5F0 3F540A00 */  dsra32     $10, $10, 16
    /* 1EB5F4 002EB5F4 2D20A002 */  daddu      $4, $21, $0
    /* 1EB5F8 002EB5F8 A802A5DF */  ld         $5, 0x2A8($29)
    /* 1EB5FC 002EB5FC A002A6DF */  ld         $6, 0x2A0($29)
    /* 1EB600 002EB600 08000724 */  addiu      $7, $0, 0x8
    /* 1EB604 002EB604 01000824 */  addiu      $8, $0, 0x1
    /* 1EB608 002EB608 405E0C0C */  jal        func_00317900
    /* 1EB60C 002EB60C 00000000 */   nop
  .L002EB610:
    /* 1EB610 002EB610 6400103C */  lui        $16, %hi(D_0064079C)
    /* 1EB614 002EB614 9C071026 */  addiu      $16, $16, %lo(D_0064079C)
    /* 1EB618 002EB618 2A002016 */  bnez       $17, .L002EB6C4
    /* 1EB61C 002EB61C 00000000 */   nop
    /* 1EB620 002EB620 040001C6 */  lwc1       $f1, 0x4($16)
    /* 1EB624 002EB624 C842023C */  lui        $2, (0x42C80000 >> 16)
    /* 1EB628 002EB628 00008244 */  mtc1       $2, $f0
    /* 1EB62C 002EB62C 00000000 */  nop
    /* 1EB630 002EB630 40030146 */  add.s      $f13, $f0, $f1
    /* 1EB634 002EB634 9802A427 */  addiu      $4, $29, 0x298
    /* 1EB638 002EB638 06A30046 */  mov.s      $f12, $f20
    /* 1EB63C 002EB63C 5CCA0A0C */  jal        func_002b2970
    /* 1EB640 002EB640 00000000 */   nop
    /* 1EB644 002EB644 9002A427 */  addiu      $4, $29, 0x290
    /* 1EB648 002EB648 00000CC6 */  lwc1       $f12, 0x0($16)
    /* 1EB64C 002EB64C 04000DC6 */  lwc1       $f13, 0x4($16)
    /* 1EB650 002EB650 5CCA0A0C */  jal        func_002b2970
    /* 1EB654 002EB654 00000000 */   nop
    /* 1EB658 002EB658 08000386 */  lh         $3, 0x8($16)
    /* 1EB65C 002EB65C 40100300 */  sll        $2, $3, 1
    /* 1EB660 002EB660 21104300 */  addu       $2, $2, $3
    /* 1EB664 002EB664 3E004224 */  addiu      $2, $2, 0x3E
    /* 1EB668 002EB668 3C4C0200 */  dsll32     $9, $2, 16
    /* 1EB66C 002EB66C 3F4C0900 */  dsra32     $9, $9, 16
    /* 1EB670 002EB670 0A000286 */  lh         $2, 0xA($16)
    /* 1EB674 002EB674 57004224 */  addiu      $2, $2, 0x57
    /* 1EB678 002EB678 3C540200 */  dsll32     $10, $2, 16
    /* 1EB67C 002EB67C 3F540A00 */  dsra32     $10, $10, 16
    /* 1EB680 002EB680 2D20A002 */  daddu      $4, $21, $0
    /* 1EB684 002EB684 9802A5DF */  ld         $5, 0x298($29)
    /* 1EB688 002EB688 9002A6DF */  ld         $6, 0x290($29)
    /* 1EB68C 002EB68C 07000724 */  addiu      $7, $0, 0x7
    /* 1EB690 002EB690 06000824 */  addiu      $8, $0, 0x6
    /* 1EB694 002EB694 405E0C0C */  jal        func_00317900
    /* 1EB698 002EB698 00000000 */   nop
    /* 1EB69C 002EB69C 08000386 */  lh         $3, 0x8($16)
    /* 1EB6A0 002EB6A0 40100300 */  sll        $2, $3, 1
    /* 1EB6A4 002EB6A4 21104300 */  addu       $2, $2, $3
    /* 1EB6A8 002EB6A8 3E004224 */  addiu      $2, $2, 0x3E
    /* 1EB6AC 002EB6AC F20062A6 */  sh         $2, 0xF2($19)
    /* 1EB6B0 002EB6B0 0A000286 */  lh         $2, 0xA($16)
    /* 1EB6B4 002EB6B4 57004224 */  addiu      $2, $2, 0x57
    /* 1EB6B8 002EB6B8 F40062A6 */  sh         $2, 0xF4($19)
    /* 1EB6BC 002EB6BC 28000010 */  b          .L002EB760
    /* 1EB6C0 002EB6C0 00000000 */   nop
  .L002EB6C4:
    /* 1EB6C4 002EB6C4 18DC0E0C */  jal        func_003b7060
    /* 1EB6C8 002EB6C8 00000000 */   nop
    /* 1EB6CC 002EB6CC 2C010324 */  addiu      $3, $0, 0x12C
    /* 1EB6D0 002EB6D0 1B004300 */  divu       $0, $2, $3
    /* 1EB6D4 002EB6D4 10100000 */  mfhi       $2
    /* 1EB6D8 002EB6D8 6AFF4224 */  addiu      $2, $2, -0x96
    /* 1EB6DC 002EB6DC 3C940200 */  dsll32     $18, $2, 16
    /* 1EB6E0 002EB6E0 3F941200 */  dsra32     $18, $18, 16
    /* 1EB6E4 002EB6E4 8802A427 */  addiu      $4, $29, 0x288
    /* 1EB6E8 002EB6E8 00000CC6 */  lwc1       $f12, 0x0($16)
    /* 1EB6EC 002EB6EC 04000DC6 */  lwc1       $f13, 0x4($16)
    /* 1EB6F0 002EB6F0 5CCA0A0C */  jal        func_002b2970
    /* 1EB6F4 002EB6F4 00000000 */   nop
    /* 1EB6F8 002EB6F8 040001C6 */  lwc1       $f1, 0x4($16)
    /* 1EB6FC 002EB6FC 00009244 */  mtc1       $18, $f0
    /* 1EB700 002EB700 00000000 */  nop
    /* 1EB704 002EB704 20008046 */  cvt.s.w    $f0, $f0
    /* 1EB708 002EB708 400B0046 */  add.s      $f13, $f1, $f0
    /* 1EB70C 002EB70C 8002A427 */  addiu      $4, $29, 0x280
    /* 1EB710 002EB710 06A30046 */  mov.s      $f12, $f20
    /* 1EB714 002EB714 5CCA0A0C */  jal        func_002b2970
    /* 1EB718 002EB718 00000000 */   nop
    /* 1EB71C 002EB71C 08000386 */  lh         $3, 0x8($16)
    /* 1EB720 002EB720 40100300 */  sll        $2, $3, 1
    /* 1EB724 002EB724 21104300 */  addu       $2, $2, $3
    /* 1EB728 002EB728 3E004224 */  addiu      $2, $2, 0x3E
    /* 1EB72C 002EB72C 3C4C0200 */  dsll32     $9, $2, 16
    /* 1EB730 002EB730 3F4C0900 */  dsra32     $9, $9, 16
    /* 1EB734 002EB734 0A000286 */  lh         $2, 0xA($16)
    /* 1EB738 002EB738 57004224 */  addiu      $2, $2, 0x57
    /* 1EB73C 002EB73C 3C540200 */  dsll32     $10, $2, 16
    /* 1EB740 002EB740 3F540A00 */  dsra32     $10, $10, 16
    /* 1EB744 002EB744 2D20A002 */  daddu      $4, $21, $0
    /* 1EB748 002EB748 8802A5DF */  ld         $5, 0x288($29)
    /* 1EB74C 002EB74C 8002A6DF */  ld         $6, 0x280($29)
    /* 1EB750 002EB750 07000724 */  addiu      $7, $0, 0x7
    /* 1EB754 002EB754 03000824 */  addiu      $8, $0, 0x3
    /* 1EB758 002EB758 405E0C0C */  jal        func_00317900
    /* 1EB75C 002EB75C 00000000 */   nop
  .L002EB760:
    /* 1EB760 002EB760 6400103C */  lui        $16, %hi(D_00640790)
    /* 1EB764 002EB764 90071026 */  addiu      $16, $16, %lo(D_00640790)
    /* 1EB768 002EB768 2A002016 */  bnez       $17, .L002EB814
    /* 1EB76C 002EB76C 00000000 */   nop
    /* 1EB770 002EB770 040001C6 */  lwc1       $f1, 0x4($16)
    /* 1EB774 002EB774 C842023C */  lui        $2, (0x42C80000 >> 16)
    /* 1EB778 002EB778 00008244 */  mtc1       $2, $f0
    /* 1EB77C 002EB77C 00000000 */  nop
    /* 1EB780 002EB780 40030146 */  add.s      $f13, $f0, $f1
    /* 1EB784 002EB784 7802A427 */  addiu      $4, $29, 0x278
    /* 1EB788 002EB788 06A30046 */  mov.s      $f12, $f20
    /* 1EB78C 002EB78C 5CCA0A0C */  jal        func_002b2970
    /* 1EB790 002EB790 00000000 */   nop
    /* 1EB794 002EB794 7002A427 */  addiu      $4, $29, 0x270
    /* 1EB798 002EB798 00000CC6 */  lwc1       $f12, 0x0($16)
    /* 1EB79C 002EB79C 04000DC6 */  lwc1       $f13, 0x4($16)
    /* 1EB7A0 002EB7A0 5CCA0A0C */  jal        func_002b2970
    /* 1EB7A4 002EB7A4 00000000 */   nop
    /* 1EB7A8 002EB7A8 08000386 */  lh         $3, 0x8($16)
    /* 1EB7AC 002EB7AC 40100300 */  sll        $2, $3, 1
    /* 1EB7B0 002EB7B0 21104300 */  addu       $2, $2, $3
    /* 1EB7B4 002EB7B4 3E004224 */  addiu      $2, $2, 0x3E
    /* 1EB7B8 002EB7B8 3C4C0200 */  dsll32     $9, $2, 16
    /* 1EB7BC 002EB7BC 3F4C0900 */  dsra32     $9, $9, 16
    /* 1EB7C0 002EB7C0 0A000286 */  lh         $2, 0xA($16)
    /* 1EB7C4 002EB7C4 57004224 */  addiu      $2, $2, 0x57
    /* 1EB7C8 002EB7C8 3C540200 */  dsll32     $10, $2, 16
    /* 1EB7CC 002EB7CC 3F540A00 */  dsra32     $10, $10, 16
    /* 1EB7D0 002EB7D0 2D20A002 */  daddu      $4, $21, $0
    /* 1EB7D4 002EB7D4 7802A5DF */  ld         $5, 0x278($29)
    /* 1EB7D8 002EB7D8 7002A6DF */  ld         $6, 0x270($29)
    /* 1EB7DC 002EB7DC 06000724 */  addiu      $7, $0, 0x6
    /* 1EB7E0 002EB7E0 0A000824 */  addiu      $8, $0, 0xA
    /* 1EB7E4 002EB7E4 405E0C0C */  jal        func_00317900
    /* 1EB7E8 002EB7E8 00000000 */   nop
    /* 1EB7EC 002EB7EC 08000486 */  lh         $4, 0x8($16)
    /* 1EB7F0 002EB7F0 40180400 */  sll        $3, $4, 1
    /* 1EB7F4 002EB7F4 21186400 */  addu       $3, $3, $4
    /* 1EB7F8 002EB7F8 3E006324 */  addiu      $3, $3, 0x3E
    /* 1EB7FC 002EB7FC E80063A6 */  sh         $3, 0xE8($19)
    /* 1EB800 002EB800 0A000386 */  lh         $3, 0xA($16)
    /* 1EB804 002EB804 57006324 */  addiu      $3, $3, 0x57
    /* 1EB808 002EB808 EA0063A6 */  sh         $3, 0xEA($19)
    /* 1EB80C 002EB80C AE050010 */  b          .L002ECEC8
    /* 1EB810 002EB810 00000000 */   nop
  .L002EB814:
    /* 1EB814 002EB814 18DC0E0C */  jal        func_003b7060
    /* 1EB818 002EB818 00000000 */   nop
    /* 1EB81C 002EB81C 2C010324 */  addiu      $3, $0, 0x12C
    /* 1EB820 002EB820 1B004300 */  divu       $0, $2, $3
    /* 1EB824 002EB824 10100000 */  mfhi       $2
    /* 1EB828 002EB828 6AFF4224 */  addiu      $2, $2, -0x96
    /* 1EB82C 002EB82C 3C8C0200 */  dsll32     $17, $2, 16
    /* 1EB830 002EB830 3F8C1100 */  dsra32     $17, $17, 16
    /* 1EB834 002EB834 6802A427 */  addiu      $4, $29, 0x268
    /* 1EB838 002EB838 00000CC6 */  lwc1       $f12, 0x0($16)
    /* 1EB83C 002EB83C 04000DC6 */  lwc1       $f13, 0x4($16)
    /* 1EB840 002EB840 5CCA0A0C */  jal        func_002b2970
    /* 1EB844 002EB844 00000000 */   nop
    /* 1EB848 002EB848 040001C6 */  lwc1       $f1, 0x4($16)
    /* 1EB84C 002EB84C 00009144 */  mtc1       $17, $f0
    /* 1EB850 002EB850 00000000 */  nop
    /* 1EB854 002EB854 20008046 */  cvt.s.w    $f0, $f0
    /* 1EB858 002EB858 400B0046 */  add.s      $f13, $f1, $f0
    /* 1EB85C 002EB85C 6002A427 */  addiu      $4, $29, 0x260
    /* 1EB860 002EB860 06A30046 */  mov.s      $f12, $f20
    /* 1EB864 002EB864 5CCA0A0C */  jal        func_002b2970
    /* 1EB868 002EB868 00000000 */   nop
    /* 1EB86C 002EB86C 08000386 */  lh         $3, 0x8($16)
    /* 1EB870 002EB870 40100300 */  sll        $2, $3, 1
    /* 1EB874 002EB874 21104300 */  addu       $2, $2, $3
    /* 1EB878 002EB878 3E004224 */  addiu      $2, $2, 0x3E
    /* 1EB87C 002EB87C 3C4C0200 */  dsll32     $9, $2, 16
    /* 1EB880 002EB880 3F4C0900 */  dsra32     $9, $9, 16
    /* 1EB884 002EB884 0A000286 */  lh         $2, 0xA($16)
    /* 1EB888 002EB888 57004224 */  addiu      $2, $2, 0x57
    /* 1EB88C 002EB88C 3C540200 */  dsll32     $10, $2, 16
    /* 1EB890 002EB890 3F540A00 */  dsra32     $10, $10, 16
    /* 1EB894 002EB894 2D20A002 */  daddu      $4, $21, $0
    /* 1EB898 002EB898 6802A5DF */  ld         $5, 0x268($29)
    /* 1EB89C 002EB89C 6002A6DF */  ld         $6, 0x260($29)
    /* 1EB8A0 002EB8A0 06000724 */  addiu      $7, $0, 0x6
    /* 1EB8A4 002EB8A4 05000824 */  addiu      $8, $0, 0x5
    /* 1EB8A8 002EB8A8 405E0C0C */  jal        func_00317900
    /* 1EB8AC 002EB8AC 00000000 */   nop
    /* 1EB8B0 002EB8B0 85050010 */  b          .L002ECEC8
    /* 1EB8B4 002EB8B4 00000000 */   nop
  .L002EB8B8:
    /* 1EB8B8 002EB8B8 08000324 */  addiu      $3, $0, 0x8
    /* 1EB8BC 002EB8BC 82058314 */  bne        $4, $3, .L002ECEC8
    /* 1EB8C0 002EB8C0 00000000 */   nop
    /* 1EB8C4 002EB8C4 2D900000 */  daddu      $18, $0, $0
    /* 1EB8C8 002EB8C8 3C861700 */  dsll32     $16, $23, 24
    /* 1EB8CC 002EB8CC 3F861000 */  dsra32     $16, $16, 24
    /* 1EB8D0 002EB8D0 6A000010 */  b          .L002EBA7C
    /* 1EB8D4 002EB8D4 00000000 */   nop
  .L002EB8D8:
    /* 1EB8D8 002EB8D8 40101400 */  sll        $2, $20, 1
    /* 1EB8DC 002EB8DC 21105400 */  addu       $2, $2, $20
    /* 1EB8E0 002EB8E0 80180200 */  sll        $3, $2, 2
    /* 1EB8E4 002EB8E4 6400023C */  lui        $2, %hi(D_00640760)
    /* 1EB8E8 002EB8E8 60074224 */  addiu      $2, $2, %lo(D_00640760)
    /* 1EB8EC 002EB8EC 21884300 */  addu       $17, $2, $3
    /* 1EB8F0 002EB8F0 34000016 */  bnez       $16, .L002EB9C4
    /* 1EB8F4 002EB8F4 00000000 */   nop
    /* 1EB8F8 002EB8F8 3CA41200 */  dsll32     $20, $18, 16
    /* 1EB8FC 002EB8FC 3FA41400 */  dsra32     $20, $20, 16
    /* 1EB900 002EB900 48C3023C */  lui        $2, (0xC3480000 >> 16)
    /* 1EB904 002EB904 00608244 */  mtc1       $2, $f12
    /* 1EB908 002EB908 040021C6 */  lwc1       $f1, 0x4($17)
    /* 1EB90C 002EB90C C842023C */  lui        $2, (0x42C80000 >> 16)
    /* 1EB910 002EB910 00008244 */  mtc1       $2, $f0
    /* 1EB914 002EB914 00000000 */  nop
    /* 1EB918 002EB918 40030146 */  add.s      $f13, $f0, $f1
    /* 1EB91C 002EB91C 5802A427 */  addiu      $4, $29, 0x258
    /* 1EB920 002EB920 5CCA0A0C */  jal        func_002b2970
    /* 1EB924 002EB924 00000000 */   nop
    /* 1EB928 002EB928 5002A427 */  addiu      $4, $29, 0x250
    /* 1EB92C 002EB92C 00002CC6 */  lwc1       $f12, 0x0($17)
    /* 1EB930 002EB930 04002DC6 */  lwc1       $f13, 0x4($17)
    /* 1EB934 002EB934 5CCA0A0C */  jal        func_002b2970
    /* 1EB938 002EB938 00000000 */   nop
    /* 1EB93C 002EB93C 3C3E1200 */  dsll32     $7, $18, 24
    /* 1EB940 002EB940 3F3E0700 */  dsra32     $7, $7, 24
    /* 1EB944 002EB944 80101400 */  sll        $2, $20, 2
    /* 1EB948 002EB948 3C440200 */  dsll32     $8, $2, 16
    /* 1EB94C 002EB94C 3F440800 */  dsra32     $8, $8, 16
    /* 1EB950 002EB950 08002386 */  lh         $3, 0x8($17)
    /* 1EB954 002EB954 40100300 */  sll        $2, $3, 1
    /* 1EB958 002EB958 21104300 */  addu       $2, $2, $3
    /* 1EB95C 002EB95C 3E004224 */  addiu      $2, $2, 0x3E
    /* 1EB960 002EB960 3C4C0200 */  dsll32     $9, $2, 16
    /* 1EB964 002EB964 3F4C0900 */  dsra32     $9, $9, 16
    /* 1EB968 002EB968 0A002286 */  lh         $2, 0xA($17)
    /* 1EB96C 002EB96C 57004224 */  addiu      $2, $2, 0x57
    /* 1EB970 002EB970 3C540200 */  dsll32     $10, $2, 16
    /* 1EB974 002EB974 3F540A00 */  dsra32     $10, $10, 16
    /* 1EB978 002EB978 2D20A002 */  daddu      $4, $21, $0
    /* 1EB97C 002EB97C 5802A5DF */  ld         $5, 0x258($29)
    /* 1EB980 002EB980 5002A6DF */  ld         $6, 0x250($29)
    /* 1EB984 002EB984 405E0C0C */  jal        func_00317900
    /* 1EB988 002EB988 00000000 */   nop
    /* 1EB98C 002EB98C 80101400 */  sll        $2, $20, 2
    /* 1EB990 002EB990 21105400 */  addu       $2, $2, $20
    /* 1EB994 002EB994 40100200 */  sll        $2, $2, 1
    /* 1EB998 002EB998 21206202 */  addu       $4, $19, $2
    /* 1EB99C 002EB99C 08002386 */  lh         $3, 0x8($17)
    /* 1EB9A0 002EB9A0 40100300 */  sll        $2, $3, 1
    /* 1EB9A4 002EB9A4 21104300 */  addu       $2, $2, $3
    /* 1EB9A8 002EB9A8 3E004224 */  addiu      $2, $2, 0x3E
    /* 1EB9AC 002EB9AC CA0082A4 */  sh         $2, 0xCA($4)
    /* 1EB9B0 002EB9B0 0A002286 */  lh         $2, 0xA($17)
    /* 1EB9B4 002EB9B4 57004224 */  addiu      $2, $2, 0x57
    /* 1EB9B8 002EB9B8 CC0082A4 */  sh         $2, 0xCC($4)
    /* 1EB9BC 002EB9BC 2C000010 */  b          .L002EBA70
    /* 1EB9C0 002EB9C0 00000000 */   nop
  .L002EB9C4:
    /* 1EB9C4 002EB9C4 18DC0E0C */  jal        func_003b7060
    /* 1EB9C8 002EB9C8 00000000 */   nop
    /* 1EB9CC 002EB9CC 2C010324 */  addiu      $3, $0, 0x12C
    /* 1EB9D0 002EB9D0 1B004300 */  divu       $0, $2, $3
    /* 1EB9D4 002EB9D4 10100000 */  mfhi       $2
    /* 1EB9D8 002EB9D8 6AFF4224 */  addiu      $2, $2, -0x96
    /* 1EB9DC 002EB9DC 3CB40200 */  dsll32     $22, $2, 16
    /* 1EB9E0 002EB9E0 3FB41600 */  dsra32     $22, $22, 16
    /* 1EB9E4 002EB9E4 4802A427 */  addiu      $4, $29, 0x248
    /* 1EB9E8 002EB9E8 00002CC6 */  lwc1       $f12, 0x0($17)
    /* 1EB9EC 002EB9EC 04002DC6 */  lwc1       $f13, 0x4($17)
    /* 1EB9F0 002EB9F0 5CCA0A0C */  jal        func_002b2970
    /* 1EB9F4 002EB9F4 00000000 */   nop
    /* 1EB9F8 002EB9F8 040021C6 */  lwc1       $f1, 0x4($17)
    /* 1EB9FC 002EB9FC 00009644 */  mtc1       $22, $f0
    /* 1EBA00 002EBA00 00000000 */  nop
    /* 1EBA04 002EBA04 20008046 */  cvt.s.w    $f0, $f0
    /* 1EBA08 002EBA08 400B0046 */  add.s      $f13, $f1, $f0
    /* 1EBA0C 002EBA0C 96C3023C */  lui        $2, (0xC3960000 >> 16)
    /* 1EBA10 002EBA10 00608244 */  mtc1       $2, $f12
    /* 1EBA14 002EBA14 4002A427 */  addiu      $4, $29, 0x240
    /* 1EBA18 002EBA18 5CCA0A0C */  jal        func_002b2970
    /* 1EBA1C 002EBA1C 00000000 */   nop
    /* 1EBA20 002EBA20 3C3E1200 */  dsll32     $7, $18, 24
    /* 1EBA24 002EBA24 3F3E0700 */  dsra32     $7, $7, 24
    /* 1EBA28 002EBA28 40101400 */  sll        $2, $20, 1
    /* 1EBA2C 002EBA2C 3C440200 */  dsll32     $8, $2, 16
    /* 1EBA30 002EBA30 3F440800 */  dsra32     $8, $8, 16
    /* 1EBA34 002EBA34 08002386 */  lh         $3, 0x8($17)
    /* 1EBA38 002EBA38 40100300 */  sll        $2, $3, 1
    /* 1EBA3C 002EBA3C 21104300 */  addu       $2, $2, $3
    /* 1EBA40 002EBA40 3E004224 */  addiu      $2, $2, 0x3E
    /* 1EBA44 002EBA44 3C4C0200 */  dsll32     $9, $2, 16
    /* 1EBA48 002EBA48 3F4C0900 */  dsra32     $9, $9, 16
    /* 1EBA4C 002EBA4C 0A002286 */  lh         $2, 0xA($17)
    /* 1EBA50 002EBA50 57004224 */  addiu      $2, $2, 0x57
    /* 1EBA54 002EBA54 3C540200 */  dsll32     $10, $2, 16
    /* 1EBA58 002EBA58 3F540A00 */  dsra32     $10, $10, 16
    /* 1EBA5C 002EBA5C 2D20A002 */  daddu      $4, $21, $0
    /* 1EBA60 002EBA60 4802A5DF */  ld         $5, 0x248($29)
    /* 1EBA64 002EBA64 4002A6DF */  ld         $6, 0x240($29)
    /* 1EBA68 002EBA68 405E0C0C */  jal        func_00317900
    /* 1EBA6C 002EBA6C 00000000 */   nop
  .L002EBA70:
    /* 1EBA70 002EBA70 01004226 */  addiu      $2, $18, 0x1
    /* 1EBA74 002EBA74 3C940200 */  dsll32     $18, $2, 16
    /* 1EBA78 002EBA78 3F941200 */  dsra32     $18, $18, 16
  .L002EBA7C:
    /* 1EBA7C 002EBA7C 3CA41200 */  dsll32     $20, $18, 16
    /* 1EBA80 002EBA80 3FA41400 */  dsra32     $20, $20, 16
    /* 1EBA84 002EBA84 0400822A */  slti       $2, $20, 0x4
    /* 1EBA88 002EBA88 93FF4014 */  bnez       $2, .L002EB8D8
    /* 1EBA8C 002EBA8C 00000000 */   nop
    /* 1EBA90 002EBA90 2D900000 */  daddu      $18, $0, $0
    /* 1EBA94 002EBA94 76000010 */  b          .L002EBC70
    /* 1EBA98 002EBA98 00000000 */   nop
  .L002EBA9C:
    /* 1EBA9C 002EBA9C 07000224 */  addiu      $2, $0, 0x7
    /* 1EBAA0 002EBAA0 23184300 */  subu       $3, $2, $3
    /* 1EBAA4 002EBAA4 40100300 */  sll        $2, $3, 1
    /* 1EBAA8 002EBAA8 21104300 */  addu       $2, $2, $3
    /* 1EBAAC 002EBAAC 80180200 */  sll        $3, $2, 2
    /* 1EBAB0 002EBAB0 6400023C */  lui        $2, %hi(D_00640760)
    /* 1EBAB4 002EBAB4 60074224 */  addiu      $2, $2, %lo(D_00640760)
    /* 1EBAB8 002EBAB8 21884300 */  addu       $17, $2, $3
    /* 1EBABC 002EBABC 39000016 */  bnez       $16, .L002EBBA4
    /* 1EBAC0 002EBAC0 00000000 */   nop
    /* 1EBAC4 002EBAC4 3CA41200 */  dsll32     $20, $18, 16
    /* 1EBAC8 002EBAC8 3FA41400 */  dsra32     $20, $20, 16
    /* 1EBACC 002EBACC 2F44023C */  lui        $2, (0x442F0000 >> 16)
    /* 1EBAD0 002EBAD0 00608244 */  mtc1       $2, $f12
    /* 1EBAD4 002EBAD4 040021C6 */  lwc1       $f1, 0x4($17)
    /* 1EBAD8 002EBAD8 C842023C */  lui        $2, (0x42C80000 >> 16)
    /* 1EBADC 002EBADC 00008244 */  mtc1       $2, $f0
    /* 1EBAE0 002EBAE0 00000000 */  nop
    /* 1EBAE4 002EBAE4 40030146 */  add.s      $f13, $f0, $f1
    /* 1EBAE8 002EBAE8 3802A427 */  addiu      $4, $29, 0x238
    /* 1EBAEC 002EBAEC 5CCA0A0C */  jal        func_002b2970
    /* 1EBAF0 002EBAF0 00000000 */   nop
    /* 1EBAF4 002EBAF4 3002A427 */  addiu      $4, $29, 0x230
    /* 1EBAF8 002EBAF8 00002CC6 */  lwc1       $f12, 0x0($17)
    /* 1EBAFC 002EBAFC 04002DC6 */  lwc1       $f13, 0x4($17)
    /* 1EBB00 002EBB00 5CCA0A0C */  jal        func_002b2970
    /* 1EBB04 002EBB04 00000000 */   nop
    /* 1EBB08 002EBB08 08000224 */  addiu      $2, $0, 0x8
    /* 1EBB0C 002EBB0C 23105400 */  subu       $2, $2, $20
    /* 1EBB10 002EBB10 3C3E0200 */  dsll32     $7, $2, 24
    /* 1EBB14 002EBB14 3F3E0700 */  dsra32     $7, $7, 24
    /* 1EBB18 002EBB18 80101400 */  sll        $2, $20, 2
    /* 1EBB1C 002EBB1C 02004224 */  addiu      $2, $2, 0x2
    /* 1EBB20 002EBB20 3C440200 */  dsll32     $8, $2, 16
    /* 1EBB24 002EBB24 3F440800 */  dsra32     $8, $8, 16
    /* 1EBB28 002EBB28 08002386 */  lh         $3, 0x8($17)
    /* 1EBB2C 002EBB2C 40100300 */  sll        $2, $3, 1
    /* 1EBB30 002EBB30 21104300 */  addu       $2, $2, $3
    /* 1EBB34 002EBB34 3E004224 */  addiu      $2, $2, 0x3E
    /* 1EBB38 002EBB38 3C4C0200 */  dsll32     $9, $2, 16
    /* 1EBB3C 002EBB3C 3F4C0900 */  dsra32     $9, $9, 16
    /* 1EBB40 002EBB40 0A002286 */  lh         $2, 0xA($17)
    /* 1EBB44 002EBB44 57004224 */  addiu      $2, $2, 0x57
    /* 1EBB48 002EBB48 3C540200 */  dsll32     $10, $2, 16
    /* 1EBB4C 002EBB4C 3F540A00 */  dsra32     $10, $10, 16
    /* 1EBB50 002EBB50 2D20A002 */  daddu      $4, $21, $0
    /* 1EBB54 002EBB54 3802A5DF */  ld         $5, 0x238($29)
    /* 1EBB58 002EBB58 3002A6DF */  ld         $6, 0x230($29)
    /* 1EBB5C 002EBB5C 405E0C0C */  jal        func_00317900
    /* 1EBB60 002EBB60 00000000 */   nop
    /* 1EBB64 002EBB64 07000224 */  addiu      $2, $0, 0x7
    /* 1EBB68 002EBB68 23185400 */  subu       $3, $2, $20
    /* 1EBB6C 002EBB6C 80100300 */  sll        $2, $3, 2
    /* 1EBB70 002EBB70 21104300 */  addu       $2, $2, $3
    /* 1EBB74 002EBB74 40100200 */  sll        $2, $2, 1
    /* 1EBB78 002EBB78 21206202 */  addu       $4, $19, $2
    /* 1EBB7C 002EBB7C 08002386 */  lh         $3, 0x8($17)
    /* 1EBB80 002EBB80 40100300 */  sll        $2, $3, 1
    /* 1EBB84 002EBB84 21104300 */  addu       $2, $2, $3
    /* 1EBB88 002EBB88 3E004224 */  addiu      $2, $2, 0x3E
    /* 1EBB8C 002EBB8C CA0082A4 */  sh         $2, 0xCA($4)
    /* 1EBB90 002EBB90 0A002286 */  lh         $2, 0xA($17)
    /* 1EBB94 002EBB94 57004224 */  addiu      $2, $2, 0x57
    /* 1EBB98 002EBB98 CC0082A4 */  sh         $2, 0xCC($4)
    /* 1EBB9C 002EBB9C 31000010 */  b          .L002EBC64
    /* 1EBBA0 002EBBA0 00000000 */   nop
  .L002EBBA4:
    /* 1EBBA4 002EBBA4 18DC0E0C */  jal        func_003b7060
    /* 1EBBA8 002EBBA8 00000000 */   nop
    /* 1EBBAC 002EBBAC 2C010324 */  addiu      $3, $0, 0x12C
    /* 1EBBB0 002EBBB0 1B004300 */  divu       $0, $2, $3
    /* 1EBBB4 002EBBB4 10100000 */  mfhi       $2
    /* 1EBBB8 002EBBB8 6AFF4224 */  addiu      $2, $2, -0x96
    /* 1EBBBC 002EBBBC 3CB40200 */  dsll32     $22, $2, 16
    /* 1EBBC0 002EBBC0 3FB41600 */  dsra32     $22, $22, 16
    /* 1EBBC4 002EBBC4 3CA41200 */  dsll32     $20, $18, 16
    /* 1EBBC8 002EBBC8 3FA41400 */  dsra32     $20, $20, 16
    /* 1EBBCC 002EBBCC 2802A427 */  addiu      $4, $29, 0x228
    /* 1EBBD0 002EBBD0 00002CC6 */  lwc1       $f12, 0x0($17)
    /* 1EBBD4 002EBBD4 04002DC6 */  lwc1       $f13, 0x4($17)
    /* 1EBBD8 002EBBD8 5CCA0A0C */  jal        func_002b2970
    /* 1EBBDC 002EBBDC 00000000 */   nop
    /* 1EBBE0 002EBBE0 040021C6 */  lwc1       $f1, 0x4($17)
    /* 1EBBE4 002EBBE4 00009644 */  mtc1       $22, $f0
    /* 1EBBE8 002EBBE8 00000000 */  nop
    /* 1EBBEC 002EBBEC 20008046 */  cvt.s.w    $f0, $f0
    /* 1EBBF0 002EBBF0 400B0046 */  add.s      $f13, $f1, $f0
    /* 1EBBF4 002EBBF4 2F44023C */  lui        $2, (0x442F0000 >> 16)
    /* 1EBBF8 002EBBF8 00608244 */  mtc1       $2, $f12
    /* 1EBBFC 002EBBFC 2002A427 */  addiu      $4, $29, 0x220
    /* 1EBC00 002EBC00 5CCA0A0C */  jal        func_002b2970
    /* 1EBC04 002EBC04 00000000 */   nop
    /* 1EBC08 002EBC08 08000224 */  addiu      $2, $0, 0x8
    /* 1EBC0C 002EBC0C 23105400 */  subu       $2, $2, $20
    /* 1EBC10 002EBC10 3C3E0200 */  dsll32     $7, $2, 24
    /* 1EBC14 002EBC14 3F3E0700 */  dsra32     $7, $7, 24
    /* 1EBC18 002EBC18 40101400 */  sll        $2, $20, 1
    /* 1EBC1C 002EBC1C 01004224 */  addiu      $2, $2, 0x1
    /* 1EBC20 002EBC20 3C440200 */  dsll32     $8, $2, 16
    /* 1EBC24 002EBC24 3F440800 */  dsra32     $8, $8, 16
    /* 1EBC28 002EBC28 08002386 */  lh         $3, 0x8($17)
    /* 1EBC2C 002EBC2C 40100300 */  sll        $2, $3, 1
    /* 1EBC30 002EBC30 21104300 */  addu       $2, $2, $3
    /* 1EBC34 002EBC34 3E004224 */  addiu      $2, $2, 0x3E
    /* 1EBC38 002EBC38 3C4C0200 */  dsll32     $9, $2, 16
    /* 1EBC3C 002EBC3C 3F4C0900 */  dsra32     $9, $9, 16
    /* 1EBC40 002EBC40 0A002286 */  lh         $2, 0xA($17)
    /* 1EBC44 002EBC44 57004224 */  addiu      $2, $2, 0x57
    /* 1EBC48 002EBC48 3C540200 */  dsll32     $10, $2, 16
    /* 1EBC4C 002EBC4C 3F540A00 */  dsra32     $10, $10, 16
    /* 1EBC50 002EBC50 2D20A002 */  daddu      $4, $21, $0
    /* 1EBC54 002EBC54 2802A5DF */  ld         $5, 0x228($29)
    /* 1EBC58 002EBC58 2002A6DF */  ld         $6, 0x220($29)
    /* 1EBC5C 002EBC5C 405E0C0C */  jal        func_00317900
    /* 1EBC60 002EBC60 00000000 */   nop
  .L002EBC64:
    /* 1EBC64 002EBC64 01004226 */  addiu      $2, $18, 0x1
    /* 1EBC68 002EBC68 3C940200 */  dsll32     $18, $2, 16
    /* 1EBC6C 002EBC6C 3F941200 */  dsra32     $18, $18, 16
  .L002EBC70:
    /* 1EBC70 002EBC70 3C1C1200 */  dsll32     $3, $18, 16
    /* 1EBC74 002EBC74 3F1C0300 */  dsra32     $3, $3, 16
    /* 1EBC78 002EBC78 03006228 */  slti       $2, $3, 0x3
    /* 1EBC7C 002EBC7C 87FF4014 */  bnez       $2, .L002EBA9C
    /* 1EBC80 002EBC80 00000000 */   nop
    /* 1EBC84 002EBC84 6400113C */  lui        $17, %hi(D_00640790)
    /* 1EBC88 002EBC88 90073126 */  addiu      $17, $17, %lo(D_00640790)
    /* 1EBC8C 002EBC8C 2B000016 */  bnez       $16, .L002EBD3C
    /* 1EBC90 002EBC90 00000000 */   nop
    /* 1EBC94 002EBC94 2F44023C */  lui        $2, (0x442F0000 >> 16)
    /* 1EBC98 002EBC98 00608244 */  mtc1       $2, $f12
    /* 1EBC9C 002EBC9C 040021C6 */  lwc1       $f1, 0x4($17)
    /* 1EBCA0 002EBCA0 C842023C */  lui        $2, (0x42C80000 >> 16)
    /* 1EBCA4 002EBCA4 00008244 */  mtc1       $2, $f0
    /* 1EBCA8 002EBCA8 00000000 */  nop
    /* 1EBCAC 002EBCAC 40030146 */  add.s      $f13, $f0, $f1
    /* 1EBCB0 002EBCB0 1802A427 */  addiu      $4, $29, 0x218
    /* 1EBCB4 002EBCB4 5CCA0A0C */  jal        func_002b2970
    /* 1EBCB8 002EBCB8 00000000 */   nop
    /* 1EBCBC 002EBCBC 1002A427 */  addiu      $4, $29, 0x210
    /* 1EBCC0 002EBCC0 00002CC6 */  lwc1       $f12, 0x0($17)
    /* 1EBCC4 002EBCC4 04002DC6 */  lwc1       $f13, 0x4($17)
    /* 1EBCC8 002EBCC8 5CCA0A0C */  jal        func_002b2970
    /* 1EBCCC 002EBCCC 00000000 */   nop
    /* 1EBCD0 002EBCD0 08002386 */  lh         $3, 0x8($17)
    /* 1EBCD4 002EBCD4 40100300 */  sll        $2, $3, 1
    /* 1EBCD8 002EBCD8 21104300 */  addu       $2, $2, $3
    /* 1EBCDC 002EBCDC 3E004224 */  addiu      $2, $2, 0x3E
    /* 1EBCE0 002EBCE0 3C4C0200 */  dsll32     $9, $2, 16
    /* 1EBCE4 002EBCE4 3F4C0900 */  dsra32     $9, $9, 16
    /* 1EBCE8 002EBCE8 0A002286 */  lh         $2, 0xA($17)
    /* 1EBCEC 002EBCEC 57004224 */  addiu      $2, $2, 0x57
    /* 1EBCF0 002EBCF0 3C540200 */  dsll32     $10, $2, 16
    /* 1EBCF4 002EBCF4 3F540A00 */  dsra32     $10, $10, 16
    /* 1EBCF8 002EBCF8 2D20A002 */  daddu      $4, $21, $0
    /* 1EBCFC 002EBCFC 1802A5DF */  ld         $5, 0x218($29)
    /* 1EBD00 002EBD00 1002A6DF */  ld         $6, 0x210($29)
    /* 1EBD04 002EBD04 04000724 */  addiu      $7, $0, 0x4
    /* 1EBD08 002EBD08 0E000824 */  addiu      $8, $0, 0xE
    /* 1EBD0C 002EBD0C 405E0C0C */  jal        func_00317900
    /* 1EBD10 002EBD10 00000000 */   nop
    /* 1EBD14 002EBD14 08002486 */  lh         $4, 0x8($17)
    /* 1EBD18 002EBD18 40180400 */  sll        $3, $4, 1
    /* 1EBD1C 002EBD1C 21186400 */  addu       $3, $3, $4
    /* 1EBD20 002EBD20 3E006324 */  addiu      $3, $3, 0x3E
    /* 1EBD24 002EBD24 F20063A6 */  sh         $3, 0xF2($19)
    /* 1EBD28 002EBD28 0A002386 */  lh         $3, 0xA($17)
    /* 1EBD2C 002EBD2C 57006324 */  addiu      $3, $3, 0x57
    /* 1EBD30 002EBD30 F40063A6 */  sh         $3, 0xF4($19)
    /* 1EBD34 002EBD34 64040010 */  b          .L002ECEC8
    /* 1EBD38 002EBD38 00000000 */   nop
  .L002EBD3C:
    /* 1EBD3C 002EBD3C 18DC0E0C */  jal        func_003b7060
    /* 1EBD40 002EBD40 00000000 */   nop
    /* 1EBD44 002EBD44 2C010324 */  addiu      $3, $0, 0x12C
    /* 1EBD48 002EBD48 1B004300 */  divu       $0, $2, $3
    /* 1EBD4C 002EBD4C 10100000 */  mfhi       $2
    /* 1EBD50 002EBD50 6AFF4224 */  addiu      $2, $2, -0x96
    /* 1EBD54 002EBD54 3C840200 */  dsll32     $16, $2, 16
    /* 1EBD58 002EBD58 3F841000 */  dsra32     $16, $16, 16
    /* 1EBD5C 002EBD5C 0802A427 */  addiu      $4, $29, 0x208
    /* 1EBD60 002EBD60 00002CC6 */  lwc1       $f12, 0x0($17)
    /* 1EBD64 002EBD64 04002DC6 */  lwc1       $f13, 0x4($17)
    /* 1EBD68 002EBD68 5CCA0A0C */  jal        func_002b2970
    /* 1EBD6C 002EBD6C 00000000 */   nop
    /* 1EBD70 002EBD70 040021C6 */  lwc1       $f1, 0x4($17)
    /* 1EBD74 002EBD74 00009044 */  mtc1       $16, $f0
    /* 1EBD78 002EBD78 00000000 */  nop
    /* 1EBD7C 002EBD7C 20008046 */  cvt.s.w    $f0, $f0
    /* 1EBD80 002EBD80 400B0046 */  add.s      $f13, $f1, $f0
    /* 1EBD84 002EBD84 2F44023C */  lui        $2, (0x442F0000 >> 16)
    /* 1EBD88 002EBD88 00608244 */  mtc1       $2, $f12
    /* 1EBD8C 002EBD8C 0002A427 */  addiu      $4, $29, 0x200
    /* 1EBD90 002EBD90 5CCA0A0C */  jal        func_002b2970
    /* 1EBD94 002EBD94 00000000 */   nop
    /* 1EBD98 002EBD98 08002386 */  lh         $3, 0x8($17)
    /* 1EBD9C 002EBD9C 40100300 */  sll        $2, $3, 1
    /* 1EBDA0 002EBDA0 21104300 */  addu       $2, $2, $3
    /* 1EBDA4 002EBDA4 3E004224 */  addiu      $2, $2, 0x3E
    /* 1EBDA8 002EBDA8 3C4C0200 */  dsll32     $9, $2, 16
    /* 1EBDAC 002EBDAC 3F4C0900 */  dsra32     $9, $9, 16
    /* 1EBDB0 002EBDB0 0A002286 */  lh         $2, 0xA($17)
    /* 1EBDB4 002EBDB4 57004224 */  addiu      $2, $2, 0x57
    /* 1EBDB8 002EBDB8 3C540200 */  dsll32     $10, $2, 16
    /* 1EBDBC 002EBDBC 3F540A00 */  dsra32     $10, $10, 16
    /* 1EBDC0 002EBDC0 2D20A002 */  daddu      $4, $21, $0
    /* 1EBDC4 002EBDC4 0802A5DF */  ld         $5, 0x208($29)
    /* 1EBDC8 002EBDC8 0002A6DF */  ld         $6, 0x200($29)
    /* 1EBDCC 002EBDCC 04000724 */  addiu      $7, $0, 0x4
    /* 1EBDD0 002EBDD0 07000824 */  addiu      $8, $0, 0x7
    /* 1EBDD4 002EBDD4 405E0C0C */  jal        func_00317900
    /* 1EBDD8 002EBDD8 00000000 */   nop
    /* 1EBDDC 002EBDDC 3A040010 */  b          .L002ECEC8
    /* 1EBDE0 002EBDE0 00000000 */   nop
  .L002EBDE4:
    /* 1EBDE4 002EBDE4 05000324 */  addiu      $3, $0, 0x5
    /* 1EBDE8 002EBDE8 69018314 */  bne        $4, $3, .L002EC390
    /* 1EBDEC 002EBDEC 00000000 */   nop
    /* 1EBDF0 002EBDF0 2DA00000 */  daddu      $20, $0, $0
    /* 1EBDF4 002EBDF4 3C961700 */  dsll32     $18, $23, 24
    /* 1EBDF8 002EBDF8 3F961200 */  dsra32     $18, $18, 24
    /* 1EBDFC 002EBDFC DD000010 */  b          .L002EC174
    /* 1EBE00 002EBE00 00000000 */   nop
  .L002EBE04:
    /* 1EBE04 002EBE04 02000326 */  addiu      $3, $16, 0x2
    /* 1EBE08 002EBE08 40100300 */  sll        $2, $3, 1
    /* 1EBE0C 002EBE0C 21104300 */  addu       $2, $2, $3
    /* 1EBE10 002EBE10 80180200 */  sll        $3, $2, 2
    /* 1EBE14 002EBE14 6400023C */  lui        $2, %hi(D_006407C0)
    /* 1EBE18 002EBE18 C0074224 */  addiu      $2, $2, %lo(D_006407C0)
    /* 1EBE1C 002EBE1C 21884300 */  addu       $17, $2, $3
    /* 1EBE20 002EBE20 34004016 */  bnez       $18, .L002EBEF4
    /* 1EBE24 002EBE24 00000000 */   nop
    /* 1EBE28 002EBE28 3CB41400 */  dsll32     $22, $20, 16
    /* 1EBE2C 002EBE2C 3FB41600 */  dsra32     $22, $22, 16
    /* 1EBE30 002EBE30 48C3023C */  lui        $2, (0xC3480000 >> 16)
    /* 1EBE34 002EBE34 00608244 */  mtc1       $2, $f12
    /* 1EBE38 002EBE38 040021C6 */  lwc1       $f1, 0x4($17)
    /* 1EBE3C 002EBE3C C842023C */  lui        $2, (0x42C80000 >> 16)
    /* 1EBE40 002EBE40 00008244 */  mtc1       $2, $f0
    /* 1EBE44 002EBE44 00000000 */  nop
    /* 1EBE48 002EBE48 40030146 */  add.s      $f13, $f0, $f1
    /* 1EBE4C 002EBE4C F801A427 */  addiu      $4, $29, 0x1F8
    /* 1EBE50 002EBE50 5CCA0A0C */  jal        func_002b2970
    /* 1EBE54 002EBE54 00000000 */   nop
    /* 1EBE58 002EBE58 F001A427 */  addiu      $4, $29, 0x1F0
    /* 1EBE5C 002EBE5C 00002CC6 */  lwc1       $f12, 0x0($17)
    /* 1EBE60 002EBE60 04002DC6 */  lwc1       $f13, 0x4($17)
    /* 1EBE64 002EBE64 5CCA0A0C */  jal        func_002b2970
    /* 1EBE68 002EBE68 00000000 */   nop
    /* 1EBE6C 002EBE6C 3C3E1400 */  dsll32     $7, $20, 24
    /* 1EBE70 002EBE70 3F3E0700 */  dsra32     $7, $7, 24
    /* 1EBE74 002EBE74 80101600 */  sll        $2, $22, 2
    /* 1EBE78 002EBE78 3C440200 */  dsll32     $8, $2, 16
    /* 1EBE7C 002EBE7C 3F440800 */  dsra32     $8, $8, 16
    /* 1EBE80 002EBE80 08002386 */  lh         $3, 0x8($17)
    /* 1EBE84 002EBE84 40100300 */  sll        $2, $3, 1
    /* 1EBE88 002EBE88 21104300 */  addu       $2, $2, $3
    /* 1EBE8C 002EBE8C 3E004224 */  addiu      $2, $2, 0x3E
    /* 1EBE90 002EBE90 3C4C0200 */  dsll32     $9, $2, 16
    /* 1EBE94 002EBE94 3F4C0900 */  dsra32     $9, $9, 16
    /* 1EBE98 002EBE98 0A002286 */  lh         $2, 0xA($17)
    /* 1EBE9C 002EBE9C 57004224 */  addiu      $2, $2, 0x57
    /* 1EBEA0 002EBEA0 3C540200 */  dsll32     $10, $2, 16
    /* 1EBEA4 002EBEA4 3F540A00 */  dsra32     $10, $10, 16
    /* 1EBEA8 002EBEA8 2D20A002 */  daddu      $4, $21, $0
    /* 1EBEAC 002EBEAC F801A5DF */  ld         $5, 0x1F8($29)
    /* 1EBEB0 002EBEB0 F001A6DF */  ld         $6, 0x1F0($29)
    /* 1EBEB4 002EBEB4 405E0C0C */  jal        func_00317900
    /* 1EBEB8 002EBEB8 00000000 */   nop
    /* 1EBEBC 002EBEBC 80101600 */  sll        $2, $22, 2
    /* 1EBEC0 002EBEC0 21105600 */  addu       $2, $2, $22
    /* 1EBEC4 002EBEC4 40100200 */  sll        $2, $2, 1
    /* 1EBEC8 002EBEC8 21206202 */  addu       $4, $19, $2
    /* 1EBECC 002EBECC 08002386 */  lh         $3, 0x8($17)
    /* 1EBED0 002EBED0 40100300 */  sll        $2, $3, 1
    /* 1EBED4 002EBED4 21104300 */  addu       $2, $2, $3
    /* 1EBED8 002EBED8 3E004224 */  addiu      $2, $2, 0x3E
    /* 1EBEDC 002EBEDC CA0082A4 */  sh         $2, 0xCA($4)
    /* 1EBEE0 002EBEE0 0A002286 */  lh         $2, 0xA($17)
    /* 1EBEE4 002EBEE4 57004224 */  addiu      $2, $2, 0x57
    /* 1EBEE8 002EBEE8 CC0082A4 */  sh         $2, 0xCC($4)
    /* 1EBEEC 002EBEEC 2C000010 */  b          .L002EBFA0
    /* 1EBEF0 002EBEF0 00000000 */   nop
  .L002EBEF4:
    /* 1EBEF4 002EBEF4 18DC0E0C */  jal        func_003b7060
    /* 1EBEF8 002EBEF8 00000000 */   nop
    /* 1EBEFC 002EBEFC 2C010324 */  addiu      $3, $0, 0x12C
    /* 1EBF00 002EBF00 1B004300 */  divu       $0, $2, $3
    /* 1EBF04 002EBF04 10100000 */  mfhi       $2
    /* 1EBF08 002EBF08 6AFF4224 */  addiu      $2, $2, -0x96
    /* 1EBF0C 002EBF0C 3CB40200 */  dsll32     $22, $2, 16
    /* 1EBF10 002EBF10 3FB41600 */  dsra32     $22, $22, 16
    /* 1EBF14 002EBF14 E801A427 */  addiu      $4, $29, 0x1E8
    /* 1EBF18 002EBF18 00002CC6 */  lwc1       $f12, 0x0($17)
    /* 1EBF1C 002EBF1C 04002DC6 */  lwc1       $f13, 0x4($17)
    /* 1EBF20 002EBF20 5CCA0A0C */  jal        func_002b2970
    /* 1EBF24 002EBF24 00000000 */   nop
    /* 1EBF28 002EBF28 040021C6 */  lwc1       $f1, 0x4($17)
    /* 1EBF2C 002EBF2C 00009644 */  mtc1       $22, $f0
    /* 1EBF30 002EBF30 00000000 */  nop
    /* 1EBF34 002EBF34 20008046 */  cvt.s.w    $f0, $f0
    /* 1EBF38 002EBF38 400B0046 */  add.s      $f13, $f1, $f0
    /* 1EBF3C 002EBF3C 96C3023C */  lui        $2, (0xC3960000 >> 16)
    /* 1EBF40 002EBF40 00608244 */  mtc1       $2, $f12
    /* 1EBF44 002EBF44 E001A427 */  addiu      $4, $29, 0x1E0
    /* 1EBF48 002EBF48 5CCA0A0C */  jal        func_002b2970
    /* 1EBF4C 002EBF4C 00000000 */   nop
    /* 1EBF50 002EBF50 3C3E1400 */  dsll32     $7, $20, 24
    /* 1EBF54 002EBF54 3F3E0700 */  dsra32     $7, $7, 24
    /* 1EBF58 002EBF58 40101000 */  sll        $2, $16, 1
    /* 1EBF5C 002EBF5C 3C440200 */  dsll32     $8, $2, 16
    /* 1EBF60 002EBF60 3F440800 */  dsra32     $8, $8, 16
    /* 1EBF64 002EBF64 08002386 */  lh         $3, 0x8($17)
    /* 1EBF68 002EBF68 40100300 */  sll        $2, $3, 1
    /* 1EBF6C 002EBF6C 21104300 */  addu       $2, $2, $3
    /* 1EBF70 002EBF70 3E004224 */  addiu      $2, $2, 0x3E
    /* 1EBF74 002EBF74 3C4C0200 */  dsll32     $9, $2, 16
    /* 1EBF78 002EBF78 3F4C0900 */  dsra32     $9, $9, 16
    /* 1EBF7C 002EBF7C 0A002286 */  lh         $2, 0xA($17)
    /* 1EBF80 002EBF80 57004224 */  addiu      $2, $2, 0x57
    /* 1EBF84 002EBF84 3C540200 */  dsll32     $10, $2, 16
    /* 1EBF88 002EBF88 3F540A00 */  dsra32     $10, $10, 16
    /* 1EBF8C 002EBF8C 2D20A002 */  daddu      $4, $21, $0
    /* 1EBF90 002EBF90 E801A5DF */  ld         $5, 0x1E8($29)
    /* 1EBF94 002EBF94 E001A6DF */  ld         $6, 0x1E0($29)
    /* 1EBF98 002EBF98 405E0C0C */  jal        func_00317900
    /* 1EBF9C 002EBF9C 00000000 */   nop
  .L002EBFA0:
    /* 1EBFA0 002EBFA0 06000224 */  addiu      $2, $0, 0x6
    /* 1EBFA4 002EBFA4 23185000 */  subu       $3, $2, $16
    /* 1EBFA8 002EBFA8 40100300 */  sll        $2, $3, 1
    /* 1EBFAC 002EBFAC 21104300 */  addu       $2, $2, $3
    /* 1EBFB0 002EBFB0 80180200 */  sll        $3, $2, 2
    /* 1EBFB4 002EBFB4 6400023C */  lui        $2, %hi(D_006407C0)
    /* 1EBFB8 002EBFB8 C0074224 */  addiu      $2, $2, %lo(D_006407C0)
    /* 1EBFBC 002EBFBC 21804300 */  addu       $16, $2, $3
    /* 1EBFC0 002EBFC0 39004016 */  bnez       $18, .L002EC0A8
    /* 1EBFC4 002EBFC4 00000000 */   nop
    /* 1EBFC8 002EBFC8 3C8C1400 */  dsll32     $17, $20, 16
    /* 1EBFCC 002EBFCC 3F8C1100 */  dsra32     $17, $17, 16
    /* 1EBFD0 002EBFD0 2F44023C */  lui        $2, (0x442F0000 >> 16)
    /* 1EBFD4 002EBFD4 00608244 */  mtc1       $2, $f12
    /* 1EBFD8 002EBFD8 040001C6 */  lwc1       $f1, 0x4($16)
    /* 1EBFDC 002EBFDC C842023C */  lui        $2, (0x42C80000 >> 16)
    /* 1EBFE0 002EBFE0 00008244 */  mtc1       $2, $f0
    /* 1EBFE4 002EBFE4 00000000 */  nop
    /* 1EBFE8 002EBFE8 40030146 */  add.s      $f13, $f0, $f1
    /* 1EBFEC 002EBFEC D801A427 */  addiu      $4, $29, 0x1D8
    /* 1EBFF0 002EBFF0 5CCA0A0C */  jal        func_002b2970
    /* 1EBFF4 002EBFF4 00000000 */   nop
    /* 1EBFF8 002EBFF8 D001A427 */  addiu      $4, $29, 0x1D0
    /* 1EBFFC 002EBFFC 00000CC6 */  lwc1       $f12, 0x0($16)
    /* 1EC000 002EC000 04000DC6 */  lwc1       $f13, 0x4($16)
    /* 1EC004 002EC004 5CCA0A0C */  jal        func_002b2970
    /* 1EC008 002EC008 00000000 */   nop
    /* 1EC00C 002EC00C 08000224 */  addiu      $2, $0, 0x8
    /* 1EC010 002EC010 23105100 */  subu       $2, $2, $17
    /* 1EC014 002EC014 3C3E0200 */  dsll32     $7, $2, 24
    /* 1EC018 002EC018 3F3E0700 */  dsra32     $7, $7, 24
    /* 1EC01C 002EC01C 80101100 */  sll        $2, $17, 2
    /* 1EC020 002EC020 02004224 */  addiu      $2, $2, 0x2
    /* 1EC024 002EC024 3C440200 */  dsll32     $8, $2, 16
    /* 1EC028 002EC028 3F440800 */  dsra32     $8, $8, 16
    /* 1EC02C 002EC02C 08000386 */  lh         $3, 0x8($16)
    /* 1EC030 002EC030 40100300 */  sll        $2, $3, 1
    /* 1EC034 002EC034 21104300 */  addu       $2, $2, $3
    /* 1EC038 002EC038 3E004224 */  addiu      $2, $2, 0x3E
    /* 1EC03C 002EC03C 3C4C0200 */  dsll32     $9, $2, 16
    /* 1EC040 002EC040 3F4C0900 */  dsra32     $9, $9, 16
    /* 1EC044 002EC044 0A000286 */  lh         $2, 0xA($16)
    /* 1EC048 002EC048 57004224 */  addiu      $2, $2, 0x57
    /* 1EC04C 002EC04C 3C540200 */  dsll32     $10, $2, 16
    /* 1EC050 002EC050 3F540A00 */  dsra32     $10, $10, 16
    /* 1EC054 002EC054 2D20A002 */  daddu      $4, $21, $0
    /* 1EC058 002EC058 D801A5DF */  ld         $5, 0x1D8($29)
    /* 1EC05C 002EC05C D001A6DF */  ld         $6, 0x1D0($29)
    /* 1EC060 002EC060 405E0C0C */  jal        func_00317900
    /* 1EC064 002EC064 00000000 */   nop
    /* 1EC068 002EC068 04000224 */  addiu      $2, $0, 0x4
    /* 1EC06C 002EC06C 23185100 */  subu       $3, $2, $17
    /* 1EC070 002EC070 80100300 */  sll        $2, $3, 2
    /* 1EC074 002EC074 21104300 */  addu       $2, $2, $3
    /* 1EC078 002EC078 40100200 */  sll        $2, $2, 1
    /* 1EC07C 002EC07C 21206202 */  addu       $4, $19, $2
    /* 1EC080 002EC080 08000386 */  lh         $3, 0x8($16)
    /* 1EC084 002EC084 40100300 */  sll        $2, $3, 1
    /* 1EC088 002EC088 21104300 */  addu       $2, $2, $3
    /* 1EC08C 002EC08C 3E004224 */  addiu      $2, $2, 0x3E
    /* 1EC090 002EC090 CA0082A4 */  sh         $2, 0xCA($4)
    /* 1EC094 002EC094 0A000286 */  lh         $2, 0xA($16)
    /* 1EC098 002EC098 57004224 */  addiu      $2, $2, 0x57
    /* 1EC09C 002EC09C CC0082A4 */  sh         $2, 0xCC($4)
    /* 1EC0A0 002EC0A0 31000010 */  b          .L002EC168
    /* 1EC0A4 002EC0A4 00000000 */   nop
  .L002EC0A8:
    /* 1EC0A8 002EC0A8 18DC0E0C */  jal        func_003b7060
    /* 1EC0AC 002EC0AC 00000000 */   nop
    /* 1EC0B0 002EC0B0 2C010324 */  addiu      $3, $0, 0x12C
    /* 1EC0B4 002EC0B4 1B004300 */  divu       $0, $2, $3
    /* 1EC0B8 002EC0B8 10100000 */  mfhi       $2
    /* 1EC0BC 002EC0BC 6AFF4224 */  addiu      $2, $2, -0x96
    /* 1EC0C0 002EC0C0 3CB40200 */  dsll32     $22, $2, 16
    /* 1EC0C4 002EC0C4 3FB41600 */  dsra32     $22, $22, 16
    /* 1EC0C8 002EC0C8 3C8C1400 */  dsll32     $17, $20, 16
    /* 1EC0CC 002EC0CC 3F8C1100 */  dsra32     $17, $17, 16
    /* 1EC0D0 002EC0D0 C801A427 */  addiu      $4, $29, 0x1C8
    /* 1EC0D4 002EC0D4 00000CC6 */  lwc1       $f12, 0x0($16)
    /* 1EC0D8 002EC0D8 04000DC6 */  lwc1       $f13, 0x4($16)
    /* 1EC0DC 002EC0DC 5CCA0A0C */  jal        func_002b2970
    /* 1EC0E0 002EC0E0 00000000 */   nop
    /* 1EC0E4 002EC0E4 040001C6 */  lwc1       $f1, 0x4($16)
    /* 1EC0E8 002EC0E8 00009644 */  mtc1       $22, $f0
    /* 1EC0EC 002EC0EC 00000000 */  nop
    /* 1EC0F0 002EC0F0 20008046 */  cvt.s.w    $f0, $f0
    /* 1EC0F4 002EC0F4 400B0046 */  add.s      $f13, $f1, $f0
    /* 1EC0F8 002EC0F8 2F44023C */  lui        $2, (0x442F0000 >> 16)
    /* 1EC0FC 002EC0FC 00608244 */  mtc1       $2, $f12
    /* 1EC100 002EC100 C001A427 */  addiu      $4, $29, 0x1C0
    /* 1EC104 002EC104 5CCA0A0C */  jal        func_002b2970
    /* 1EC108 002EC108 00000000 */   nop
    /* 1EC10C 002EC10C 08000224 */  addiu      $2, $0, 0x8
    /* 1EC110 002EC110 23105100 */  subu       $2, $2, $17
    /* 1EC114 002EC114 3C3E0200 */  dsll32     $7, $2, 24
    /* 1EC118 002EC118 3F3E0700 */  dsra32     $7, $7, 24
    /* 1EC11C 002EC11C 40101100 */  sll        $2, $17, 1
    /* 1EC120 002EC120 01004224 */  addiu      $2, $2, 0x1
    /* 1EC124 002EC124 3C440200 */  dsll32     $8, $2, 16
    /* 1EC128 002EC128 3F440800 */  dsra32     $8, $8, 16
    /* 1EC12C 002EC12C 08000386 */  lh         $3, 0x8($16)
    /* 1EC130 002EC130 40100300 */  sll        $2, $3, 1
    /* 1EC134 002EC134 21104300 */  addu       $2, $2, $3
    /* 1EC138 002EC138 3E004224 */  addiu      $2, $2, 0x3E
    /* 1EC13C 002EC13C 3C4C0200 */  dsll32     $9, $2, 16
    /* 1EC140 002EC140 3F4C0900 */  dsra32     $9, $9, 16
    /* 1EC144 002EC144 0A000286 */  lh         $2, 0xA($16)
    /* 1EC148 002EC148 57004224 */  addiu      $2, $2, 0x57
    /* 1EC14C 002EC14C 3C540200 */  dsll32     $10, $2, 16
    /* 1EC150 002EC150 3F540A00 */  dsra32     $10, $10, 16
    /* 1EC154 002EC154 2D20A002 */  daddu      $4, $21, $0
    /* 1EC158 002EC158 C801A5DF */  ld         $5, 0x1C8($29)
    /* 1EC15C 002EC15C C001A6DF */  ld         $6, 0x1C0($29)
    /* 1EC160 002EC160 405E0C0C */  jal        func_00317900
    /* 1EC164 002EC164 00000000 */   nop
  .L002EC168:
    /* 1EC168 002EC168 01008226 */  addiu      $2, $20, 0x1
    /* 1EC16C 002EC16C 3CA40200 */  dsll32     $20, $2, 16
    /* 1EC170 002EC170 3FA41400 */  dsra32     $20, $20, 16
  .L002EC174:
    /* 1EC174 002EC174 3C841400 */  dsll32     $16, $20, 16
    /* 1EC178 002EC178 3F841000 */  dsra32     $16, $16, 16
    /* 1EC17C 002EC17C 0200022A */  slti       $2, $16, 0x2
    /* 1EC180 002EC180 20FF4014 */  bnez       $2, .L002EBE04
    /* 1EC184 002EC184 00000000 */   nop
    /* 1EC188 002EC188 6400113C */  lui        $17, %hi(D_006407F0)
    /* 1EC18C 002EC18C F0073126 */  addiu      $17, $17, %lo(D_006407F0)
    /* 1EC190 002EC190 2B004016 */  bnez       $18, .L002EC240
    /* 1EC194 002EC194 00000000 */   nop
    /* 1EC198 002EC198 48C3023C */  lui        $2, (0xC3480000 >> 16)
    /* 1EC19C 002EC19C 00608244 */  mtc1       $2, $f12
    /* 1EC1A0 002EC1A0 040021C6 */  lwc1       $f1, 0x4($17)
    /* 1EC1A4 002EC1A4 C842023C */  lui        $2, (0x42C80000 >> 16)
    /* 1EC1A8 002EC1A8 00008244 */  mtc1       $2, $f0
    /* 1EC1AC 002EC1AC 00000000 */  nop
    /* 1EC1B0 002EC1B0 40030146 */  add.s      $f13, $f0, $f1
    /* 1EC1B4 002EC1B4 B801A427 */  addiu      $4, $29, 0x1B8
    /* 1EC1B8 002EC1B8 5CCA0A0C */  jal        func_002b2970
    /* 1EC1BC 002EC1BC 00000000 */   nop
    /* 1EC1C0 002EC1C0 B001A427 */  addiu      $4, $29, 0x1B0
    /* 1EC1C4 002EC1C4 00002CC6 */  lwc1       $f12, 0x0($17)
    /* 1EC1C8 002EC1C8 04002DC6 */  lwc1       $f13, 0x4($17)
    /* 1EC1CC 002EC1CC 5CCA0A0C */  jal        func_002b2970
    /* 1EC1D0 002EC1D0 00000000 */   nop
    /* 1EC1D4 002EC1D4 08002386 */  lh         $3, 0x8($17)
    /* 1EC1D8 002EC1D8 40100300 */  sll        $2, $3, 1
    /* 1EC1DC 002EC1DC 21104300 */  addu       $2, $2, $3
    /* 1EC1E0 002EC1E0 3E004224 */  addiu      $2, $2, 0x3E
    /* 1EC1E4 002EC1E4 3C4C0200 */  dsll32     $9, $2, 16
    /* 1EC1E8 002EC1E8 3F4C0900 */  dsra32     $9, $9, 16
    /* 1EC1EC 002EC1EC 0A002286 */  lh         $2, 0xA($17)
    /* 1EC1F0 002EC1F0 57004224 */  addiu      $2, $2, 0x57
    /* 1EC1F4 002EC1F4 3C540200 */  dsll32     $10, $2, 16
    /* 1EC1F8 002EC1F8 3F540A00 */  dsra32     $10, $10, 16
    /* 1EC1FC 002EC1FC 2D20A002 */  daddu      $4, $21, $0
    /* 1EC200 002EC200 B801A5DF */  ld         $5, 0x1B8($29)
    /* 1EC204 002EC204 B001A6DF */  ld         $6, 0x1B0($29)
    /* 1EC208 002EC208 06000724 */  addiu      $7, $0, 0x6
    /* 1EC20C 002EC20C 08000824 */  addiu      $8, $0, 0x8
    /* 1EC210 002EC210 405E0C0C */  jal        func_00317900
    /* 1EC214 002EC214 00000000 */   nop
    /* 1EC218 002EC218 08002486 */  lh         $4, 0x8($17)
    /* 1EC21C 002EC21C 40180400 */  sll        $3, $4, 1
    /* 1EC220 002EC220 21186400 */  addu       $3, $3, $4
    /* 1EC224 002EC224 3E006324 */  addiu      $3, $3, 0x3E
    /* 1EC228 002EC228 DE0063A6 */  sh         $3, 0xDE($19)
    /* 1EC22C 002EC22C 0A002386 */  lh         $3, 0xA($17)
    /* 1EC230 002EC230 57006324 */  addiu      $3, $3, 0x57
    /* 1EC234 002EC234 E00063A6 */  sh         $3, 0xE0($19)
    /* 1EC238 002EC238 23030010 */  b          .L002ECEC8
    /* 1EC23C 002EC23C 00000000 */   nop
  .L002EC240:
    /* 1EC240 002EC240 18DC0E0C */  jal        func_003b7060
    /* 1EC244 002EC244 00000000 */   nop
    /* 1EC248 002EC248 2C010324 */  addiu      $3, $0, 0x12C
    /* 1EC24C 002EC24C 1B004300 */  divu       $0, $2, $3
    /* 1EC250 002EC250 10100000 */  mfhi       $2
    /* 1EC254 002EC254 6AFF4224 */  addiu      $2, $2, -0x96
    /* 1EC258 002EC258 3C840200 */  dsll32     $16, $2, 16
    /* 1EC25C 002EC25C 3F841000 */  dsra32     $16, $16, 16
    /* 1EC260 002EC260 18DC0E0C */  jal        func_003b7060
    /* 1EC264 002EC264 00000000 */   nop
    /* 1EC268 002EC268 64000324 */  addiu      $3, $0, 0x64
    /* 1EC26C 002EC26C 1B004300 */  divu       $0, $2, $3
    /* 1EC270 002EC270 10100000 */  mfhi       $2
    /* 1EC274 002EC274 3200422C */  sltiu      $2, $2, 0x32
    /* 1EC278 002EC278 23004014 */  bnez       $2, .L002EC308
    /* 1EC27C 002EC27C 00000000 */   nop
    /* 1EC280 002EC280 A801A427 */  addiu      $4, $29, 0x1A8
    /* 1EC284 002EC284 00002CC6 */  lwc1       $f12, 0x0($17)
    /* 1EC288 002EC288 04002DC6 */  lwc1       $f13, 0x4($17)
    /* 1EC28C 002EC28C 5CCA0A0C */  jal        func_002b2970
    /* 1EC290 002EC290 00000000 */   nop
    /* 1EC294 002EC294 040021C6 */  lwc1       $f1, 0x4($17)
    /* 1EC298 002EC298 00009044 */  mtc1       $16, $f0
    /* 1EC29C 002EC29C 00000000 */  nop
    /* 1EC2A0 002EC2A0 20008046 */  cvt.s.w    $f0, $f0
    /* 1EC2A4 002EC2A4 400B0046 */  add.s      $f13, $f1, $f0
    /* 1EC2A8 002EC2A8 96C3023C */  lui        $2, (0xC3960000 >> 16)
    /* 1EC2AC 002EC2AC 00608244 */  mtc1       $2, $f12
    /* 1EC2B0 002EC2B0 A001A427 */  addiu      $4, $29, 0x1A0
    /* 1EC2B4 002EC2B4 5CCA0A0C */  jal        func_002b2970
    /* 1EC2B8 002EC2B8 00000000 */   nop
    /* 1EC2BC 002EC2BC 08002386 */  lh         $3, 0x8($17)
    /* 1EC2C0 002EC2C0 40100300 */  sll        $2, $3, 1
    /* 1EC2C4 002EC2C4 21104300 */  addu       $2, $2, $3
    /* 1EC2C8 002EC2C8 3E004224 */  addiu      $2, $2, 0x3E
    /* 1EC2CC 002EC2CC 3C4C0200 */  dsll32     $9, $2, 16
    /* 1EC2D0 002EC2D0 3F4C0900 */  dsra32     $9, $9, 16
    /* 1EC2D4 002EC2D4 0A002286 */  lh         $2, 0xA($17)
    /* 1EC2D8 002EC2D8 57004224 */  addiu      $2, $2, 0x57
    /* 1EC2DC 002EC2DC 3C540200 */  dsll32     $10, $2, 16
    /* 1EC2E0 002EC2E0 3F540A00 */  dsra32     $10, $10, 16
    /* 1EC2E4 002EC2E4 2D20A002 */  daddu      $4, $21, $0
    /* 1EC2E8 002EC2E8 A801A5DF */  ld         $5, 0x1A8($29)
    /* 1EC2EC 002EC2EC A001A6DF */  ld         $6, 0x1A0($29)
    /* 1EC2F0 002EC2F0 06000724 */  addiu      $7, $0, 0x6
    /* 1EC2F4 002EC2F4 04000824 */  addiu      $8, $0, 0x4
    /* 1EC2F8 002EC2F8 405E0C0C */  jal        func_00317900
    /* 1EC2FC 002EC2FC 00000000 */   nop
    /* 1EC300 002EC300 F1020010 */  b          .L002ECEC8
    /* 1EC304 002EC304 00000000 */   nop
  .L002EC308:
    /* 1EC308 002EC308 9801A427 */  addiu      $4, $29, 0x198
    /* 1EC30C 002EC30C 00002CC6 */  lwc1       $f12, 0x0($17)
    /* 1EC310 002EC310 04002DC6 */  lwc1       $f13, 0x4($17)
    /* 1EC314 002EC314 5CCA0A0C */  jal        func_002b2970
    /* 1EC318 002EC318 00000000 */   nop
    /* 1EC31C 002EC31C 040021C6 */  lwc1       $f1, 0x4($17)
    /* 1EC320 002EC320 00009044 */  mtc1       $16, $f0
    /* 1EC324 002EC324 00000000 */  nop
    /* 1EC328 002EC328 20008046 */  cvt.s.w    $f0, $f0
    /* 1EC32C 002EC32C 400B0046 */  add.s      $f13, $f1, $f0
    /* 1EC330 002EC330 2F44023C */  lui        $2, (0x442F0000 >> 16)
    /* 1EC334 002EC334 00608244 */  mtc1       $2, $f12
    /* 1EC338 002EC338 9001A427 */  addiu      $4, $29, 0x190
    /* 1EC33C 002EC33C 5CCA0A0C */  jal        func_002b2970
    /* 1EC340 002EC340 00000000 */   nop
    /* 1EC344 002EC344 08002386 */  lh         $3, 0x8($17)
    /* 1EC348 002EC348 40100300 */  sll        $2, $3, 1
    /* 1EC34C 002EC34C 21104300 */  addu       $2, $2, $3
    /* 1EC350 002EC350 3E004224 */  addiu      $2, $2, 0x3E
    /* 1EC354 002EC354 3C4C0200 */  dsll32     $9, $2, 16
    /* 1EC358 002EC358 3F4C0900 */  dsra32     $9, $9, 16
    /* 1EC35C 002EC35C 0A002286 */  lh         $2, 0xA($17)
    /* 1EC360 002EC360 57004224 */  addiu      $2, $2, 0x57
    /* 1EC364 002EC364 3C540200 */  dsll32     $10, $2, 16
    /* 1EC368 002EC368 3F540A00 */  dsra32     $10, $10, 16
    /* 1EC36C 002EC36C 2D20A002 */  daddu      $4, $21, $0
    /* 1EC370 002EC370 9801A5DF */  ld         $5, 0x198($29)
    /* 1EC374 002EC374 9001A6DF */  ld         $6, 0x190($29)
    /* 1EC378 002EC378 06000724 */  addiu      $7, $0, 0x6
    /* 1EC37C 002EC37C 04000824 */  addiu      $8, $0, 0x4
    /* 1EC380 002EC380 405E0C0C */  jal        func_00317900
    /* 1EC384 002EC384 00000000 */   nop
    /* 1EC388 002EC388 CF020010 */  b          .L002ECEC8
    /* 1EC38C 002EC38C 00000000 */   nop
  .L002EC390:
    /* 1EC390 002EC390 07000324 */  addiu      $3, $0, 0x7
    /* 1EC394 002EC394 69018314 */  bne        $4, $3, .L002EC93C
    /* 1EC398 002EC398 00000000 */   nop
    /* 1EC39C 002EC39C 2DA00000 */  daddu      $20, $0, $0
    /* 1EC3A0 002EC3A0 3C961700 */  dsll32     $18, $23, 24
    /* 1EC3A4 002EC3A4 3F961200 */  dsra32     $18, $18, 24
    /* 1EC3A8 002EC3A8 DD000010 */  b          .L002EC720
    /* 1EC3AC 002EC3AC 00000000 */   nop
  .L002EC3B0:
    /* 1EC3B0 002EC3B0 01000326 */  addiu      $3, $16, 0x1
    /* 1EC3B4 002EC3B4 40100300 */  sll        $2, $3, 1
    /* 1EC3B8 002EC3B8 21104300 */  addu       $2, $2, $3
    /* 1EC3BC 002EC3BC 80180200 */  sll        $3, $2, 2
    /* 1EC3C0 002EC3C0 6400023C */  lui        $2, %hi(D_006407C0)
    /* 1EC3C4 002EC3C4 C0074224 */  addiu      $2, $2, %lo(D_006407C0)
    /* 1EC3C8 002EC3C8 21884300 */  addu       $17, $2, $3
    /* 1EC3CC 002EC3CC 34004016 */  bnez       $18, .L002EC4A0
    /* 1EC3D0 002EC3D0 00000000 */   nop
    /* 1EC3D4 002EC3D4 3CB41400 */  dsll32     $22, $20, 16
    /* 1EC3D8 002EC3D8 3FB41600 */  dsra32     $22, $22, 16
    /* 1EC3DC 002EC3DC 48C3023C */  lui        $2, (0xC3480000 >> 16)
    /* 1EC3E0 002EC3E0 00608244 */  mtc1       $2, $f12
    /* 1EC3E4 002EC3E4 040021C6 */  lwc1       $f1, 0x4($17)
    /* 1EC3E8 002EC3E8 C842023C */  lui        $2, (0x42C80000 >> 16)
    /* 1EC3EC 002EC3EC 00008244 */  mtc1       $2, $f0
    /* 1EC3F0 002EC3F0 00000000 */  nop
    /* 1EC3F4 002EC3F4 40030146 */  add.s      $f13, $f0, $f1
    /* 1EC3F8 002EC3F8 8801A427 */  addiu      $4, $29, 0x188
    /* 1EC3FC 002EC3FC 5CCA0A0C */  jal        func_002b2970
    /* 1EC400 002EC400 00000000 */   nop
    /* 1EC404 002EC404 8001A427 */  addiu      $4, $29, 0x180
    /* 1EC408 002EC408 00002CC6 */  lwc1       $f12, 0x0($17)
    /* 1EC40C 002EC40C 04002DC6 */  lwc1       $f13, 0x4($17)
    /* 1EC410 002EC410 5CCA0A0C */  jal        func_002b2970
    /* 1EC414 002EC414 00000000 */   nop
    /* 1EC418 002EC418 3C3E1400 */  dsll32     $7, $20, 24
    /* 1EC41C 002EC41C 3F3E0700 */  dsra32     $7, $7, 24
    /* 1EC420 002EC420 80101600 */  sll        $2, $22, 2
    /* 1EC424 002EC424 3C440200 */  dsll32     $8, $2, 16
    /* 1EC428 002EC428 3F440800 */  dsra32     $8, $8, 16
    /* 1EC42C 002EC42C 08002386 */  lh         $3, 0x8($17)
    /* 1EC430 002EC430 40100300 */  sll        $2, $3, 1
    /* 1EC434 002EC434 21104300 */  addu       $2, $2, $3
    /* 1EC438 002EC438 3E004224 */  addiu      $2, $2, 0x3E
    /* 1EC43C 002EC43C 3C4C0200 */  dsll32     $9, $2, 16
    /* 1EC440 002EC440 3F4C0900 */  dsra32     $9, $9, 16
    /* 1EC444 002EC444 0A002286 */  lh         $2, 0xA($17)
    /* 1EC448 002EC448 57004224 */  addiu      $2, $2, 0x57
    /* 1EC44C 002EC44C 3C540200 */  dsll32     $10, $2, 16
    /* 1EC450 002EC450 3F540A00 */  dsra32     $10, $10, 16
    /* 1EC454 002EC454 2D20A002 */  daddu      $4, $21, $0
    /* 1EC458 002EC458 8801A5DF */  ld         $5, 0x188($29)
    /* 1EC45C 002EC45C 8001A6DF */  ld         $6, 0x180($29)
    /* 1EC460 002EC460 405E0C0C */  jal        func_00317900
    /* 1EC464 002EC464 00000000 */   nop
    /* 1EC468 002EC468 80101600 */  sll        $2, $22, 2
    /* 1EC46C 002EC46C 21105600 */  addu       $2, $2, $22
    /* 1EC470 002EC470 40100200 */  sll        $2, $2, 1
    /* 1EC474 002EC474 21206202 */  addu       $4, $19, $2
    /* 1EC478 002EC478 08002386 */  lh         $3, 0x8($17)
    /* 1EC47C 002EC47C 40100300 */  sll        $2, $3, 1
    /* 1EC480 002EC480 21104300 */  addu       $2, $2, $3
    /* 1EC484 002EC484 3E004224 */  addiu      $2, $2, 0x3E
    /* 1EC488 002EC488 CA0082A4 */  sh         $2, 0xCA($4)
    /* 1EC48C 002EC48C 0A002286 */  lh         $2, 0xA($17)
    /* 1EC490 002EC490 57004224 */  addiu      $2, $2, 0x57
    /* 1EC494 002EC494 CC0082A4 */  sh         $2, 0xCC($4)
    /* 1EC498 002EC498 2C000010 */  b          .L002EC54C
    /* 1EC49C 002EC49C 00000000 */   nop
  .L002EC4A0:
    /* 1EC4A0 002EC4A0 18DC0E0C */  jal        func_003b7060
    /* 1EC4A4 002EC4A4 00000000 */   nop
    /* 1EC4A8 002EC4A8 2C010324 */  addiu      $3, $0, 0x12C
    /* 1EC4AC 002EC4AC 1B004300 */  divu       $0, $2, $3
    /* 1EC4B0 002EC4B0 10100000 */  mfhi       $2
    /* 1EC4B4 002EC4B4 6AFF4224 */  addiu      $2, $2, -0x96
    /* 1EC4B8 002EC4B8 3CB40200 */  dsll32     $22, $2, 16
    /* 1EC4BC 002EC4BC 3FB41600 */  dsra32     $22, $22, 16
    /* 1EC4C0 002EC4C0 7801A427 */  addiu      $4, $29, 0x178
    /* 1EC4C4 002EC4C4 00002CC6 */  lwc1       $f12, 0x0($17)
    /* 1EC4C8 002EC4C8 04002DC6 */  lwc1       $f13, 0x4($17)
    /* 1EC4CC 002EC4CC 5CCA0A0C */  jal        func_002b2970
    /* 1EC4D0 002EC4D0 00000000 */   nop
    /* 1EC4D4 002EC4D4 040021C6 */  lwc1       $f1, 0x4($17)
    /* 1EC4D8 002EC4D8 00009644 */  mtc1       $22, $f0
    /* 1EC4DC 002EC4DC 00000000 */  nop
    /* 1EC4E0 002EC4E0 20008046 */  cvt.s.w    $f0, $f0
    /* 1EC4E4 002EC4E4 400B0046 */  add.s      $f13, $f1, $f0
    /* 1EC4E8 002EC4E8 96C3023C */  lui        $2, (0xC3960000 >> 16)
    /* 1EC4EC 002EC4EC 00608244 */  mtc1       $2, $f12
    /* 1EC4F0 002EC4F0 7001A427 */  addiu      $4, $29, 0x170
    /* 1EC4F4 002EC4F4 5CCA0A0C */  jal        func_002b2970
    /* 1EC4F8 002EC4F8 00000000 */   nop
    /* 1EC4FC 002EC4FC 3C3E1400 */  dsll32     $7, $20, 24
    /* 1EC500 002EC500 3F3E0700 */  dsra32     $7, $7, 24
    /* 1EC504 002EC504 40101000 */  sll        $2, $16, 1
    /* 1EC508 002EC508 3C440200 */  dsll32     $8, $2, 16
    /* 1EC50C 002EC50C 3F440800 */  dsra32     $8, $8, 16
    /* 1EC510 002EC510 08002386 */  lh         $3, 0x8($17)
    /* 1EC514 002EC514 40100300 */  sll        $2, $3, 1
    /* 1EC518 002EC518 21104300 */  addu       $2, $2, $3
    /* 1EC51C 002EC51C 3E004224 */  addiu      $2, $2, 0x3E
    /* 1EC520 002EC520 3C4C0200 */  dsll32     $9, $2, 16
    /* 1EC524 002EC524 3F4C0900 */  dsra32     $9, $9, 16
    /* 1EC528 002EC528 0A002286 */  lh         $2, 0xA($17)
    /* 1EC52C 002EC52C 57004224 */  addiu      $2, $2, 0x57
    /* 1EC530 002EC530 3C540200 */  dsll32     $10, $2, 16
    /* 1EC534 002EC534 3F540A00 */  dsra32     $10, $10, 16
    /* 1EC538 002EC538 2D20A002 */  daddu      $4, $21, $0
    /* 1EC53C 002EC53C 7801A5DF */  ld         $5, 0x178($29)
    /* 1EC540 002EC540 7001A6DF */  ld         $6, 0x170($29)
    /* 1EC544 002EC544 405E0C0C */  jal        func_00317900
    /* 1EC548 002EC548 00000000 */   nop
  .L002EC54C:
    /* 1EC54C 002EC54C 07000224 */  addiu      $2, $0, 0x7
    /* 1EC550 002EC550 23185000 */  subu       $3, $2, $16
    /* 1EC554 002EC554 40100300 */  sll        $2, $3, 1
    /* 1EC558 002EC558 21104300 */  addu       $2, $2, $3
    /* 1EC55C 002EC55C 80180200 */  sll        $3, $2, 2
    /* 1EC560 002EC560 6400023C */  lui        $2, %hi(D_006407C0)
    /* 1EC564 002EC564 C0074224 */  addiu      $2, $2, %lo(D_006407C0)
    /* 1EC568 002EC568 21804300 */  addu       $16, $2, $3
    /* 1EC56C 002EC56C 39004016 */  bnez       $18, .L002EC654
    /* 1EC570 002EC570 00000000 */   nop
    /* 1EC574 002EC574 3C8C1400 */  dsll32     $17, $20, 16
    /* 1EC578 002EC578 3F8C1100 */  dsra32     $17, $17, 16
    /* 1EC57C 002EC57C 2F44023C */  lui        $2, (0x442F0000 >> 16)
    /* 1EC580 002EC580 00608244 */  mtc1       $2, $f12
    /* 1EC584 002EC584 040001C6 */  lwc1       $f1, 0x4($16)
    /* 1EC588 002EC588 C842023C */  lui        $2, (0x42C80000 >> 16)
    /* 1EC58C 002EC58C 00008244 */  mtc1       $2, $f0
    /* 1EC590 002EC590 00000000 */  nop
    /* 1EC594 002EC594 40030146 */  add.s      $f13, $f0, $f1
    /* 1EC598 002EC598 6801A427 */  addiu      $4, $29, 0x168
    /* 1EC59C 002EC59C 5CCA0A0C */  jal        func_002b2970
    /* 1EC5A0 002EC5A0 00000000 */   nop
    /* 1EC5A4 002EC5A4 6001A427 */  addiu      $4, $29, 0x160
    /* 1EC5A8 002EC5A8 00000CC6 */  lwc1       $f12, 0x0($16)
    /* 1EC5AC 002EC5AC 04000DC6 */  lwc1       $f13, 0x4($16)
    /* 1EC5B0 002EC5B0 5CCA0A0C */  jal        func_002b2970
    /* 1EC5B4 002EC5B4 00000000 */   nop
    /* 1EC5B8 002EC5B8 08000224 */  addiu      $2, $0, 0x8
    /* 1EC5BC 002EC5BC 23105100 */  subu       $2, $2, $17
    /* 1EC5C0 002EC5C0 3C3E0200 */  dsll32     $7, $2, 24
    /* 1EC5C4 002EC5C4 3F3E0700 */  dsra32     $7, $7, 24
    /* 1EC5C8 002EC5C8 80101100 */  sll        $2, $17, 2
    /* 1EC5CC 002EC5CC 02004224 */  addiu      $2, $2, 0x2
    /* 1EC5D0 002EC5D0 3C440200 */  dsll32     $8, $2, 16
    /* 1EC5D4 002EC5D4 3F440800 */  dsra32     $8, $8, 16
    /* 1EC5D8 002EC5D8 08000386 */  lh         $3, 0x8($16)
    /* 1EC5DC 002EC5DC 40100300 */  sll        $2, $3, 1
    /* 1EC5E0 002EC5E0 21104300 */  addu       $2, $2, $3
    /* 1EC5E4 002EC5E4 3E004224 */  addiu      $2, $2, 0x3E
    /* 1EC5E8 002EC5E8 3C4C0200 */  dsll32     $9, $2, 16
    /* 1EC5EC 002EC5EC 3F4C0900 */  dsra32     $9, $9, 16
    /* 1EC5F0 002EC5F0 0A000286 */  lh         $2, 0xA($16)
    /* 1EC5F4 002EC5F4 57004224 */  addiu      $2, $2, 0x57
    /* 1EC5F8 002EC5F8 3C540200 */  dsll32     $10, $2, 16
    /* 1EC5FC 002EC5FC 3F540A00 */  dsra32     $10, $10, 16
    /* 1EC600 002EC600 2D20A002 */  daddu      $4, $21, $0
    /* 1EC604 002EC604 6801A5DF */  ld         $5, 0x168($29)
    /* 1EC608 002EC608 6001A6DF */  ld         $6, 0x160($29)
    /* 1EC60C 002EC60C 405E0C0C */  jal        func_00317900
    /* 1EC610 002EC610 00000000 */   nop
    /* 1EC614 002EC614 06000224 */  addiu      $2, $0, 0x6
    /* 1EC618 002EC618 23185100 */  subu       $3, $2, $17
    /* 1EC61C 002EC61C 80100300 */  sll        $2, $3, 2
    /* 1EC620 002EC620 21104300 */  addu       $2, $2, $3
    /* 1EC624 002EC624 40100200 */  sll        $2, $2, 1
    /* 1EC628 002EC628 21206202 */  addu       $4, $19, $2
    /* 1EC62C 002EC62C 08000386 */  lh         $3, 0x8($16)
    /* 1EC630 002EC630 40100300 */  sll        $2, $3, 1
    /* 1EC634 002EC634 21104300 */  addu       $2, $2, $3
    /* 1EC638 002EC638 3E004224 */  addiu      $2, $2, 0x3E
    /* 1EC63C 002EC63C CA0082A4 */  sh         $2, 0xCA($4)
    /* 1EC640 002EC640 0A000286 */  lh         $2, 0xA($16)
    /* 1EC644 002EC644 57004224 */  addiu      $2, $2, 0x57
    /* 1EC648 002EC648 CC0082A4 */  sh         $2, 0xCC($4)
    /* 1EC64C 002EC64C 31000010 */  b          .L002EC714
    /* 1EC650 002EC650 00000000 */   nop
  .L002EC654:
    /* 1EC654 002EC654 18DC0E0C */  jal        func_003b7060
    /* 1EC658 002EC658 00000000 */   nop
    /* 1EC65C 002EC65C 2C010324 */  addiu      $3, $0, 0x12C
    /* 1EC660 002EC660 1B004300 */  divu       $0, $2, $3
    /* 1EC664 002EC664 10100000 */  mfhi       $2
    /* 1EC668 002EC668 6AFF4224 */  addiu      $2, $2, -0x96
    /* 1EC66C 002EC66C 3CB40200 */  dsll32     $22, $2, 16
    /* 1EC670 002EC670 3FB41600 */  dsra32     $22, $22, 16
    /* 1EC674 002EC674 3C8C1400 */  dsll32     $17, $20, 16
    /* 1EC678 002EC678 3F8C1100 */  dsra32     $17, $17, 16
    /* 1EC67C 002EC67C 5801A427 */  addiu      $4, $29, 0x158
    /* 1EC680 002EC680 00000CC6 */  lwc1       $f12, 0x0($16)
    /* 1EC684 002EC684 04000DC6 */  lwc1       $f13, 0x4($16)
    /* 1EC688 002EC688 5CCA0A0C */  jal        func_002b2970
    /* 1EC68C 002EC68C 00000000 */   nop
    /* 1EC690 002EC690 040001C6 */  lwc1       $f1, 0x4($16)
    /* 1EC694 002EC694 00009644 */  mtc1       $22, $f0
    /* 1EC698 002EC698 00000000 */  nop
    /* 1EC69C 002EC69C 20008046 */  cvt.s.w    $f0, $f0
    /* 1EC6A0 002EC6A0 400B0046 */  add.s      $f13, $f1, $f0
    /* 1EC6A4 002EC6A4 2F44023C */  lui        $2, (0x442F0000 >> 16)
    /* 1EC6A8 002EC6A8 00608244 */  mtc1       $2, $f12
    /* 1EC6AC 002EC6AC 5001A427 */  addiu      $4, $29, 0x150
    /* 1EC6B0 002EC6B0 5CCA0A0C */  jal        func_002b2970
    /* 1EC6B4 002EC6B4 00000000 */   nop
    /* 1EC6B8 002EC6B8 08000224 */  addiu      $2, $0, 0x8
    /* 1EC6BC 002EC6BC 23105100 */  subu       $2, $2, $17
    /* 1EC6C0 002EC6C0 3C3E0200 */  dsll32     $7, $2, 24
    /* 1EC6C4 002EC6C4 3F3E0700 */  dsra32     $7, $7, 24
    /* 1EC6C8 002EC6C8 40101100 */  sll        $2, $17, 1
    /* 1EC6CC 002EC6CC 01004224 */  addiu      $2, $2, 0x1
    /* 1EC6D0 002EC6D0 3C440200 */  dsll32     $8, $2, 16
    /* 1EC6D4 002EC6D4 3F440800 */  dsra32     $8, $8, 16
    /* 1EC6D8 002EC6D8 08000386 */  lh         $3, 0x8($16)
    /* 1EC6DC 002EC6DC 40100300 */  sll        $2, $3, 1
    /* 1EC6E0 002EC6E0 21104300 */  addu       $2, $2, $3
    /* 1EC6E4 002EC6E4 3E004224 */  addiu      $2, $2, 0x3E
    /* 1EC6E8 002EC6E8 3C4C0200 */  dsll32     $9, $2, 16
    /* 1EC6EC 002EC6EC 3F4C0900 */  dsra32     $9, $9, 16
    /* 1EC6F0 002EC6F0 0A000286 */  lh         $2, 0xA($16)
    /* 1EC6F4 002EC6F4 57004224 */  addiu      $2, $2, 0x57
    /* 1EC6F8 002EC6F8 3C540200 */  dsll32     $10, $2, 16
    /* 1EC6FC 002EC6FC 3F540A00 */  dsra32     $10, $10, 16
    /* 1EC700 002EC700 2D20A002 */  daddu      $4, $21, $0
    /* 1EC704 002EC704 5801A5DF */  ld         $5, 0x158($29)
    /* 1EC708 002EC708 5001A6DF */  ld         $6, 0x150($29)
    /* 1EC70C 002EC70C 405E0C0C */  jal        func_00317900
    /* 1EC710 002EC710 00000000 */   nop
  .L002EC714:
    /* 1EC714 002EC714 01008226 */  addiu      $2, $20, 0x1
    /* 1EC718 002EC718 3CA40200 */  dsll32     $20, $2, 16
    /* 1EC71C 002EC71C 3FA41400 */  dsra32     $20, $20, 16
  .L002EC720:
    /* 1EC720 002EC720 3C841400 */  dsll32     $16, $20, 16
    /* 1EC724 002EC724 3F841000 */  dsra32     $16, $16, 16
    /* 1EC728 002EC728 0300022A */  slti       $2, $16, 0x3
    /* 1EC72C 002EC72C 20FF4014 */  bnez       $2, .L002EC3B0
    /* 1EC730 002EC730 00000000 */   nop
    /* 1EC734 002EC734 6400113C */  lui        $17, %hi(D_006407F0)
    /* 1EC738 002EC738 F0073126 */  addiu      $17, $17, %lo(D_006407F0)
    /* 1EC73C 002EC73C 2B004016 */  bnez       $18, .L002EC7EC
    /* 1EC740 002EC740 00000000 */   nop
    /* 1EC744 002EC744 48C3023C */  lui        $2, (0xC3480000 >> 16)
    /* 1EC748 002EC748 00608244 */  mtc1       $2, $f12
    /* 1EC74C 002EC74C 040021C6 */  lwc1       $f1, 0x4($17)
    /* 1EC750 002EC750 C842023C */  lui        $2, (0x42C80000 >> 16)
    /* 1EC754 002EC754 00008244 */  mtc1       $2, $f0
    /* 1EC758 002EC758 00000000 */  nop
    /* 1EC75C 002EC75C 40030146 */  add.s      $f13, $f0, $f1
    /* 1EC760 002EC760 4801A427 */  addiu      $4, $29, 0x148
    /* 1EC764 002EC764 5CCA0A0C */  jal        func_002b2970
    /* 1EC768 002EC768 00000000 */   nop
    /* 1EC76C 002EC76C 4001A427 */  addiu      $4, $29, 0x140
    /* 1EC770 002EC770 00002CC6 */  lwc1       $f12, 0x0($17)
    /* 1EC774 002EC774 04002DC6 */  lwc1       $f13, 0x4($17)
    /* 1EC778 002EC778 5CCA0A0C */  jal        func_002b2970
    /* 1EC77C 002EC77C 00000000 */   nop
    /* 1EC780 002EC780 08002386 */  lh         $3, 0x8($17)
    /* 1EC784 002EC784 40100300 */  sll        $2, $3, 1
    /* 1EC788 002EC788 21104300 */  addu       $2, $2, $3
    /* 1EC78C 002EC78C 3E004224 */  addiu      $2, $2, 0x3E
    /* 1EC790 002EC790 3C4C0200 */  dsll32     $9, $2, 16
    /* 1EC794 002EC794 3F4C0900 */  dsra32     $9, $9, 16
    /* 1EC798 002EC798 0A002286 */  lh         $2, 0xA($17)
    /* 1EC79C 002EC79C 57004224 */  addiu      $2, $2, 0x57
    /* 1EC7A0 002EC7A0 3C540200 */  dsll32     $10, $2, 16
    /* 1EC7A4 002EC7A4 3F540A00 */  dsra32     $10, $10, 16
    /* 1EC7A8 002EC7A8 2D20A002 */  daddu      $4, $21, $0
    /* 1EC7AC 002EC7AC 4801A5DF */  ld         $5, 0x148($29)
    /* 1EC7B0 002EC7B0 4001A6DF */  ld         $6, 0x140($29)
    /* 1EC7B4 002EC7B4 03000724 */  addiu      $7, $0, 0x3
    /* 1EC7B8 002EC7B8 0C000824 */  addiu      $8, $0, 0xC
    /* 1EC7BC 002EC7BC 405E0C0C */  jal        func_00317900
    /* 1EC7C0 002EC7C0 00000000 */   nop
    /* 1EC7C4 002EC7C4 08002486 */  lh         $4, 0x8($17)
    /* 1EC7C8 002EC7C8 40180400 */  sll        $3, $4, 1
    /* 1EC7CC 002EC7CC 21186400 */  addu       $3, $3, $4
    /* 1EC7D0 002EC7D0 3E006324 */  addiu      $3, $3, 0x3E
    /* 1EC7D4 002EC7D4 E80063A6 */  sh         $3, 0xE8($19)
    /* 1EC7D8 002EC7D8 0A002386 */  lh         $3, 0xA($17)
    /* 1EC7DC 002EC7DC 57006324 */  addiu      $3, $3, 0x57
    /* 1EC7E0 002EC7E0 EA0063A6 */  sh         $3, 0xEA($19)
    /* 1EC7E4 002EC7E4 B8010010 */  b          .L002ECEC8
    /* 1EC7E8 002EC7E8 00000000 */   nop
  .L002EC7EC:
    /* 1EC7EC 002EC7EC 18DC0E0C */  jal        func_003b7060
    /* 1EC7F0 002EC7F0 00000000 */   nop
    /* 1EC7F4 002EC7F4 2C010324 */  addiu      $3, $0, 0x12C
    /* 1EC7F8 002EC7F8 1B004300 */  divu       $0, $2, $3
    /* 1EC7FC 002EC7FC 10100000 */  mfhi       $2
    /* 1EC800 002EC800 6AFF4224 */  addiu      $2, $2, -0x96
    /* 1EC804 002EC804 3C840200 */  dsll32     $16, $2, 16
    /* 1EC808 002EC808 3F841000 */  dsra32     $16, $16, 16
    /* 1EC80C 002EC80C 18DC0E0C */  jal        func_003b7060
    /* 1EC810 002EC810 00000000 */   nop
    /* 1EC814 002EC814 64000324 */  addiu      $3, $0, 0x64
    /* 1EC818 002EC818 1B004300 */  divu       $0, $2, $3
    /* 1EC81C 002EC81C 10100000 */  mfhi       $2
    /* 1EC820 002EC820 3200422C */  sltiu      $2, $2, 0x32
    /* 1EC824 002EC824 23004014 */  bnez       $2, .L002EC8B4
    /* 1EC828 002EC828 00000000 */   nop
    /* 1EC82C 002EC82C 3801A427 */  addiu      $4, $29, 0x138
    /* 1EC830 002EC830 00002CC6 */  lwc1       $f12, 0x0($17)
    /* 1EC834 002EC834 04002DC6 */  lwc1       $f13, 0x4($17)
    /* 1EC838 002EC838 5CCA0A0C */  jal        func_002b2970
    /* 1EC83C 002EC83C 00000000 */   nop
    /* 1EC840 002EC840 040021C6 */  lwc1       $f1, 0x4($17)
    /* 1EC844 002EC844 00009044 */  mtc1       $16, $f0
    /* 1EC848 002EC848 00000000 */  nop
    /* 1EC84C 002EC84C 20008046 */  cvt.s.w    $f0, $f0
    /* 1EC850 002EC850 400B0046 */  add.s      $f13, $f1, $f0
    /* 1EC854 002EC854 96C3023C */  lui        $2, (0xC3960000 >> 16)
    /* 1EC858 002EC858 00608244 */  mtc1       $2, $f12
    /* 1EC85C 002EC85C 3001A427 */  addiu      $4, $29, 0x130
    /* 1EC860 002EC860 5CCA0A0C */  jal        func_002b2970
    /* 1EC864 002EC864 00000000 */   nop
    /* 1EC868 002EC868 08002386 */  lh         $3, 0x8($17)
    /* 1EC86C 002EC86C 40100300 */  sll        $2, $3, 1
    /* 1EC870 002EC870 21104300 */  addu       $2, $2, $3
    /* 1EC874 002EC874 3E004224 */  addiu      $2, $2, 0x3E
    /* 1EC878 002EC878 3C4C0200 */  dsll32     $9, $2, 16
    /* 1EC87C 002EC87C 3F4C0900 */  dsra32     $9, $9, 16
    /* 1EC880 002EC880 0A002286 */  lh         $2, 0xA($17)
    /* 1EC884 002EC884 57004224 */  addiu      $2, $2, 0x57
    /* 1EC888 002EC888 3C540200 */  dsll32     $10, $2, 16
    /* 1EC88C 002EC88C 3F540A00 */  dsra32     $10, $10, 16
    /* 1EC890 002EC890 2D20A002 */  daddu      $4, $21, $0
    /* 1EC894 002EC894 3801A5DF */  ld         $5, 0x138($29)
    /* 1EC898 002EC898 3001A6DF */  ld         $6, 0x130($29)
    /* 1EC89C 002EC89C 03000724 */  addiu      $7, $0, 0x3
    /* 1EC8A0 002EC8A0 06000824 */  addiu      $8, $0, 0x6
    /* 1EC8A4 002EC8A4 405E0C0C */  jal        func_00317900
    /* 1EC8A8 002EC8A8 00000000 */   nop
    /* 1EC8AC 002EC8AC 86010010 */  b          .L002ECEC8
    /* 1EC8B0 002EC8B0 00000000 */   nop
  .L002EC8B4:
    /* 1EC8B4 002EC8B4 2801A427 */  addiu      $4, $29, 0x128
    /* 1EC8B8 002EC8B8 00002CC6 */  lwc1       $f12, 0x0($17)
    /* 1EC8BC 002EC8BC 04002DC6 */  lwc1       $f13, 0x4($17)
    /* 1EC8C0 002EC8C0 5CCA0A0C */  jal        func_002b2970
    /* 1EC8C4 002EC8C4 00000000 */   nop
    /* 1EC8C8 002EC8C8 040021C6 */  lwc1       $f1, 0x4($17)
    /* 1EC8CC 002EC8CC 00009044 */  mtc1       $16, $f0
    /* 1EC8D0 002EC8D0 00000000 */  nop
    /* 1EC8D4 002EC8D4 20008046 */  cvt.s.w    $f0, $f0
    /* 1EC8D8 002EC8D8 400B0046 */  add.s      $f13, $f1, $f0
    /* 1EC8DC 002EC8DC 2F44023C */  lui        $2, (0x442F0000 >> 16)
    /* 1EC8E0 002EC8E0 00608244 */  mtc1       $2, $f12
    /* 1EC8E4 002EC8E4 2001A427 */  addiu      $4, $29, 0x120
    /* 1EC8E8 002EC8E8 5CCA0A0C */  jal        func_002b2970
    /* 1EC8EC 002EC8EC 00000000 */   nop
    /* 1EC8F0 002EC8F0 08002386 */  lh         $3, 0x8($17)
    /* 1EC8F4 002EC8F4 40100300 */  sll        $2, $3, 1
    /* 1EC8F8 002EC8F8 21104300 */  addu       $2, $2, $3
    /* 1EC8FC 002EC8FC 3E004224 */  addiu      $2, $2, 0x3E
    /* 1EC900 002EC900 3C4C0200 */  dsll32     $9, $2, 16
    /* 1EC904 002EC904 3F4C0900 */  dsra32     $9, $9, 16
    /* 1EC908 002EC908 0A002286 */  lh         $2, 0xA($17)
    /* 1EC90C 002EC90C 57004224 */  addiu      $2, $2, 0x57
    /* 1EC910 002EC910 3C540200 */  dsll32     $10, $2, 16
    /* 1EC914 002EC914 3F540A00 */  dsra32     $10, $10, 16
    /* 1EC918 002EC918 2D20A002 */  daddu      $4, $21, $0
    /* 1EC91C 002EC91C 2801A5DF */  ld         $5, 0x128($29)
    /* 1EC920 002EC920 2001A6DF */  ld         $6, 0x120($29)
    /* 1EC924 002EC924 03000724 */  addiu      $7, $0, 0x3
    /* 1EC928 002EC928 06000824 */  addiu      $8, $0, 0x6
    /* 1EC92C 002EC92C 405E0C0C */  jal        func_00317900
    /* 1EC930 002EC930 00000000 */   nop
    /* 1EC934 002EC934 64010010 */  b          .L002ECEC8
    /* 1EC938 002EC938 00000000 */   nop
  .L002EC93C:
    /* 1EC93C 002EC93C 09000324 */  addiu      $3, $0, 0x9
    /* 1EC940 002EC940 61018314 */  bne        $4, $3, .L002ECEC8
    /* 1EC944 002EC944 00000000 */   nop
    /* 1EC948 002EC948 2DA00000 */  daddu      $20, $0, $0
    /* 1EC94C 002EC94C 3C961700 */  dsll32     $18, $23, 24
    /* 1EC950 002EC950 3F961200 */  dsra32     $18, $18, 24
    /* 1EC954 002EC954 D7000010 */  b          .L002ECCB4
    /* 1EC958 002EC958 00000000 */   nop
  .L002EC95C:
    /* 1EC95C 002EC95C 40101000 */  sll        $2, $16, 1
    /* 1EC960 002EC960 21105000 */  addu       $2, $2, $16
    /* 1EC964 002EC964 80180200 */  sll        $3, $2, 2
    /* 1EC968 002EC968 6400023C */  lui        $2, %hi(D_006407C0)
    /* 1EC96C 002EC96C C0074224 */  addiu      $2, $2, %lo(D_006407C0)
    /* 1EC970 002EC970 21884300 */  addu       $17, $2, $3
    /* 1EC974 002EC974 34004016 */  bnez       $18, .L002ECA48
    /* 1EC978 002EC978 00000000 */   nop
    /* 1EC97C 002EC97C 3CB41400 */  dsll32     $22, $20, 16
    /* 1EC980 002EC980 3FB41600 */  dsra32     $22, $22, 16
    /* 1EC984 002EC984 48C3023C */  lui        $2, (0xC3480000 >> 16)
    /* 1EC988 002EC988 00608244 */  mtc1       $2, $f12
    /* 1EC98C 002EC98C 040021C6 */  lwc1       $f1, 0x4($17)
    /* 1EC990 002EC990 C842023C */  lui        $2, (0x42C80000 >> 16)
    /* 1EC994 002EC994 00008244 */  mtc1       $2, $f0
    /* 1EC998 002EC998 00000000 */  nop
    /* 1EC99C 002EC99C 40030146 */  add.s      $f13, $f0, $f1
    /* 1EC9A0 002EC9A0 1801A427 */  addiu      $4, $29, 0x118
    /* 1EC9A4 002EC9A4 5CCA0A0C */  jal        func_002b2970
    /* 1EC9A8 002EC9A8 00000000 */   nop
    /* 1EC9AC 002EC9AC 1001A427 */  addiu      $4, $29, 0x110
    /* 1EC9B0 002EC9B0 00002CC6 */  lwc1       $f12, 0x0($17)
    /* 1EC9B4 002EC9B4 04002DC6 */  lwc1       $f13, 0x4($17)
    /* 1EC9B8 002EC9B8 5CCA0A0C */  jal        func_002b2970
    /* 1EC9BC 002EC9BC 00000000 */   nop
    /* 1EC9C0 002EC9C0 3C3E1400 */  dsll32     $7, $20, 24
    /* 1EC9C4 002EC9C4 3F3E0700 */  dsra32     $7, $7, 24
    /* 1EC9C8 002EC9C8 80101600 */  sll        $2, $22, 2
    /* 1EC9CC 002EC9CC 3C440200 */  dsll32     $8, $2, 16
    /* 1EC9D0 002EC9D0 3F440800 */  dsra32     $8, $8, 16
    /* 1EC9D4 002EC9D4 08002386 */  lh         $3, 0x8($17)
    /* 1EC9D8 002EC9D8 40100300 */  sll        $2, $3, 1
    /* 1EC9DC 002EC9DC 21104300 */  addu       $2, $2, $3
    /* 1EC9E0 002EC9E0 3E004224 */  addiu      $2, $2, 0x3E
    /* 1EC9E4 002EC9E4 3C4C0200 */  dsll32     $9, $2, 16
    /* 1EC9E8 002EC9E8 3F4C0900 */  dsra32     $9, $9, 16
    /* 1EC9EC 002EC9EC 0A002286 */  lh         $2, 0xA($17)
    /* 1EC9F0 002EC9F0 57004224 */  addiu      $2, $2, 0x57
    /* 1EC9F4 002EC9F4 3C540200 */  dsll32     $10, $2, 16
    /* 1EC9F8 002EC9F8 3F540A00 */  dsra32     $10, $10, 16
    /* 1EC9FC 002EC9FC 2D20A002 */  daddu      $4, $21, $0
    /* 1ECA00 002ECA00 1801A5DF */  ld         $5, 0x118($29)
    /* 1ECA04 002ECA04 1001A6DF */  ld         $6, 0x110($29)
    /* 1ECA08 002ECA08 405E0C0C */  jal        func_00317900
    /* 1ECA0C 002ECA0C 00000000 */   nop
    /* 1ECA10 002ECA10 80101600 */  sll        $2, $22, 2
    /* 1ECA14 002ECA14 21105600 */  addu       $2, $2, $22
    /* 1ECA18 002ECA18 40100200 */  sll        $2, $2, 1
    /* 1ECA1C 002ECA1C 21206202 */  addu       $4, $19, $2
    /* 1ECA20 002ECA20 08002386 */  lh         $3, 0x8($17)
    /* 1ECA24 002ECA24 40100300 */  sll        $2, $3, 1
    /* 1ECA28 002ECA28 21104300 */  addu       $2, $2, $3
    /* 1ECA2C 002ECA2C 3E004224 */  addiu      $2, $2, 0x3E
    /* 1ECA30 002ECA30 CA0082A4 */  sh         $2, 0xCA($4)
    /* 1ECA34 002ECA34 0A002286 */  lh         $2, 0xA($17)
    /* 1ECA38 002ECA38 57004224 */  addiu      $2, $2, 0x57
    /* 1ECA3C 002ECA3C CC0082A4 */  sh         $2, 0xCC($4)
    /* 1ECA40 002ECA40 2C000010 */  b          .L002ECAF4
    /* 1ECA44 002ECA44 00000000 */   nop
  .L002ECA48:
    /* 1ECA48 002ECA48 18DC0E0C */  jal        func_003b7060
    /* 1ECA4C 002ECA4C 00000000 */   nop
    /* 1ECA50 002ECA50 2C010324 */  addiu      $3, $0, 0x12C
    /* 1ECA54 002ECA54 1B004300 */  divu       $0, $2, $3
    /* 1ECA58 002ECA58 10100000 */  mfhi       $2
    /* 1ECA5C 002ECA5C 6AFF4224 */  addiu      $2, $2, -0x96
    /* 1ECA60 002ECA60 3CB40200 */  dsll32     $22, $2, 16
    /* 1ECA64 002ECA64 3FB41600 */  dsra32     $22, $22, 16
    /* 1ECA68 002ECA68 0801A427 */  addiu      $4, $29, 0x108
    /* 1ECA6C 002ECA6C 00002CC6 */  lwc1       $f12, 0x0($17)
    /* 1ECA70 002ECA70 04002DC6 */  lwc1       $f13, 0x4($17)
    /* 1ECA74 002ECA74 5CCA0A0C */  jal        func_002b2970
    /* 1ECA78 002ECA78 00000000 */   nop
    /* 1ECA7C 002ECA7C 040021C6 */  lwc1       $f1, 0x4($17)
    /* 1ECA80 002ECA80 00009644 */  mtc1       $22, $f0
    /* 1ECA84 002ECA84 00000000 */  nop
    /* 1ECA88 002ECA88 20008046 */  cvt.s.w    $f0, $f0
    /* 1ECA8C 002ECA8C 400B0046 */  add.s      $f13, $f1, $f0
    /* 1ECA90 002ECA90 96C3023C */  lui        $2, (0xC3960000 >> 16)
    /* 1ECA94 002ECA94 00608244 */  mtc1       $2, $f12
    /* 1ECA98 002ECA98 0001A427 */  addiu      $4, $29, 0x100
    /* 1ECA9C 002ECA9C 5CCA0A0C */  jal        func_002b2970
    /* 1ECAA0 002ECAA0 00000000 */   nop
    /* 1ECAA4 002ECAA4 3C3E1400 */  dsll32     $7, $20, 24
    /* 1ECAA8 002ECAA8 3F3E0700 */  dsra32     $7, $7, 24
    /* 1ECAAC 002ECAAC 40101000 */  sll        $2, $16, 1
    /* 1ECAB0 002ECAB0 3C440200 */  dsll32     $8, $2, 16
    /* 1ECAB4 002ECAB4 3F440800 */  dsra32     $8, $8, 16
    /* 1ECAB8 002ECAB8 08002386 */  lh         $3, 0x8($17)
    /* 1ECABC 002ECABC 40100300 */  sll        $2, $3, 1
    /* 1ECAC0 002ECAC0 21104300 */  addu       $2, $2, $3
    /* 1ECAC4 002ECAC4 3E004224 */  addiu      $2, $2, 0x3E
    /* 1ECAC8 002ECAC8 3C4C0200 */  dsll32     $9, $2, 16
    /* 1ECACC 002ECACC 3F4C0900 */  dsra32     $9, $9, 16
    /* 1ECAD0 002ECAD0 0A002286 */  lh         $2, 0xA($17)
    /* 1ECAD4 002ECAD4 57004224 */  addiu      $2, $2, 0x57
    /* 1ECAD8 002ECAD8 3C540200 */  dsll32     $10, $2, 16
    /* 1ECADC 002ECADC 3F540A00 */  dsra32     $10, $10, 16
    /* 1ECAE0 002ECAE0 2D20A002 */  daddu      $4, $21, $0
    /* 1ECAE4 002ECAE4 0801A5DF */  ld         $5, 0x108($29)
    /* 1ECAE8 002ECAE8 0001A6DF */  ld         $6, 0x100($29)
    /* 1ECAEC 002ECAEC 405E0C0C */  jal        func_00317900
    /* 1ECAF0 002ECAF0 00000000 */   nop
  .L002ECAF4:
    /* 1ECAF4 002ECAF4 08000424 */  addiu      $4, $0, 0x8
    /* 1ECAF8 002ECAF8 23809000 */  subu       $16, $4, $16
    /* 1ECAFC 002ECAFC 40101000 */  sll        $2, $16, 1
    /* 1ECB00 002ECB00 21105000 */  addu       $2, $2, $16
    /* 1ECB04 002ECB04 80180200 */  sll        $3, $2, 2
    /* 1ECB08 002ECB08 6400023C */  lui        $2, %hi(D_006407C0)
    /* 1ECB0C 002ECB0C C0074224 */  addiu      $2, $2, %lo(D_006407C0)
    /* 1ECB10 002ECB10 21884300 */  addu       $17, $2, $3
    /* 1ECB14 002ECB14 36004016 */  bnez       $18, .L002ECBF0
    /* 1ECB18 002ECB18 00000000 */   nop
    /* 1ECB1C 002ECB1C 3CB41400 */  dsll32     $22, $20, 16
    /* 1ECB20 002ECB20 3FB41600 */  dsra32     $22, $22, 16
    /* 1ECB24 002ECB24 23809600 */  subu       $16, $4, $22
    /* 1ECB28 002ECB28 2F44023C */  lui        $2, (0x442F0000 >> 16)
    /* 1ECB2C 002ECB2C 00608244 */  mtc1       $2, $f12
    /* 1ECB30 002ECB30 040021C6 */  lwc1       $f1, 0x4($17)
    /* 1ECB34 002ECB34 C842023C */  lui        $2, (0x42C80000 >> 16)
    /* 1ECB38 002ECB38 00008244 */  mtc1       $2, $f0
    /* 1ECB3C 002ECB3C 00000000 */  nop
    /* 1ECB40 002ECB40 40030146 */  add.s      $f13, $f0, $f1
    /* 1ECB44 002ECB44 F800A427 */  addiu      $4, $29, 0xF8
    /* 1ECB48 002ECB48 5CCA0A0C */  jal        func_002b2970
    /* 1ECB4C 002ECB4C 00000000 */   nop
    /* 1ECB50 002ECB50 F000A427 */  addiu      $4, $29, 0xF0
    /* 1ECB54 002ECB54 00002CC6 */  lwc1       $f12, 0x0($17)
    /* 1ECB58 002ECB58 04002DC6 */  lwc1       $f13, 0x4($17)
    /* 1ECB5C 002ECB5C 5CCA0A0C */  jal        func_002b2970
    /* 1ECB60 002ECB60 00000000 */   nop
    /* 1ECB64 002ECB64 3C3E1000 */  dsll32     $7, $16, 24
    /* 1ECB68 002ECB68 3F3E0700 */  dsra32     $7, $7, 24
    /* 1ECB6C 002ECB6C 80101600 */  sll        $2, $22, 2
    /* 1ECB70 002ECB70 02004224 */  addiu      $2, $2, 0x2
    /* 1ECB74 002ECB74 3C440200 */  dsll32     $8, $2, 16
    /* 1ECB78 002ECB78 3F440800 */  dsra32     $8, $8, 16
    /* 1ECB7C 002ECB7C 08002386 */  lh         $3, 0x8($17)
    /* 1ECB80 002ECB80 40100300 */  sll        $2, $3, 1
    /* 1ECB84 002ECB84 21104300 */  addu       $2, $2, $3
    /* 1ECB88 002ECB88 3E004224 */  addiu      $2, $2, 0x3E
    /* 1ECB8C 002ECB8C 3C4C0200 */  dsll32     $9, $2, 16
    /* 1ECB90 002ECB90 3F4C0900 */  dsra32     $9, $9, 16
    /* 1ECB94 002ECB94 0A002286 */  lh         $2, 0xA($17)
    /* 1ECB98 002ECB98 57004224 */  addiu      $2, $2, 0x57
    /* 1ECB9C 002ECB9C 3C540200 */  dsll32     $10, $2, 16
    /* 1ECBA0 002ECBA0 3F540A00 */  dsra32     $10, $10, 16
    /* 1ECBA4 002ECBA4 2D20A002 */  daddu      $4, $21, $0
    /* 1ECBA8 002ECBA8 F800A5DF */  ld         $5, 0xF8($29)
    /* 1ECBAC 002ECBAC F000A6DF */  ld         $6, 0xF0($29)
    /* 1ECBB0 002ECBB0 405E0C0C */  jal        func_00317900
    /* 1ECBB4 002ECBB4 00000000 */   nop
    /* 1ECBB8 002ECBB8 80101000 */  sll        $2, $16, 2
    /* 1ECBBC 002ECBBC 21105000 */  addu       $2, $2, $16
    /* 1ECBC0 002ECBC0 40100200 */  sll        $2, $2, 1
    /* 1ECBC4 002ECBC4 21206202 */  addu       $4, $19, $2
    /* 1ECBC8 002ECBC8 08002386 */  lh         $3, 0x8($17)
    /* 1ECBCC 002ECBCC 40100300 */  sll        $2, $3, 1
    /* 1ECBD0 002ECBD0 21104300 */  addu       $2, $2, $3
    /* 1ECBD4 002ECBD4 3E004224 */  addiu      $2, $2, 0x3E
    /* 1ECBD8 002ECBD8 CA0082A4 */  sh         $2, 0xCA($4)
    /* 1ECBDC 002ECBDC 0A002286 */  lh         $2, 0xA($17)
    /* 1ECBE0 002ECBE0 57004224 */  addiu      $2, $2, 0x57
    /* 1ECBE4 002ECBE4 CC0082A4 */  sh         $2, 0xCC($4)
    /* 1ECBE8 002ECBE8 2F000010 */  b          .L002ECCA8
    /* 1ECBEC 002ECBEC 00000000 */   nop
  .L002ECBF0:
    /* 1ECBF0 002ECBF0 18DC0E0C */  jal        func_003b7060
    /* 1ECBF4 002ECBF4 00000000 */   nop
    /* 1ECBF8 002ECBF8 2C010324 */  addiu      $3, $0, 0x12C
    /* 1ECBFC 002ECBFC 1B004300 */  divu       $0, $2, $3
    /* 1ECC00 002ECC00 10100000 */  mfhi       $2
    /* 1ECC04 002ECC04 6AFF4224 */  addiu      $2, $2, -0x96
    /* 1ECC08 002ECC08 3CB40200 */  dsll32     $22, $2, 16
    /* 1ECC0C 002ECC0C 3FB41600 */  dsra32     $22, $22, 16
    /* 1ECC10 002ECC10 3CF41400 */  dsll32     $30, $20, 16
    /* 1ECC14 002ECC14 3FF41E00 */  dsra32     $30, $30, 16
    /* 1ECC18 002ECC18 E800A427 */  addiu      $4, $29, 0xE8
    /* 1ECC1C 002ECC1C 00002CC6 */  lwc1       $f12, 0x0($17)
    /* 1ECC20 002ECC20 04002DC6 */  lwc1       $f13, 0x4($17)
    /* 1ECC24 002ECC24 5CCA0A0C */  jal        func_002b2970
    /* 1ECC28 002ECC28 00000000 */   nop
    /* 1ECC2C 002ECC2C 040021C6 */  lwc1       $f1, 0x4($17)
    /* 1ECC30 002ECC30 00009644 */  mtc1       $22, $f0
    /* 1ECC34 002ECC34 00000000 */  nop
    /* 1ECC38 002ECC38 20008046 */  cvt.s.w    $f0, $f0
    /* 1ECC3C 002ECC3C 400B0046 */  add.s      $f13, $f1, $f0
    /* 1ECC40 002ECC40 2F44023C */  lui        $2, (0x442F0000 >> 16)
    /* 1ECC44 002ECC44 00608244 */  mtc1       $2, $f12
    /* 1ECC48 002ECC48 E000A427 */  addiu      $4, $29, 0xE0
    /* 1ECC4C 002ECC4C 5CCA0A0C */  jal        func_002b2970
    /* 1ECC50 002ECC50 00000000 */   nop
    /* 1ECC54 002ECC54 3C3E1000 */  dsll32     $7, $16, 24
    /* 1ECC58 002ECC58 3F3E0700 */  dsra32     $7, $7, 24
    /* 1ECC5C 002ECC5C 40101E00 */  sll        $2, $30, 1
    /* 1ECC60 002ECC60 01004224 */  addiu      $2, $2, 0x1
    /* 1ECC64 002ECC64 3C440200 */  dsll32     $8, $2, 16
    /* 1ECC68 002ECC68 3F440800 */  dsra32     $8, $8, 16
    /* 1ECC6C 002ECC6C 08002386 */  lh         $3, 0x8($17)
    /* 1ECC70 002ECC70 40100300 */  sll        $2, $3, 1
    /* 1ECC74 002ECC74 21104300 */  addu       $2, $2, $3
    /* 1ECC78 002ECC78 3E004224 */  addiu      $2, $2, 0x3E
    /* 1ECC7C 002ECC7C 3C4C0200 */  dsll32     $9, $2, 16
    /* 1ECC80 002ECC80 3F4C0900 */  dsra32     $9, $9, 16
    /* 1ECC84 002ECC84 0A002286 */  lh         $2, 0xA($17)
    /* 1ECC88 002ECC88 57004224 */  addiu      $2, $2, 0x57
    /* 1ECC8C 002ECC8C 3C540200 */  dsll32     $10, $2, 16
    /* 1ECC90 002ECC90 3F540A00 */  dsra32     $10, $10, 16
    /* 1ECC94 002ECC94 2D20A002 */  daddu      $4, $21, $0
    /* 1ECC98 002ECC98 E800A5DF */  ld         $5, 0xE8($29)
    /* 1ECC9C 002ECC9C E000A6DF */  ld         $6, 0xE0($29)
    /* 1ECCA0 002ECCA0 405E0C0C */  jal        func_00317900
    /* 1ECCA4 002ECCA4 00000000 */   nop
  .L002ECCA8:
    /* 1ECCA8 002ECCA8 01008226 */  addiu      $2, $20, 0x1
    /* 1ECCAC 002ECCAC 3CA40200 */  dsll32     $20, $2, 16
    /* 1ECCB0 002ECCB0 3FA41400 */  dsra32     $20, $20, 16
  .L002ECCB4:
    /* 1ECCB4 002ECCB4 3C841400 */  dsll32     $16, $20, 16
    /* 1ECCB8 002ECCB8 3F841000 */  dsra32     $16, $16, 16
    /* 1ECCBC 002ECCBC 0400022A */  slti       $2, $16, 0x4
    /* 1ECCC0 002ECCC0 26FF4014 */  bnez       $2, .L002EC95C
    /* 1ECCC4 002ECCC4 00000000 */   nop
    /* 1ECCC8 002ECCC8 6400113C */  lui        $17, %hi(D_006407F0)
    /* 1ECCCC 002ECCCC F0073126 */  addiu      $17, $17, %lo(D_006407F0)
    /* 1ECCD0 002ECCD0 2B004016 */  bnez       $18, .L002ECD80
    /* 1ECCD4 002ECCD4 00000000 */   nop
    /* 1ECCD8 002ECCD8 48C3023C */  lui        $2, (0xC3480000 >> 16)
    /* 1ECCDC 002ECCDC 00608244 */  mtc1       $2, $f12
    /* 1ECCE0 002ECCE0 040021C6 */  lwc1       $f1, 0x4($17)
    /* 1ECCE4 002ECCE4 C842023C */  lui        $2, (0x42C80000 >> 16)
    /* 1ECCE8 002ECCE8 00008244 */  mtc1       $2, $f0
    /* 1ECCEC 002ECCEC 00000000 */  nop
    /* 1ECCF0 002ECCF0 40030146 */  add.s      $f13, $f0, $f1
    /* 1ECCF4 002ECCF4 D800A427 */  addiu      $4, $29, 0xD8
    /* 1ECCF8 002ECCF8 5CCA0A0C */  jal        func_002b2970
    /* 1ECCFC 002ECCFC 00000000 */   nop
    /* 1ECD00 002ECD00 D000A427 */  addiu      $4, $29, 0xD0
    /* 1ECD04 002ECD04 00002CC6 */  lwc1       $f12, 0x0($17)
    /* 1ECD08 002ECD08 04002DC6 */  lwc1       $f13, 0x4($17)
    /* 1ECD0C 002ECD0C 5CCA0A0C */  jal        func_002b2970
    /* 1ECD10 002ECD10 00000000 */   nop
    /* 1ECD14 002ECD14 08002386 */  lh         $3, 0x8($17)
    /* 1ECD18 002ECD18 40100300 */  sll        $2, $3, 1
    /* 1ECD1C 002ECD1C 21104300 */  addu       $2, $2, $3
    /* 1ECD20 002ECD20 3E004224 */  addiu      $2, $2, 0x3E
    /* 1ECD24 002ECD24 3C4C0200 */  dsll32     $9, $2, 16
    /* 1ECD28 002ECD28 3F4C0900 */  dsra32     $9, $9, 16
    /* 1ECD2C 002ECD2C 0A002286 */  lh         $2, 0xA($17)
    /* 1ECD30 002ECD30 57004224 */  addiu      $2, $2, 0x57
    /* 1ECD34 002ECD34 3C540200 */  dsll32     $10, $2, 16
    /* 1ECD38 002ECD38 3F540A00 */  dsra32     $10, $10, 16
    /* 1ECD3C 002ECD3C 2D20A002 */  daddu      $4, $21, $0
    /* 1ECD40 002ECD40 D800A5DF */  ld         $5, 0xD8($29)
    /* 1ECD44 002ECD44 D000A6DF */  ld         $6, 0xD0($29)
    /* 1ECD48 002ECD48 04000724 */  addiu      $7, $0, 0x4
    /* 1ECD4C 002ECD4C 10000824 */  addiu      $8, $0, 0x10
    /* 1ECD50 002ECD50 405E0C0C */  jal        func_00317900
    /* 1ECD54 002ECD54 00000000 */   nop
    /* 1ECD58 002ECD58 08002486 */  lh         $4, 0x8($17)
    /* 1ECD5C 002ECD5C 40180400 */  sll        $3, $4, 1
    /* 1ECD60 002ECD60 21186400 */  addu       $3, $3, $4
    /* 1ECD64 002ECD64 3E006324 */  addiu      $3, $3, 0x3E
    /* 1ECD68 002ECD68 F20063A6 */  sh         $3, 0xF2($19)
    /* 1ECD6C 002ECD6C 0A002386 */  lh         $3, 0xA($17)
    /* 1ECD70 002ECD70 57006324 */  addiu      $3, $3, 0x57
    /* 1ECD74 002ECD74 F40063A6 */  sh         $3, 0xF4($19)
    /* 1ECD78 002ECD78 53000010 */  b          .L002ECEC8
    /* 1ECD7C 002ECD7C 00000000 */   nop
  .L002ECD80:
    /* 1ECD80 002ECD80 18DC0E0C */  jal        func_003b7060
    /* 1ECD84 002ECD84 00000000 */   nop
    /* 1ECD88 002ECD88 2C010324 */  addiu      $3, $0, 0x12C
    /* 1ECD8C 002ECD8C 1B004300 */  divu       $0, $2, $3
    /* 1ECD90 002ECD90 10100000 */  mfhi       $2
    /* 1ECD94 002ECD94 6AFF4224 */  addiu      $2, $2, -0x96
    /* 1ECD98 002ECD98 3C840200 */  dsll32     $16, $2, 16
    /* 1ECD9C 002ECD9C 3F841000 */  dsra32     $16, $16, 16
    /* 1ECDA0 002ECDA0 18DC0E0C */  jal        func_003b7060
    /* 1ECDA4 002ECDA4 00000000 */   nop
    /* 1ECDA8 002ECDA8 64000324 */  addiu      $3, $0, 0x64
    /* 1ECDAC 002ECDAC 1B004300 */  divu       $0, $2, $3
    /* 1ECDB0 002ECDB0 10100000 */  mfhi       $2
    /* 1ECDB4 002ECDB4 3200422C */  sltiu      $2, $2, 0x32
    /* 1ECDB8 002ECDB8 23004014 */  bnez       $2, .L002ECE48
    /* 1ECDBC 002ECDBC 00000000 */   nop
    /* 1ECDC0 002ECDC0 C800A427 */  addiu      $4, $29, 0xC8
    /* 1ECDC4 002ECDC4 00002CC6 */  lwc1       $f12, 0x0($17)
    /* 1ECDC8 002ECDC8 04002DC6 */  lwc1       $f13, 0x4($17)
    /* 1ECDCC 002ECDCC 5CCA0A0C */  jal        func_002b2970
    /* 1ECDD0 002ECDD0 00000000 */   nop
    /* 1ECDD4 002ECDD4 040021C6 */  lwc1       $f1, 0x4($17)
    /* 1ECDD8 002ECDD8 00009044 */  mtc1       $16, $f0
    /* 1ECDDC 002ECDDC 00000000 */  nop
    /* 1ECDE0 002ECDE0 20008046 */  cvt.s.w    $f0, $f0
    /* 1ECDE4 002ECDE4 400B0046 */  add.s      $f13, $f1, $f0
    /* 1ECDE8 002ECDE8 96C3023C */  lui        $2, (0xC3960000 >> 16)
    /* 1ECDEC 002ECDEC 00608244 */  mtc1       $2, $f12
    /* 1ECDF0 002ECDF0 C000A427 */  addiu      $4, $29, 0xC0
    /* 1ECDF4 002ECDF4 5CCA0A0C */  jal        func_002b2970
    /* 1ECDF8 002ECDF8 00000000 */   nop
    /* 1ECDFC 002ECDFC 08002386 */  lh         $3, 0x8($17)
    /* 1ECE00 002ECE00 40100300 */  sll        $2, $3, 1
    /* 1ECE04 002ECE04 21104300 */  addu       $2, $2, $3
    /* 1ECE08 002ECE08 3E004224 */  addiu      $2, $2, 0x3E
    /* 1ECE0C 002ECE0C 3C4C0200 */  dsll32     $9, $2, 16
    /* 1ECE10 002ECE10 3F4C0900 */  dsra32     $9, $9, 16
    /* 1ECE14 002ECE14 0A002286 */  lh         $2, 0xA($17)
    /* 1ECE18 002ECE18 57004224 */  addiu      $2, $2, 0x57
    /* 1ECE1C 002ECE1C 3C540200 */  dsll32     $10, $2, 16
    /* 1ECE20 002ECE20 3F540A00 */  dsra32     $10, $10, 16
    /* 1ECE24 002ECE24 2D20A002 */  daddu      $4, $21, $0
    /* 1ECE28 002ECE28 C800A5DF */  ld         $5, 0xC8($29)
    /* 1ECE2C 002ECE2C C000A6DF */  ld         $6, 0xC0($29)
    /* 1ECE30 002ECE30 04000724 */  addiu      $7, $0, 0x4
    /* 1ECE34 002ECE34 08000824 */  addiu      $8, $0, 0x8
    /* 1ECE38 002ECE38 405E0C0C */  jal        func_00317900
    /* 1ECE3C 002ECE3C 00000000 */   nop
    /* 1ECE40 002ECE40 21000010 */  b          .L002ECEC8
    /* 1ECE44 002ECE44 00000000 */   nop
  .L002ECE48:
    /* 1ECE48 002ECE48 B800A427 */  addiu      $4, $29, 0xB8
    /* 1ECE4C 002ECE4C 00002CC6 */  lwc1       $f12, 0x0($17)
    /* 1ECE50 002ECE50 04002DC6 */  lwc1       $f13, 0x4($17)
    /* 1ECE54 002ECE54 5CCA0A0C */  jal        func_002b2970
    /* 1ECE58 002ECE58 00000000 */   nop
    /* 1ECE5C 002ECE5C 040021C6 */  lwc1       $f1, 0x4($17)
    /* 1ECE60 002ECE60 00009044 */  mtc1       $16, $f0
    /* 1ECE64 002ECE64 00000000 */  nop
    /* 1ECE68 002ECE68 20008046 */  cvt.s.w    $f0, $f0
    /* 1ECE6C 002ECE6C 400B0046 */  add.s      $f13, $f1, $f0
    /* 1ECE70 002ECE70 2F44023C */  lui        $2, (0x442F0000 >> 16)
    /* 1ECE74 002ECE74 00608244 */  mtc1       $2, $f12
    /* 1ECE78 002ECE78 B000A427 */  addiu      $4, $29, 0xB0
    /* 1ECE7C 002ECE7C 5CCA0A0C */  jal        func_002b2970
    /* 1ECE80 002ECE80 00000000 */   nop
    /* 1ECE84 002ECE84 08002386 */  lh         $3, 0x8($17)
    /* 1ECE88 002ECE88 40100300 */  sll        $2, $3, 1
    /* 1ECE8C 002ECE8C 21104300 */  addu       $2, $2, $3
    /* 1ECE90 002ECE90 3E004224 */  addiu      $2, $2, 0x3E
    /* 1ECE94 002ECE94 3C4C0200 */  dsll32     $9, $2, 16
    /* 1ECE98 002ECE98 3F4C0900 */  dsra32     $9, $9, 16
    /* 1ECE9C 002ECE9C 0A002286 */  lh         $2, 0xA($17)
    /* 1ECEA0 002ECEA0 57004224 */  addiu      $2, $2, 0x57
    /* 1ECEA4 002ECEA4 3C540200 */  dsll32     $10, $2, 16
    /* 1ECEA8 002ECEA8 3F540A00 */  dsra32     $10, $10, 16
    /* 1ECEAC 002ECEAC 2D20A002 */  daddu      $4, $21, $0
    /* 1ECEB0 002ECEB0 B800A5DF */  ld         $5, 0xB8($29)
    /* 1ECEB4 002ECEB4 B000A6DF */  ld         $6, 0xB0($29)
    /* 1ECEB8 002ECEB8 04000724 */  addiu      $7, $0, 0x4
    /* 1ECEBC 002ECEBC 08000824 */  addiu      $8, $0, 0x8
    /* 1ECEC0 002ECEC0 405E0C0C */  jal        func_00317900
    /* 1ECEC4 002ECEC4 00000000 */   nop
  .L002ECEC8:
    /* 1ECEC8 002ECEC8 3C261700 */  dsll32     $4, $23, 24
    /* 1ECECC 002ECECC 3F260400 */  dsra32     $4, $4, 24
    /* 1ECED0 002ECED0 01000324 */  addiu      $3, $0, 0x1
    /* 1ECED4 002ECED4 2B008314 */  bne        $4, $3, .L002ECF84
    /* 1ECED8 002ECED8 00000000 */   nop
    /* 1ECEDC 002ECEDC 16020424 */  addiu      $4, $0, 0x216
    /* 1ECEE0 002ECEE0 54D80A0C */  jal        func_002b6150
    /* 1ECEE4 002ECEE4 00000000 */   nop
    /* 1ECEE8 002ECEE8 730040A0 */  sb         $0, 0x73($2)
    /* 1ECEEC 002ECEEC 16020424 */  addiu      $4, $0, 0x216
    /* 1ECEF0 002ECEF0 54D80A0C */  jal        func_002b6150
    /* 1ECEF4 002ECEF4 00000000 */   nop
    /* 1ECEF8 002ECEF8 17020424 */  addiu      $4, $0, 0x217
    /* 1ECEFC 002ECEFC 54D80A0C */  jal        func_002b6150
    /* 1ECF00 002ECF00 00000000 */   nop
    /* 1ECF04 002ECF04 730040A0 */  sb         $0, 0x73($2)
    /* 1ECF08 002ECF08 17020424 */  addiu      $4, $0, 0x217
    /* 1ECF0C 002ECF0C 54D80A0C */  jal        func_002b6150
    /* 1ECF10 002ECF10 00000000 */   nop
    /* 1ECF14 002ECF14 18020424 */  addiu      $4, $0, 0x218
    /* 1ECF18 002ECF18 54D80A0C */  jal        func_002b6150
    /* 1ECF1C 002ECF1C 00000000 */   nop
    /* 1ECF20 002ECF20 730040A0 */  sb         $0, 0x73($2)
    /* 1ECF24 002ECF24 18020424 */  addiu      $4, $0, 0x218
    /* 1ECF28 002ECF28 54D80A0C */  jal        func_002b6150
    /* 1ECF2C 002ECF2C 00000000 */   nop
    /* 1ECF30 002ECF30 19020424 */  addiu      $4, $0, 0x219
    /* 1ECF34 002ECF34 54D80A0C */  jal        func_002b6150
    /* 1ECF38 002ECF38 00000000 */   nop
    /* 1ECF3C 002ECF3C 730040A0 */  sb         $0, 0x73($2)
    /* 1ECF40 002ECF40 19020424 */  addiu      $4, $0, 0x219
    /* 1ECF44 002ECF44 54D80A0C */  jal        func_002b6150
    /* 1ECF48 002ECF48 00000000 */   nop
    /* 1ECF4C 002ECF4C 1A020424 */  addiu      $4, $0, 0x21A
    /* 1ECF50 002ECF50 54D80A0C */  jal        func_002b6150
    /* 1ECF54 002ECF54 00000000 */   nop
    /* 1ECF58 002ECF58 730040A0 */  sb         $0, 0x73($2)
    /* 1ECF5C 002ECF5C 1A020424 */  addiu      $4, $0, 0x21A
    /* 1ECF60 002ECF60 54D80A0C */  jal        func_002b6150
    /* 1ECF64 002ECF64 00000000 */   nop
    /* 1ECF68 002ECF68 1B020424 */  addiu      $4, $0, 0x21B
    /* 1ECF6C 002ECF6C 54D80A0C */  jal        func_002b6150
    /* 1ECF70 002ECF70 00000000 */   nop
    /* 1ECF74 002ECF74 730040A0 */  sb         $0, 0x73($2)
    /* 1ECF78 002ECF78 1B020424 */  addiu      $4, $0, 0x21B
    /* 1ECF7C 002ECF7C 54D80A0C */  jal        func_002b6150
    /* 1ECF80 002ECF80 00000000 */   nop
  .L002ECF84:
    /* 1ECF84 002ECF84 A000BFDF */  ld         $31, 0xA0($29)
    /* 1ECF88 002ECF88 9000BE7B */  lq         $30, 0x90($29)
    /* 1ECF8C 002ECF8C 8000B77B */  lq         $23, 0x80($29)
    /* 1ECF90 002ECF90 7000B67B */  lq         $22, 0x70($29)
    /* 1ECF94 002ECF94 6000B57B */  lq         $21, 0x60($29)
    /* 1ECF98 002ECF98 5000B47B */  lq         $20, 0x50($29)
    /* 1ECF9C 002ECF9C 4000B37B */  lq         $19, 0x40($29)
    /* 1ECFA0 002ECFA0 3000B27B */  lq         $18, 0x30($29)
    /* 1ECFA4 002ECFA4 2000B17B */  lq         $17, 0x20($29)
    /* 1ECFA8 002ECFA8 1000B07B */  lq         $16, 0x10($29)
    /* 1ECFAC 002ECFAC 0000B4C7 */  lwc1       $f20, 0x0($29)
    /* 1ECFB0 002ECFB0 E002BD27 */  addiu      $29, $29, 0x2E0
    /* 1ECFB4 002ECFB4 0800E003 */  jr         $31
    /* 1ECFB8 002ECFB8 00000000 */   nop
    /* 1ECFBC 002ECFBC 00000000 */  nop
.size func_002eb270, 0x1d50
