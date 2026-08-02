.section .text
.set noat
.set noreorder
glabel func_004f4ce8
    /* 3F4CE8 004F4CE8 D0FFBD27 */  addiu      $29, $29, -0x30
    /* 3F4CEC 004F4CEC 2000B2FF */  sd         $18, 0x20($29)
    /* 3F4CF0 004F4CF0 2D90A000 */  daddu      $18, $5, $0
    /* 3F4CF4 004F4CF4 1000B0FF */  sd         $16, 0x10($29)
    /* 3F4CF8 004F4CF8 1800B1FF */  sd         $17, 0x18($29)
    /* 3F4CFC 004F4CFC 0C004016 */  bnez       $18, .L004F4D30
    /* 3F4D00 004F4D00 2800BFFF */   sd        $31, 0x28($29)
    /* 3F4D04 004F4D04 7600043C */  lui        $4, %hi(D_0075D6C8)
    /* 3F4D08 004F4D08 7600063C */  lui        $6, %hi(D_0075D7E0)
    /* 3F4D0C 004F4D0C C8D68424 */  addiu      $4, $4, %lo(D_0075D6C8)
    /* 3F4D10 004F4D10 E0D7C624 */  addiu      $6, $6, %lo(D_0075D7E0)
    /* 3F4D14 004F4D14 27070524 */  addiu      $5, $0, 0x727
    /* 3F4D18 004F4D18 2D380000 */  daddu      $7, $0, $0
    /* 3F4D1C 004F4D1C F0D4130C */  jal        func_004f53c0
    /* 3F4D20 004F4D20 9CFF0824 */   addiu     $8, $0, -0x64
    /* 3F4D24 004F4D24 61000010 */  b          .L004F4EAC
    /* 3F4D28 004F4D28 1000B0DF */   ld        $16, 0x10($29)
    /* 3F4D2C 004F4D2C 00000000 */  nop
  .L004F4D30:
    /* 3F4D30 004F4D30 A0CB130C */  jal        func_004f2e80
    /* 3F4D34 004F4D34 01000524 */   addiu     $5, $0, 0x1
    /* 3F4D38 004F4D38 2D884000 */  daddu      $17, $2, $0
    /* 3F4D3C 004F4D3C 0C002016 */  bnez       $17, .L004F4D70
    /* 3F4D40 004F4D40 2D200000 */   daddu     $4, $0, $0
    /* 3F4D44 004F4D44 7600043C */  lui        $4, %hi(D_0075D6C8)
    /* 3F4D48 004F4D48 7600063C */  lui        $6, %hi(D_0075D798)
    /* 3F4D4C 004F4D4C C8D68424 */  addiu      $4, $4, %lo(D_0075D6C8)
    /* 3F4D50 004F4D50 98D7C624 */  addiu      $6, $6, %lo(D_0075D798)
    /* 3F4D54 004F4D54 2D070524 */  addiu      $5, $0, 0x72D
    /* 3F4D58 004F4D58 2D380000 */  daddu      $7, $0, $0
    /* 3F4D5C 004F4D5C F0D4130C */  jal        func_004f53c0
    /* 3F4D60 004F4D60 97FF0824 */   addiu     $8, $0, -0x69
    /* 3F4D64 004F4D64 51000010 */  b          .L004F4EAC
    /* 3F4D68 004F4D68 1000B0DF */   ld        $16, 0x10($29)
    /* 3F4D6C 004F4D6C 00000000 */  nop
  .L004F4D70:
    /* 3F4D70 004F4D70 2D280000 */  daddu      $5, $0, $0
    /* 3F4D74 004F4D74 34D7130C */  jal        func_004f5cd0
    /* 3F4D78 004F4D78 2D30A003 */   daddu     $6, $29, $0
    /* 3F4D7C 004F4D7C 01000324 */  addiu      $3, $0, 0x1
    /* 3F4D80 004F4D80 0000A28F */  lw         $2, 0x0($29)
    /* 3F4D84 004F4D84 04004314 */  bne        $2, $3, .L004F4D98
    /* 3F4D88 004F4D88 7600043C */   lui       $4, %hi(D_0075D7D0)
    /* 3F4D8C 004F4D8C 100032AE */  sw         $18, 0x10($17)
    /* 3F4D90 004F4D90 45000010 */  b          .L004F4EA8
    /* 3F4D94 004F4D94 2D100000 */   daddu     $2, $0, $0
  .L004F4D98:
    /* 3F4D98 004F4D98 0C005026 */  addiu      $16, $18, 0xC
    /* 3F4D9C 004F4D9C D0D78424 */  addiu      $4, $4, %lo(D_0075D7D0)
    /* 3F4DA0 004F4DA0 BA09110C */  jal        func_004426e8
    /* 3F4DA4 004F4DA4 2D280002 */   daddu     $5, $16, $0
    /* 3F4DA8 004F4DA8 0F004010 */  beqz       $2, .L004F4DE8
    /* 3F4DAC 004F4DAC 2D280002 */   daddu     $5, $16, $0
    /* 3F4DB0 004F4DB0 BA09110C */  jal        func_004426e8
    /* 3F4DB4 004F4DB4 16002426 */   addiu     $4, $17, 0x16
    /* 3F4DB8 004F4DB8 0B004010 */  beqz       $2, .L004F4DE8
    /* 3F4DBC 004F4DBC 7600043C */   lui       $4, %hi(D_0075D6C8)
    /* 3F4DC0 004F4DC0 7600063C */  lui        $6, %hi(D_0075D7E0)
    /* 3F4DC4 004F4DC4 C8D68424 */  addiu      $4, $4, %lo(D_0075D6C8)
    /* 3F4DC8 004F4DC8 E0D7C624 */  addiu      $6, $6, %lo(D_0075D7E0)
    /* 3F4DCC 004F4DCC 3D070524 */  addiu      $5, $0, 0x73D
    /* 3F4DD0 004F4DD0 2D380000 */  daddu      $7, $0, $0
    /* 3F4DD4 004F4DD4 F0D4130C */  jal        func_004f53c0
    /* 3F4DD8 004F4DD8 94FF0824 */   addiu     $8, $0, -0x6C
    /* 3F4DDC 004F4DDC 33000010 */  b          .L004F4EAC
    /* 3F4DE0 004F4DE0 1000B0DF */   ld        $16, 0x10($29)
    /* 3F4DE4 004F4DE4 00000000 */  nop
  .L004F4DE8:
    /* 3F4DE8 004F4DE8 1000248E */  lw         $4, 0x10($17)
    /* 3F4DEC 004F4DEC 18004926 */  addiu      $9, $18, 0x18
    /* 3F4DF0 004F4DF0 00004A8E */  lw         $10, 0x0($18)
    /* 3F4DF4 004F4DF4 2D400000 */  daddu      $8, $0, $0
    /* 3F4DF8 004F4DF8 0400858C */  lw         $5, 0x4($4)
    /* 3F4DFC 004F4DFC 18008624 */  addiu      $6, $4, 0x18
    /* 3F4E00 004F4E00 2D384001 */  daddu      $7, $10, $0
    /* 3F4E04 004F4E04 0800438E */  lw         $3, 0x8($18)
    /* 3F4E08 004F4E08 2A104501 */  slt        $2, $10, $5
    /* 3F4E0C 004F4E0C 0A38A200 */  movz       $7, $5, $2
    /* 3F4E10 004F4E10 2100E018 */  blez       $7, .L004F4E98
    /* 3F4E14 004F4E14 080083AC */   sw        $3, 0x8($4)
    /* 3F4E18 004F4E18 2D40E000 */  daddu      $8, $7, $0
    /* 3F4E1C 004F4E1C 00000000 */  nop
  .L004F4E20:
    /* 3F4E20 004F4E20 07002269 */  ldl        $2, 0x7($9)
    /* 3F4E24 004F4E24 0000226D */  ldr        $2, 0x0($9)
    /* 3F4E28 004F4E28 0F002369 */  ldl        $3, 0xF($9)
    /* 3F4E2C 004F4E2C 0800236D */  ldr        $3, 0x8($9)
    /* 3F4E30 004F4E30 17002B69 */  ldl        $11, 0x17($9)
    /* 3F4E34 004F4E34 10002B6D */  ldr        $11, 0x10($9)
    /* 3F4E38 004F4E38 1F002C69 */  ldl        $12, 0x1F($9)
    /* 3F4E3C 004F4E3C 18002C6D */  ldr        $12, 0x18($9)
    /* 3F4E40 004F4E40 0700C2B0 */  sdl        $2, 0x7($6)
    /* 3F4E44 004F4E44 0000C2B4 */  sdr        $2, 0x0($6)
    /* 3F4E48 004F4E48 0F00C3B0 */  sdl        $3, 0xF($6)
    /* 3F4E4C 004F4E4C 0800C3B4 */  sdr        $3, 0x8($6)
    /* 3F4E50 004F4E50 1700CBB0 */  sdl        $11, 0x17($6)
    /* 3F4E54 004F4E54 1000CBB4 */  sdr        $11, 0x10($6)
    /* 3F4E58 004F4E58 1F00CCB0 */  sdl        $12, 0x1F($6)
    /* 3F4E5C 004F4E5C 1800CCB4 */  sdr        $12, 0x18($6)
    /* 3F4E60 004F4E60 27002269 */  ldl        $2, 0x27($9)
    /* 3F4E64 004F4E64 2000226D */  ldr        $2, 0x20($9)
    /* 3F4E68 004F4E68 2F002369 */  ldl        $3, 0x2F($9)
    /* 3F4E6C 004F4E6C 2800236D */  ldr        $3, 0x28($9)
    /* 3F4E70 004F4E70 2700C2B0 */  sdl        $2, 0x27($6)
    /* 3F4E74 004F4E74 2000C2B4 */  sdr        $2, 0x20($6)
    /* 3F4E78 004F4E78 2F00C3B0 */  sdl        $3, 0x2F($6)
    /* 3F4E7C 004F4E7C FFFF0825 */  addiu      $8, $8, -0x1
    /* 3F4E80 004F4E80 2800C3B4 */  sdr        $3, 0x28($6)
    /* 3F4E84 004F4E84 3000C624 */  addiu      $6, $6, 0x30
    /* 3F4E88 004F4E88 00000000 */  nop
    /* 3F4E8C 004F4E8C E4FF0015 */  bnez       $8, .L004F4E20
    /* 3F4E90 004F4E90 30002925 */   addiu     $9, $9, 0x30
    /* 3F4E94 004F4E94 2D40E000 */  daddu      $8, $7, $0
  .L004F4E98:
    /* 3F4E98 004F4E98 2A18AA00 */  slt        $3, $5, $10
    /* 3F4E9C 004F4E9C 93FF0224 */  addiu      $2, $0, -0x6D
    /* 3F4EA0 004F4EA0 000088AC */  sw         $8, 0x0($4)
    /* 3F4EA4 004F4EA4 0A100300 */  movz       $2, $0, $3
  .L004F4EA8:
    /* 3F4EA8 004F4EA8 1000B0DF */  ld         $16, 0x10($29)
  .L004F4EAC:
    /* 3F4EAC 004F4EAC 1800B1DF */  ld         $17, 0x18($29)
    /* 3F4EB0 004F4EB0 2000B2DF */  ld         $18, 0x20($29)
    /* 3F4EB4 004F4EB4 2800BFDF */  ld         $31, 0x28($29)
    /* 3F4EB8 004F4EB8 0800E003 */  jr         $31
    /* 3F4EBC 004F4EBC 3000BD27 */   addiu     $29, $29, 0x30
.size func_004f4ce8, 0x1d8
