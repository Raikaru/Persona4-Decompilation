.section .text
.set noat
.set noreorder
glabel func_004c6b60
    /* 3C6B60 004C6B60 0A000224 */  addiu      $2, $0, 0xA
    /* 3C6B64 004C6B64 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 3C6B68 004C6B68 1A008200 */  div        $0, $4, $2
    /* 3C6B6C 004C6B6C 0000B0FF */  sd         $16, 0x0($29)
    /* 3C6B70 004C6B70 0A000324 */  addiu      $3, $0, 0xA
    /* 3C6B74 004C6B74 2D80A000 */  daddu      $16, $5, $0
    /* 3C6B78 004C6B78 1000B2FF */  sd         $18, 0x10($29)
    /* 3C6B7C 004C6B7C 2D90C000 */  daddu      $18, $6, $0
    /* 3C6B80 004C6B80 0800B1FF */  sd         $17, 0x8($29)
    /* 3C6B84 004C6B84 2D280000 */  daddu      $5, $0, $0
    /* 3C6B88 004C6B88 1800BFFF */  sd         $31, 0x18($29)
    /* 3C6B8C 004C6B8C 01004050 */  beql       $2, $0, .L004C6B94
    /* 3C6B90 004C6B90 CD010000 */   break     0, 7
  .L004C6B94:
    /* 3C6B94 004C6B94 12400000 */  mflo       $8
    /* 3C6B98 004C6B98 10380000 */  mfhi       $7
    /* 3C6B9C 004C6B9C 2D200001 */  daddu      $4, $8, $0
    /* 3C6BA0 004C6BA0 000007A2 */  sb         $7, 0x0($16)
    /* 3C6BA4 004C6BA4 04008054 */  bnel       $4, $0, .L004C6BB8
    /* 3C6BA8 004C6BA8 0100A524 */   addiu     $5, $5, 0x1
    /* 3C6BAC 004C6BAC 11000010 */  b          .L004C6BF4
    /* 3C6BB0 004C6BB0 000000A2 */   sb        $0, 0x0($16)
    /* 3C6BB4 004C6BB4 00000000 */  nop
  .L004C6BB8:
    /* 3C6BB8 004C6BB8 2000A228 */  slti       $2, $5, 0x20
    /* 3C6BBC 004C6BBC 0D004010 */  beqz       $2, .L004C6BF4
    /* 3C6BC0 004C6BC0 21300502 */   addu      $6, $16, $5
    /* 3C6BC4 004C6BC4 0A000224 */  addiu      $2, $0, 0xA
    /* 3C6BC8 004C6BC8 0A000324 */  addiu      $3, $0, 0xA
    /* 3C6BCC 004C6BCC 1A008200 */  div        $0, $4, $2
    /* 3C6BD0 004C6BD0 01004050 */  beql       $2, $0, .L004C6BD8
    /* 3C6BD4 004C6BD4 CD010000 */   break     0, 7
  .L004C6BD8:
    /* 3C6BD8 004C6BD8 12400000 */  mflo       $8
    /* 3C6BDC 004C6BDC 10380000 */  mfhi       $7
    /* 3C6BE0 004C6BE0 2D200001 */  daddu      $4, $8, $0
    /* 3C6BE4 004C6BE4 0000C7A0 */  sb         $7, 0x0($6)
    /* 3C6BE8 004C6BE8 F3FF8054 */  bnel       $4, $0, .L004C6BB8
    /* 3C6BEC 004C6BEC 0100A524 */   addiu     $5, $5, 0x1
    /* 3C6BF0 004C6BF0 0000C0A0 */  sb         $0, 0x0($6)
  .L004C6BF4:
    /* 3C6BF4 004C6BF4 9200023C */  lui        $2, %hi(D_00922DF0)
    /* 3C6BF8 004C6BF8 F02D5124 */  addiu      $17, $2, %lo(D_00922DF0)
    /* 3C6BFC 004C6BFC 520A110C */  jal        func_00442948
    /* 3C6C00 004C6C00 2D202002 */   daddu     $4, $17, $0
    /* 3C6C04 004C6C04 2D384000 */  daddu      $7, $2, $0
    /* 3C6C08 004C6C08 FFFF4226 */  addiu      $2, $18, -0x1
    /* 3C6C0C 004C6C0C 2A18E200 */  slt        $3, $7, $2
    /* 3C6C10 004C6C10 0A384300 */  movz       $7, $2, $3
    /* 3C6C14 004C6C14 0B00E018 */  blez       $7, .L004C6C44
    /* 3C6C18 004C6C18 2D280000 */   daddu     $5, $0, $0
    /* 3C6C1C 004C6C1C 2110F100 */  addu       $2, $7, $17
    /* 3C6C20 004C6C20 FFFF4624 */  addiu      $6, $2, -0x1
    /* 3C6C24 004C6C24 00000000 */  nop
  .L004C6C28:
    /* 3C6C28 004C6C28 21200502 */  addu       $4, $16, $5
    /* 3C6C2C 004C6C2C 0100A524 */  addiu      $5, $5, 0x1
    /* 3C6C30 004C6C30 0000C390 */  lbu        $3, 0x0($6)
    /* 3C6C34 004C6C34 FFFFC624 */  addiu      $6, $6, -0x1
    /* 3C6C38 004C6C38 2A10A700 */  slt        $2, $5, $7
    /* 3C6C3C 004C6C3C FAFF4014 */  bnez       $2, .L004C6C28
    /* 3C6C40 004C6C40 000083A0 */   sb        $3, 0x0($4)
  .L004C6C44:
    /* 3C6C44 004C6C44 21100502 */  addu       $2, $16, $5
    /* 3C6C48 004C6C48 0000B0DF */  ld         $16, 0x0($29)
    /* 3C6C4C 004C6C4C 0800B1DF */  ld         $17, 0x8($29)
    /* 3C6C50 004C6C50 1000B2DF */  ld         $18, 0x10($29)
    /* 3C6C54 004C6C54 1800BFDF */  ld         $31, 0x18($29)
    /* 3C6C58 004C6C58 000040A0 */  sb         $0, 0x0($2)
    /* 3C6C5C 004C6C5C 0800E003 */  jr         $31
    /* 3C6C60 004C6C60 2000BD27 */   addiu     $29, $29, 0x20
    /* 3C6C64 004C6C64 00000000 */  nop
.size func_004c6b60, 0x108
