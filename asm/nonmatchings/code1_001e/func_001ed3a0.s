.section .text
.set noat
.set noreorder
glabel func_001ed3a0
    /* ED3A0 001ED3A0 70FFBD27 */  addiu      $29, $29, -0x90
    /* ED3A4 001ED3A4 6000BFFF */  sd         $31, 0x60($29)
    /* ED3A8 001ED3A8 5000B47F */  sq         $20, 0x50($29)
    /* ED3AC 001ED3AC 4000B37F */  sq         $19, 0x40($29)
    /* ED3B0 001ED3B0 3000B27F */  sq         $18, 0x30($29)
    /* ED3B4 001ED3B4 2000B17F */  sq         $17, 0x20($29)
    /* ED3B8 001ED3B8 1000B07F */  sq         $16, 0x10($29)
    /* ED3BC 001ED3BC 0000B4E7 */  swc1       $f20, 0x0($29)
    /* ED3C0 001ED3C0 2D808000 */  daddu      $16, $4, $0
    /* ED3C4 001ED3C4 06650046 */  mov.s      $f20, $f12
    /* ED3C8 001ED3C8 2D980000 */  daddu      $19, $0, $0
    /* ED3CC 001ED3CC ACB3828F */  lw         $2, -0x4C54($28)
    /* ED3D0 001ED3D0 1803548C */  lw         $20, 0x318($2)
    /* ED3D4 001ED3D4 3E000010 */  b          .L001ED4D0
    /* ED3D8 001ED3D8 00000000 */   nop
  .L001ED3DC:
    /* ED3DC 001ED3DC 2D900000 */  daddu      $18, $0, $0
    /* ED3E0 001ED3E0 36000010 */  b          .L001ED4BC
    /* ED3E4 001ED3E4 00000000 */   nop
  .L001ED3E8:
    /* ED3E8 001ED3E8 FFFF4332 */  andi       $3, $18, 0xFFFF
    /* ED3EC 001ED3EC C0100300 */  sll        $2, $3, 3
    /* ED3F0 001ED3F0 21104300 */  addu       $2, $2, $3
    /* ED3F4 001ED3F4 40100200 */  sll        $2, $2, 1
    /* ED3F8 001ED3F8 21104300 */  addu       $2, $2, $3
    /* ED3FC 001ED3FC 00110200 */  sll        $2, $2, 4
    /* ED400 001ED400 21108202 */  addu       $2, $20, $2
    /* ED404 001ED404 08005124 */  addiu      $17, $2, 0x8
    /* ED408 001ED408 2A003012 */  beq        $17, $16, .L001ED4B4
    /* ED40C 001ED40C 00000000 */   nop
    /* ED410 001ED410 1C0041C4 */  lwc1       $f1, 0x1C($2)
    /* ED414 001ED414 00008044 */  mtc1       $0, $f0
    /* ED418 001ED418 00000000 */  nop
    /* ED41C 001ED41C 36080046 */  c.le.s     $f1, $f0
    /* ED420 001ED420 24000145 */  bc1t       .L001ED4B4
    /* ED424 001ED424 00000000 */   nop
    /* ED428 001ED428 200040C4 */  lwc1       $f0, 0x20($2)
    /* ED42C 001ED42C 34001446 */  c.lt.s     $f0, $f20
    /* ED430 001ED430 20000145 */  bc1t       .L001ED4B4
    /* ED434 001ED434 00000000 */   nop
    /* ED438 001ED438 2D200002 */  daddu      $4, $16, $0
    /* ED43C 001ED43C 2D282002 */  daddu      $5, $17, $0
    /* ED440 001ED440 84B2070C */  jal        func_001eca10
    /* ED444 001ED444 00000000 */   nop
    /* ED448 001ED448 1A004014 */  bnez       $2, .L001ED4B4
    /* ED44C 001ED44C 00000000 */   nop
    /* ED450 001ED450 FFFF4332 */  andi       $3, $18, 0xFFFF
    /* ED454 001ED454 C0100300 */  sll        $2, $3, 3
    /* ED458 001ED458 21104300 */  addu       $2, $2, $3
    /* ED45C 001ED45C 40100200 */  sll        $2, $2, 1
    /* ED460 001ED460 21104300 */  addu       $2, $2, $3
    /* ED464 001ED464 00110200 */  sll        $2, $2, 4
    /* ED468 001ED468 21108202 */  addu       $2, $20, $2
    /* ED46C 001ED46C 080001C6 */  lwc1       $f1, 0x8($16)
    /* ED470 001ED470 100040C4 */  lwc1       $f0, 0x10($2)
    /* ED474 001ED474 01080046 */  sub.s      $f0, $f1, $f0
    /* ED478 001ED478 8800A0E7 */  swc1       $f0, 0x88($29)
    /* ED47C 001ED47C 0C0001C6 */  lwc1       $f1, 0xC($16)
    /* ED480 001ED480 140040C4 */  lwc1       $f0, 0x14($2)
    /* ED484 001ED484 01080046 */  sub.s      $f0, $f1, $f0
    /* ED488 001ED488 8C00A0E7 */  swc1       $f0, 0x8C($29)
    /* ED48C 001ED48C 8800A427 */  addiu      $4, $29, 0x88
    /* ED490 001ED490 6C900F0C */  jal        func_003e41b0
    /* ED494 001ED494 00000000 */   nop
    /* ED498 001ED498 FFFF6232 */  andi       $2, $19, 0xFFFF
    /* ED49C 001ED49C 80100200 */  sll        $2, $2, 2
    /* ED4A0 001ED4A0 21100202 */  addu       $2, $16, $2
    /* ED4A4 001ED4A4 B00040E4 */  swc1       $f0, 0xB0($2)
    /* ED4A8 001ED4A8 300051AC */  sw         $17, 0x30($2)
    /* ED4AC 001ED4AC 01006226 */  addiu      $2, $19, 0x1
    /* ED4B0 001ED4B0 FFFF5330 */  andi       $19, $2, 0xFFFF
  .L001ED4B4:
    /* ED4B4 001ED4B4 01004226 */  addiu      $2, $18, 0x1
    /* ED4B8 001ED4B8 FFFF5230 */  andi       $18, $2, 0xFFFF
  .L001ED4BC:
    /* ED4BC 001ED4BC FFFF4232 */  andi       $2, $18, 0xFFFF
    /* ED4C0 001ED4C0 04004228 */  slti       $2, $2, 0x4
    /* ED4C4 001ED4C4 C8FF4014 */  bnez       $2, .L001ED3E8
    /* ED4C8 001ED4C8 00000000 */   nop
    /* ED4CC 001ED4CC CC04948E */  lw         $20, 0x4CC($20)
  .L001ED4D0:
    /* ED4D0 001ED4D0 C2FF8016 */  bnez       $20, .L001ED3DC
    /* ED4D4 001ED4D4 00000000 */   nop
    /* ED4D8 001ED4D8 2D900000 */  daddu      $18, $0, $0
    /* ED4DC 001ED4DC 36000010 */  b          .L001ED5B8
    /* ED4E0 001ED4E0 00000000 */   nop
  .L001ED4E4:
    /* ED4E4 001ED4E4 FFFF4332 */  andi       $3, $18, 0xFFFF
    /* ED4E8 001ED4E8 C0100300 */  sll        $2, $3, 3
    /* ED4EC 001ED4EC 21104300 */  addu       $2, $2, $3
    /* ED4F0 001ED4F0 40100200 */  sll        $2, $2, 1
    /* ED4F4 001ED4F4 21104300 */  addu       $2, $2, $3
    /* ED4F8 001ED4F8 00190200 */  sll        $3, $2, 4
    /* ED4FC 001ED4FC ACB3828F */  lw         $2, -0x4C54($28)
    /* ED500 001ED500 21104300 */  addu       $2, $2, $3
    /* ED504 001ED504 1C034524 */  addiu      $5, $2, 0x31C
    /* ED508 001ED508 2900B010 */  beq        $5, $16, .L001ED5B0
    /* ED50C 001ED50C 00000000 */   nop
    /* ED510 001ED510 300341C4 */  lwc1       $f1, 0x330($2)
    /* ED514 001ED514 00008044 */  mtc1       $0, $f0
    /* ED518 001ED518 00000000 */  nop
    /* ED51C 001ED51C 36080046 */  c.le.s     $f1, $f0
    /* ED520 001ED520 23000145 */  bc1t       .L001ED5B0
    /* ED524 001ED524 00000000 */   nop
    /* ED528 001ED528 2D200002 */  daddu      $4, $16, $0
    /* ED52C 001ED52C 84B2070C */  jal        func_001eca10
    /* ED530 001ED530 00000000 */   nop
    /* ED534 001ED534 1E004014 */  bnez       $2, .L001ED5B0
    /* ED538 001ED538 00000000 */   nop
    /* ED53C 001ED53C FFFF4332 */  andi       $3, $18, 0xFFFF
    /* ED540 001ED540 C0100300 */  sll        $2, $3, 3
    /* ED544 001ED544 21104300 */  addu       $2, $2, $3
    /* ED548 001ED548 40100200 */  sll        $2, $2, 1
    /* ED54C 001ED54C 21104300 */  addu       $2, $2, $3
    /* ED550 001ED550 00890200 */  sll        $17, $2, 4
    /* ED554 001ED554 ACB3828F */  lw         $2, -0x4C54($28)
    /* ED558 001ED558 21105100 */  addu       $2, $2, $17
    /* ED55C 001ED55C 080001C6 */  lwc1       $f1, 0x8($16)
    /* ED560 001ED560 240340C4 */  lwc1       $f0, 0x324($2)
    /* ED564 001ED564 01080046 */  sub.s      $f0, $f1, $f0
    /* ED568 001ED568 8000A0E7 */  swc1       $f0, 0x80($29)
    /* ED56C 001ED56C 0C0001C6 */  lwc1       $f1, 0xC($16)
    /* ED570 001ED570 280340C4 */  lwc1       $f0, 0x328($2)
    /* ED574 001ED574 01080046 */  sub.s      $f0, $f1, $f0
    /* ED578 001ED578 8400A0E7 */  swc1       $f0, 0x84($29)
    /* ED57C 001ED57C 8000A427 */  addiu      $4, $29, 0x80
    /* ED580 001ED580 6C900F0C */  jal        func_003e41b0
    /* ED584 001ED584 00000000 */   nop
    /* ED588 001ED588 FFFF6232 */  andi       $2, $19, 0xFFFF
    /* ED58C 001ED58C 80100200 */  sll        $2, $2, 2
    /* ED590 001ED590 21180202 */  addu       $3, $16, $2
    /* ED594 001ED594 B00060E4 */  swc1       $f0, 0xB0($3)
    /* ED598 001ED598 ACB3828F */  lw         $2, -0x4C54($28)
    /* ED59C 001ED59C 21105100 */  addu       $2, $2, $17
    /* ED5A0 001ED5A0 1C034224 */  addiu      $2, $2, 0x31C
    /* ED5A4 001ED5A4 300062AC */  sw         $2, 0x30($3)
    /* ED5A8 001ED5A8 01006226 */  addiu      $2, $19, 0x1
    /* ED5AC 001ED5AC FFFF5330 */  andi       $19, $2, 0xFFFF
  .L001ED5B0:
    /* ED5B0 001ED5B0 01004226 */  addiu      $2, $18, 0x1
    /* ED5B4 001ED5B4 FFFF5230 */  andi       $18, $2, 0xFFFF
  .L001ED5B8:
    /* ED5B8 001ED5B8 FFFF4232 */  andi       $2, $18, 0xFFFF
    /* ED5BC 001ED5BC 04004228 */  slti       $2, $2, 0x4
    /* ED5C0 001ED5C0 C8FF4014 */  bnez       $2, .L001ED4E4
    /* ED5C4 001ED5C4 00000000 */   nop
    /* ED5C8 001ED5C8 ACB3828F */  lw         $2, -0x4C54($28)
    /* ED5CC 001ED5CC DC074524 */  addiu      $5, $2, 0x7DC
    /* ED5D0 001ED5D0 1B00B010 */  beq        $5, $16, .L001ED640
    /* ED5D4 001ED5D4 00000000 */   nop
    /* ED5D8 001ED5D8 2D200002 */  daddu      $4, $16, $0
    /* ED5DC 001ED5DC 84B2070C */  jal        func_001eca10
    /* ED5E0 001ED5E0 00000000 */   nop
    /* ED5E4 001ED5E4 16004014 */  bnez       $2, .L001ED640
    /* ED5E8 001ED5E8 00000000 */   nop
    /* ED5EC 001ED5EC ACB3828F */  lw         $2, -0x4C54($28)
    /* ED5F0 001ED5F0 080001C6 */  lwc1       $f1, 0x8($16)
    /* ED5F4 001ED5F4 E40740C4 */  lwc1       $f0, 0x7E4($2)
    /* ED5F8 001ED5F8 01080046 */  sub.s      $f0, $f1, $f0
    /* ED5FC 001ED5FC 7800A0E7 */  swc1       $f0, 0x78($29)
    /* ED600 001ED600 0C0001C6 */  lwc1       $f1, 0xC($16)
    /* ED604 001ED604 E80740C4 */  lwc1       $f0, 0x7E8($2)
    /* ED608 001ED608 01080046 */  sub.s      $f0, $f1, $f0
    /* ED60C 001ED60C 7C00A0E7 */  swc1       $f0, 0x7C($29)
    /* ED610 001ED610 7800A427 */  addiu      $4, $29, 0x78
    /* ED614 001ED614 6C900F0C */  jal        func_003e41b0
    /* ED618 001ED618 00000000 */   nop
    /* ED61C 001ED61C FFFF6232 */  andi       $2, $19, 0xFFFF
    /* ED620 001ED620 80100200 */  sll        $2, $2, 2
    /* ED624 001ED624 21185000 */  addu       $3, $2, $16
    /* ED628 001ED628 B00060E4 */  swc1       $f0, 0xB0($3)
    /* ED62C 001ED62C ACB3828F */  lw         $2, -0x4C54($28)
    /* ED630 001ED630 DC074224 */  addiu      $2, $2, 0x7DC
    /* ED634 001ED634 300062AC */  sw         $2, 0x30($3)
    /* ED638 001ED638 01006226 */  addiu      $2, $19, 0x1
    /* ED63C 001ED63C FFFF5330 */  andi       $19, $2, 0xFFFF
  .L001ED640:
    /* ED640 001ED640 ACB3828F */  lw         $2, -0x4C54($28)
    /* ED644 001ED644 0C094524 */  addiu      $5, $2, 0x90C
    /* ED648 001ED648 1B00B010 */  beq        $5, $16, .L001ED6B8
    /* ED64C 001ED64C 00000000 */   nop
    /* ED650 001ED650 2D200002 */  daddu      $4, $16, $0
    /* ED654 001ED654 84B2070C */  jal        func_001eca10
    /* ED658 001ED658 00000000 */   nop
    /* ED65C 001ED65C 16004014 */  bnez       $2, .L001ED6B8
    /* ED660 001ED660 00000000 */   nop
    /* ED664 001ED664 ACB3828F */  lw         $2, -0x4C54($28)
    /* ED668 001ED668 080001C6 */  lwc1       $f1, 0x8($16)
    /* ED66C 001ED66C 140940C4 */  lwc1       $f0, 0x914($2)
    /* ED670 001ED670 01080046 */  sub.s      $f0, $f1, $f0
    /* ED674 001ED674 7000A0E7 */  swc1       $f0, 0x70($29)
    /* ED678 001ED678 0C0001C6 */  lwc1       $f1, 0xC($16)
    /* ED67C 001ED67C 180940C4 */  lwc1       $f0, 0x918($2)
    /* ED680 001ED680 01080046 */  sub.s      $f0, $f1, $f0
    /* ED684 001ED684 7400A0E7 */  swc1       $f0, 0x74($29)
    /* ED688 001ED688 7000A427 */  addiu      $4, $29, 0x70
    /* ED68C 001ED68C 6C900F0C */  jal        func_003e41b0
    /* ED690 001ED690 00000000 */   nop
    /* ED694 001ED694 FFFF6232 */  andi       $2, $19, 0xFFFF
    /* ED698 001ED698 80100200 */  sll        $2, $2, 2
    /* ED69C 001ED69C 21185000 */  addu       $3, $2, $16
    /* ED6A0 001ED6A0 B00060E4 */  swc1       $f0, 0xB0($3)
    /* ED6A4 001ED6A4 ACB3828F */  lw         $2, -0x4C54($28)
    /* ED6A8 001ED6A8 0C094224 */  addiu      $2, $2, 0x90C
    /* ED6AC 001ED6AC 300062AC */  sw         $2, 0x30($3)
    /* ED6B0 001ED6B0 01006226 */  addiu      $2, $19, 0x1
    /* ED6B4 001ED6B4 FFFF5330 */  andi       $19, $2, 0xFFFF
  .L001ED6B8:
    /* ED6B8 001ED6B8 FFFF6232 */  andi       $2, $19, 0xFFFF
    /* ED6BC 001ED6BC 80100200 */  sll        $2, $2, 2
    /* ED6C0 001ED6C0 21105000 */  addu       $2, $2, $16
    /* ED6C4 001ED6C4 300040AC */  sw         $0, 0x30($2)
    /* ED6C8 001ED6C8 2D106002 */  daddu      $2, $19, $0
    /* ED6CC 001ED6CC 6000BFDF */  ld         $31, 0x60($29)
    /* ED6D0 001ED6D0 5000B47B */  lq         $20, 0x50($29)
    /* ED6D4 001ED6D4 4000B37B */  lq         $19, 0x40($29)
    /* ED6D8 001ED6D8 3000B27B */  lq         $18, 0x30($29)
    /* ED6DC 001ED6DC 2000B17B */  lq         $17, 0x20($29)
    /* ED6E0 001ED6E0 1000B07B */  lq         $16, 0x10($29)
    /* ED6E4 001ED6E4 0000B4C7 */  lwc1       $f20, 0x0($29)
    /* ED6E8 001ED6E8 9000BD27 */  addiu      $29, $29, 0x90
    /* ED6EC 001ED6EC 0800E003 */  jr         $31
    /* ED6F0 001ED6F0 00000000 */   nop
    /* ED6F4 001ED6F4 00000000 */  nop
    /* ED6F8 001ED6F8 00000000 */  nop
    /* ED6FC 001ED6FC 00000000 */  nop
.size func_001ed3a0, 0x360
