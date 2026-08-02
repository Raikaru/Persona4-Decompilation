.section .text
.set noat
.set noreorder
glabel func_004f5a20
    /* 3F5A20 004F5A20 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 3F5A24 004F5A24 2D188000 */  daddu      $3, $4, $0
    /* 3F5A28 004F5A28 0000B0FF */  sd         $16, 0x0($29)
    /* 3F5A2C 004F5A2C 2D80C000 */  daddu      $16, $6, $0
    /* 3F5A30 004F5A30 0800B1FF */  sd         $17, 0x8($29)
    /* 3F5A34 004F5A34 2D88A000 */  daddu      $17, $5, $0
    /* 3F5A38 004F5A38 1000BFFF */  sd         $31, 0x10($29)
    /* 3F5A3C 004F5A3C 0C006014 */  bnez       $3, .L004F5A70
    /* 3F5A40 004F5A40 A4090524 */   addiu     $5, $0, 0x9A4
    /* 3F5A44 004F5A44 7600043C */  lui        $4, %hi(D_0075D6C8)
    /* 3F5A48 004F5A48 7600063C */  lui        $6, %hi(D_0075D9D0)
    /* 3F5A4C 004F5A4C 0000B0DF */  ld         $16, 0x0($29)
    /* 3F5A50 004F5A50 C8D68424 */  addiu      $4, $4, %lo(D_0075D6C8)
    /* 3F5A54 004F5A54 0800B1DF */  ld         $17, 0x8($29)
    /* 3F5A58 004F5A58 D0D9C624 */  addiu      $6, $6, %lo(D_0075D9D0)
    /* 3F5A5C 004F5A5C 1000BFDF */  ld         $31, 0x10($29)
    /* 3F5A60 004F5A60 2D380000 */  daddu      $7, $0, $0
    /* 3F5A64 004F5A64 9CFF0824 */  addiu      $8, $0, -0x64
    /* 3F5A68 004F5A68 F0D41308 */  j          func_004f53c0
    /* 3F5A6C 004F5A6C 2000BD27 */   addiu     $29, $29, 0x20
  .L004F5A70:
    /* 3F5A70 004F5A70 0D002106 */  bgez       $17, .L004F5AA8
    /* 3F5A74 004F5A74 7600043C */   lui       $4, %hi(D_0075D6C8)
    /* 3F5A78 004F5A78 7600063C */  lui        $6, %hi(D_0075D9D0)
    /* 3F5A7C 004F5A7C 0000B0DF */  ld         $16, 0x0($29)
    /* 3F5A80 004F5A80 C8D68424 */  addiu      $4, $4, %lo(D_0075D6C8)
    /* 3F5A84 004F5A84 0800B1DF */  ld         $17, 0x8($29)
    /* 3F5A88 004F5A88 D0D9C624 */  addiu      $6, $6, %lo(D_0075D9D0)
    /* 3F5A8C 004F5A8C 1000BFDF */  ld         $31, 0x10($29)
    /* 3F5A90 004F5A90 A7090524 */  addiu      $5, $0, 0x9A7
    /* 3F5A94 004F5A94 2D380000 */  daddu      $7, $0, $0
    /* 3F5A98 004F5A98 9CFF0824 */  addiu      $8, $0, -0x64
    /* 3F5A9C 004F5A9C F0D41308 */  j          func_004f53c0
    /* 3F5AA0 004F5AA0 2000BD27 */   addiu     $29, $29, 0x20
    /* 3F5AA4 004F5AA4 00000000 */  nop
  .L004F5AA8:
    /* 3F5AA8 004F5AA8 0D000056 */  bnel       $16, $0, .L004F5AE0
    /* 3F5AAC 004F5AAC 0000028E */   lw        $2, 0x0($16)
    /* 3F5AB0 004F5AB0 7600043C */  lui        $4, %hi(D_0075D6C8)
    /* 3F5AB4 004F5AB4 7600063C */  lui        $6, %hi(D_0075D9D0)
    /* 3F5AB8 004F5AB8 0000B0DF */  ld         $16, 0x0($29)
    /* 3F5ABC 004F5ABC C8D68424 */  addiu      $4, $4, %lo(D_0075D6C8)
    /* 3F5AC0 004F5AC0 0800B1DF */  ld         $17, 0x8($29)
    /* 3F5AC4 004F5AC4 D0D9C624 */  addiu      $6, $6, %lo(D_0075D9D0)
    /* 3F5AC8 004F5AC8 1000BFDF */  ld         $31, 0x10($29)
    /* 3F5ACC 004F5ACC AA090524 */  addiu      $5, $0, 0x9AA
    /* 3F5AD0 004F5AD0 2D380000 */  daddu      $7, $0, $0
    /* 3F5AD4 004F5AD4 9CFF0824 */  addiu      $8, $0, -0x64
    /* 3F5AD8 004F5AD8 F0D41308 */  j          func_004f53c0
    /* 3F5ADC 004F5ADC 2000BD27 */   addiu     $29, $29, 0x20
  .L004F5AE0:
    /* 3F5AE0 004F5AE0 0D004014 */  bnez       $2, .L004F5B18
    /* 3F5AE4 004F5AE4 2D204000 */   daddu     $4, $2, $0
    /* 3F5AE8 004F5AE8 7600043C */  lui        $4, %hi(D_0075D6C8)
    /* 3F5AEC 004F5AEC 7600063C */  lui        $6, %hi(D_0075D9D0)
    /* 3F5AF0 004F5AF0 0000B0DF */  ld         $16, 0x0($29)
    /* 3F5AF4 004F5AF4 C8D68424 */  addiu      $4, $4, %lo(D_0075D6C8)
    /* 3F5AF8 004F5AF8 0800B1DF */  ld         $17, 0x8($29)
    /* 3F5AFC 004F5AFC D0D9C624 */  addiu      $6, $6, %lo(D_0075D9D0)
    /* 3F5B00 004F5B00 1000BFDF */  ld         $31, 0x10($29)
    /* 3F5B04 004F5B04 AD090524 */  addiu      $5, $0, 0x9AD
    /* 3F5B08 004F5B08 2D380000 */  daddu      $7, $0, $0
    /* 3F5B0C 004F5B0C 9CFF0824 */  addiu      $8, $0, -0x64
    /* 3F5B10 004F5B10 F0D41308 */  j          func_004f53c0
    /* 3F5B14 004F5B14 2000BD27 */   addiu     $29, $29, 0x20
  .L004F5B18:
    /* 3F5B18 004F5B18 0400078E */  lw         $7, 0x4($16)
    /* 3F5B1C 004F5B1C 2D286000 */  daddu      $5, $3, $0
    /* 3F5B20 004F5B20 24D6130C */  jal        func_004f5890
    /* 3F5B24 004F5B24 2D302002 */   daddu     $6, $17, $0
    /* 3F5B28 004F5B28 0400038E */  lw         $3, 0x4($16)
    /* 3F5B2C 004F5B2C 1000BFDF */  ld         $31, 0x10($29)
    /* 3F5B30 004F5B30 2D100000 */  daddu      $2, $0, $0
    /* 3F5B34 004F5B34 21187100 */  addu       $3, $3, $17
    /* 3F5B38 004F5B38 0800B1DF */  ld         $17, 0x8($29)
    /* 3F5B3C 004F5B3C 040003AE */  sw         $3, 0x4($16)
    /* 3F5B40 004F5B40 0000B0DF */  ld         $16, 0x0($29)
    /* 3F5B44 004F5B44 0800E003 */  jr         $31
    /* 3F5B48 004F5B48 2000BD27 */   addiu     $29, $29, 0x20
    /* 3F5B4C 004F5B4C 00000000 */  nop
.size func_004f5a20, 0x130
