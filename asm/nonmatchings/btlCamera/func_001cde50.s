.section .text
.set noat
.set noreorder
glabel func_001cde50
    /* CDE50 001CDE50 F0FEBD27 */  addiu      $29, $29, -0x110
    /* CDE54 001CDE54 3000BFFF */  sd         $31, 0x30($29)
    /* CDE58 001CDE58 2000B17F */  sq         $17, 0x20($29)
    /* CDE5C 001CDE5C 1000B07F */  sq         $16, 0x10($29)
    /* CDE60 001CDE60 0800B6E7 */  swc1       $f22, 0x8($29)
    /* CDE64 001CDE64 0400B5E7 */  swc1       $f21, 0x4($29)
    /* CDE68 001CDE68 0000B4E7 */  swc1       $f20, 0x0($29)
    /* CDE6C 001CDE6C 2D808000 */  daddu      $16, $4, $0
    /* CDE70 001CDE70 E000828C */  lw         $2, 0xE0($4)
    /* CDE74 001CDE74 3000518C */  lw         $17, 0x30($2)
    /* CDE78 001CDE78 900021C6 */  lwc1       $f1, 0x90($17)
    /* CDE7C 001CDE7C 2C0020C6 */  lwc1       $f0, 0x2C($17)
    /* CDE80 001CDE80 020D0046 */  mul.s      $f20, $f1, $f0
    /* CDE84 001CDE84 4000A427 */  addiu      $4, $29, 0x40
    /* CDE88 001CDE88 9C000526 */  addiu      $5, $16, 0x9C
    /* CDE8C 001CDE8C 58F5060C */  jal        func_001bd560
    /* CDE90 001CDE90 00000000 */   nop
    /* CDE94 001CDE94 2D202002 */  daddu      $4, $17, $0
    /* CDE98 001CDE98 D000A527 */  addiu      $5, $29, 0xD0
    /* CDE9C 001CDE9C 3C56060C */  jal        func_001958f0
    /* CDEA0 001CDEA0 00000000 */   nop
    /* CDEA4 001CDEA4 4000A1C7 */  lwc1       $f1, 0x40($29)
    /* CDEA8 001CDEA8 D000A0C7 */  lwc1       $f0, 0xD0($29)
    /* CDEAC 001CDEAC 01080046 */  sub.s      $f0, $f1, $f0
    /* CDEB0 001CDEB0 F000A0E7 */  swc1       $f0, 0xF0($29)
    /* CDEB4 001CDEB4 4400A1C7 */  lwc1       $f1, 0x44($29)
    /* CDEB8 001CDEB8 D400A0C7 */  lwc1       $f0, 0xD4($29)
    /* CDEBC 001CDEBC 01080046 */  sub.s      $f0, $f1, $f0
    /* CDEC0 001CDEC0 F400A0E7 */  swc1       $f0, 0xF4($29)
    /* CDEC4 001CDEC4 4800A1C7 */  lwc1       $f1, 0x48($29)
    /* CDEC8 001CDEC8 D800A0C7 */  lwc1       $f0, 0xD8($29)
    /* CDECC 001CDECC 01080046 */  sub.s      $f0, $f1, $f0
    /* CDED0 001CDED0 F800A0E7 */  swc1       $f0, 0xF8($29)
    /* CDED4 001CDED4 F000A427 */  addiu      $4, $29, 0xF0
    /* CDED8 001CDED8 60900F0C */  jal        func_003e4180
    /* CDEDC 001CDEDC 00000000 */   nop
    /* CDEE0 001CDEE0 003F023C */  lui        $2, (0x3F000000 >> 16)
    /* CDEE4 001CDEE4 00088244 */  mtc1       $2, $f1
    /* CDEE8 001CDEE8 00000000 */  nop
    /* CDEEC 001CDEEC 82050146 */  mul.s      $f22, $f0, $f1
    /* CDEF0 001CDEF0 B80000C6 */  lwc1       $f0, 0xB8($16)
    /* CDEF4 001CDEF4 020B0046 */  mul.s      $f12, $f1, $f0
    /* CDEF8 001CDEF8 1A2E110C */  jal        func_0044b868
    /* CDEFC 001CDEFC 00000000 */   nop
    /* CDF00 001CDF00 C03F023C */  lui        $2, (0x3FC00000 >> 16)
    /* CDF04 001CDF04 00088244 */  mtc1       $2, $f1
    /* CDF08 001CDF08 00000000 */  nop
    /* CDF0C 001CDF0C 42081446 */  mul.s      $f1, $f1, $f20
    /* CDF10 001CDF10 430D0046 */  div.s      $f21, $f1, $f0
    /* CDF14 001CDF14 F000A427 */  addiu      $4, $29, 0xF0
    /* CDF18 001CDF18 6100053C */  lui        $5, %hi(D_0060A0F0)
    /* CDF1C 001CDF1C F0A0A524 */  addiu      $5, $5, %lo(D_0060A0F0)
    /* CDF20 001CDF20 01000624 */  addiu      $6, $0, 0x1
    /* CDF24 001CDF24 1C002726 */  addiu      $7, $17, 0x1C
    /* CDF28 001CDF28 D0720F0C */  jal        func_003dcb40
    /* CDF2C 001CDF2C 00000000 */   nop
    /* CDF30 001CDF30 003F023C */  lui        $2, (0x3F000000 >> 16)
    /* CDF34 001CDF34 00008244 */  mtc1       $2, $f0
    /* CDF38 001CDF38 00000000 */  nop
    /* CDF3C 001CDF3C 02001446 */  mul.s      $f0, $f0, $f20
    /* CDF40 001CDF40 F000A8C7 */  lwc1       $f8, 0xF0($29)
    /* CDF44 001CDF44 C2400046 */  mul.s      $f3, $f8, $f0
    /* CDF48 001CDF48 0001A3E7 */  swc1       $f3, 0x100($29)
    /* CDF4C 001CDF4C F400A7C7 */  lwc1       $f7, 0xF4($29)
    /* CDF50 001CDF50 82380046 */  mul.s      $f2, $f7, $f0
    /* CDF54 001CDF54 0401A2E7 */  swc1       $f2, 0x104($29)
    /* CDF58 001CDF58 F800A6C7 */  lwc1       $f6, 0xF8($29)
    /* CDF5C 001CDF5C 42300046 */  mul.s      $f1, $f6, $f0
    /* CDF60 001CDF60 0801A1E7 */  swc1       $f1, 0x108($29)
    /* CDF64 001CDF64 D000A0C7 */  lwc1       $f0, 0xD0($29)
    /* CDF68 001CDF68 40010346 */  add.s      $f5, $f0, $f3
    /* CDF6C 001CDF6C E000A5E7 */  swc1       $f5, 0xE0($29)
    /* CDF70 001CDF70 D400A0C7 */  lwc1       $f0, 0xD4($29)
    /* CDF74 001CDF74 C0000246 */  add.s      $f3, $f0, $f2
    /* CDF78 001CDF78 E400A3E7 */  swc1       $f3, 0xE4($29)
    /* CDF7C 001CDF7C D800A0C7 */  lwc1       $f0, 0xD8($29)
    /* CDF80 001CDF80 00010146 */  add.s      $f4, $f0, $f1
    /* CDF84 001CDF84 E800A4E7 */  swc1       $f4, 0xE8($29)
    /* CDF88 001CDF88 02401546 */  mul.s      $f0, $f8, $f21
    /* CDF8C 001CDF8C 0001A0E7 */  swc1       $f0, 0x100($29)
    /* CDF90 001CDF90 82381546 */  mul.s      $f2, $f7, $f21
    /* CDF94 001CDF94 0401A2E7 */  swc1       $f2, 0x104($29)
    /* CDF98 001CDF98 42301546 */  mul.s      $f1, $f6, $f21
    /* CDF9C 001CDF9C 0801A1E7 */  swc1       $f1, 0x108($29)
    /* CDFA0 001CDFA0 00000546 */  add.s      $f0, $f0, $f5
    /* CDFA4 001CDFA4 0001A0E7 */  swc1       $f0, 0x100($29)
    /* CDFA8 001CDFA8 C0100346 */  add.s      $f3, $f2, $f3
    /* CDFAC 001CDFAC 0401A3E7 */  swc1       $f3, 0x104($29)
    /* CDFB0 001CDFB0 00080446 */  add.s      $f0, $f1, $f4
    /* CDFB4 001CDFB4 0801A0E7 */  swc1       $f0, 0x108($29)
    /* CDFB8 001CDFB8 8C0021C6 */  lwc1       $f1, 0x8C($17)
    /* CDFBC 001CDFBC 2C0020C6 */  lwc1       $f0, 0x2C($17)
    /* CDFC0 001CDFC0 82080046 */  mul.s      $f2, $f1, $f0
    /* CDFC4 001CDFC4 1C8181C7 */  lwc1       $f1, -0x7EE4($28)
    /* CDFC8 001CDFC8 00008044 */  mtc1       $0, $f0
    /* CDFCC 001CDFCC 00000000 */  nop
    /* CDFD0 001CDFD0 18000346 */  adda.s     $f0, $f3
    /* CDFD4 001CDFD4 1C080246 */  madd.s     $f0, $f1, $f2
    /* CDFD8 001CDFD8 0401A0E7 */  swc1       $f0, 0x104($29)
    /* CDFDC 001CDFDC 6800A427 */  addiu      $4, $29, 0x68
    /* CDFE0 001CDFE0 0001A527 */  addiu      $5, $29, 0x100
    /* CDFE4 001CDFE4 E000A627 */  addiu      $6, $29, 0xE0
    /* CDFE8 001CDFE8 6100073C */  lui        $7, %hi(D_0060A0E0)
    /* CDFEC 001CDFEC E0A0E724 */  addiu      $7, $7, %lo(D_0060A0E0)
    /* CDFF0 001CDFF0 E0F5060C */  jal        func_001bd780
    /* CDFF4 001CDFF4 00000000 */   nop
    /* CDFF8 001CDFF8 4C00A427 */  addiu      $4, $29, 0x4C
    /* CDFFC 001CDFFC 6800A527 */  addiu      $5, $29, 0x68
    /* CE000 001CE000 ACB0070C */  jal        func_001ec2b0
    /* CE004 001CE004 00000000 */   nop
    /* CE008 001CE008 DC8081C7 */  lwc1       $f1, -0x7F24($28)
    /* CE00C 001CE00C 36000146 */  c.le.s     $f0, $f1
    /* CE010 001CE010 87000145 */  bc1t       .L001CE230
    /* CE014 001CE014 00000000 */   nop
    /* CE018 001CE018 00000000 */  nop
    /* CE01C 001CE01C 00000000 */  nop
    /* CE020 001CE020 030D0046 */  div.s      $f20, $f1, $f0
    /* CE024 001CE024 4C00A427 */  addiu      $4, $29, 0x4C
    /* CE028 001CE028 6800A527 */  addiu      $5, $29, 0x68
    /* CE02C 001CE02C 8000A627 */  addiu      $6, $29, 0x80
    /* CE030 001CE030 1C730F0C */  jal        func_003dcc70
    /* CE034 001CE034 00000000 */   nop
    /* CE038 001CE038 00588044 */  mtc1       $0, $f11
    /* CE03C 001CE03C 00000000 */  nop
    /* CE040 001CE040 36A00B46 */  c.le.s     $f20, $f11
    /* CE044 001CE044 0B000045 */  bc1f       .L001CE074
    /* CE048 001CE048 00000000 */   nop
    /* CE04C 001CE04C 4C00A3C7 */  lwc1       $f3, 0x4C($29)
    /* CE050 001CE050 5000A2C7 */  lwc1       $f2, 0x50($29)
    /* CE054 001CE054 5400A1C7 */  lwc1       $f1, 0x54($29)
    /* CE058 001CE058 5800A0C7 */  lwc1       $f0, 0x58($29)
    /* CE05C 001CE05C B000A3E7 */  swc1       $f3, 0xB0($29)
    /* CE060 001CE060 B400A2E7 */  swc1       $f2, 0xB4($29)
    /* CE064 001CE064 B800A1E7 */  swc1       $f1, 0xB8($29)
    /* CE068 001CE068 BC00A0E7 */  swc1       $f0, 0xBC($29)
    /* CE06C 001CE06C 56000010 */  b          .L001CE1C8
    /* CE070 001CE070 00000000 */   nop
  .L001CE074:
    /* CE074 001CE074 803F023C */  lui        $2, (0x3F800000 >> 16)
    /* CE078 001CE078 00008244 */  mtc1       $2, $f0
    /* CE07C 001CE07C 00000000 */  nop
    /* CE080 001CE080 36001446 */  c.le.s     $f0, $f20
    /* CE084 001CE084 0B000045 */  bc1f       .L001CE0B4
    /* CE088 001CE088 00000000 */   nop
    /* CE08C 001CE08C 6800A3C7 */  lwc1       $f3, 0x68($29)
    /* CE090 001CE090 6C00A2C7 */  lwc1       $f2, 0x6C($29)
    /* CE094 001CE094 7000A1C7 */  lwc1       $f1, 0x70($29)
    /* CE098 001CE098 7400A0C7 */  lwc1       $f0, 0x74($29)
    /* CE09C 001CE09C B000A3E7 */  swc1       $f3, 0xB0($29)
    /* CE0A0 001CE0A0 B400A2E7 */  swc1       $f2, 0xB4($29)
    /* CE0A4 001CE0A4 B800A1E7 */  swc1       $f1, 0xB8($29)
    /* CE0A8 001CE0A8 BC00A0E7 */  swc1       $f0, 0xBC($29)
    /* CE0AC 001CE0AC 46000010 */  b          .L001CE1C8
    /* CE0B0 001CE0B0 00000000 */   nop
  .L001CE0B4:
    /* CE0B4 001CE0B4 01001446 */  sub.s      $f0, $f0, $f20
    /* CE0B8 001CE0B8 A400A28F */  lw         $2, 0xA4($29)
    /* CE0BC 001CE0BC 26004014 */  bnez       $2, .L001CE158
    /* CE0C0 001CE0C0 00000000 */   nop
    /* CE0C4 001CE0C4 A000AAC7 */  lwc1       $f10, 0xA0($29)
    /* CE0C8 001CE0C8 02010A46 */  mul.s      $f4, $f0, $f10
    /* CE0CC 001CE0CC C2200446 */  mul.s      $f3, $f4, $f4
    /* CE0D0 001CE0D0 948189C7 */  lwc1       $f9, -0x7E6C($28)
    /* CE0D4 001CE0D4 548088C7 */  lwc1       $f8, -0x7FAC($28)
    /* CE0D8 001CE0D8 18580846 */  adda.s     $f11, $f8
    /* CE0DC 001CE0DC 1C480346 */  madd.s     $f0, $f9, $f3
    /* CE0E0 001CE0E0 588087C7 */  lwc1       $f7, -0x7FA8($28)
    /* CE0E4 001CE0E4 18580746 */  adda.s     $f11, $f7
    /* CE0E8 001CE0E8 1C180046 */  madd.s     $f0, $f3, $f0
    /* CE0EC 001CE0EC 5C8086C7 */  lwc1       $f6, -0x7FA4($28)
    /* CE0F0 001CE0F0 18580646 */  adda.s     $f11, $f6
    /* CE0F4 001CE0F4 1C180046 */  madd.s     $f0, $f3, $f0
    /* CE0F8 001CE0F8 608085C7 */  lwc1       $f5, -0x7FA0($28)
    /* CE0FC 001CE0FC 18580546 */  adda.s     $f11, $f5
    /* CE100 001CE100 1C180046 */  madd.s     $f0, $f3, $f0
    /* CE104 001CE104 088182C7 */  lwc1       $f2, -0x7EF8($28)
    /* CE108 001CE108 18580246 */  adda.s     $f11, $f2
    /* CE10C 001CE10C 5C180046 */  madd.s     $f1, $f3, $f0
    /* CE110 001CE110 02180446 */  mul.s      $f0, $f3, $f4
    /* CE114 001CE114 18580446 */  adda.s     $f11, $f4
    /* CE118 001CE118 1C000146 */  madd.s     $f0, $f0, $f1
    /* CE11C 001CE11C 02A10A46 */  mul.s      $f4, $f20, $f10
    /* CE120 001CE120 C2200446 */  mul.s      $f3, $f4, $f4
    /* CE124 001CE124 18580846 */  adda.s     $f11, $f8
    /* CE128 001CE128 5C480346 */  madd.s     $f1, $f9, $f3
    /* CE12C 001CE12C 18580746 */  adda.s     $f11, $f7
    /* CE130 001CE130 5C180146 */  madd.s     $f1, $f3, $f1
    /* CE134 001CE134 18580646 */  adda.s     $f11, $f6
    /* CE138 001CE138 5C180146 */  madd.s     $f1, $f3, $f1
    /* CE13C 001CE13C 18580546 */  adda.s     $f11, $f5
    /* CE140 001CE140 5C180146 */  madd.s     $f1, $f3, $f1
    /* CE144 001CE144 18580246 */  adda.s     $f11, $f2
    /* CE148 001CE148 9C180146 */  madd.s     $f2, $f3, $f1
    /* CE14C 001CE14C 42180446 */  mul.s      $f1, $f3, $f4
    /* CE150 001CE150 18580446 */  adda.s     $f11, $f4
    /* CE154 001CE154 1C0D0246 */  madd.s     $f20, $f1, $f2
  .L001CE158:
    /* CE158 001CE158 8000A1C7 */  lwc1       $f1, 0x80($29)
    /* CE15C 001CE15C 42090046 */  mul.s      $f5, $f1, $f0
    /* CE160 001CE160 B000A5E7 */  swc1       $f5, 0xB0($29)
    /* CE164 001CE164 8400A1C7 */  lwc1       $f1, 0x84($29)
    /* CE168 001CE168 02090046 */  mul.s      $f4, $f1, $f0
    /* CE16C 001CE16C B400A4E7 */  swc1       $f4, 0xB4($29)
    /* CE170 001CE170 8800A1C7 */  lwc1       $f1, 0x88($29)
    /* CE174 001CE174 C2080046 */  mul.s      $f3, $f1, $f0
    /* CE178 001CE178 B800A3E7 */  swc1       $f3, 0xB8($29)
    /* CE17C 001CE17C 9000A1C7 */  lwc1       $f1, 0x90($29)
    /* CE180 001CE180 00108044 */  mtc1       $0, $f2
    /* CE184 001CE184 00000000 */  nop
    /* CE188 001CE188 18100546 */  adda.s     $f2, $f5
    /* CE18C 001CE18C 5C081446 */  madd.s     $f1, $f1, $f20
    /* CE190 001CE190 B000A1E7 */  swc1       $f1, 0xB0($29)
    /* CE194 001CE194 9400A1C7 */  lwc1       $f1, 0x94($29)
    /* CE198 001CE198 18100446 */  adda.s     $f2, $f4
    /* CE19C 001CE19C 5C081446 */  madd.s     $f1, $f1, $f20
    /* CE1A0 001CE1A0 B400A1E7 */  swc1       $f1, 0xB4($29)
    /* CE1A4 001CE1A4 9800A1C7 */  lwc1       $f1, 0x98($29)
    /* CE1A8 001CE1A8 18100346 */  adda.s     $f2, $f3
    /* CE1AC 001CE1AC 5C081446 */  madd.s     $f1, $f1, $f20
    /* CE1B0 001CE1B0 B800A1E7 */  swc1       $f1, 0xB8($29)
    /* CE1B4 001CE1B4 8C00A2C7 */  lwc1       $f2, 0x8C($29)
    /* CE1B8 001CE1B8 9C00A1C7 */  lwc1       $f1, 0x9C($29)
    /* CE1BC 001CE1BC 1A081446 */  mula.s     $f1, $f20
    /* CE1C0 001CE1C0 1C100046 */  madd.s     $f0, $f2, $f0
    /* CE1C4 001CE1C4 BC00A0E7 */  swc1       $f0, 0xBC($29)
  .L001CE1C8:
    /* CE1C8 001CE1C8 F000A427 */  addiu      $4, $29, 0xF0
    /* CE1CC 001CE1CC 6100053C */  lui        $5, %hi(D_0060A100)
    /* CE1D0 001CE1D0 00A1A524 */  addiu      $5, $5, %lo(D_0060A100)
    /* CE1D4 001CE1D4 01000624 */  addiu      $6, $0, 0x1
    /* CE1D8 001CE1D8 B000A727 */  addiu      $7, $29, 0xB0
    /* CE1DC 001CE1DC D0720F0C */  jal        func_003dcb40
    /* CE1E0 001CE1E0 00000000 */   nop
    /* CE1E4 001CE1E4 E000A1C7 */  lwc1       $f1, 0xE0($29)
    /* CE1E8 001CE1E8 F000A0C7 */  lwc1       $f0, 0xF0($29)
    /* CE1EC 001CE1EC 00080046 */  add.s      $f0, $f1, $f0
    /* CE1F0 001CE1F0 0001A0E7 */  swc1       $f0, 0x100($29)
    /* CE1F4 001CE1F4 E400A1C7 */  lwc1       $f1, 0xE4($29)
    /* CE1F8 001CE1F8 F400A0C7 */  lwc1       $f0, 0xF4($29)
    /* CE1FC 001CE1FC 00080046 */  add.s      $f0, $f1, $f0
    /* CE200 001CE200 0401A0E7 */  swc1       $f0, 0x104($29)
    /* CE204 001CE204 E800A1C7 */  lwc1       $f1, 0xE8($29)
    /* CE208 001CE208 F800A0C7 */  lwc1       $f0, 0xF8($29)
    /* CE20C 001CE20C 00080046 */  add.s      $f0, $f1, $f0
    /* CE210 001CE210 0801A0E7 */  swc1       $f0, 0x108($29)
    /* CE214 001CE214 6800A427 */  addiu      $4, $29, 0x68
    /* CE218 001CE218 0001A527 */  addiu      $5, $29, 0x100
    /* CE21C 001CE21C E000A627 */  addiu      $6, $29, 0xE0
    /* CE220 001CE220 6100073C */  lui        $7, %hi(D_0060A0E0)
    /* CE224 001CE224 E0A0E724 */  addiu      $7, $7, %lo(D_0060A0E0)
    /* CE228 001CE228 E0F5060C */  jal        func_001bd780
    /* CE22C 001CE22C 00000000 */   nop
  .L001CE230:
    /* CE230 001CE230 1644023C */  lui        $2, (0x44160000 >> 16)
    /* CE234 001CE234 00008244 */  mtc1       $2, $f0
    /* CE238 001CE238 00000000 */  nop
    /* CE23C 001CE23C 34B00046 */  c.lt.s     $f22, $f0
    /* CE240 001CE240 02000045 */  bc1f       .L001CE24C
    /* CE244 001CE244 00000000 */   nop
    /* CE248 001CE248 86050046 */  mov.s      $f22, $f0
  .L001CE24C:
    /* CE24C 001CE24C F000A427 */  addiu      $4, $29, 0xF0
    /* CE250 001CE250 6100053C */  lui        $5, %hi(D_0060A100)
    /* CE254 001CE254 00A1A524 */  addiu      $5, $5, %lo(D_0060A100)
    /* CE258 001CE258 01000624 */  addiu      $6, $0, 0x1
    /* CE25C 001CE25C 6800A727 */  addiu      $7, $29, 0x68
    /* CE260 001CE260 D0720F0C */  jal        func_003dcb40
    /* CE264 001CE264 00000000 */   nop
    /* CE268 001CE268 F000A0C7 */  lwc1       $f0, 0xF0($29)
    /* CE26C 001CE26C 02001646 */  mul.s      $f0, $f0, $f22
    /* CE270 001CE270 F000A0E7 */  swc1       $f0, 0xF0($29)
    /* CE274 001CE274 F400A0C7 */  lwc1       $f0, 0xF4($29)
    /* CE278 001CE278 02001646 */  mul.s      $f0, $f0, $f22
    /* CE27C 001CE27C F400A0E7 */  swc1       $f0, 0xF4($29)
    /* CE280 001CE280 F800A0C7 */  lwc1       $f0, 0xF8($29)
    /* CE284 001CE284 02001646 */  mul.s      $f0, $f0, $f22
    /* CE288 001CE288 F800A0E7 */  swc1       $f0, 0xF8($29)
    /* CE28C 001CE28C 003F023C */  lui        $2, (0x3F000000 >> 16)
    /* CE290 001CE290 00088244 */  mtc1       $2, $f1
    /* CE294 001CE294 B80000C6 */  lwc1       $f0, 0xB8($16)
    /* CE298 001CE298 42080046 */  mul.s      $f1, $f1, $f0
    /* CE29C 001CE29C 108180C7 */  lwc1       $f0, -0x7EF0($28)
    /* CE2A0 001CE2A0 02030146 */  mul.s      $f12, $f0, $f1
    /* CE2A4 001CE2A4 1A2E110C */  jal        func_0044b868
    /* CE2A8 001CE2A8 00000000 */   nop
    /* CE2AC 001CE2AC 42B00046 */  mul.s      $f1, $f22, $f0
    /* CE2B0 001CE2B0 603E023C */  lui        $2, (0x3E600000 >> 16)
    /* CE2B4 001CE2B4 00008244 */  mtc1       $2, $f0
    /* CE2B8 001CE2B8 00000000 */  nop
    /* CE2BC 001CE2BC 020D0046 */  mul.s      $f20, $f1, $f0
    /* CE2C0 001CE2C0 F000A0C7 */  lwc1       $f0, 0xF0($29)
    /* CE2C4 001CE2C4 C800A0E7 */  swc1       $f0, 0xC8($29)
    /* CE2C8 001CE2C8 F800A0C7 */  lwc1       $f0, 0xF8($29)
    /* CE2CC 001CE2CC CC00A0E7 */  swc1       $f0, 0xCC($29)
    /* CE2D0 001CE2D0 C800A427 */  addiu      $4, $29, 0xC8
    /* CE2D4 001CE2D4 2D288000 */  daddu      $5, $4, $0
    /* CE2D8 001CE2D8 78900F0C */  jal        func_003e41e0
    /* CE2DC 001CE2DC 00000000 */   nop
    /* CE2E0 001CE2E0 CC00A1C7 */  lwc1       $f1, 0xCC($29)
    /* CE2E4 001CE2E4 E000A0C7 */  lwc1       $f0, 0xE0($29)
    /* CE2E8 001CE2E8 00108044 */  mtc1       $0, $f2
    /* CE2EC 001CE2EC 00000000 */  nop
    /* CE2F0 001CE2F0 18100046 */  adda.s     $f2, $f0
    /* CE2F4 001CE2F4 DC081446 */  madd.s     $f3, $f1, $f20
    /* CE2F8 001CE2F8 E000A3E7 */  swc1       $f3, 0xE0($29)
    /* CE2FC 001CE2FC C800A1C7 */  lwc1       $f1, 0xC8($29)
    /* CE300 001CE300 E800A0C7 */  lwc1       $f0, 0xE8($29)
    /* CE304 001CE304 18100046 */  adda.s     $f2, $f0
    /* CE308 001CE308 9D081446 */  msub.s     $f2, $f1, $f20
    /* CE30C 001CE30C E800A2E7 */  swc1       $f2, 0xE8($29)
    /* CE310 001CE310 F000A0C7 */  lwc1       $f0, 0xF0($29)
    /* CE314 001CE314 00180046 */  add.s      $f0, $f3, $f0
    /* CE318 001CE318 5C00A0E7 */  swc1       $f0, 0x5C($29)
    /* CE31C 001CE31C E400A1C7 */  lwc1       $f1, 0xE4($29)
    /* CE320 001CE320 F400A0C7 */  lwc1       $f0, 0xF4($29)
    /* CE324 001CE324 00080046 */  add.s      $f0, $f1, $f0
    /* CE328 001CE328 6000A0E7 */  swc1       $f0, 0x60($29)
    /* CE32C 001CE32C F800A0C7 */  lwc1       $f0, 0xF8($29)
    /* CE330 001CE330 00100046 */  add.s      $f0, $f2, $f0
    /* CE334 001CE334 6400A0E7 */  swc1       $f0, 0x64($29)
    /* CE338 001CE338 2D200002 */  daddu      $4, $16, $0
    /* CE33C 001CE33C 4000A527 */  addiu      $5, $29, 0x40
    /* CE340 001CE340 5C00A627 */  addiu      $6, $29, 0x5C
    /* CE344 001CE344 01000724 */  addiu      $7, $0, 0x1
    /* CE348 001CE348 08EB060C */  jal        func_001bac20
    /* CE34C 001CE34C 00000000 */   nop
    /* CE350 001CE350 A03F023C */  lui        $2, (0x3FA00000 >> 16)
    /* CE354 001CE354 00608244 */  mtc1       $2, $f12
    /* CE358 001CE358 2D200002 */  daddu      $4, $16, $0
    /* CE35C 001CE35C BCEF060C */  jal        func_001bbef0
    /* CE360 001CE360 00000000 */   nop
    /* CE364 001CE364 3000BFDF */  ld         $31, 0x30($29)
    /* CE368 001CE368 2000B17B */  lq         $17, 0x20($29)
    /* CE36C 001CE36C 1000B07B */  lq         $16, 0x10($29)
    /* CE370 001CE370 0800B6C7 */  lwc1       $f22, 0x8($29)
    /* CE374 001CE374 0400B5C7 */  lwc1       $f21, 0x4($29)
    /* CE378 001CE378 0000B4C7 */  lwc1       $f20, 0x0($29)
    /* CE37C 001CE37C 1001BD27 */  addiu      $29, $29, 0x110
    /* CE380 001CE380 0800E003 */  jr         $31
    /* CE384 001CE384 00000000 */   nop
    /* CE388 001CE388 00000000 */  nop
    /* CE38C 001CE38C 00000000 */  nop
.size func_001cde50, 0x540
