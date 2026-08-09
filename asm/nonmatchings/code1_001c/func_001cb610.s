.section .text
.set noat
.set noreorder
glabel func_001cb610
    /* CB610 001CB610 20FFBD27 */  addiu      $29, $29, -0xE0
    /* CB614 001CB614 2000BFFF */  sd         $31, 0x20($29)
    /* CB618 001CB618 1000B17F */  sq         $17, 0x10($29)
    /* CB61C 001CB61C 0000B07F */  sq         $16, 0x0($29)
    /* CB620 001CB620 2D808000 */  daddu      $16, $4, $0
    /* CB624 001CB624 E000828C */  lw         $2, 0xE0($4)
    /* CB628 001CB628 3800428C */  lw         $2, 0x38($2)
    /* CB62C 001CB62C 3000518C */  lw         $17, 0x30($2)
    /* CB630 001CB630 2D202002 */  daddu      $4, $17, $0
    /* CB634 001CB634 B000A527 */  addiu      $5, $29, 0xB0
    /* CB638 001CB638 7456060C */  jal        func_001959d0
    /* CB63C 001CB63C 00000000 */   nop
    /* CB640 001CB640 8C0021C6 */  lwc1       $f1, 0x8C($17)
    /* CB644 001CB644 2C0020C6 */  lwc1       $f0, 0x2C($17)
    /* CB648 001CB648 C2080046 */  mul.s      $f3, $f1, $f0
    /* CB64C 001CB64C 888182C7 */  lwc1       $f2, -0x7E78($28)
    /* CB650 001CB650 B400A1C7 */  lwc1       $f1, 0xB4($29)
    /* CB654 001CB654 00008044 */  mtc1       $0, $f0
    /* CB658 001CB658 00000000 */  nop
    /* CB65C 001CB65C 18000146 */  adda.s     $f0, $f1
    /* CB660 001CB660 5C100346 */  madd.s     $f1, $f2, $f3
    /* CB664 001CB664 B400A1E7 */  swc1       $f1, 0xB4($29)
    /* CB668 001CB668 2041023C */  lui        $2, (0x41200000 >> 16)
    /* CB66C 001CB66C 00008244 */  mtc1       $2, $f0
    /* CB670 001CB670 00000000 */  nop
    /* CB674 001CB674 00080046 */  add.s      $f0, $f1, $f0
    /* CB678 001CB678 B400A0E7 */  swc1       $f0, 0xB4($29)
    /* CB67C 001CB67C C000A427 */  addiu      $4, $29, 0xC0
    /* CB680 001CB680 6100053C */  lui        $5, %hi(D_0060A100)
    /* CB684 001CB684 00A1A524 */  addiu      $5, $5, %lo(D_0060A100)
    /* CB688 001CB688 01000624 */  addiu      $6, $0, 0x1
    /* CB68C 001CB68C 1C002726 */  addiu      $7, $17, 0x1C
    /* CB690 001CB690 D0720F0C */  jal        func_003dcb40
    /* CB694 001CB694 00000000 */   nop
    /* CB698 001CB698 4843023C */  lui        $2, (0x43480000 >> 16)
    /* CB69C 001CB69C 00108244 */  mtc1       $2, $f2
    /* CB6A0 001CB6A0 C000A0C7 */  lwc1       $f0, 0xC0($29)
    /* CB6A4 001CB6A4 42110046 */  mul.s      $f5, $f2, $f0
    /* CB6A8 001CB6A8 D000A5E7 */  swc1       $f5, 0xD0($29)
    /* CB6AC 001CB6AC C400A0C7 */  lwc1       $f0, 0xC4($29)
    /* CB6B0 001CB6B0 42100046 */  mul.s      $f1, $f2, $f0
    /* CB6B4 001CB6B4 D400A1E7 */  swc1       $f1, 0xD4($29)
    /* CB6B8 001CB6B8 C800A0C7 */  lwc1       $f0, 0xC8($29)
    /* CB6BC 001CB6BC 02110046 */  mul.s      $f4, $f2, $f0
    /* CB6C0 001CB6C0 D800A4E7 */  swc1       $f4, 0xD8($29)
    /* CB6C4 001CB6C4 B400A3C7 */  lwc1       $f3, 0xB4($29)
    /* CB6C8 001CB6C8 40180146 */  add.s      $f1, $f3, $f1
    /* CB6CC 001CB6CC 2041023C */  lui        $2, (0x41200000 >> 16)
    /* CB6D0 001CB6D0 00008244 */  mtc1       $2, $f0
    /* CB6D4 001CB6D4 00000000 */  nop
    /* CB6D8 001CB6D8 80080046 */  add.s      $f2, $f1, $f0
    /* CB6DC 001CB6DC B000A1C7 */  lwc1       $f1, 0xB0($29)
    /* CB6E0 001CB6E0 00080546 */  add.s      $f0, $f1, $f5
    /* CB6E4 001CB6E4 01000146 */  sub.s      $f0, $f0, $f1
    /* CB6E8 001CB6E8 C000A0E7 */  swc1       $f0, 0xC0($29)
    /* CB6EC 001CB6EC 01100346 */  sub.s      $f0, $f2, $f3
    /* CB6F0 001CB6F0 C400A0E7 */  swc1       $f0, 0xC4($29)
    /* CB6F4 001CB6F4 B800A1C7 */  lwc1       $f1, 0xB8($29)
    /* CB6F8 001CB6F8 00080446 */  add.s      $f0, $f1, $f4
    /* CB6FC 001CB6FC 01000146 */  sub.s      $f0, $f0, $f1
    /* CB700 001CB700 C800A0E7 */  swc1       $f0, 0xC8($29)
    /* CB704 001CB704 C000A427 */  addiu      $4, $29, 0xC0
    /* CB708 001CB708 2D288000 */  daddu      $5, $4, $0
    /* CB70C 001CB70C 2C900F0C */  jal        func_003e40b0
    /* CB710 001CB710 00000000 */   nop
    /* CB714 001CB714 003F023C */  lui        $2, (0x3F000000 >> 16)
    /* CB718 001CB718 00088244 */  mtc1       $2, $f1
    /* CB71C 001CB71C F041023C */  lui        $2, (0x41F00000 >> 16)
    /* CB720 001CB720 00008244 */  mtc1       $2, $f0
    /* CB724 001CB724 00000000 */  nop
    /* CB728 001CB728 07000046 */  neg.s      $f0, $f0
    /* CB72C 001CB72C 020B0046 */  mul.s      $f12, $f1, $f0
    /* CB730 001CB730 7000A427 */  addiu      $4, $29, 0x70
    /* CB734 001CB734 6100053C */  lui        $5, %hi(D_0060A0E0)
    /* CB738 001CB738 E0A0A524 */  addiu      $5, $5, %lo(D_0060A0E0)
    /* CB73C 001CB73C 2D300000 */  daddu      $6, $0, $0
    /* CB740 001CB740 1C820F0C */  jal        func_003e0870
    /* CB744 001CB744 00000000 */   nop
    /* CB748 001CB748 D000A427 */  addiu      $4, $29, 0xD0
    /* CB74C 001CB74C C000A527 */  addiu      $5, $29, 0xC0
    /* CB750 001CB750 7000A627 */  addiu      $6, $29, 0x70
    /* CB754 001CB754 C8900F0C */  jal        func_003e4320
    /* CB758 001CB758 00000000 */   nop
    /* CB75C 001CB75C 003F023C */  lui        $2, (0x3F000000 >> 16)
    /* CB760 001CB760 00088244 */  mtc1       $2, $f1
    /* CB764 001CB764 B80000C6 */  lwc1       $f0, 0xB8($16)
    /* CB768 001CB768 42080046 */  mul.s      $f1, $f1, $f0
    /* CB76C 001CB76C 108180C7 */  lwc1       $f0, -0x7EF0($28)
    /* CB770 001CB770 02030146 */  mul.s      $f12, $f0, $f1
    /* CB774 001CB774 1A2E110C */  jal        func_0044b868
    /* CB778 001CB778 00000000 */   nop
    /* CB77C 001CB77C E642023C */  lui        $2, (0x42E60000 >> 16)
    /* CB780 001CB780 00088244 */  mtc1       $2, $f1
    /* CB784 001CB784 00000000 */  nop
    /* CB788 001CB788 43080046 */  div.s      $f1, $f1, $f0
    /* CB78C 001CB78C D000A0C7 */  lwc1       $f0, 0xD0($29)
    /* CB790 001CB790 C2000146 */  mul.s      $f3, $f0, $f1
    /* CB794 001CB794 D000A3E7 */  swc1       $f3, 0xD0($29)
    /* CB798 001CB798 D400A0C7 */  lwc1       $f0, 0xD4($29)
    /* CB79C 001CB79C 82000146 */  mul.s      $f2, $f0, $f1
    /* CB7A0 001CB7A0 D400A2E7 */  swc1       $f2, 0xD4($29)
    /* CB7A4 001CB7A4 D800A0C7 */  lwc1       $f0, 0xD8($29)
    /* CB7A8 001CB7A8 42000146 */  mul.s      $f1, $f0, $f1
    /* CB7AC 001CB7AC D800A1E7 */  swc1       $f1, 0xD8($29)
    /* CB7B0 001CB7B0 B000A0C7 */  lwc1       $f0, 0xB0($29)
    /* CB7B4 001CB7B4 00000346 */  add.s      $f0, $f0, $f3
    /* CB7B8 001CB7B8 3000A0E7 */  swc1       $f0, 0x30($29)
    /* CB7BC 001CB7BC B400A0C7 */  lwc1       $f0, 0xB4($29)
    /* CB7C0 001CB7C0 00000246 */  add.s      $f0, $f0, $f2
    /* CB7C4 001CB7C4 3400A0E7 */  swc1       $f0, 0x34($29)
    /* CB7C8 001CB7C8 B800A0C7 */  lwc1       $f0, 0xB8($29)
    /* CB7CC 001CB7CC 00000146 */  add.s      $f0, $f0, $f1
    /* CB7D0 001CB7D0 3800A0E7 */  swc1       $f0, 0x38($29)
    /* CB7D4 001CB7D4 3C00A427 */  addiu      $4, $29, 0x3C
    /* CB7D8 001CB7D8 3000A527 */  addiu      $5, $29, 0x30
    /* CB7DC 001CB7DC B000A627 */  addiu      $6, $29, 0xB0
    /* CB7E0 001CB7E0 6100073C */  lui        $7, %hi(D_0060A0E0)
    /* CB7E4 001CB7E4 E0A0E724 */  addiu      $7, $7, %lo(D_0060A0E0)
    /* CB7E8 001CB7E8 E0F5060C */  jal        func_001bd780
    /* CB7EC 001CB7EC 00000000 */   nop
    /* CB7F0 001CB7F0 7041023C */  lui        $2, (0x41700000 >> 16)
    /* CB7F4 001CB7F4 00608244 */  mtc1       $2, $f12
    /* CB7F8 001CB7F8 7000A427 */  addiu      $4, $29, 0x70
    /* CB7FC 001CB7FC 6100053C */  lui        $5, %hi(D_0060A0E0)
    /* CB800 001CB800 E0A0A524 */  addiu      $5, $5, %lo(D_0060A0E0)
    /* CB804 001CB804 2D300000 */  daddu      $6, $0, $0
    /* CB808 001CB808 1C820F0C */  jal        func_003e0870
    /* CB80C 001CB80C 00000000 */   nop
    /* CB810 001CB810 D000A427 */  addiu      $4, $29, 0xD0
    /* CB814 001CB814 C000A527 */  addiu      $5, $29, 0xC0
    /* CB818 001CB818 7000A627 */  addiu      $6, $29, 0x70
    /* CB81C 001CB81C C8900F0C */  jal        func_003e4320
    /* CB820 001CB820 00000000 */   nop
    /* CB824 001CB824 003F023C */  lui        $2, (0x3F000000 >> 16)
    /* CB828 001CB828 00088244 */  mtc1       $2, $f1
    /* CB82C 001CB82C B80000C6 */  lwc1       $f0, 0xB8($16)
    /* CB830 001CB830 42080046 */  mul.s      $f1, $f1, $f0
    /* CB834 001CB834 108180C7 */  lwc1       $f0, -0x7EF0($28)
    /* CB838 001CB838 02030146 */  mul.s      $f12, $f0, $f1
    /* CB83C 001CB83C 1A2E110C */  jal        func_0044b868
    /* CB840 001CB840 00000000 */   nop
    /* CB844 001CB844 2543023C */  lui        $2, (0x43250000 >> 16)
    /* CB848 001CB848 00088244 */  mtc1       $2, $f1
    /* CB84C 001CB84C 00000000 */  nop
    /* CB850 001CB850 43080046 */  div.s      $f1, $f1, $f0
    /* CB854 001CB854 D000A0C7 */  lwc1       $f0, 0xD0($29)
    /* CB858 001CB858 C2000146 */  mul.s      $f3, $f0, $f1
    /* CB85C 001CB85C D000A3E7 */  swc1       $f3, 0xD0($29)
    /* CB860 001CB860 D400A0C7 */  lwc1       $f0, 0xD4($29)
    /* CB864 001CB864 82000146 */  mul.s      $f2, $f0, $f1
    /* CB868 001CB868 D400A2E7 */  swc1       $f2, 0xD4($29)
    /* CB86C 001CB86C D800A0C7 */  lwc1       $f0, 0xD8($29)
    /* CB870 001CB870 42000146 */  mul.s      $f1, $f0, $f1
    /* CB874 001CB874 D800A1E7 */  swc1       $f1, 0xD8($29)
    /* CB878 001CB878 B000A0C7 */  lwc1       $f0, 0xB0($29)
    /* CB87C 001CB87C 00000346 */  add.s      $f0, $f0, $f3
    /* CB880 001CB880 4C00A0E7 */  swc1       $f0, 0x4C($29)
    /* CB884 001CB884 B400A0C7 */  lwc1       $f0, 0xB4($29)
    /* CB888 001CB888 00000246 */  add.s      $f0, $f0, $f2
    /* CB88C 001CB88C 5000A0E7 */  swc1       $f0, 0x50($29)
    /* CB890 001CB890 B800A0C7 */  lwc1       $f0, 0xB8($29)
    /* CB894 001CB894 00000146 */  add.s      $f0, $f0, $f1
    /* CB898 001CB898 5400A0E7 */  swc1       $f0, 0x54($29)
    /* CB89C 001CB89C 5800A427 */  addiu      $4, $29, 0x58
    /* CB8A0 001CB8A0 4C00A527 */  addiu      $5, $29, 0x4C
    /* CB8A4 001CB8A4 B000A627 */  addiu      $6, $29, 0xB0
    /* CB8A8 001CB8A8 6100073C */  lui        $7, %hi(D_0060A0E0)
    /* CB8AC 001CB8AC E0A0E724 */  addiu      $7, $7, %lo(D_0060A0E0)
    /* CB8B0 001CB8B0 E0F5060C */  jal        func_001bd780
    /* CB8B4 001CB8B4 00000000 */   nop
    /* CB8B8 001CB8B8 3400A1C7 */  lwc1       $f1, 0x34($29)
    /* CB8BC 001CB8BC C841023C */  lui        $2, (0x41C80000 >> 16)
    /* CB8C0 001CB8C0 00008244 */  mtc1       $2, $f0
    /* CB8C4 001CB8C4 00000000 */  nop
    /* CB8C8 001CB8C8 34080046 */  c.lt.s     $f1, $f0
    /* CB8CC 001CB8CC 02000045 */  bc1f       .L001CB8D8
    /* CB8D0 001CB8D0 00000000 */   nop
    /* CB8D4 001CB8D4 3400A0E7 */  swc1       $f0, 0x34($29)
  .L001CB8D8:
    /* CB8D8 001CB8D8 5000A1C7 */  lwc1       $f1, 0x50($29)
    /* CB8DC 001CB8DC C841023C */  lui        $2, (0x41C80000 >> 16)
    /* CB8E0 001CB8E0 00008244 */  mtc1       $2, $f0
    /* CB8E4 001CB8E4 00000000 */  nop
    /* CB8E8 001CB8E8 34080046 */  c.lt.s     $f1, $f0
    /* CB8EC 001CB8EC 02000045 */  bc1f       .L001CB8F8
    /* CB8F0 001CB8F0 00000000 */   nop
    /* CB8F4 001CB8F4 5000A0E7 */  swc1       $f0, 0x50($29)
  .L001CB8F8:
    /* CB8F8 001CB8F8 00608044 */  mtc1       $0, $f12
    /* CB8FC 001CB8FC E000048E */  lw         $4, 0xE0($16)
    /* CB900 001CB900 2D280000 */  daddu      $5, $0, $0
    /* CB904 001CB904 2D300000 */  daddu      $6, $0, $0
    /* CB908 001CB908 03000724 */  addiu      $7, $0, 0x3
    /* CB90C 001CB90C 50F3060C */  jal        func_001bcd40
    /* CB910 001CB910 00000000 */   nop
    /* CB914 001CB914 2D200002 */  daddu      $4, $16, $0
    /* CB918 001CB918 3000A527 */  addiu      $5, $29, 0x30
    /* CB91C 001CB91C 4C00A627 */  addiu      $6, $29, 0x4C
    /* CB920 001CB920 01000724 */  addiu      $7, $0, 0x1
    /* CB924 001CB924 08EB060C */  jal        func_001bac20
    /* CB928 001CB928 00000000 */   nop
    /* CB92C 001CB92C 0040023C */  lui        $2, (0x40000000 >> 16)
    /* CB930 001CB930 00608244 */  mtc1       $2, $f12
    /* CB934 001CB934 2D200002 */  daddu      $4, $16, $0
    /* CB938 001CB938 BCEF060C */  jal        func_001bbef0
    /* CB93C 001CB93C 00000000 */   nop
    /* CB940 001CB940 2000BFDF */  ld         $31, 0x20($29)
    /* CB944 001CB944 1000B17B */  lq         $17, 0x10($29)
    /* CB948 001CB948 0000B07B */  lq         $16, 0x0($29)
    /* CB94C 001CB94C E000BD27 */  addiu      $29, $29, 0xE0
    /* CB950 001CB950 0800E003 */  jr         $31
    /* CB954 001CB954 00000000 */   nop
    /* CB958 001CB958 00000000 */  nop
    /* CB95C 001CB95C 00000000 */  nop
.size func_001cb610, 0x350
