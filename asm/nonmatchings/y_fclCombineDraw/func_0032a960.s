.section .text
.set noat
.set noreorder
glabel func_0032a960
    /* 22A960 0032A960 90FFBD27 */  addiu      $29, $29, -0x70
    /* 22A964 0032A964 3000BFFF */  sd         $31, 0x30($29)
    /* 22A968 0032A968 2000B17F */  sq         $17, 0x20($29)
    /* 22A96C 0032A96C 1000B07F */  sq         $16, 0x10($29)
    /* 22A970 0032A970 0800B6E7 */  swc1       $f22, 0x8($29)
    /* 22A974 0032A974 0400B5E7 */  swc1       $f21, 0x4($29)
    /* 22A978 0032A978 0000B4E7 */  swc1       $f20, 0x0($29)
    /* 22A97C 0032A97C 2D80A000 */  daddu      $16, $5, $0
    /* 22A980 0032A980 B041023C */  lui        $2, (0x41B00000 >> 16)
    /* 22A984 0032A984 00608244 */  mtc1       $2, $f12
    /* 22A988 0032A988 9C42023C */  lui        $2, (0x429C0000 >> 16)
    /* 22A98C 0032A98C 00688244 */  mtc1       $2, $f13
    /* 22A990 0032A990 4000A427 */  addiu      $4, $29, 0x40
    /* 22A994 0032A994 5CCA0A0C */  jal        func_002b2970
    /* 22A998 0032A998 00000000 */   nop
    /* 22A99C 0032A99C 4000A1C7 */  lwc1       $f1, 0x40($29)
    /* 22A9A0 0032A9A0 4400A0C7 */  lwc1       $f0, 0x44($29)
    /* 22A9A4 0032A9A4 5000A1E7 */  swc1       $f1, 0x50($29)
    /* 22A9A8 0032A9A8 5400A0E7 */  swc1       $f0, 0x54($29)
    /* 22A9AC 0032A9AC 3C861000 */  dsll32     $16, $16, 24
    /* 22A9B0 0032A9B0 3F861000 */  dsra32     $16, $16, 24
    /* 22A9B4 0032A9B4 29000016 */  bnez       $16, .L0032AA5C
    /* 22A9B8 0032A9B8 00000000 */   nop
    /* 22A9BC 0032A9BC 7041023C */  lui        $2, (0x41700000 >> 16)
    /* 22A9C0 0032A9C0 00608244 */  mtc1       $2, $f12
    /* 22A9C4 0032A9C4 9E000424 */  addiu      $4, $0, 0x9E
    /* 22A9C8 0032A9C8 5000A5DF */  ld         $5, 0x50($29)
    /* 22A9CC 0032A9CC C1000624 */  addiu      $6, $0, 0xC1
    /* 22A9D0 0032A9D0 0CDB0A0C */  jal        func_002b6c30
    /* 22A9D4 0032A9D4 00000000 */   nop
    /* 22A9D8 0032A9D8 6C00A427 */  addiu      $4, $29, 0x6C
    /* 22A9DC 0032A9DC 2D280000 */  daddu      $5, $0, $0
    /* 22A9E0 0032A9E0 2D300000 */  daddu      $6, $0, $0
    /* 22A9E4 0032A9E4 2D380000 */  daddu      $7, $0, $0
    /* 22A9E8 0032A9E8 FF000824 */  addiu      $8, $0, 0xFF
    /* 22A9EC 0032A9EC 98CA0A0C */  jal        func_002b2a60
    /* 22A9F0 0032A9F0 00000000 */   nop
    /* 22A9F4 0032A9F4 9E000424 */  addiu      $4, $0, 0x9E
    /* 22A9F8 0032A9F8 54D80A0C */  jal        func_002b6150
    /* 22A9FC 0032A9FC 00000000 */   nop
    /* 22AA00 0032AA00 6C00A693 */  lbu        $6, 0x6C($29)
    /* 22AA04 0032AA04 6D00A593 */  lbu        $5, 0x6D($29)
    /* 22AA08 0032AA08 6E00A493 */  lbu        $4, 0x6E($29)
    /* 22AA0C 0032AA0C 6F00A393 */  lbu        $3, 0x6F($29)
    /* 22AA10 0032AA10 850046A0 */  sb         $6, 0x85($2)
    /* 22AA14 0032AA14 860045A0 */  sb         $5, 0x86($2)
    /* 22AA18 0032AA18 870044A0 */  sb         $4, 0x87($2)
    /* 22AA1C 0032AA1C 880043A0 */  sb         $3, 0x88($2)
    /* 22AA20 0032AA20 66001124 */  addiu      $17, $0, 0x66
    /* 22AA24 0032AA24 9E000424 */  addiu      $4, $0, 0x9E
    /* 22AA28 0032AA28 54D80A0C */  jal        func_002b6150
    /* 22AA2C 0032AA2C 00000000 */   nop
    /* 22AA30 0032AA30 6E0051A0 */  sb         $17, 0x6E($2)
    /* 22AA34 0032AA34 9E000424 */  addiu      $4, $0, 0x9E
    /* 22AA38 0032AA38 2D280000 */  daddu      $5, $0, $0
    /* 22AA3C 0032AA3C 2D302002 */  daddu      $6, $17, $0
    /* 22AA40 0032AA40 2D380000 */  daddu      $7, $0, $0
    /* 22AA44 0032AA44 05000824 */  addiu      $8, $0, 0x5
    /* 22AA48 0032AA48 03000924 */  addiu      $9, $0, 0x3
    /* 22AA4C 0032AA4C 9CDA0A0C */  jal        func_002b6a70
    /* 22AA50 0032AA50 00000000 */   nop
    /* 22AA54 0032AA54 0C000010 */  b          .L0032AA88
    /* 22AA58 0032AA58 00000000 */   nop
  .L0032AA5C:
    /* 22AA5C 0032AA5C 9E000424 */  addiu      $4, $0, 0x9E
    /* 22AA60 0032AA60 54D80A0C */  jal        func_002b6150
    /* 22AA64 0032AA64 00000000 */   nop
    /* 22AA68 0032AA68 9E000424 */  addiu      $4, $0, 0x9E
    /* 22AA6C 0032AA6C 6E004590 */  lbu        $5, 0x6E($2)
    /* 22AA70 0032AA70 2D300000 */  daddu      $6, $0, $0
    /* 22AA74 0032AA74 2D380000 */  daddu      $7, $0, $0
    /* 22AA78 0032AA78 2D400000 */  daddu      $8, $0, $0
    /* 22AA7C 0032AA7C 2D480000 */  daddu      $9, $0, $0
    /* 22AA80 0032AA80 9CDA0A0C */  jal        func_002b6a70
    /* 22AA84 0032AA84 00000000 */   nop
  .L0032AA88:
    /* 22AA88 0032AA88 5400B4C7 */  lwc1       $f20, 0x54($29)
    /* 22AA8C 0032AA8C 25010224 */  addiu      $2, $0, 0x125
    /* 22AA90 0032AA90 00008244 */  mtc1       $2, $f0
    /* 22AA94 0032AA94 00000000 */  nop
    /* 22AA98 0032AA98 20008046 */  cvt.s.w    $f0, $f0
    /* 22AA9C 0032AA9C 40031446 */  add.s      $f13, $f0, $f20
    /* 22AAA0 0032AAA0 4800A427 */  addiu      $4, $29, 0x48
    /* 22AAA4 0032AAA4 5000ACC7 */  lwc1       $f12, 0x50($29)
    /* 22AAA8 0032AAA8 5CCA0A0C */  jal        func_002b2970
    /* 22AAAC 0032AAAC 00000000 */   nop
    /* 22AAB0 0032AAB0 29000016 */  bnez       $16, .L0032AB58
    /* 22AAB4 0032AAB4 00000000 */   nop
    /* 22AAB8 0032AAB8 8041023C */  lui        $2, (0x41800000 >> 16)
    /* 22AABC 0032AABC 00608244 */  mtc1       $2, $f12
    /* 22AAC0 0032AAC0 A0000424 */  addiu      $4, $0, 0xA0
    /* 22AAC4 0032AAC4 4800A5DF */  ld         $5, 0x48($29)
    /* 22AAC8 0032AAC8 C1000624 */  addiu      $6, $0, 0xC1
    /* 22AACC 0032AACC 0CDB0A0C */  jal        func_002b6c30
    /* 22AAD0 0032AAD0 00000000 */   nop
    /* 22AAD4 0032AAD4 6800A427 */  addiu      $4, $29, 0x68
    /* 22AAD8 0032AAD8 2D280000 */  daddu      $5, $0, $0
    /* 22AADC 0032AADC 2D300000 */  daddu      $6, $0, $0
    /* 22AAE0 0032AAE0 2D380000 */  daddu      $7, $0, $0
    /* 22AAE4 0032AAE4 FF000824 */  addiu      $8, $0, 0xFF
    /* 22AAE8 0032AAE8 98CA0A0C */  jal        func_002b2a60
    /* 22AAEC 0032AAEC 00000000 */   nop
    /* 22AAF0 0032AAF0 A0000424 */  addiu      $4, $0, 0xA0
    /* 22AAF4 0032AAF4 54D80A0C */  jal        func_002b6150
    /* 22AAF8 0032AAF8 00000000 */   nop
    /* 22AAFC 0032AAFC 6800A693 */  lbu        $6, 0x68($29)
    /* 22AB00 0032AB00 6900A593 */  lbu        $5, 0x69($29)
    /* 22AB04 0032AB04 6A00A493 */  lbu        $4, 0x6A($29)
    /* 22AB08 0032AB08 6B00A393 */  lbu        $3, 0x6B($29)
    /* 22AB0C 0032AB0C 850046A0 */  sb         $6, 0x85($2)
    /* 22AB10 0032AB10 860045A0 */  sb         $5, 0x86($2)
    /* 22AB14 0032AB14 870044A0 */  sb         $4, 0x87($2)
    /* 22AB18 0032AB18 880043A0 */  sb         $3, 0x88($2)
    /* 22AB1C 0032AB1C 66001124 */  addiu      $17, $0, 0x66
    /* 22AB20 0032AB20 A0000424 */  addiu      $4, $0, 0xA0
    /* 22AB24 0032AB24 54D80A0C */  jal        func_002b6150
    /* 22AB28 0032AB28 00000000 */   nop
    /* 22AB2C 0032AB2C 6E0051A0 */  sb         $17, 0x6E($2)
    /* 22AB30 0032AB30 A0000424 */  addiu      $4, $0, 0xA0
    /* 22AB34 0032AB34 2D280000 */  daddu      $5, $0, $0
    /* 22AB38 0032AB38 2D302002 */  daddu      $6, $17, $0
    /* 22AB3C 0032AB3C 2D380000 */  daddu      $7, $0, $0
    /* 22AB40 0032AB40 05000824 */  addiu      $8, $0, 0x5
    /* 22AB44 0032AB44 03000924 */  addiu      $9, $0, 0x3
    /* 22AB48 0032AB48 9CDA0A0C */  jal        func_002b6a70
    /* 22AB4C 0032AB4C 00000000 */   nop
    /* 22AB50 0032AB50 0C000010 */  b          .L0032AB84
    /* 22AB54 0032AB54 00000000 */   nop
  .L0032AB58:
    /* 22AB58 0032AB58 A0000424 */  addiu      $4, $0, 0xA0
    /* 22AB5C 0032AB5C 54D80A0C */  jal        func_002b6150
    /* 22AB60 0032AB60 00000000 */   nop
    /* 22AB64 0032AB64 A0000424 */  addiu      $4, $0, 0xA0
    /* 22AB68 0032AB68 6E004590 */  lbu        $5, 0x6E($2)
    /* 22AB6C 0032AB6C 2D300000 */  daddu      $6, $0, $0
    /* 22AB70 0032AB70 2D380000 */  daddu      $7, $0, $0
    /* 22AB74 0032AB74 2D400000 */  daddu      $8, $0, $0
    /* 22AB78 0032AB78 2D480000 */  daddu      $9, $0, $0
    /* 22AB7C 0032AB7C 9CDA0A0C */  jal        func_002b6a70
    /* 22AB80 0032AB80 00000000 */   nop
  .L0032AB84:
    /* 22AB84 0032AB84 B841023C */  lui        $2, (0x41B80000 >> 16)
    /* 22AB88 0032AB88 00008244 */  mtc1       $2, $f0
    /* 22AB8C 0032AB8C 00000000 */  nop
    /* 22AB90 0032AB90 40051446 */  add.s      $f21, $f0, $f20
    /* 22AB94 0032AB94 7041023C */  lui        $2, (0x41700000 >> 16)
    /* 22AB98 0032AB98 00088244 */  mtc1       $2, $f1
    /* 22AB9C 0032AB9C 5000A0C7 */  lwc1       $f0, 0x50($29)
    /* 22ABA0 0032ABA0 000B0046 */  add.s      $f12, $f1, $f0
    /* 22ABA4 0032ABA4 4800A427 */  addiu      $4, $29, 0x48
    /* 22ABA8 0032ABA8 46AB0046 */  mov.s      $f13, $f21
    /* 22ABAC 0032ABAC 5CCA0A0C */  jal        func_002b2970
    /* 22ABB0 0032ABB0 00000000 */   nop
    /* 22ABB4 0032ABB4 24000016 */  bnez       $16, .L0032AC48
    /* 22ABB8 0032ABB8 00000000 */   nop
    /* 22ABBC 0032ABBC 5041023C */  lui        $2, (0x41500000 >> 16)
    /* 22ABC0 0032ABC0 00608244 */  mtc1       $2, $f12
    /* 22ABC4 0032ABC4 96010424 */  addiu      $4, $0, 0x196
    /* 22ABC8 0032ABC8 4800A5DF */  ld         $5, 0x48($29)
    /* 22ABCC 0032ABCC C2000624 */  addiu      $6, $0, 0xC2
    /* 22ABD0 0032ABD0 0CDB0A0C */  jal        func_002b6c30
    /* 22ABD4 0032ABD4 00000000 */   nop
    /* 22ABD8 0032ABD8 6400A427 */  addiu      $4, $29, 0x64
    /* 22ABDC 0032ABDC FF000524 */  addiu      $5, $0, 0xFF
    /* 22ABE0 0032ABE0 2D30A000 */  daddu      $6, $5, $0
    /* 22ABE4 0032ABE4 2D38A000 */  daddu      $7, $5, $0
    /* 22ABE8 0032ABE8 2D40A000 */  daddu      $8, $5, $0
    /* 22ABEC 0032ABEC 98CA0A0C */  jal        func_002b2a60
    /* 22ABF0 0032ABF0 00000000 */   nop
    /* 22ABF4 0032ABF4 96010424 */  addiu      $4, $0, 0x196
    /* 22ABF8 0032ABF8 54D80A0C */  jal        func_002b6150
    /* 22ABFC 0032ABFC 00000000 */   nop
    /* 22AC00 0032AC00 6400A693 */  lbu        $6, 0x64($29)
    /* 22AC04 0032AC04 6500A593 */  lbu        $5, 0x65($29)
    /* 22AC08 0032AC08 6600A493 */  lbu        $4, 0x66($29)
    /* 22AC0C 0032AC0C 6700A393 */  lbu        $3, 0x67($29)
    /* 22AC10 0032AC10 850046A0 */  sb         $6, 0x85($2)
    /* 22AC14 0032AC14 860045A0 */  sb         $5, 0x86($2)
    /* 22AC18 0032AC18 870044A0 */  sb         $4, 0x87($2)
    /* 22AC1C 0032AC1C 880043A0 */  sb         $3, 0x88($2)
    /* 22AC20 0032AC20 96010424 */  addiu      $4, $0, 0x196
    /* 22AC24 0032AC24 2D280000 */  daddu      $5, $0, $0
    /* 22AC28 0032AC28 FF000624 */  addiu      $6, $0, 0xFF
    /* 22AC2C 0032AC2C 2D380000 */  daddu      $7, $0, $0
    /* 22AC30 0032AC30 05000824 */  addiu      $8, $0, 0x5
    /* 22AC34 0032AC34 2D480000 */  daddu      $9, $0, $0
    /* 22AC38 0032AC38 9CDA0A0C */  jal        func_002b6a70
    /* 22AC3C 0032AC3C 00000000 */   nop
    /* 22AC40 0032AC40 0C000010 */  b          .L0032AC74
    /* 22AC44 0032AC44 00000000 */   nop
  .L0032AC48:
    /* 22AC48 0032AC48 96010424 */  addiu      $4, $0, 0x196
    /* 22AC4C 0032AC4C 54D80A0C */  jal        func_002b6150
    /* 22AC50 0032AC50 00000000 */   nop
    /* 22AC54 0032AC54 96010424 */  addiu      $4, $0, 0x196
    /* 22AC58 0032AC58 6E004590 */  lbu        $5, 0x6E($2)
    /* 22AC5C 0032AC5C 2D300000 */  daddu      $6, $0, $0
    /* 22AC60 0032AC60 2D380000 */  daddu      $7, $0, $0
    /* 22AC64 0032AC64 2D400000 */  daddu      $8, $0, $0
    /* 22AC68 0032AC68 2D480000 */  daddu      $9, $0, $0
    /* 22AC6C 0032AC6C 9CDA0A0C */  jal        func_002b6a70
    /* 22AC70 0032AC70 00000000 */   nop
  .L0032AC74:
    /* 22AC74 0032AC74 1D010224 */  addiu      $2, $0, 0x11D
    /* 22AC78 0032AC78 00008244 */  mtc1       $2, $f0
    /* 22AC7C 0032AC7C 00000000 */  nop
    /* 22AC80 0032AC80 60008046 */  cvt.s.w    $f1, $f0
    /* 22AC84 0032AC84 5000A0C7 */  lwc1       $f0, 0x50($29)
    /* 22AC88 0032AC88 000B0046 */  add.s      $f12, $f1, $f0
    /* 22AC8C 0032AC8C 4800A427 */  addiu      $4, $29, 0x48
    /* 22AC90 0032AC90 46AB0046 */  mov.s      $f13, $f21
    /* 22AC94 0032AC94 5CCA0A0C */  jal        func_002b2970
    /* 22AC98 0032AC98 00000000 */   nop
    /* 22AC9C 0032AC9C 24000016 */  bnez       $16, .L0032AD30
    /* 22ACA0 0032ACA0 00000000 */   nop
    /* 22ACA4 0032ACA4 6041023C */  lui        $2, (0x41600000 >> 16)
    /* 22ACA8 0032ACA8 00608244 */  mtc1       $2, $f12
    /* 22ACAC 0032ACAC A1010424 */  addiu      $4, $0, 0x1A1
    /* 22ACB0 0032ACB0 4800A5DF */  ld         $5, 0x48($29)
    /* 22ACB4 0032ACB4 C2000624 */  addiu      $6, $0, 0xC2
    /* 22ACB8 0032ACB8 0CDB0A0C */  jal        func_002b6c30
    /* 22ACBC 0032ACBC 00000000 */   nop
    /* 22ACC0 0032ACC0 6000A427 */  addiu      $4, $29, 0x60
    /* 22ACC4 0032ACC4 FF000524 */  addiu      $5, $0, 0xFF
    /* 22ACC8 0032ACC8 2D30A000 */  daddu      $6, $5, $0
    /* 22ACCC 0032ACCC 2D38A000 */  daddu      $7, $5, $0
    /* 22ACD0 0032ACD0 2D40A000 */  daddu      $8, $5, $0
    /* 22ACD4 0032ACD4 98CA0A0C */  jal        func_002b2a60
    /* 22ACD8 0032ACD8 00000000 */   nop
    /* 22ACDC 0032ACDC A1010424 */  addiu      $4, $0, 0x1A1
    /* 22ACE0 0032ACE0 54D80A0C */  jal        func_002b6150
    /* 22ACE4 0032ACE4 00000000 */   nop
    /* 22ACE8 0032ACE8 6000A693 */  lbu        $6, 0x60($29)
    /* 22ACEC 0032ACEC 6100A593 */  lbu        $5, 0x61($29)
    /* 22ACF0 0032ACF0 6200A493 */  lbu        $4, 0x62($29)
    /* 22ACF4 0032ACF4 6300A393 */  lbu        $3, 0x63($29)
    /* 22ACF8 0032ACF8 850046A0 */  sb         $6, 0x85($2)
    /* 22ACFC 0032ACFC 860045A0 */  sb         $5, 0x86($2)
    /* 22AD00 0032AD00 870044A0 */  sb         $4, 0x87($2)
    /* 22AD04 0032AD04 880043A0 */  sb         $3, 0x88($2)
    /* 22AD08 0032AD08 A1010424 */  addiu      $4, $0, 0x1A1
    /* 22AD0C 0032AD0C 2D280000 */  daddu      $5, $0, $0
    /* 22AD10 0032AD10 FF000624 */  addiu      $6, $0, 0xFF
    /* 22AD14 0032AD14 2D380000 */  daddu      $7, $0, $0
    /* 22AD18 0032AD18 05000824 */  addiu      $8, $0, 0x5
    /* 22AD1C 0032AD1C 2D480000 */  daddu      $9, $0, $0
    /* 22AD20 0032AD20 9CDA0A0C */  jal        func_002b6a70
    /* 22AD24 0032AD24 00000000 */   nop
    /* 22AD28 0032AD28 0C000010 */  b          .L0032AD5C
    /* 22AD2C 0032AD2C 00000000 */   nop
  .L0032AD30:
    /* 22AD30 0032AD30 A1010424 */  addiu      $4, $0, 0x1A1
    /* 22AD34 0032AD34 54D80A0C */  jal        func_002b6150
    /* 22AD38 0032AD38 00000000 */   nop
    /* 22AD3C 0032AD3C A1010424 */  addiu      $4, $0, 0x1A1
    /* 22AD40 0032AD40 6E004590 */  lbu        $5, 0x6E($2)
    /* 22AD44 0032AD44 2D300000 */  daddu      $6, $0, $0
    /* 22AD48 0032AD48 2D380000 */  daddu      $7, $0, $0
    /* 22AD4C 0032AD4C 2D400000 */  daddu      $8, $0, $0
    /* 22AD50 0032AD50 2D480000 */  daddu      $9, $0, $0
    /* 22AD54 0032AD54 9CDA0A0C */  jal        func_002b6a70
    /* 22AD58 0032AD58 00000000 */   nop
  .L0032AD5C:
    /* 22AD5C 0032AD5C E2020424 */  addiu      $4, $0, 0x2E2
    /* 22AD60 0032AD60 9E000524 */  addiu      $5, $0, 0x9E
    /* 22AD64 0032AD64 D4DD0A0C */  jal        func_002b7750
    /* 22AD68 0032AD68 00000000 */   nop
    /* 22AD6C 0032AD6C 3041023C */  lui        $2, (0x41300000 >> 16)
    /* 22AD70 0032AD70 00088244 */  mtc1       $2, $f1
    /* 22AD74 0032AD74 5000A0C7 */  lwc1       $f0, 0x50($29)
    /* 22AD78 0032AD78 800D0046 */  add.s      $f22, $f1, $f0
    /* 22AD7C 0032AD7C 5041023C */  lui        $2, (0x41500000 >> 16)
    /* 22AD80 0032AD80 00008244 */  mtc1       $2, $f0
    /* 22AD84 0032AD84 00000000 */  nop
    /* 22AD88 0032AD88 40031446 */  add.s      $f13, $f0, $f20
    /* 22AD8C 0032AD8C 4800A427 */  addiu      $4, $29, 0x48
    /* 22AD90 0032AD90 06B30046 */  mov.s      $f12, $f22
    /* 22AD94 0032AD94 5CCA0A0C */  jal        func_002b2970
    /* 22AD98 0032AD98 00000000 */   nop
    /* 22AD9C 0032AD9C 36000016 */  bnez       $16, .L0032AE78
    /* 22ADA0 0032ADA0 00000000 */   nop
    /* 22ADA4 0032ADA4 6041023C */  lui        $2, (0x41600000 >> 16)
    /* 22ADA8 0032ADA8 00608244 */  mtc1       $2, $f12
    /* 22ADAC 0032ADAC E2020424 */  addiu      $4, $0, 0x2E2
    /* 22ADB0 0032ADB0 4800A5DF */  ld         $5, 0x48($29)
    /* 22ADB4 0032ADB4 C1000624 */  addiu      $6, $0, 0xC1
    /* 22ADB8 0032ADB8 0CDB0A0C */  jal        func_002b6c30
    /* 22ADBC 0032ADBC 00000000 */   nop
    /* 22ADC0 0032ADC0 E2020424 */  addiu      $4, $0, 0x2E2
    /* 22ADC4 0032ADC4 58DB0A0C */  jal        func_002b6d60
    /* 22ADC8 0032ADC8 00000000 */   nop
    /* 22ADCC 0032ADCC 5C00A427 */  addiu      $4, $29, 0x5C
    /* 22ADD0 0032ADD0 2D280000 */  daddu      $5, $0, $0
    /* 22ADD4 0032ADD4 2D300000 */  daddu      $6, $0, $0
    /* 22ADD8 0032ADD8 2D380000 */  daddu      $7, $0, $0
    /* 22ADDC 0032ADDC FF000824 */  addiu      $8, $0, 0xFF
    /* 22ADE0 0032ADE0 98CA0A0C */  jal        func_002b2a60
    /* 22ADE4 0032ADE4 00000000 */   nop
    /* 22ADE8 0032ADE8 E2020424 */  addiu      $4, $0, 0x2E2
    /* 22ADEC 0032ADEC 54D80A0C */  jal        func_002b6150
    /* 22ADF0 0032ADF0 00000000 */   nop
    /* 22ADF4 0032ADF4 5C00A693 */  lbu        $6, 0x5C($29)
    /* 22ADF8 0032ADF8 5D00A593 */  lbu        $5, 0x5D($29)
    /* 22ADFC 0032ADFC 5E00A493 */  lbu        $4, 0x5E($29)
    /* 22AE00 0032AE00 5F00A393 */  lbu        $3, 0x5F($29)
    /* 22AE04 0032AE04 850046A0 */  sb         $6, 0x85($2)
    /* 22AE08 0032AE08 860045A0 */  sb         $5, 0x86($2)
    /* 22AE0C 0032AE0C 870044A0 */  sb         $4, 0x87($2)
    /* 22AE10 0032AE10 880043A0 */  sb         $3, 0x88($2)
    /* 22AE14 0032AE14 66001124 */  addiu      $17, $0, 0x66
    /* 22AE18 0032AE18 E2020424 */  addiu      $4, $0, 0x2E2
    /* 22AE1C 0032AE1C 54D80A0C */  jal        func_002b6150
    /* 22AE20 0032AE20 00000000 */   nop
    /* 22AE24 0032AE24 6E0051A0 */  sb         $17, 0x6E($2)
    /* 22AE28 0032AE28 803F023C */  lui        $2, (0x3F800000 >> 16)
    /* 22AE2C 0032AE2C 00A88244 */  mtc1       $2, $f21
    /* 22AE30 0032AE30 E2020424 */  addiu      $4, $0, 0x2E2
    /* 22AE34 0032AE34 54D80A0C */  jal        func_002b6150
    /* 22AE38 0032AE38 00000000 */   nop
    /* 22AE3C 0032AE3C AC0055E4 */  swc1       $f21, 0xAC($2)
    /* 22AE40 0032AE40 E2020424 */  addiu      $4, $0, 0x2E2
    /* 22AE44 0032AE44 54D80A0C */  jal        func_002b6150
    /* 22AE48 0032AE48 00000000 */   nop
    /* 22AE4C 0032AE4C A00055E4 */  swc1       $f21, 0xA0($2)
    /* 22AE50 0032AE50 E2020424 */  addiu      $4, $0, 0x2E2
    /* 22AE54 0032AE54 2D280000 */  daddu      $5, $0, $0
    /* 22AE58 0032AE58 2D302002 */  daddu      $6, $17, $0
    /* 22AE5C 0032AE5C 2D380000 */  daddu      $7, $0, $0
    /* 22AE60 0032AE60 05000824 */  addiu      $8, $0, 0x5
    /* 22AE64 0032AE64 03000924 */  addiu      $9, $0, 0x3
    /* 22AE68 0032AE68 9CDA0A0C */  jal        func_002b6a70
    /* 22AE6C 0032AE6C 00000000 */   nop
    /* 22AE70 0032AE70 0C000010 */  b          .L0032AEA4
    /* 22AE74 0032AE74 00000000 */   nop
  .L0032AE78:
    /* 22AE78 0032AE78 E2020424 */  addiu      $4, $0, 0x2E2
    /* 22AE7C 0032AE7C 54D80A0C */  jal        func_002b6150
    /* 22AE80 0032AE80 00000000 */   nop
    /* 22AE84 0032AE84 E2020424 */  addiu      $4, $0, 0x2E2
    /* 22AE88 0032AE88 6E004590 */  lbu        $5, 0x6E($2)
    /* 22AE8C 0032AE8C 2D300000 */  daddu      $6, $0, $0
    /* 22AE90 0032AE90 2D380000 */  daddu      $7, $0, $0
    /* 22AE94 0032AE94 2D400000 */  daddu      $8, $0, $0
    /* 22AE98 0032AE98 2D480000 */  daddu      $9, $0, $0
    /* 22AE9C 0032AE9C 9CDA0A0C */  jal        func_002b6a70
    /* 22AEA0 0032AEA0 00000000 */   nop
  .L0032AEA4:
    /* 22AEA4 0032AEA4 E3020424 */  addiu      $4, $0, 0x2E3
    /* 22AEA8 0032AEA8 A0000524 */  addiu      $5, $0, 0xA0
    /* 22AEAC 0032AEAC D4DD0A0C */  jal        func_002b7750
    /* 22AEB0 0032AEB0 00000000 */   nop
    /* 22AEB4 0032AEB4 9943023C */  lui        $2, (0x43990000 >> 16)
    /* 22AEB8 0032AEB8 00008244 */  mtc1       $2, $f0
    /* 22AEBC 0032AEBC 00000000 */  nop
    /* 22AEC0 0032AEC0 40031446 */  add.s      $f13, $f0, $f20
    /* 22AEC4 0032AEC4 4800A427 */  addiu      $4, $29, 0x48
    /* 22AEC8 0032AEC8 06B30046 */  mov.s      $f12, $f22
    /* 22AECC 0032AECC 5CCA0A0C */  jal        func_002b2970
    /* 22AED0 0032AED0 00000000 */   nop
    /* 22AED4 0032AED4 33000016 */  bnez       $16, .L0032AFA4
    /* 22AED8 0032AED8 00000000 */   nop
    /* 22AEDC 0032AEDC 6041023C */  lui        $2, (0x41600000 >> 16)
    /* 22AEE0 0032AEE0 00608244 */  mtc1       $2, $f12
    /* 22AEE4 0032AEE4 E3020424 */  addiu      $4, $0, 0x2E3
    /* 22AEE8 0032AEE8 4800A5DF */  ld         $5, 0x48($29)
    /* 22AEEC 0032AEEC C1000624 */  addiu      $6, $0, 0xC1
    /* 22AEF0 0032AEF0 0CDB0A0C */  jal        func_002b6c30
    /* 22AEF4 0032AEF4 00000000 */   nop
    /* 22AEF8 0032AEF8 5800A427 */  addiu      $4, $29, 0x58
    /* 22AEFC 0032AEFC 2D280000 */  daddu      $5, $0, $0
    /* 22AF00 0032AF00 2D300000 */  daddu      $6, $0, $0
    /* 22AF04 0032AF04 2D380000 */  daddu      $7, $0, $0
    /* 22AF08 0032AF08 FF000824 */  addiu      $8, $0, 0xFF
    /* 22AF0C 0032AF0C 98CA0A0C */  jal        func_002b2a60
    /* 22AF10 0032AF10 00000000 */   nop
    /* 22AF14 0032AF14 E3020424 */  addiu      $4, $0, 0x2E3
    /* 22AF18 0032AF18 54D80A0C */  jal        func_002b6150
    /* 22AF1C 0032AF1C 00000000 */   nop
    /* 22AF20 0032AF20 5800A693 */  lbu        $6, 0x58($29)
    /* 22AF24 0032AF24 5900A593 */  lbu        $5, 0x59($29)
    /* 22AF28 0032AF28 5A00A493 */  lbu        $4, 0x5A($29)
    /* 22AF2C 0032AF2C 5B00A393 */  lbu        $3, 0x5B($29)
    /* 22AF30 0032AF30 850046A0 */  sb         $6, 0x85($2)
    /* 22AF34 0032AF34 860045A0 */  sb         $5, 0x86($2)
    /* 22AF38 0032AF38 870044A0 */  sb         $4, 0x87($2)
    /* 22AF3C 0032AF3C 880043A0 */  sb         $3, 0x88($2)
    /* 22AF40 0032AF40 66001024 */  addiu      $16, $0, 0x66
    /* 22AF44 0032AF44 E3020424 */  addiu      $4, $0, 0x2E3
    /* 22AF48 0032AF48 54D80A0C */  jal        func_002b6150
    /* 22AF4C 0032AF4C 00000000 */   nop
    /* 22AF50 0032AF50 6E0050A0 */  sb         $16, 0x6E($2)
    /* 22AF54 0032AF54 803F023C */  lui        $2, (0x3F800000 >> 16)
    /* 22AF58 0032AF58 00A08244 */  mtc1       $2, $f20
    /* 22AF5C 0032AF5C E3020424 */  addiu      $4, $0, 0x2E3
    /* 22AF60 0032AF60 54D80A0C */  jal        func_002b6150
    /* 22AF64 0032AF64 00000000 */   nop
    /* 22AF68 0032AF68 AC0054E4 */  swc1       $f20, 0xAC($2)
    /* 22AF6C 0032AF6C E3020424 */  addiu      $4, $0, 0x2E3
    /* 22AF70 0032AF70 54D80A0C */  jal        func_002b6150
    /* 22AF74 0032AF74 00000000 */   nop
    /* 22AF78 0032AF78 A00054E4 */  swc1       $f20, 0xA0($2)
    /* 22AF7C 0032AF7C E3020424 */  addiu      $4, $0, 0x2E3
    /* 22AF80 0032AF80 2D280000 */  daddu      $5, $0, $0
    /* 22AF84 0032AF84 2D300002 */  daddu      $6, $16, $0
    /* 22AF88 0032AF88 2D380000 */  daddu      $7, $0, $0
    /* 22AF8C 0032AF8C 05000824 */  addiu      $8, $0, 0x5
    /* 22AF90 0032AF90 03000924 */  addiu      $9, $0, 0x3
    /* 22AF94 0032AF94 9CDA0A0C */  jal        func_002b6a70
    /* 22AF98 0032AF98 00000000 */   nop
    /* 22AF9C 0032AF9C 0C000010 */  b          .L0032AFD0
    /* 22AFA0 0032AFA0 00000000 */   nop
  .L0032AFA4:
    /* 22AFA4 0032AFA4 E3020424 */  addiu      $4, $0, 0x2E3
    /* 22AFA8 0032AFA8 54D80A0C */  jal        func_002b6150
    /* 22AFAC 0032AFAC 00000000 */   nop
    /* 22AFB0 0032AFB0 E3020424 */  addiu      $4, $0, 0x2E3
    /* 22AFB4 0032AFB4 6E004590 */  lbu        $5, 0x6E($2)
    /* 22AFB8 0032AFB8 2D300000 */  daddu      $6, $0, $0
    /* 22AFBC 0032AFBC 2D380000 */  daddu      $7, $0, $0
    /* 22AFC0 0032AFC0 2D400000 */  daddu      $8, $0, $0
    /* 22AFC4 0032AFC4 2D480000 */  daddu      $9, $0, $0
    /* 22AFC8 0032AFC8 9CDA0A0C */  jal        func_002b6a70
    /* 22AFCC 0032AFCC 00000000 */   nop
  .L0032AFD0:
    /* 22AFD0 0032AFD0 3000BFDF */  ld         $31, 0x30($29)
    /* 22AFD4 0032AFD4 2000B17B */  lq         $17, 0x20($29)
    /* 22AFD8 0032AFD8 1000B07B */  lq         $16, 0x10($29)
    /* 22AFDC 0032AFDC 0800B6C7 */  lwc1       $f22, 0x8($29)
    /* 22AFE0 0032AFE0 0400B5C7 */  lwc1       $f21, 0x4($29)
    /* 22AFE4 0032AFE4 0000B4C7 */  lwc1       $f20, 0x0($29)
    /* 22AFE8 0032AFE8 7000BD27 */  addiu      $29, $29, 0x70
    /* 22AFEC 0032AFEC 0800E003 */  jr         $31
    /* 22AFF0 0032AFF0 00000000 */   nop
    /* 22AFF4 0032AFF4 00000000 */  nop
    /* 22AFF8 0032AFF8 00000000 */  nop
    /* 22AFFC 0032AFFC 00000000 */  nop
.size func_0032a960, 0x6a0
