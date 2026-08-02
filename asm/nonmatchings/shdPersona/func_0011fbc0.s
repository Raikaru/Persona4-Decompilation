.section .text
.set noat
.set noreorder
glabel func_0011fbc0
    /* 1FBC0 0011FBC0 A0FFBD27 */  addiu      $29, $29, -0x60
    /* 1FBC4 0011FBC4 5000BFFF */  sd         $31, 0x50($29)
    /* 1FBC8 0011FBC8 4000B47F */  sq         $20, 0x40($29)
    /* 1FBCC 0011FBCC 3000B37F */  sq         $19, 0x30($29)
    /* 1FBD0 0011FBD0 2000B27F */  sq         $18, 0x20($29)
    /* 1FBD4 0011FBD4 1000B17F */  sq         $17, 0x10($29)
    /* 1FBD8 0011FBD8 0000B07F */  sq         $16, 0x0($29)
    /* 1FBDC 0011FBDC 2D808000 */  daddu      $16, $4, $0
    /* 1FBE0 0011FBE0 2DA0A000 */  daddu      $20, $5, $0
    /* 1FBE4 0011FBE4 2D98C000 */  daddu      $19, $6, $0
    /* 1FBE8 0011FBE8 2D90E000 */  daddu      $18, $7, $0
    /* 1FBEC 0011FBEC 5E00043C */  lui        $4, %hi(D_005E4868)
    /* 1FBF0 0011FBF0 68488424 */  addiu      $4, $4, %lo(D_005E4868)
    /* 1FBF4 0011FBF4 51150524 */  addiu      $5, $0, 0x1551
    /* 1FBF8 0011FBF8 A43A110C */  jal        func_0044ea90
    /* 1FBFC 0011FBFC 00000000 */   nop
    /* 1FC00 0011FC00 01000424 */  addiu      $4, $0, 0x1
    /* 1FC04 0011FC04 44000524 */  addiu      $5, $0, 0x44
    /* 1FC08 0011FC08 0400063C */  lui        $6, (0x40000 >> 16)
    /* 1FC0C 0011FC0C 8800023C */  lui        $2, %hi(D_008873F4)
    /* 1FC10 0011FC10 F473428C */  lw         $2, %lo(D_008873F4)($2)
    /* 1FC14 0011FC14 09F84000 */  jalr       $2
    /* 1FC18 0011FC18 00000000 */   nop
    /* 1FC1C 0011FC1C 2D884000 */  daddu      $17, $2, $0
    /* 1FC20 0011FC20 06002016 */  bnez       $17, .L0011FC3C
    /* 1FC24 0011FC24 00000000 */   nop
    /* 1FC28 0011FC28 5E00043C */  lui        $4, %hi(D_005E4868)
    /* 1FC2C 0011FC2C 68488424 */  addiu      $4, $4, %lo(D_005E4868)
    /* 1FC30 0011FC30 52150524 */  addiu      $5, $0, 0x1552
    /* 1FC34 0011FC34 CCB5110C */  jal        func_0046d730
    /* 1FC38 0011FC38 00000000 */   nop
  .L0011FC3C:
    /* 1FC3C 0011FC3C 2D200002 */  daddu      $4, $16, $0
    /* 1FC40 0011FC40 5E00053C */  lui        $5, %hi(D_005E4F50)
    /* 1FC44 0011FC44 504FA524 */  addiu      $5, $5, %lo(D_005E4F50)
    /* 1FC48 0011FC48 0F000624 */  addiu      $6, $0, 0xF
    /* 1FC4C 0011FC4C 2D380000 */  daddu      $7, $0, $0
    /* 1FC50 0011FC50 2D400000 */  daddu      $8, $0, $0
    /* 1FC54 0011FC54 1200093C */  lui        $9, %hi(func_0011f5a0)
    /* 1FC58 0011FC58 A0F52925 */  addiu      $9, $9, %lo(func_0011f5a0)
    /* 1FC5C 0011FC5C 12000A3C */  lui        $10, %hi(func_0011fb90)
    /* 1FC60 0011FC60 90FB4A25 */  addiu      $10, $10, %lo(func_0011fb90)
    /* 1FC64 0011FC64 2D582002 */  daddu      $11, $17, $0
    /* 1FC68 0011FC68 F047110C */  jal        func_00451fc0
    /* 1FC6C 0011FC6C 00000000 */   nop
    /* 1FC70 0011FC70 2D804000 */  daddu      $16, $2, $0
    /* 1FC74 0011FC74 06000016 */  bnez       $16, .L0011FC90
    /* 1FC78 0011FC78 00000000 */   nop
    /* 1FC7C 0011FC7C 5E00043C */  lui        $4, %hi(D_005E4868)
    /* 1FC80 0011FC80 68488424 */  addiu      $4, $4, %lo(D_005E4868)
    /* 1FC84 0011FC84 5C150524 */  addiu      $5, $0, 0x155C
    /* 1FC88 0011FC88 CCB5110C */  jal        func_0046d730
    /* 1FC8C 0011FC8C 00000000 */   nop
  .L0011FC90:
    /* 1FC90 0011FC90 0C0034AE */  sw         $20, 0xC($17)
    /* 1FC94 0011FC94 140033AE */  sw         $19, 0x14($17)
    /* 1FC98 0011FC98 2D280000 */  daddu      $5, $0, $0
    /* 1FC9C 0011FC9C 07000010 */  b          .L0011FCBC
    /* 1FCA0 0011FCA0 00000000 */   nop
  .L0011FCA4:
    /* 1FCA4 0011FCA4 80200500 */  sll        $4, $5, 2
    /* 1FCA8 0011FCA8 21104402 */  addu       $2, $18, $4
    /* 1FCAC 0011FCAC 0000438C */  lw         $3, 0x0($2)
    /* 1FCB0 0011FCB0 21102402 */  addu       $2, $17, $4
    /* 1FCB4 0011FCB4 180043AC */  sw         $3, 0x18($2)
    /* 1FCB8 0011FCB8 0100A524 */  addiu      $5, $5, 0x1
  .L0011FCBC:
    /* 1FCBC 0011FCBC 0B00A228 */  slti       $2, $5, 0xB
    /* 1FCC0 0011FCC0 F8FF4014 */  bnez       $2, .L0011FCA4
    /* 1FCC4 0011FCC4 00000000 */   nop
    /* 1FCC8 0011FCC8 2D100002 */  daddu      $2, $16, $0
    /* 1FCCC 0011FCCC 5000BFDF */  ld         $31, 0x50($29)
    /* 1FCD0 0011FCD0 4000B47B */  lq         $20, 0x40($29)
    /* 1FCD4 0011FCD4 3000B37B */  lq         $19, 0x30($29)
    /* 1FCD8 0011FCD8 2000B27B */  lq         $18, 0x20($29)
    /* 1FCDC 0011FCDC 1000B17B */  lq         $17, 0x10($29)
    /* 1FCE0 0011FCE0 0000B07B */  lq         $16, 0x0($29)
    /* 1FCE4 0011FCE4 6000BD27 */  addiu      $29, $29, 0x60
    /* 1FCE8 0011FCE8 0800E003 */  jr         $31
    /* 1FCEC 0011FCEC 00000000 */   nop
.size func_0011fbc0, 0x130
