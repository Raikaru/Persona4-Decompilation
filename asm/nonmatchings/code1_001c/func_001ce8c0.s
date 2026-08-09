.section .text
.set noat
.set noreorder
glabel func_001ce8c0
    /* CE8C0 001CE8C0 50FFBD27 */  addiu      $29, $29, -0xB0
    /* CE8C4 001CE8C4 2000BFFF */  sd         $31, 0x20($29)
    /* CE8C8 001CE8C8 1000B07F */  sq         $16, 0x10($29)
    /* CE8CC 001CE8CC 0800B6E7 */  swc1       $f22, 0x8($29)
    /* CE8D0 001CE8D0 0400B5E7 */  swc1       $f21, 0x4($29)
    /* CE8D4 001CE8D4 0000B4E7 */  swc1       $f20, 0x0($29)
    /* CE8D8 001CE8D8 2D808000 */  daddu      $16, $4, $0
    /* CE8DC 001CE8DC 86650046 */  mov.s      $f22, $f12
    /* CE8E0 001CE8E0 466D0046 */  mov.s      $f21, $f13
    /* CE8E4 001CE8E4 06750046 */  mov.s      $f20, $f14
    /* CE8E8 001CE8E8 2001828C */  lw         $2, 0x120($4)
    /* CE8EC 001CE8EC 4C004010 */  beqz       $2, .L001CEA20
    /* CE8F0 001CE8F0 00000000 */   nop
    /* CE8F4 001CE8F4 02000424 */  addiu      $4, $0, 0x2
    /* CE8F8 001CE8F8 01000524 */  addiu      $5, $0, 0x1
    /* CE8FC 001CE8FC A000A627 */  addiu      $6, $29, 0xA0
    /* CE900 001CE900 2D380000 */  daddu      $7, $0, $0
    /* CE904 001CE904 2D400000 */  daddu      $8, $0, $0
    /* CE908 001CE908 2D48A000 */  daddu      $9, $5, $0
    /* CE90C 001CE90C 1058060C */  jal        func_00196040
    /* CE910 001CE910 00000000 */   nop
    /* CE914 001CE914 03000424 */  addiu      $4, $0, 0x3
    /* CE918 001CE918 2D280000 */  daddu      $5, $0, $0
    /* CE91C 001CE91C 04010626 */  addiu      $6, $16, 0x104
    /* CE920 001CE920 2D380000 */  daddu      $7, $0, $0
    /* CE924 001CE924 2D400000 */  daddu      $8, $0, $0
    /* CE928 001CE928 02000924 */  addiu      $9, $0, 0x2
    /* CE92C 001CE92C 1058060C */  jal        func_00196040
    /* CE930 001CE930 00000000 */   nop
    /* CE934 001CE934 1C0100E6 */  swc1       $f0, 0x11C($16)
    /* CE938 001CE938 080100AE */  sw         $0, 0x108($16)
    /* CE93C 001CE93C 040101C6 */  lwc1       $f1, 0x104($16)
    /* CE940 001CE940 A000A0C7 */  lwc1       $f0, 0xA0($29)
    /* CE944 001CE944 01080046 */  sub.s      $f0, $f1, $f0
    /* CE948 001CE948 9000A0E7 */  swc1       $f0, 0x90($29)
    /* CE94C 001CE94C 080101C6 */  lwc1       $f1, 0x108($16)
    /* CE950 001CE950 A400A0C7 */  lwc1       $f0, 0xA4($29)
    /* CE954 001CE954 01080046 */  sub.s      $f0, $f1, $f0
    /* CE958 001CE958 9400A0E7 */  swc1       $f0, 0x94($29)
    /* CE95C 001CE95C 0C0101C6 */  lwc1       $f1, 0x10C($16)
    /* CE960 001CE960 A800A0C7 */  lwc1       $f0, 0xA8($29)
    /* CE964 001CE964 01080046 */  sub.s      $f0, $f1, $f0
    /* CE968 001CE968 9800A0E7 */  swc1       $f0, 0x98($29)
    /* CE96C 001CE96C 9000A427 */  addiu      $4, $29, 0x90
    /* CE970 001CE970 2D288000 */  daddu      $5, $4, $0
    /* CE974 001CE974 2C900F0C */  jal        func_003e40b0
    /* CE978 001CE978 00000000 */   nop
    /* CE97C 001CE97C 008181C7 */  lwc1       $f1, -0x7F00($28)
    /* CE980 001CE980 82080046 */  mul.s      $f2, $f1, $f0
    /* CE984 001CE984 9000A0C7 */  lwc1       $f0, 0x90($29)
    /* CE988 001CE988 42000246 */  mul.s      $f1, $f0, $f2
    /* CE98C 001CE98C 9000A1E7 */  swc1       $f1, 0x90($29)
    /* CE990 001CE990 9400A0C7 */  lwc1       $f0, 0x94($29)
    /* CE994 001CE994 02000246 */  mul.s      $f0, $f0, $f2
    /* CE998 001CE998 9400A0E7 */  swc1       $f0, 0x94($29)
    /* CE99C 001CE99C 9800A0C7 */  lwc1       $f0, 0x98($29)
    /* CE9A0 001CE9A0 02000246 */  mul.s      $f0, $f0, $f2
    /* CE9A4 001CE9A4 9800A0E7 */  swc1       $f0, 0x98($29)
    /* CE9A8 001CE9A8 A000A0C7 */  lwc1       $f0, 0xA0($29)
    /* CE9AC 001CE9AC 00000146 */  add.s      $f0, $f0, $f1
    /* CE9B0 001CE9B0 040100E6 */  swc1       $f0, 0x104($16)
    /* CE9B4 001CE9B4 A400A1C7 */  lwc1       $f1, 0xA4($29)
    /* CE9B8 001CE9B8 9400A0C7 */  lwc1       $f0, 0x94($29)
    /* CE9BC 001CE9BC 00080046 */  add.s      $f0, $f1, $f0
    /* CE9C0 001CE9C0 080100E6 */  swc1       $f0, 0x108($16)
    /* CE9C4 001CE9C4 A800A1C7 */  lwc1       $f1, 0xA8($29)
    /* CE9C8 001CE9C8 9800A0C7 */  lwc1       $f0, 0x98($29)
    /* CE9CC 001CE9CC 00080046 */  add.s      $f0, $f1, $f0
    /* CE9D0 001CE9D0 0C0100E6 */  swc1       $f0, 0x10C($16)
    /* CE9D4 001CE9D4 A400A0C7 */  lwc1       $f0, 0xA4($29)
    /* CE9D8 001CE9D8 080100E6 */  swc1       $f0, 0x108($16)
    /* CE9DC 001CE9DC 040101C6 */  lwc1       $f1, 0x104($16)
    /* CE9E0 001CE9E0 A000A0C7 */  lwc1       $f0, 0xA0($29)
    /* CE9E4 001CE9E4 01080046 */  sub.s      $f0, $f1, $f0
    /* CE9E8 001CE9E8 100100E6 */  swc1       $f0, 0x110($16)
    /* CE9EC 001CE9EC 080101C6 */  lwc1       $f1, 0x108($16)
    /* CE9F0 001CE9F0 A400A0C7 */  lwc1       $f0, 0xA4($29)
    /* CE9F4 001CE9F4 01080046 */  sub.s      $f0, $f1, $f0
    /* CE9F8 001CE9F8 140100E6 */  swc1       $f0, 0x114($16)
    /* CE9FC 001CE9FC 0C0101C6 */  lwc1       $f1, 0x10C($16)
    /* CEA00 001CEA00 A800A0C7 */  lwc1       $f0, 0xA8($29)
    /* CEA04 001CEA04 01080046 */  sub.s      $f0, $f1, $f0
    /* CEA08 001CEA08 180100E6 */  swc1       $f0, 0x118($16)
    /* CEA0C 001CEA0C 10010426 */  addiu      $4, $16, 0x110
    /* CEA10 001CEA10 2D288000 */  daddu      $5, $4, $0
    /* CEA14 001CEA14 2C900F0C */  jal        func_003e40b0
    /* CEA18 001CEA18 00000000 */   nop
    /* CEA1C 001CEA1C 200100AE */  sw         $0, 0x120($16)
  .L001CEA20:
    /* CEA20 001CEA20 3000A427 */  addiu      $4, $29, 0x30
    /* CEA24 001CEA24 6100053C */  lui        $5, %hi(D_0060A0D0)
    /* CEA28 001CEA28 D0A0A524 */  addiu      $5, $5, %lo(D_0060A0D0)
    /* CEA2C 001CEA2C 06B30046 */  mov.s      $f12, $f22
    /* CEA30 001CEA30 2D300000 */  daddu      $6, $0, $0
    /* CEA34 001CEA34 1C820F0C */  jal        func_003e0870
    /* CEA38 001CEA38 00000000 */   nop
    /* CEA3C 001CEA3C 3000A427 */  addiu      $4, $29, 0x30
    /* CEA40 001CEA40 6100053C */  lui        $5, %hi(D_0060A0E0)
    /* CEA44 001CEA44 E0A0A524 */  addiu      $5, $5, %lo(D_0060A0E0)
    /* CEA48 001CEA48 00010CC6 */  lwc1       $f12, 0x100($16)
    /* CEA4C 001CEA4C 02000624 */  addiu      $6, $0, 0x2
    /* CEA50 001CEA50 1C820F0C */  jal        func_003e0870
    /* CEA54 001CEA54 00000000 */   nop
    /* CEA58 001CEA58 9000A427 */  addiu      $4, $29, 0x90
    /* CEA5C 001CEA5C 10010526 */  addiu      $5, $16, 0x110
    /* CEA60 001CEA60 3000A627 */  addiu      $6, $29, 0x30
    /* CEA64 001CEA64 C8900F0C */  jal        func_003e4320
    /* CEA68 001CEA68 00000000 */   nop
    /* CEA6C 001CEA6C 1C0101C6 */  lwc1       $f1, 0x11C($16)
    /* CEA70 001CEA70 1644023C */  lui        $2, (0x44160000 >> 16)
    /* CEA74 001CEA74 00008244 */  mtc1       $2, $f0
    /* CEA78 001CEA78 00000000 */  nop
    /* CEA7C 001CEA7C 34080046 */  c.lt.s     $f1, $f0
    /* CEA80 001CEA80 02000045 */  bc1f       .L001CEA8C
    /* CEA84 001CEA84 00000000 */   nop
    /* CEA88 001CEA88 1C0100E6 */  swc1       $f0, 0x11C($16)
  .L001CEA8C:
    /* CEA8C 001CEA8C 003F023C */  lui        $2, (0x3F000000 >> 16)
    /* CEA90 001CEA90 00088244 */  mtc1       $2, $f1
    /* CEA94 001CEA94 B80000C6 */  lwc1       $f0, 0xB8($16)
    /* CEA98 001CEA98 42080046 */  mul.s      $f1, $f1, $f0
    /* CEA9C 001CEA9C 108180C7 */  lwc1       $f0, -0x7EF0($28)
    /* CEAA0 001CEAA0 02030146 */  mul.s      $f12, $f0, $f1
    /* CEAA4 001CEAA4 1A2E110C */  jal        func_0044b868
    /* CEAA8 001CEAA8 00000000 */   nop
    /* CEAAC 001CEAAC 1C0101C6 */  lwc1       $f1, 0x11C($16)
    /* CEAB0 001CEAB0 42081446 */  mul.s      $f1, $f1, $f20
    /* CEAB4 001CEAB4 43080046 */  div.s      $f1, $f1, $f0
    /* CEAB8 001CEAB8 9000A0C7 */  lwc1       $f0, 0x90($29)
    /* CEABC 001CEABC C2000146 */  mul.s      $f3, $f0, $f1
    /* CEAC0 001CEAC0 9000A3E7 */  swc1       $f3, 0x90($29)
    /* CEAC4 001CEAC4 9400A0C7 */  lwc1       $f0, 0x94($29)
    /* CEAC8 001CEAC8 82000146 */  mul.s      $f2, $f0, $f1
    /* CEACC 001CEACC 9400A2E7 */  swc1       $f2, 0x94($29)
    /* CEAD0 001CEAD0 9800A0C7 */  lwc1       $f0, 0x98($29)
    /* CEAD4 001CEAD4 42000146 */  mul.s      $f1, $f0, $f1
    /* CEAD8 001CEAD8 9800A1E7 */  swc1       $f1, 0x98($29)
    /* CEADC 001CEADC 040100C6 */  lwc1       $f0, 0x104($16)
    /* CEAE0 001CEAE0 00180046 */  add.s      $f0, $f3, $f0
    /* CEAE4 001CEAE4 7000A0E7 */  swc1       $f0, 0x70($29)
    /* CEAE8 001CEAE8 080100C6 */  lwc1       $f0, 0x108($16)
    /* CEAEC 001CEAEC 00100046 */  add.s      $f0, $f2, $f0
    /* CEAF0 001CEAF0 7400A0E7 */  swc1       $f0, 0x74($29)
    /* CEAF4 001CEAF4 0C0100C6 */  lwc1       $f0, 0x10C($16)
    /* CEAF8 001CEAF8 00080046 */  add.s      $f0, $f1, $f0
    /* CEAFC 001CEAFC 7800A0E7 */  swc1       $f0, 0x78($29)
    /* CEB00 001CEB00 7C00A427 */  addiu      $4, $29, 0x7C
    /* CEB04 001CEB04 7000A527 */  addiu      $5, $29, 0x70
    /* CEB08 001CEB08 04010626 */  addiu      $6, $16, 0x104
    /* CEB0C 001CEB0C 6100073C */  lui        $7, %hi(D_0060A0E0)
    /* CEB10 001CEB10 E0A0E724 */  addiu      $7, $7, %lo(D_0060A0E0)
    /* CEB14 001CEB14 E0F5060C */  jal        func_001bd780
    /* CEB18 001CEB18 00000000 */   nop
    /* CEB1C 001CEB1C 7400A1C7 */  lwc1       $f1, 0x74($29)
    /* CEB20 001CEB20 C841023C */  lui        $2, (0x41C80000 >> 16)
    /* CEB24 001CEB24 00008244 */  mtc1       $2, $f0
    /* CEB28 001CEB28 00000000 */  nop
    /* CEB2C 001CEB2C 34080046 */  c.lt.s     $f1, $f0
    /* CEB30 001CEB30 02000045 */  bc1f       .L001CEB3C
    /* CEB34 001CEB34 00000000 */   nop
    /* CEB38 001CEB38 7400A0E7 */  swc1       $f0, 0x74($29)
  .L001CEB3C:
    /* CEB3C 001CEB3C 000100C6 */  lwc1       $f0, 0x100($16)
    /* CEB40 001CEB40 00001546 */  add.s      $f0, $f0, $f21
    /* CEB44 001CEB44 000100E6 */  swc1       $f0, 0x100($16)
    /* CEB48 001CEB48 ACB3828F */  lw         $2, -0x4C54($28)
    /* CEB4C 001CEB4C 0C00438C */  lw         $3, 0xC($2)
    /* CEB50 001CEB50 2000023C */  lui        $2, (0x200000 >> 16)
    /* CEB54 001CEB54 24106200 */  and        $2, $3, $2
    /* CEB58 001CEB58 05004014 */  bnez       $2, .L001CEB70
    /* CEB5C 001CEB5C 00000000 */   nop
    /* CEB60 001CEB60 7000A427 */  addiu      $4, $29, 0x70
    /* CEB64 001CEB64 2D288000 */  daddu      $5, $4, $0
    /* CEB68 001CEB68 E8F0060C */  jal        func_001bc3a0
    /* CEB6C 001CEB6C 00000000 */   nop
  .L001CEB70:
    /* CEB70 001CEB70 2D200002 */  daddu      $4, $16, $0
    /* CEB74 001CEB74 7000A527 */  addiu      $5, $29, 0x70
    /* CEB78 001CEB78 C0EA060C */  jal        func_001bab00
    /* CEB7C 001CEB7C 00000000 */   nop
    /* CEB80 001CEB80 2000BFDF */  ld         $31, 0x20($29)
    /* CEB84 001CEB84 1000B07B */  lq         $16, 0x10($29)
    /* CEB88 001CEB88 0800B6C7 */  lwc1       $f22, 0x8($29)
    /* CEB8C 001CEB8C 0400B5C7 */  lwc1       $f21, 0x4($29)
    /* CEB90 001CEB90 0000B4C7 */  lwc1       $f20, 0x0($29)
    /* CEB94 001CEB94 B000BD27 */  addiu      $29, $29, 0xB0
    /* CEB98 001CEB98 0800E003 */  jr         $31
    /* CEB9C 001CEB9C 00000000 */   nop
.size func_001ce8c0, 0x2e0
