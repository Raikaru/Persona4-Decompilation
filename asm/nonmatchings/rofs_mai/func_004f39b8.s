.section .text
.set noat
.set noreorder
glabel func_004f39b8
    /* 3F39B8 004F39B8 10F0BD27 */  addiu      $29, $29, -0xFF0
    /* 3F39BC 004F39BC C80FB3FF */  sd         $19, 0xFC8($29)
    /* 3F39C0 004F39C0 2D98A000 */  daddu      $19, $5, $0
    /* 3F39C4 004F39C4 2D280000 */  daddu      $5, $0, $0
    /* 3F39C8 004F39C8 B00FB0FF */  sd         $16, 0xFB0($29)
    /* 3F39CC 004F39CC D80FB5FF */  sd         $21, 0xFD8($29)
    /* 3F39D0 004F39D0 2DA8C000 */  daddu      $21, $6, $0
    /* 3F39D4 004F39D4 B80FB1FF */  sd         $17, 0xFB8($29)
    /* 3F39D8 004F39D8 C00FB2FF */  sd         $18, 0xFC0($29)
    /* 3F39DC 004F39DC D00FB4FF */  sd         $20, 0xFD0($29)
    /* 3F39E0 004F39E0 E00FBFFF */  sd         $31, 0xFE0($29)
    /* 3F39E4 004F39E4 A0CB130C */  jal        func_004f2e80
    /* 3F39E8 004F39E8 2D808000 */   daddu     $16, $4, $0
    /* 3F39EC 004F39EC 0A004010 */  beqz       $2, .L004F3A18
    /* 3F39F0 004F39F0 7600043C */   lui       $4, %hi(D_0075D6C8)
    /* 3F39F4 004F39F4 7600063C */  lui        $6, %hi(D_0075D708)
    /* 3F39F8 004F39F8 C8D68424 */  addiu      $4, $4, %lo(D_0075D6C8)
    /* 3F39FC 004F39FC 08D7C624 */  addiu      $6, $6, %lo(D_0075D708)
    /* 3F3A00 004F3A00 DE030524 */  addiu      $5, $0, 0x3DE
    /* 3F3A04 004F3A04 2D380000 */  daddu      $7, $0, $0
    /* 3F3A08 004F3A08 F0D4130C */  jal        func_004f53c0
    /* 3F3A0C 004F3A0C 98FF0824 */   addiu     $8, $0, -0x68
    /* 3F3A10 004F3A10 BC000010 */  b          .L004F3D04
    /* 3F3A14 004F3A14 B00FB0DF */   ld        $16, 0xFB0($29)
  .L004F3A18:
    /* 3F3A18 004F3A18 2D200002 */  daddu      $4, $16, $0
    /* 3F3A1C 004F3A1C D6CB130C */  jal        func_004f2f58
    /* 3F3A20 004F3A20 2D286002 */   daddu     $5, $19, $0
    /* 3F3A24 004F3A24 2D884000 */  daddu      $17, $2, $0
    /* 3F3A28 004F3A28 07002016 */  bnez       $17, .L004F3A48
    /* 3F3A2C 004F3A2C 7400023C */   lui       $2, %hi(D_00743A50)
    /* 3F3A30 004F3A30 7600043C */  lui        $4, %hi(D_0075D6C8)
    /* 3F3A34 004F3A34 7600063C */  lui        $6, %hi(D_0075D718)
    /* 3F3A38 004F3A38 C8D68424 */  addiu      $4, $4, %lo(D_0075D6C8)
    /* 3F3A3C 004F3A3C 18D7C624 */  addiu      $6, $6, %lo(D_0075D718)
    /* 3F3A40 004F3A40 7C000010 */  b          .L004F3C34
    /* 3F3A44 004F3A44 E5030524 */   addiu     $5, $0, 0x3E5
  .L004F3A48:
    /* 3F3A48 004F3A48 2D280000 */  daddu      $5, $0, $0
    /* 3F3A4C 004F3A4C 503A438C */  lw         $3, %lo(D_00743A50)($2)
    /* 3F3A50 004F3A50 2D300000 */  daddu      $6, $0, $0
    /* 3F3A54 004F3A54 2D380000 */  daddu      $7, $0, $0
    /* 3F3A58 004F3A58 2D400000 */  daddu      $8, $0, $0
    /* 3F3A5C 004F3A5C C2C5130C */  jal        func_004f1708
    /* 3F3A60 004F3A60 2000648C */   lw        $4, 0x20($3)
    /* 3F3A64 004F3A64 2D904000 */  daddu      $18, $2, $0
    /* 3F3A68 004F3A68 0D004016 */  bnez       $18, .L004F3AA0
    /* 3F3A6C 004F3A6C 2D204002 */   daddu     $4, $18, $0
    /* 3F3A70 004F3A70 30CC130C */  jal        func_004f30c0
    /* 3F3A74 004F3A74 2D202002 */   daddu     $4, $17, $0
    /* 3F3A78 004F3A78 7600043C */  lui        $4, %hi(D_0075D6C8)
    /* 3F3A7C 004F3A7C 7600063C */  lui        $6, %hi(D_0075D728)
    /* 3F3A80 004F3A80 C8D68424 */  addiu      $4, $4, %lo(D_0075D6C8)
    /* 3F3A84 004F3A84 28D7C624 */  addiu      $6, $6, %lo(D_0075D728)
    /* 3F3A88 004F3A88 F1030524 */  addiu      $5, $0, 0x3F1
    /* 3F3A8C 004F3A8C 2D380000 */  daddu      $7, $0, $0
    /* 3F3A90 004F3A90 F0D4130C */  jal        func_004f53c0
    /* 3F3A94 004F3A94 32FF0824 */   addiu     $8, $0, -0xCE
    /* 3F3A98 004F3A98 9A000010 */  b          .L004F3D04
    /* 3F3A9C 004F3A9C B00FB0DF */   ld        $16, 0xFB0($29)
  .L004F3AA0:
    /* 3F3AA0 004F3AA0 EAC5130C */  jal        func_004f17a8
    /* 3F3AA4 004F3AA4 2D286002 */   daddu     $5, $19, $0
    /* 3F3AA8 004F3AA8 01001424 */  addiu      $20, $0, 0x1
    /* 3F3AAC 004F3AAC 0E005414 */  bne        $2, $20, .L004F3AE8
    /* 3F3AB0 004F3AB0 00000000 */   nop
    /* 3F3AB4 004F3AB4 30CC130C */  jal        func_004f30c0
    /* 3F3AB8 004F3AB8 2D202002 */   daddu     $4, $17, $0
    /* 3F3ABC 004F3ABC 7600043C */  lui        $4, %hi(D_0075D6C8)
    /* 3F3AC0 004F3AC0 7600063C */  lui        $6, %hi(D_0075D708)
    /* 3F3AC4 004F3AC4 C8D68424 */  addiu      $4, $4, %lo(D_0075D6C8)
    /* 3F3AC8 004F3AC8 08D7C624 */  addiu      $6, $6, %lo(D_0075D708)
    /* 3F3ACC 004F3ACC F7030524 */  addiu      $5, $0, 0x3F7
    /* 3F3AD0 004F3AD0 2D380000 */  daddu      $7, $0, $0
    /* 3F3AD4 004F3AD4 F0D4130C */  jal        func_004f53c0
    /* 3F3AD8 004F3AD8 38FF0824 */   addiu     $8, $0, -0xC8
    /* 3F3ADC 004F3ADC 89000010 */  b          .L004F3D04
    /* 3F3AE0 004F3AE0 B00FB0DF */   ld        $16, 0xFB0($29)
    /* 3F3AE4 004F3AE4 00000000 */  nop
  .L004F3AE8:
    /* 3F3AE8 004F3AE8 08DA130C */  jal        func_004f6820
    /* 3F3AEC 004F3AEC 00000000 */   nop
    /* 3F3AF0 004F3AF0 2D804000 */  daddu      $16, $2, $0
    /* 3F3AF4 004F3AF4 0A000012 */  beqz       $16, .L004F3B20
    /* 3F3AF8 004F3AF8 00000000 */   nop
    /* 3F3AFC 004F3AFC 30CC130C */  jal        func_004f30c0
    /* 3F3B00 004F3B00 2D202002 */   daddu     $4, $17, $0
    /* 3F3B04 004F3B04 7600043C */  lui        $4, %hi(D_0075D6C8)
    /* 3F3B08 004F3B08 7600063C */  lui        $6, %hi(D_0075D738)
    /* 3F3B0C 004F3B0C C8D68424 */  addiu      $4, $4, %lo(D_0075D6C8)
    /* 3F3B10 004F3B10 38D7C624 */  addiu      $6, $6, %lo(D_0075D738)
    /* 3F3B14 004F3B14 2D400002 */  daddu      $8, $16, $0
    /* 3F3B18 004F3B18 1B000010 */  b          .L004F3B88
    /* 3F3B1C 004F3B1C 00040524 */   addiu     $5, $0, 0x400
  .L004F3B20:
    /* 3F3B20 004F3B20 42CC130C */  jal        func_004f3108
    /* 3F3B24 004F3B24 2D206002 */   daddu     $4, $19, $0
    /* 3F3B28 004F3B28 07005414 */  bne        $2, $20, .L004F3B48
    /* 3F3B2C 004F3B2C 7007B327 */   addiu     $19, $29, 0x770
    /* 3F3B30 004F3B30 2D20A003 */  daddu      $4, $29, $0
    /* 3F3B34 004F3B34 96CC130C */  jal        func_004f3258
    /* 3F3B38 004F3B38 2D286002 */   daddu     $5, $19, $0
    /* 3F3B3C 004F3B3C 08000010 */  b          .L004F3B60
    /* 3F3B40 004F3B40 2D804000 */   daddu     $16, $2, $0
    /* 3F3B44 004F3B44 00000000 */  nop
  .L004F3B48:
    /* 3F3B48 004F3B48 2D38A002 */  daddu      $7, $21, $0
    /* 3F3B4C 004F3B4C 2D202002 */  daddu      $4, $17, $0
    /* 3F3B50 004F3B50 2D28A003 */  daddu      $5, $29, $0
    /* 3F3B54 004F3B54 54CC130C */  jal        func_004f3150
    /* 3F3B58 004F3B58 2D306002 */   daddu     $6, $19, $0
    /* 3F3B5C 004F3B5C 2D804000 */  daddu      $16, $2, $0
  .L004F3B60:
    /* 3F3B60 004F3B60 0D000012 */  beqz       $16, .L004F3B98
    /* 3F3B64 004F3B64 2D204002 */   daddu     $4, $18, $0
    /* 3F3B68 004F3B68 4ACF130C */  jal        func_004f3d28
    /* 3F3B6C 004F3B6C 2D282002 */   daddu     $5, $17, $0
    /* 3F3B70 004F3B70 7600043C */  lui        $4, %hi(D_0075D6C8)
    /* 3F3B74 004F3B74 7600063C */  lui        $6, %hi(D_0075D750)
    /* 3F3B78 004F3B78 C8D68424 */  addiu      $4, $4, %lo(D_0075D6C8)
    /* 3F3B7C 004F3B7C 50D7C624 */  addiu      $6, $6, %lo(D_0075D750)
    /* 3F3B80 004F3B80 2D400002 */  daddu      $8, $16, $0
    /* 3F3B84 004F3B84 14040524 */  addiu      $5, $0, 0x414
  .L004F3B88:
    /* 3F3B88 004F3B88 F0D4130C */  jal        func_004f53c0
    /* 3F3B8C 004F3B8C 2D380000 */   daddu     $7, $0, $0
    /* 3F3B90 004F3B90 5C000010 */  b          .L004F3D04
    /* 3F3B94 004F3B94 B00FB0DF */   ld        $16, 0xFB0($29)
  .L004F3B98:
    /* 3F3B98 004F3B98 6C00A28F */  lw         $2, 0x6C($29)
    /* 3F3B9C 004F3B9C 2D286002 */  daddu      $5, $19, $0
    /* 3F3BA0 004F3BA0 040022AE */  sw         $2, 0x4($17)
    /* 3F3BA4 004F3BA4 0F00A26B */  ldl        $2, 0xF($29)
    /* 3F3BA8 004F3BA8 0800A26F */  ldr        $2, 0x8($29)
    /* 3F3BAC 004F3BAC 330022B2 */  sdl        $2, 0x33($17)
    /* 3F3BB0 004F3BB0 2C0022B6 */  sdr        $2, 0x2C($17)
    /* 3F3BB4 004F3BB4 D0CC130C */  jal        func_004f3340
    /* 3F3BB8 004F3BB8 2D202002 */   daddu     $4, $17, $0
    /* 3F3BBC 004F3BBC 2D804000 */  daddu      $16, $2, $0
    /* 3F3BC0 004F3BC0 0D000016 */  bnez       $16, .L004F3BF8
    /* 3F3BC4 004F3BC4 2D204002 */   daddu     $4, $18, $0
    /* 3F3BC8 004F3BC8 4ACF130C */  jal        func_004f3d28
    /* 3F3BCC 004F3BCC 2D282002 */   daddu     $5, $17, $0
    /* 3F3BD0 004F3BD0 7600043C */  lui        $4, %hi(D_0075D6C8)
    /* 3F3BD4 004F3BD4 7600063C */  lui        $6, %hi(D_0075D760)
    /* 3F3BD8 004F3BD8 C8D68424 */  addiu      $4, $4, %lo(D_0075D6C8)
    /* 3F3BDC 004F3BDC 60D7C624 */  addiu      $6, $6, %lo(D_0075D760)
    /* 3F3BE0 004F3BE0 27040524 */  addiu      $5, $0, 0x427
    /* 3F3BE4 004F3BE4 2D380000 */  daddu      $7, $0, $0
    /* 3F3BE8 004F3BE8 F0D4130C */  jal        func_004f53c0
    /* 3F3BEC 004F3BEC 31FF0824 */   addiu     $8, $0, -0xCF
    /* 3F3BF0 004F3BF0 44000010 */  b          .L004F3D04
    /* 3F3BF4 004F3BF4 B00FB0DF */   ld        $16, 0xFB0($29)
  .L004F3BF8:
    /* 3F3BF8 004F3BF8 4ACF130C */  jal        func_004f3d28
    /* 3F3BFC 004F3BFC 2D280000 */   daddu     $5, $0, $0
    /* 3F3C00 004F3C00 F0CA130C */  jal        func_004f2bc0
    /* 3F3C04 004F3C04 2D200002 */   daddu     $4, $16, $0
    /* 3F3C08 004F3C08 2D904000 */  daddu      $18, $2, $0
    /* 3F3C0C 004F3C0C 01000224 */  addiu      $2, $0, 0x1
    /* 3F3C10 004F3C10 0D004212 */  beq        $18, $2, .L004F3C48
    /* 3F3C14 004F3C14 A007B327 */   addiu     $19, $29, 0x7A0
    /* 3F3C18 004F3C18 30CC130C */  jal        func_004f30c0
    /* 3F3C1C 004F3C1C 2D202002 */   daddu     $4, $17, $0
    /* 3F3C20 004F3C20 7600043C */  lui        $4, %hi(D_0075D6C8)
    /* 3F3C24 004F3C24 7600063C */  lui        $6, %hi(D_0075D768)
    /* 3F3C28 004F3C28 C8D68424 */  addiu      $4, $4, %lo(D_0075D6C8)
    /* 3F3C2C 004F3C2C 68D7C624 */  addiu      $6, $6, %lo(D_0075D768)
    /* 3F3C30 004F3C30 34040524 */  addiu      $5, $0, 0x434
  .L004F3C34:
    /* 3F3C34 004F3C34 2D380000 */  daddu      $7, $0, $0
    /* 3F3C38 004F3C38 F0D4130C */  jal        func_004f53c0
    /* 3F3C3C 004F3C3C 97FF0824 */   addiu     $8, $0, -0x69
    /* 3F3C40 004F3C40 30000010 */  b          .L004F3D04
    /* 3F3C44 004F3C44 B00FB0DF */   ld        $16, 0xFB0($29)
  .L004F3C48:
    /* 3F3C48 004F3C48 2D280002 */  daddu      $5, $16, $0
    /* 3F3C4C 004F3C4C 4ED7130C */  jal        func_004f5d38
    /* 3F3C50 004F3C50 2D206002 */   daddu     $4, $19, $0
    /* 3F3C54 004F3C54 2D200000 */  daddu      $4, $0, $0
    /* 3F3C58 004F3C58 2C08A28F */  lw         $2, 0x82C($29)
    /* 3F3C5C 004F3C5C 2D280000 */  daddu      $5, $0, $0
    /* 3F3C60 004F3C60 A00FA627 */  addiu      $6, $29, 0xFA0
    /* 3F3C64 004F3C64 080022AE */  sw         $2, 0x8($17)
    /* 3F3C68 004F3C68 2408A38F */  lw         $3, 0x824($29)
    /* 3F3C6C 004F3C6C 34D7130C */  jal        func_004f5cd0
    /* 3F3C70 004F3C70 0C0023AE */   sw        $3, 0xC($17)
    /* 3F3C74 004F3C74 A00FA38F */  lw         $3, 0xFA0($29)
    /* 3F3C78 004F3C78 21007210 */  beq        $3, $18, .L004F3D00
    /* 3F3C7C 004F3C7C 2D100000 */   daddu     $2, $0, $0
    /* 3F3C80 004F3C80 1000268E */  lw         $6, 0x10($17)
    /* 3F3C84 004F3C84 2D286002 */  daddu      $5, $19, $0
    /* 3F3C88 004F3C88 F8CC130C */  jal        func_004f33e0
    /* 3F3C8C 004F3C8C 2D202002 */   daddu     $4, $17, $0
    /* 3F3C90 004F3C90 93FF0324 */  addiu      $3, $0, -0x6D
    /* 3F3C94 004F3C94 2D804000 */  daddu      $16, $2, $0
    /* 3F3C98 004F3C98 0D000316 */  bne        $16, $3, .L004F3CD0
    /* 3F3C9C 004F3C9C 00000000 */   nop
    /* 3F3CA0 004F3CA0 30CC130C */  jal        func_004f30c0
    /* 3F3CA4 004F3CA4 2D202002 */   daddu     $4, $17, $0
    /* 3F3CA8 004F3CA8 7600043C */  lui        $4, %hi(D_0075D6C8)
    /* 3F3CAC 004F3CAC 7600063C */  lui        $6, %hi(D_0075D778)
    /* 3F3CB0 004F3CB0 C8D68424 */  addiu      $4, $4, %lo(D_0075D6C8)
    /* 3F3CB4 004F3CB4 78D7C624 */  addiu      $6, $6, %lo(D_0075D778)
    /* 3F3CB8 004F3CB8 5B040524 */  addiu      $5, $0, 0x45B
    /* 3F3CBC 004F3CBC 2D380000 */  daddu      $7, $0, $0
    /* 3F3CC0 004F3CC0 F0D4130C */  jal        func_004f53c0
    /* 3F3CC4 004F3CC4 93FF0824 */   addiu     $8, $0, -0x6D
    /* 3F3CC8 004F3CC8 0E000010 */  b          .L004F3D04
    /* 3F3CCC 004F3CCC B00FB0DF */   ld        $16, 0xFB0($29)
  .L004F3CD0:
    /* 3F3CD0 004F3CD0 0C000052 */  beql       $16, $0, .L004F3D04
    /* 3F3CD4 004F3CD4 B00FB0DF */   ld        $16, 0xFB0($29)
    /* 3F3CD8 004F3CD8 30CC130C */  jal        func_004f30c0
    /* 3F3CDC 004F3CDC 2D202002 */   daddu     $4, $17, $0
    /* 3F3CE0 004F3CE0 7600043C */  lui        $4, %hi(D_0075D6C8)
    /* 3F3CE4 004F3CE4 7600063C */  lui        $6, %hi(D_0075D778)
    /* 3F3CE8 004F3CE8 C8D68424 */  addiu      $4, $4, %lo(D_0075D6C8)
    /* 3F3CEC 004F3CEC 78D7C624 */  addiu      $6, $6, %lo(D_0075D778)
    /* 3F3CF0 004F3CF0 2D400002 */  daddu      $8, $16, $0
    /* 3F3CF4 004F3CF4 5F040524 */  addiu      $5, $0, 0x45F
    /* 3F3CF8 004F3CF8 F0D4130C */  jal        func_004f53c0
    /* 3F3CFC 004F3CFC 2D380000 */   daddu     $7, $0, $0
  .L004F3D00:
    /* 3F3D00 004F3D00 B00FB0DF */  ld         $16, 0xFB0($29)
  .L004F3D04:
    /* 3F3D04 004F3D04 B80FB1DF */  ld         $17, 0xFB8($29)
    /* 3F3D08 004F3D08 C00FB2DF */  ld         $18, 0xFC0($29)
    /* 3F3D0C 004F3D0C C80FB3DF */  ld         $19, 0xFC8($29)
    /* 3F3D10 004F3D10 D00FB4DF */  ld         $20, 0xFD0($29)
    /* 3F3D14 004F3D14 D80FB5DF */  ld         $21, 0xFD8($29)
    /* 3F3D18 004F3D18 E00FBFDF */  ld         $31, 0xFE0($29)
    /* 3F3D1C 004F3D1C 0800E003 */  jr         $31
    /* 3F3D20 004F3D20 F00FBD27 */   addiu     $29, $29, 0xFF0
    /* 3F3D24 004F3D24 00000000 */  nop
.size func_004f39b8, 0x370
