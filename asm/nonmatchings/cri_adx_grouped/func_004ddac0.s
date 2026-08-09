.section .text
.set noat
.set noreorder
glabel func_004ddac0
    /* 3DDAC0 004DDAC0 C0FFBD27 */  addiu      $29, $29, -0x40
    /* 3DDAC4 004DDAC4 0000B0FF */  sd         $16, 0x0($29)
    /* 3DDAC8 004DDAC8 2D80E000 */  daddu      $16, $7, $0
    /* 3DDACC 004DDACC 0800B1FF */  sd         $17, 0x8($29)
    /* 3DDAD0 004DDAD0 2D880000 */  daddu      $17, $0, $0
    /* 3DDAD4 004DDAD4 1000B2FF */  sd         $18, 0x10($29)
    /* 3DDAD8 004DDAD8 2D90A000 */  daddu      $18, $5, $0
    /* 3DDADC 004DDADC 1800B3FF */  sd         $19, 0x18($29)
    /* 3DDAE0 004DDAE0 2D988000 */  daddu      $19, $4, $0
    /* 3DDAE4 004DDAE4 2000B4FF */  sd         $20, 0x20($29)
    /* 3DDAE8 004DDAE8 7300143C */  lui        $20, %hi(D_00729A40)
    /* 3DDAEC 004DDAEC 2800B5FF */  sd         $21, 0x28($29)
    /* 3DDAF0 004DDAF0 2DA8C000 */  daddu      $21, $6, $0
    /* 3DDAF4 004DDAF4 3000BFFF */  sd         $31, 0x30($29)
    /* 3DDAF8 004DDAF8 409A8326 */  addiu      $3, $20, %lo(D_00729A40)
    /* 3DDAFC 004DDAFC 0000628C */  lw         $2, 0x0($3)
    /* 3DDB00 004DDB00 0C004010 */  beqz       $2, .L004DDB34
    /* 3DDB04 004DDB04 2D300001 */   daddu     $6, $8, $0
    /* 3DDB08 004DDB08 01003126 */  addiu      $17, $17, 0x1
    /* 3DDB0C 004DDB0C 00000000 */  nop
  .L004DDB10:
    /* 3DDB10 004DDB10 1000222A */  slti       $2, $17, 0x10
    /* 3DDB14 004DDB14 07004010 */  beqz       $2, .L004DDB34
    /* 3DDB18 004DDB18 04006324 */   addiu     $3, $3, 0x4
    /* 3DDB1C 004DDB1C 0000628C */  lw         $2, 0x0($3)
    /* 3DDB20 004DDB20 00000000 */  nop
    /* 3DDB24 004DDB24 00000000 */  nop
    /* 3DDB28 004DDB28 00000000 */  nop
    /* 3DDB2C 004DDB2C F8FF4054 */  bnel       $2, $0, .L004DDB10
    /* 3DDB30 004DDB30 01003126 */   addiu     $17, $17, 0x1
  .L004DDB34:
    /* 3DDB34 004DDB34 10000324 */  addiu      $3, $0, 0x10
    /* 3DDB38 004DDB38 2C002312 */  beq        $17, $3, .L004DDBEC
    /* 3DDB3C 004DDB3C 2D100000 */   daddu     $2, $0, $0
    /* 3DDB40 004DDB40 2D200002 */  daddu      $4, $16, $0
    /* 3DDB44 004DDB44 72FE100C */  jal        func_0043f9c8
    /* 3DDB48 004DDB48 2D280000 */   daddu     $5, $0, $0
    /* 3DDB4C 004DDB4C 409A8326 */  addiu      $3, $20, %lo(D_00729A40)
    /* 3DDB50 004DDB50 80101100 */  sll        $2, $17, 2
    /* 3DDB54 004DDB54 3C0011AE */  sw         $17, 0x3C($16)
    /* 3DDB58 004DDB58 21104300 */  addu       $2, $2, $3
    /* 3DDB5C 004DDB5C 2D206002 */  daddu      $4, $19, $0
    /* 3DDB60 004DDB60 D264130C */  jal        func_004d9348
    /* 3DDB64 004DDB64 000050AC */   sw        $16, 0x0($2)
    /* 3DDB68 004DDB68 2D184000 */  daddu      $3, $2, $0
    /* 3DDB6C 004DDB6C 1F006010 */  beqz       $3, .L004DDBEC
    /* 3DDB70 004DDB70 0C0003AE */   sw        $3, 0xC($16)
    /* 3DDB74 004DDB74 50000426 */  addiu      $4, $16, 0x50
    /* 3DDB78 004DDB78 8467130C */  jal        func_004d9e10
    /* 3DDB7C 004DDB7C 3C1A0524 */   addiu     $5, $0, 0x1A3C
    /* 3DDB80 004DDB80 2D184000 */  daddu      $3, $2, $0
    /* 3DDB84 004DDB84 19006010 */  beqz       $3, .L004DDBEC
    /* 3DDB88 004DDB88 000003AE */   sw        $3, 0x0($16)
    /* 3DDB8C 004DDB8C 100013AE */  sw         $19, 0x10($16)
    /* 3DDB90 004DDB90 2D280000 */  daddu      $5, $0, $0
    /* 3DDB94 004DDB94 0B00401A */  blez       $18, .L004DDBC4
    /* 3DDB98 004DDB98 060012A2 */   sb        $18, 0x6($16)
    /* 3DDB9C 004DDB9C 2D30A002 */  daddu      $6, $21, $0
    /* 3DDBA0 004DDBA0 14000426 */  addiu      $4, $16, 0x14
    /* 3DDBA4 004DDBA4 00000000 */  nop
  .L004DDBA8:
    /* 3DDBA8 004DDBA8 0000C38C */  lw         $3, 0x0($6)
    /* 3DDBAC 004DDBAC 0400C624 */  addiu      $6, $6, 0x4
    /* 3DDBB0 004DDBB0 0100A524 */  addiu      $5, $5, 0x1
    /* 3DDBB4 004DDBB4 2A10B200 */  slt        $2, $5, $18
    /* 3DDBB8 004DDBB8 000083AC */  sw         $3, 0x0($4)
    /* 3DDBBC 004DDBBC FAFF4014 */  bnez       $2, .L004DDBA8
    /* 3DDBC0 004DDBC0 04008424 */   addiu     $4, $4, 0x4
  .L004DDBC4:
    /* 3DDBC4 004DDBC4 050000A2 */  sb         $0, 0x5($16)
    /* 3DDBC8 004DDBC8 A276130C */  jal        func_004dda88
    /* 3DDBCC 004DDBCC 2D200002 */   daddu     $4, $16, $0
    /* 3DDBD0 004DDBD0 400000AE */  sw         $0, 0x40($16)
    /* 3DDBD4 004DDBD4 01000224 */  addiu      $2, $0, 0x1
    /* 3DDBD8 004DDBD8 440000AE */  sw         $0, 0x44($16)
    /* 3DDBDC 004DDBDC 480000AE */  sw         $0, 0x48($16)
    /* 3DDBE0 004DDBE0 4C0000AE */  sw         $0, 0x4C($16)
    /* 3DDBE4 004DDBE4 040002A2 */  sb         $2, 0x4($16)
    /* 3DDBE8 004DDBE8 2D100002 */  daddu      $2, $16, $0
  .L004DDBEC:
    /* 3DDBEC 004DDBEC 0000B0DF */  ld         $16, 0x0($29)
    /* 3DDBF0 004DDBF0 0800B1DF */  ld         $17, 0x8($29)
    /* 3DDBF4 004DDBF4 1000B2DF */  ld         $18, 0x10($29)
    /* 3DDBF8 004DDBF8 1800B3DF */  ld         $19, 0x18($29)
    /* 3DDBFC 004DDBFC 2000B4DF */  ld         $20, 0x20($29)
    /* 3DDC00 004DDC00 2800B5DF */  ld         $21, 0x28($29)
    /* 3DDC04 004DDC04 3000BFDF */  ld         $31, 0x30($29)
    /* 3DDC08 004DDC08 0800E003 */  jr         $31
    /* 3DDC0C 004DDC0C 4000BD27 */   addiu     $29, $29, 0x40
.size func_004ddac0, 0x150
