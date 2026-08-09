.section .text
.set noat
.set noreorder
glabel func_003ddca0
    /* 2DDCA0 003DDCA0 20FFBD27 */  addiu      $29, $29, -0xE0
    /* 2DDCA4 003DDCA4 8800023C */  lui        $2, %hi(D_00887188)
    /* 2DDCA8 003DDCA8 6000BFFF */  sd         $31, 0x60($29)
    /* 2DDCAC 003DDCAC 5000B57F */  sq         $21, 0x50($29)
    /* 2DDCB0 003DDCB0 4000B47F */  sq         $20, 0x40($29)
    /* 2DDCB4 003DDCB4 3000B37F */  sq         $19, 0x30($29)
    /* 2DDCB8 003DDCB8 2000B27F */  sq         $18, 0x20($29)
    /* 2DDCBC 003DDCBC 1000B17F */  sq         $17, 0x10($29)
    /* 2DDCC0 003DDCC0 0000B07F */  sq         $16, 0x0($29)
    /* 2DDCC4 003DDCC4 8871428C */  lw         $2, %lo(D_00887188)($2)
    /* 2DDCC8 003DDCC8 09004014 */  bnez       $2, .L003DDCF0
    /* 2DDCCC 003DDCCC 2DA08000 */   daddu     $20, $4, $0
  .L003DDCD0:
    /* 2DDCD0 003DDCD0 8800023C */  lui        $2, %hi(D_00887194)
    /* 2DDCD4 003DDCD4 9471428C */  lw         $2, %lo(D_00887194)($2)
    /* 2DDCD8 003DDCD8 03004010 */  beqz       $2, .L003DDCE8
    /* 2DDCDC 003DDCDC 00000000 */   nop
    /* 2DDCE0 003DDCE0 09F84000 */  jalr       $2
    /* 2DDCE4 003DDCE4 06000424 */   addiu     $4, $0, 0x6
  .L003DDCE8:
    /* 2DDCE8 003DDCE8 34000010 */  b          .L003DDDBC
    /* 2DDCEC 003DDCEC 2D100000 */   daddu     $2, $0, $0
  .L003DDCF0:
    /* 2DDCF0 003DDCF0 8800023C */  lui        $2, %hi(D_008873D4)
    /* 2DDCF4 003DDCF4 D473428C */  lw         $2, %lo(D_008873D4)($2)
    /* 2DDCF8 003DDCF8 09F84000 */  jalr       $2
    /* 2DDCFC 003DDCFC 00000000 */   nop
    /* 2DDD00 003DDD00 2D804000 */  daddu      $16, $2, $0
    /* 2DDD04 003DDD04 2B081000 */  sltu       $1, $0, $16
    /* 2DDD08 003DDD08 0D002010 */  beqz       $1, .L003DDD40
    /* 2DDD0C 003DDD0C 2D980000 */   daddu     $19, $0, $0
    /* 2DDD10 003DDD10 8800153C */  lui        $21, %hi(D_008873D0)
    /* 2DDD14 003DDD14 7000B127 */  addiu      $17, $29, 0x70
    /* 2DDD18 003DDD18 D073B526 */  addiu      $21, $21, %lo(D_008873D0)
  .L003DDD1C:
    /* 2DDD1C 003DDD1C 21189302 */  addu       $3, $20, $19
    /* 2DDD20 003DDD20 3A000224 */  addiu      $2, $0, 0x3A
    /* 2DDD24 003DDD24 00006380 */  lb         $3, 0x0($3)
    /* 2DDD28 003DDD28 0A006210 */  beq        $3, $2, .L003DDD54
    /* 2DDD2C 003DDD2C 00000000 */   nop
  .L003DDD30:
    /* 2DDD30 003DDD30 01007326 */  addiu      $19, $19, 0x1
    /* 2DDD34 003DDD34 2B107002 */  sltu       $2, $19, $16
    /* 2DDD38 003DDD38 F8FF4014 */  bnez       $2, .L003DDD1C
    /* 2DDD3C 003DDD3C 01003126 */   addiu     $17, $17, 0x1
  .L003DDD40:
    /* 2DDD40 003DDD40 50B7828F */  lw         $2, -0x48B0($28)
    /* 2DDD44 003DDD44 E2FF4010 */  beqz       $2, .L003DDCD0
    /* 2DDD48 003DDD48 00000000 */   nop
    /* 2DDD4C 003DDD4C 1C000010 */  b          .L003DDDC0
    /* 2DDD50 003DDD50 6000BFDF */   ld        $31, 0x60($29)
  .L003DDD54:
    /* 2DDD54 003DDD54 01006626 */  addiu      $6, $19, 0x1
    /* 2DDD58 003DDD58 7000A427 */  addiu      $4, $29, 0x70
    /* 2DDD5C 003DDD5C 7A0B110C */  jal        func_00442de8
    /* 2DDD60 003DDD60 2D288002 */   daddu     $5, $20, $0
    /* 2DDD64 003DDD64 8800023C */  lui        $2, %hi(D_00887180)
    /* 2DDD68 003DDD68 8071528C */  lw         $18, %lo(D_00887180)($2)
    /* 2DDD6C 003DDD6C 0E004012 */  beqz       $18, .L003DDDA8
    /* 2DDD70 003DDD70 010020A2 */   sb        $0, 0x1($17)
    /* 2DDD74 003DDD74 00000000 */  nop
  .L003DDD78:
    /* 2DDD78 003DDD78 0C00458E */  lw         $5, 0xC($18)
    /* 2DDD7C 003DDD7C 0000A28E */  lw         $2, 0x0($21)
    /* 2DDD80 003DDD80 09F84000 */  jalr       $2
    /* 2DDD84 003DDD84 7000A427 */   addiu     $4, $29, 0x70
    /* 2DDD88 003DDD88 03004014 */  bnez       $2, .L003DDD98
    /* 2DDD8C 003DDD8C 00000000 */   nop
    /* 2DDD90 003DDD90 07000010 */  b          .L003DDDB0
    /* 2DDD94 003DDD94 00000000 */   nop
  .L003DDD98:
    /* 2DDD98 003DDD98 0000528E */  lw         $18, 0x0($18)
    /* 2DDD9C 003DDD9C F6FF4016 */  bnez       $18, .L003DDD78
    /* 2DDDA0 003DDDA0 00000000 */   nop
    /* 2DDDA4 003DDDA4 00000000 */  nop
  .L003DDDA8:
    /* 2DDDA8 003DDDA8 2D900000 */  daddu      $18, $0, $0
    /* 2DDDAC 003DDDAC 00000000 */  nop
  .L003DDDB0:
    /* 2DDDB0 003DDDB0 DFFF4012 */  beqz       $18, .L003DDD30
    /* 2DDDB4 003DDDB4 00000000 */   nop
    /* 2DDDB8 003DDDB8 2D104002 */  daddu      $2, $18, $0
  .L003DDDBC:
    /* 2DDDBC 003DDDBC 6000BFDF */  ld         $31, 0x60($29)
  .L003DDDC0:
    /* 2DDDC0 003DDDC0 5000B57B */  lq         $21, 0x50($29)
    /* 2DDDC4 003DDDC4 4000B47B */  lq         $20, 0x40($29)
    /* 2DDDC8 003DDDC8 3000B37B */  lq         $19, 0x30($29)
    /* 2DDDCC 003DDDCC 2000B27B */  lq         $18, 0x20($29)
    /* 2DDDD0 003DDDD0 1000B17B */  lq         $17, 0x10($29)
    /* 2DDDD4 003DDDD4 0000B07B */  lq         $16, 0x0($29)
    /* 2DDDD8 003DDDD8 0800E003 */  jr         $31
    /* 2DDDDC 003DDDDC E000BD27 */   addiu     $29, $29, 0xE0
.size func_003ddca0, 0x140
