.section .text
.set noat
.set noreorder
glabel func_001d1cc0
    /* D1CC0 001D1CC0 90FFBD27 */  addiu      $29, $29, -0x70
    /* D1CC4 001D1CC4 3000BFFF */  sd         $31, 0x30($29)
    /* D1CC8 001D1CC8 2000B27F */  sq         $18, 0x20($29)
    /* D1CCC 001D1CCC 1000B17F */  sq         $17, 0x10($29)
    /* D1CD0 001D1CD0 0000B07F */  sq         $16, 0x0($29)
    /* D1CD4 001D1CD4 2D908000 */  daddu      $18, $4, $0
    /* D1CD8 001D1CD8 0000918C */  lw         $17, 0x0($4)
    /* D1CDC 001D1CDC 0400908C */  lw         $16, 0x4($4)
    /* D1CE0 001D1CE0 2D200002 */  daddu      $4, $16, $0
    /* D1CE4 001D1CE4 2D282002 */  daddu      $5, $17, $0
    /* D1CE8 001D1CE8 4000A627 */  addiu      $6, $29, 0x40
    /* D1CEC 001D1CEC D856060C */  jal        func_00195b60
    /* D1CF0 001D1CF0 00000000 */   nop
    /* D1CF4 001D1CF4 040021C6 */  lwc1       $f1, 0x4($17)
    /* D1CF8 001D1CF8 4000A0C7 */  lwc1       $f0, 0x40($29)
    /* D1CFC 001D1CFC 01080046 */  sub.s      $f0, $f1, $f0
    /* D1D00 001D1D00 6000A0E7 */  swc1       $f0, 0x60($29)
    /* D1D04 001D1D04 6400A0AF */  sw         $0, 0x64($29)
    /* D1D08 001D1D08 0C0021C6 */  lwc1       $f1, 0xC($17)
    /* D1D0C 001D1D0C 4800A0C7 */  lwc1       $f0, 0x48($29)
    /* D1D10 001D1D10 01080046 */  sub.s      $f0, $f1, $f0
    /* D1D14 001D1D14 6800A0E7 */  swc1       $f0, 0x68($29)
    /* D1D18 001D1D18 6000A427 */  addiu      $4, $29, 0x60
    /* D1D1C 001D1D1C 2D288000 */  daddu      $5, $4, $0
    /* D1D20 001D1D20 2C900F0C */  jal        func_003e40b0
    /* D1D24 001D1D24 00000000 */   nop
    /* D1D28 001D1D28 00088044 */  mtc1       $0, $f1
    /* D1D2C 001D1D2C 6000A0C7 */  lwc1       $f0, 0x60($29)
    /* D1D30 001D1D30 32080046 */  c.eq.s     $f1, $f0
    /* D1D34 001D1D34 08000045 */  bc1f       .L001D1D58
    /* D1D38 001D1D38 00000000 */   nop
    /* D1D3C 001D1D3C 6800A0C7 */  lwc1       $f0, 0x68($29)
    /* D1D40 001D1D40 32080046 */  c.eq.s     $f1, $f0
    /* D1D44 001D1D44 04000045 */  bc1f       .L001D1D58
    /* D1D48 001D1D48 00000000 */   nop
    /* D1D4C 001D1D4C 01000224 */  addiu      $2, $0, 0x1
    /* D1D50 001D1D50 50000010 */  b          .L001D1E94
    /* D1D54 001D1D54 00000000 */   nop
  .L001D1D58:
    /* D1D58 001D1D58 2D200002 */  daddu      $4, $16, $0
    /* D1D5C 001D1D5C 0A000524 */  addiu      $5, $0, 0xA
    /* D1D60 001D1D60 687B060C */  jal        func_0019eda0
    /* D1D64 001D1D64 00000000 */   nop
    /* D1D68 001D1D68 04004284 */  lh         $2, 0x4($2)
    /* D1D6C 001D1D6C 00008244 */  mtc1       $2, $f0
    /* D1D70 001D1D70 00000000 */  nop
    /* D1D74 001D1D74 E0008046 */  cvt.s.w    $f3, $f0
    /* D1D78 001D1D78 2C0002C6 */  lwc1       $f2, 0x2C($16)
    /* D1D7C 001D1D7C 080041C6 */  lwc1       $f1, 0x8($18)
    /* D1D80 001D1D80 00008044 */  mtc1       $0, $f0
    /* D1D84 001D1D84 00000000 */  nop
    /* D1D88 001D1D88 18000146 */  adda.s     $f0, $f1
    /* D1D8C 001D1D8C 5D180246 */  msub.s     $f1, $f3, $f2
    /* D1D90 001D1D90 6000A0C7 */  lwc1       $f0, 0x60($29)
    /* D1D94 001D1D94 C2000146 */  mul.s      $f3, $f0, $f1
    /* D1D98 001D1D98 6000A3E7 */  swc1       $f3, 0x60($29)
    /* D1D9C 001D1D9C 6400A0C7 */  lwc1       $f0, 0x64($29)
    /* D1DA0 001D1DA0 82000146 */  mul.s      $f2, $f0, $f1
    /* D1DA4 001D1DA4 6400A2E7 */  swc1       $f2, 0x64($29)
    /* D1DA8 001D1DA8 6800A0C7 */  lwc1       $f0, 0x68($29)
    /* D1DAC 001D1DAC 42000146 */  mul.s      $f1, $f0, $f1
    /* D1DB0 001D1DB0 6800A1E7 */  swc1       $f1, 0x68($29)
    /* D1DB4 001D1DB4 0C004296 */  lhu        $2, 0xC($18)
    /* D1DB8 001D1DB8 01004230 */  andi       $2, $2, 0x1
    /* D1DBC 001D1DBC 20004010 */  beqz       $2, .L001D1E40
    /* D1DC0 001D1DC0 00000000 */   nop
    /* D1DC4 001D1DC4 040020C6 */  lwc1       $f0, 0x4($17)
    /* D1DC8 001D1DC8 00000346 */  add.s      $f0, $f0, $f3
    /* D1DCC 001D1DCC 5000A0E7 */  swc1       $f0, 0x50($29)
    /* D1DD0 001D1DD0 080020C6 */  lwc1       $f0, 0x8($17)
    /* D1DD4 001D1DD4 00000246 */  add.s      $f0, $f0, $f2
    /* D1DD8 001D1DD8 5400A0E7 */  swc1       $f0, 0x54($29)
    /* D1DDC 001D1DDC 0C0020C6 */  lwc1       $f0, 0xC($17)
    /* D1DE0 001D1DE0 00000146 */  add.s      $f0, $f0, $f1
    /* D1DE4 001D1DE4 5800A0E7 */  swc1       $f0, 0x58($29)
    /* D1DE8 001D1DE8 2D202002 */  daddu      $4, $17, $0
    /* D1DEC 001D1DEC 5000A527 */  addiu      $5, $29, 0x50
    /* D1DF0 001D1DF0 B853060C */  jal        func_00194ee0
    /* D1DF4 001D1DF4 00000000 */   nop
    /* D1DF8 001D1DF8 0C0A248E */  lw         $4, 0xA0C($17)
    /* D1DFC 001D1DFC 10008010 */  beqz       $4, .L001D1E40
    /* D1E00 001D1E00 00000000 */   nop
    /* D1E04 001D1E04 040081C4 */  lwc1       $f1, 0x4($4)
    /* D1E08 001D1E08 6000A0C7 */  lwc1       $f0, 0x60($29)
    /* D1E0C 001D1E0C 00080046 */  add.s      $f0, $f1, $f0
    /* D1E10 001D1E10 5000A0E7 */  swc1       $f0, 0x50($29)
    /* D1E14 001D1E14 080081C4 */  lwc1       $f1, 0x8($4)
    /* D1E18 001D1E18 6400A0C7 */  lwc1       $f0, 0x64($29)
    /* D1E1C 001D1E1C 00080046 */  add.s      $f0, $f1, $f0
    /* D1E20 001D1E20 5400A0E7 */  swc1       $f0, 0x54($29)
    /* D1E24 001D1E24 0C0081C4 */  lwc1       $f1, 0xC($4)
    /* D1E28 001D1E28 6800A0C7 */  lwc1       $f0, 0x68($29)
    /* D1E2C 001D1E2C 00080046 */  add.s      $f0, $f1, $f0
    /* D1E30 001D1E30 5800A0E7 */  swc1       $f0, 0x58($29)
    /* D1E34 001D1E34 5000A527 */  addiu      $5, $29, 0x50
    /* D1E38 001D1E38 B853060C */  jal        func_00194ee0
    /* D1E3C 001D1E3C 00000000 */   nop
  .L001D1E40:
    /* D1E40 001D1E40 0C004296 */  lhu        $2, 0xC($18)
    /* D1E44 001D1E44 02004230 */  andi       $2, $2, 0x2
    /* D1E48 001D1E48 11004010 */  beqz       $2, .L001D1E90
    /* D1E4C 001D1E4C 00000000 */   nop
    /* D1E50 001D1E50 040001C6 */  lwc1       $f1, 0x4($16)
    /* D1E54 001D1E54 6000A0C7 */  lwc1       $f0, 0x60($29)
    /* D1E58 001D1E58 00080046 */  add.s      $f0, $f1, $f0
    /* D1E5C 001D1E5C 5000A0E7 */  swc1       $f0, 0x50($29)
    /* D1E60 001D1E60 080001C6 */  lwc1       $f1, 0x8($16)
    /* D1E64 001D1E64 6400A0C7 */  lwc1       $f0, 0x64($29)
    /* D1E68 001D1E68 00080046 */  add.s      $f0, $f1, $f0
    /* D1E6C 001D1E6C 5400A0E7 */  swc1       $f0, 0x54($29)
    /* D1E70 001D1E70 0C0001C6 */  lwc1       $f1, 0xC($16)
    /* D1E74 001D1E74 6800A0C7 */  lwc1       $f0, 0x68($29)
    /* D1E78 001D1E78 00080046 */  add.s      $f0, $f1, $f0
    /* D1E7C 001D1E7C 5800A0E7 */  swc1       $f0, 0x58($29)
    /* D1E80 001D1E80 2D200002 */  daddu      $4, $16, $0
    /* D1E84 001D1E84 5000A527 */  addiu      $5, $29, 0x50
    /* D1E88 001D1E88 B853060C */  jal        func_00194ee0
    /* D1E8C 001D1E8C 00000000 */   nop
  .L001D1E90:
    /* D1E90 001D1E90 01000224 */  addiu      $2, $0, 0x1
  .L001D1E94:
    /* D1E94 001D1E94 3000BFDF */  ld         $31, 0x30($29)
    /* D1E98 001D1E98 2000B27B */  lq         $18, 0x20($29)
    /* D1E9C 001D1E9C 1000B17B */  lq         $17, 0x10($29)
    /* D1EA0 001D1EA0 0000B07B */  lq         $16, 0x0($29)
    /* D1EA4 001D1EA4 7000BD27 */  addiu      $29, $29, 0x70
    /* D1EA8 001D1EA8 0800E003 */  jr         $31
    /* D1EAC 001D1EAC 00000000 */   nop
.size func_001d1cc0, 0x1f0
