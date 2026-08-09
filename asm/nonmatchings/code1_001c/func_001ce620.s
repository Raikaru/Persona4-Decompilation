.section .text
.set noat
.set noreorder
glabel func_001ce620
    /* CE620 001CE620 60FFBD27 */  addiu      $29, $29, -0xA0
    /* CE624 001CE624 2000BFFF */  sd         $31, 0x20($29)
    /* CE628 001CE628 1000B07F */  sq         $16, 0x10($29)
    /* CE62C 001CE62C 0800B6E7 */  swc1       $f22, 0x8($29)
    /* CE630 001CE630 0400B5E7 */  swc1       $f21, 0x4($29)
    /* CE634 001CE634 0000B4E7 */  swc1       $f20, 0x0($29)
    /* CE638 001CE638 2D808000 */  daddu      $16, $4, $0
    /* CE63C 001CE63C 86650046 */  mov.s      $f22, $f12
    /* CE640 001CE640 066D0046 */  mov.s      $f20, $f13
    /* CE644 001CE644 46750046 */  mov.s      $f21, $f14
    /* CE648 001CE648 2001828C */  lw         $2, 0x120($4)
    /* CE64C 001CE64C 0C004010 */  beqz       $2, .L001CE680
    /* CE650 001CE650 00000000 */   nop
    /* CE654 001CE654 03000424 */  addiu      $4, $0, 0x3
    /* CE658 001CE658 2D280000 */  daddu      $5, $0, $0
    /* CE65C 001CE65C 04010626 */  addiu      $6, $16, 0x104
    /* CE660 001CE660 2D380000 */  daddu      $7, $0, $0
    /* CE664 001CE664 2D400000 */  daddu      $8, $0, $0
    /* CE668 001CE668 01000924 */  addiu      $9, $0, 0x1
    /* CE66C 001CE66C 1058060C */  jal        func_00196040
    /* CE670 001CE670 00000000 */   nop
    /* CE674 001CE674 1C0100E6 */  swc1       $f0, 0x11C($16)
    /* CE678 001CE678 080100AE */  sw         $0, 0x108($16)
    /* CE67C 001CE67C 200100AE */  sw         $0, 0x120($16)
  .L001CE680:
    /* CE680 001CE680 3000A427 */  addiu      $4, $29, 0x30
    /* CE684 001CE684 6100053C */  lui        $5, %hi(D_0060A0D0)
    /* CE688 001CE688 D0A0A524 */  addiu      $5, $5, %lo(D_0060A0D0)
    /* CE68C 001CE68C 06B30046 */  mov.s      $f12, $f22
    /* CE690 001CE690 2D300000 */  daddu      $6, $0, $0
    /* CE694 001CE694 1C820F0C */  jal        func_003e0870
    /* CE698 001CE698 00000000 */   nop
    /* CE69C 001CE69C 3000A427 */  addiu      $4, $29, 0x30
    /* CE6A0 001CE6A0 6100053C */  lui        $5, %hi(D_0060A0E0)
    /* CE6A4 001CE6A4 E0A0A524 */  addiu      $5, $5, %lo(D_0060A0E0)
    /* CE6A8 001CE6A8 00010CC6 */  lwc1       $f12, 0x100($16)
    /* CE6AC 001CE6AC 02000624 */  addiu      $6, $0, 0x2
    /* CE6B0 001CE6B0 1C820F0C */  jal        func_003e0870
    /* CE6B4 001CE6B4 00000000 */   nop
    /* CE6B8 001CE6B8 9000A427 */  addiu      $4, $29, 0x90
    /* CE6BC 001CE6BC 6100053C */  lui        $5, %hi(D_0060A0F0)
    /* CE6C0 001CE6C0 F0A0A524 */  addiu      $5, $5, %lo(D_0060A0F0)
    /* CE6C4 001CE6C4 3000A627 */  addiu      $6, $29, 0x30
    /* CE6C8 001CE6C8 C8900F0C */  jal        func_003e4320
    /* CE6CC 001CE6CC 00000000 */   nop
    /* CE6D0 001CE6D0 003F023C */  lui        $2, (0x3F000000 >> 16)
    /* CE6D4 001CE6D4 00088244 */  mtc1       $2, $f1
    /* CE6D8 001CE6D8 B80000C6 */  lwc1       $f0, 0xB8($16)
    /* CE6DC 001CE6DC 42080046 */  mul.s      $f1, $f1, $f0
    /* CE6E0 001CE6E0 108180C7 */  lwc1       $f0, -0x7EF0($28)
    /* CE6E4 001CE6E4 02030146 */  mul.s      $f12, $f0, $f1
    /* CE6E8 001CE6E8 1A2E110C */  jal        func_0044b868
    /* CE6EC 001CE6EC 00000000 */   nop
    /* CE6F0 001CE6F0 1C0101C6 */  lwc1       $f1, 0x11C($16)
    /* CE6F4 001CE6F4 42081546 */  mul.s      $f1, $f1, $f21
    /* CE6F8 001CE6F8 43080046 */  div.s      $f1, $f1, $f0
    /* CE6FC 001CE6FC 9000A0C7 */  lwc1       $f0, 0x90($29)
    /* CE700 001CE700 C2000146 */  mul.s      $f3, $f0, $f1
    /* CE704 001CE704 9000A3E7 */  swc1       $f3, 0x90($29)
    /* CE708 001CE708 9400A0C7 */  lwc1       $f0, 0x94($29)
    /* CE70C 001CE70C 82000146 */  mul.s      $f2, $f0, $f1
    /* CE710 001CE710 9400A2E7 */  swc1       $f2, 0x94($29)
    /* CE714 001CE714 9800A0C7 */  lwc1       $f0, 0x98($29)
    /* CE718 001CE718 42000146 */  mul.s      $f1, $f0, $f1
    /* CE71C 001CE71C 9800A1E7 */  swc1       $f1, 0x98($29)
    /* CE720 001CE720 040100C6 */  lwc1       $f0, 0x104($16)
    /* CE724 001CE724 00180046 */  add.s      $f0, $f3, $f0
    /* CE728 001CE728 7000A0E7 */  swc1       $f0, 0x70($29)
    /* CE72C 001CE72C 080100C6 */  lwc1       $f0, 0x108($16)
    /* CE730 001CE730 00100046 */  add.s      $f0, $f2, $f0
    /* CE734 001CE734 7400A0E7 */  swc1       $f0, 0x74($29)
    /* CE738 001CE738 0C0100C6 */  lwc1       $f0, 0x10C($16)
    /* CE73C 001CE73C 00080046 */  add.s      $f0, $f1, $f0
    /* CE740 001CE740 7800A0E7 */  swc1       $f0, 0x78($29)
    /* CE744 001CE744 7C00A427 */  addiu      $4, $29, 0x7C
    /* CE748 001CE748 7000A527 */  addiu      $5, $29, 0x70
    /* CE74C 001CE74C 04010626 */  addiu      $6, $16, 0x104
    /* CE750 001CE750 6100073C */  lui        $7, %hi(D_0060A0E0)
    /* CE754 001CE754 E0A0E724 */  addiu      $7, $7, %lo(D_0060A0E0)
    /* CE758 001CE758 E0F5060C */  jal        func_001bd780
    /* CE75C 001CE75C 00000000 */   nop
    /* CE760 001CE760 7400A1C7 */  lwc1       $f1, 0x74($29)
    /* CE764 001CE764 C841023C */  lui        $2, (0x41C80000 >> 16)
    /* CE768 001CE768 00008244 */  mtc1       $2, $f0
    /* CE76C 001CE76C 00000000 */  nop
    /* CE770 001CE770 34080046 */  c.lt.s     $f1, $f0
    /* CE774 001CE774 02000045 */  bc1f       .L001CE780
    /* CE778 001CE778 00000000 */   nop
    /* CE77C 001CE77C 7400A0E7 */  swc1       $f0, 0x74($29)
  .L001CE780:
    /* CE780 001CE780 000100C6 */  lwc1       $f0, 0x100($16)
    /* CE784 001CE784 00001446 */  add.s      $f0, $f0, $f20
    /* CE788 001CE788 000100E6 */  swc1       $f0, 0x100($16)
    /* CE78C 001CE78C ACB3828F */  lw         $2, -0x4C54($28)
    /* CE790 001CE790 0C00438C */  lw         $3, 0xC($2)
    /* CE794 001CE794 2000023C */  lui        $2, (0x200000 >> 16)
    /* CE798 001CE798 24106200 */  and        $2, $3, $2
    /* CE79C 001CE79C 05004014 */  bnez       $2, .L001CE7B4
    /* CE7A0 001CE7A0 00000000 */   nop
    /* CE7A4 001CE7A4 7000A427 */  addiu      $4, $29, 0x70
    /* CE7A8 001CE7A8 2D288000 */  daddu      $5, $4, $0
    /* CE7AC 001CE7AC E8F0060C */  jal        func_001bc3a0
    /* CE7B0 001CE7B0 00000000 */   nop
  .L001CE7B4:
    /* CE7B4 001CE7B4 2D200002 */  daddu      $4, $16, $0
    /* CE7B8 001CE7B8 7000A527 */  addiu      $5, $29, 0x70
    /* CE7BC 001CE7BC C0EA060C */  jal        func_001bab00
    /* CE7C0 001CE7C0 00000000 */   nop
    /* CE7C4 001CE7C4 2000BFDF */  ld         $31, 0x20($29)
    /* CE7C8 001CE7C8 1000B07B */  lq         $16, 0x10($29)
    /* CE7CC 001CE7CC 0800B6C7 */  lwc1       $f22, 0x8($29)
    /* CE7D0 001CE7D0 0400B5C7 */  lwc1       $f21, 0x4($29)
    /* CE7D4 001CE7D4 0000B4C7 */  lwc1       $f20, 0x0($29)
    /* CE7D8 001CE7D8 A000BD27 */  addiu      $29, $29, 0xA0
    /* CE7DC 001CE7DC 0800E003 */  jr         $31
    /* CE7E0 001CE7E0 00000000 */   nop
    /* CE7E4 001CE7E4 00000000 */  nop
    /* CE7E8 001CE7E8 00000000 */  nop
    /* CE7EC 001CE7EC 00000000 */  nop
.size func_001ce620, 0x1d0
