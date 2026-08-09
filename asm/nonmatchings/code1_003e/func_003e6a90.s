.section .text
.set noat
.set noreorder
glabel func_003e6a90
    /* 2E6A90 003E6A90 90FFBD27 */  addiu      $29, $29, -0x70
    /* 2E6A94 003E6A94 01000524 */  addiu      $5, $0, 0x1
    /* 2E6A98 003E6A98 3000BFFF */  sd         $31, 0x30($29)
    /* 2E6A9C 003E6A9C 6800A627 */  addiu      $6, $29, 0x68
    /* 2E6AA0 003E6AA0 2000B27F */  sq         $18, 0x20($29)
    /* 2E6AA4 003E6AA4 6400A727 */  addiu      $7, $29, 0x64
    /* 2E6AA8 003E6AA8 1000B17F */  sq         $17, 0x10($29)
    /* 2E6AAC 003E6AAC 2D908000 */  daddu      $18, $4, $0
    /* 2E6AB0 003E6AB0 147C0F0C */  jal        func_003df050
    /* 2E6AB4 003E6AB4 0000B07F */   sq        $16, 0x0($29)
    /* 2E6AB8 003E6AB8 1B004010 */  beqz       $2, .L003E6B28
    /* 2E6ABC 003E6ABC 00000000 */   nop
    /* 2E6AC0 003E6AC0 6400A38F */  lw         $3, 0x64($29)
    /* 2E6AC4 003E6AC4 0300023C */  lui        $2, (0x35000 >> 16)
    /* 2E6AC8 003E6AC8 00504234 */  ori        $2, $2, (0x35000 & 0xFFFF)
    /* 2E6ACC 003E6ACC 2B106200 */  sltu       $2, $3, $2
    /* 2E6AD0 003E6AD0 A7004014 */  bnez       $2, .L003E6D70
    /* 2E6AD4 003E6AD4 00000000 */   nop
    /* 2E6AD8 003E6AD8 0300013C */  lui        $1, (0x37003 >> 16)
    /* 2E6ADC 003E6ADC 03702134 */  ori        $1, $1, (0x37003 & 0xFFFF)
    /* 2E6AE0 003E6AE0 2B086100 */  sltu       $1, $3, $1
    /* 2E6AE4 003E6AE4 A2002010 */  beqz       $1, .L003E6D70
    /* 2E6AE8 003E6AE8 00000000 */   nop
    /* 2E6AEC 003E6AEC 8800113C */  lui        $17, %hi(D_008872F0)
    /* 2E6AF0 003E6AF0 6000A427 */  addiu      $4, $29, 0x60
    /* 2E6AF4 003E6AF4 2D280000 */  daddu      $5, $0, $0
    /* 2E6AF8 003E6AF8 04000624 */  addiu      $6, $0, 0x4
    /* 2E6AFC 003E6AFC 72FE100C */  jal        func_0043f9c8
    /* 2E6B00 003E6B00 F0723126 */   addiu     $17, $17, %lo(D_008872F0)
    /* 2E6B04 003E6B04 6800B08F */  lw         $16, 0x68($29)
    /* 2E6B08 003E6B08 2D204002 */  daddu      $4, $18, $0
    /* 2E6B0C 003E6B0C 6000A527 */  addiu      $5, $29, 0x60
    /* 2E6B10 003E6B10 448A0F0C */  jal        func_003e2910
    /* 2E6B14 003E6B14 2D300002 */   daddu     $6, $16, $0
    /* 2E6B18 003E6B18 05000212 */  beq        $16, $2, .L003E6B30
    /* 2E6B1C 003E6B1C 00000000 */   nop
    /* 2E6B20 003E6B20 9C000010 */  b          .L003E6D94
    /* 2E6B24 003E6B24 2D100000 */   daddu     $2, $0, $0
  .L003E6B28:
    /* 2E6B28 003E6B28 9A000010 */  b          .L003E6D94
    /* 2E6B2C 003E6B2C 2D100000 */   daddu     $2, $0, $0
  .L003E6B30:
    /* 2E6B30 003E6B30 2D202002 */  daddu      $4, $17, $0
    /* 2E6B34 003E6B34 16000524 */  addiu      $5, $0, 0x16
    /* 2E6B38 003E6B38 6E00A627 */  addiu      $6, $29, 0x6E
    /* 2E6B3C 003E6B3C 2D380000 */  daddu      $7, $0, $0
    /* 2E6B40 003E6B40 2D400000 */  daddu      $8, $0, $0
    /* 2E6B44 003E6B44 FCA10F0C */  jal        func_003e87f0
    /* 2E6B48 003E6B48 6E00A0A7 */   sh        $0, 0x6E($29)
    /* 2E6B4C 003E6B4C 6E00A293 */  lbu        $2, 0x6E($29)
    /* 2E6B50 003E6B50 6E00A2A7 */  sh         $2, 0x6E($29)
    /* 2E6B54 003E6B54 6E00A397 */  lhu        $3, 0x6E($29)
    /* 2E6B58 003E6B58 08006010 */  beqz       $3, .L003E6B7C
    /* 2E6B5C 003E6B5C 00000000 */   nop
    /* 2E6B60 003E6B60 6200A297 */  lhu        $2, 0x62($29)
    /* 2E6B64 003E6B64 05004010 */  beqz       $2, .L003E6B7C
    /* 2E6B68 003E6B68 00000000 */   nop
    /* 2E6B6C 003E6B6C 03006210 */  beq        $3, $2, .L003E6B7C
    /* 2E6B70 003E6B70 00000000 */   nop
    /* 2E6B74 003E6B74 87000010 */  b          .L003E6D94
    /* 2E6B78 003E6B78 2D100000 */   daddu     $2, $0, $0
  .L003E6B7C:
    /* 2E6B7C 003E6B7C 34BC0F0C */  jal        func_003ef0d0
    /* 2E6B80 003E6B80 00000000 */   nop
    /* 2E6B84 003E6B84 2D884000 */  daddu      $17, $2, $0
    /* 2E6B88 003E6B88 42002012 */  beqz       $17, .L003E6C94
    /* 2E6B8C 003E6B8C 00000000 */   nop
    /* 2E6B90 003E6B90 6000A397 */  lhu        $3, 0x60($29)
    /* 2E6B94 003E6B94 FFFF6224 */  addiu      $2, $3, -0x1
    /* 2E6B98 003E6B98 35006010 */  beqz       $3, .L003E6C70
    /* 2E6B9C 003E6B9C 6000A2A7 */   sh        $2, 0x60($29)
    /* 2E6BA0 003E6BA0 8800103C */  lui        $16, %hi(D_00887390)
    /* 2E6BA4 003E6BA4 90731026 */  addiu      $16, $16, %lo(D_00887390)
  .L003E6BA8:
    /* 2E6BA8 003E6BA8 2D204002 */  daddu      $4, $18, $0
    /* 2E6BAC 003E6BAC 15000524 */  addiu      $5, $0, 0x15
    /* 2E6BB0 003E6BB0 6800A627 */  addiu      $6, $29, 0x68
    /* 2E6BB4 003E6BB4 147C0F0C */  jal        func_003df050
    /* 2E6BB8 003E6BB8 6400A727 */   addiu     $7, $29, 0x64
    /* 2E6BBC 003E6BBC 0A004014 */  bnez       $2, .L003E6BE8
    /* 2E6BC0 003E6BC0 00000000 */   nop
    /* 2E6BC4 003E6BC4 3E00053C */  lui        $5, %hi(func_003e6a60)
    /* 2E6BC8 003E6BC8 2D202002 */  daddu      $4, $17, $0
    /* 2E6BCC 003E6BCC 606AA524 */  addiu      $5, $5, %lo(func_003e6a60)
    /* 2E6BD0 003E6BD0 98BC0F0C */  jal        func_003ef260
    /* 2E6BD4 003E6BD4 2D300000 */   daddu     $6, $0, $0
    /* 2E6BD8 003E6BD8 6CBC0F0C */  jal        func_003ef1b0
    /* 2E6BDC 003E6BDC 2D202002 */   daddu     $4, $17, $0
    /* 2E6BE0 003E6BE0 6C000010 */  b          .L003E6D94
    /* 2E6BE4 003E6BE4 2D100000 */   daddu     $2, $0, $0
  .L003E6BE8:
    /* 2E6BE8 003E6BE8 6400A38F */  lw         $3, 0x64($29)
    /* 2E6BEC 003E6BEC 0300023C */  lui        $2, (0x35000 >> 16)
    /* 2E6BF0 003E6BF0 00504234 */  ori        $2, $2, (0x35000 & 0xFFFF)
    /* 2E6BF4 003E6BF4 2B106200 */  sltu       $2, $3, $2
    /* 2E6BF8 003E6BF8 28004014 */  bnez       $2, .L003E6C9C
    /* 2E6BFC 003E6BFC 00000000 */   nop
    /* 2E6C00 003E6C00 0300013C */  lui        $1, (0x37003 >> 16)
    /* 2E6C04 003E6C04 03702134 */  ori        $1, $1, (0x37003 & 0xFFFF)
    /* 2E6C08 003E6C08 2B086100 */  sltu       $1, $3, $1
    /* 2E6C0C 003E6C0C 23002010 */  beqz       $1, .L003E6C9C
    /* 2E6C10 003E6C10 00000000 */   nop
    /* 2E6C14 003E6C14 6800A68F */  lw         $6, 0x68($29)
    /* 2E6C18 003E6C18 2D204002 */  daddu      $4, $18, $0
    /* 2E6C1C 003E6C1C 0000028E */  lw         $2, 0x0($16)
    /* 2E6C20 003E6C20 09F84000 */  jalr       $2
    /* 2E6C24 003E6C24 5C00A527 */   addiu     $5, $29, 0x5C
    /* 2E6C28 003E6C28 2D004010 */  beqz       $2, .L003E6CE0
    /* 2E6C2C 003E6C2C 00000000 */   nop
    /* 2E6C30 003E6C30 5C00A68F */  lw         $6, 0x5C($29)
    /* 2E6C34 003E6C34 3300C010 */  beqz       $6, .L003E6D04
    /* 2E6C38 003E6C38 00000000 */   nop
    /* 2E6C3C 003E6C3C 7100043C */  lui        $4, %hi(D_0070B800)
    /* 2E6C40 003E6C40 2D284002 */  daddu      $5, $18, $0
    /* 2E6C44 003E6C44 448C0F0C */  jal        func_003e3110
    /* 2E6C48 003E6C48 00B88424 */   addiu     $4, $4, %lo(D_0070B800)
    /* 2E6C4C 003E6C4C 36004010 */  beqz       $2, .L003E6D28
    /* 2E6C50 003E6C50 00000000 */   nop
    /* 2E6C54 003E6C54 5C00A58F */  lw         $5, 0x5C($29)
    /* 2E6C58 003E6C58 6CBD0F0C */  jal        func_003ef5b0
    /* 2E6C5C 003E6C5C 2D202002 */   daddu     $4, $17, $0
    /* 2E6C60 003E6C60 6000A397 */  lhu        $3, 0x60($29)
    /* 2E6C64 003E6C64 FFFF6224 */  addiu      $2, $3, -0x1
    /* 2E6C68 003E6C68 CFFF6014 */  bnez       $3, .L003E6BA8
    /* 2E6C6C 003E6C6C 6000A2A7 */   sh        $2, 0x60($29)
  .L003E6C70:
    /* 2E6C70 003E6C70 7100043C */  lui        $4, %hi(D_0070B820)
    /* 2E6C74 003E6C74 2D284002 */  daddu      $5, $18, $0
    /* 2E6C78 003E6C78 20B88424 */  addiu      $4, $4, %lo(D_0070B820)
    /* 2E6C7C 003E6C7C 448C0F0C */  jal        func_003e3110
    /* 2E6C80 003E6C80 2D302002 */   daddu     $6, $17, $0
    /* 2E6C84 003E6C84 31004010 */  beqz       $2, .L003E6D4C
    /* 2E6C88 003E6C88 00000000 */   nop
    /* 2E6C8C 003E6C8C 41000010 */  b          .L003E6D94
    /* 2E6C90 003E6C90 2D102002 */   daddu     $2, $17, $0
  .L003E6C94:
    /* 2E6C94 003E6C94 3F000010 */  b          .L003E6D94
    /* 2E6C98 003E6C98 2D100000 */   daddu     $2, $0, $0
  .L003E6C9C:
    /* 2E6C9C 003E6C9C 3E00053C */  lui        $5, %hi(func_003e6a60)
    /* 2E6CA0 003E6CA0 2D202002 */  daddu      $4, $17, $0
    /* 2E6CA4 003E6CA4 606AA524 */  addiu      $5, $5, %lo(func_003e6a60)
    /* 2E6CA8 003E6CA8 98BC0F0C */  jal        func_003ef260
    /* 2E6CAC 003E6CAC 2D300000 */   daddu     $6, $0, $0
    /* 2E6CB0 003E6CB0 6CBC0F0C */  jal        func_003ef1b0
    /* 2E6CB4 003E6CB4 2D202002 */   daddu     $4, $17, $0
    /* 2E6CB8 003E6CB8 01000324 */  addiu      $3, $0, 0x1
    /* 2E6CBC 003E6CBC 0080023C */  lui        $2, (0x80000004 >> 16)
    /* 2E6CC0 003E6CC0 5000A3AF */  sw         $3, 0x50($29)
    /* 2E6CC4 003E6CC4 647D0F0C */  jal        func_003df590
    /* 2E6CC8 003E6CC8 04004434 */   ori       $4, $2, (0x80000004 & 0xFFFF)
    /* 2E6CCC 003E6CCC 5400A2AF */  sw         $2, 0x54($29)
    /* 2E6CD0 003E6CD0 347D0F0C */  jal        func_003df4d0
    /* 2E6CD4 003E6CD4 5000A427 */   addiu     $4, $29, 0x50
    /* 2E6CD8 003E6CD8 2E000010 */  b          .L003E6D94
    /* 2E6CDC 003E6CDC 2D100000 */   daddu     $2, $0, $0
  .L003E6CE0:
    /* 2E6CE0 003E6CE0 3E00053C */  lui        $5, %hi(func_003e6a60)
    /* 2E6CE4 003E6CE4 2D202002 */  daddu      $4, $17, $0
    /* 2E6CE8 003E6CE8 606AA524 */  addiu      $5, $5, %lo(func_003e6a60)
    /* 2E6CEC 003E6CEC 98BC0F0C */  jal        func_003ef260
    /* 2E6CF0 003E6CF0 2D300000 */   daddu     $6, $0, $0
    /* 2E6CF4 003E6CF4 6CBC0F0C */  jal        func_003ef1b0
    /* 2E6CF8 003E6CF8 2D202002 */   daddu     $4, $17, $0
    /* 2E6CFC 003E6CFC 25000010 */  b          .L003E6D94
    /* 2E6D00 003E6D00 2D100000 */   daddu     $2, $0, $0
  .L003E6D04:
    /* 2E6D04 003E6D04 3E00053C */  lui        $5, %hi(func_003e6a60)
    /* 2E6D08 003E6D08 2D202002 */  daddu      $4, $17, $0
    /* 2E6D0C 003E6D0C 606AA524 */  addiu      $5, $5, %lo(func_003e6a60)
    /* 2E6D10 003E6D10 98BC0F0C */  jal        func_003ef260
    /* 2E6D14 003E6D14 2D300000 */   daddu     $6, $0, $0
    /* 2E6D18 003E6D18 6CBC0F0C */  jal        func_003ef1b0
    /* 2E6D1C 003E6D1C 2D202002 */   daddu     $4, $17, $0
    /* 2E6D20 003E6D20 1C000010 */  b          .L003E6D94
    /* 2E6D24 003E6D24 2D100000 */   daddu     $2, $0, $0
  .L003E6D28:
    /* 2E6D28 003E6D28 3E00053C */  lui        $5, %hi(func_003e6a60)
    /* 2E6D2C 003E6D2C 2D202002 */  daddu      $4, $17, $0
    /* 2E6D30 003E6D30 606AA524 */  addiu      $5, $5, %lo(func_003e6a60)
    /* 2E6D34 003E6D34 98BC0F0C */  jal        func_003ef260
    /* 2E6D38 003E6D38 2D300000 */   daddu     $6, $0, $0
    /* 2E6D3C 003E6D3C 6CBC0F0C */  jal        func_003ef1b0
    /* 2E6D40 003E6D40 2D202002 */   daddu     $4, $17, $0
    /* 2E6D44 003E6D44 13000010 */  b          .L003E6D94
    /* 2E6D48 003E6D48 2D100000 */   daddu     $2, $0, $0
  .L003E6D4C:
    /* 2E6D4C 003E6D4C 3E00053C */  lui        $5, %hi(func_003e6a60)
    /* 2E6D50 003E6D50 2D202002 */  daddu      $4, $17, $0
    /* 2E6D54 003E6D54 606AA524 */  addiu      $5, $5, %lo(func_003e6a60)
    /* 2E6D58 003E6D58 98BC0F0C */  jal        func_003ef260
    /* 2E6D5C 003E6D5C 2D300000 */   daddu     $6, $0, $0
    /* 2E6D60 003E6D60 6CBC0F0C */  jal        func_003ef1b0
    /* 2E6D64 003E6D64 2D202002 */   daddu     $4, $17, $0
    /* 2E6D68 003E6D68 0A000010 */  b          .L003E6D94
    /* 2E6D6C 003E6D6C 2D100000 */   daddu     $2, $0, $0
  .L003E6D70:
    /* 2E6D70 003E6D70 01000324 */  addiu      $3, $0, 0x1
    /* 2E6D74 003E6D74 0080023C */  lui        $2, (0x80000004 >> 16)
    /* 2E6D78 003E6D78 4800A3AF */  sw         $3, 0x48($29)
    /* 2E6D7C 003E6D7C 647D0F0C */  jal        func_003df590
    /* 2E6D80 003E6D80 04004434 */   ori       $4, $2, (0x80000004 & 0xFFFF)
    /* 2E6D84 003E6D84 4C00A2AF */  sw         $2, 0x4C($29)
    /* 2E6D88 003E6D88 347D0F0C */  jal        func_003df4d0
    /* 2E6D8C 003E6D8C 4800A427 */   addiu     $4, $29, 0x48
    /* 2E6D90 003E6D90 2D100000 */  daddu      $2, $0, $0
  .L003E6D94:
    /* 2E6D94 003E6D94 3000BFDF */  ld         $31, 0x30($29)
    /* 2E6D98 003E6D98 2000B27B */  lq         $18, 0x20($29)
    /* 2E6D9C 003E6D9C 1000B17B */  lq         $17, 0x10($29)
    /* 2E6DA0 003E6DA0 0000B07B */  lq         $16, 0x0($29)
    /* 2E6DA4 003E6DA4 0800E003 */  jr         $31
    /* 2E6DA8 003E6DA8 7000BD27 */   addiu     $29, $29, 0x70
    /* 2E6DAC 003E6DAC 00000000 */  nop
.size func_003e6a90, 0x320
