.section .text
.set noat
.set noreorder
glabel func_002dd3b0
    /* 1DD3B0 002DD3B0 90FEBD27 */  addiu      $29, $29, -0x170
    /* 1DD3B4 002DD3B4 4000BFFF */  sd         $31, 0x40($29)
    /* 1DD3B8 002DD3B8 3000B27F */  sq         $18, 0x30($29)
    /* 1DD3BC 002DD3BC 2000B17F */  sq         $17, 0x20($29)
    /* 1DD3C0 002DD3C0 1000B07F */  sq         $16, 0x10($29)
    /* 1DD3C4 002DD3C4 3800928C */  lw         $18, 0x38($4)
    /* 1DD3C8 002DD3C8 240C4382 */  lb         $3, 0xC24($18)
    /* 1DD3CC 002DD3CC 6D046010 */  beqz       $3, .L002DE584
    /* 1DD3D0 002DD3D0 00000000 */   nop
    /* 1DD3D4 002DD3D4 11004282 */  lb         $2, 0x11($18)
    /* 1DD3D8 002DD3D8 80100200 */  sll        $2, $2, 2
    /* 1DD3DC 002DD3DC 21105200 */  addu       $2, $2, $18
    /* 1DD3E0 002DD3E0 180F448C */  lw         $4, 0xF18($2)
    /* 1DD3E4 002DD3E4 BC890B0C */  jal        func_002e26f0
    /* 1DD3E8 002DD3E8 00000000 */   nop
    /* 1DD3EC 002DD3EC 02004228 */  slti       $2, $2, 0x2
    /* 1DD3F0 002DD3F0 6F004014 */  bnez       $2, .L002DD5B0
    /* 1DD3F4 002DD3F4 00000000 */   nop
    /* 1DD3F8 002DD3F8 11004282 */  lb         $2, 0x11($18)
    /* 1DD3FC 002DD3FC 2C004014 */  bnez       $2, .L002DD4B0
    /* 1DD400 002DD400 00000000 */   nop
    /* 1DD404 002DD404 80100200 */  sll        $2, $2, 2
    /* 1DD408 002DD408 21105200 */  addu       $2, $2, $18
    /* 1DD40C 002DD40C 180F448C */  lw         $4, 0xF18($2)
    /* 1DD410 002DD410 BC890B0C */  jal        func_002e26f0
    /* 1DD414 002DD414 00000000 */   nop
    /* 1DD418 002DD418 03004228 */  slti       $2, $2, 0x3
    /* 1DD41C 002DD41C 14004014 */  bnez       $2, .L002DD470
    /* 1DD420 002DD420 00000000 */   nop
    /* 1DD424 002DD424 11004282 */  lb         $2, 0x11($18)
    /* 1DD428 002DD428 80100200 */  sll        $2, $2, 2
    /* 1DD42C 002DD42C 21105200 */  addu       $2, $2, $18
    /* 1DD430 002DD430 180F448C */  lw         $4, 0xF18($2)
    /* 1DD434 002DD434 BC890B0C */  jal        func_002e26f0
    /* 1DD438 002DD438 00000000 */   nop
    /* 1DD43C 002DD43C FEFF4224 */  addiu      $2, $2, -0x2
    /* 1DD440 002DD440 00008244 */  mtc1       $2, $f0
    /* 1DD444 002DD444 00000000 */  nop
    /* 1DD448 002DD448 60008046 */  cvt.s.w    $f1, $f0
    /* 1DD44C 002DD44C B642023C */  lui        $2, (0x42B60000 >> 16)
    /* 1DD450 002DD450 00008244 */  mtc1       $2, $f0
    /* 1DD454 002DD454 00000000 */  nop
    /* 1DD458 002DD458 03000146 */  div.s      $f0, $f0, $f1
    /* 1DD45C 002DD45C 00000000 */  nop
    /* 1DD460 002DD460 00000000 */  nop
    /* 1DD464 002DD464 0C0040E6 */  swc1       $f0, 0xC($18)
    /* 1DD468 002DD468 03000010 */  b          .L002DD478
    /* 1DD46C 002DD46C 00000000 */   nop
  .L002DD470:
    /* 1DD470 002DD470 B642023C */  lui        $2, (0x42B60000 >> 16)
    /* 1DD474 002DD474 0C0042AE */  sw         $2, 0xC($18)
  .L002DD478:
    /* 1DD478 002DD478 02004286 */  lh         $2, 0x2($18)
    /* 1DD47C 002DD47C FFFF4224 */  addiu      $2, $2, -0x1
    /* 1DD480 002DD480 00008244 */  mtc1       $2, $f0
    /* 1DD484 002DD484 00000000 */  nop
    /* 1DD488 002DD488 E0008046 */  cvt.s.w    $f3, $f0
    /* 1DD48C 002DD48C 0C0042C6 */  lwc1       $f2, 0xC($18)
    /* 1DD490 002DD490 1243023C */  lui        $2, (0x43120000 >> 16)
    /* 1DD494 002DD494 00088244 */  mtc1       $2, $f1
    /* 1DD498 002DD498 00008044 */  mtc1       $0, $f0
    /* 1DD49C 002DD49C 00000000 */  nop
    /* 1DD4A0 002DD4A0 18000146 */  adda.s     $f0, $f1
    /* 1DD4A4 002DD4A4 5C130346 */  madd.s     $f13, $f2, $f3
    /* 1DD4A8 002DD4A8 19000010 */  b          .L002DD510
    /* 1DD4AC 002DD4AC 00000000 */   nop
  .L002DD4B0:
    /* 1DD4B0 002DD4B0 80100200 */  sll        $2, $2, 2
    /* 1DD4B4 002DD4B4 21105200 */  addu       $2, $2, $18
    /* 1DD4B8 002DD4B8 180F448C */  lw         $4, 0xF18($2)
    /* 1DD4BC 002DD4BC BC890B0C */  jal        func_002e26f0
    /* 1DD4C0 002DD4C0 00000000 */   nop
    /* 1DD4C4 002DD4C4 FFFF4224 */  addiu      $2, $2, -0x1
    /* 1DD4C8 002DD4C8 00008244 */  mtc1       $2, $f0
    /* 1DD4CC 002DD4CC 00000000 */  nop
    /* 1DD4D0 002DD4D0 60008046 */  cvt.s.w    $f1, $f0
    /* 1DD4D4 002DD4D4 B642023C */  lui        $2, (0x42B60000 >> 16)
    /* 1DD4D8 002DD4D8 00008244 */  mtc1       $2, $f0
    /* 1DD4DC 002DD4DC 00000000 */  nop
    /* 1DD4E0 002DD4E0 C3000146 */  div.s      $f3, $f0, $f1
    /* 1DD4E4 002DD4E4 0C0043E6 */  swc1       $f3, 0xC($18)
    /* 1DD4E8 002DD4E8 02004286 */  lh         $2, 0x2($18)
    /* 1DD4EC 002DD4EC 00008244 */  mtc1       $2, $f0
    /* 1DD4F0 002DD4F0 00000000 */  nop
    /* 1DD4F4 002DD4F4 A0008046 */  cvt.s.w    $f2, $f0
    /* 1DD4F8 002DD4F8 1243023C */  lui        $2, (0x43120000 >> 16)
    /* 1DD4FC 002DD4FC 00088244 */  mtc1       $2, $f1
    /* 1DD500 002DD500 00008044 */  mtc1       $0, $f0
    /* 1DD504 002DD504 00000000 */  nop
    /* 1DD508 002DD508 18000146 */  adda.s     $f0, $f1
    /* 1DD50C 002DD50C 5C1B0246 */  madd.s     $f13, $f3, $f2
  .L002DD510:
    /* 1DD510 002DD510 46020224 */  addiu      $2, $0, 0x246
    /* 1DD514 002DD514 00008244 */  mtc1       $2, $f0
    /* 1DD518 002DD518 00000000 */  nop
    /* 1DD51C 002DD51C 20038046 */  cvt.s.w    $f12, $f0
    /* 1DD520 002DD520 4001A427 */  addiu      $4, $29, 0x140
    /* 1DD524 002DD524 5CCA0A0C */  jal        func_002b2970
    /* 1DD528 002DD528 00000000 */   nop
    /* 1DD52C 002DD52C FF000424 */  addiu      $4, $0, 0xFF
    /* 1DD530 002DD530 2D288000 */  daddu      $5, $4, $0
    /* 1DD534 002DD534 6D000624 */  addiu      $6, $0, 0x6D
    /* 1DD538 002DD538 31000724 */  addiu      $7, $0, 0x31
    /* 1DD53C 002DD53C 8CCA0A0C */  jal        func_002b2a30
    /* 1DD540 002DD540 00000000 */   nop
    /* 1DD544 002DD544 2D804000 */  daddu      $16, $2, $0
    /* 1DD548 002DD548 940C448E */  lw         $4, 0xC94($18)
    /* 1DD54C 002DD54C 38810B0C */  jal        func_002e04e0
    /* 1DD550 002DD550 00000000 */   nop
    /* 1DD554 002DD554 B042033C */  lui        $3, (0x42B00000 >> 16)
    /* 1DD558 002DD558 00608344 */  mtc1       $3, $f12
    /* 1DD55C 002DD55C 36000424 */  addiu      $4, $0, 0x36
    /* 1DD560 002DD560 4001A5DF */  ld         $5, 0x140($29)
    /* 1DD564 002DD564 2D300002 */  daddu      $6, $16, $0
    /* 1DD568 002DD568 62004790 */  lbu        $7, 0x62($2)
    /* 1DD56C 002DD56C 2D400000 */  daddu      $8, $0, $0
    /* 1DD570 002DD570 7900093C */  lui        $9, %hi(D_00794EA0)
    /* 1DD574 002DD574 A04E2925 */  addiu      $9, $9, %lo(D_00794EA0)
    /* 1DD578 002DD578 C8820B0C */  jal        func_002e0b20
    /* 1DD57C 002DD57C 00000000 */   nop
    /* 1DD580 002DD580 940C448E */  lw         $4, 0xC94($18)
    /* 1DD584 002DD584 2D280000 */  daddu      $5, $0, $0
    /* 1DD588 002DD588 2D300000 */  daddu      $6, $0, $0
    /* 1DD58C 002DD58C 3C810B0C */  jal        func_002e04f0
    /* 1DD590 002DD590 00000000 */   nop
    /* 1DD594 002DD594 980C448E */  lw         $4, 0xC98($18)
    /* 1DD598 002DD598 2D280000 */  daddu      $5, $0, $0
    /* 1DD59C 002DD59C 2D300000 */  daddu      $6, $0, $0
    /* 1DD5A0 002DD5A0 3C810B0C */  jal        func_002e04f0
    /* 1DD5A4 002DD5A4 00000000 */   nop
    /* 1DD5A8 002DD5A8 0B000010 */  b          .L002DD5D8
    /* 1DD5AC 002DD5AC 00000000 */   nop
  .L002DD5B0:
    /* 1DD5B0 002DD5B0 940C448E */  lw         $4, 0xC94($18)
    /* 1DD5B4 002DD5B4 2D280000 */  daddu      $5, $0, $0
    /* 1DD5B8 002DD5B8 01000624 */  addiu      $6, $0, 0x1
    /* 1DD5BC 002DD5BC 3C810B0C */  jal        func_002e04f0
    /* 1DD5C0 002DD5C0 00000000 */   nop
    /* 1DD5C4 002DD5C4 980C448E */  lw         $4, 0xC98($18)
    /* 1DD5C8 002DD5C8 2D280000 */  daddu      $5, $0, $0
    /* 1DD5CC 002DD5CC 01000624 */  addiu      $6, $0, 0x1
    /* 1DD5D0 002DD5D0 3C810B0C */  jal        func_002e04f0
    /* 1DD5D4 002DD5D4 00000000 */   nop
  .L002DD5D8:
    /* 1DD5D8 002DD5D8 11004282 */  lb         $2, 0x11($18)
    /* 1DD5DC 002DD5DC 80100200 */  sll        $2, $2, 2
    /* 1DD5E0 002DD5E0 21105200 */  addu       $2, $2, $18
    /* 1DD5E4 002DD5E4 02004586 */  lh         $5, 0x2($18)
    /* 1DD5E8 002DD5E8 180F448C */  lw         $4, 0xF18($2)
    /* 1DD5EC 002DD5EC 0C8A0B0C */  jal        func_002e2830
    /* 1DD5F0 002DD5F0 00000000 */   nop
    /* 1DD5F4 002DD5F4 3C840200 */  dsll32     $16, $2, 16
    /* 1DD5F8 002DD5F8 3F841000 */  dsra32     $16, $16, 16
    /* 1DD5FC 002DD5FC 2D000424 */  addiu      $4, $0, 0x2D
    /* 1DD600 002DD600 2D288000 */  daddu      $5, $4, $0
    /* 1DD604 002DD604 2D308000 */  daddu      $6, $4, $0
    /* 1DD608 002DD608 FF000724 */  addiu      $7, $0, 0xFF
    /* 1DD60C 002DD60C 8CCA0A0C */  jal        func_002b2a30
    /* 1DD610 002DD610 00000000 */   nop
    /* 1DD614 002DD614 2D884000 */  daddu      $17, $2, $0
    /* 1DD618 002DD618 0143023C */  lui        $2, (0x43010000 >> 16)
    /* 1DD61C 002DD61C 00608244 */  mtc1       $2, $f12
    /* 1DD620 002DD620 0643023C */  lui        $2, (0x43060000 >> 16)
    /* 1DD624 002DD624 00688244 */  mtc1       $2, $f13
    /* 1DD628 002DD628 3801A427 */  addiu      $4, $29, 0x138
    /* 1DD62C 002DD62C 5CCA0A0C */  jal        func_002b2970
    /* 1DD630 002DD630 00000000 */   nop
    /* 1DD634 002DD634 3801A1C7 */  lwc1       $f1, 0x138($29)
    /* 1DD638 002DD638 3C01A0C7 */  lwc1       $f0, 0x13C($29)
    /* 1DD63C 002DD63C 9800A1E7 */  swc1       $f1, 0x98($29)
    /* 1DD640 002DD640 9C00A0E7 */  swc1       $f0, 0x9C($29)
    /* 1DD644 002DD644 2D200002 */  daddu      $4, $16, $0
    /* 1DD648 002DD648 FC19040C */  jal        func_001067f0
    /* 1DD64C 002DD64C 00000000 */   nop
    /* 1DD650 002DD650 8C42033C */  lui        $3, (0x428C0000 >> 16)
    /* 1DD654 002DD654 00708344 */  mtc1       $3, $f14
    /* 1DD658 002DD658 9800ACC7 */  lwc1       $f12, 0x98($29)
    /* 1DD65C 002DD65C 9C00ADC7 */  lwc1       $f13, 0x9C($29)
    /* 1DD660 002DD660 2D202002 */  daddu      $4, $17, $0
    /* 1DD664 002DD664 2D280000 */  daddu      $5, $0, $0
    /* 1DD668 002DD668 01000624 */  addiu      $6, $0, 0x1
    /* 1DD66C 002DD66C 2D384000 */  daddu      $7, $2, $0
    /* 1DD670 002DD670 2D400000 */  daddu      $8, $0, $0
    /* 1DD674 002DD674 2D480000 */  daddu      $9, $0, $0
    /* 1DD678 002DD678 79000A3C */  lui        $10, %hi(D_00795E30)
    /* 1DD67C 002DD67C 305E4A25 */  addiu      $10, $10, %lo(D_00795E30)
    /* 1DD680 002DD680 FFFF0B24 */  addiu      $11, $0, -0x1
    /* 1DD684 002DD684 A0D5090C */  jal        func_00275680
    /* 1DD688 002DD688 00000000 */   nop
    /* 1DD68C 002DD68C 3C241000 */  dsll32     $4, $16, 16
    /* 1DD690 002DD690 3F240400 */  dsra32     $4, $4, 16
    /* 1DD694 002DD694 A41A040C */  jal        func_00106a90
    /* 1DD698 002DD698 00000000 */   nop
    /* 1DD69C 002DD69C 05000324 */  addiu      $3, $0, 0x5
    /* 1DD6A0 002DD6A0 1B004300 */  divu       $0, $2, $3
    /* 1DD6A4 002DD6A4 12880000 */  mflo       $17
    /* 1DD6A8 002DD6A8 F343023C */  lui        $2, (0x43F30000 >> 16)
    /* 1DD6AC 002DD6AC 00608244 */  mtc1       $2, $f12
    /* 1DD6B0 002DD6B0 1143023C */  lui        $2, (0x43110000 >> 16)
    /* 1DD6B4 002DD6B4 00688244 */  mtc1       $2, $f13
    /* 1DD6B8 002DD6B8 3001A427 */  addiu      $4, $29, 0x130
    /* 1DD6BC 002DD6BC 5CCA0A0C */  jal        func_002b2970
    /* 1DD6C0 002DD6C0 00000000 */   nop
    /* 1DD6C4 002DD6C4 6C01A427 */  addiu      $4, $29, 0x16C
    /* 1DD6C8 002DD6C8 2D000524 */  addiu      $5, $0, 0x2D
    /* 1DD6CC 002DD6CC 2D30A000 */  daddu      $6, $5, $0
    /* 1DD6D0 002DD6D0 2D38A000 */  daddu      $7, $5, $0
    /* 1DD6D4 002DD6D4 FF000824 */  addiu      $8, $0, 0xFF
    /* 1DD6D8 002DD6D8 98CA0A0C */  jal        func_002b2a60
    /* 1DD6DC 002DD6DC 00000000 */   nop
    /* 1DD6E0 002DD6E0 6400043C */  lui        $4, %hi(D_0063FB50)
    /* 1DD6E4 002DD6E4 50FB8424 */  addiu      $4, $4, %lo(D_0063FB50)
    /* 1DD6E8 002DD6E8 DCA9110C */  jal        func_0046a770
    /* 1DD6EC 002DD6EC 00000000 */   nop
    /* 1DD6F0 002DD6F0 280F438E */  lw         $3, 0xF28($18)
    /* 1DD6F4 002DD6F4 0000A3FF */  sd         $3, 0x0($29)
    /* 1DD6F8 002DD6F8 A9000324 */  addiu      $3, $0, 0xA9
    /* 1DD6FC 002DD6FC 0800A3FF */  sd         $3, 0x8($29)
    /* 1DD700 002DD700 8C42033C */  lui        $3, (0x428C0000 >> 16)
    /* 1DD704 002DD704 00608344 */  mtc1       $3, $f12
    /* 1DD708 002DD708 3001A4DF */  ld         $4, 0x130($29)
    /* 1DD70C 002DD70C 6C01A58F */  lw         $5, 0x16C($29)
    /* 1DD710 002DD710 10000624 */  addiu      $6, $0, 0x10
    /* 1DD714 002DD714 05000724 */  addiu      $7, $0, 0x5
    /* 1DD718 002DD718 2D402002 */  daddu      $8, $17, $0
    /* 1DD71C 002DD71C 09000924 */  addiu      $9, $0, 0x9
    /* 1DD720 002DD720 7B000A24 */  addiu      $10, $0, 0x7B
    /* 1DD724 002DD724 2D584000 */  daddu      $11, $2, $0
    /* 1DD728 002DD728 342B0B0C */  jal        func_002cacd0
    /* 1DD72C 002DD72C 00000000 */   nop
    /* 1DD730 002DD730 02020224 */  addiu      $2, $0, 0x202
    /* 1DD734 002DD734 00008244 */  mtc1       $2, $f0
    /* 1DD738 002DD738 00000000 */  nop
    /* 1DD73C 002DD73C 20038046 */  cvt.s.w    $f12, $f0
    /* 1DD740 002DD740 1343023C */  lui        $2, (0x43130000 >> 16)
    /* 1DD744 002DD744 00688244 */  mtc1       $2, $f13
    /* 1DD748 002DD748 2801A427 */  addiu      $4, $29, 0x128
    /* 1DD74C 002DD74C 5CCA0A0C */  jal        func_002b2970
    /* 1DD750 002DD750 00000000 */   nop
    /* 1DD754 002DD754 2D000424 */  addiu      $4, $0, 0x2D
    /* 1DD758 002DD758 2D288000 */  daddu      $5, $4, $0
    /* 1DD75C 002DD75C 2D308000 */  daddu      $6, $4, $0
    /* 1DD760 002DD760 2D388000 */  daddu      $7, $4, $0
    /* 1DD764 002DD764 8CCA0A0C */  jal        func_002b2a30
    /* 1DD768 002DD768 00000000 */   nop
    /* 1DD76C 002DD76C 8C42033C */  lui        $3, (0x428C0000 >> 16)
    /* 1DD770 002DD770 00608344 */  mtc1       $3, $f12
    /* 1DD774 002DD774 47000424 */  addiu      $4, $0, 0x47
    /* 1DD778 002DD778 2801A5DF */  ld         $5, 0x128($29)
    /* 1DD77C 002DD77C 2D304000 */  daddu      $6, $2, $0
    /* 1DD780 002DD780 FF000724 */  addiu      $7, $0, 0xFF
    /* 1DD784 002DD784 2D400000 */  daddu      $8, $0, $0
    /* 1DD788 002DD788 7900093C */  lui        $9, %hi(D_00795E60)
    /* 1DD78C 002DD78C 605E2925 */  addiu      $9, $9, %lo(D_00795E60)
    /* 1DD790 002DD790 C8820B0C */  jal        func_002e0b20
    /* 1DD794 002DD794 00000000 */   nop
    /* 1DD798 002DD798 21020224 */  addiu      $2, $0, 0x221
    /* 1DD79C 002DD79C 00008244 */  mtc1       $2, $f0
    /* 1DD7A0 002DD7A0 00000000 */  nop
    /* 1DD7A4 002DD7A4 20038046 */  cvt.s.w    $f12, $f0
    /* 1DD7A8 002DD7A8 1143023C */  lui        $2, (0x43110000 >> 16)
    /* 1DD7AC 002DD7AC 00688244 */  mtc1       $2, $f13
    /* 1DD7B0 002DD7B0 2001A427 */  addiu      $4, $29, 0x120
    /* 1DD7B4 002DD7B4 5CCA0A0C */  jal        func_002b2970
    /* 1DD7B8 002DD7B8 00000000 */   nop
    /* 1DD7BC 002DD7BC 6801A427 */  addiu      $4, $29, 0x168
    /* 1DD7C0 002DD7C0 2D000524 */  addiu      $5, $0, 0x2D
    /* 1DD7C4 002DD7C4 2D30A000 */  daddu      $6, $5, $0
    /* 1DD7C8 002DD7C8 2D38A000 */  daddu      $7, $5, $0
    /* 1DD7CC 002DD7CC FF000824 */  addiu      $8, $0, 0xFF
    /* 1DD7D0 002DD7D0 98CA0A0C */  jal        func_002b2a60
    /* 1DD7D4 002DD7D4 00000000 */   nop
    /* 1DD7D8 002DD7D8 2D200002 */  daddu      $4, $16, $0
    /* 1DD7DC 002DD7DC 8019040C */  jal        func_00106600
    /* 1DD7E0 002DD7E0 00000000 */   nop
    /* 1DD7E4 002DD7E4 FF005130 */  andi       $17, $2, 0xFF
    /* 1DD7E8 002DD7E8 6400043C */  lui        $4, %hi(D_0063FB50)
    /* 1DD7EC 002DD7EC 50FB8424 */  addiu      $4, $4, %lo(D_0063FB50)
    /* 1DD7F0 002DD7F0 DCA9110C */  jal        func_0046a770
    /* 1DD7F4 002DD7F4 00000000 */   nop
    /* 1DD7F8 002DD7F8 280F438E */  lw         $3, 0xF28($18)
    /* 1DD7FC 002DD7FC 0000A3FF */  sd         $3, 0x0($29)
    /* 1DD800 002DD800 A9000324 */  addiu      $3, $0, 0xA9
    /* 1DD804 002DD804 0800A3FF */  sd         $3, 0x8($29)
    /* 1DD808 002DD808 8C42033C */  lui        $3, (0x428C0000 >> 16)
    /* 1DD80C 002DD80C 00608344 */  mtc1       $3, $f12
    /* 1DD810 002DD810 2001A4DF */  ld         $4, 0x120($29)
    /* 1DD814 002DD814 6801A58F */  lw         $5, 0x168($29)
    /* 1DD818 002DD818 10000624 */  addiu      $6, $0, 0x10
    /* 1DD81C 002DD81C 05000724 */  addiu      $7, $0, 0x5
    /* 1DD820 002DD820 2D402002 */  daddu      $8, $17, $0
    /* 1DD824 002DD824 09000924 */  addiu      $9, $0, 0x9
    /* 1DD828 002DD828 7B000A24 */  addiu      $10, $0, 0x7B
    /* 1DD82C 002DD82C 2D584000 */  daddu      $11, $2, $0
    /* 1DD830 002DD830 342B0B0C */  jal        func_002cacd0
    /* 1DD834 002DD834 00000000 */   nop
    /* 1DD838 002DD838 2D200002 */  daddu      $4, $16, $0
    /* 1DD83C 002DD83C 741A040C */  jal        func_001069d0
    /* 1DD840 002DD840 00000000 */   nop
    /* 1DD844 002DD844 FFFF4330 */  andi       $3, $2, 0xFFFF
    /* 1DD848 002DD848 2D006014 */  bnez       $3, .L002DD900
    /* 1DD84C 002DD84C 00000000 */   nop
    /* 1DD850 002DD850 2D880000 */  daddu      $17, $0, $0
    /* 1DD854 002DD854 23000010 */  b          .L002DD8E4
    /* 1DD858 002DD858 00000000 */   nop
  .L002DD85C:
    /* 1DD85C 002DD85C 80100400 */  sll        $2, $4, 2
    /* 1DD860 002DD860 21104400 */  addu       $2, $2, $4
    /* 1DD864 002DD864 40100200 */  sll        $2, $2, 1
    /* 1DD868 002DD868 21104400 */  addu       $2, $2, $4
    /* 1DD86C 002DD86C 40100200 */  sll        $2, $2, 1
    /* 1DD870 002DD870 6F004224 */  addiu      $2, $2, 0x6F
    /* 1DD874 002DD874 00008244 */  mtc1       $2, $f0
    /* 1DD878 002DD878 00000000 */  nop
    /* 1DD87C 002DD87C 20038046 */  cvt.s.w    $f12, $f0
    /* 1DD880 002DD880 3243023C */  lui        $2, (0x43320000 >> 16)
    /* 1DD884 002DD884 00688244 */  mtc1       $2, $f13
    /* 1DD888 002DD888 1801A427 */  addiu      $4, $29, 0x118
    /* 1DD88C 002DD88C 5CCA0A0C */  jal        func_002b2970
    /* 1DD890 002DD890 00000000 */   nop
    /* 1DD894 002DD894 FF000424 */  addiu      $4, $0, 0xFF
    /* 1DD898 002DD898 2D288000 */  daddu      $5, $4, $0
    /* 1DD89C 002DD89C C7000624 */  addiu      $6, $0, 0xC7
    /* 1DD8A0 002DD8A0 31000724 */  addiu      $7, $0, 0x31
    /* 1DD8A4 002DD8A4 8CCA0A0C */  jal        func_002b2a30
    /* 1DD8A8 002DD8A8 00000000 */   nop
    /* 1DD8AC 002DD8AC AC42033C */  lui        $3, (0x42AC0000 >> 16)
    /* 1DD8B0 002DD8B0 00608344 */  mtc1       $3, $f12
    /* 1DD8B4 002DD8B4 3C000424 */  addiu      $4, $0, 0x3C
    /* 1DD8B8 002DD8B8 1801A5DF */  ld         $5, 0x118($29)
    /* 1DD8BC 002DD8BC 2D304000 */  daddu      $6, $2, $0
    /* 1DD8C0 002DD8C0 FF000724 */  addiu      $7, $0, 0xFF
    /* 1DD8C4 002DD8C4 2D400000 */  daddu      $8, $0, $0
    /* 1DD8C8 002DD8C8 7900093C */  lui        $9, %hi(D_00794ED0)
    /* 1DD8CC 002DD8CC D04E2925 */  addiu      $9, $9, %lo(D_00794ED0)
    /* 1DD8D0 002DD8D0 C8820B0C */  jal        func_002e0b20
    /* 1DD8D4 002DD8D4 00000000 */   nop
    /* 1DD8D8 002DD8D8 01002326 */  addiu      $3, $17, 0x1
    /* 1DD8DC 002DD8DC 3C8C0300 */  dsll32     $17, $3, 16
    /* 1DD8E0 002DD8E0 3F8C1100 */  dsra32     $17, $17, 16
  .L002DD8E4:
    /* 1DD8E4 002DD8E4 3C241100 */  dsll32     $4, $17, 16
    /* 1DD8E8 002DD8E8 3F240400 */  dsra32     $4, $4, 16
    /* 1DD8EC 002DD8EC 0F008328 */  slti       $3, $4, 0xF
    /* 1DD8F0 002DD8F0 DAFF6014 */  bnez       $3, .L002DD85C
    /* 1DD8F4 002DD8F4 00000000 */   nop
    /* 1DD8F8 002DD8F8 19000010 */  b          .L002DD960
    /* 1DD8FC 002DD8FC 00000000 */   nop
  .L002DD900:
    /* 1DD900 002DD900 2D200002 */  daddu      $4, $16, $0
    /* 1DD904 002DD904 741A040C */  jal        func_001069d0
    /* 1DD908 002DD908 00000000 */   nop
    /* 1DD90C 002DD90C FFFF5130 */  andi       $17, $2, 0xFFFF
    /* 1DD910 002DD910 2D000424 */  addiu      $4, $0, 0x2D
    /* 1DD914 002DD914 2D288000 */  daddu      $5, $4, $0
    /* 1DD918 002DD918 2D308000 */  daddu      $6, $4, $0
    /* 1DD91C 002DD91C FF000724 */  addiu      $7, $0, 0xFF
    /* 1DD920 002DD920 8CCA0A0C */  jal        func_002b2a30
    /* 1DD924 002DD924 00000000 */   nop
    /* 1DD928 002DD928 DA42033C */  lui        $3, (0x42DA0000 >> 16)
    /* 1DD92C 002DD92C 00608344 */  mtc1       $3, $f12
    /* 1DD930 002DD930 2943033C */  lui        $3, (0x43290000 >> 16)
    /* 1DD934 002DD934 00688344 */  mtc1       $3, $f13
    /* 1DD938 002DD938 8C42033C */  lui        $3, (0x428C0000 >> 16)
    /* 1DD93C 002DD93C 00708344 */  mtc1       $3, $f14
    /* 1DD940 002DD940 2D202002 */  daddu      $4, $17, $0
    /* 1DD944 002DD944 2D284000 */  daddu      $5, $2, $0
    /* 1DD948 002DD948 01000624 */  addiu      $6, $0, 0x1
    /* 1DD94C 002DD94C 2D380000 */  daddu      $7, $0, $0
    /* 1DD950 002DD950 03000824 */  addiu      $8, $0, 0x3
    /* 1DD954 002DD954 57000924 */  addiu      $9, $0, 0x57
    /* 1DD958 002DD958 FCF10A0C */  jal        func_002bc7f0
    /* 1DD95C 002DD95C 00000000 */   nop
  .L002DD960:
    /* 1DD960 002DD960 11004482 */  lb         $4, 0x11($18)
    /* 1DD964 002DD964 6D028010 */  beqz       $4, .L002DE31C
    /* 1DD968 002DD968 00000000 */   nop
    /* 1DD96C 002DD96C 02000324 */  addiu      $3, $0, 0x2
    /* 1DD970 002DD970 6A028310 */  beq        $4, $3, .L002DE31C
    /* 1DD974 002DD974 00000000 */   nop
    /* 1DD978 002DD978 01000324 */  addiu      $3, $0, 0x1
    /* 1DD97C 002DD97C 03008310 */  beq        $4, $3, .L002DD98C
    /* 1DD980 002DD980 00000000 */   nop
    /* 1DD984 002DD984 FF020010 */  b          .L002DE584
    /* 1DD988 002DD988 00000000 */   nop
  .L002DD98C:
    /* 1DD98C 002DD98C 2D200002 */  daddu      $4, $16, $0
    /* 1DD990 002DD990 201A040C */  jal        func_00106880
    /* 1DD994 002DD994 00000000 */   nop
    /* 1DD998 002DD998 3C240200 */  dsll32     $4, $2, 16
    /* 1DD99C 002DD99C 3F240400 */  dsra32     $4, $4, 16
    /* 1DD9A0 002DD9A0 CC530B0C */  jal        func_002d4f30
    /* 1DD9A4 002DD9A4 00000000 */   nop
    /* 1DD9A8 002DD9A8 FFFF5130 */  andi       $17, $2, 0xFFFF
    /* 1DD9AC 002DD9AC AC42023C */  lui        $2, (0x42AC0000 >> 16)
    /* 1DD9B0 002DD9B0 00608244 */  mtc1       $2, $f12
    /* 1DD9B4 002DD9B4 0743023C */  lui        $2, (0x43070000 >> 16)
    /* 1DD9B8 002DD9B8 00688244 */  mtc1       $2, $f13
    /* 1DD9BC 002DD9BC 1001A427 */  addiu      $4, $29, 0x110
    /* 1DD9C0 002DD9C0 5CCA0A0C */  jal        func_002b2970
    /* 1DD9C4 002DD9C4 00000000 */   nop
    /* 1DD9C8 002DD9C8 2D200000 */  daddu      $4, $0, $0
    /* 1DD9CC 002DD9CC 2D000524 */  addiu      $5, $0, 0x2D
    /* 1DD9D0 002DD9D0 2D30A000 */  daddu      $6, $5, $0
    /* 1DD9D4 002DD9D4 2D38A000 */  daddu      $7, $5, $0
    /* 1DD9D8 002DD9D8 8CCA0A0C */  jal        func_002b2a30
    /* 1DD9DC 002DD9DC 00000000 */   nop
    /* 1DD9E0 002DD9E0 8A42033C */  lui        $3, (0x428A0000 >> 16)
    /* 1DD9E4 002DD9E4 00608344 */  mtc1       $3, $f12
    /* 1DD9E8 002DD9E8 2D202002 */  daddu      $4, $17, $0
    /* 1DD9EC 002DD9EC 1001A5DF */  ld         $5, 0x110($29)
    /* 1DD9F0 002DD9F0 2D304000 */  daddu      $6, $2, $0
    /* 1DD9F4 002DD9F4 FF000724 */  addiu      $7, $0, 0xFF
    /* 1DD9F8 002DD9F8 2D400000 */  daddu      $8, $0, $0
    /* 1DD9FC 002DD9FC 7900093C */  lui        $9, %hi(D_00795E30)
    /* 1DDA00 002DDA00 305E2925 */  addiu      $9, $9, %lo(D_00795E30)
    /* 1DDA04 002DDA04 C8820B0C */  jal        func_002e0b20
    /* 1DDA08 002DDA08 00000000 */   nop
    /* 1DDA0C 002DDA0C 2D200002 */  daddu      $4, $16, $0
    /* 1DDA10 002DDA10 201A040C */  jal        func_00106880
    /* 1DDA14 002DDA14 00000000 */   nop
    /* 1DDA18 002DDA18 3C240200 */  dsll32     $4, $2, 16
    /* 1DDA1C 002DDA1C 3F240400 */  dsra32     $4, $4, 16
    /* 1DDA20 002DDA20 CC530B0C */  jal        func_002d4f30
    /* 1DDA24 002DDA24 00000000 */   nop
    /* 1DDA28 002DDA28 3C1C0200 */  dsll32     $3, $2, 16
    /* 1DDA2C 002DDA2C 3F1C0300 */  dsra32     $3, $3, 16
    /* 1DDA30 002DDA30 ECFF6324 */  addiu      $3, $3, -0x14
    /* 1DDA34 002DDA34 0900612C */  sltiu      $1, $3, 0x9
    /* 1DDA38 002DDA38 D2022010 */  beqz       $1, .L002DE584
    /* 1DDA3C 002DDA3C 00000000 */   nop
    /* 1DDA40 002DDA40 7500043C */  lui        $4, %hi(jtbl_007489F0)
    /* 1DDA44 002DDA44 F0898424 */  addiu      $4, $4, %lo(jtbl_007489F0)
    /* 1DDA48 002DDA48 80180300 */  sll        $3, $3, 2
    /* 1DDA4C 002DDA4C 21186400 */  addu       $3, $3, $4
    /* 1DDA50 002DDA50 0000638C */  lw         $3, 0x0($3)
    /* 1DDA54 002DDA54 08006000 */  jr         $3
    /* 1DDA58 002DDA58 00000000 */   nop
    /* 1DDA5C 002DDA5C 2D200002 */  daddu      $4, $16, $0
    /* 1DDA60 002DDA60 E01A040C */  jal        func_00106b80
    /* 1DDA64 002DDA64 00000000 */   nop
    /* 1DDA68 002DDA68 3C8C0200 */  dsll32     $17, $2, 16
    /* 1DDA6C 002DDA6C 3F8C1100 */  dsra32     $17, $17, 16
    /* 1DDA70 002DDA70 DF000424 */  addiu      $4, $0, 0xDF
    /* 1DDA74 002DDA74 6C000524 */  addiu      $5, $0, 0x6C
    /* 1DDA78 002DDA78 2D300000 */  daddu      $6, $0, $0
    /* 1DDA7C 002DDA7C FF000724 */  addiu      $7, $0, 0xFF
    /* 1DDA80 002DDA80 8CCA0A0C */  jal        func_002b2a30
    /* 1DDA84 002DDA84 00000000 */   nop
    /* 1DDA88 002DDA88 DA42033C */  lui        $3, (0x42DA0000 >> 16)
    /* 1DDA8C 002DDA8C 00608344 */  mtc1       $3, $f12
    /* 1DDA90 002DDA90 4943033C */  lui        $3, (0x43490000 >> 16)
    /* 1DDA94 002DDA94 00688344 */  mtc1       $3, $f13
    /* 1DDA98 002DDA98 8C42033C */  lui        $3, (0x428C0000 >> 16)
    /* 1DDA9C 002DDA9C 00708344 */  mtc1       $3, $f14
    /* 1DDAA0 002DDAA0 2D202002 */  daddu      $4, $17, $0
    /* 1DDAA4 002DDAA4 2D284000 */  daddu      $5, $2, $0
    /* 1DDAA8 002DDAA8 01000624 */  addiu      $6, $0, 0x1
    /* 1DDAAC 002DDAAC 2D380000 */  daddu      $7, $0, $0
    /* 1DDAB0 002DDAB0 2D400000 */  daddu      $8, $0, $0
    /* 1DDAB4 002DDAB4 57000924 */  addiu      $9, $0, 0x57
    /* 1DDAB8 002DDAB8 FCF10A0C */  jal        func_002bc7f0
    /* 1DDABC 002DDABC 00000000 */   nop
    /* 1DDAC0 002DDAC0 A642023C */  lui        $2, (0x42A60000 >> 16)
    /* 1DDAC4 002DDAC4 00608244 */  mtc1       $2, $f12
    /* 1DDAC8 002DDAC8 A00C448E */  lw         $4, 0xCA0($18)
    /* 1DDACC 002DDACC 57000524 */  addiu      $5, $0, 0x57
    /* 1DDAD0 002DDAD0 78820B0C */  jal        func_002e09e0
    /* 1DDAD4 002DDAD4 00000000 */   nop
    /* 1DDAD8 002DDAD8 6401A427 */  addiu      $4, $29, 0x164
    /* 1DDADC 002DDADC FE000524 */  addiu      $5, $0, 0xFE
    /* 1DDAE0 002DDAE0 EF000624 */  addiu      $6, $0, 0xEF
    /* 1DDAE4 002DDAE4 80000724 */  addiu      $7, $0, 0x80
    /* 1DDAE8 002DDAE8 FF000824 */  addiu      $8, $0, 0xFF
    /* 1DDAEC 002DDAEC 98CA0A0C */  jal        func_002b2a60
    /* 1DDAF0 002DDAF0 00000000 */   nop
    /* 1DDAF4 002DDAF4 A00C448E */  lw         $4, 0xCA0($18)
    /* 1DDAF8 002DDAF8 38810B0C */  jal        func_002e04e0
    /* 1DDAFC 002DDAFC 00000000 */   nop
    /* 1DDB00 002DDB00 6401A693 */  lbu        $6, 0x164($29)
    /* 1DDB04 002DDB04 6501A593 */  lbu        $5, 0x165($29)
    /* 1DDB08 002DDB08 6601A493 */  lbu        $4, 0x166($29)
    /* 1DDB0C 002DDB0C 6701A393 */  lbu        $3, 0x167($29)
    /* 1DDB10 002DDB10 790046A0 */  sb         $6, 0x79($2)
    /* 1DDB14 002DDB14 7A0045A0 */  sb         $5, 0x7A($2)
    /* 1DDB18 002DDB18 7B0044A0 */  sb         $4, 0x7B($2)
    /* 1DDB1C 002DDB1C 7C0043A0 */  sb         $3, 0x7C($2)
    /* 1DDB20 002DDB20 E1010224 */  addiu      $2, $0, 0x1E1
    /* 1DDB24 002DDB24 00008244 */  mtc1       $2, $f0
    /* 1DDB28 002DDB28 00000000 */  nop
    /* 1DDB2C 002DDB2C 20038046 */  cvt.s.w    $f12, $f0
    /* 1DDB30 002DDB30 2E43023C */  lui        $2, (0x432E0000 >> 16)
    /* 1DDB34 002DDB34 00688244 */  mtc1       $2, $f13
    /* 1DDB38 002DDB38 0801A427 */  addiu      $4, $29, 0x108
    /* 1DDB3C 002DDB3C 5CCA0A0C */  jal        func_002b2970
    /* 1DDB40 002DDB40 00000000 */   nop
    /* 1DDB44 002DDB44 A00C448E */  lw         $4, 0xCA0($18)
    /* 1DDB48 002DDB48 38810B0C */  jal        func_002e04e0
    /* 1DDB4C 002DDB4C 00000000 */   nop
    /* 1DDB50 002DDB50 0801A1C7 */  lwc1       $f1, 0x108($29)
    /* 1DDB54 002DDB54 0C01A0C7 */  lwc1       $f0, 0x10C($29)
    /* 1DDB58 002DDB58 2C0041E4 */  swc1       $f1, 0x2C($2)
    /* 1DDB5C 002DDB5C 300040E4 */  swc1       $f0, 0x30($2)
    /* 1DDB60 002DDB60 A442023C */  lui        $2, (0x42A40000 >> 16)
    /* 1DDB64 002DDB64 00608244 */  mtc1       $2, $f12
    /* 1DDB68 002DDB68 A80C448E */  lw         $4, 0xCA8($18)
    /* 1DDB6C 002DDB6C 57000524 */  addiu      $5, $0, 0x57
    /* 1DDB70 002DDB70 78820B0C */  jal        func_002e09e0
    /* 1DDB74 002DDB74 00000000 */   nop
    /* 1DDB78 002DDB78 6001A427 */  addiu      $4, $29, 0x160
    /* 1DDB7C 002DDB7C FE000524 */  addiu      $5, $0, 0xFE
    /* 1DDB80 002DDB80 EF000624 */  addiu      $6, $0, 0xEF
    /* 1DDB84 002DDB84 80000724 */  addiu      $7, $0, 0x80
    /* 1DDB88 002DDB88 FF000824 */  addiu      $8, $0, 0xFF
    /* 1DDB8C 002DDB8C 98CA0A0C */  jal        func_002b2a60
    /* 1DDB90 002DDB90 00000000 */   nop
    /* 1DDB94 002DDB94 A80C448E */  lw         $4, 0xCA8($18)
    /* 1DDB98 002DDB98 38810B0C */  jal        func_002e04e0
    /* 1DDB9C 002DDB9C 00000000 */   nop
    /* 1DDBA0 002DDBA0 6001A693 */  lbu        $6, 0x160($29)
    /* 1DDBA4 002DDBA4 6101A593 */  lbu        $5, 0x161($29)
    /* 1DDBA8 002DDBA8 6201A493 */  lbu        $4, 0x162($29)
    /* 1DDBAC 002DDBAC 6301A393 */  lbu        $3, 0x163($29)
    /* 1DDBB0 002DDBB0 790046A0 */  sb         $6, 0x79($2)
    /* 1DDBB4 002DDBB4 7A0045A0 */  sb         $5, 0x7A($2)
    /* 1DDBB8 002DDBB8 7B0044A0 */  sb         $4, 0x7B($2)
    /* 1DDBBC 002DDBBC 7C0043A0 */  sb         $3, 0x7C($2)
    /* 1DDBC0 002DDBC0 E1010224 */  addiu      $2, $0, 0x1E1
    /* 1DDBC4 002DDBC4 00008244 */  mtc1       $2, $f0
    /* 1DDBC8 002DDBC8 00000000 */  nop
    /* 1DDBCC 002DDBCC 20038046 */  cvt.s.w    $f12, $f0
    /* 1DDBD0 002DDBD0 6043023C */  lui        $2, (0x43600000 >> 16)
    /* 1DDBD4 002DDBD4 00688244 */  mtc1       $2, $f13
    /* 1DDBD8 002DDBD8 0001A427 */  addiu      $4, $29, 0x100
    /* 1DDBDC 002DDBDC 5CCA0A0C */  jal        func_002b2970
    /* 1DDBE0 002DDBE0 00000000 */   nop
    /* 1DDBE4 002DDBE4 A80C448E */  lw         $4, 0xCA8($18)
    /* 1DDBE8 002DDBE8 38810B0C */  jal        func_002e04e0
    /* 1DDBEC 002DDBEC 00000000 */   nop
    /* 1DDBF0 002DDBF0 0001A1C7 */  lwc1       $f1, 0x100($29)
    /* 1DDBF4 002DDBF4 0401A0C7 */  lwc1       $f0, 0x104($29)
    /* 1DDBF8 002DDBF8 2C0041E4 */  swc1       $f1, 0x2C($2)
    /* 1DDBFC 002DDBFC 300040E4 */  swc1       $f0, 0x30($2)
    /* 1DDC00 002DDC00 0E020224 */  addiu      $2, $0, 0x20E
    /* 1DDC04 002DDC04 00008244 */  mtc1       $2, $f0
    /* 1DDC08 002DDC08 00000000 */  nop
    /* 1DDC0C 002DDC0C 20038046 */  cvt.s.w    $f12, $f0
    /* 1DDC10 002DDC10 4A43023C */  lui        $2, (0x434A0000 >> 16)
    /* 1DDC14 002DDC14 00688244 */  mtc1       $2, $f13
    /* 1DDC18 002DDC18 F800A427 */  addiu      $4, $29, 0xF8
    /* 1DDC1C 002DDC1C 5CCA0A0C */  jal        func_002b2970
    /* 1DDC20 002DDC20 00000000 */   nop
    /* 1DDC24 002DDC24 F800A1C7 */  lwc1       $f1, 0xF8($29)
    /* 1DDC28 002DDC28 FC00A0C7 */  lwc1       $f0, 0xFC($29)
    /* 1DDC2C 002DDC2C 9000A1E7 */  swc1       $f1, 0x90($29)
    /* 1DDC30 002DDC30 9400A0E7 */  swc1       $f0, 0x94($29)
    /* 1DDC34 002DDC34 2D200002 */  daddu      $4, $16, $0
    /* 1DDC38 002DDC38 2C1A040C */  jal        func_001068b0
    /* 1DDC3C 002DDC3C 00000000 */   nop
    /* 1DDC40 002DDC40 FFFF5130 */  andi       $17, $2, 0xFFFF
    /* 1DDC44 002DDC44 2D200002 */  daddu      $4, $16, $0
    /* 1DDC48 002DDC48 2C1A040C */  jal        func_001068b0
    /* 1DDC4C 002DDC4C 00000000 */   nop
    /* 1DDC50 002DDC50 2D202002 */  daddu      $4, $17, $0
    /* 1DDC54 002DDC54 5CCC0A0C */  jal        func_002b3170
    /* 1DDC58 002DDC58 00000000 */   nop
    /* 1DDC5C 002DDC5C FFFF4224 */  addiu      $2, $2, -0x1
    /* 1DDC60 002DDC60 3C140200 */  dsll32     $2, $2, 16
    /* 1DDC64 002DDC64 3F140200 */  dsra32     $2, $2, 16
    /* 1DDC68 002DDC68 C0100200 */  sll        $2, $2, 3
    /* 1DDC6C 002DDC6C 00008244 */  mtc1       $2, $f0
    /* 1DDC70 002DDC70 00000000 */  nop
    /* 1DDC74 002DDC74 60008046 */  cvt.s.w    $f1, $f0
    /* 1DDC78 002DDC78 9000A0C7 */  lwc1       $f0, 0x90($29)
    /* 1DDC7C 002DDC7C 00030146 */  add.s      $f12, $f0, $f1
    /* 1DDC80 002DDC80 7000A427 */  addiu      $4, $29, 0x70
    /* 1DDC84 002DDC84 9400ADC7 */  lwc1       $f13, 0x94($29)
    /* 1DDC88 002DDC88 5CCA0A0C */  jal        func_002b2970
    /* 1DDC8C 002DDC8C 00000000 */   nop
    /* 1DDC90 002DDC90 5401A427 */  addiu      $4, $29, 0x154
    /* 1DDC94 002DDC94 2D000524 */  addiu      $5, $0, 0x2D
    /* 1DDC98 002DDC98 2D30A000 */  daddu      $6, $5, $0
    /* 1DDC9C 002DDC9C 2D38A000 */  daddu      $7, $5, $0
    /* 1DDCA0 002DDCA0 FF000824 */  addiu      $8, $0, 0xFF
    /* 1DDCA4 002DDCA4 98CA0A0C */  jal        func_002b2a60
    /* 1DDCA8 002DDCA8 00000000 */   nop
    /* 1DDCAC 002DDCAC 6400043C */  lui        $4, %hi(D_0063FB50)
    /* 1DDCB0 002DDCB0 50FB8424 */  addiu      $4, $4, %lo(D_0063FB50)
    /* 1DDCB4 002DDCB4 DCA9110C */  jal        func_0046a770
    /* 1DDCB8 002DDCB8 00000000 */   nop
    /* 1DDCBC 002DDCBC 2D904000 */  daddu      $18, $2, $0
    /* 1DDCC0 002DDCC0 6400043C */  lui        $4, %hi(D_0063FB50)
    /* 1DDCC4 002DDCC4 50FB8424 */  addiu      $4, $4, %lo(D_0063FB50)
    /* 1DDCC8 002DDCC8 DCA9110C */  jal        func_0046a770
    /* 1DDCCC 002DDCCC 00000000 */   nop
    /* 1DDCD0 002DDCD0 0000A2FF */  sd         $2, 0x0($29)
    /* 1DDCD4 002DDCD4 A9000224 */  addiu      $2, $0, 0xA9
    /* 1DDCD8 002DDCD8 0800A2FF */  sd         $2, 0x8($29)
    /* 1DDCDC 002DDCDC B041023C */  lui        $2, (0x41B00000 >> 16)
    /* 1DDCE0 002DDCE0 00608244 */  mtc1       $2, $f12
    /* 1DDCE4 002DDCE4 7000A4DF */  ld         $4, 0x70($29)
    /* 1DDCE8 002DDCE8 5401A58F */  lw         $5, 0x154($29)
    /* 1DDCEC 002DDCEC 0F000624 */  addiu      $6, $0, 0xF
    /* 1DDCF0 002DDCF0 2D380000 */  daddu      $7, $0, $0
    /* 1DDCF4 002DDCF4 2D402002 */  daddu      $8, $17, $0
    /* 1DDCF8 002DDCF8 1E000924 */  addiu      $9, $0, 0x1E
    /* 1DDCFC 002DDCFC 7B000A24 */  addiu      $10, $0, 0x7B
    /* 1DDD00 002DDD00 2D584002 */  daddu      $11, $18, $0
    /* 1DDD04 002DDD04 342B0B0C */  jal        func_002cacd0
    /* 1DDD08 002DDD08 00000000 */   nop
    /* 1DDD0C 002DDD0C 0E020224 */  addiu      $2, $0, 0x20E
    /* 1DDD10 002DDD10 00008244 */  mtc1       $2, $f0
    /* 1DDD14 002DDD14 00000000 */  nop
    /* 1DDD18 002DDD18 20038046 */  cvt.s.w    $f12, $f0
    /* 1DDD1C 002DDD1C 7C43023C */  lui        $2, (0x437C0000 >> 16)
    /* 1DDD20 002DDD20 00688244 */  mtc1       $2, $f13
    /* 1DDD24 002DDD24 F000A427 */  addiu      $4, $29, 0xF0
    /* 1DDD28 002DDD28 5CCA0A0C */  jal        func_002b2970
    /* 1DDD2C 002DDD2C 00000000 */   nop
    /* 1DDD30 002DDD30 F000A1C7 */  lwc1       $f1, 0xF0($29)
    /* 1DDD34 002DDD34 F400A0C7 */  lwc1       $f0, 0xF4($29)
    /* 1DDD38 002DDD38 8800A1E7 */  swc1       $f1, 0x88($29)
    /* 1DDD3C 002DDD3C 8C00A0E7 */  swc1       $f0, 0x8C($29)
    /* 1DDD40 002DDD40 2D200002 */  daddu      $4, $16, $0
    /* 1DDD44 002DDD44 381A040C */  jal        func_001068e0
    /* 1DDD48 002DDD48 00000000 */   nop
    /* 1DDD4C 002DDD4C FFFF5130 */  andi       $17, $2, 0xFFFF
    /* 1DDD50 002DDD50 2D200002 */  daddu      $4, $16, $0
    /* 1DDD54 002DDD54 381A040C */  jal        func_001068e0
    /* 1DDD58 002DDD58 00000000 */   nop
    /* 1DDD5C 002DDD5C 2D202002 */  daddu      $4, $17, $0
    /* 1DDD60 002DDD60 5CCC0A0C */  jal        func_002b3170
    /* 1DDD64 002DDD64 00000000 */   nop
    /* 1DDD68 002DDD68 FFFF4224 */  addiu      $2, $2, -0x1
    /* 1DDD6C 002DDD6C 3C140200 */  dsll32     $2, $2, 16
    /* 1DDD70 002DDD70 3F140200 */  dsra32     $2, $2, 16
    /* 1DDD74 002DDD74 C0100200 */  sll        $2, $2, 3
    /* 1DDD78 002DDD78 00008244 */  mtc1       $2, $f0
    /* 1DDD7C 002DDD7C 00000000 */  nop
    /* 1DDD80 002DDD80 60008046 */  cvt.s.w    $f1, $f0
    /* 1DDD84 002DDD84 8800A0C7 */  lwc1       $f0, 0x88($29)
    /* 1DDD88 002DDD88 00030146 */  add.s      $f12, $f0, $f1
    /* 1DDD8C 002DDD8C 6800A427 */  addiu      $4, $29, 0x68
    /* 1DDD90 002DDD90 8C00ADC7 */  lwc1       $f13, 0x8C($29)
    /* 1DDD94 002DDD94 5CCA0A0C */  jal        func_002b2970
    /* 1DDD98 002DDD98 00000000 */   nop
    /* 1DDD9C 002DDD9C 5001A427 */  addiu      $4, $29, 0x150
    /* 1DDDA0 002DDDA0 2D000524 */  addiu      $5, $0, 0x2D
    /* 1DDDA4 002DDDA4 2D30A000 */  daddu      $6, $5, $0
    /* 1DDDA8 002DDDA8 2D38A000 */  daddu      $7, $5, $0
    /* 1DDDAC 002DDDAC FF000824 */  addiu      $8, $0, 0xFF
    /* 1DDDB0 002DDDB0 98CA0A0C */  jal        func_002b2a60
    /* 1DDDB4 002DDDB4 00000000 */   nop
    /* 1DDDB8 002DDDB8 6400043C */  lui        $4, %hi(D_0063FB50)
    /* 1DDDBC 002DDDBC 50FB8424 */  addiu      $4, $4, %lo(D_0063FB50)
    /* 1DDDC0 002DDDC0 DCA9110C */  jal        func_0046a770
    /* 1DDDC4 002DDDC4 00000000 */   nop
    /* 1DDDC8 002DDDC8 2D804000 */  daddu      $16, $2, $0
    /* 1DDDCC 002DDDCC 6400043C */  lui        $4, %hi(D_0063FB50)
    /* 1DDDD0 002DDDD0 50FB8424 */  addiu      $4, $4, %lo(D_0063FB50)
    /* 1DDDD4 002DDDD4 DCA9110C */  jal        func_0046a770
    /* 1DDDD8 002DDDD8 00000000 */   nop
    /* 1DDDDC 002DDDDC 0000A2FF */  sd         $2, 0x0($29)
    /* 1DDDE0 002DDDE0 A9000224 */  addiu      $2, $0, 0xA9
    /* 1DDDE4 002DDDE4 0800A2FF */  sd         $2, 0x8($29)
    /* 1DDDE8 002DDDE8 B041023C */  lui        $2, (0x41B00000 >> 16)
    /* 1DDDEC 002DDDEC 00608244 */  mtc1       $2, $f12
    /* 1DDDF0 002DDDF0 6800A4DF */  ld         $4, 0x68($29)
    /* 1DDDF4 002DDDF4 5001A58F */  lw         $5, 0x150($29)
    /* 1DDDF8 002DDDF8 0F000624 */  addiu      $6, $0, 0xF
    /* 1DDDFC 002DDDFC 2D380000 */  daddu      $7, $0, $0
    /* 1DDE00 002DDE00 2D402002 */  daddu      $8, $17, $0
    /* 1DDE04 002DDE04 1E000924 */  addiu      $9, $0, 0x1E
    /* 1DDE08 002DDE08 7B000A24 */  addiu      $10, $0, 0x7B
    /* 1DDE0C 002DDE0C 2D580002 */  daddu      $11, $16, $0
    /* 1DDE10 002DDE10 342B0B0C */  jal        func_002cacd0
    /* 1DDE14 002DDE14 00000000 */   nop
    /* 1DDE18 002DDE18 DA010010 */  b          .L002DE584
    /* 1DDE1C 002DDE1C 00000000 */   nop
    /* 1DDE20 002DDE20 2D200002 */  daddu      $4, $16, $0
    /* 1DDE24 002DDE24 E01A040C */  jal        func_00106b80
    /* 1DDE28 002DDE28 00000000 */   nop
    /* 1DDE2C 002DDE2C 3C8C0200 */  dsll32     $17, $2, 16
    /* 1DDE30 002DDE30 3F8C1100 */  dsra32     $17, $17, 16
    /* 1DDE34 002DDE34 DF000424 */  addiu      $4, $0, 0xDF
    /* 1DDE38 002DDE38 6C000524 */  addiu      $5, $0, 0x6C
    /* 1DDE3C 002DDE3C 2D300000 */  daddu      $6, $0, $0
    /* 1DDE40 002DDE40 FF000724 */  addiu      $7, $0, 0xFF
    /* 1DDE44 002DDE44 8CCA0A0C */  jal        func_002b2a30
    /* 1DDE48 002DDE48 00000000 */   nop
    /* 1DDE4C 002DDE4C DA42033C */  lui        $3, (0x42DA0000 >> 16)
    /* 1DDE50 002DDE50 00608344 */  mtc1       $3, $f12
    /* 1DDE54 002DDE54 4943033C */  lui        $3, (0x43490000 >> 16)
    /* 1DDE58 002DDE58 00688344 */  mtc1       $3, $f13
    /* 1DDE5C 002DDE5C 8C42033C */  lui        $3, (0x428C0000 >> 16)
    /* 1DDE60 002DDE60 00708344 */  mtc1       $3, $f14
    /* 1DDE64 002DDE64 2D202002 */  daddu      $4, $17, $0
    /* 1DDE68 002DDE68 2D284000 */  daddu      $5, $2, $0
    /* 1DDE6C 002DDE6C 01000624 */  addiu      $6, $0, 0x1
    /* 1DDE70 002DDE70 2D380000 */  daddu      $7, $0, $0
    /* 1DDE74 002DDE74 2D40C000 */  daddu      $8, $6, $0
    /* 1DDE78 002DDE78 57000924 */  addiu      $9, $0, 0x57
    /* 1DDE7C 002DDE7C FCF10A0C */  jal        func_002bc7f0
    /* 1DDE80 002DDE80 00000000 */   nop
    /* 1DDE84 002DDE84 A242023C */  lui        $2, (0x42A20000 >> 16)
    /* 1DDE88 002DDE88 00608244 */  mtc1       $2, $f12
    /* 1DDE8C 002DDE8C 9C0C448E */  lw         $4, 0xC9C($18)
    /* 1DDE90 002DDE90 57000524 */  addiu      $5, $0, 0x57
    /* 1DDE94 002DDE94 78820B0C */  jal        func_002e09e0
    /* 1DDE98 002DDE98 00000000 */   nop
    /* 1DDE9C 002DDE9C 5C01A427 */  addiu      $4, $29, 0x15C
    /* 1DDEA0 002DDEA0 FE000524 */  addiu      $5, $0, 0xFE
    /* 1DDEA4 002DDEA4 EF000624 */  addiu      $6, $0, 0xEF
    /* 1DDEA8 002DDEA8 80000724 */  addiu      $7, $0, 0x80
    /* 1DDEAC 002DDEAC FF000824 */  addiu      $8, $0, 0xFF
    /* 1DDEB0 002DDEB0 98CA0A0C */  jal        func_002b2a60
    /* 1DDEB4 002DDEB4 00000000 */   nop
    /* 1DDEB8 002DDEB8 9C0C448E */  lw         $4, 0xC9C($18)
    /* 1DDEBC 002DDEBC 38810B0C */  jal        func_002e04e0
    /* 1DDEC0 002DDEC0 00000000 */   nop
    /* 1DDEC4 002DDEC4 5C01A693 */  lbu        $6, 0x15C($29)
    /* 1DDEC8 002DDEC8 5D01A593 */  lbu        $5, 0x15D($29)
    /* 1DDECC 002DDECC 5E01A493 */  lbu        $4, 0x15E($29)
    /* 1DDED0 002DDED0 5F01A393 */  lbu        $3, 0x15F($29)
    /* 1DDED4 002DDED4 790046A0 */  sb         $6, 0x79($2)
    /* 1DDED8 002DDED8 7A0045A0 */  sb         $5, 0x7A($2)
    /* 1DDEDC 002DDEDC 7B0044A0 */  sb         $4, 0x7B($2)
    /* 1DDEE0 002DDEE0 7C0043A0 */  sb         $3, 0x7C($2)
    /* 1DDEE4 002DDEE4 E1010224 */  addiu      $2, $0, 0x1E1
    /* 1DDEE8 002DDEE8 00008244 */  mtc1       $2, $f0
    /* 1DDEEC 002DDEEC 00000000 */  nop
    /* 1DDEF0 002DDEF0 20038046 */  cvt.s.w    $f12, $f0
    /* 1DDEF4 002DDEF4 2E43023C */  lui        $2, (0x432E0000 >> 16)
    /* 1DDEF8 002DDEF8 00688244 */  mtc1       $2, $f13
    /* 1DDEFC 002DDEFC E800A427 */  addiu      $4, $29, 0xE8
    /* 1DDF00 002DDF00 5CCA0A0C */  jal        func_002b2970
    /* 1DDF04 002DDF04 00000000 */   nop
    /* 1DDF08 002DDF08 9C0C448E */  lw         $4, 0xC9C($18)
    /* 1DDF0C 002DDF0C 38810B0C */  jal        func_002e04e0
    /* 1DDF10 002DDF10 00000000 */   nop
    /* 1DDF14 002DDF14 E800A1C7 */  lwc1       $f1, 0xE8($29)
    /* 1DDF18 002DDF18 EC00A0C7 */  lwc1       $f0, 0xEC($29)
    /* 1DDF1C 002DDF1C 2C0041E4 */  swc1       $f1, 0x2C($2)
    /* 1DDF20 002DDF20 300040E4 */  swc1       $f0, 0x30($2)
    /* 1DDF24 002DDF24 A042023C */  lui        $2, (0x42A00000 >> 16)
    /* 1DDF28 002DDF28 00608244 */  mtc1       $2, $f12
    /* 1DDF2C 002DDF2C A40C448E */  lw         $4, 0xCA4($18)
    /* 1DDF30 002DDF30 57000524 */  addiu      $5, $0, 0x57
    /* 1DDF34 002DDF34 78820B0C */  jal        func_002e09e0
    /* 1DDF38 002DDF38 00000000 */   nop
    /* 1DDF3C 002DDF3C 5801A427 */  addiu      $4, $29, 0x158
    /* 1DDF40 002DDF40 FE000524 */  addiu      $5, $0, 0xFE
    /* 1DDF44 002DDF44 EF000624 */  addiu      $6, $0, 0xEF
    /* 1DDF48 002DDF48 80000724 */  addiu      $7, $0, 0x80
    /* 1DDF4C 002DDF4C FF000824 */  addiu      $8, $0, 0xFF
    /* 1DDF50 002DDF50 98CA0A0C */  jal        func_002b2a60
    /* 1DDF54 002DDF54 00000000 */   nop
    /* 1DDF58 002DDF58 A40C448E */  lw         $4, 0xCA4($18)
    /* 1DDF5C 002DDF5C 38810B0C */  jal        func_002e04e0
    /* 1DDF60 002DDF60 00000000 */   nop
    /* 1DDF64 002DDF64 5801A693 */  lbu        $6, 0x158($29)
    /* 1DDF68 002DDF68 5901A593 */  lbu        $5, 0x159($29)
    /* 1DDF6C 002DDF6C 5A01A493 */  lbu        $4, 0x15A($29)
    /* 1DDF70 002DDF70 5B01A393 */  lbu        $3, 0x15B($29)
    /* 1DDF74 002DDF74 790046A0 */  sb         $6, 0x79($2)
    /* 1DDF78 002DDF78 7A0045A0 */  sb         $5, 0x7A($2)
    /* 1DDF7C 002DDF7C 7B0044A0 */  sb         $4, 0x7B($2)
    /* 1DDF80 002DDF80 7C0043A0 */  sb         $3, 0x7C($2)
    /* 1DDF84 002DDF84 E1010224 */  addiu      $2, $0, 0x1E1
    /* 1DDF88 002DDF88 00008244 */  mtc1       $2, $f0
    /* 1DDF8C 002DDF8C 00000000 */  nop
    /* 1DDF90 002DDF90 20038046 */  cvt.s.w    $f12, $f0
    /* 1DDF94 002DDF94 6043023C */  lui        $2, (0x43600000 >> 16)
    /* 1DDF98 002DDF98 00688244 */  mtc1       $2, $f13
    /* 1DDF9C 002DDF9C E000A427 */  addiu      $4, $29, 0xE0
    /* 1DDFA0 002DDFA0 5CCA0A0C */  jal        func_002b2970
    /* 1DDFA4 002DDFA4 00000000 */   nop
    /* 1DDFA8 002DDFA8 A40C448E */  lw         $4, 0xCA4($18)
    /* 1DDFAC 002DDFAC 38810B0C */  jal        func_002e04e0
    /* 1DDFB0 002DDFB0 00000000 */   nop
    /* 1DDFB4 002DDFB4 E000A1C7 */  lwc1       $f1, 0xE0($29)
    /* 1DDFB8 002DDFB8 E400A0C7 */  lwc1       $f0, 0xE4($29)
    /* 1DDFBC 002DDFBC 2C0041E4 */  swc1       $f1, 0x2C($2)
    /* 1DDFC0 002DDFC0 300040E4 */  swc1       $f0, 0x30($2)
    /* 1DDFC4 002DDFC4 0E020224 */  addiu      $2, $0, 0x20E
    /* 1DDFC8 002DDFC8 00008244 */  mtc1       $2, $f0
    /* 1DDFCC 002DDFCC 00000000 */  nop
    /* 1DDFD0 002DDFD0 20038046 */  cvt.s.w    $f12, $f0
    /* 1DDFD4 002DDFD4 4A43023C */  lui        $2, (0x434A0000 >> 16)
    /* 1DDFD8 002DDFD8 00688244 */  mtc1       $2, $f13
    /* 1DDFDC 002DDFDC D800A427 */  addiu      $4, $29, 0xD8
    /* 1DDFE0 002DDFE0 5CCA0A0C */  jal        func_002b2970
    /* 1DDFE4 002DDFE4 00000000 */   nop
    /* 1DDFE8 002DDFE8 D800A1C7 */  lwc1       $f1, 0xD8($29)
    /* 1DDFEC 002DDFEC DC00A0C7 */  lwc1       $f0, 0xDC($29)
    /* 1DDFF0 002DDFF0 8000A1E7 */  swc1       $f1, 0x80($29)
    /* 1DDFF4 002DDFF4 8400A0E7 */  swc1       $f0, 0x84($29)
    /* 1DDFF8 002DDFF8 2D200002 */  daddu      $4, $16, $0
    /* 1DDFFC 002DDFFC 501A040C */  jal        func_00106940
    /* 1DE000 002DE000 00000000 */   nop
    /* 1DE004 002DE004 FFFF5130 */  andi       $17, $2, 0xFFFF
    /* 1DE008 002DE008 2D200002 */  daddu      $4, $16, $0
    /* 1DE00C 002DE00C 501A040C */  jal        func_00106940
    /* 1DE010 002DE010 00000000 */   nop
    /* 1DE014 002DE014 2D202002 */  daddu      $4, $17, $0
    /* 1DE018 002DE018 5CCC0A0C */  jal        func_002b3170
    /* 1DE01C 002DE01C 00000000 */   nop
    /* 1DE020 002DE020 FFFF4224 */  addiu      $2, $2, -0x1
    /* 1DE024 002DE024 3C140200 */  dsll32     $2, $2, 16
    /* 1DE028 002DE028 3F140200 */  dsra32     $2, $2, 16
    /* 1DE02C 002DE02C C0100200 */  sll        $2, $2, 3
    /* 1DE030 002DE030 00008244 */  mtc1       $2, $f0
    /* 1DE034 002DE034 00000000 */  nop
    /* 1DE038 002DE038 60008046 */  cvt.s.w    $f1, $f0
    /* 1DE03C 002DE03C 8000A0C7 */  lwc1       $f0, 0x80($29)
    /* 1DE040 002DE040 00030146 */  add.s      $f12, $f0, $f1
    /* 1DE044 002DE044 6000A427 */  addiu      $4, $29, 0x60
    /* 1DE048 002DE048 8400ADC7 */  lwc1       $f13, 0x84($29)
    /* 1DE04C 002DE04C 5CCA0A0C */  jal        func_002b2970
    /* 1DE050 002DE050 00000000 */   nop
    /* 1DE054 002DE054 4C01A427 */  addiu      $4, $29, 0x14C
    /* 1DE058 002DE058 2D000524 */  addiu      $5, $0, 0x2D
    /* 1DE05C 002DE05C 2D30A000 */  daddu      $6, $5, $0
    /* 1DE060 002DE060 2D38A000 */  daddu      $7, $5, $0
    /* 1DE064 002DE064 FF000824 */  addiu      $8, $0, 0xFF
    /* 1DE068 002DE068 98CA0A0C */  jal        func_002b2a60
    /* 1DE06C 002DE06C 00000000 */   nop
    /* 1DE070 002DE070 6400043C */  lui        $4, %hi(D_0063FB50)
    /* 1DE074 002DE074 50FB8424 */  addiu      $4, $4, %lo(D_0063FB50)
    /* 1DE078 002DE078 DCA9110C */  jal        func_0046a770
    /* 1DE07C 002DE07C 00000000 */   nop
    /* 1DE080 002DE080 2D904000 */  daddu      $18, $2, $0
    /* 1DE084 002DE084 6400043C */  lui        $4, %hi(D_0063FB50)
    /* 1DE088 002DE088 50FB8424 */  addiu      $4, $4, %lo(D_0063FB50)
    /* 1DE08C 002DE08C DCA9110C */  jal        func_0046a770
    /* 1DE090 002DE090 00000000 */   nop
    /* 1DE094 002DE094 0000A2FF */  sd         $2, 0x0($29)
    /* 1DE098 002DE098 A9000224 */  addiu      $2, $0, 0xA9
    /* 1DE09C 002DE09C 0800A2FF */  sd         $2, 0x8($29)
    /* 1DE0A0 002DE0A0 B041023C */  lui        $2, (0x41B00000 >> 16)
    /* 1DE0A4 002DE0A4 00608244 */  mtc1       $2, $f12
    /* 1DE0A8 002DE0A8 6000A4DF */  ld         $4, 0x60($29)
    /* 1DE0AC 002DE0AC 4C01A58F */  lw         $5, 0x14C($29)
    /* 1DE0B0 002DE0B0 0F000624 */  addiu      $6, $0, 0xF
    /* 1DE0B4 002DE0B4 2D380000 */  daddu      $7, $0, $0
    /* 1DE0B8 002DE0B8 2D402002 */  daddu      $8, $17, $0
    /* 1DE0BC 002DE0BC 1E000924 */  addiu      $9, $0, 0x1E
    /* 1DE0C0 002DE0C0 7B000A24 */  addiu      $10, $0, 0x7B
    /* 1DE0C4 002DE0C4 2D584002 */  daddu      $11, $18, $0
    /* 1DE0C8 002DE0C8 342B0B0C */  jal        func_002cacd0
    /* 1DE0CC 002DE0CC 00000000 */   nop
    /* 1DE0D0 002DE0D0 0E020224 */  addiu      $2, $0, 0x20E
    /* 1DE0D4 002DE0D4 00008244 */  mtc1       $2, $f0
    /* 1DE0D8 002DE0D8 00000000 */  nop
    /* 1DE0DC 002DE0DC 20038046 */  cvt.s.w    $f12, $f0
    /* 1DE0E0 002DE0E0 7C43023C */  lui        $2, (0x437C0000 >> 16)
    /* 1DE0E4 002DE0E4 00688244 */  mtc1       $2, $f13
    /* 1DE0E8 002DE0E8 D000A427 */  addiu      $4, $29, 0xD0
    /* 1DE0EC 002DE0EC 5CCA0A0C */  jal        func_002b2970
    /* 1DE0F0 002DE0F0 00000000 */   nop
    /* 1DE0F4 002DE0F4 D000A1C7 */  lwc1       $f1, 0xD0($29)
    /* 1DE0F8 002DE0F8 D400A0C7 */  lwc1       $f0, 0xD4($29)
    /* 1DE0FC 002DE0FC 7800A1E7 */  swc1       $f1, 0x78($29)
    /* 1DE100 002DE100 7C00A0E7 */  swc1       $f0, 0x7C($29)
    /* 1DE104 002DE104 2D200002 */  daddu      $4, $16, $0
    /* 1DE108 002DE108 5C1A040C */  jal        func_00106970
    /* 1DE10C 002DE10C 00000000 */   nop
    /* 1DE110 002DE110 FFFF5130 */  andi       $17, $2, 0xFFFF
    /* 1DE114 002DE114 2D200002 */  daddu      $4, $16, $0
    /* 1DE118 002DE118 5C1A040C */  jal        func_00106970
    /* 1DE11C 002DE11C 00000000 */   nop
    /* 1DE120 002DE120 2D202002 */  daddu      $4, $17, $0
    /* 1DE124 002DE124 5CCC0A0C */  jal        func_002b3170
    /* 1DE128 002DE128 00000000 */   nop
    /* 1DE12C 002DE12C FFFF4224 */  addiu      $2, $2, -0x1
    /* 1DE130 002DE130 3C140200 */  dsll32     $2, $2, 16
    /* 1DE134 002DE134 3F140200 */  dsra32     $2, $2, 16
    /* 1DE138 002DE138 C0100200 */  sll        $2, $2, 3
    /* 1DE13C 002DE13C 00008244 */  mtc1       $2, $f0
    /* 1DE140 002DE140 00000000 */  nop
    /* 1DE144 002DE144 60008046 */  cvt.s.w    $f1, $f0
    /* 1DE148 002DE148 7800A0C7 */  lwc1       $f0, 0x78($29)
    /* 1DE14C 002DE14C 00030146 */  add.s      $f12, $f0, $f1
    /* 1DE150 002DE150 5800A427 */  addiu      $4, $29, 0x58
    /* 1DE154 002DE154 7C00ADC7 */  lwc1       $f13, 0x7C($29)
    /* 1DE158 002DE158 5CCA0A0C */  jal        func_002b2970
    /* 1DE15C 002DE15C 00000000 */   nop
    /* 1DE160 002DE160 4801A427 */  addiu      $4, $29, 0x148
    /* 1DE164 002DE164 2D000524 */  addiu      $5, $0, 0x2D
    /* 1DE168 002DE168 2D30A000 */  daddu      $6, $5, $0
    /* 1DE16C 002DE16C 2D38A000 */  daddu      $7, $5, $0
    /* 1DE170 002DE170 FF000824 */  addiu      $8, $0, 0xFF
    /* 1DE174 002DE174 98CA0A0C */  jal        func_002b2a60
    /* 1DE178 002DE178 00000000 */   nop
    /* 1DE17C 002DE17C 6400043C */  lui        $4, %hi(D_0063FB50)
    /* 1DE180 002DE180 50FB8424 */  addiu      $4, $4, %lo(D_0063FB50)
    /* 1DE184 002DE184 DCA9110C */  jal        func_0046a770
    /* 1DE188 002DE188 00000000 */   nop
    /* 1DE18C 002DE18C 2D804000 */  daddu      $16, $2, $0
    /* 1DE190 002DE190 6400043C */  lui        $4, %hi(D_0063FB50)
    /* 1DE194 002DE194 50FB8424 */  addiu      $4, $4, %lo(D_0063FB50)
    /* 1DE198 002DE198 DCA9110C */  jal        func_0046a770
    /* 1DE19C 002DE19C 00000000 */   nop
    /* 1DE1A0 002DE1A0 0000A2FF */  sd         $2, 0x0($29)
    /* 1DE1A4 002DE1A4 A9000224 */  addiu      $2, $0, 0xA9
    /* 1DE1A8 002DE1A8 0800A2FF */  sd         $2, 0x8($29)
    /* 1DE1AC 002DE1AC B041023C */  lui        $2, (0x41B00000 >> 16)
    /* 1DE1B0 002DE1B0 00608244 */  mtc1       $2, $f12
    /* 1DE1B4 002DE1B4 5800A4DF */  ld         $4, 0x58($29)
    /* 1DE1B8 002DE1B8 4801A58F */  lw         $5, 0x148($29)
    /* 1DE1BC 002DE1BC 0F000624 */  addiu      $6, $0, 0xF
    /* 1DE1C0 002DE1C0 2D380000 */  daddu      $7, $0, $0
    /* 1DE1C4 002DE1C4 2D402002 */  daddu      $8, $17, $0
    /* 1DE1C8 002DE1C8 1E000924 */  addiu      $9, $0, 0x1E
    /* 1DE1CC 002DE1CC 7B000A24 */  addiu      $10, $0, 0x7B
    /* 1DE1D0 002DE1D0 2D580002 */  daddu      $11, $16, $0
    /* 1DE1D4 002DE1D4 342B0B0C */  jal        func_002cacd0
    /* 1DE1D8 002DE1D8 00000000 */   nop
    /* 1DE1DC 002DE1DC E9000010 */  b          .L002DE584
    /* 1DE1E0 002DE1E0 00000000 */   nop
    /* 1DE1E4 002DE1E4 2D200002 */  daddu      $4, $16, $0
    /* 1DE1E8 002DE1E8 E01A040C */  jal        func_00106b80
    /* 1DE1EC 002DE1EC 00000000 */   nop
    /* 1DE1F0 002DE1F0 3C840200 */  dsll32     $16, $2, 16
    /* 1DE1F4 002DE1F4 3F841000 */  dsra32     $16, $16, 16
    /* 1DE1F8 002DE1F8 DF000424 */  addiu      $4, $0, 0xDF
    /* 1DE1FC 002DE1FC 6C000524 */  addiu      $5, $0, 0x6C
    /* 1DE200 002DE200 2D300000 */  daddu      $6, $0, $0
    /* 1DE204 002DE204 FF000724 */  addiu      $7, $0, 0xFF
    /* 1DE208 002DE208 8CCA0A0C */  jal        func_002b2a30
    /* 1DE20C 002DE20C 00000000 */   nop
    /* 1DE210 002DE210 DA42033C */  lui        $3, (0x42DA0000 >> 16)
    /* 1DE214 002DE214 00608344 */  mtc1       $3, $f12
    /* 1DE218 002DE218 4943033C */  lui        $3, (0x43490000 >> 16)
    /* 1DE21C 002DE21C 00688344 */  mtc1       $3, $f13
    /* 1DE220 002DE220 8C42033C */  lui        $3, (0x428C0000 >> 16)
    /* 1DE224 002DE224 00708344 */  mtc1       $3, $f14
    /* 1DE228 002DE228 2D200002 */  daddu      $4, $16, $0
    /* 1DE22C 002DE22C 2D284000 */  daddu      $5, $2, $0
    /* 1DE230 002DE230 01000624 */  addiu      $6, $0, 0x1
    /* 1DE234 002DE234 2D380000 */  daddu      $7, $0, $0
    /* 1DE238 002DE238 02000824 */  addiu      $8, $0, 0x2
    /* 1DE23C 002DE23C 57000924 */  addiu      $9, $0, 0x57
    /* 1DE240 002DE240 FCF10A0C */  jal        func_002bc7f0
    /* 1DE244 002DE244 00000000 */   nop
    /* 1DE248 002DE248 A842023C */  lui        $2, (0x42A80000 >> 16)
    /* 1DE24C 002DE24C 00608244 */  mtc1       $2, $f12
    /* 1DE250 002DE250 B80C448E */  lw         $4, 0xCB8($18)
    /* 1DE254 002DE254 57000524 */  addiu      $5, $0, 0x57
    /* 1DE258 002DE258 78820B0C */  jal        func_002e09e0
    /* 1DE25C 002DE25C 00000000 */   nop
    /* 1DE260 002DE260 7F001024 */  addiu      $16, $0, 0x7F
    /* 1DE264 002DE264 B80C448E */  lw         $4, 0xCB8($18)
    /* 1DE268 002DE268 38810B0C */  jal        func_002e04e0
    /* 1DE26C 002DE26C 00000000 */   nop
    /* 1DE270 002DE270 620050A0 */  sb         $16, 0x62($2)
    /* 1DE274 002DE274 EF43023C */  lui        $2, (0x43EF0000 >> 16)
    /* 1DE278 002DE278 00608244 */  mtc1       $2, $f12
    /* 1DE27C 002DE27C 2643023C */  lui        $2, (0x43260000 >> 16)
    /* 1DE280 002DE280 00688244 */  mtc1       $2, $f13
    /* 1DE284 002DE284 C800A427 */  addiu      $4, $29, 0xC8
    /* 1DE288 002DE288 5CCA0A0C */  jal        func_002b2970
    /* 1DE28C 002DE28C 00000000 */   nop
    /* 1DE290 002DE290 B80C448E */  lw         $4, 0xCB8($18)
    /* 1DE294 002DE294 38810B0C */  jal        func_002e04e0
    /* 1DE298 002DE298 00000000 */   nop
    /* 1DE29C 002DE29C C800A1C7 */  lwc1       $f1, 0xC8($29)
    /* 1DE2A0 002DE2A0 CC00A0C7 */  lwc1       $f0, 0xCC($29)
    /* 1DE2A4 002DE2A4 2C0041E4 */  swc1       $f1, 0x2C($2)
    /* 1DE2A8 002DE2A8 300040E4 */  swc1       $f0, 0x30($2)
    /* 1DE2AC 002DE2AC A842023C */  lui        $2, (0x42A80000 >> 16)
    /* 1DE2B0 002DE2B0 00608244 */  mtc1       $2, $f12
    /* 1DE2B4 002DE2B4 AC0E448E */  lw         $4, 0xEAC($18)
    /* 1DE2B8 002DE2B8 57000524 */  addiu      $5, $0, 0x57
    /* 1DE2BC 002DE2BC 78820B0C */  jal        func_002e09e0
    /* 1DE2C0 002DE2C0 00000000 */   nop
    /* 1DE2C4 002DE2C4 AC0E448E */  lw         $4, 0xEAC($18)
    /* 1DE2C8 002DE2C8 38810B0C */  jal        func_002e04e0
    /* 1DE2CC 002DE2CC 00000000 */   nop
    /* 1DE2D0 002DE2D0 620050A0 */  sb         $16, 0x62($2)
    /* 1DE2D4 002DE2D4 DD010224 */  addiu      $2, $0, 0x1DD
    /* 1DE2D8 002DE2D8 00008244 */  mtc1       $2, $f0
    /* 1DE2DC 002DE2DC 00000000 */  nop
    /* 1DE2E0 002DE2E0 20038046 */  cvt.s.w    $f12, $f0
    /* 1DE2E4 002DE2E4 5843023C */  lui        $2, (0x43580000 >> 16)
    /* 1DE2E8 002DE2E8 00688244 */  mtc1       $2, $f13
    /* 1DE2EC 002DE2EC C000A427 */  addiu      $4, $29, 0xC0
    /* 1DE2F0 002DE2F0 5CCA0A0C */  jal        func_002b2970
    /* 1DE2F4 002DE2F4 00000000 */   nop
    /* 1DE2F8 002DE2F8 AC0E448E */  lw         $4, 0xEAC($18)
    /* 1DE2FC 002DE2FC 38810B0C */  jal        func_002e04e0
    /* 1DE300 002DE300 00000000 */   nop
    /* 1DE304 002DE304 C000A1C7 */  lwc1       $f1, 0xC0($29)
    /* 1DE308 002DE308 C400A0C7 */  lwc1       $f0, 0xC4($29)
    /* 1DE30C 002DE30C 2C0041E4 */  swc1       $f1, 0x2C($2)
    /* 1DE310 002DE310 300040E4 */  swc1       $f0, 0x30($2)
    /* 1DE314 002DE314 9B000010 */  b          .L002DE584
    /* 1DE318 002DE318 00000000 */   nop
  .L002DE31C:
    /* 1DE31C 002DE31C 02000224 */  addiu      $2, $0, 0x2
    /* 1DE320 002DE320 34008214 */  bne        $4, $2, .L002DE3F4
    /* 1DE324 002DE324 00000000 */   nop
    /* 1DE328 002DE328 AC42023C */  lui        $2, (0x42AC0000 >> 16)
    /* 1DE32C 002DE32C 00608244 */  mtc1       $2, $f12
    /* 1DE330 002DE330 0743023C */  lui        $2, (0x43070000 >> 16)
    /* 1DE334 002DE334 00688244 */  mtc1       $2, $f13
    /* 1DE338 002DE338 B800A427 */  addiu      $4, $29, 0xB8
    /* 1DE33C 002DE33C 5CCA0A0C */  jal        func_002b2970
    /* 1DE340 002DE340 00000000 */   nop
    /* 1DE344 002DE344 2D200000 */  daddu      $4, $0, $0
    /* 1DE348 002DE348 2D000524 */  addiu      $5, $0, 0x2D
    /* 1DE34C 002DE34C 2D30A000 */  daddu      $6, $5, $0
    /* 1DE350 002DE350 2D38A000 */  daddu      $7, $5, $0
    /* 1DE354 002DE354 8CCA0A0C */  jal        func_002b2a30
    /* 1DE358 002DE358 00000000 */   nop
    /* 1DE35C 002DE35C 8A42033C */  lui        $3, (0x428A0000 >> 16)
    /* 1DE360 002DE360 00608344 */  mtc1       $3, $f12
    /* 1DE364 002DE364 1B000424 */  addiu      $4, $0, 0x1B
    /* 1DE368 002DE368 B800A5DF */  ld         $5, 0xB8($29)
    /* 1DE36C 002DE36C 2D304000 */  daddu      $6, $2, $0
    /* 1DE370 002DE370 FF000724 */  addiu      $7, $0, 0xFF
    /* 1DE374 002DE374 2D400000 */  daddu      $8, $0, $0
    /* 1DE378 002DE378 7900093C */  lui        $9, %hi(D_00795E30)
    /* 1DE37C 002DE37C 305E2925 */  addiu      $9, $9, %lo(D_00795E30)
    /* 1DE380 002DE380 28830B0C */  jal        func_002e0ca0
    /* 1DE384 002DE384 00000000 */   nop
    /* 1DE388 002DE388 2D200002 */  daddu      $4, $16, $0
    /* 1DE38C 002DE38C E01A040C */  jal        func_00106b80
    /* 1DE390 002DE390 00000000 */   nop
    /* 1DE394 002DE394 3C840200 */  dsll32     $16, $2, 16
    /* 1DE398 002DE398 3F841000 */  dsra32     $16, $16, 16
    /* 1DE39C 002DE39C DF000424 */  addiu      $4, $0, 0xDF
    /* 1DE3A0 002DE3A0 6C000524 */  addiu      $5, $0, 0x6C
    /* 1DE3A4 002DE3A4 2D300000 */  daddu      $6, $0, $0
    /* 1DE3A8 002DE3A8 FF000724 */  addiu      $7, $0, 0xFF
    /* 1DE3AC 002DE3AC 8CCA0A0C */  jal        func_002b2a30
    /* 1DE3B0 002DE3B0 00000000 */   nop
    /* 1DE3B4 002DE3B4 DA42033C */  lui        $3, (0x42DA0000 >> 16)
    /* 1DE3B8 002DE3B8 00608344 */  mtc1       $3, $f12
    /* 1DE3BC 002DE3BC 4943033C */  lui        $3, (0x43490000 >> 16)
    /* 1DE3C0 002DE3C0 00688344 */  mtc1       $3, $f13
    /* 1DE3C4 002DE3C4 8C42033C */  lui        $3, (0x428C0000 >> 16)
    /* 1DE3C8 002DE3C8 00708344 */  mtc1       $3, $f14
    /* 1DE3CC 002DE3CC 2D200002 */  daddu      $4, $16, $0
    /* 1DE3D0 002DE3D0 2D284000 */  daddu      $5, $2, $0
    /* 1DE3D4 002DE3D4 01000624 */  addiu      $6, $0, 0x1
    /* 1DE3D8 002DE3D8 2D380000 */  daddu      $7, $0, $0
    /* 1DE3DC 002DE3DC 04000824 */  addiu      $8, $0, 0x4
    /* 1DE3E0 002DE3E0 57000924 */  addiu      $9, $0, 0x57
    /* 1DE3E4 002DE3E4 FCF10A0C */  jal        func_002bc7f0
    /* 1DE3E8 002DE3E8 00000000 */   nop
    /* 1DE3EC 002DE3EC 32000010 */  b          .L002DE4B8
    /* 1DE3F0 002DE3F0 00000000 */   nop
  .L002DE3F4:
    /* 1DE3F4 002DE3F4 AC42023C */  lui        $2, (0x42AC0000 >> 16)
    /* 1DE3F8 002DE3F8 00608244 */  mtc1       $2, $f12
    /* 1DE3FC 002DE3FC 0743023C */  lui        $2, (0x43070000 >> 16)
    /* 1DE400 002DE400 00688244 */  mtc1       $2, $f13
    /* 1DE404 002DE404 B000A427 */  addiu      $4, $29, 0xB0
    /* 1DE408 002DE408 5CCA0A0C */  jal        func_002b2970
    /* 1DE40C 002DE40C 00000000 */   nop
    /* 1DE410 002DE410 2D200000 */  daddu      $4, $0, $0
    /* 1DE414 002DE414 2D000524 */  addiu      $5, $0, 0x2D
    /* 1DE418 002DE418 2D30A000 */  daddu      $6, $5, $0
    /* 1DE41C 002DE41C 2D38A000 */  daddu      $7, $5, $0
    /* 1DE420 002DE420 8CCA0A0C */  jal        func_002b2a30
    /* 1DE424 002DE424 00000000 */   nop
    /* 1DE428 002DE428 8A42033C */  lui        $3, (0x428A0000 >> 16)
    /* 1DE42C 002DE42C 00608344 */  mtc1       $3, $f12
    /* 1DE430 002DE430 1A000424 */  addiu      $4, $0, 0x1A
    /* 1DE434 002DE434 B000A5DF */  ld         $5, 0xB0($29)
    /* 1DE438 002DE438 2D304000 */  daddu      $6, $2, $0
    /* 1DE43C 002DE43C FF000724 */  addiu      $7, $0, 0xFF
    /* 1DE440 002DE440 2D400000 */  daddu      $8, $0, $0
    /* 1DE444 002DE444 7900093C */  lui        $9, %hi(D_00795E30)
    /* 1DE448 002DE448 305E2925 */  addiu      $9, $9, %lo(D_00795E30)
    /* 1DE44C 002DE44C 28830B0C */  jal        func_002e0ca0
    /* 1DE450 002DE450 00000000 */   nop
    /* 1DE454 002DE454 2D200002 */  daddu      $4, $16, $0
    /* 1DE458 002DE458 E01A040C */  jal        func_00106b80
    /* 1DE45C 002DE45C 00000000 */   nop
    /* 1DE460 002DE460 3C840200 */  dsll32     $16, $2, 16
    /* 1DE464 002DE464 3F841000 */  dsra32     $16, $16, 16
    /* 1DE468 002DE468 DF000424 */  addiu      $4, $0, 0xDF
    /* 1DE46C 002DE46C 6C000524 */  addiu      $5, $0, 0x6C
    /* 1DE470 002DE470 2D300000 */  daddu      $6, $0, $0
    /* 1DE474 002DE474 FF000724 */  addiu      $7, $0, 0xFF
    /* 1DE478 002DE478 8CCA0A0C */  jal        func_002b2a30
    /* 1DE47C 002DE47C 00000000 */   nop
    /* 1DE480 002DE480 DA42033C */  lui        $3, (0x42DA0000 >> 16)
    /* 1DE484 002DE484 00608344 */  mtc1       $3, $f12
    /* 1DE488 002DE488 4943033C */  lui        $3, (0x43490000 >> 16)
    /* 1DE48C 002DE48C 00688344 */  mtc1       $3, $f13
    /* 1DE490 002DE490 8C42033C */  lui        $3, (0x428C0000 >> 16)
    /* 1DE494 002DE494 00708344 */  mtc1       $3, $f14
    /* 1DE498 002DE498 2D200002 */  daddu      $4, $16, $0
    /* 1DE49C 002DE49C 2D284000 */  daddu      $5, $2, $0
    /* 1DE4A0 002DE4A0 01000624 */  addiu      $6, $0, 0x1
    /* 1DE4A4 002DE4A4 2D380000 */  daddu      $7, $0, $0
    /* 1DE4A8 002DE4A8 07000824 */  addiu      $8, $0, 0x7
    /* 1DE4AC 002DE4AC 57000924 */  addiu      $9, $0, 0x57
    /* 1DE4B0 002DE4B0 FCF10A0C */  jal        func_002bc7f0
    /* 1DE4B4 002DE4B4 00000000 */   nop
  .L002DE4B8:
    /* 1DE4B8 002DE4B8 A842023C */  lui        $2, (0x42A80000 >> 16)
    /* 1DE4BC 002DE4BC 00608244 */  mtc1       $2, $f12
    /* 1DE4C0 002DE4C0 B80C448E */  lw         $4, 0xCB8($18)
    /* 1DE4C4 002DE4C4 56000524 */  addiu      $5, $0, 0x56
    /* 1DE4C8 002DE4C8 78820B0C */  jal        func_002e09e0
    /* 1DE4CC 002DE4CC 00000000 */   nop
    /* 1DE4D0 002DE4D0 7F001024 */  addiu      $16, $0, 0x7F
    /* 1DE4D4 002DE4D4 B80C448E */  lw         $4, 0xCB8($18)
    /* 1DE4D8 002DE4D8 38810B0C */  jal        func_002e04e0
    /* 1DE4DC 002DE4DC 00000000 */   nop
    /* 1DE4E0 002DE4E0 620050A0 */  sb         $16, 0x62($2)
    /* 1DE4E4 002DE4E4 EF43023C */  lui        $2, (0x43EF0000 >> 16)
    /* 1DE4E8 002DE4E8 00608244 */  mtc1       $2, $f12
    /* 1DE4EC 002DE4EC 2643023C */  lui        $2, (0x43260000 >> 16)
    /* 1DE4F0 002DE4F0 00688244 */  mtc1       $2, $f13
    /* 1DE4F4 002DE4F4 A800A427 */  addiu      $4, $29, 0xA8
    /* 1DE4F8 002DE4F8 5CCA0A0C */  jal        func_002b2970
    /* 1DE4FC 002DE4FC 00000000 */   nop
    /* 1DE500 002DE500 B80C448E */  lw         $4, 0xCB8($18)
    /* 1DE504 002DE504 38810B0C */  jal        func_002e04e0
    /* 1DE508 002DE508 00000000 */   nop
    /* 1DE50C 002DE50C A800A1C7 */  lwc1       $f1, 0xA8($29)
    /* 1DE510 002DE510 AC00A0C7 */  lwc1       $f0, 0xAC($29)
    /* 1DE514 002DE514 2C0041E4 */  swc1       $f1, 0x2C($2)
    /* 1DE518 002DE518 300040E4 */  swc1       $f0, 0x30($2)
    /* 1DE51C 002DE51C A842023C */  lui        $2, (0x42A80000 >> 16)
    /* 1DE520 002DE520 00608244 */  mtc1       $2, $f12
    /* 1DE524 002DE524 AC0E448E */  lw         $4, 0xEAC($18)
    /* 1DE528 002DE528 56000524 */  addiu      $5, $0, 0x56
    /* 1DE52C 002DE52C 78820B0C */  jal        func_002e09e0
    /* 1DE530 002DE530 00000000 */   nop
    /* 1DE534 002DE534 AC0E448E */  lw         $4, 0xEAC($18)
    /* 1DE538 002DE538 38810B0C */  jal        func_002e04e0
    /* 1DE53C 002DE53C 00000000 */   nop
    /* 1DE540 002DE540 620050A0 */  sb         $16, 0x62($2)
    /* 1DE544 002DE544 DD010224 */  addiu      $2, $0, 0x1DD
    /* 1DE548 002DE548 00008244 */  mtc1       $2, $f0
    /* 1DE54C 002DE54C 00000000 */  nop
    /* 1DE550 002DE550 20038046 */  cvt.s.w    $f12, $f0
    /* 1DE554 002DE554 5843023C */  lui        $2, (0x43580000 >> 16)
    /* 1DE558 002DE558 00688244 */  mtc1       $2, $f13
    /* 1DE55C 002DE55C A000A427 */  addiu      $4, $29, 0xA0
    /* 1DE560 002DE560 5CCA0A0C */  jal        func_002b2970
    /* 1DE564 002DE564 00000000 */   nop
    /* 1DE568 002DE568 AC0E448E */  lw         $4, 0xEAC($18)
    /* 1DE56C 002DE56C 38810B0C */  jal        func_002e04e0
    /* 1DE570 002DE570 00000000 */   nop
    /* 1DE574 002DE574 A000A1C7 */  lwc1       $f1, 0xA0($29)
    /* 1DE578 002DE578 A400A0C7 */  lwc1       $f0, 0xA4($29)
    /* 1DE57C 002DE57C 2C0041E4 */  swc1       $f1, 0x2C($2)
    /* 1DE580 002DE580 300040E4 */  swc1       $f0, 0x30($2)
  .L002DE584:
    /* 1DE584 002DE584 4000BFDF */  ld         $31, 0x40($29)
    /* 1DE588 002DE588 3000B27B */  lq         $18, 0x30($29)
    /* 1DE58C 002DE58C 2000B17B */  lq         $17, 0x20($29)
    /* 1DE590 002DE590 1000B07B */  lq         $16, 0x10($29)
    /* 1DE594 002DE594 7001BD27 */  addiu      $29, $29, 0x170
    /* 1DE598 002DE598 0800E003 */  jr         $31
    /* 1DE59C 002DE59C 00000000 */   nop
.size func_002dd3b0, 0x11f0
