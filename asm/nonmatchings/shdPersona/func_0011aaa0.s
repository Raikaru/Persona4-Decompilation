.section .text
.set noat
.set noreorder
glabel func_0011aaa0
    /* 1AAA0 0011AAA0 C0FFBD27 */  addiu      $29, $29, -0x40
    /* 1AAA4 0011AAA4 3000BFFF */  sd         $31, 0x30($29)
    /* 1AAA8 0011AAA8 2000B17F */  sq         $17, 0x20($29)
    /* 1AAAC 0011AAAC 1000B07F */  sq         $16, 0x10($29)
    /* 1AAB0 0011AAB0 0000B4E7 */  swc1       $f20, 0x0($29)
    /* 1AAB4 0011AAB4 2D888000 */  daddu      $17, $4, $0
    /* 1AAB8 0011AAB8 2D800000 */  daddu      $16, $0, $0
    /* 1AABC 0011AABC 2D300000 */  daddu      $6, $0, $0
    /* 1AAC0 0011AAC0 0C000010 */  b          .L0011AAF4
    /* 1AAC4 0011AAC4 00000000 */   nop
  .L0011AAC8:
    /* 1AAC8 0011AAC8 C0180600 */  sll        $3, $6, 3
    /* 1AACC 0011AACC 21186600 */  addu       $3, $3, $6
    /* 1AAD0 0011AAD0 80180300 */  sll        $3, $3, 2
    /* 1AAD4 0011AAD4 21202302 */  addu       $4, $17, $3
    /* 1AAD8 0011AAD8 DC0280C4 */  lwc1       $f0, 0x2DC($4)
    /* 1AADC 0011AADC CC0280E4 */  swc1       $f0, 0x2CC($4)
    /* 1AAE0 0011AAE0 E00280C4 */  lwc1       $f0, 0x2E0($4)
    /* 1AAE4 0011AAE4 D00280E4 */  swc1       $f0, 0x2D0($4)
    /* 1AAE8 0011AAE8 E6028390 */  lbu        $3, 0x2E6($4)
    /* 1AAEC 0011AAEC E40283A0 */  sb         $3, 0x2E4($4)
    /* 1AAF0 0011AAF0 0100C624 */  addiu      $6, $6, 0x1
  .L0011AAF4:
    /* 1AAF4 0011AAF4 0A00C328 */  slti       $3, $6, 0xA
    /* 1AAF8 0011AAF8 F3FF6014 */  bnez       $3, .L0011AAC8
    /* 1AAFC 0011AAFC 00000000 */   nop
    /* 1AB00 0011AB00 0600A12C */  sltiu      $1, $5, 0x6
    /* 1AB04 0011AB04 2C002010 */  beqz       $1, .L0011ABB8
    /* 1AB08 0011AB08 00000000 */   nop
    /* 1AB0C 0011AB0C 7400043C */  lui        $4, %hi(jtbl_007465E0)
    /* 1AB10 0011AB10 E0658424 */  addiu      $4, $4, %lo(jtbl_007465E0)
    /* 1AB14 0011AB14 80180500 */  sll        $3, $5, 2
    /* 1AB18 0011AB18 21186400 */  addu       $3, $3, $4
    /* 1AB1C 0011AB1C 0000638C */  lw         $3, 0x0($3)
    /* 1AB20 0011AB20 08006000 */  jr         $3
    /* 1AB24 0011AB24 00000000 */   nop
    /* 1AB28 0011AB28 5E00103C */  lui        $16, %hi(D_005E4950)
    /* 1AB2C 0011AB2C 50491026 */  addiu      $16, $16, %lo(D_005E4950)
    /* 1AB30 0011AB30 0C0520C6 */  lwc1       $f0, 0x50C($17)
    /* 1AB34 0011AB34 20058046 */  cvt.s.w    $f20, $f0
    /* 1AB38 0011AB38 24000010 */  b          .L0011ABCC
    /* 1AB3C 0011AB3C 00000000 */   nop
    /* 1AB40 0011AB40 5E00103C */  lui        $16, %hi(D_005E4880)
    /* 1AB44 0011AB44 80481026 */  addiu      $16, $16, %lo(D_005E4880)
    /* 1AB48 0011AB48 100520C6 */  lwc1       $f0, 0x510($17)
    /* 1AB4C 0011AB4C 20058046 */  cvt.s.w    $f20, $f0
    /* 1AB50 0011AB50 1E000010 */  b          .L0011ABCC
    /* 1AB54 0011AB54 00000000 */   nop
    /* 1AB58 0011AB58 5E00103C */  lui        $16, %hi(D_005E4A20)
    /* 1AB5C 0011AB5C 204A1026 */  addiu      $16, $16, %lo(D_005E4A20)
    /* 1AB60 0011AB60 8040033C */  lui        $3, (0x40800000 >> 16)
    /* 1AB64 0011AB64 00A08344 */  mtc1       $3, $f20
    /* 1AB68 0011AB68 18000010 */  b          .L0011ABCC
    /* 1AB6C 0011AB6C 00000000 */   nop
    /* 1AB70 0011AB70 5E00103C */  lui        $16, %hi(D_005E4AF0)
    /* 1AB74 0011AB74 F04A1026 */  addiu      $16, $16, %lo(D_005E4AF0)
    /* 1AB78 0011AB78 8040033C */  lui        $3, (0x40800000 >> 16)
    /* 1AB7C 0011AB7C 00A08344 */  mtc1       $3, $f20
    /* 1AB80 0011AB80 12000010 */  b          .L0011ABCC
    /* 1AB84 0011AB84 00000000 */   nop
    /* 1AB88 0011AB88 5E00103C */  lui        $16, %hi(D_005E4BC0)
    /* 1AB8C 0011AB8C C04B1026 */  addiu      $16, $16, %lo(D_005E4BC0)
    /* 1AB90 0011AB90 0C0520C6 */  lwc1       $f0, 0x50C($17)
    /* 1AB94 0011AB94 20058046 */  cvt.s.w    $f20, $f0
    /* 1AB98 0011AB98 0C000010 */  b          .L0011ABCC
    /* 1AB9C 0011AB9C 00000000 */   nop
    /* 1ABA0 0011ABA0 5E00103C */  lui        $16, %hi(D_005E4C90)
    /* 1ABA4 0011ABA4 904C1026 */  addiu      $16, $16, %lo(D_005E4C90)
    /* 1ABA8 0011ABA8 100520C6 */  lwc1       $f0, 0x510($17)
    /* 1ABAC 0011ABAC 20058046 */  cvt.s.w    $f20, $f0
    /* 1ABB0 0011ABB0 06000010 */  b          .L0011ABCC
    /* 1ABB4 0011ABB4 00000000 */   nop
  .L0011ABB8:
    /* 1ABB8 0011ABB8 5E00043C */  lui        $4, %hi(D_005E4868)
    /* 1ABBC 0011ABBC 68488424 */  addiu      $4, $4, %lo(D_005E4868)
    /* 1ABC0 0011ABC0 A60A0524 */  addiu      $5, $0, 0xAA6
    /* 1ABC4 0011ABC4 CCB5110C */  jal        func_0046d730
    /* 1ABC8 0011ABC8 00000000 */   nop
  .L0011ABCC:
    /* 1ABCC 0011ABCC 06000016 */  bnez       $16, .L0011ABE8
    /* 1ABD0 0011ABD0 00000000 */   nop
    /* 1ABD4 0011ABD4 5E00043C */  lui        $4, %hi(D_005E4868)
    /* 1ABD8 0011ABD8 68488424 */  addiu      $4, $4, %lo(D_005E4868)
    /* 1ABDC 0011ABDC A90A0524 */  addiu      $5, $0, 0xAA9
    /* 1ABE0 0011ABE0 CCB5110C */  jal        func_0046d730
    /* 1ABE4 0011ABE4 00000000 */   nop
  .L0011ABE8:
    /* 1ABE8 0011ABE8 2D300000 */  daddu      $6, $0, $0
    /* 1ABEC 0011ABEC 16000010 */  b          .L0011AC48
    /* 1ABF0 0011ABF0 00000000 */   nop
  .L0011ABF4:
    /* 1ABF4 0011ABF4 80180600 */  sll        $3, $6, 2
    /* 1ABF8 0011ABF8 21186600 */  addu       $3, $3, $6
    /* 1ABFC 0011ABFC 80180300 */  sll        $3, $3, 2
    /* 1AC00 0011AC00 21280302 */  addu       $5, $16, $3
    /* 1AC04 0011AC04 C0180600 */  sll        $3, $6, 3
    /* 1AC08 0011AC08 21186600 */  addu       $3, $3, $6
    /* 1AC0C 0011AC0C 80180300 */  sll        $3, $3, 2
    /* 1AC10 0011AC10 21202302 */  addu       $4, $17, $3
    /* 1AC14 0011AC14 0000A0C4 */  lwc1       $f0, 0x0($5)
    /* 1AC18 0011AC18 D40280E4 */  swc1       $f0, 0x2D4($4)
    /* 1AC1C 0011AC1C 0400A0C4 */  lwc1       $f0, 0x4($5)
    /* 1AC20 0011AC20 D80280E4 */  swc1       $f0, 0x2D8($4)
    /* 1AC24 0011AC24 0800A390 */  lbu        $3, 0x8($5)
    /* 1AC28 0011AC28 E50283A0 */  sb         $3, 0x2E5($4)
    /* 1AC2C 0011AC2C 0C00A0C4 */  lwc1       $f0, 0xC($5)
    /* 1AC30 0011AC30 02A00046 */  mul.s      $f0, $f20, $f0
    /* 1AC34 0011AC34 E80280E4 */  swc1       $f0, 0x2E8($4)
    /* 1AC38 0011AC38 1000A0C4 */  lwc1       $f0, 0x10($5)
    /* 1AC3C 0011AC3C 02A00046 */  mul.s      $f0, $f20, $f0
    /* 1AC40 0011AC40 EC0280E4 */  swc1       $f0, 0x2EC($4)
    /* 1AC44 0011AC44 0100C624 */  addiu      $6, $6, 0x1
  .L0011AC48:
    /* 1AC48 0011AC48 0A00C328 */  slti       $3, $6, 0xA
    /* 1AC4C 0011AC4C E9FF6014 */  bnez       $3, .L0011ABF4
    /* 1AC50 0011AC50 00000000 */   nop
    /* 1AC54 0011AC54 3000BFDF */  ld         $31, 0x30($29)
    /* 1AC58 0011AC58 2000B17B */  lq         $17, 0x20($29)
    /* 1AC5C 0011AC5C 1000B07B */  lq         $16, 0x10($29)
    /* 1AC60 0011AC60 0000B4C7 */  lwc1       $f20, 0x0($29)
    /* 1AC64 0011AC64 4000BD27 */  addiu      $29, $29, 0x40
    /* 1AC68 0011AC68 0800E003 */  jr         $31
    /* 1AC6C 0011AC6C 00000000 */   nop
.size func_0011aaa0, 0x1d0
