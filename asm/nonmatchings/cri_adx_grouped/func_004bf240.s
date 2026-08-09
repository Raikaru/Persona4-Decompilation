.section .text
.set noat
.set noreorder
glabel func_004bf240
    /* 3BF240 004BF240 D0FFBD27 */  addiu      $29, $29, -0x30
    /* 3BF244 004BF244 0000B0FF */  sd         $16, 0x0($29)
    /* 3BF248 004BF248 2D808000 */  daddu      $16, $4, $0
    /* 3BF24C 004BF24C 0800B1FF */  sd         $17, 0x8($29)
    /* 3BF250 004BF250 1000B2FF */  sd         $18, 0x10($29)
    /* 3BF254 004BF254 1800B3FF */  sd         $19, 0x18($29)
    /* 3BF258 004BF258 2000BFFF */  sd         $31, 0x20($29)
    /* 3BF25C 004BF25C 5000028E */  lw         $2, 0x50($16)
    /* 3BF260 004BF260 0B004054 */  bnel       $2, $0, .L004BF290
    /* 3BF264 004BF264 9800028E */   lw        $2, 0x98($16)
    /* 3BF268 004BF268 7500043C */  lui        $4, %hi(D_00756FE0)
    /* 3BF26C 004BF26C 0000B0DF */  ld         $16, 0x0($29)
    /* 3BF270 004BF270 0800B1DF */  ld         $17, 0x8($29)
    /* 3BF274 004BF274 E06F8424 */  addiu      $4, $4, %lo(D_00756FE0)
    /* 3BF278 004BF278 1000B2DF */  ld         $18, 0x10($29)
    /* 3BF27C 004BF27C 1800B3DF */  ld         $19, 0x18($29)
    /* 3BF280 004BF280 2000BFDF */  ld         $31, 0x20($29)
    /* 3BF284 004BF284 A8F51208 */  j          func_004bd6a0
    /* 3BF288 004BF288 3000BD27 */   addiu     $29, $29, 0x30
    /* 3BF28C 004BF28C 00000000 */  nop
  .L004BF290:
    /* 3BF290 004BF290 0B004054 */  bnel       $2, $0, .L004BF2C0
    /* 3BF294 004BF294 A000028E */   lw        $2, 0xA0($16)
    /* 3BF298 004BF298 7500043C */  lui        $4, %hi(D_00757010)
    /* 3BF29C 004BF29C 0000B0DF */  ld         $16, 0x0($29)
    /* 3BF2A0 004BF2A0 0800B1DF */  ld         $17, 0x8($29)
    /* 3BF2A4 004BF2A4 10708424 */  addiu      $4, $4, %lo(D_00757010)
    /* 3BF2A8 004BF2A8 1000B2DF */  ld         $18, 0x10($29)
    /* 3BF2AC 004BF2AC 1800B3DF */  ld         $19, 0x18($29)
    /* 3BF2B0 004BF2B0 2000BFDF */  ld         $31, 0x20($29)
    /* 3BF2B4 004BF2B4 A8F51208 */  j          func_004bd6a0
    /* 3BF2B8 004BF2B8 3000BD27 */   addiu     $29, $29, 0x30
    /* 3BF2BC 004BF2BC 00000000 */  nop
  .L004BF2C0:
    /* 3BF2C0 004BF2C0 1C004018 */  blez       $2, .L004BF334
    /* 3BF2C4 004BF2C4 2D880000 */   daddu     $17, $0, $0
    /* 3BF2C8 004BF2C8 01001324 */  addiu      $19, $0, 0x1
    /* 3BF2CC 004BF2CC 2D900000 */  daddu      $18, $0, $0
    /* 3BF2D0 004BF2D0 9400028E */  lw         $2, 0x94($16)
    /* 3BF2D4 004BF2D4 00000000 */  nop
  .L004BF2D8:
    /* 3BF2D8 004BF2D8 09005314 */  bne        $2, $19, .L004BF300
    /* 3BF2DC 004BF2DC 2D282002 */   daddu     $5, $17, $0
    /* 3BF2E0 004BF2E0 AAFD120C */  jal        func_004bf6a8
    /* 3BF2E4 004BF2E4 2D200002 */   daddu     $4, $16, $0
    /* 3BF2E8 004BF2E8 2D280000 */  daddu      $5, $0, $0
    /* 3BF2EC 004BF2EC B07B130C */  jal        func_004deec0
    /* 3BF2F0 004BF2F0 2D204000 */   daddu     $4, $2, $0
    /* 3BF2F4 004BF2F4 05000010 */  b          .L004BF30C
    /* 3BF2F8 004BF2F8 6C00058E */   lw        $5, 0x6C($16)
    /* 3BF2FC 004BF2FC 00000000 */  nop
  .L004BF300:
    /* 3BF300 004BF300 44FD120C */  jal        func_004bf510
    /* 3BF304 004BF304 2D200002 */   daddu     $4, $16, $0
    /* 3BF308 004BF308 6C00058E */  lw         $5, 0x6C($16)
  .L004BF30C:
    /* 3BF30C 004BF30C 2D204000 */  daddu      $4, $2, $0
    /* 3BF310 004BF310 00300624 */  addiu      $6, $0, 0x3000
    /* 3BF314 004BF314 01003126 */  addiu      $17, $17, 0x1
    /* 3BF318 004BF318 2128B200 */  addu       $5, $5, $18
    /* 3BF31C 004BF31C 946C130C */  jal        func_004db250
    /* 3BF320 004BF320 00305226 */   addiu     $18, $18, 0x3000
    /* 3BF324 004BF324 A000028E */  lw         $2, 0xA0($16)
    /* 3BF328 004BF328 2A102202 */  slt        $2, $17, $2
    /* 3BF32C 004BF32C EAFF4054 */  bnel       $2, $0, .L004BF2D8
    /* 3BF330 004BF330 9400028E */   lw        $2, 0x94($16)
  .L004BF334:
    /* 3BF334 004BF334 0000B0DF */  ld         $16, 0x0($29)
    /* 3BF338 004BF338 0800B1DF */  ld         $17, 0x8($29)
    /* 3BF33C 004BF33C 1000B2DF */  ld         $18, 0x10($29)
    /* 3BF340 004BF340 1800B3DF */  ld         $19, 0x18($29)
    /* 3BF344 004BF344 2000BFDF */  ld         $31, 0x20($29)
    /* 3BF348 004BF348 0800E003 */  jr         $31
    /* 3BF34C 004BF34C 3000BD27 */   addiu     $29, $29, 0x30
.size func_004bf240, 0x110
