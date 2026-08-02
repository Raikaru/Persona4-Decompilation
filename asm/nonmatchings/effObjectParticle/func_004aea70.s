.section .text
.set noat
.set noreorder
glabel func_004aea70
    /* 3AEA70 004AEA70 70FFBD27 */  addiu      $29, $29, -0x90
    /* 3AEA74 004AEA74 5000BFFF */  sd         $31, 0x50($29)
    /* 3AEA78 004AEA78 4000B47F */  sq         $20, 0x40($29)
    /* 3AEA7C 004AEA7C 3000B37F */  sq         $19, 0x30($29)
    /* 3AEA80 004AEA80 2000B27F */  sq         $18, 0x20($29)
    /* 3AEA84 004AEA84 1000B17F */  sq         $17, 0x10($29)
    /* 3AEA88 004AEA88 0000B07F */  sq         $16, 0x0($29)
    /* 3AEA8C 004AEA8C 2DA08000 */  daddu      $20, $4, $0
    /* 3AEA90 004AEA90 2D98A000 */  daddu      $19, $5, $0
    /* 3AEA94 004AEA94 2D90C000 */  daddu      $18, $6, $0
    /* 3AEA98 004AEA98 2D880000 */  daddu      $17, $0, $0
    /* 3AEA9C 004AEA9C 2D800000 */  daddu      $16, $0, $0
    /* 3AEAA0 004AEAA0 8C00A0AF */  sw         $0, 0x8C($29)
    /* 3AEAA4 004AEAA4 5800828C */  lw         $2, 0x58($4)
    /* 3AEAA8 004AEAA8 06004014 */  bnez       $2, .L004AEAC4
    /* 3AEAAC 004AEAAC 00000000 */   nop
    /* 3AEAB0 004AEAB0 7100043C */  lui        $4, %hi(D_00714520)
    /* 3AEAB4 004AEAB4 20458424 */  addiu      $4, $4, %lo(D_00714520)
    /* 3AEAB8 004AEAB8 B3010524 */  addiu      $5, $0, 0x1B3
    /* 3AEABC 004AEABC CCB5110C */  jal        func_0046d730
    /* 3AEAC0 004AEAC0 00000000 */   nop
  .L004AEAC4:
    /* 3AEAC4 004AEAC4 5800828E */  lw         $2, 0x58($20)
    /* 3AEAC8 004AEAC8 0800428C */  lw         $2, 0x8($2)
    /* 3AEACC 004AEACC 06004014 */  bnez       $2, .L004AEAE8
    /* 3AEAD0 004AEAD0 00000000 */   nop
    /* 3AEAD4 004AEAD4 7100043C */  lui        $4, %hi(D_00714520)
    /* 3AEAD8 004AEAD8 20458424 */  addiu      $4, $4, %lo(D_00714520)
    /* 3AEADC 004AEADC B4010524 */  addiu      $5, $0, 0x1B4
    /* 3AEAE0 004AEAE0 CCB5110C */  jal        func_0046d730
    /* 3AEAE4 004AEAE4 00000000 */   nop
  .L004AEAE8:
    /* 3AEAE8 004AEAE8 8000B3AF */  sw         $19, 0x80($29)
    /* 3AEAEC 004AEAEC 8400B2AF */  sw         $18, 0x84($29)
    /* 3AEAF0 004AEAF0 03000424 */  addiu      $4, $0, 0x3
    /* 3AEAF4 004AEAF4 01000524 */  addiu      $5, $0, 0x1
    /* 3AEAF8 004AEAF8 8000A627 */  addiu      $6, $29, 0x80
    /* 3AEAFC 004AEAFC D88B0F0C */  jal        func_003e2f60
    /* 3AEB00 004AEB00 00000000 */   nop
    /* 3AEB04 004AEB04 2D904000 */  daddu      $18, $2, $0
    /* 3AEB08 004AEB08 29000010 */  b          .L004AEBB0
    /* 3AEB0C 004AEB0C 00000000 */   nop
  .L004AEB10:
    /* 3AEB10 004AEB10 6000A38F */  lw         $3, 0x60($29)
    /* 3AEB14 004AEB14 2C006010 */  beqz       $3, .L004AEBC8
    /* 3AEB18 004AEB18 00000000 */   nop
    /* 3AEB1C 004AEB1C 10000224 */  addiu      $2, $0, 0x10
    /* 3AEB20 004AEB20 17006210 */  beq        $3, $2, .L004AEB80
    /* 3AEB24 004AEB24 00000000 */   nop
    /* 3AEB28 004AEB28 16000224 */  addiu      $2, $0, 0x16
    /* 3AEB2C 004AEB2C 03006210 */  beq        $3, $2, .L004AEB3C
    /* 3AEB30 004AEB30 00000000 */   nop
    /* 3AEB34 004AEB34 1A000010 */  b          .L004AEBA0
    /* 3AEB38 004AEB38 00000000 */   nop
  .L004AEB3C:
    /* 3AEB3C 004AEB3C 1C000016 */  bnez       $16, .L004AEBB0
    /* 3AEB40 004AEB40 00000000 */   nop
    /* 3AEB44 004AEB44 2D204002 */  daddu      $4, $18, $0
    /* 3AEB48 004AEB48 A49A0F0C */  jal        func_003e6a90
    /* 3AEB4C 004AEB4C 00000000 */   nop
    /* 3AEB50 004AEB50 2D804000 */  daddu      $16, $2, $0
    /* 3AEB54 004AEB54 2D200002 */  daddu      $4, $16, $0
    /* 3AEB58 004AEB58 4600053C */  lui        $5, %hi(func_00463100)
    /* 3AEB5C 004AEB5C 0031A524 */  addiu      $5, $5, %lo(func_00463100)
    /* 3AEB60 004AEB60 8C00A627 */  addiu      $6, $29, 0x8C
    /* 3AEB64 004AEB64 98BC0F0C */  jal        func_003ef260
    /* 3AEB68 004AEB68 00000000 */   nop
    /* 3AEB6C 004AEB6C 2D200002 */  daddu      $4, $16, $0
    /* 3AEB70 004AEB70 6CBC0F0C */  jal        func_003ef1b0
    /* 3AEB74 004AEB74 00000000 */   nop
    /* 3AEB78 004AEB78 0D000010 */  b          .L004AEBB0
    /* 3AEB7C 004AEB7C 00000000 */   nop
  .L004AEB80:
    /* 3AEB80 004AEB80 0B002016 */  bnez       $17, .L004AEBB0
    /* 3AEB84 004AEB84 00000000 */   nop
    /* 3AEB88 004AEB88 2D204002 */  daddu      $4, $18, $0
    /* 3AEB8C 004AEB8C C8030F0C */  jal        func_003c0f20
    /* 3AEB90 004AEB90 00000000 */   nop
    /* 3AEB94 004AEB94 2D884000 */  daddu      $17, $2, $0
    /* 3AEB98 004AEB98 05000010 */  b          .L004AEBB0
    /* 3AEB9C 004AEB9C 00000000 */   nop
  .L004AEBA0:
    /* 3AEBA0 004AEBA0 2D204002 */  daddu      $4, $18, $0
    /* 3AEBA4 004AEBA4 6400A58F */  lw         $5, 0x64($29)
    /* 3AEBA8 004AEBA8 388B0F0C */  jal        func_003e2ce0
    /* 3AEBAC 004AEBAC 00000000 */   nop
  .L004AEBB0:
    /* 3AEBB0 004AEBB0 2D204002 */  daddu      $4, $18, $0
    /* 3AEBB4 004AEBB4 6000A527 */  addiu      $5, $29, 0x60
    /* 3AEBB8 004AEBB8 F07C0F0C */  jal        func_003df3c0
    /* 3AEBBC 004AEBBC 00000000 */   nop
    /* 3AEBC0 004AEBC0 D3FF4014 */  bnez       $2, .L004AEB10
    /* 3AEBC4 004AEBC4 00000000 */   nop
  .L004AEBC8:
    /* 3AEBC8 004AEBC8 2D204002 */  daddu      $4, $18, $0
    /* 3AEBCC 004AEBCC 8000A527 */  addiu      $5, $29, 0x80
    /* 3AEBD0 004AEBD0 908B0F0C */  jal        func_003e2e40
    /* 3AEBD4 004AEBD4 00000000 */   nop
    /* 3AEBD8 004AEBD8 8C00A48F */  lw         $4, 0x8C($29)
    /* 3AEBDC 004AEBDC 03008010 */  beqz       $4, .L004AEBEC
    /* 3AEBE0 004AEBE0 00000000 */   nop
    /* 3AEBE4 004AEBE4 948C110C */  jal        func_00463250
    /* 3AEBE8 004AEBE8 00000000 */   nop
  .L004AEBEC:
    /* 3AEBEC 004AEBEC 06002016 */  bnez       $17, .L004AEC08
    /* 3AEBF0 004AEBF0 00000000 */   nop
    /* 3AEBF4 004AEBF4 7100043C */  lui        $4, %hi(D_00714520)
    /* 3AEBF8 004AEBF8 20458424 */  addiu      $4, $4, %lo(D_00714520)
    /* 3AEBFC 004AEBFC DF010524 */  addiu      $5, $0, 0x1DF
    /* 3AEC00 004AEC00 CCB5110C */  jal        func_0046d730
    /* 3AEC04 004AEC04 00000000 */   nop
  .L004AEC08:
    /* 3AEC08 004AEC08 540091AE */  sw         $17, 0x54($20)
    /* 3AEC0C 004AEC0C 2D202002 */  daddu      $4, $17, $0
    /* 3AEC10 004AEC10 4B00053C */  lui        $5, %hi(func_004ae080)
    /* 3AEC14 004AEC14 80E0A524 */  addiu      $5, $5, %lo(func_004ae080)
    /* 3AEC18 004AEC18 2D300000 */  daddu      $6, $0, $0
    /* 3AEC1C 004AEC1C CCFF0E0C */  jal        func_003bff30
    /* 3AEC20 004AEC20 00000000 */   nop
    /* 3AEC24 004AEC24 5000BFDF */  ld         $31, 0x50($29)
    /* 3AEC28 004AEC28 4000B47B */  lq         $20, 0x40($29)
    /* 3AEC2C 004AEC2C 3000B37B */  lq         $19, 0x30($29)
    /* 3AEC30 004AEC30 2000B27B */  lq         $18, 0x20($29)
    /* 3AEC34 004AEC34 1000B17B */  lq         $17, 0x10($29)
    /* 3AEC38 004AEC38 0000B07B */  lq         $16, 0x0($29)
    /* 3AEC3C 004AEC3C 9000BD27 */  addiu      $29, $29, 0x90
    /* 3AEC40 004AEC40 0800E003 */  jr         $31
    /* 3AEC44 004AEC44 00000000 */   nop
    /* 3AEC48 004AEC48 00000000 */  nop
    /* 3AEC4C 004AEC4C 00000000 */  nop
.size func_004aea70, 0x1e0
