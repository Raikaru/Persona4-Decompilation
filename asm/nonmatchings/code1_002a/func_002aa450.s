.section .text
.set noat
.set noreorder
glabel func_002aa450
    /* 1AA450 002AA450 10FFBD27 */  addiu      $29, $29, -0xF0
    /* 1AA454 002AA454 5000BFFF */  sd         $31, 0x50($29)
    /* 1AA458 002AA458 4000B17F */  sq         $17, 0x40($29)
    /* 1AA45C 002AA45C 3000B07F */  sq         $16, 0x30($29)
    /* 1AA460 002AA460 2C00B7E7 */  swc1       $f23, 0x2C($29)
    /* 1AA464 002AA464 2800B6E7 */  swc1       $f22, 0x28($29)
    /* 1AA468 002AA468 2400B5E7 */  swc1       $f21, 0x24($29)
    /* 1AA46C 002AA46C 2000B4E7 */  swc1       $f20, 0x20($29)
    /* 1AA470 002AA470 8800023C */  lui        $2, %hi(D_00882F20)
    /* 1AA474 002AA474 202F4224 */  addiu      $2, $2, %lo(D_00882F20)
    /* 1AA478 002AA478 6400033C */  lui        $3, %hi(D_0063EDF0)
    /* 1AA47C 002AA47C F0ED64DC */  ld         $4, %lo(D_0063EDF0)($3)
    /* 1AA480 002AA480 6400033C */  lui        $3, %hi(D_0063EDF8)
    /* 1AA484 002AA484 F8ED60C4 */  lwc1       $f0, %lo(D_0063EDF8)($3)
    /* 1AA488 002AA488 E000A4FF */  sd         $4, 0xE0($29)
    /* 1AA48C 002AA48C E800A0E7 */  swc1       $f0, 0xE8($29)
    /* 1AA490 002AA490 6400033C */  lui        $3, %hi(D_0063EE00)
    /* 1AA494 002AA494 00EE64DC */  ld         $4, %lo(D_0063EE00)($3)
    /* 1AA498 002AA498 6400033C */  lui        $3, %hi(D_0063EE08)
    /* 1AA49C 002AA49C 08EE60C4 */  lwc1       $f0, %lo(D_0063EE08)($3)
    /* 1AA4A0 002AA4A0 D000A4FF */  sd         $4, 0xD0($29)
    /* 1AA4A4 002AA4A4 D800A0E7 */  swc1       $f0, 0xD8($29)
    /* 1AA4A8 002AA4A8 6400033C */  lui        $3, %hi(D_0063EE10)
    /* 1AA4AC 002AA4AC 10EE64DC */  ld         $4, %lo(D_0063EE10)($3)
    /* 1AA4B0 002AA4B0 6400033C */  lui        $3, %hi(D_0063EE18)
    /* 1AA4B4 002AA4B4 18EE60C4 */  lwc1       $f0, %lo(D_0063EE18)($3)
    /* 1AA4B8 002AA4B8 C000A4FF */  sd         $4, 0xC0($29)
    /* 1AA4BC 002AA4BC C800A0E7 */  swc1       $f0, 0xC8($29)
    /* 1AA4C0 002AA4C0 6400033C */  lui        $3, %hi(D_0063EE20)
    /* 1AA4C4 002AA4C4 20EE64DC */  ld         $4, %lo(D_0063EE20)($3)
    /* 1AA4C8 002AA4C8 6400033C */  lui        $3, %hi(D_0063EE28)
    /* 1AA4CC 002AA4CC 28EE60C4 */  lwc1       $f0, %lo(D_0063EE28)($3)
    /* 1AA4D0 002AA4D0 B000A4FF */  sd         $4, 0xB0($29)
    /* 1AA4D4 002AA4D4 B800A0E7 */  swc1       $f0, 0xB8($29)
    /* 1AA4D8 002AA4D8 6400033C */  lui        $3, %hi(D_0063EE30)
    /* 1AA4DC 002AA4DC 30EE64DC */  ld         $4, %lo(D_0063EE30)($3)
    /* 1AA4E0 002AA4E0 6400033C */  lui        $3, %hi(D_0063EE38)
    /* 1AA4E4 002AA4E4 38EE60C4 */  lwc1       $f0, %lo(D_0063EE38)($3)
    /* 1AA4E8 002AA4E8 A000A4FF */  sd         $4, 0xA0($29)
    /* 1AA4EC 002AA4EC A800A0E7 */  swc1       $f0, 0xA8($29)
    /* 1AA4F0 002AA4F0 8800033C */  lui        $3, %hi(D_00882F2C)
    /* 1AA4F4 002AA4F4 2C2F60C4 */  lwc1       $f0, %lo(D_00882F2C)($3)
    /* 1AA4F8 002AA4F8 60008046 */  cvt.s.w    $f1, $f0
    /* 1AA4FC 002AA4FC A040033C */  lui        $3, (0x40A00000 >> 16)
    /* 1AA500 002AA500 00008344 */  mtc1       $3, $f0
    /* 1AA504 002AA504 00000000 */  nop
    /* 1AA508 002AA508 030D0046 */  div.s      $f20, $f1, $f0
    /* 1AA50C 002AA50C 8800033C */  lui        $3, %hi(D_00882F28)
    /* 1AA510 002AA510 282F638C */  lw         $3, %lo(D_00882F28)($3)
    /* 1AA514 002AA514 01006424 */  addiu      $4, $3, 0x1
    /* 1AA518 002AA518 8800033C */  lui        $3, %hi(D_00882F28)
    /* 1AA51C 002AA51C 282F64AC */  sw         $4, %lo(D_00882F28)($3)
    /* 1AA520 002AA520 3C008328 */  slti       $3, $4, 0x3C
    /* 1AA524 002AA524 02006014 */  bnez       $3, .L002AA530
    /* 1AA528 002AA528 00000000 */   nop
    /* 1AA52C 002AA52C 080040AC */  sw         $0, 0x8($2)
  .L002AA530:
    /* 1AA530 002AA530 080040C4 */  lwc1       $f0, 0x8($2)
    /* 1AA534 002AA534 60008046 */  cvt.s.w    $f1, $f0
    /* 1AA538 002AA538 7042023C */  lui        $2, (0x42700000 >> 16)
    /* 1AA53C 002AA53C 00008244 */  mtc1       $2, $f0
    /* 1AA540 002AA540 00000000 */  nop
    /* 1AA544 002AA544 430D0046 */  div.s      $f21, $f1, $f0
    /* 1AA548 002AA548 803F023C */  lui        $2, (0x3F800000 >> 16)
    /* 1AA54C 002AA54C 00008244 */  mtc1       $2, $f0
    /* 1AA550 002AA550 00000000 */  nop
    /* 1AA554 002AA554 41001446 */  sub.s      $f1, $f0, $f20
    /* 1AA558 002AA558 2041023C */  lui        $2, (0x41200000 >> 16)
    /* 1AA55C 002AA55C 00008244 */  mtc1       $2, $f0
    /* 1AA560 002AA560 00000000 */  nop
    /* 1AA564 002AA564 42000146 */  mul.s      $f1, $f0, $f1
    /* 1AA568 002AA568 A0C2023C */  lui        $2, (0xC2A00000 >> 16)
    /* 1AA56C 002AA56C 00008244 */  mtc1       $2, $f0
    /* 1AA570 002AA570 00000000 */  nop
    /* 1AA574 002AA574 C1050146 */  sub.s      $f23, $f0, $f1
    /* 1AA578 002AA578 6000A427 */  addiu      $4, $29, 0x60
    /* 1AA57C 002AA57C E000A527 */  addiu      $5, $29, 0xE0
    /* 1AA580 002AA580 06BB0046 */  mov.s      $f12, $f23
    /* 1AA584 002AA584 2D300000 */  daddu      $6, $0, $0
    /* 1AA588 002AA588 1C820F0C */  jal        func_003e0870
    /* 1AA58C 002AA58C 00000000 */   nop
    /* 1AA590 002AA590 B000A427 */  addiu      $4, $29, 0xB0
    /* 1AA594 002AA594 2D288000 */  daddu      $5, $4, $0
    /* 1AA598 002AA598 6000A627 */  addiu      $6, $29, 0x60
    /* 1AA59C 002AA59C C8900F0C */  jal        func_003e4320
    /* 1AA5A0 002AA5A0 00000000 */   nop
    /* 1AA5A4 002AA5A4 B443023C */  lui        $2, (0x43B40000 >> 16)
    /* 1AA5A8 002AA5A8 00008244 */  mtc1       $2, $f0
    /* 1AA5AC 002AA5AC 00000000 */  nop
    /* 1AA5B0 002AA5B0 82051546 */  mul.s      $f22, $f0, $f21
    /* 1AA5B4 002AA5B4 6000A427 */  addiu      $4, $29, 0x60
    /* 1AA5B8 002AA5B8 B000A527 */  addiu      $5, $29, 0xB0
    /* 1AA5BC 002AA5BC 06B30046 */  mov.s      $f12, $f22
    /* 1AA5C0 002AA5C0 02000624 */  addiu      $6, $0, 0x2
    /* 1AA5C4 002AA5C4 1C820F0C */  jal        func_003e0870
    /* 1AA5C8 002AA5C8 00000000 */   nop
    /* 1AA5CC 002AA5CC 6000A427 */  addiu      $4, $29, 0x60
    /* 1AA5D0 002AA5D0 A000A527 */  addiu      $5, $29, 0xA0
    /* 1AA5D4 002AA5D4 02000624 */  addiu      $6, $0, 0x2
    /* 1AA5D8 002AA5D8 A4820F0C */  jal        func_003e0a90
    /* 1AA5DC 002AA5DC 00000000 */   nop
    /* 1AA5E0 002AA5E0 A3010224 */  addiu      $2, $0, 0x1A3
    /* 1AA5E4 002AA5E4 00008244 */  mtc1       $2, $f0
    /* 1AA5E8 002AA5E8 00000000 */  nop
    /* 1AA5EC 002AA5EC 20008046 */  cvt.s.w    $f0, $f0
    /* 1AA5F0 002AA5F0 24000046 */  .word      0x46000024                    # cvt.w.s    $f0, $f0 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    /* 1AA5F4 002AA5F4 00001144 */  mfc1       $17, $f0
    /* 1AA5F8 002AA5F8 42020224 */  addiu      $2, $0, 0x242
    /* 1AA5FC 002AA5FC 00008244 */  mtc1       $2, $f0
    /* 1AA600 002AA600 00000000 */  nop
    /* 1AA604 002AA604 20008046 */  cvt.s.w    $f0, $f0
    /* 1AA608 002AA608 24000046 */  .word      0x46000024                    # cvt.w.s    $f0, $f0 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    /* 1AA60C 002AA60C 00001044 */  mfc1       $16, $f0
    /* 1AA610 002AA610 0000A0FF */  sd         $0, 0x0($29)
    /* 1AA614 002AA614 6000A227 */  addiu      $2, $29, 0x60
    /* 1AA618 002AA618 0800A2FF */  sd         $2, 0x8($29)
    /* 1AA61C 002AA61C 1000A0FF */  sd         $0, 0x10($29)
    /* 1AA620 002AA620 00608044 */  mtc1       $0, $f12
    /* 1AA624 002AA624 2D200002 */  daddu      $4, $16, $0
    /* 1AA628 002AA628 2D282002 */  daddu      $5, $17, $0
    /* 1AA62C 002AA62C 18000624 */  addiu      $6, $0, 0x18
    /* 1AA630 002AA630 1F000724 */  addiu      $7, $0, 0x1F
    /* 1AA634 002AA634 00FF0834 */  ori        $8, $0, 0xFF00
    /* 1AA638 002AA638 FF000924 */  addiu      $9, $0, 0xFF
    /* 1AA63C 002AA63C 01000A24 */  addiu      $10, $0, 0x1
    /* 1AA640 002AA640 2D580000 */  daddu      $11, $0, $0
    /* 1AA644 002AA644 589A0D0C */  jal        func_00366960
    /* 1AA648 002AA648 00000000 */   nop
    /* 1AA64C 002AA64C 6000A427 */  addiu      $4, $29, 0x60
    /* 1AA650 002AA650 E000A527 */  addiu      $5, $29, 0xE0
    /* 1AA654 002AA654 06BB0046 */  mov.s      $f12, $f23
    /* 1AA658 002AA658 2D300000 */  daddu      $6, $0, $0
    /* 1AA65C 002AA65C 1C820F0C */  jal        func_003e0870
    /* 1AA660 002AA660 00000000 */   nop
    /* 1AA664 002AA664 F042023C */  lui        $2, (0x42F00000 >> 16)
    /* 1AA668 002AA668 00008244 */  mtc1       $2, $f0
    /* 1AA66C 002AA66C 00000000 */  nop
    /* 1AA670 002AA670 00031646 */  add.s      $f12, $f0, $f22
    /* 1AA674 002AA674 6000A427 */  addiu      $4, $29, 0x60
    /* 1AA678 002AA678 B000A527 */  addiu      $5, $29, 0xB0
    /* 1AA67C 002AA67C 02000624 */  addiu      $6, $0, 0x2
    /* 1AA680 002AA680 1C820F0C */  jal        func_003e0870
    /* 1AA684 002AA684 00000000 */   nop
    /* 1AA688 002AA688 6000A427 */  addiu      $4, $29, 0x60
    /* 1AA68C 002AA68C A000A527 */  addiu      $5, $29, 0xA0
    /* 1AA690 002AA690 02000624 */  addiu      $6, $0, 0x2
    /* 1AA694 002AA694 A4820F0C */  jal        func_003e0a90
    /* 1AA698 002AA698 00000000 */   nop
    /* 1AA69C 002AA69C 0000A0FF */  sd         $0, 0x0($29)
    /* 1AA6A0 002AA6A0 6000A227 */  addiu      $2, $29, 0x60
    /* 1AA6A4 002AA6A4 0800A2FF */  sd         $2, 0x8($29)
    /* 1AA6A8 002AA6A8 1000A0FF */  sd         $0, 0x10($29)
    /* 1AA6AC 002AA6AC 00608044 */  mtc1       $0, $f12
    /* 1AA6B0 002AA6B0 2D200002 */  daddu      $4, $16, $0
    /* 1AA6B4 002AA6B4 2D282002 */  daddu      $5, $17, $0
    /* 1AA6B8 002AA6B8 18000624 */  addiu      $6, $0, 0x18
    /* 1AA6BC 002AA6BC 1F000724 */  addiu      $7, $0, 0x1F
    /* 1AA6C0 002AA6C0 FF00023C */  lui        $2, (0xFFFF00 >> 16)
    /* 1AA6C4 002AA6C4 00FF4834 */  ori        $8, $2, (0xFFFF00 & 0xFFFF)
    /* 1AA6C8 002AA6C8 FF000924 */  addiu      $9, $0, 0xFF
    /* 1AA6CC 002AA6CC 01000A24 */  addiu      $10, $0, 0x1
    /* 1AA6D0 002AA6D0 2D580000 */  daddu      $11, $0, $0
    /* 1AA6D4 002AA6D4 589A0D0C */  jal        func_00366960
    /* 1AA6D8 002AA6D8 00000000 */   nop
    /* 1AA6DC 002AA6DC 6000A427 */  addiu      $4, $29, 0x60
    /* 1AA6E0 002AA6E0 E000A527 */  addiu      $5, $29, 0xE0
    /* 1AA6E4 002AA6E4 06BB0046 */  mov.s      $f12, $f23
    /* 1AA6E8 002AA6E8 2D300000 */  daddu      $6, $0, $0
    /* 1AA6EC 002AA6EC 1C820F0C */  jal        func_003e0870
    /* 1AA6F0 002AA6F0 00000000 */   nop
    /* 1AA6F4 002AA6F4 7043023C */  lui        $2, (0x43700000 >> 16)
    /* 1AA6F8 002AA6F8 00008244 */  mtc1       $2, $f0
    /* 1AA6FC 002AA6FC 00000000 */  nop
    /* 1AA700 002AA700 00031646 */  add.s      $f12, $f0, $f22
    /* 1AA704 002AA704 6000A427 */  addiu      $4, $29, 0x60
    /* 1AA708 002AA708 B000A527 */  addiu      $5, $29, 0xB0
    /* 1AA70C 002AA70C 02000624 */  addiu      $6, $0, 0x2
    /* 1AA710 002AA710 1C820F0C */  jal        func_003e0870
    /* 1AA714 002AA714 00000000 */   nop
    /* 1AA718 002AA718 6000A427 */  addiu      $4, $29, 0x60
    /* 1AA71C 002AA71C A000A527 */  addiu      $5, $29, 0xA0
    /* 1AA720 002AA720 02000624 */  addiu      $6, $0, 0x2
    /* 1AA724 002AA724 A4820F0C */  jal        func_003e0a90
    /* 1AA728 002AA728 00000000 */   nop
    /* 1AA72C 002AA72C 0000A0FF */  sd         $0, 0x0($29)
    /* 1AA730 002AA730 6000A227 */  addiu      $2, $29, 0x60
    /* 1AA734 002AA734 0800A2FF */  sd         $2, 0x8($29)
    /* 1AA738 002AA738 1000A0FF */  sd         $0, 0x10($29)
    /* 1AA73C 002AA73C 00608044 */  mtc1       $0, $f12
    /* 1AA740 002AA740 2D200002 */  daddu      $4, $16, $0
    /* 1AA744 002AA744 2D282002 */  daddu      $5, $17, $0
    /* 1AA748 002AA748 18000624 */  addiu      $6, $0, 0x18
    /* 1AA74C 002AA74C 1F000724 */  addiu      $7, $0, 0x1F
    /* 1AA750 002AA750 FF00083C */  lui        $8, (0xFF0000 >> 16)
    /* 1AA754 002AA754 FF000924 */  addiu      $9, $0, 0xFF
    /* 1AA758 002AA758 01000A24 */  addiu      $10, $0, 0x1
    /* 1AA75C 002AA75C 2D580000 */  daddu      $11, $0, $0
    /* 1AA760 002AA760 589A0D0C */  jal        func_00366960
    /* 1AA764 002AA764 00000000 */   nop
    /* 1AA768 002AA768 6000A427 */  addiu      $4, $29, 0x60
    /* 1AA76C 002AA76C D000A527 */  addiu      $5, $29, 0xD0
    /* 1AA770 002AA770 5C858CC7 */  lwc1       $f12, -0x7AA4($28)
    /* 1AA774 002AA774 2D300000 */  daddu      $6, $0, $0
    /* 1AA778 002AA778 1C820F0C */  jal        func_003e0870
    /* 1AA77C 002AA77C 00000000 */   nop
    /* 1AA780 002AA780 65010224 */  addiu      $2, $0, 0x165
    /* 1AA784 002AA784 00008244 */  mtc1       $2, $f0
    /* 1AA788 002AA788 00000000 */  nop
    /* 1AA78C 002AA78C A0008046 */  cvt.s.w    $f2, $f0
    /* 1AA790 002AA790 4040023C */  lui        $2, (0x40400000 >> 16)
    /* 1AA794 002AA794 00088244 */  mtc1       $2, $f1
    /* 1AA798 002AA798 00008044 */  mtc1       $0, $f0
    /* 1AA79C 002AA79C 00000000 */  nop
    /* 1AA7A0 002AA7A0 18000146 */  adda.s     $f0, $f1
    /* 1AA7A4 002AA7A4 1C131546 */  madd.s     $f12, $f2, $f21
    /* 1AA7A8 002AA7A8 6000A427 */  addiu      $4, $29, 0x60
    /* 1AA7AC 002AA7AC C000A527 */  addiu      $5, $29, 0xC0
    /* 1AA7B0 002AA7B0 02000624 */  addiu      $6, $0, 0x2
    /* 1AA7B4 002AA7B4 1C820F0C */  jal        func_003e0870
    /* 1AA7B8 002AA7B8 00000000 */   nop
    /* 1AA7BC 002AA7BC A000A0C7 */  lwc1       $f0, 0xA0($29)
    /* 1AA7C0 002AA7C0 02001446 */  mul.s      $f0, $f0, $f20
    /* 1AA7C4 002AA7C4 A000A0E7 */  swc1       $f0, 0xA0($29)
    /* 1AA7C8 002AA7C8 A400A0C7 */  lwc1       $f0, 0xA4($29)
    /* 1AA7CC 002AA7CC 02001446 */  mul.s      $f0, $f0, $f20
    /* 1AA7D0 002AA7D0 A400A0E7 */  swc1       $f0, 0xA4($29)
    /* 1AA7D4 002AA7D4 A800A0C7 */  lwc1       $f0, 0xA8($29)
    /* 1AA7D8 002AA7D8 02001446 */  mul.s      $f0, $f0, $f20
    /* 1AA7DC 002AA7DC A800A0E7 */  swc1       $f0, 0xA8($29)
    /* 1AA7E0 002AA7E0 6000A427 */  addiu      $4, $29, 0x60
    /* 1AA7E4 002AA7E4 A000A527 */  addiu      $5, $29, 0xA0
    /* 1AA7E8 002AA7E8 02000624 */  addiu      $6, $0, 0x2
    /* 1AA7EC 002AA7EC A4820F0C */  jal        func_003e0a90
    /* 1AA7F0 002AA7F0 00000000 */   nop
    /* 1AA7F4 002AA7F4 0040023C */  lui        $2, (0x40000000 >> 16)
    /* 1AA7F8 002AA7F8 00088244 */  mtc1       $2, $f1
    /* 1AA7FC 002AA7FC 8D010224 */  addiu      $2, $0, 0x18D
    /* 1AA800 002AA800 00008244 */  mtc1       $2, $f0
    /* 1AA804 002AA804 00000000 */  nop
    /* 1AA808 002AA808 20008046 */  cvt.s.w    $f0, $f0
    /* 1AA80C 002AA80C 00608044 */  mtc1       $0, $f12
    /* 1AA810 002AA810 00000000 */  nop
    /* 1AA814 002AA814 18600046 */  adda.s     $f12, $f0
    /* 1AA818 002AA818 1D081446 */  msub.s     $f0, $f1, $f20
    /* 1AA81C 002AA81C 24000046 */  .word      0x46000024                    # cvt.w.s    $f0, $f0 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    /* 1AA820 002AA820 00000544 */  mfc1       $5, $f0
    /* 1AA824 002AA824 16000224 */  addiu      $2, $0, 0x16
    /* 1AA828 002AA828 0000A2FF */  sd         $2, 0x0($29)
    /* 1AA82C 002AA82C 6000A227 */  addiu      $2, $29, 0x60
    /* 1AA830 002AA830 0800A2FF */  sd         $2, 0x8($29)
    /* 1AA834 002AA834 1000A0FF */  sd         $0, 0x10($29)
    /* 1AA838 002AA838 2D200002 */  daddu      $4, $16, $0
    /* 1AA83C 002AA83C 22000624 */  addiu      $6, $0, 0x22
    /* 1AA840 002AA840 2C000724 */  addiu      $7, $0, 0x2C
    /* 1AA844 002AA844 E600023C */  lui        $2, (0xE6E6E6 >> 16)
    /* 1AA848 002AA848 E6E64834 */  ori        $8, $2, (0xE6E6E6 & 0xFFFF)
    /* 1AA84C 002AA84C FF000924 */  addiu      $9, $0, 0xFF
    /* 1AA850 002AA850 01000A24 */  addiu      $10, $0, 0x1
    /* 1AA854 002AA854 11000B24 */  addiu      $11, $0, 0x11
    /* 1AA858 002AA858 589A0D0C */  jal        func_00366960
    /* 1AA85C 002AA85C 00000000 */   nop
    /* 1AA860 002AA860 5000BFDF */  ld         $31, 0x50($29)
    /* 1AA864 002AA864 4000B17B */  lq         $17, 0x40($29)
    /* 1AA868 002AA868 3000B07B */  lq         $16, 0x30($29)
    /* 1AA86C 002AA86C 2C00B7C7 */  lwc1       $f23, 0x2C($29)
    /* 1AA870 002AA870 2800B6C7 */  lwc1       $f22, 0x28($29)
    /* 1AA874 002AA874 2400B5C7 */  lwc1       $f21, 0x24($29)
    /* 1AA878 002AA878 2000B4C7 */  lwc1       $f20, 0x20($29)
    /* 1AA87C 002AA87C F000BD27 */  addiu      $29, $29, 0xF0
    /* 1AA880 002AA880 0800E003 */  jr         $31
    /* 1AA884 002AA884 00000000 */   nop
    /* 1AA888 002AA888 00000000 */  nop
    /* 1AA88C 002AA88C 00000000 */  nop
.size func_002aa450, 0x440
