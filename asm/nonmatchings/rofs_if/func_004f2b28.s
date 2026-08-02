.section .text
.set noat
.set noreorder
glabel func_004f2b28
    /* 3F2B28 004F2B28 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 3F2B2C 004F2B2C 0000B0FF */  sd         $16, 0x0($29)
    /* 3F2B30 004F2B30 2D808000 */  daddu      $16, $4, $0
    /* 3F2B34 004F2B34 0800B1FF */  sd         $17, 0x8($29)
    /* 3F2B38 004F2B38 2D88A000 */  daddu      $17, $5, $0
    /* 3F2B3C 004F2B3C 1000B2FF */  sd         $18, 0x10($29)
    /* 3F2B40 004F2B40 1800BFFF */  sd         $31, 0x18($29)
    /* 3F2B44 004F2B44 28D5130C */  jal        func_004f54a0
    /* 3F2B48 004F2B48 2D90C000 */   daddu     $18, $6, $0
    /* 3F2B4C 004F2B4C 7400023C */  lui        $2, %hi(D_00743A48)
    /* 3F2B50 004F2B50 2D200002 */  daddu      $4, $16, $0
    /* 3F2B54 004F2B54 483A428C */  lw         $2, %lo(D_00743A48)($2)
    /* 3F2B58 004F2B58 2D282002 */  daddu      $5, $17, $0
    /* 3F2B5C 004F2B5C 2D304002 */  daddu      $6, $18, $0
    /* 3F2B60 004F2B60 2D380000 */  daddu      $7, $0, $0
    /* 3F2B64 004F2B64 0A004010 */  beqz       $2, .L004F2B90
    /* 3F2B68 004F2B68 35FF0824 */   addiu     $8, $0, -0xCB
    /* 3F2B6C 004F2B6C 6000428C */  lw         $2, 0x60($2)
    /* 3F2B70 004F2B70 09F84000 */  jalr       $2
    /* 3F2B74 004F2B74 00000000 */   nop
    /* 3F2B78 004F2B78 0000B0DF */  ld         $16, 0x0($29)
    /* 3F2B7C 004F2B7C 0800B1DF */  ld         $17, 0x8($29)
    /* 3F2B80 004F2B80 1000B2DF */  ld         $18, 0x10($29)
    /* 3F2B84 004F2B84 1800BFDF */  ld         $31, 0x18($29)
    /* 3F2B88 004F2B88 0800E003 */  jr         $31
    /* 3F2B8C 004F2B8C 2000BD27 */   addiu     $29, $29, 0x20
  .L004F2B90:
    /* 3F2B90 004F2B90 7600043C */  lui        $4, %hi(D_0075D488)
    /* 3F2B94 004F2B94 7600063C */  lui        $6, %hi(D_0075D600)
    /* 3F2B98 004F2B98 0000B0DF */  ld         $16, 0x0($29)
    /* 3F2B9C 004F2B9C 88D48424 */  addiu      $4, $4, %lo(D_0075D488)
    /* 3F2BA0 004F2BA0 0800B1DF */  ld         $17, 0x8($29)
    /* 3F2BA4 004F2BA4 00D6C624 */  addiu      $6, $6, %lo(D_0075D600)
    /* 3F2BA8 004F2BA8 1000B2DF */  ld         $18, 0x10($29)
    /* 3F2BAC 004F2BAC 14020524 */  addiu      $5, $0, 0x214
    /* 3F2BB0 004F2BB0 1800BFDF */  ld         $31, 0x18($29)
    /* 3F2BB4 004F2BB4 F0D41308 */  j          func_004f53c0
    /* 3F2BB8 004F2BB8 2000BD27 */   addiu     $29, $29, 0x20
    /* 3F2BBC 004F2BBC 00000000 */  nop
.size func_004f2b28, 0x98
