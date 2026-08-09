.section .text
.set noat
.set noreorder
glabel func_004cfb98
    /* 3CFB98 004CFB98 90FFBD27 */  addiu      $29, $29, -0x70
    /* 3CFB9C 004CFB9C 2800B1FF */  sd         $17, 0x28($29)
    /* 3CFBA0 004CFBA0 2D880000 */  daddu      $17, $0, $0
    /* 3CFBA4 004CFBA4 3000B2FF */  sd         $18, 0x30($29)
    /* 3CFBA8 004CFBA8 2D90C000 */  daddu      $18, $6, $0
    /* 3CFBAC 004CFBAC 4000B4FF */  sd         $20, 0x40($29)
    /* 3CFBB0 004CFBB0 2DA00000 */  daddu      $20, $0, $0
    /* 3CFBB4 004CFBB4 5800B7FF */  sd         $23, 0x58($29)
    /* 3CFBB8 004CFBB8 2DB88000 */  daddu      $23, $4, $0
    /* 3CFBBC 004CFBBC 6000BEFF */  sd         $30, 0x60($29)
    /* 3CFBC0 004CFBC0 0400FE26 */  addiu      $30, $23, 0x4
    /* 3CFBC4 004CFBC4 2000B0FF */  sd         $16, 0x20($29)
    /* 3CFBC8 004CFBC8 3800B3FF */  sd         $19, 0x38($29)
    /* 3CFBCC 004CFBCC 4800B5FF */  sd         $21, 0x48($29)
    /* 3CFBD0 004CFBD0 5000B6FF */  sd         $22, 0x50($29)
    /* 3CFBD4 004CFBD4 6800BFFF */  sd         $31, 0x68($29)
    /* 3CFBD8 004CFBD8 5800E38E */  lw         $3, 0x58($23)
    /* 3CFBDC 004CFBDC 12006018 */  blez       $3, .L004CFC28
    /* 3CFBE0 004CFBE0 1000A7AF */   sw        $7, 0x10($29)
    /* 3CFBE4 004CFBE4 2D80C003 */  daddu      $16, $30, $0
    /* 3CFBE8 004CFBE8 0000048E */  lw         $4, 0x0($16)
    /* 3CFBEC 004CFBEC 00000000 */  nop
  .L004CFBF0:
    /* 3CFBF0 004CFBF0 04001026 */  addiu      $16, $16, 0x4
    /* 3CFBF4 004CFBF4 0000838C */  lw         $3, 0x0($4)
    /* 3CFBF8 004CFBF8 2400628C */  lw         $2, 0x24($3)
    /* 3CFBFC 004CFBFC 09F84000 */  jalr       $2
    /* 3CFC00 004CFC00 01000524 */   addiu     $5, $0, 0x1
    /* 3CFC04 004CFC04 42880200 */  srl        $17, $2, 1
    /* 3CFC08 004CFC08 2A183202 */  slt        $3, $17, $18
    /* 3CFC0C 004CFC0C 31006014 */  bnez       $3, .L004CFCD4
    /* 3CFC10 004CFC10 2D100000 */   daddu     $2, $0, $0
    /* 3CFC14 004CFC14 5800E38E */  lw         $3, 0x58($23)
    /* 3CFC18 004CFC18 01009426 */  addiu      $20, $20, 0x1
    /* 3CFC1C 004CFC1C 2A108302 */  slt        $2, $20, $3
    /* 3CFC20 004CFC20 F3FF4054 */  bnel       $2, $0, .L004CFBF0
    /* 3CFC24 004CFC24 0000048E */   lw        $4, 0x0($16)
  .L004CFC28:
    /* 3CFC28 004CFC28 29006018 */  blez       $3, .L004CFCD0
    /* 3CFC2C 004CFC2C 2DA00000 */   daddu     $20, $0, $0
    /* 3CFC30 004CFC30 2DA80000 */  daddu      $21, $0, $0
    /* 3CFC34 004CFC34 00000000 */  nop
  .L004CFC38:
    /* 3CFC38 004CFC38 2100401A */  blez       $18, .L004CFCC0
    /* 3CFC3C 004CFC3C 2D880000 */   daddu     $17, $0, $0
    /* 3CFC40 004CFC40 1000A28F */  lw         $2, 0x10($29)
    /* 3CFC44 004CFC44 40B01200 */  sll        $22, $18, 1
    /* 3CFC48 004CFC48 2180BE02 */  addu       $16, $21, $30
    /* 3CFC4C 004CFC4C 2198A202 */  addu       $19, $21, $2
    /* 3CFC50 004CFC50 0000048E */  lw         $4, 0x0($16)
    /* 3CFC54 004CFC54 00000000 */  nop
  .L004CFC58:
    /* 3CFC58 004CFC58 2D38A003 */  daddu      $7, $29, $0
    /* 3CFC5C 004CFC5C 01000524 */  addiu      $5, $0, 0x1
    /* 3CFC60 004CFC60 0000838C */  lw         $3, 0x0($4)
    /* 3CFC64 004CFC64 1800628C */  lw         $2, 0x18($3)
    /* 3CFC68 004CFC68 09F84000 */  jalr       $2
    /* 3CFC6C 004CFC6C 2D30C002 */   daddu     $6, $22, $0
    /* 3CFC70 004CFC70 0000638E */  lw         $3, 0x0($19)
    /* 3CFC74 004CFC74 0000A58F */  lw         $5, 0x0($29)
    /* 3CFC78 004CFC78 40201100 */  sll        $4, $17, 1
    /* 3CFC7C 004CFC7C 0400A68F */  lw         $6, 0x4($29)
    /* 3CFC80 004CFC80 04FE100C */  jal        func_0043f810
    /* 3CFC84 004CFC84 21208300 */   addu      $4, $4, $3
    /* 3CFC88 004CFC88 0000048E */  lw         $4, 0x0($16)
    /* 3CFC8C 004CFC8C 0400A28F */  lw         $2, 0x4($29)
    /* 3CFC90 004CFC90 2D280000 */  daddu      $5, $0, $0
    /* 3CFC94 004CFC94 0000878C */  lw         $7, 0x0($4)
    /* 3CFC98 004CFC98 2D30A003 */  daddu      $6, $29, $0
    /* 3CFC9C 004CFC9C C0130200 */  sll        $2, $2, 15
    /* 3CFCA0 004CFCA0 03140200 */  sra        $2, $2, 16
    /* 3CFCA4 004CFCA4 2000E38C */  lw         $3, 0x20($7)
    /* 3CFCA8 004CFCA8 09F86000 */  jalr       $3
    /* 3CFCAC 004CFCAC 21882202 */   addu      $17, $17, $2
    /* 3CFCB0 004CFCB0 2A103202 */  slt        $2, $17, $18
    /* 3CFCB4 004CFCB4 E8FF4054 */  bnel       $2, $0, .L004CFC58
    /* 3CFCB8 004CFCB8 0000048E */   lw        $4, 0x0($16)
    /* 3CFCBC 004CFCBC 5800E38E */  lw         $3, 0x58($23)
  .L004CFCC0:
    /* 3CFCC0 004CFCC0 01009426 */  addiu      $20, $20, 0x1
    /* 3CFCC4 004CFCC4 2A108302 */  slt        $2, $20, $3
    /* 3CFCC8 004CFCC8 DBFF4014 */  bnez       $2, .L004CFC38
    /* 3CFCCC 004CFCCC 0400B526 */   addiu     $21, $21, 0x4
  .L004CFCD0:
    /* 3CFCD0 004CFCD0 2D102002 */  daddu      $2, $17, $0
  .L004CFCD4:
    /* 3CFCD4 004CFCD4 2000B0DF */  ld         $16, 0x20($29)
    /* 3CFCD8 004CFCD8 2800B1DF */  ld         $17, 0x28($29)
    /* 3CFCDC 004CFCDC 3000B2DF */  ld         $18, 0x30($29)
    /* 3CFCE0 004CFCE0 3800B3DF */  ld         $19, 0x38($29)
    /* 3CFCE4 004CFCE4 4000B4DF */  ld         $20, 0x40($29)
    /* 3CFCE8 004CFCE8 4800B5DF */  ld         $21, 0x48($29)
    /* 3CFCEC 004CFCEC 5000B6DF */  ld         $22, 0x50($29)
    /* 3CFCF0 004CFCF0 5800B7DF */  ld         $23, 0x58($29)
    /* 3CFCF4 004CFCF4 6000BEDF */  ld         $30, 0x60($29)
    /* 3CFCF8 004CFCF8 6800BFDF */  ld         $31, 0x68($29)
    /* 3CFCFC 004CFCFC 0800E003 */  jr         $31
    /* 3CFD00 004CFD00 7000BD27 */   addiu     $29, $29, 0x70
    /* 3CFD04 004CFD04 00000000 */  nop
.size func_004cfb98, 0x170
