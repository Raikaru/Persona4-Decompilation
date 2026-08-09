.section .text
.set noat
.set noreorder
glabel func_003fe210
    /* 2FE210 003FE210 2A080500 */  slt        $1, $0, $5
    /* 2FE214 003FE214 2C002010 */  beqz       $1, .L003FE2C8
    /* 2FE218 003FE218 2D580000 */   daddu     $11, $0, $0
    /* 2FE21C 003FE21C 0900A128 */  slti       $1, $5, 0x9
    /* 2FE220 003FE220 1B002014 */  bnez       $1, .L003FE290
    /* 2FE224 003FE224 F8FFA924 */   addiu     $9, $5, -0x8
    /* 2FE228 003FE228 2A08A000 */  slt        $1, $5, $0
    /* 2FE22C 003FE22C 07002014 */  bnez       $1, .L003FE24C
    /* 2FE230 003FE230 2D180000 */   daddu     $3, $0, $0
    /* 2FE234 003FE234 FF7F013C */  lui        $1, (0x7FFFFFFF >> 16)
    /* 2FE238 003FE238 FFFF2134 */  ori        $1, $1, (0x7FFFFFFF & 0xFFFF)
    /* 2FE23C 003FE23C 2A08A100 */  slt        $1, $5, $1
    /* 2FE240 003FE240 02002010 */  beqz       $1, .L003FE24C
    /* 2FE244 003FE244 00000000 */   nop
    /* 2FE248 003FE248 01000324 */  addiu      $3, $0, 0x1
  .L003FE24C:
    /* 2FE24C 003FE24C 10006010 */  beqz       $3, .L003FE290
    /* 2FE250 003FE250 00000000 */   nop
    /* 2FE254 003FE254 4000083C */  lui        $8, %hi(func_003fe200)
    /* 2FE258 003FE258 2D508000 */  daddu      $10, $4, $0
    /* 2FE25C 003FE25C 00E20825 */  addiu      $8, $8, %lo(func_003fe200)
  .L003FE260:
    /* 2FE260 003FE260 000048AD */  sw         $8, 0x0($10)
    /* 2FE264 003FE264 08006B25 */  addiu      $11, $11, 0x8
    /* 2FE268 003FE268 040048AD */  sw         $8, 0x4($10)
    /* 2FE26C 003FE26C 2A186901 */  slt        $3, $11, $9
    /* 2FE270 003FE270 080048AD */  sw         $8, 0x8($10)
    /* 2FE274 003FE274 0C0048AD */  sw         $8, 0xC($10)
    /* 2FE278 003FE278 100048AD */  sw         $8, 0x10($10)
    /* 2FE27C 003FE27C 140048AD */  sw         $8, 0x14($10)
    /* 2FE280 003FE280 180048AD */  sw         $8, 0x18($10)
    /* 2FE284 003FE284 1C0048AD */  sw         $8, 0x1C($10)
    /* 2FE288 003FE288 F5FF6014 */  bnez       $3, .L003FE260
    /* 2FE28C 003FE28C 20004A25 */   addiu     $10, $10, 0x20
  .L003FE290:
    /* 2FE290 003FE290 2A086501 */  slt        $1, $11, $5
    /* 2FE294 003FE294 0C002010 */  beqz       $1, .L003FE2C8
    /* 2FE298 003FE298 00000000 */   nop
    /* 2FE29C 003FE29C 80180B00 */  sll        $3, $11, 2
    /* 2FE2A0 003FE2A0 4000083C */  lui        $8, %hi(func_003fe200)
    /* 2FE2A4 003FE2A4 21488300 */  addu       $9, $4, $3
    /* 2FE2A8 003FE2A8 00E20825 */  addiu      $8, $8, %lo(func_003fe200)
  .L003FE2AC:
    /* 2FE2AC 003FE2AC 01006B25 */  addiu      $11, $11, 0x1
    /* 2FE2B0 003FE2B0 000028AD */  sw         $8, 0x0($9)
    /* 2FE2B4 003FE2B4 2A186501 */  slt        $3, $11, $5
    /* 2FE2B8 003FE2B8 04002925 */  addiu      $9, $9, 0x4
    /* 2FE2BC 003FE2BC 00000000 */  nop
    /* 2FE2C0 003FE2C0 FAFF6014 */  bnez       $3, .L003FE2AC
    /* 2FE2C4 003FE2C4 00000000 */   nop
  .L003FE2C8:
    /* 2FE2C8 003FE2C8 2D18E000 */  daddu      $3, $7, $0
    /* 2FE2CC 003FE2CC 10006010 */  beqz       $3, .L003FE310
    /* 2FE2D0 003FE2D0 FFFFE724 */   addiu     $7, $7, -0x1
  .L003FE2D4:
    /* 2FE2D4 003FE2D4 0000C38C */  lw         $3, 0x0($6)
    /* 2FE2D8 003FE2D8 2A086500 */  slt        $1, $3, $5
    /* 2FE2DC 003FE2DC 08002010 */  beqz       $1, .L003FE300
    /* 2FE2E0 003FE2E0 00000000 */   nop
    /* 2FE2E4 003FE2E4 06006004 */  bltz       $3, .L003FE300
    /* 2FE2E8 003FE2E8 00000000 */   nop
    /* 2FE2EC 003FE2EC 0400C88C */  lw         $8, 0x4($6)
    /* 2FE2F0 003FE2F0 80180300 */  sll        $3, $3, 2
    /* 2FE2F4 003FE2F4 21188300 */  addu       $3, $4, $3
    /* 2FE2F8 003FE2F8 000068AC */  sw         $8, 0x0($3)
    /* 2FE2FC 003FE2FC 00000000 */  nop
  .L003FE300:
    /* 2FE300 003FE300 2D18E000 */  daddu      $3, $7, $0
    /* 2FE304 003FE304 0800C624 */  addiu      $6, $6, 0x8
    /* 2FE308 003FE308 F2FF6014 */  bnez       $3, .L003FE2D4
    /* 2FE30C 003FE30C FFFFE724 */   addiu     $7, $7, -0x1
  .L003FE310:
    /* 2FE310 003FE310 0800E003 */  jr         $31
    /* 2FE314 003FE314 00000000 */   nop
    /* 2FE318 003FE318 00000000 */  nop
    /* 2FE31C 003FE31C 00000000 */  nop
.size func_003fe210, 0x110
