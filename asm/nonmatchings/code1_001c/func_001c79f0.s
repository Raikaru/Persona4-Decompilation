.section .text
.set noat
.set noreorder
glabel func_001c79f0
    /* C79F0 001C79F0 B0FEBD27 */  addiu      $29, $29, -0x150
    /* C79F4 001C79F4 5000BFFF */  sd         $31, 0x50($29)
    /* C79F8 001C79F8 4000B27F */  sq         $18, 0x40($29)
    /* C79FC 001C79FC 3000B17F */  sq         $17, 0x30($29)
    /* C7A00 001C7A00 2000B07F */  sq         $16, 0x20($29)
    /* C7A04 001C7A04 1000B8E7 */  swc1       $f24, 0x10($29)
    /* C7A08 001C7A08 0C00B7E7 */  swc1       $f23, 0xC($29)
    /* C7A0C 001C7A0C 0800B6E7 */  swc1       $f22, 0x8($29)
    /* C7A10 001C7A10 0400B5E7 */  swc1       $f21, 0x4($29)
    /* C7A14 001C7A14 0000B4E7 */  swc1       $f20, 0x0($29)
    /* C7A18 001C7A18 2D908000 */  daddu      $18, $4, $0
    /* C7A1C 001C7A1C 06018294 */  lhu        $2, 0x106($4)
    /* C7A20 001C7A20 B3004010 */  beqz       $2, .L001C7CF0
    /* C7A24 001C7A24 00000000 */   nop
    /* C7A28 001C7A28 A000A427 */  addiu      $4, $29, 0xA0
    /* C7A2C 001C7A2C 9C004526 */  addiu      $5, $18, 0x9C
    /* C7A30 001C7A30 58F5060C */  jal        func_001bd560
    /* C7A34 001C7A34 00000000 */   nop
    /* C7A38 001C7A38 E000428E */  lw         $2, 0xE0($18)
    /* C7A3C 001C7A3C 3000508C */  lw         $16, 0x30($2)
    /* C7A40 001C7A40 03000424 */  addiu      $4, $0, 0x3
    /* C7A44 001C7A44 2D280000 */  daddu      $5, $0, $0
    /* C7A48 001C7A48 1801A627 */  addiu      $6, $29, 0x118
    /* C7A4C 001C7A4C 2D380000 */  daddu      $7, $0, $0
    /* C7A50 001C7A50 2D400000 */  daddu      $8, $0, $0
    /* C7A54 001C7A54 01000924 */  addiu      $9, $0, 0x1
    /* C7A58 001C7A58 1058060C */  jal        func_00196040
    /* C7A5C 001C7A5C 00000000 */   nop
    /* C7A60 001C7A60 06050046 */  mov.s      $f20, $f0
    /* C7A64 001C7A64 01000424 */  addiu      $4, $0, 0x1
    /* C7A68 001C7A68 2D280000 */  daddu      $5, $0, $0
    /* C7A6C 001C7A6C 2D300000 */  daddu      $6, $0, $0
    /* C7A70 001C7A70 4C01A727 */  addiu      $7, $29, 0x14C
    /* C7A74 001C7A74 4801A827 */  addiu      $8, $29, 0x148
    /* C7A78 001C7A78 2D488000 */  daddu      $9, $4, $0
    /* C7A7C 001C7A7C 1058060C */  jal        func_00196040
    /* C7A80 001C7A80 00000000 */   nop
    /* C7A84 001C7A84 4801A3C7 */  lwc1       $f3, 0x148($29)
    /* C7A88 001C7A88 4C01A0C7 */  lwc1       $f0, 0x14C($29)
    /* C7A8C 001C7A8C 81000346 */  sub.s      $f2, $f0, $f3
    /* C7A90 001C7A90 003F023C */  lui        $2, (0x3F000000 >> 16)
    /* C7A94 001C7A94 00088244 */  mtc1       $2, $f1
    /* C7A98 001C7A98 00008044 */  mtc1       $0, $f0
    /* C7A9C 001C7A9C 00000000 */  nop
    /* C7AA0 001C7AA0 18000346 */  adda.s     $f0, $f3
    /* C7AA4 001C7AA4 1C080246 */  madd.s     $f0, $f1, $f2
    /* C7AA8 001C7AA8 1C01A0E7 */  swc1       $f0, 0x11C($29)
    /* C7AAC 001C7AAC B80040C6 */  lwc1       $f0, 0xB8($18)
    /* C7AB0 001C7AB0 42080046 */  mul.s      $f1, $f1, $f0
    /* C7AB4 001C7AB4 108180C7 */  lwc1       $f0, -0x7EF0($28)
    /* C7AB8 001C7AB8 02030146 */  mul.s      $f12, $f0, $f1
    /* C7ABC 001C7ABC 1A2E110C */  jal        func_0044b868
    /* C7AC0 001C7AC0 00000000 */   nop
    /* C7AC4 001C7AC4 403F023C */  lui        $2, (0x3F400000 >> 16)
    /* C7AC8 001C7AC8 00088244 */  mtc1       $2, $f1
    /* C7ACC 001C7ACC 00000000 */  nop
    /* C7AD0 001C7AD0 42081446 */  mul.s      $f1, $f1, $f20
    /* C7AD4 001C7AD4 030D0046 */  div.s      $f20, $f1, $f0
    /* C7AD8 001C7AD8 00000000 */  nop
    /* C7ADC 001C7ADC 2D200002 */  daddu      $4, $16, $0
    /* C7AE0 001C7AE0 E800A527 */  addiu      $5, $29, 0xE8
    /* C7AE4 001C7AE4 3C56060C */  jal        func_001958f0
    /* C7AE8 001C7AE8 00000000 */   nop
    /* C7AEC 001C7AEC E800A3C7 */  lwc1       $f3, 0xE8($29)
    /* C7AF0 001C7AF0 0801A3E7 */  swc1       $f3, 0x108($29)
    /* C7AF4 001C7AF4 1C01A2C7 */  lwc1       $f2, 0x11C($29)
    /* C7AF8 001C7AF8 0C01A2E7 */  swc1       $f2, 0x10C($29)
    /* C7AFC 001C7AFC F000A1C7 */  lwc1       $f1, 0xF0($29)
    /* C7B00 001C7B00 1001A1E7 */  swc1       $f1, 0x110($29)
    /* C7B04 001C7B04 1801A0C7 */  lwc1       $f0, 0x118($29)
    /* C7B08 001C7B08 01180046 */  sub.s      $f0, $f3, $f0
    /* C7B0C 001C7B0C 2801A0E7 */  swc1       $f0, 0x128($29)
    /* C7B10 001C7B10 01100246 */  sub.s      $f0, $f2, $f2
    /* C7B14 001C7B14 2C01A0E7 */  swc1       $f0, 0x12C($29)
    /* C7B18 001C7B18 2001A0C7 */  lwc1       $f0, 0x120($29)
    /* C7B1C 001C7B1C 01080046 */  sub.s      $f0, $f1, $f0
    /* C7B20 001C7B20 3001A0E7 */  swc1       $f0, 0x130($29)
    /* C7B24 001C7B24 2801A427 */  addiu      $4, $29, 0x128
    /* C7B28 001C7B28 2D288000 */  daddu      $5, $4, $0
    /* C7B2C 001C7B2C 2C900F0C */  jal        func_003e40b0
    /* C7B30 001C7B30 00000000 */   nop
    /* C7B34 001C7B34 288181C7 */  lwc1       $f1, -0x7ED8($28)
    /* C7B38 001C7B38 42080046 */  mul.s      $f1, $f1, $f0
    /* C7B3C 001C7B3C 2801A0C7 */  lwc1       $f0, 0x128($29)
    /* C7B40 001C7B40 C2000146 */  mul.s      $f3, $f0, $f1
    /* C7B44 001C7B44 2801A3E7 */  swc1       $f3, 0x128($29)
    /* C7B48 001C7B48 2C01A0C7 */  lwc1       $f0, 0x12C($29)
    /* C7B4C 001C7B4C 82000146 */  mul.s      $f2, $f0, $f1
    /* C7B50 001C7B50 2C01A2E7 */  swc1       $f2, 0x12C($29)
    /* C7B54 001C7B54 3001A0C7 */  lwc1       $f0, 0x130($29)
    /* C7B58 001C7B58 42000146 */  mul.s      $f1, $f0, $f1
    /* C7B5C 001C7B5C 3001A1E7 */  swc1       $f1, 0x130($29)
    /* C7B60 001C7B60 1801A0C7 */  lwc1       $f0, 0x118($29)
    /* C7B64 001C7B64 00000346 */  add.s      $f0, $f0, $f3
    /* C7B68 001C7B68 F800A0E7 */  swc1       $f0, 0xF8($29)
    /* C7B6C 001C7B6C 1C01A0C7 */  lwc1       $f0, 0x11C($29)
    /* C7B70 001C7B70 00000246 */  add.s      $f0, $f0, $f2
    /* C7B74 001C7B74 FC00A0E7 */  swc1       $f0, 0xFC($29)
    /* C7B78 001C7B78 2001A0C7 */  lwc1       $f0, 0x120($29)
    /* C7B7C 001C7B7C 00000146 */  add.s      $f0, $f0, $f1
    /* C7B80 001C7B80 0001A0E7 */  swc1       $f0, 0x100($29)
    /* C7B84 001C7B84 E800A0C7 */  lwc1       $f0, 0xE8($29)
    /* C7B88 001C7B88 0801A0E7 */  swc1       $f0, 0x108($29)
    /* C7B8C 001C7B8C 4C01A0C7 */  lwc1       $f0, 0x14C($29)
    /* C7B90 001C7B90 0C01A0E7 */  swc1       $f0, 0x10C($29)
    /* C7B94 001C7B94 F000A0C7 */  lwc1       $f0, 0xF0($29)
    /* C7B98 001C7B98 1001A0E7 */  swc1       $f0, 0x110($29)
    /* C7B9C 001C7B9C CC00A427 */  addiu      $4, $29, 0xCC
    /* C7BA0 001C7BA0 0801A527 */  addiu      $5, $29, 0x108
    /* C7BA4 001C7BA4 F800A627 */  addiu      $6, $29, 0xF8
    /* C7BA8 001C7BA8 6100073C */  lui        $7, %hi(D_0060A0E0)
    /* C7BAC 001C7BAC E0A0E724 */  addiu      $7, $7, %lo(D_0060A0E0)
    /* C7BB0 001C7BB0 E0F5060C */  jal        func_001bd780
    /* C7BB4 001C7BB4 00000000 */   nop
    /* C7BB8 001C7BB8 2801A427 */  addiu      $4, $29, 0x128
    /* C7BBC 001C7BBC 6100053C */  lui        $5, %hi(D_0060A100)
    /* C7BC0 001C7BC0 00A1A524 */  addiu      $5, $5, %lo(D_0060A100)
    /* C7BC4 001C7BC4 01000624 */  addiu      $6, $0, 0x1
    /* C7BC8 001C7BC8 CC00A727 */  addiu      $7, $29, 0xCC
    /* C7BCC 001C7BCC D0720F0C */  jal        func_003dcb40
    /* C7BD0 001C7BD0 00000000 */   nop
    /* C7BD4 001C7BD4 2801A0C7 */  lwc1       $f0, 0x128($29)
    /* C7BD8 001C7BD8 02001446 */  mul.s      $f0, $f0, $f20
    /* C7BDC 001C7BDC 2801A0E7 */  swc1       $f0, 0x128($29)
    /* C7BE0 001C7BE0 2C01A0C7 */  lwc1       $f0, 0x12C($29)
    /* C7BE4 001C7BE4 02001446 */  mul.s      $f0, $f0, $f20
    /* C7BE8 001C7BE8 2C01A0E7 */  swc1       $f0, 0x12C($29)
    /* C7BEC 001C7BEC 3001A0C7 */  lwc1       $f0, 0x130($29)
    /* C7BF0 001C7BF0 02001446 */  mul.s      $f0, $f0, $f20
    /* C7BF4 001C7BF4 3001A0E7 */  swc1       $f0, 0x130($29)
    /* C7BF8 001C7BF8 003F023C */  lui        $2, (0x3F000000 >> 16)
    /* C7BFC 001C7BFC 00088244 */  mtc1       $2, $f1
    /* C7C00 001C7C00 B80040C6 */  lwc1       $f0, 0xB8($18)
    /* C7C04 001C7C04 42080046 */  mul.s      $f1, $f1, $f0
    /* C7C08 001C7C08 108180C7 */  lwc1       $f0, -0x7EF0($28)
    /* C7C0C 001C7C0C 02030146 */  mul.s      $f12, $f0, $f1
    /* C7C10 001C7C10 1A2E110C */  jal        func_0044b868
    /* C7C14 001C7C14 00000000 */   nop
    /* C7C18 001C7C18 42A00046 */  mul.s      $f1, $f20, $f0
    /* C7C1C 001C7C1C 603E023C */  lui        $2, (0x3E600000 >> 16)
    /* C7C20 001C7C20 00008244 */  mtc1       $2, $f0
    /* C7C24 001C7C24 00000000 */  nop
    /* C7C28 001C7C28 42080046 */  mul.s      $f1, $f1, $f0
    /* C7C2C 001C7C2C 2C8180C7 */  lwc1       $f0, -0x7ED4($28)
    /* C7C30 001C7C30 020D0046 */  mul.s      $f20, $f1, $f0
    /* C7C34 001C7C34 2801A0C7 */  lwc1       $f0, 0x128($29)
    /* C7C38 001C7C38 E000A0E7 */  swc1       $f0, 0xE0($29)
    /* C7C3C 001C7C3C 3001A0C7 */  lwc1       $f0, 0x130($29)
    /* C7C40 001C7C40 E400A0E7 */  swc1       $f0, 0xE4($29)
    /* C7C44 001C7C44 E000A427 */  addiu      $4, $29, 0xE0
    /* C7C48 001C7C48 2D288000 */  daddu      $5, $4, $0
    /* C7C4C 001C7C4C 78900F0C */  jal        func_003e41e0
    /* C7C50 001C7C50 00000000 */   nop
    /* C7C54 001C7C54 E400A1C7 */  lwc1       $f1, 0xE4($29)
    /* C7C58 001C7C58 F800A0C7 */  lwc1       $f0, 0xF8($29)
    /* C7C5C 001C7C5C 00108044 */  mtc1       $0, $f2
    /* C7C60 001C7C60 00000000 */  nop
    /* C7C64 001C7C64 18100046 */  adda.s     $f2, $f0
    /* C7C68 001C7C68 DC081446 */  madd.s     $f3, $f1, $f20
    /* C7C6C 001C7C6C F800A3E7 */  swc1       $f3, 0xF8($29)
    /* C7C70 001C7C70 E000A1C7 */  lwc1       $f1, 0xE0($29)
    /* C7C74 001C7C74 0001A0C7 */  lwc1       $f0, 0x100($29)
    /* C7C78 001C7C78 18100046 */  adda.s     $f2, $f0
    /* C7C7C 001C7C7C 9D081446 */  msub.s     $f2, $f1, $f20
    /* C7C80 001C7C80 0001A2E7 */  swc1       $f2, 0x100($29)
    /* C7C84 001C7C84 2801A0C7 */  lwc1       $f0, 0x128($29)
    /* C7C88 001C7C88 00180046 */  add.s      $f0, $f3, $f0
    /* C7C8C 001C7C8C C000A0E7 */  swc1       $f0, 0xC0($29)
    /* C7C90 001C7C90 FC00A1C7 */  lwc1       $f1, 0xFC($29)
    /* C7C94 001C7C94 2C01A0C7 */  lwc1       $f0, 0x12C($29)
    /* C7C98 001C7C98 00080046 */  add.s      $f0, $f1, $f0
    /* C7C9C 001C7C9C C400A0E7 */  swc1       $f0, 0xC4($29)
    /* C7CA0 001C7CA0 3001A0C7 */  lwc1       $f0, 0x130($29)
    /* C7CA4 001C7CA4 00100046 */  add.s      $f0, $f2, $f0
    /* C7CA8 001C7CA8 C800A0E7 */  swc1       $f0, 0xC8($29)
    /* C7CAC 001C7CAC C000A427 */  addiu      $4, $29, 0xC0
    /* C7CB0 001C7CB0 2D288000 */  daddu      $5, $4, $0
    /* C7CB4 001C7CB4 E8F0060C */  jal        func_001bc3a0
    /* C7CB8 001C7CB8 00000000 */   nop
    /* C7CBC 001C7CBC 2D204002 */  daddu      $4, $18, $0
    /* C7CC0 001C7CC0 A000A527 */  addiu      $5, $29, 0xA0
    /* C7CC4 001C7CC4 C000A627 */  addiu      $6, $29, 0xC0
    /* C7CC8 001C7CC8 01000724 */  addiu      $7, $0, 0x1
    /* C7CCC 001C7CCC 08EB060C */  jal        func_001bac20
    /* C7CD0 001C7CD0 00000000 */   nop
    /* C7CD4 001C7CD4 403F023C */  lui        $2, (0x3F400000 >> 16)
    /* C7CD8 001C7CD8 00608244 */  mtc1       $2, $f12
    /* C7CDC 001C7CDC 2D204002 */  daddu      $4, $18, $0
    /* C7CE0 001C7CE0 BCEF060C */  jal        func_001bbef0
    /* C7CE4 001C7CE4 00000000 */   nop
    /* C7CE8 001C7CE8 F5000010 */  b          .L001C80C0
    /* C7CEC 001C7CEC 00000000 */   nop
  .L001C7CF0:
    /* C7CF0 001C7CF0 01000224 */  addiu      $2, $0, 0x1
    /* C7CF4 001C7CF4 480142AE */  sw         $2, 0x148($18)
    /* C7CF8 001C7CF8 E000428E */  lw         $2, 0xE0($18)
    /* C7CFC 001C7CFC 98004424 */  addiu      $4, $2, 0x98
    /* C7D00 001C7D00 F062070C */  jal        func_001d8bc0
    /* C7D04 001C7D04 00000000 */   nop
    /* C7D08 001C7D08 2D884000 */  daddu      $17, $2, $0
    /* C7D0C 001C7D0C 3000508C */  lw         $16, 0x30($2)
    /* C7D10 001C7D10 2C0001C6 */  lwc1       $f1, 0x2C($16)
    /* C7D14 001C7D14 900000C6 */  lwc1       $f0, 0x90($16)
    /* C7D18 001C7D18 02050146 */  mul.s      $f20, $f0, $f1
    /* C7D1C 001C7D1C 8C0000C6 */  lwc1       $f0, 0x8C($16)
    /* C7D20 001C7D20 42000146 */  mul.s      $f1, $f0, $f1
    /* C7D24 001C7D24 003F023C */  lui        $2, (0x3F000000 >> 16)
    /* C7D28 001C7D28 00008244 */  mtc1       $2, $f0
    /* C7D2C 001C7D2C 00000000 */  nop
    /* C7D30 001C7D30 02060146 */  mul.s      $f24, $f0, $f1
    /* C7D34 001C7D34 640A048E */  lw         $4, 0xA64($16)
    /* C7D38 001C7D38 2D280000 */  daddu      $5, $0, $0
    /* C7D3C 001C7D3C 3C0A090C */  jal        func_002428f0
    /* C7D40 001C7D40 00000000 */   nop
    /* C7D44 001C7D44 14004010 */  beqz       $2, .L001C7D98
    /* C7D48 001C7D48 00000000 */   nop
    /* C7D4C 001C7D4C 2D200002 */  daddu      $4, $16, $0
    /* C7D50 001C7D50 3801A527 */  addiu      $5, $29, 0x138
    /* C7D54 001C7D54 5457060C */  jal        func_00195d50
    /* C7D58 001C7D58 00000000 */   nop
    /* C7D5C 001C7D5C C03F023C */  lui        $2, (0x3FC00000 >> 16)
    /* C7D60 001C7D60 00B88244 */  mtc1       $2, $f23
    /* C7D64 001C7D64 6040023C */  lui        $2, (0x40600000 >> 16)
    /* C7D68 001C7D68 00B08244 */  mtc1       $2, $f22
    /* C7D6C 001C7D6C C841023C */  lui        $2, (0x41C80000 >> 16)
    /* C7D70 001C7D70 00A88244 */  mtc1       $2, $f21
    /* C7D74 001C7D74 188182C7 */  lwc1       $f2, -0x7EE8($28)
    /* C7D78 001C7D78 3C01A1C7 */  lwc1       $f1, 0x13C($29)
    /* C7D7C 001C7D7C 00008044 */  mtc1       $0, $f0
    /* C7D80 001C7D80 00000000 */  nop
    /* C7D84 001C7D84 18000146 */  adda.s     $f0, $f1
    /* C7D88 001C7D88 1D101846 */  msub.s     $f0, $f2, $f24
    /* C7D8C 001C7D8C 3C01A0E7 */  swc1       $f0, 0x13C($29)
    /* C7D90 001C7D90 57000010 */  b          .L001C7EF0
    /* C7D94 001C7D94 00000000 */   nop
  .L001C7D98:
    /* C7D98 001C7D98 640A048E */  lw         $4, 0xA64($16)
    /* C7D9C 001C7D9C 1000053C */  lui        $5, (0x100000 >> 16)
    /* C7DA0 001C7DA0 C4C9080C */  jal        func_00232710
    /* C7DA4 001C7DA4 00000000 */   nop
    /* C7DA8 001C7DA8 12004010 */  beqz       $2, .L001C7DF4
    /* C7DAC 001C7DAC 00000000 */   nop
    /* C7DB0 001C7DB0 2D200002 */  daddu      $4, $16, $0
    /* C7DB4 001C7DB4 3801A527 */  addiu      $5, $29, 0x138
    /* C7DB8 001C7DB8 1456060C */  jal        func_00195850
    /* C7DBC 001C7DBC 00000000 */   nop
    /* C7DC0 001C7DC0 308197C7 */  lwc1       $f23, -0x7ED0($28)
    /* C7DC4 001C7DC4 348196C7 */  lwc1       $f22, -0x7ECC($28)
    /* C7DC8 001C7DC8 C841023C */  lui        $2, (0x41C80000 >> 16)
    /* C7DCC 001C7DCC 00A88244 */  mtc1       $2, $f21
    /* C7DD0 001C7DD0 188182C7 */  lwc1       $f2, -0x7EE8($28)
    /* C7DD4 001C7DD4 3C01A1C7 */  lwc1       $f1, 0x13C($29)
    /* C7DD8 001C7DD8 00008044 */  mtc1       $0, $f0
    /* C7DDC 001C7DDC 00000000 */  nop
    /* C7DE0 001C7DE0 18000146 */  adda.s     $f0, $f1
    /* C7DE4 001C7DE4 1D101846 */  msub.s     $f0, $f2, $f24
    /* C7DE8 001C7DE8 3C01A0E7 */  swc1       $f0, 0x13C($29)
    /* C7DEC 001C7DEC 40000010 */  b          .L001C7EF0
    /* C7DF0 001C7DF0 00000000 */   nop
  .L001C7DF4:
    /* C7DF4 001C7DF4 640A048E */  lw         $4, 0xA64($16)
    /* C7DF8 001C7DF8 8C0F090C */  jal        func_00243e30
    /* C7DFC 001C7DFC 00000000 */   nop
    /* C7E00 001C7E00 13004010 */  beqz       $2, .L001C7E50
    /* C7E04 001C7E04 00000000 */   nop
    /* C7E08 001C7E08 2D200002 */  daddu      $4, $16, $0
    /* C7E0C 001C7E0C 3801A527 */  addiu      $5, $29, 0x138
    /* C7E10 001C7E10 1456060C */  jal        func_00195850
    /* C7E14 001C7E14 00000000 */   nop
    /* C7E18 001C7E18 388197C7 */  lwc1       $f23, -0x7EC8($28)
    /* C7E1C 001C7E1C 403F023C */  lui        $2, (0x3F400000 >> 16)
    /* C7E20 001C7E20 00B08244 */  mtc1       $2, $f22
    /* C7E24 001C7E24 7041023C */  lui        $2, (0x41700000 >> 16)
    /* C7E28 001C7E28 00A88244 */  mtc1       $2, $f21
    /* C7E2C 001C7E2C 188182C7 */  lwc1       $f2, -0x7EE8($28)
    /* C7E30 001C7E30 3C01A1C7 */  lwc1       $f1, 0x13C($29)
    /* C7E34 001C7E34 00008044 */  mtc1       $0, $f0
    /* C7E38 001C7E38 00000000 */  nop
    /* C7E3C 001C7E3C 18000146 */  adda.s     $f0, $f1
    /* C7E40 001C7E40 1C101846 */  madd.s     $f0, $f2, $f24
    /* C7E44 001C7E44 3C01A0E7 */  swc1       $f0, 0x13C($29)
    /* C7E48 001C7E48 29000010 */  b          .L001C7EF0
    /* C7E4C 001C7E4C 00000000 */   nop
  .L001C7E50:
    /* C7E50 001C7E50 640A048E */  lw         $4, 0xA64($16)
    /* C7E54 001C7E54 4C0A090C */  jal        func_00242930
    /* C7E58 001C7E58 00000000 */   nop
    /* C7E5C 001C7E5C 13004010 */  beqz       $2, .L001C7EAC
    /* C7E60 001C7E60 00000000 */   nop
    /* C7E64 001C7E64 2D200002 */  daddu      $4, $16, $0
    /* C7E68 001C7E68 3801A527 */  addiu      $5, $29, 0x138
    /* C7E6C 001C7E6C 1456060C */  jal        func_00195850
    /* C7E70 001C7E70 00000000 */   nop
    /* C7E74 001C7E74 388197C7 */  lwc1       $f23, -0x7EC8($28)
    /* C7E78 001C7E78 803F023C */  lui        $2, (0x3F800000 >> 16)
    /* C7E7C 001C7E7C 00B08244 */  mtc1       $2, $f22
    /* C7E80 001C7E80 C841023C */  lui        $2, (0x41C80000 >> 16)
    /* C7E84 001C7E84 00A88244 */  mtc1       $2, $f21
    /* C7E88 001C7E88 308082C7 */  lwc1       $f2, -0x7FD0($28)
    /* C7E8C 001C7E8C 3C01A1C7 */  lwc1       $f1, 0x13C($29)
    /* C7E90 001C7E90 00008044 */  mtc1       $0, $f0
    /* C7E94 001C7E94 00000000 */  nop
    /* C7E98 001C7E98 18000146 */  adda.s     $f0, $f1
    /* C7E9C 001C7E9C 1D101846 */  msub.s     $f0, $f2, $f24
    /* C7EA0 001C7EA0 3C01A0E7 */  swc1       $f0, 0x13C($29)
    /* C7EA4 001C7EA4 12000010 */  b          .L001C7EF0
    /* C7EA8 001C7EA8 00000000 */   nop
  .L001C7EAC:
    /* C7EAC 001C7EAC 2D200002 */  daddu      $4, $16, $0
    /* C7EB0 001C7EB0 3801A527 */  addiu      $5, $29, 0x138
    /* C7EB4 001C7EB4 1456060C */  jal        func_00195850
    /* C7EB8 001C7EB8 00000000 */   nop
    /* C7EBC 001C7EBC A03F023C */  lui        $2, (0x3FA00000 >> 16)
    /* C7EC0 001C7EC0 00B88244 */  mtc1       $2, $f23
    /* C7EC4 001C7EC4 803F023C */  lui        $2, (0x3F800000 >> 16)
    /* C7EC8 001C7EC8 00B08244 */  mtc1       $2, $f22
    /* C7ECC 001C7ECC C841023C */  lui        $2, (0x41C80000 >> 16)
    /* C7ED0 001C7ED0 00A88244 */  mtc1       $2, $f21
    /* C7ED4 001C7ED4 3C8182C7 */  lwc1       $f2, -0x7EC4($28)
    /* C7ED8 001C7ED8 3C01A1C7 */  lwc1       $f1, 0x13C($29)
    /* C7EDC 001C7EDC 00008044 */  mtc1       $0, $f0
    /* C7EE0 001C7EE0 00000000 */  nop
    /* C7EE4 001C7EE4 18000146 */  adda.s     $f0, $f1
    /* C7EE8 001C7EE8 1C101846 */  madd.s     $f0, $f2, $f24
    /* C7EEC 001C7EEC 3C01A0E7 */  swc1       $f0, 0x13C($29)
  .L001C7EF0:
    /* C7EF0 001C7EF0 36A01846 */  c.le.s     $f20, $f24
    /* C7EF4 001C7EF4 11000145 */  bc1t       .L001C7F3C
    /* C7EF8 001C7EF8 00000000 */   nop
    /* C7EFC 001C7EFC 003F023C */  lui        $2, (0x3F000000 >> 16)
    /* C7F00 001C7F00 00088244 */  mtc1       $2, $f1
    /* C7F04 001C7F04 B80040C6 */  lwc1       $f0, 0xB8($18)
    /* C7F08 001C7F08 42080046 */  mul.s      $f1, $f1, $f0
    /* C7F0C 001C7F0C 108180C7 */  lwc1       $f0, -0x7EF0($28)
    /* C7F10 001C7F10 02030146 */  mul.s      $f12, $f0, $f1
    /* C7F14 001C7F14 1A2E110C */  jal        func_0044b868
    /* C7F18 001C7F18 00000000 */   nop
    /* C7F1C 001C7F1C 42A01746 */  mul.s      $f1, $f20, $f23
    /* C7F20 001C7F20 00000000 */  nop
    /* C7F24 001C7F24 030D0046 */  div.s      $f20, $f1, $f0
    /* C7F28 001C7F28 00000000 */  nop
    /* C7F2C 001C7F2C 00000000 */  nop
    /* C7F30 001C7F30 00000000 */  nop
    /* C7F34 001C7F34 0A000010 */  b          .L001C7F60
    /* C7F38 001C7F38 00000000 */   nop
  .L001C7F3C:
    /* C7F3C 001C7F3C 003F023C */  lui        $2, (0x3F000000 >> 16)
    /* C7F40 001C7F40 00088244 */  mtc1       $2, $f1
    /* C7F44 001C7F44 B80040C6 */  lwc1       $f0, 0xB8($18)
    /* C7F48 001C7F48 020B0046 */  mul.s      $f12, $f1, $f0
    /* C7F4C 001C7F4C 1A2E110C */  jal        func_0044b868
    /* C7F50 001C7F50 00000000 */   nop
    /* C7F54 001C7F54 42C01746 */  mul.s      $f1, $f24, $f23
    /* C7F58 001C7F58 00000000 */  nop
    /* C7F5C 001C7F5C 030D0046 */  div.s      $f20, $f1, $f0
  .L001C7F60:
    /* C7F60 001C7F60 2801A427 */  addiu      $4, $29, 0x128
    /* C7F64 001C7F64 6100053C */  lui        $5, %hi(D_0060A0F0)
    /* C7F68 001C7F68 F0A0A524 */  addiu      $5, $5, %lo(D_0060A0F0)
    /* C7F6C 001C7F6C 01000624 */  addiu      $6, $0, 0x1
    /* C7F70 001C7F70 1C000726 */  addiu      $7, $16, 0x1C
    /* C7F74 001C7F74 D0720F0C */  jal        func_003dcb40
    /* C7F78 001C7F78 00000000 */   nop
    /* C7F7C 001C7F7C 6000A427 */  addiu      $4, $29, 0x60
    /* C7F80 001C7F80 6100053C */  lui        $5, %hi(D_0060A0E0)
    /* C7F84 001C7F84 E0A0A524 */  addiu      $5, $5, %lo(D_0060A0E0)
    /* C7F88 001C7F88 06AB0046 */  mov.s      $f12, $f21
    /* C7F8C 001C7F8C 2D300000 */  daddu      $6, $0, $0
    /* C7F90 001C7F90 1C820F0C */  jal        func_003e0870
    /* C7F94 001C7F94 00000000 */   nop
    /* C7F98 001C7F98 2801A427 */  addiu      $4, $29, 0x128
    /* C7F9C 001C7F9C 2D288000 */  daddu      $5, $4, $0
    /* C7FA0 001C7FA0 6000A627 */  addiu      $6, $29, 0x60
    /* C7FA4 001C7FA4 C8900F0C */  jal        func_003e4320
    /* C7FA8 001C7FA8 00000000 */   nop
    /* C7FAC 001C7FAC 003F023C */  lui        $2, (0x3F000000 >> 16)
    /* C7FB0 001C7FB0 00088244 */  mtc1       $2, $f1
    /* C7FB4 001C7FB4 B80040C6 */  lwc1       $f0, 0xB8($18)
    /* C7FB8 001C7FB8 42080046 */  mul.s      $f1, $f1, $f0
    /* C7FBC 001C7FBC 108180C7 */  lwc1       $f0, -0x7EF0($28)
    /* C7FC0 001C7FC0 02030146 */  mul.s      $f12, $f0, $f1
    /* C7FC4 001C7FC4 1A2E110C */  jal        func_0044b868
    /* C7FC8 001C7FC8 00000000 */   nop
    /* C7FCC 001C7FCC 42A00046 */  mul.s      $f1, $f20, $f0
    /* C7FD0 001C7FD0 603E023C */  lui        $2, (0x3E600000 >> 16)
    /* C7FD4 001C7FD4 00008244 */  mtc1       $2, $f0
    /* C7FD8 001C7FD8 00000000 */  nop
    /* C7FDC 001C7FDC 42080046 */  mul.s      $f1, $f1, $f0
    /* C7FE0 001C7FE0 188180C7 */  lwc1       $f0, -0x7EE8($28)
    /* C7FE4 001C7FE4 420D0046 */  mul.s      $f21, $f1, $f0
    /* C7FE8 001C7FE8 2801A0C7 */  lwc1       $f0, 0x128($29)
    /* C7FEC 001C7FEC E000A0E7 */  swc1       $f0, 0xE0($29)
    /* C7FF0 001C7FF0 3001A0C7 */  lwc1       $f0, 0x130($29)
    /* C7FF4 001C7FF4 E400A0E7 */  swc1       $f0, 0xE4($29)
    /* C7FF8 001C7FF8 E000A427 */  addiu      $4, $29, 0xE0
    /* C7FFC 001C7FFC 2D288000 */  daddu      $5, $4, $0
    /* C8000 001C8000 78900F0C */  jal        func_003e41e0
    /* C8004 001C8004 00000000 */   nop
    /* C8008 001C8008 E400A1C7 */  lwc1       $f1, 0xE4($29)
    /* C800C 001C800C 3801A0C7 */  lwc1       $f0, 0x138($29)
    /* C8010 001C8010 00188044 */  mtc1       $0, $f3
    /* C8014 001C8014 00000000 */  nop
    /* C8018 001C8018 18180046 */  adda.s     $f3, $f0
    /* C801C 001C801C 1C091546 */  madd.s     $f4, $f1, $f21
    /* C8020 001C8020 3801A4E7 */  swc1       $f4, 0x138($29)
    /* C8024 001C8024 E000A1C7 */  lwc1       $f1, 0xE0($29)
    /* C8028 001C8028 4001A0C7 */  lwc1       $f0, 0x140($29)
    /* C802C 001C802C 18180046 */  adda.s     $f3, $f0
    /* C8030 001C8030 9D081546 */  msub.s     $f2, $f1, $f21
    /* C8034 001C8034 4001A2E7 */  swc1       $f2, 0x140($29)
    /* C8038 001C8038 2801A0C7 */  lwc1       $f0, 0x128($29)
    /* C803C 001C803C 18180446 */  adda.s     $f3, $f4
    /* C8040 001C8040 1C001446 */  madd.s     $f0, $f0, $f20
    /* C8044 001C8044 C000A0E7 */  swc1       $f0, 0xC0($29)
    /* C8048 001C8048 3C01A1C7 */  lwc1       $f1, 0x13C($29)
    /* C804C 001C804C 2C01A0C7 */  lwc1       $f0, 0x12C($29)
    /* C8050 001C8050 18180146 */  adda.s     $f3, $f1
    /* C8054 001C8054 1C001446 */  madd.s     $f0, $f0, $f20
    /* C8058 001C8058 C400A0E7 */  swc1       $f0, 0xC4($29)
    /* C805C 001C805C 3001A0C7 */  lwc1       $f0, 0x130($29)
    /* C8060 001C8060 18180246 */  adda.s     $f3, $f2
    /* C8064 001C8064 1C001446 */  madd.s     $f0, $f0, $f20
    /* C8068 001C8068 C800A0E7 */  swc1       $f0, 0xC8($29)
    /* C806C 001C806C 18180146 */  adda.s     $f3, $f1
    /* C8070 001C8070 1CC01646 */  madd.s     $f0, $f24, $f22
    /* C8074 001C8074 C400A0E7 */  swc1       $f0, 0xC4($29)
    /* C8078 001C8078 CC00A427 */  addiu      $4, $29, 0xCC
    /* C807C 001C807C C000A527 */  addiu      $5, $29, 0xC0
    /* C8080 001C8080 3801A627 */  addiu      $6, $29, 0x138
    /* C8084 001C8084 6100073C */  lui        $7, %hi(D_0060A0E0)
    /* C8088 001C8088 E0A0E724 */  addiu      $7, $7, %lo(D_0060A0E0)
    /* C808C 001C808C E0F5060C */  jal        func_001bd780
    /* C8090 001C8090 00000000 */   nop
    /* C8094 001C8094 00608044 */  mtc1       $0, $f12
    /* C8098 001C8098 2D202002 */  daddu      $4, $17, $0
    /* C809C 001C809C 2D280000 */  daddu      $5, $0, $0
    /* C80A0 001C80A0 2D300000 */  daddu      $6, $0, $0
    /* C80A4 001C80A4 01000724 */  addiu      $7, $0, 0x1
    /* C80A8 001C80A8 50F3060C */  jal        func_001bcd40
    /* C80AC 001C80AC 00000000 */   nop
    /* C80B0 001C80B0 2D204002 */  daddu      $4, $18, $0
    /* C80B4 001C80B4 C000A527 */  addiu      $5, $29, 0xC0
    /* C80B8 001C80B8 C0EA060C */  jal        func_001bab00
    /* C80BC 001C80BC 00000000 */   nop
  .L001C80C0:
    /* C80C0 001C80C0 5000BFDF */  ld         $31, 0x50($29)
    /* C80C4 001C80C4 4000B27B */  lq         $18, 0x40($29)
    /* C80C8 001C80C8 3000B17B */  lq         $17, 0x30($29)
    /* C80CC 001C80CC 2000B07B */  lq         $16, 0x20($29)
    /* C80D0 001C80D0 1000B8C7 */  lwc1       $f24, 0x10($29)
    /* C80D4 001C80D4 0C00B7C7 */  lwc1       $f23, 0xC($29)
    /* C80D8 001C80D8 0800B6C7 */  lwc1       $f22, 0x8($29)
    /* C80DC 001C80DC 0400B5C7 */  lwc1       $f21, 0x4($29)
    /* C80E0 001C80E0 0000B4C7 */  lwc1       $f20, 0x0($29)
    /* C80E4 001C80E4 5001BD27 */  addiu      $29, $29, 0x150
    /* C80E8 001C80E8 0800E003 */  jr         $31
    /* C80EC 001C80EC 00000000 */   nop
.size func_001c79f0, 0x700
