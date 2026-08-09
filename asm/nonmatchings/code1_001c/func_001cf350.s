.section .text
.set noat
.set noreorder
glabel func_001cf350
    /* CF350 001CF350 E0FEBD27 */  addiu      $29, $29, -0x120
    /* CF354 001CF354 3000BFFF */  sd         $31, 0x30($29)
    /* CF358 001CF358 2000B17F */  sq         $17, 0x20($29)
    /* CF35C 001CF35C 1000B07F */  sq         $16, 0x10($29)
    /* CF360 001CF360 0400B5E7 */  swc1       $f21, 0x4($29)
    /* CF364 001CF364 0000B4E7 */  swc1       $f20, 0x0($29)
    /* CF368 001CF368 2D888000 */  daddu      $17, $4, $0
    /* CF36C 001CF36C ACB3828F */  lw         $2, -0x4C54($28)
    /* CF370 001CF370 7001428C */  lw         $2, 0x170($2)
    /* CF374 001CF374 3000508C */  lw         $16, 0x30($2)
    /* CF378 001CF378 03000424 */  addiu      $4, $0, 0x3
    /* CF37C 001CF37C 01000524 */  addiu      $5, $0, 0x1
    /* CF380 001CF380 D000A627 */  addiu      $6, $29, 0xD0
    /* CF384 001CF384 2D380000 */  daddu      $7, $0, $0
    /* CF388 001CF388 2D400000 */  daddu      $8, $0, $0
    /* CF38C 001CF38C 2D48A000 */  daddu      $9, $5, $0
    /* CF390 001CF390 1058060C */  jal        func_00196040
    /* CF394 001CF394 00000000 */   nop
    /* CF398 001CF398 46050046 */  mov.s      $f21, $f0
    /* CF39C 001CF39C 26020224 */  addiu      $2, $0, 0x226
    /* CF3A0 001CF3A0 00088244 */  mtc1       $2, $f1
    /* CF3A4 001CF3A4 00000000 */  nop
    /* CF3A8 001CF3A8 60088046 */  cvt.s.w    $f1, $f1
    /* CF3AC 001CF3AC 34000146 */  c.lt.s     $f0, $f1
    /* CF3B0 001CF3B0 02000045 */  bc1f       .L001CF3BC
    /* CF3B4 001CF3B4 00000000 */   nop
    /* CF3B8 001CF3B8 460D0046 */  mov.s      $f21, $f1
  .L001CF3BC:
    /* CF3BC 001CF3BC 2D200002 */  daddu      $4, $16, $0
    /* CF3C0 001CF3C0 1001A527 */  addiu      $5, $29, 0x110
    /* CF3C4 001CF3C4 3C56060C */  jal        func_001958f0
    /* CF3C8 001CF3C8 00000000 */   nop
    /* CF3CC 001CF3CC 1001A1C7 */  lwc1       $f1, 0x110($29)
    /* CF3D0 001CF3D0 D000A0C7 */  lwc1       $f0, 0xD0($29)
    /* CF3D4 001CF3D4 01080046 */  sub.s      $f0, $f1, $f0
    /* CF3D8 001CF3D8 0001A0E7 */  swc1       $f0, 0x100($29)
    /* CF3DC 001CF3DC 1401A1C7 */  lwc1       $f1, 0x114($29)
    /* CF3E0 001CF3E0 D400A0C7 */  lwc1       $f0, 0xD4($29)
    /* CF3E4 001CF3E4 01080046 */  sub.s      $f0, $f1, $f0
    /* CF3E8 001CF3E8 0401A0E7 */  swc1       $f0, 0x104($29)
    /* CF3EC 001CF3EC 1801A1C7 */  lwc1       $f1, 0x118($29)
    /* CF3F0 001CF3F0 D800A0C7 */  lwc1       $f0, 0xD8($29)
    /* CF3F4 001CF3F4 01080046 */  sub.s      $f0, $f1, $f0
    /* CF3F8 001CF3F8 0801A0E7 */  swc1       $f0, 0x108($29)
    /* CF3FC 001CF3FC 0001A427 */  addiu      $4, $29, 0x100
    /* CF400 001CF400 2D288000 */  daddu      $5, $4, $0
    /* CF404 001CF404 2C900F0C */  jal        func_003e40b0
    /* CF408 001CF408 00000000 */   nop
    /* CF40C 001CF40C 803E023C */  lui        $2, (0x3E800000 >> 16)
    /* CF410 001CF410 00088244 */  mtc1       $2, $f1
    /* CF414 001CF414 00000000 */  nop
    /* CF418 001CF418 42080046 */  mul.s      $f1, $f1, $f0
    /* CF41C 001CF41C 0001A0C7 */  lwc1       $f0, 0x100($29)
    /* CF420 001CF420 C2000146 */  mul.s      $f3, $f0, $f1
    /* CF424 001CF424 F000A3E7 */  swc1       $f3, 0xF0($29)
    /* CF428 001CF428 0401A0C7 */  lwc1       $f0, 0x104($29)
    /* CF42C 001CF42C 82000146 */  mul.s      $f2, $f0, $f1
    /* CF430 001CF430 F400A2E7 */  swc1       $f2, 0xF4($29)
    /* CF434 001CF434 0801A0C7 */  lwc1       $f0, 0x108($29)
    /* CF438 001CF438 42000146 */  mul.s      $f1, $f0, $f1
    /* CF43C 001CF43C F800A1E7 */  swc1       $f1, 0xF8($29)
    /* CF440 001CF440 D000A0C7 */  lwc1       $f0, 0xD0($29)
    /* CF444 001CF444 00000346 */  add.s      $f0, $f0, $f3
    /* CF448 001CF448 E000A0E7 */  swc1       $f0, 0xE0($29)
    /* CF44C 001CF44C D400A0C7 */  lwc1       $f0, 0xD4($29)
    /* CF450 001CF450 00000246 */  add.s      $f0, $f0, $f2
    /* CF454 001CF454 E400A0E7 */  swc1       $f0, 0xE4($29)
    /* CF458 001CF458 D800A0C7 */  lwc1       $f0, 0xD8($29)
    /* CF45C 001CF45C 00000146 */  add.s      $f0, $f0, $f1
    /* CF460 001CF460 E800A0E7 */  swc1       $f0, 0xE8($29)
    /* CF464 001CF464 E88080C7 */  lwc1       $f0, -0x7F18($28)
    /* CF468 001CF468 42AD0046 */  mul.s      $f21, $f21, $f0
    /* CF46C 001CF46C 003F023C */  lui        $2, (0x3F000000 >> 16)
    /* CF470 001CF470 00088244 */  mtc1       $2, $f1
    /* CF474 001CF474 B80020C6 */  lwc1       $f0, 0xB8($17)
    /* CF478 001CF478 42080046 */  mul.s      $f1, $f1, $f0
    /* CF47C 001CF47C 108180C7 */  lwc1       $f0, -0x7EF0($28)
    /* CF480 001CF480 02030146 */  mul.s      $f12, $f0, $f1
    /* CF484 001CF484 1A2E110C */  jal        func_0044b868
    /* CF488 001CF488 00000000 */   nop
    /* CF48C 001CF48C 00000000 */  nop
    /* CF490 001CF490 00000000 */  nop
    /* CF494 001CF494 03AD0046 */  div.s      $f20, $f21, $f0
    /* CF498 001CF498 0242023C */  lui        $2, (0x42020000 >> 16)
    /* CF49C 001CF49C 00608244 */  mtc1       $2, $f12
    /* CF4A0 001CF4A0 8000A427 */  addiu      $4, $29, 0x80
    /* CF4A4 001CF4A4 6100053C */  lui        $5, %hi(D_0060A0D0)
    /* CF4A8 001CF4A8 D0A0A524 */  addiu      $5, $5, %lo(D_0060A0D0)
    /* CF4AC 001CF4AC 2D300000 */  daddu      $6, $0, $0
    /* CF4B0 001CF4B0 1C820F0C */  jal        func_003e0870
    /* CF4B4 001CF4B4 00000000 */   nop
    /* CF4B8 001CF4B8 F000A427 */  addiu      $4, $29, 0xF0
    /* CF4BC 001CF4BC 6100053C */  lui        $5, %hi(D_0060A100)
    /* CF4C0 001CF4C0 00A1A524 */  addiu      $5, $5, %lo(D_0060A100)
    /* CF4C4 001CF4C4 8000A627 */  addiu      $6, $29, 0x80
    /* CF4C8 001CF4C8 C8900F0C */  jal        func_003e4320
    /* CF4CC 001CF4CC 00000000 */   nop
    /* CF4D0 001CF4D0 0001A427 */  addiu      $4, $29, 0x100
    /* CF4D4 001CF4D4 F000A527 */  addiu      $5, $29, 0xF0
    /* CF4D8 001CF4D8 01000624 */  addiu      $6, $0, 0x1
    /* CF4DC 001CF4DC 1C000726 */  addiu      $7, $16, 0x1C
    /* CF4E0 001CF4E0 D0720F0C */  jal        func_003dcb40
    /* CF4E4 001CF4E4 00000000 */   nop
    /* CF4E8 001CF4E8 0001A0C7 */  lwc1       $f0, 0x100($29)
    /* CF4EC 001CF4EC C2001546 */  mul.s      $f3, $f0, $f21
    /* CF4F0 001CF4F0 1001A3E7 */  swc1       $f3, 0x110($29)
    /* CF4F4 001CF4F4 0401A0C7 */  lwc1       $f0, 0x104($29)
    /* CF4F8 001CF4F8 82001546 */  mul.s      $f2, $f0, $f21
    /* CF4FC 001CF4FC 1401A2E7 */  swc1       $f2, 0x114($29)
    /* CF500 001CF500 0801A0C7 */  lwc1       $f0, 0x108($29)
    /* CF504 001CF504 42001546 */  mul.s      $f1, $f0, $f21
    /* CF508 001CF508 1801A1E7 */  swc1       $f1, 0x118($29)
    /* CF50C 001CF50C D000A0C7 */  lwc1       $f0, 0xD0($29)
    /* CF510 001CF510 00180046 */  add.s      $f0, $f3, $f0
    /* CF514 001CF514 1001A0E7 */  swc1       $f0, 0x110($29)
    /* CF518 001CF518 D400A0C7 */  lwc1       $f0, 0xD4($29)
    /* CF51C 001CF51C 00100046 */  add.s      $f0, $f2, $f0
    /* CF520 001CF520 1401A0E7 */  swc1       $f0, 0x114($29)
    /* CF524 001CF524 D800A0C7 */  lwc1       $f0, 0xD8($29)
    /* CF528 001CF528 00080046 */  add.s      $f0, $f1, $f0
    /* CF52C 001CF52C 1801A0E7 */  swc1       $f0, 0x118($29)
    /* CF530 001CF530 6800A427 */  addiu      $4, $29, 0x68
    /* CF534 001CF534 1001A527 */  addiu      $5, $29, 0x110
    /* CF538 001CF538 E000A627 */  addiu      $6, $29, 0xE0
    /* CF53C 001CF53C 6100073C */  lui        $7, %hi(D_0060A0E0)
    /* CF540 001CF540 E0A0E724 */  addiu      $7, $7, %lo(D_0060A0E0)
    /* CF544 001CF544 E0F5060C */  jal        func_001bd780
    /* CF548 001CF548 00000000 */   nop
    /* CF54C 001CF54C F000A427 */  addiu      $4, $29, 0xF0
    /* CF550 001CF550 6100053C */  lui        $5, %hi(D_0060A100)
    /* CF554 001CF554 00A1A524 */  addiu      $5, $5, %lo(D_0060A100)
    /* CF558 001CF558 01000624 */  addiu      $6, $0, 0x1
    /* CF55C 001CF55C 6800A727 */  addiu      $7, $29, 0x68
    /* CF560 001CF560 D0720F0C */  jal        func_003dcb40
    /* CF564 001CF564 00000000 */   nop
    /* CF568 001CF568 F000A0C7 */  lwc1       $f0, 0xF0($29)
    /* CF56C 001CF56C 02001446 */  mul.s      $f0, $f0, $f20
    /* CF570 001CF570 0001A0E7 */  swc1       $f0, 0x100($29)
    /* CF574 001CF574 F400A0C7 */  lwc1       $f0, 0xF4($29)
    /* CF578 001CF578 02001446 */  mul.s      $f0, $f0, $f20
    /* CF57C 001CF57C 0401A0E7 */  swc1       $f0, 0x104($29)
    /* CF580 001CF580 F800A0C7 */  lwc1       $f0, 0xF8($29)
    /* CF584 001CF584 02001446 */  mul.s      $f0, $f0, $f20
    /* CF588 001CF588 0801A0E7 */  swc1       $f0, 0x108($29)
    /* CF58C 001CF58C 003F023C */  lui        $2, (0x3F000000 >> 16)
    /* CF590 001CF590 00088244 */  mtc1       $2, $f1
    /* CF594 001CF594 B80020C6 */  lwc1       $f0, 0xB8($17)
    /* CF598 001CF598 42080046 */  mul.s      $f1, $f1, $f0
    /* CF59C 001CF59C 108180C7 */  lwc1       $f0, -0x7EF0($28)
    /* CF5A0 001CF5A0 02030146 */  mul.s      $f12, $f0, $f1
    /* CF5A4 001CF5A4 1A2E110C */  jal        func_0044b868
    /* CF5A8 001CF5A8 00000000 */   nop
    /* CF5AC 001CF5AC 42A00046 */  mul.s      $f1, $f20, $f0
    /* CF5B0 001CF5B0 603E023C */  lui        $2, (0x3E600000 >> 16)
    /* CF5B4 001CF5B4 00008244 */  mtc1       $2, $f0
    /* CF5B8 001CF5B8 00000000 */  nop
    /* CF5BC 001CF5BC 42080046 */  mul.s      $f1, $f1, $f0
    /* CF5C0 001CF5C0 E88080C7 */  lwc1       $f0, -0x7F18($28)
    /* CF5C4 001CF5C4 420D0046 */  mul.s      $f21, $f1, $f0
    /* CF5C8 001CF5C8 0001A0C7 */  lwc1       $f0, 0x100($29)
    /* CF5CC 001CF5CC C800A0E7 */  swc1       $f0, 0xC8($29)
    /* CF5D0 001CF5D0 0801A0C7 */  lwc1       $f0, 0x108($29)
    /* CF5D4 001CF5D4 CC00A0E7 */  swc1       $f0, 0xCC($29)
    /* CF5D8 001CF5D8 C800A427 */  addiu      $4, $29, 0xC8
    /* CF5DC 001CF5DC 2D288000 */  daddu      $5, $4, $0
    /* CF5E0 001CF5E0 78900F0C */  jal        func_003e41e0
    /* CF5E4 001CF5E4 00000000 */   nop
    /* CF5E8 001CF5E8 CC00A1C7 */  lwc1       $f1, 0xCC($29)
    /* CF5EC 001CF5EC E000A0C7 */  lwc1       $f0, 0xE0($29)
    /* CF5F0 001CF5F0 00608044 */  mtc1       $0, $f12
    /* CF5F4 001CF5F4 00000000 */  nop
    /* CF5F8 001CF5F8 18600046 */  adda.s     $f12, $f0
    /* CF5FC 001CF5FC 9C091546 */  madd.s     $f6, $f1, $f21
    /* CF600 001CF600 E000A6E7 */  swc1       $f6, 0xE0($29)
    /* CF604 001CF604 C800A1C7 */  lwc1       $f1, 0xC8($29)
    /* CF608 001CF608 E800A0C7 */  lwc1       $f0, 0xE8($29)
    /* CF60C 001CF60C 18600046 */  adda.s     $f12, $f0
    /* CF610 001CF610 5D091546 */  msub.s     $f5, $f1, $f21
    /* CF614 001CF614 E800A5E7 */  swc1       $f5, 0xE8($29)
    /* CF618 001CF618 0001A0C7 */  lwc1       $f0, 0x100($29)
    /* CF61C 001CF61C 00300046 */  add.s      $f0, $f6, $f0
    /* CF620 001CF620 5C00A0E7 */  swc1       $f0, 0x5C($29)
    /* CF624 001CF624 E400A4C7 */  lwc1       $f4, 0xE4($29)
    /* CF628 001CF628 0401A0C7 */  lwc1       $f0, 0x104($29)
    /* CF62C 001CF62C 00200046 */  add.s      $f0, $f4, $f0
    /* CF630 001CF630 6000A0E7 */  swc1       $f0, 0x60($29)
    /* CF634 001CF634 0801A0C7 */  lwc1       $f0, 0x108($29)
    /* CF638 001CF638 00280046 */  add.s      $f0, $f5, $f0
    /* CF63C 001CF63C 6400A0E7 */  swc1       $f0, 0x64($29)
    /* CF640 001CF640 6800A3C7 */  lwc1       $f3, 0x68($29)
    /* CF644 001CF644 6C00A2C7 */  lwc1       $f2, 0x6C($29)
    /* CF648 001CF648 7000A1C7 */  lwc1       $f1, 0x70($29)
    /* CF64C 001CF64C 7400A0C7 */  lwc1       $f0, 0x74($29)
    /* CF650 001CF650 4C00A3E7 */  swc1       $f3, 0x4C($29)
    /* CF654 001CF654 5000A2E7 */  swc1       $f2, 0x50($29)
    /* CF658 001CF658 5400A1E7 */  swc1       $f1, 0x54($29)
    /* CF65C 001CF65C 5800A0E7 */  swc1       $f0, 0x58($29)
    /* CF660 001CF660 C842023C */  lui        $2, (0x42C80000 >> 16)
    /* CF664 001CF664 00008244 */  mtc1       $2, $f0
    /* CF668 001CF668 00000000 */  nop
    /* CF66C 001CF66C 41A00046 */  sub.s      $f1, $f20, $f0
    /* CF670 001CF670 F000A0C7 */  lwc1       $f0, 0xF0($29)
    /* CF674 001CF674 C2000146 */  mul.s      $f3, $f0, $f1
    /* CF678 001CF678 0001A3E7 */  swc1       $f3, 0x100($29)
    /* CF67C 001CF67C F400A0C7 */  lwc1       $f0, 0xF4($29)
    /* CF680 001CF680 82000146 */  mul.s      $f2, $f0, $f1
    /* CF684 001CF684 0401A2E7 */  swc1       $f2, 0x104($29)
    /* CF688 001CF688 F800A0C7 */  lwc1       $f0, 0xF8($29)
    /* CF68C 001CF68C 42000146 */  mul.s      $f1, $f0, $f1
    /* CF690 001CF690 0801A1E7 */  swc1       $f1, 0x108($29)
    /* CF694 001CF694 00300346 */  add.s      $f0, $f6, $f3
    /* CF698 001CF698 4000A0E7 */  swc1       $f0, 0x40($29)
    /* CF69C 001CF69C 00200246 */  add.s      $f0, $f4, $f2
    /* CF6A0 001CF6A0 4400A0E7 */  swc1       $f0, 0x44($29)
    /* CF6A4 001CF6A4 00280146 */  add.s      $f0, $f5, $f1
    /* CF6A8 001CF6A8 4800A0E7 */  swc1       $f0, 0x48($29)
    /* CF6AC 001CF6AC 2D200000 */  daddu      $4, $0, $0
    /* CF6B0 001CF6B0 2D280000 */  daddu      $5, $0, $0
    /* CF6B4 001CF6B4 2D300000 */  daddu      $6, $0, $0
    /* CF6B8 001CF6B8 00010724 */  addiu      $7, $0, 0x100
    /* CF6BC 001CF6BC 50F3060C */  jal        func_001bcd40
    /* CF6C0 001CF6C0 00000000 */   nop
    /* CF6C4 001CF6C4 4000A427 */  addiu      $4, $29, 0x40
    /* CF6C8 001CF6C8 2D288000 */  daddu      $5, $4, $0
    /* CF6CC 001CF6CC E8F0060C */  jal        func_001bc3a0
    /* CF6D0 001CF6D0 00000000 */   nop
    /* CF6D4 001CF6D4 5C00A427 */  addiu      $4, $29, 0x5C
    /* CF6D8 001CF6D8 2D288000 */  daddu      $5, $4, $0
    /* CF6DC 001CF6DC E8F0060C */  jal        func_001bc3a0
    /* CF6E0 001CF6E0 00000000 */   nop
    /* CF6E4 001CF6E4 2D202002 */  daddu      $4, $17, $0
    /* CF6E8 001CF6E8 4000A527 */  addiu      $5, $29, 0x40
    /* CF6EC 001CF6EC 5C00A627 */  addiu      $6, $29, 0x5C
    /* CF6F0 001CF6F0 01000724 */  addiu      $7, $0, 0x1
    /* CF6F4 001CF6F4 08EB060C */  jal        func_001bac20
    /* CF6F8 001CF6F8 00000000 */   nop
    /* CF6FC 001CF6FC 4040023C */  lui        $2, (0x40400000 >> 16)
    /* CF700 001CF700 00608244 */  mtc1       $2, $f12
    /* CF704 001CF704 2D202002 */  daddu      $4, $17, $0
    /* CF708 001CF708 BCEF060C */  jal        func_001bbef0
    /* CF70C 001CF70C 00000000 */   nop
    /* CF710 001CF710 3000BFDF */  ld         $31, 0x30($29)
    /* CF714 001CF714 2000B17B */  lq         $17, 0x20($29)
    /* CF718 001CF718 1000B07B */  lq         $16, 0x10($29)
    /* CF71C 001CF71C 0400B5C7 */  lwc1       $f21, 0x4($29)
    /* CF720 001CF720 0000B4C7 */  lwc1       $f20, 0x0($29)
    /* CF724 001CF724 2001BD27 */  addiu      $29, $29, 0x120
    /* CF728 001CF728 0800E003 */  jr         $31
    /* CF72C 001CF72C 00000000 */   nop
.size func_001cf350, 0x3e0
