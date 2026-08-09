.section .text
.set noat
.set noreorder
glabel func_001c09b0
    /* C09B0 001C09B0 10FFBD27 */  addiu      $29, $29, -0xF0
    /* C09B4 001C09B4 3000BFFF */  sd         $31, 0x30($29)
    /* C09B8 001C09B8 2000B17F */  sq         $17, 0x20($29)
    /* C09BC 001C09BC 1000B07F */  sq         $16, 0x10($29)
    /* C09C0 001C09C0 0000B4E7 */  swc1       $f20, 0x0($29)
    /* C09C4 001C09C4 2D808000 */  daddu      $16, $4, $0
    /* C09C8 001C09C8 E000828C */  lw         $2, 0xE0($4)
    /* C09CC 001C09CC 3000518C */  lw         $17, 0x30($2)
    /* C09D0 001C09D0 4000A427 */  addiu      $4, $29, 0x40
    /* C09D4 001C09D4 9C000526 */  addiu      $5, $16, 0x9C
    /* C09D8 001C09D8 58F5060C */  jal        func_001bd560
    /* C09DC 001C09DC 00000000 */   nop
    /* C09E0 001C09E0 2D202002 */  daddu      $4, $17, $0
    /* C09E4 001C09E4 C800A527 */  addiu      $5, $29, 0xC8
    /* C09E8 001C09E8 2D300000 */  daddu      $6, $0, $0
    /* C09EC 001C09EC 2D380000 */  daddu      $7, $0, $0
    /* C09F0 001C09F0 FC53060C */  jal        func_00194ff0
    /* C09F4 001C09F4 00000000 */   nop
    /* C09F8 001C09F8 2C0021C6 */  lwc1       $f1, 0x2C($17)
    /* C09FC 001C09FC 840020C6 */  lwc1       $f0, 0x84($17)
    /* C0A00 001C0A00 1A000146 */  mula.s     $f0, $f1
    /* C0A04 001C0A04 8C0020C6 */  lwc1       $f0, 0x8C($17)
    /* C0A08 001C0A08 42000146 */  mul.s      $f1, $f0, $f1
    /* C0A0C 001C0A0C 188180C7 */  lwc1       $f0, -0x7EE8($28)
    /* C0A10 001C0A10 5C000146 */  madd.s     $f1, $f0, $f1
    /* C0A14 001C0A14 CC00A1E7 */  swc1       $f1, 0xCC($29)
    /* C0A18 001C0A18 D800A527 */  addiu      $5, $29, 0xD8
    /* C0A1C 001C0A1C 4000A2DF */  ld         $2, 0x40($29)
    /* C0A20 001C0A20 4800A0C7 */  lwc1       $f0, 0x48($29)
    /* C0A24 001C0A24 D800A2FF */  sd         $2, 0xD8($29)
    /* C0A28 001C0A28 E000A0E7 */  swc1       $f0, 0xE0($29)
    /* C0A2C 001C0A2C DC00A1E7 */  swc1       $f1, 0xDC($29)
    /* C0A30 001C0A30 6800A427 */  addiu      $4, $29, 0x68
    /* C0A34 001C0A34 C800A627 */  addiu      $6, $29, 0xC8
    /* C0A38 001C0A38 6100073C */  lui        $7, %hi(D_0060A0E0)
    /* C0A3C 001C0A3C E0A0E724 */  addiu      $7, $7, %lo(D_0060A0E0)
    /* C0A40 001C0A40 E0F5060C */  jal        func_001bd780
    /* C0A44 001C0A44 00000000 */   nop
    /* C0A48 001C0A48 4C00A427 */  addiu      $4, $29, 0x4C
    /* C0A4C 001C0A4C 6800A527 */  addiu      $5, $29, 0x68
    /* C0A50 001C0A50 ACB0070C */  jal        func_001ec2b0
    /* C0A54 001C0A54 00000000 */   nop
    /* C0A58 001C0A58 5C8181C7 */  lwc1       $f1, -0x7EA4($28)
    /* C0A5C 001C0A5C 36000146 */  c.le.s     $f0, $f1
    /* C0A60 001C0A60 89000145 */  bc1t       .L001C0C88
    /* C0A64 001C0A64 00000000 */   nop
    /* C0A68 001C0A68 00000000 */  nop
    /* C0A6C 001C0A6C 00000000 */  nop
    /* C0A70 001C0A70 030D0046 */  div.s      $f20, $f1, $f0
    /* C0A74 001C0A74 4C00A427 */  addiu      $4, $29, 0x4C
    /* C0A78 001C0A78 6800A527 */  addiu      $5, $29, 0x68
    /* C0A7C 001C0A7C 8000A627 */  addiu      $6, $29, 0x80
    /* C0A80 001C0A80 1C730F0C */  jal        func_003dcc70
    /* C0A84 001C0A84 00000000 */   nop
    /* C0A88 001C0A88 00588044 */  mtc1       $0, $f11
    /* C0A8C 001C0A8C 00000000 */  nop
    /* C0A90 001C0A90 36A00B46 */  c.le.s     $f20, $f11
    /* C0A94 001C0A94 0B000045 */  bc1f       .L001C0AC4
    /* C0A98 001C0A98 00000000 */   nop
    /* C0A9C 001C0A9C 4C00A3C7 */  lwc1       $f3, 0x4C($29)
    /* C0AA0 001C0AA0 5000A2C7 */  lwc1       $f2, 0x50($29)
    /* C0AA4 001C0AA4 5400A1C7 */  lwc1       $f1, 0x54($29)
    /* C0AA8 001C0AA8 5800A0C7 */  lwc1       $f0, 0x58($29)
    /* C0AAC 001C0AAC B000A3E7 */  swc1       $f3, 0xB0($29)
    /* C0AB0 001C0AB0 B400A2E7 */  swc1       $f2, 0xB4($29)
    /* C0AB4 001C0AB4 B800A1E7 */  swc1       $f1, 0xB8($29)
    /* C0AB8 001C0AB8 BC00A0E7 */  swc1       $f0, 0xBC($29)
    /* C0ABC 001C0ABC 56000010 */  b          .L001C0C18
    /* C0AC0 001C0AC0 00000000 */   nop
  .L001C0AC4:
    /* C0AC4 001C0AC4 803F023C */  lui        $2, (0x3F800000 >> 16)
    /* C0AC8 001C0AC8 00008244 */  mtc1       $2, $f0
    /* C0ACC 001C0ACC 00000000 */  nop
    /* C0AD0 001C0AD0 36001446 */  c.le.s     $f0, $f20
    /* C0AD4 001C0AD4 0B000045 */  bc1f       .L001C0B04
    /* C0AD8 001C0AD8 00000000 */   nop
    /* C0ADC 001C0ADC 6800A3C7 */  lwc1       $f3, 0x68($29)
    /* C0AE0 001C0AE0 6C00A2C7 */  lwc1       $f2, 0x6C($29)
    /* C0AE4 001C0AE4 7000A1C7 */  lwc1       $f1, 0x70($29)
    /* C0AE8 001C0AE8 7400A0C7 */  lwc1       $f0, 0x74($29)
    /* C0AEC 001C0AEC B000A3E7 */  swc1       $f3, 0xB0($29)
    /* C0AF0 001C0AF0 B400A2E7 */  swc1       $f2, 0xB4($29)
    /* C0AF4 001C0AF4 B800A1E7 */  swc1       $f1, 0xB8($29)
    /* C0AF8 001C0AF8 BC00A0E7 */  swc1       $f0, 0xBC($29)
    /* C0AFC 001C0AFC 46000010 */  b          .L001C0C18
    /* C0B00 001C0B00 00000000 */   nop
  .L001C0B04:
    /* C0B04 001C0B04 01001446 */  sub.s      $f0, $f0, $f20
    /* C0B08 001C0B08 A400A28F */  lw         $2, 0xA4($29)
    /* C0B0C 001C0B0C 26004014 */  bnez       $2, .L001C0BA8
    /* C0B10 001C0B10 00000000 */   nop
    /* C0B14 001C0B14 A000AAC7 */  lwc1       $f10, 0xA0($29)
    /* C0B18 001C0B18 02010A46 */  mul.s      $f4, $f0, $f10
    /* C0B1C 001C0B1C C2200446 */  mul.s      $f3, $f4, $f4
    /* C0B20 001C0B20 808189C7 */  lwc1       $f9, -0x7E80($28)
    /* C0B24 001C0B24 548088C7 */  lwc1       $f8, -0x7FAC($28)
    /* C0B28 001C0B28 18580846 */  adda.s     $f11, $f8
    /* C0B2C 001C0B2C 1C480346 */  madd.s     $f0, $f9, $f3
    /* C0B30 001C0B30 588087C7 */  lwc1       $f7, -0x7FA8($28)
    /* C0B34 001C0B34 18580746 */  adda.s     $f11, $f7
    /* C0B38 001C0B38 1C180046 */  madd.s     $f0, $f3, $f0
    /* C0B3C 001C0B3C 5C8086C7 */  lwc1       $f6, -0x7FA4($28)
    /* C0B40 001C0B40 18580646 */  adda.s     $f11, $f6
    /* C0B44 001C0B44 1C180046 */  madd.s     $f0, $f3, $f0
    /* C0B48 001C0B48 608085C7 */  lwc1       $f5, -0x7FA0($28)
    /* C0B4C 001C0B4C 18580546 */  adda.s     $f11, $f5
    /* C0B50 001C0B50 1C180046 */  madd.s     $f0, $f3, $f0
    /* C0B54 001C0B54 088182C7 */  lwc1       $f2, -0x7EF8($28)
    /* C0B58 001C0B58 18580246 */  adda.s     $f11, $f2
    /* C0B5C 001C0B5C 5C180046 */  madd.s     $f1, $f3, $f0
    /* C0B60 001C0B60 02180446 */  mul.s      $f0, $f3, $f4
    /* C0B64 001C0B64 18580446 */  adda.s     $f11, $f4
    /* C0B68 001C0B68 1C000146 */  madd.s     $f0, $f0, $f1
    /* C0B6C 001C0B6C 02A10A46 */  mul.s      $f4, $f20, $f10
    /* C0B70 001C0B70 C2200446 */  mul.s      $f3, $f4, $f4
    /* C0B74 001C0B74 18580846 */  adda.s     $f11, $f8
    /* C0B78 001C0B78 5C480346 */  madd.s     $f1, $f9, $f3
    /* C0B7C 001C0B7C 18580746 */  adda.s     $f11, $f7
    /* C0B80 001C0B80 5C180146 */  madd.s     $f1, $f3, $f1
    /* C0B84 001C0B84 18580646 */  adda.s     $f11, $f6
    /* C0B88 001C0B88 5C180146 */  madd.s     $f1, $f3, $f1
    /* C0B8C 001C0B8C 18580546 */  adda.s     $f11, $f5
    /* C0B90 001C0B90 5C180146 */  madd.s     $f1, $f3, $f1
    /* C0B94 001C0B94 18580246 */  adda.s     $f11, $f2
    /* C0B98 001C0B98 9C180146 */  madd.s     $f2, $f3, $f1
    /* C0B9C 001C0B9C 42180446 */  mul.s      $f1, $f3, $f4
    /* C0BA0 001C0BA0 18580446 */  adda.s     $f11, $f4
    /* C0BA4 001C0BA4 1C0D0246 */  madd.s     $f20, $f1, $f2
  .L001C0BA8:
    /* C0BA8 001C0BA8 8000A1C7 */  lwc1       $f1, 0x80($29)
    /* C0BAC 001C0BAC 42090046 */  mul.s      $f5, $f1, $f0
    /* C0BB0 001C0BB0 B000A5E7 */  swc1       $f5, 0xB0($29)
    /* C0BB4 001C0BB4 8400A1C7 */  lwc1       $f1, 0x84($29)
    /* C0BB8 001C0BB8 02090046 */  mul.s      $f4, $f1, $f0
    /* C0BBC 001C0BBC B400A4E7 */  swc1       $f4, 0xB4($29)
    /* C0BC0 001C0BC0 8800A1C7 */  lwc1       $f1, 0x88($29)
    /* C0BC4 001C0BC4 C2080046 */  mul.s      $f3, $f1, $f0
    /* C0BC8 001C0BC8 B800A3E7 */  swc1       $f3, 0xB8($29)
    /* C0BCC 001C0BCC 9000A1C7 */  lwc1       $f1, 0x90($29)
    /* C0BD0 001C0BD0 00108044 */  mtc1       $0, $f2
    /* C0BD4 001C0BD4 00000000 */  nop
    /* C0BD8 001C0BD8 18100546 */  adda.s     $f2, $f5
    /* C0BDC 001C0BDC 5C081446 */  madd.s     $f1, $f1, $f20
    /* C0BE0 001C0BE0 B000A1E7 */  swc1       $f1, 0xB0($29)
    /* C0BE4 001C0BE4 9400A1C7 */  lwc1       $f1, 0x94($29)
    /* C0BE8 001C0BE8 18100446 */  adda.s     $f2, $f4
    /* C0BEC 001C0BEC 5C081446 */  madd.s     $f1, $f1, $f20
    /* C0BF0 001C0BF0 B400A1E7 */  swc1       $f1, 0xB4($29)
    /* C0BF4 001C0BF4 9800A1C7 */  lwc1       $f1, 0x98($29)
    /* C0BF8 001C0BF8 18100346 */  adda.s     $f2, $f3
    /* C0BFC 001C0BFC 5C081446 */  madd.s     $f1, $f1, $f20
    /* C0C00 001C0C00 B800A1E7 */  swc1       $f1, 0xB8($29)
    /* C0C04 001C0C04 8C00A2C7 */  lwc1       $f2, 0x8C($29)
    /* C0C08 001C0C08 9C00A1C7 */  lwc1       $f1, 0x9C($29)
    /* C0C0C 001C0C0C 1A081446 */  mula.s     $f1, $f20
    /* C0C10 001C0C10 1C100046 */  madd.s     $f0, $f2, $f0
    /* C0C14 001C0C14 BC00A0E7 */  swc1       $f0, 0xBC($29)
  .L001C0C18:
    /* C0C18 001C0C18 D800A427 */  addiu      $4, $29, 0xD8
    /* C0C1C 001C0C1C 6100053C */  lui        $5, %hi(D_0060A100)
    /* C0C20 001C0C20 00A1A524 */  addiu      $5, $5, %lo(D_0060A100)
    /* C0C24 001C0C24 01000624 */  addiu      $6, $0, 0x1
    /* C0C28 001C0C28 B000A727 */  addiu      $7, $29, 0xB0
    /* C0C2C 001C0C2C D0720F0C */  jal        func_003dcb40
    /* C0C30 001C0C30 00000000 */   nop
    /* C0C34 001C0C34 D800A1C7 */  lwc1       $f1, 0xD8($29)
    /* C0C38 001C0C38 C800A0C7 */  lwc1       $f0, 0xC8($29)
    /* C0C3C 001C0C3C 00080046 */  add.s      $f0, $f1, $f0
    /* C0C40 001C0C40 D800A0E7 */  swc1       $f0, 0xD8($29)
    /* C0C44 001C0C44 DC00A1C7 */  lwc1       $f1, 0xDC($29)
    /* C0C48 001C0C48 CC00A0C7 */  lwc1       $f0, 0xCC($29)
    /* C0C4C 001C0C4C 00080046 */  add.s      $f0, $f1, $f0
    /* C0C50 001C0C50 DC00A0E7 */  swc1       $f0, 0xDC($29)
    /* C0C54 001C0C54 E000A1C7 */  lwc1       $f1, 0xE0($29)
    /* C0C58 001C0C58 D000A0C7 */  lwc1       $f0, 0xD0($29)
    /* C0C5C 001C0C5C 00080046 */  add.s      $f0, $f1, $f0
    /* C0C60 001C0C60 E000A0E7 */  swc1       $f0, 0xE0($29)
    /* C0C64 001C0C64 6800A427 */  addiu      $4, $29, 0x68
    /* C0C68 001C0C68 D800A527 */  addiu      $5, $29, 0xD8
    /* C0C6C 001C0C6C C800A627 */  addiu      $6, $29, 0xC8
    /* C0C70 001C0C70 6100073C */  lui        $7, %hi(D_0060A0E0)
    /* C0C74 001C0C74 E0A0E724 */  addiu      $7, $7, %lo(D_0060A0E0)
    /* C0C78 001C0C78 E0F5060C */  jal        func_001bd780
    /* C0C7C 001C0C7C 00000000 */   nop
    /* C0C80 001C0C80 0C000010 */  b          .L001C0CB4
    /* C0C84 001C0C84 00000000 */   nop
  .L001C0C88:
    /* C0C88 001C0C88 4C8081C7 */  lwc1       $f1, -0x7FB4($28)
    /* C0C8C 001C0C8C 34000146 */  c.lt.s     $f0, $f1
    /* C0C90 001C0C90 08000045 */  bc1f       .L001C0CB4
    /* C0C94 001C0C94 00000000 */   nop
    /* C0C98 001C0C98 6800A427 */  addiu      $4, $29, 0x68
    /* C0C9C 001C0C9C 6100053C */  lui        $5, %hi(D_0060A0E0)
    /* C0CA0 001C0CA0 E0A0A524 */  addiu      $5, $5, %lo(D_0060A0E0)
    /* C0CA4 001C0CA4 60818CC7 */  lwc1       $f12, -0x7EA0($28)
    /* C0CA8 001C0CA8 02000624 */  addiu      $6, $0, 0x2
    /* C0CAC 001C0CAC D0710F0C */  jal        func_003dc740
    /* C0CB0 001C0CB0 00000000 */   nop
  .L001C0CB4:
    /* C0CB4 001C0CB4 D800A427 */  addiu      $4, $29, 0xD8
    /* C0CB8 001C0CB8 6100053C */  lui        $5, %hi(D_0060A100)
    /* C0CBC 001C0CBC 00A1A524 */  addiu      $5, $5, %lo(D_0060A100)
    /* C0CC0 001C0CC0 01000624 */  addiu      $6, $0, 0x1
    /* C0CC4 001C0CC4 6800A727 */  addiu      $7, $29, 0x68
    /* C0CC8 001C0CC8 D0720F0C */  jal        func_003dcb40
    /* C0CCC 001C0CCC 00000000 */   nop
    /* C0CD0 001C0CD0 003F023C */  lui        $2, (0x3F000000 >> 16)
    /* C0CD4 001C0CD4 00088244 */  mtc1       $2, $f1
    /* C0CD8 001C0CD8 B80000C6 */  lwc1       $f0, 0xB8($16)
    /* C0CDC 001C0CDC 42080046 */  mul.s      $f1, $f1, $f0
    /* C0CE0 001C0CE0 108180C7 */  lwc1       $f0, -0x7EF0($28)
    /* C0CE4 001C0CE4 02030146 */  mul.s      $f12, $f0, $f1
    /* C0CE8 001C0CE8 1A2E110C */  jal        func_0044b868
    /* C0CEC 001C0CEC 00000000 */   nop
    /* C0CF0 001C0CF0 77010224 */  addiu      $2, $0, 0x177
    /* C0CF4 001C0CF4 00088244 */  mtc1       $2, $f1
    /* C0CF8 001C0CF8 00000000 */  nop
    /* C0CFC 001C0CFC 60088046 */  cvt.s.w    $f1, $f1
    /* C0D00 001C0D00 030D0046 */  div.s      $f20, $f1, $f0
    /* C0D04 001C0D04 D800A0C7 */  lwc1       $f0, 0xD8($29)
    /* C0D08 001C0D08 02001446 */  mul.s      $f0, $f0, $f20
    /* C0D0C 001C0D0C D800A0E7 */  swc1       $f0, 0xD8($29)
    /* C0D10 001C0D10 DC00A0C7 */  lwc1       $f0, 0xDC($29)
    /* C0D14 001C0D14 02001446 */  mul.s      $f0, $f0, $f20
    /* C0D18 001C0D18 DC00A0E7 */  swc1       $f0, 0xDC($29)
    /* C0D1C 001C0D1C E000A0C7 */  lwc1       $f0, 0xE0($29)
    /* C0D20 001C0D20 02001446 */  mul.s      $f0, $f0, $f20
    /* C0D24 001C0D24 E000A0E7 */  swc1       $f0, 0xE0($29)
    /* C0D28 001C0D28 003F023C */  lui        $2, (0x3F000000 >> 16)
    /* C0D2C 001C0D2C 00088244 */  mtc1       $2, $f1
    /* C0D30 001C0D30 B80000C6 */  lwc1       $f0, 0xB8($16)
    /* C0D34 001C0D34 42080046 */  mul.s      $f1, $f1, $f0
    /* C0D38 001C0D38 108180C7 */  lwc1       $f0, -0x7EF0($28)
    /* C0D3C 001C0D3C 02030146 */  mul.s      $f12, $f0, $f1
    /* C0D40 001C0D40 1A2E110C */  jal        func_0044b868
    /* C0D44 001C0D44 00000000 */   nop
    /* C0D48 001C0D48 42A00046 */  mul.s      $f1, $f20, $f0
    /* C0D4C 001C0D4C 603E023C */  lui        $2, (0x3E600000 >> 16)
    /* C0D50 001C0D50 00008244 */  mtc1       $2, $f0
    /* C0D54 001C0D54 00000000 */  nop
    /* C0D58 001C0D58 020D0046 */  mul.s      $f20, $f1, $f0
    /* C0D5C 001C0D5C D800A0C7 */  lwc1       $f0, 0xD8($29)
    /* C0D60 001C0D60 E800A0E7 */  swc1       $f0, 0xE8($29)
    /* C0D64 001C0D64 E000A0C7 */  lwc1       $f0, 0xE0($29)
    /* C0D68 001C0D68 EC00A0E7 */  swc1       $f0, 0xEC($29)
    /* C0D6C 001C0D6C E800A427 */  addiu      $4, $29, 0xE8
    /* C0D70 001C0D70 2D288000 */  daddu      $5, $4, $0
    /* C0D74 001C0D74 78900F0C */  jal        func_003e41e0
    /* C0D78 001C0D78 00000000 */   nop
    /* C0D7C 001C0D7C EC00A1C7 */  lwc1       $f1, 0xEC($29)
    /* C0D80 001C0D80 C800A0C7 */  lwc1       $f0, 0xC8($29)
    /* C0D84 001C0D84 00108044 */  mtc1       $0, $f2
    /* C0D88 001C0D88 00000000 */  nop
    /* C0D8C 001C0D8C 18100046 */  adda.s     $f2, $f0
    /* C0D90 001C0D90 DC081446 */  madd.s     $f3, $f1, $f20
    /* C0D94 001C0D94 C800A3E7 */  swc1       $f3, 0xC8($29)
    /* C0D98 001C0D98 E800A1C7 */  lwc1       $f1, 0xE8($29)
    /* C0D9C 001C0D9C D000A0C7 */  lwc1       $f0, 0xD0($29)
    /* C0DA0 001C0DA0 18100046 */  adda.s     $f2, $f0
    /* C0DA4 001C0DA4 9D081446 */  msub.s     $f2, $f1, $f20
    /* C0DA8 001C0DA8 D000A2E7 */  swc1       $f2, 0xD0($29)
    /* C0DAC 001C0DAC D800A0C7 */  lwc1       $f0, 0xD8($29)
    /* C0DB0 001C0DB0 00180046 */  add.s      $f0, $f3, $f0
    /* C0DB4 001C0DB4 5C00A0E7 */  swc1       $f0, 0x5C($29)
    /* C0DB8 001C0DB8 CC00A1C7 */  lwc1       $f1, 0xCC($29)
    /* C0DBC 001C0DBC DC00A0C7 */  lwc1       $f0, 0xDC($29)
    /* C0DC0 001C0DC0 40080046 */  add.s      $f1, $f1, $f0
    /* C0DC4 001C0DC4 6000A1E7 */  swc1       $f1, 0x60($29)
    /* C0DC8 001C0DC8 E000A0C7 */  lwc1       $f0, 0xE0($29)
    /* C0DCC 001C0DCC 00100046 */  add.s      $f0, $f2, $f0
    /* C0DD0 001C0DD0 6400A0E7 */  swc1       $f0, 0x64($29)
    /* C0DD4 001C0DD4 C841023C */  lui        $2, (0x41C80000 >> 16)
    /* C0DD8 001C0DD8 00008244 */  mtc1       $2, $f0
    /* C0DDC 001C0DDC 00000000 */  nop
    /* C0DE0 001C0DE0 34080046 */  c.lt.s     $f1, $f0
    /* C0DE4 001C0DE4 02000045 */  bc1f       .L001C0DF0
    /* C0DE8 001C0DE8 00000000 */   nop
    /* C0DEC 001C0DEC 6000A0E7 */  swc1       $f0, 0x60($29)
  .L001C0DF0:
    /* C0DF0 001C0DF0 2D200002 */  daddu      $4, $16, $0
    /* C0DF4 001C0DF4 4000A527 */  addiu      $5, $29, 0x40
    /* C0DF8 001C0DF8 5C00A627 */  addiu      $6, $29, 0x5C
    /* C0DFC 001C0DFC 01000724 */  addiu      $7, $0, 0x1
    /* C0E00 001C0E00 08EB060C */  jal        func_001bac20
    /* C0E04 001C0E04 00000000 */   nop
    /* C0E08 001C0E08 2D200002 */  daddu      $4, $16, $0
    /* C0E0C 001C0E0C 8C818CC7 */  lwc1       $f12, -0x7E74($28)
    /* C0E10 001C0E10 BCEF060C */  jal        func_001bbef0
    /* C0E14 001C0E14 00000000 */   nop
    /* C0E18 001C0E18 3000BFDF */  ld         $31, 0x30($29)
    /* C0E1C 001C0E1C 2000B17B */  lq         $17, 0x20($29)
    /* C0E20 001C0E20 1000B07B */  lq         $16, 0x10($29)
    /* C0E24 001C0E24 0000B4C7 */  lwc1       $f20, 0x0($29)
    /* C0E28 001C0E28 F000BD27 */  addiu      $29, $29, 0xF0
    /* C0E2C 001C0E2C 0800E003 */  jr         $31
    /* C0E30 001C0E30 00000000 */   nop
    /* C0E34 001C0E34 00000000 */  nop
    /* C0E38 001C0E38 00000000 */  nop
    /* C0E3C 001C0E3C 00000000 */  nop
.size func_001c09b0, 0x490
