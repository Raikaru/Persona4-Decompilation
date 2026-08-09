.section .text
.set noat
.set noreorder
glabel func_001c6bf0
    /* C6BF0 001C6BF0 20FFBD27 */  addiu      $29, $29, -0xE0
    /* C6BF4 001C6BF4 2000BFFF */  sd         $31, 0x20($29)
    /* C6BF8 001C6BF8 1000B17F */  sq         $17, 0x10($29)
    /* C6BFC 001C6BFC 0000B07F */  sq         $16, 0x0($29)
    /* C6C00 001C6C00 2D808000 */  daddu      $16, $4, $0
    /* C6C04 001C6C04 E000828C */  lw         $2, 0xE0($4)
    /* C6C08 001C6C08 3800428C */  lw         $2, 0x38($2)
    /* C6C0C 001C6C0C 3000518C */  lw         $17, 0x30($2)
    /* C6C10 001C6C10 2D202002 */  daddu      $4, $17, $0
    /* C6C14 001C6C14 B000A527 */  addiu      $5, $29, 0xB0
    /* C6C18 001C6C18 7456060C */  jal        func_001959d0
    /* C6C1C 001C6C1C 00000000 */   nop
    /* C6C20 001C6C20 8C0021C6 */  lwc1       $f1, 0x8C($17)
    /* C6C24 001C6C24 2C0020C6 */  lwc1       $f0, 0x2C($17)
    /* C6C28 001C6C28 C2080046 */  mul.s      $f3, $f1, $f0
    /* C6C2C 001C6C2C 888182C7 */  lwc1       $f2, -0x7E78($28)
    /* C6C30 001C6C30 B400A1C7 */  lwc1       $f1, 0xB4($29)
    /* C6C34 001C6C34 00008044 */  mtc1       $0, $f0
    /* C6C38 001C6C38 00000000 */  nop
    /* C6C3C 001C6C3C 18000146 */  adda.s     $f0, $f1
    /* C6C40 001C6C40 1C100346 */  madd.s     $f0, $f2, $f3
    /* C6C44 001C6C44 B400A0E7 */  swc1       $f0, 0xB4($29)
    /* C6C48 001C6C48 C000A427 */  addiu      $4, $29, 0xC0
    /* C6C4C 001C6C4C 6100053C */  lui        $5, %hi(D_0060A0F0)
    /* C6C50 001C6C50 F0A0A524 */  addiu      $5, $5, %lo(D_0060A0F0)
    /* C6C54 001C6C54 01000624 */  addiu      $6, $0, 0x1
    /* C6C58 001C6C58 1C002726 */  addiu      $7, $17, 0x1C
    /* C6C5C 001C6C5C D0720F0C */  jal        func_003dcb40
    /* C6C60 001C6C60 00000000 */   nop
    /* C6C64 001C6C64 4843023C */  lui        $2, (0x43480000 >> 16)
    /* C6C68 001C6C68 00108244 */  mtc1       $2, $f2
    /* C6C6C 001C6C6C C000A0C7 */  lwc1       $f0, 0xC0($29)
    /* C6C70 001C6C70 42110046 */  mul.s      $f5, $f2, $f0
    /* C6C74 001C6C74 D000A5E7 */  swc1       $f5, 0xD0($29)
    /* C6C78 001C6C78 C400A0C7 */  lwc1       $f0, 0xC4($29)
    /* C6C7C 001C6C7C 42100046 */  mul.s      $f1, $f2, $f0
    /* C6C80 001C6C80 D400A1E7 */  swc1       $f1, 0xD4($29)
    /* C6C84 001C6C84 C800A0C7 */  lwc1       $f0, 0xC8($29)
    /* C6C88 001C6C88 02110046 */  mul.s      $f4, $f2, $f0
    /* C6C8C 001C6C8C D800A4E7 */  swc1       $f4, 0xD8($29)
    /* C6C90 001C6C90 B400A3C7 */  lwc1       $f3, 0xB4($29)
    /* C6C94 001C6C94 40180146 */  add.s      $f1, $f3, $f1
    /* C6C98 001C6C98 2041023C */  lui        $2, (0x41200000 >> 16)
    /* C6C9C 001C6C9C 00008244 */  mtc1       $2, $f0
    /* C6CA0 001C6CA0 00000000 */  nop
    /* C6CA4 001C6CA4 81080046 */  sub.s      $f2, $f1, $f0
    /* C6CA8 001C6CA8 B000A1C7 */  lwc1       $f1, 0xB0($29)
    /* C6CAC 001C6CAC 00080546 */  add.s      $f0, $f1, $f5
    /* C6CB0 001C6CB0 01000146 */  sub.s      $f0, $f0, $f1
    /* C6CB4 001C6CB4 C000A0E7 */  swc1       $f0, 0xC0($29)
    /* C6CB8 001C6CB8 01100346 */  sub.s      $f0, $f2, $f3
    /* C6CBC 001C6CBC C400A0E7 */  swc1       $f0, 0xC4($29)
    /* C6CC0 001C6CC0 B800A1C7 */  lwc1       $f1, 0xB8($29)
    /* C6CC4 001C6CC4 00080446 */  add.s      $f0, $f1, $f4
    /* C6CC8 001C6CC8 01000146 */  sub.s      $f0, $f0, $f1
    /* C6CCC 001C6CCC C800A0E7 */  swc1       $f0, 0xC8($29)
    /* C6CD0 001C6CD0 C000A427 */  addiu      $4, $29, 0xC0
    /* C6CD4 001C6CD4 2D288000 */  daddu      $5, $4, $0
    /* C6CD8 001C6CD8 2C900F0C */  jal        func_003e40b0
    /* C6CDC 001C6CDC 00000000 */   nop
    /* C6CE0 001C6CE0 003F023C */  lui        $2, (0x3F000000 >> 16)
    /* C6CE4 001C6CE4 00088244 */  mtc1       $2, $f1
    /* C6CE8 001C6CE8 20C1023C */  lui        $2, (0xC1200000 >> 16)
    /* C6CEC 001C6CEC 00008244 */  mtc1       $2, $f0
    /* C6CF0 001C6CF0 00000000 */  nop
    /* C6CF4 001C6CF4 07000046 */  neg.s      $f0, $f0
    /* C6CF8 001C6CF8 020B0046 */  mul.s      $f12, $f1, $f0
    /* C6CFC 001C6CFC 7000A427 */  addiu      $4, $29, 0x70
    /* C6D00 001C6D00 6100053C */  lui        $5, %hi(D_0060A0E0)
    /* C6D04 001C6D04 E0A0A524 */  addiu      $5, $5, %lo(D_0060A0E0)
    /* C6D08 001C6D08 2D300000 */  daddu      $6, $0, $0
    /* C6D0C 001C6D0C 1C820F0C */  jal        func_003e0870
    /* C6D10 001C6D10 00000000 */   nop
    /* C6D14 001C6D14 D000A427 */  addiu      $4, $29, 0xD0
    /* C6D18 001C6D18 C000A527 */  addiu      $5, $29, 0xC0
    /* C6D1C 001C6D1C 7000A627 */  addiu      $6, $29, 0x70
    /* C6D20 001C6D20 C8900F0C */  jal        func_003e4320
    /* C6D24 001C6D24 00000000 */   nop
    /* C6D28 001C6D28 003F023C */  lui        $2, (0x3F000000 >> 16)
    /* C6D2C 001C6D2C 00088244 */  mtc1       $2, $f1
    /* C6D30 001C6D30 B80000C6 */  lwc1       $f0, 0xB8($16)
    /* C6D34 001C6D34 42080046 */  mul.s      $f1, $f1, $f0
    /* C6D38 001C6D38 108180C7 */  lwc1       $f0, -0x7EF0($28)
    /* C6D3C 001C6D3C 02030146 */  mul.s      $f12, $f0, $f1
    /* C6D40 001C6D40 1A2E110C */  jal        func_0044b868
    /* C6D44 001C6D44 00000000 */   nop
    /* C6D48 001C6D48 3443023C */  lui        $2, (0x43340000 >> 16)
    /* C6D4C 001C6D4C 00088244 */  mtc1       $2, $f1
    /* C6D50 001C6D50 00000000 */  nop
    /* C6D54 001C6D54 43080046 */  div.s      $f1, $f1, $f0
    /* C6D58 001C6D58 D000A0C7 */  lwc1       $f0, 0xD0($29)
    /* C6D5C 001C6D5C C2000146 */  mul.s      $f3, $f0, $f1
    /* C6D60 001C6D60 D000A3E7 */  swc1       $f3, 0xD0($29)
    /* C6D64 001C6D64 D400A0C7 */  lwc1       $f0, 0xD4($29)
    /* C6D68 001C6D68 82000146 */  mul.s      $f2, $f0, $f1
    /* C6D6C 001C6D6C D400A2E7 */  swc1       $f2, 0xD4($29)
    /* C6D70 001C6D70 D800A0C7 */  lwc1       $f0, 0xD8($29)
    /* C6D74 001C6D74 42000146 */  mul.s      $f1, $f0, $f1
    /* C6D78 001C6D78 D800A1E7 */  swc1       $f1, 0xD8($29)
    /* C6D7C 001C6D7C B000A0C7 */  lwc1       $f0, 0xB0($29)
    /* C6D80 001C6D80 00000346 */  add.s      $f0, $f0, $f3
    /* C6D84 001C6D84 3000A0E7 */  swc1       $f0, 0x30($29)
    /* C6D88 001C6D88 B400A0C7 */  lwc1       $f0, 0xB4($29)
    /* C6D8C 001C6D8C 00000246 */  add.s      $f0, $f0, $f2
    /* C6D90 001C6D90 3400A0E7 */  swc1       $f0, 0x34($29)
    /* C6D94 001C6D94 B800A0C7 */  lwc1       $f0, 0xB8($29)
    /* C6D98 001C6D98 00000146 */  add.s      $f0, $f0, $f1
    /* C6D9C 001C6D9C 3800A0E7 */  swc1       $f0, 0x38($29)
    /* C6DA0 001C6DA0 3C00A427 */  addiu      $4, $29, 0x3C
    /* C6DA4 001C6DA4 3000A527 */  addiu      $5, $29, 0x30
    /* C6DA8 001C6DA8 B000A627 */  addiu      $6, $29, 0xB0
    /* C6DAC 001C6DAC 6100073C */  lui        $7, %hi(D_0060A0E0)
    /* C6DB0 001C6DB0 E0A0E724 */  addiu      $7, $7, %lo(D_0060A0E0)
    /* C6DB4 001C6DB4 E0F5060C */  jal        func_001bd780
    /* C6DB8 001C6DB8 00000000 */   nop
    /* C6DBC 001C6DBC A0C0023C */  lui        $2, (0xC0A00000 >> 16)
    /* C6DC0 001C6DC0 00608244 */  mtc1       $2, $f12
    /* C6DC4 001C6DC4 7000A427 */  addiu      $4, $29, 0x70
    /* C6DC8 001C6DC8 6100053C */  lui        $5, %hi(D_0060A0E0)
    /* C6DCC 001C6DCC E0A0A524 */  addiu      $5, $5, %lo(D_0060A0E0)
    /* C6DD0 001C6DD0 2D300000 */  daddu      $6, $0, $0
    /* C6DD4 001C6DD4 1C820F0C */  jal        func_003e0870
    /* C6DD8 001C6DD8 00000000 */   nop
    /* C6DDC 001C6DDC D000A427 */  addiu      $4, $29, 0xD0
    /* C6DE0 001C6DE0 C000A527 */  addiu      $5, $29, 0xC0
    /* C6DE4 001C6DE4 7000A627 */  addiu      $6, $29, 0x70
    /* C6DE8 001C6DE8 C8900F0C */  jal        func_003e4320
    /* C6DEC 001C6DEC 00000000 */   nop
    /* C6DF0 001C6DF0 003F023C */  lui        $2, (0x3F000000 >> 16)
    /* C6DF4 001C6DF4 00088244 */  mtc1       $2, $f1
    /* C6DF8 001C6DF8 B80000C6 */  lwc1       $f0, 0xB8($16)
    /* C6DFC 001C6DFC 42080046 */  mul.s      $f1, $f1, $f0
    /* C6E00 001C6E00 108180C7 */  lwc1       $f0, -0x7EF0($28)
    /* C6E04 001C6E04 02030146 */  mul.s      $f12, $f0, $f1
    /* C6E08 001C6E08 1A2E110C */  jal        func_0044b868
    /* C6E0C 001C6E0C 00000000 */   nop
    /* C6E10 001C6E10 DC42023C */  lui        $2, (0x42DC0000 >> 16)
    /* C6E14 001C6E14 00088244 */  mtc1       $2, $f1
    /* C6E18 001C6E18 00000000 */  nop
    /* C6E1C 001C6E1C 43080046 */  div.s      $f1, $f1, $f0
    /* C6E20 001C6E20 D000A0C7 */  lwc1       $f0, 0xD0($29)
    /* C6E24 001C6E24 C2000146 */  mul.s      $f3, $f0, $f1
    /* C6E28 001C6E28 D000A3E7 */  swc1       $f3, 0xD0($29)
    /* C6E2C 001C6E2C D400A0C7 */  lwc1       $f0, 0xD4($29)
    /* C6E30 001C6E30 82000146 */  mul.s      $f2, $f0, $f1
    /* C6E34 001C6E34 D400A2E7 */  swc1       $f2, 0xD4($29)
    /* C6E38 001C6E38 D800A0C7 */  lwc1       $f0, 0xD8($29)
    /* C6E3C 001C6E3C 42000146 */  mul.s      $f1, $f0, $f1
    /* C6E40 001C6E40 D800A1E7 */  swc1       $f1, 0xD8($29)
    /* C6E44 001C6E44 B000A0C7 */  lwc1       $f0, 0xB0($29)
    /* C6E48 001C6E48 00000346 */  add.s      $f0, $f0, $f3
    /* C6E4C 001C6E4C 4C00A0E7 */  swc1       $f0, 0x4C($29)
    /* C6E50 001C6E50 B400A0C7 */  lwc1       $f0, 0xB4($29)
    /* C6E54 001C6E54 00000246 */  add.s      $f0, $f0, $f2
    /* C6E58 001C6E58 5000A0E7 */  swc1       $f0, 0x50($29)
    /* C6E5C 001C6E5C B800A0C7 */  lwc1       $f0, 0xB8($29)
    /* C6E60 001C6E60 00000146 */  add.s      $f0, $f0, $f1
    /* C6E64 001C6E64 5400A0E7 */  swc1       $f0, 0x54($29)
    /* C6E68 001C6E68 5800A427 */  addiu      $4, $29, 0x58
    /* C6E6C 001C6E6C 4C00A527 */  addiu      $5, $29, 0x4C
    /* C6E70 001C6E70 B000A627 */  addiu      $6, $29, 0xB0
    /* C6E74 001C6E74 6100073C */  lui        $7, %hi(D_0060A0E0)
    /* C6E78 001C6E78 E0A0E724 */  addiu      $7, $7, %lo(D_0060A0E0)
    /* C6E7C 001C6E7C E0F5060C */  jal        func_001bd780
    /* C6E80 001C6E80 00000000 */   nop
    /* C6E84 001C6E84 3400A1C7 */  lwc1       $f1, 0x34($29)
    /* C6E88 001C6E88 C841023C */  lui        $2, (0x41C80000 >> 16)
    /* C6E8C 001C6E8C 00008244 */  mtc1       $2, $f0
    /* C6E90 001C6E90 00000000 */  nop
    /* C6E94 001C6E94 34080046 */  c.lt.s     $f1, $f0
    /* C6E98 001C6E98 02000045 */  bc1f       .L001C6EA4
    /* C6E9C 001C6E9C 00000000 */   nop
    /* C6EA0 001C6EA0 3400A0E7 */  swc1       $f0, 0x34($29)
  .L001C6EA4:
    /* C6EA4 001C6EA4 5000A1C7 */  lwc1       $f1, 0x50($29)
    /* C6EA8 001C6EA8 C841023C */  lui        $2, (0x41C80000 >> 16)
    /* C6EAC 001C6EAC 00008244 */  mtc1       $2, $f0
    /* C6EB0 001C6EB0 00000000 */  nop
    /* C6EB4 001C6EB4 34080046 */  c.lt.s     $f1, $f0
    /* C6EB8 001C6EB8 02000045 */  bc1f       .L001C6EC4
    /* C6EBC 001C6EBC 00000000 */   nop
    /* C6EC0 001C6EC0 5000A0E7 */  swc1       $f0, 0x50($29)
  .L001C6EC4:
    /* C6EC4 001C6EC4 00608044 */  mtc1       $0, $f12
    /* C6EC8 001C6EC8 E000048E */  lw         $4, 0xE0($16)
    /* C6ECC 001C6ECC 2D280000 */  daddu      $5, $0, $0
    /* C6ED0 001C6ED0 2D300000 */  daddu      $6, $0, $0
    /* C6ED4 001C6ED4 02000724 */  addiu      $7, $0, 0x2
    /* C6ED8 001C6ED8 50F3060C */  jal        func_001bcd40
    /* C6EDC 001C6EDC 00000000 */   nop
    /* C6EE0 001C6EE0 2D200002 */  daddu      $4, $16, $0
    /* C6EE4 001C6EE4 3000A527 */  addiu      $5, $29, 0x30
    /* C6EE8 001C6EE8 4C00A627 */  addiu      $6, $29, 0x4C
    /* C6EEC 001C6EEC 01000724 */  addiu      $7, $0, 0x1
    /* C6EF0 001C6EF0 08EB060C */  jal        func_001bac20
    /* C6EF4 001C6EF4 00000000 */   nop
    /* C6EF8 001C6EF8 C03F023C */  lui        $2, (0x3FC00000 >> 16)
    /* C6EFC 001C6EFC 00608244 */  mtc1       $2, $f12
    /* C6F00 001C6F00 2D200002 */  daddu      $4, $16, $0
    /* C6F04 001C6F04 BCEF060C */  jal        func_001bbef0
    /* C6F08 001C6F08 00000000 */   nop
    /* C6F0C 001C6F0C 2000BFDF */  ld         $31, 0x20($29)
    /* C6F10 001C6F10 1000B17B */  lq         $17, 0x10($29)
    /* C6F14 001C6F14 0000B07B */  lq         $16, 0x0($29)
    /* C6F18 001C6F18 E000BD27 */  addiu      $29, $29, 0xE0
    /* C6F1C 001C6F1C 0800E003 */  jr         $31
    /* C6F20 001C6F20 00000000 */   nop
    /* C6F24 001C6F24 00000000 */  nop
    /* C6F28 001C6F28 00000000 */  nop
    /* C6F2C 001C6F2C 00000000 */  nop
.size func_001c6bf0, 0x340
