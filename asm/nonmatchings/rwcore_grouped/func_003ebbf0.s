.section .text
.set noat
.set noreorder
glabel func_003ebbf0
    /* 2EBBF0 003EBBF0 60FFBD27 */  addiu      $29, $29, -0xA0
    /* 2EBBF4 003EBBF4 01000524 */  addiu      $5, $0, 0x1
    /* 2EBBF8 003EBBF8 7000BFFF */  sd         $31, 0x70($29)
    /* 2EBBFC 003EBBFC 9C00A627 */  addiu      $6, $29, 0x9C
    /* 2EBC00 003EBC00 6000B67F */  sq         $22, 0x60($29)
    /* 2EBC04 003EBC04 9800A727 */  addiu      $7, $29, 0x98
    /* 2EBC08 003EBC08 5000B57F */  sq         $21, 0x50($29)
    /* 2EBC0C 003EBC0C 4000B47F */  sq         $20, 0x40($29)
    /* 2EBC10 003EBC10 3000B37F */  sq         $19, 0x30($29)
    /* 2EBC14 003EBC14 2000B27F */  sq         $18, 0x20($29)
    /* 2EBC18 003EBC18 1000B17F */  sq         $17, 0x10($29)
    /* 2EBC1C 003EBC1C 0000B07F */  sq         $16, 0x0($29)
    /* 2EBC20 003EBC20 147C0F0C */  jal        func_003df050
    /* 2EBC24 003EBC24 2D808000 */   daddu     $16, $4, $0
    /* 2EBC28 003EBC28 03004014 */  bnez       $2, .L003EBC38
    /* 2EBC2C 003EBC2C 00000000 */   nop
    /* 2EBC30 003EBC30 5E000010 */  b          .L003EBDAC
    /* 2EBC34 003EBC34 2D100000 */   daddu     $2, $0, $0
  .L003EBC38:
    /* 2EBC38 003EBC38 2D200002 */  daddu      $4, $16, $0
    /* 2EBC3C 003EBC3C 8000A527 */  addiu      $5, $29, 0x80
    /* 2EBC40 003EBC40 448A0F0C */  jal        func_003e2910
    /* 2EBC44 003EBC44 10000624 */   addiu     $6, $0, 0x10
    /* 2EBC48 003EBC48 C8B7848F */  lw         $4, -0x4838($28)
    /* 2EBC4C 003EBC4C 8800033C */  lui        $3, %hi(D_008872E0)
    /* 2EBC50 003EBC50 0300023C */  lui        $2, (0x30018 >> 16)
    /* 2EBC54 003EBC54 E0726324 */  addiu      $3, $3, %lo(D_008872E0)
    /* 2EBC58 003EBC58 18004534 */  ori        $5, $2, (0x30018 & 0xFFFF)
    /* 2EBC5C 003EBC5C 8400B627 */  addiu      $22, $29, 0x84
    /* 2EBC60 003EBC60 8800023C */  lui        $2, %hi(D_008873F8)
    /* 2EBC64 003EBC64 F873428C */  lw         $2, %lo(D_008873F8)($2)
    /* 2EBC68 003EBC68 0000D18E */  lw         $17, 0x0($22)
    /* 2EBC6C 003EBC6C 21186400 */  addu       $3, $3, $4
    /* 2EBC70 003EBC70 8000B38F */  lw         $19, 0x80($29)
    /* 2EBC74 003EBC74 0000648C */  lw         $4, 0x0($3)
    /* 2EBC78 003EBC78 09F84000 */  jalr       $2
    /* 2EBC7C 003EBC7C 8800B28F */   lw        $18, 0x88($29)
    /* 2EBC80 003EBC80 2DA04000 */  daddu      $20, $2, $0
    /* 2EBC84 003EBC84 38008012 */  beqz       $20, .L003EBD68
    /* 2EBC88 003EBC88 00000000 */   nop
    /* 2EBC8C 003EBC8C 040093AE */  sw         $19, 0x4($20)
    /* 2EBC90 003EBC90 7100043C */  lui        $4, %hi(D_0070B7C0)
    /* 2EBC94 003EBC94 080091AE */  sw         $17, 0x8($20)
    /* 2EBC98 003EBC98 C0B78424 */  addiu      $4, $4, %lo(D_0070B7C0)
    /* 2EBC9C 003EBC9C 0C0092AE */  sw         $18, 0xC($20)
    /* 2EBCA0 003EBCA0 2D288002 */  daddu      $5, $20, $0
    /* 2EBCA4 003EBCA4 140080AE */  sw         $0, 0x14($20)
    /* 2EBCA8 003EBCA8 180080AE */  sw         $0, 0x18($20)
    /* 2EBCAC 003EBCAC DC8E0F0C */  jal        func_003e3b70
    /* 2EBCB0 003EBCB0 000080AE */   sw        $0, 0x0($20)
  .L003EBCB4:
    /* 2EBCB4 003EBCB4 F8A80F0C */  jal        func_003ea3e0
    /* 2EBCB8 003EBCB8 2D208002 */   daddu     $4, $20, $0
    /* 2EBCBC 003EBCBC 8C00B127 */  addiu      $17, $29, 0x8C
    /* 2EBCC0 003EBCC0 1000928E */  lw         $18, 0x10($20)
    /* 2EBCC4 003EBCC4 0000228E */  lw         $2, 0x0($17)
    /* 2EBCC8 003EBCC8 29004212 */  beq        $18, $2, .L003EBD70
    /* 2EBCCC 003EBCCC 00000000 */   nop
    /* 2EBCD0 003EBCD0 0000C28E */  lw         $2, 0x0($22)
    /* 2EBCD4 003EBCD4 2A080200 */  slt        $1, $0, $2
    /* 2EBCD8 003EBCD8 1D002010 */  beqz       $1, .L003EBD50
    /* 2EBCDC 003EBCDC 2DA80000 */   daddu     $21, $0, $0
    /* 2EBCE0 003EBCE0 2D980000 */  daddu      $19, $0, $0
  .L003EBCE4:
    /* 2EBCE4 003EBCE4 0000268E */  lw         $6, 0x0($17)
    /* 2EBCE8 003EBCE8 2A08D200 */  slt        $1, $6, $18
    /* 2EBCEC 003EBCEC 08002010 */  beqz       $1, .L003EBD10
    /* 2EBCF0 003EBCF0 00000000 */   nop
    /* 2EBCF4 003EBCF4 1400828E */  lw         $2, 0x14($20)
    /* 2EBCF8 003EBCF8 2D200002 */  daddu      $4, $16, $0
    /* 2EBCFC 003EBCFC 448A0F0C */  jal        func_003e2910
    /* 2EBD00 003EBD00 21285300 */   addu      $5, $2, $19
    /* 2EBD04 003EBD04 0C000010 */  b          .L003EBD38
    /* 2EBD08 003EBD08 00000000 */   nop
    /* 2EBD0C 003EBD0C 00000000 */  nop
  .L003EBD10:
    /* 2EBD10 003EBD10 1400828E */  lw         $2, 0x14($20)
    /* 2EBD14 003EBD14 2D200002 */  daddu      $4, $16, $0
    /* 2EBD18 003EBD18 2D304002 */  daddu      $6, $18, $0
    /* 2EBD1C 003EBD1C 448A0F0C */  jal        func_003e2910
    /* 2EBD20 003EBD20 21285300 */   addu      $5, $2, $19
    /* 2EBD24 003EBD24 0000228E */  lw         $2, 0x0($17)
    /* 2EBD28 003EBD28 2D200002 */  daddu      $4, $16, $0
    /* 2EBD2C 003EBD2C 388B0F0C */  jal        func_003e2ce0
    /* 2EBD30 003EBD30 23285200 */   subu      $5, $2, $18
    /* 2EBD34 003EBD34 00000000 */  nop
  .L003EBD38:
    /* 2EBD38 003EBD38 0000C28E */  lw         $2, 0x0($22)
    /* 2EBD3C 003EBD3C 0100B526 */  addiu      $21, $21, 0x1
    /* 2EBD40 003EBD40 2A10A202 */  slt        $2, $21, $2
    /* 2EBD44 003EBD44 E7FF4014 */  bnez       $2, .L003EBCE4
    /* 2EBD48 003EBD48 21987202 */   addu      $19, $19, $18
    /* 2EBD4C 003EBD4C 00000000 */  nop
  .L003EBD50:
    /* 2EBD50 003EBD50 0C00838E */  lw         $3, 0xC($20)
    /* 2EBD54 003EBD54 09006128 */  slti       $1, $3, 0x9
    /* 2EBD58 003EBD58 0C002014 */  bnez       $1, .L003EBD8C
    /* 2EBD5C 003EBD5C 00000000 */   nop
  .L003EBD60:
    /* 2EBD60 003EBD60 12000010 */  b          .L003EBDAC
    /* 2EBD64 003EBD64 2D108002 */   daddu     $2, $20, $0
  .L003EBD68:
    /* 2EBD68 003EBD68 D2FF0010 */  b          .L003EBCB4
    /* 2EBD6C 003EBD6C 2DA00000 */   daddu     $20, $0, $0
  .L003EBD70:
    /* 2EBD70 003EBD70 0800828E */  lw         $2, 0x8($20)
    /* 2EBD74 003EBD74 18305200 */  mult       $6, $2, $18
    /* 2EBD78 003EBD78 1400858E */  lw         $5, 0x14($20)
    /* 2EBD7C 003EBD7C 448A0F0C */  jal        func_003e2910
    /* 2EBD80 003EBD80 2D200002 */   daddu     $4, $16, $0
    /* 2EBD84 003EBD84 F2FF0010 */  b          .L003EBD50
    /* 2EBD88 003EBD88 00000000 */   nop
  .L003EBD8C:
    /* 2EBD8C 003EBD8C 1800858E */  lw         $5, 0x18($20)
    /* 2EBD90 003EBD90 01000224 */  addiu      $2, $0, 0x1
    /* 2EBD94 003EBD94 04106200 */  sllv       $2, $2, $3
    /* 2EBD98 003EBD98 2D200002 */  daddu      $4, $16, $0
    /* 2EBD9C 003EBD9C 448A0F0C */  jal        func_003e2910
    /* 2EBDA0 003EBDA0 80300200 */   sll       $6, $2, 2
    /* 2EBDA4 003EBDA4 EEFF0010 */  b          .L003EBD60
    /* 2EBDA8 003EBDA8 00000000 */   nop
  .L003EBDAC:
    /* 2EBDAC 003EBDAC 7000BFDF */  ld         $31, 0x70($29)
    /* 2EBDB0 003EBDB0 6000B67B */  lq         $22, 0x60($29)
    /* 2EBDB4 003EBDB4 5000B57B */  lq         $21, 0x50($29)
    /* 2EBDB8 003EBDB8 4000B47B */  lq         $20, 0x40($29)
    /* 2EBDBC 003EBDBC 3000B37B */  lq         $19, 0x30($29)
    /* 2EBDC0 003EBDC0 2000B27B */  lq         $18, 0x20($29)
    /* 2EBDC4 003EBDC4 1000B17B */  lq         $17, 0x10($29)
    /* 2EBDC8 003EBDC8 0000B07B */  lq         $16, 0x0($29)
    /* 2EBDCC 003EBDCC 0800E003 */  jr         $31
    /* 2EBDD0 003EBDD0 A000BD27 */   addiu     $29, $29, 0xA0
    /* 2EBDD4 003EBDD4 00000000 */  nop
    /* 2EBDD8 003EBDD8 00000000 */  nop
    /* 2EBDDC 003EBDDC 00000000 */  nop
.size func_003ebbf0, 0x1f0
