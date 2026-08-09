.section .text
.set noat
.set noreorder
glabel func_001d49c0
    /* D49C0 001D49C0 80FFBD27 */  addiu      $29, $29, -0x80
    /* D49C4 001D49C4 4000BFFF */  sd         $31, 0x40($29)
    /* D49C8 001D49C8 3000B37F */  sq         $19, 0x30($29)
    /* D49CC 001D49CC 2000B27F */  sq         $18, 0x20($29)
    /* D49D0 001D49D0 1000B17F */  sq         $17, 0x10($29)
    /* D49D4 001D49D4 0000B07F */  sq         $16, 0x0($29)
    /* D49D8 001D49D8 2D888000 */  daddu      $17, $4, $0
    /* D49DC 001D49DC 2D80E000 */  daddu      $16, $7, $0
    /* D49E0 001D49E0 0800D224 */  addiu      $18, $6, 0x8
    /* D49E4 001D49E4 9800A28C */  lw         $2, 0x98($5)
    /* D49E8 001D49E8 02004230 */  andi       $2, $2, 0x2
    /* D49EC 001D49EC 07004014 */  bnez       $2, .L001D4A0C
    /* D49F0 001D49F0 00000000 */   nop
    /* D49F4 001D49F4 2D20A000 */  daddu      $4, $5, $0
    /* D49F8 001D49F8 7000A527 */  addiu      $5, $29, 0x70
    /* D49FC 001D49FC 1456060C */  jal        func_00195850
    /* D4A00 001D4A00 00000000 */   nop
    /* D4A04 001D4A04 2F000010 */  b          .L001D4AC4
    /* D4A08 001D4A08 00000000 */   nop
  .L001D4A0C:
    /* D4A0C 001D4A0C 000AA28C */  lw         $2, 0xA00($5)
    /* D4A10 001D4A10 9C02538C */  lw         $19, 0x29C($2)
    /* D4A14 001D4A14 02006016 */  bnez       $19, .L001D4A20
    /* D4A18 001D4A18 00000000 */   nop
    /* D4A1C 001D4A1C 2D984000 */  daddu      $19, $2, $0
  .L001D4A20:
    /* D4A20 001D4A20 2D206002 */  daddu      $4, $19, $0
    /* D4A24 001D4A24 70E2110C */  jal        func_004789c0
    /* D4A28 001D4A28 00000000 */   nop
    /* D4A2C 001D4A2C 2D206002 */  daddu      $4, $19, $0
    /* D4A30 001D4A30 C8E8110C */  jal        func_0047a320
    /* D4A34 001D4A34 00000000 */   nop
    /* D4A38 001D4A38 04004596 */  lhu        $5, 0x4($18)
    /* D4A3C 001D4A3C 2D206002 */  daddu      $4, $19, $0
    /* D4A40 001D4A40 7000A627 */  addiu      $6, $29, 0x70
    /* D4A44 001D4A44 B4E9110C */  jal        func_0047a6d0
    /* D4A48 001D4A48 00000000 */   nop
    /* D4A4C 001D4A4C 1D004014 */  bnez       $2, .L001D4AC4
    /* D4A50 001D4A50 00000000 */   nop
    /* D4A54 001D4A54 200020C6 */  lwc1       $f0, 0x20($17)
    /* D4A58 001D4A58 500021C6 */  lwc1       $f1, 0x50($17)
    /* D4A5C 001D4A5C 02000146 */  mul.s      $f0, $f0, $f1
    /* D4A60 001D4A60 6000A0E7 */  swc1       $f0, 0x60($29)
    /* D4A64 001D4A64 240020C6 */  lwc1       $f0, 0x24($17)
    /* D4A68 001D4A68 02000146 */  mul.s      $f0, $f0, $f1
    /* D4A6C 001D4A6C 6400A0E7 */  swc1       $f0, 0x64($29)
    /* D4A70 001D4A70 280020C6 */  lwc1       $f0, 0x28($17)
    /* D4A74 001D4A74 02000146 */  mul.s      $f0, $f0, $f1
    /* D4A78 001D4A78 6800A0E7 */  swc1       $f0, 0x68($29)
    /* D4A7C 001D4A7C 5000A427 */  addiu      $4, $29, 0x50
    /* D4A80 001D4A80 6000A527 */  addiu      $5, $29, 0x60
    /* D4A84 001D4A84 01000624 */  addiu      $6, $0, 0x1
    /* D4A88 001D4A88 40002726 */  addiu      $7, $17, 0x40
    /* D4A8C 001D4A8C D0720F0C */  jal        func_003dcb40
    /* D4A90 001D4A90 00000000 */   nop
    /* D4A94 001D4A94 340021C6 */  lwc1       $f1, 0x34($17)
    /* D4A98 001D4A98 5000A0C7 */  lwc1       $f0, 0x50($29)
    /* D4A9C 001D4A9C 00000146 */  add.s      $f0, $f0, $f1
    /* D4AA0 001D4AA0 7000A0E7 */  swc1       $f0, 0x70($29)
    /* D4AA4 001D4AA4 380021C6 */  lwc1       $f1, 0x38($17)
    /* D4AA8 001D4AA8 5400A0C7 */  lwc1       $f0, 0x54($29)
    /* D4AAC 001D4AAC 00000146 */  add.s      $f0, $f0, $f1
    /* D4AB0 001D4AB0 7400A0E7 */  swc1       $f0, 0x74($29)
    /* D4AB4 001D4AB4 3C0021C6 */  lwc1       $f1, 0x3C($17)
    /* D4AB8 001D4AB8 5800A0C7 */  lwc1       $f0, 0x58($29)
    /* D4ABC 001D4ABC 00000146 */  add.s      $f0, $f0, $f1
    /* D4AC0 001D4AC0 7800A0E7 */  swc1       $f0, 0x78($29)
  .L001D4AC4:
    /* D4AC4 001D4AC4 7000A0C7 */  lwc1       $f0, 0x70($29)
    /* D4AC8 001D4AC8 000000E6 */  swc1       $f0, 0x0($16)
    /* D4ACC 001D4ACC 7400A0C7 */  lwc1       $f0, 0x74($29)
    /* D4AD0 001D4AD0 040000E6 */  swc1       $f0, 0x4($16)
    /* D4AD4 001D4AD4 7800A0C7 */  lwc1       $f0, 0x78($29)
    /* D4AD8 001D4AD8 080000E6 */  swc1       $f0, 0x8($16)
    /* D4ADC 001D4ADC 4000BFDF */  ld         $31, 0x40($29)
    /* D4AE0 001D4AE0 3000B37B */  lq         $19, 0x30($29)
    /* D4AE4 001D4AE4 2000B27B */  lq         $18, 0x20($29)
    /* D4AE8 001D4AE8 1000B17B */  lq         $17, 0x10($29)
    /* D4AEC 001D4AEC 0000B07B */  lq         $16, 0x0($29)
    /* D4AF0 001D4AF0 8000BD27 */  addiu      $29, $29, 0x80
    /* D4AF4 001D4AF4 0800E003 */  jr         $31
    /* D4AF8 001D4AF8 00000000 */   nop
    /* D4AFC 001D4AFC 00000000 */  nop
.size func_001d49c0, 0x140
