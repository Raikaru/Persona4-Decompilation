.section .text
.set noat
.set noreorder
glabel func_004ee240
    /* 3EE240 004EE240 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3EE244 004EE244 08008014 */  bnez       $4, .L004EE268
    /* 3EE248 004EE248 0000BFFF */   sd        $31, 0x0($29)
    /* 3EE24C 004EE24C 7600043C */  lui        $4, %hi(D_0075CDF0)
    /* 3EE250 004EE250 7600053C */  lui        $5, %hi(D_0075CDA0)
    /* 3EE254 004EE254 0000BFDF */  ld         $31, 0x0($29)
    /* 3EE258 004EE258 F0CD8424 */  addiu      $4, $4, %lo(D_0075CDF0)
    /* 3EE25C 004EE25C A0CDA524 */  addiu      $5, $5, %lo(D_0075CDA0)
    /* 3EE260 004EE260 B4B71308 */  j          func_004eded0
    /* 3EE264 004EE264 1000BD27 */   addiu     $29, $29, 0x10
  .L004EE268:
    /* 3EE268 004EE268 0400828C */  lw         $2, 0x4($4)
    /* 3EE26C 004EE26C 08004054 */  bnel       $2, $0, .L004EE290
    /* 3EE270 004EE270 2000828C */   lw        $2, 0x20($4)
    /* 3EE274 004EE274 7600043C */  lui        $4, %hi(D_0075CE00)
    /* 3EE278 004EE278 7600053C */  lui        $5, %hi(D_0075CDD0)
    /* 3EE27C 004EE27C 0000BFDF */  ld         $31, 0x0($29)
    /* 3EE280 004EE280 00CE8424 */  addiu      $4, $4, %lo(D_0075CE00)
    /* 3EE284 004EE284 D0CDA524 */  addiu      $5, $5, %lo(D_0075CDD0)
    /* 3EE288 004EE288 B4B71308 */  j          func_004eded0
    /* 3EE28C 004EE28C 1000BD27 */   addiu     $29, $29, 0x10
  .L004EE290:
    /* 3EE290 004EE290 0000BFDF */  ld         $31, 0x0($29)
    /* 3EE294 004EE294 340080AC */  sw         $0, 0x34($4)
    /* 3EE298 004EE298 100082AC */  sw         $2, 0x10($4)
    /* 3EE29C 004EE29C 0C0080AC */  sw         $0, 0xC($4)
    /* 3EE2A0 004EE2A0 140080AC */  sw         $0, 0x14($4)
    /* 3EE2A4 004EE2A4 180080AC */  sw         $0, 0x18($4)
    /* 3EE2A8 004EE2A8 280080AC */  sw         $0, 0x28($4)
    /* 3EE2AC 004EE2AC 2C0080AC */  sw         $0, 0x2C($4)
    /* 3EE2B0 004EE2B0 300080AC */  sw         $0, 0x30($4)
    /* 3EE2B4 004EE2B4 0800E003 */  jr         $31
    /* 3EE2B8 004EE2B8 1000BD27 */   addiu     $29, $29, 0x10
    /* 3EE2BC 004EE2BC 00000000 */  nop
.size func_004ee240, 0x80
