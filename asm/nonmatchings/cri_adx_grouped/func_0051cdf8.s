.section .text
.set noat
.set noreorder
glabel func_0051cdf8
    /* 41CDF8 0051CDF8 B0FFBD27 */  addiu      $29, $29, -0x50
    /* 41CDFC 0051CDFC 2D100000 */  daddu      $2, $0, $0
    /* 41CE00 0051CE00 1000B0FF */  sd         $16, 0x10($29)
    /* 41CE04 0051CE04 2D808000 */  daddu      $16, $4, $0
    /* 41CE08 0051CE08 1800B1FF */  sd         $17, 0x18($29)
    /* 41CE0C 0051CE0C 2D88A000 */  daddu      $17, $5, $0
    /* 41CE10 0051CE10 2000B2FF */  sd         $18, 0x20($29)
    /* 41CE14 0051CE14 0C091226 */  addiu      $18, $16, 0x90C
    /* 41CE18 0051CE18 3000B4FF */  sd         $20, 0x30($29)
    /* 41CE1C 0051CE1C 2DA0E000 */  daddu      $20, $7, $0
    /* 41CE20 0051CE20 3800B5FF */  sd         $21, 0x38($29)
    /* 41CE24 0051CE24 2DA8C000 */  daddu      $21, $6, $0
    /* 41CE28 0051CE28 2800B3FF */  sd         $19, 0x28($29)
    /* 41CE2C 0051CE2C 2D202002 */  daddu      $4, $17, $0
    /* 41CE30 0051CE30 4000BFFF */  sd         $31, 0x40($29)
    /* 41CE34 0051CE34 2D28A003 */  daddu      $5, $29, $0
    /* 41CE38 0051CE38 1000438E */  lw         $3, 0x10($18)
    /* 41CE3C 0051CE3C 30006014 */  bnez       $3, .L0051CF00
    /* 41CE40 0051CE40 C01F138E */   lw        $19, 0x1FC0($16)
    /* 41CE44 0051CE44 B413140C */  jal        func_00504ed0
    /* 41CE48 0051CE48 00000000 */   nop
    /* 41CE4C 0051CE4C 08004010 */  beqz       $2, .L0051CE70
    /* 41CE50 0051CE50 2D202002 */   daddu     $4, $17, $0
    /* 41CE54 0051CE54 00FF053C */  lui        $5, (0xFF000F16 >> 16)
    /* 41CE58 0051CE58 2D200002 */  daddu      $4, $16, $0
    /* 41CE5C 0051CE5C B45E140C */  jal        func_00517ad0
    /* 41CE60 0051CE60 160FA534 */   ori       $5, $5, (0xFF000F16 & 0xFFFF)
    /* 41CE64 0051CE64 27000010 */  b          .L0051CF04
    /* 41CE68 0051CE68 1000B0DF */   ld        $16, 0x10($29)
    /* 41CE6C 0051CE6C 00000000 */  nop
  .L0051CE70:
    /* 41CE70 0051CE70 0400A527 */  addiu      $5, $29, 0x4
    /* 41CE74 0051CE74 0800A627 */  addiu      $6, $29, 0x8
    /* 41CE78 0051CE78 CC13140C */  jal        func_00504f30
    /* 41CE7C 0051CE7C 0C00A727 */   addiu     $7, $29, 0xC
    /* 41CE80 0051CE80 2D200002 */  daddu      $4, $16, $0
    /* 41CE84 0051CE84 2694140C */  jal        func_00525098
    /* 41CE88 0051CE88 3C000524 */   addiu     $5, $0, 0x3C
    /* 41CE8C 0051CE8C 2D200002 */  daddu      $4, $16, $0
    /* 41CE90 0051CE90 03004014 */  bnez       $2, .L0051CEA0
    /* 41CE94 0051CE94 01000524 */   addiu     $5, $0, 0x1
    /* 41CE98 0051CE98 0D000010 */  b          .L0051CED0
    /* 41CE9C 0051CE9C 140160AE */   sw        $0, 0x114($19)
  .L0051CEA0:
    /* 41CEA0 0051CEA0 6854140C */  jal        func_005151a0
    /* 41CEA4 0051CEA4 00000000 */   nop
    /* 41CEA8 0051CEA8 0C00A38F */  lw         $3, 0xC($29)
    /* 41CEAC 0051CEAC 2D204000 */  daddu      $4, $2, $0
    /* 41CEB0 0051CEB0 FFFF0224 */  addiu      $2, $0, -0x1
    /* 41CEB4 0051CEB4 04006214 */  bne        $3, $2, .L0051CEC8
    /* 41CEB8 0051CEB8 2A106400 */   slt       $2, $3, $4
    /* 41CEBC 0051CEBC 0400A38F */  lw         $3, 0x4($29)
    /* 41CEC0 0051CEC0 0C00A3AF */  sw         $3, 0xC($29)
    /* 41CEC4 0051CEC4 2A106400 */  slt        $2, $3, $4
  .L0051CEC8:
    /* 41CEC8 0051CEC8 0A188200 */  movz       $3, $4, $2
    /* 41CECC 0051CECC 140163AE */  sw         $3, 0x114($19)
  .L0051CED0:
    /* 41CED0 0051CED0 0000A58F */  lw         $5, 0x0($29)
    /* 41CED4 0051CED4 2D308002 */  daddu      $6, $20, $0
    /* 41CED8 0051CED8 CA73140C */  jal        func_0051cf28
    /* 41CEDC 0051CEDC 2D200002 */   daddu     $4, $16, $0
    /* 41CEE0 0051CEE0 2D204002 */  daddu      $4, $18, $0
    /* 41CEE4 0051CEE4 0000A58F */  lw         $5, 0x0($29)
    /* 41CEE8 0051CEE8 2D30A002 */  daddu      $6, $21, $0
    /* 41CEEC 0051CEEC 1274140C */  jal        func_0051d048
    /* 41CEF0 0051CEF0 0400A78F */   lw        $7, 0x4($29)
    /* 41CEF4 0051CEF4 2D200002 */  daddu      $4, $16, $0
    /* 41CEF8 0051CEF8 2074140C */  jal        func_0051d080
    /* 41CEFC 0051CEFC 2D284002 */   daddu     $5, $18, $0
  .L0051CF00:
    /* 41CF00 0051CF00 1000B0DF */  ld         $16, 0x10($29)
  .L0051CF04:
    /* 41CF04 0051CF04 1800B1DF */  ld         $17, 0x18($29)
    /* 41CF08 0051CF08 2000B2DF */  ld         $18, 0x20($29)
    /* 41CF0C 0051CF0C 2800B3DF */  ld         $19, 0x28($29)
    /* 41CF10 0051CF10 3000B4DF */  ld         $20, 0x30($29)
    /* 41CF14 0051CF14 3800B5DF */  ld         $21, 0x38($29)
    /* 41CF18 0051CF18 4000BFDF */  ld         $31, 0x40($29)
    /* 41CF1C 0051CF1C 0800E003 */  jr         $31
    /* 41CF20 0051CF20 5000BD27 */   addiu     $29, $29, 0x50
    /* 41CF24 0051CF24 00000000 */  nop
.size func_0051cdf8, 0x130
