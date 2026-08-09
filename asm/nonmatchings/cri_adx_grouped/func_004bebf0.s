.section .text
.set noat
.set noreorder
glabel func_004bebf0
    /* 3BEBF0 004BEBF0 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 3BEBF4 004BEBF4 0000B0FF */  sd         $16, 0x0($29)
    /* 3BEBF8 004BEBF8 2D808000 */  daddu      $16, $4, $0
    /* 3BEBFC 004BEBFC 0800B1FF */  sd         $17, 0x8($29)
    /* 3BEC00 004BEC00 1000B2FF */  sd         $18, 0x10($29)
    /* 3BEC04 004BEC04 1800BFFF */  sd         $31, 0x18($29)
    /* 3BEC08 004BEC08 5000028E */  lw         $2, 0x50($16)
    /* 3BEC0C 004BEC0C 08004014 */  bnez       $2, .L004BEC30
    /* 3BEC10 004BEC10 7500043C */   lui       $4, %hi(D_00756E50)
    /* 3BEC14 004BEC14 0000B0DF */  ld         $16, 0x0($29)
    /* 3BEC18 004BEC18 0800B1DF */  ld         $17, 0x8($29)
    /* 3BEC1C 004BEC1C 506E8424 */  addiu      $4, $4, %lo(D_00756E50)
    /* 3BEC20 004BEC20 1000B2DF */  ld         $18, 0x10($29)
    /* 3BEC24 004BEC24 1800BFDF */  ld         $31, 0x18($29)
    /* 3BEC28 004BEC28 A8F51208 */  j          func_004bd6a0
    /* 3BEC2C 004BEC2C 2000BD27 */   addiu     $29, $29, 0x20
  .L004BEC30:
    /* 3BEC30 004BEC30 96F5120C */  jal        func_004bd658
    /* 3BEC34 004BEC34 00000000 */   nop
    /* 3BEC38 004BEC38 2D200002 */  daddu      $4, $16, $0
    /* 3BEC3C 004BEC3C 7000130C */  jal        func_004c01c0
    /* 3BEC40 004BEC40 01000524 */   addiu     $5, $0, 0x1
    /* 3BEC44 004BEC44 1000028E */  lw         $2, 0x10($16)
    /* 3BEC48 004BEC48 2D200002 */  daddu      $4, $16, $0
    /* 3BEC4C 004BEC4C 2D300000 */  daddu      $6, $0, $0
    /* 3BEC50 004BEC50 40280200 */  sll        $5, $2, 1
    /* 3BEC54 004BEC54 02000724 */  addiu      $7, $0, 0x2
    /* 3BEC58 004BEC58 2128A200 */  addu       $5, $5, $2
    /* 3BEC5C 004BEC5C 80280500 */  sll        $5, $5, 2
    /* 3BEC60 004BEC60 21280502 */  addu       $5, $16, $5
    /* 3BEC64 004BEC64 4600130C */  jal        func_004c0118
    /* 3BEC68 004BEC68 1800A524 */   addiu     $5, $5, 0x18
    /* 3BEC6C 004BEC6C 6000038E */  lw         $3, 0x60($16)
    /* 3BEC70 004BEC70 01000224 */  addiu      $2, $0, 0x1
    /* 3BEC74 004BEC74 2A006254 */  bnel       $3, $2, .L004BED20
    /* 3BEC78 004BEC78 0000B0DF */   ld        $16, 0x0($29)
    /* 3BEC7C 004BEC7C 1000038E */  lw         $3, 0x10($16)
    /* 3BEC80 004BEC80 08001126 */  addiu      $17, $16, 0x8
    /* 3BEC84 004BEC84 40100300 */  sll        $2, $3, 1
    /* 3BEC88 004BEC88 21104300 */  addu       $2, $2, $3
    /* 3BEC8C 004BEC8C 80100200 */  sll        $2, $2, 2
    /* 3BEC90 004BEC90 21105100 */  addu       $2, $2, $17
    /* 3BEC94 004BEC94 1000448C */  lw         $4, 0x10($2)
    /* 3BEC98 004BEC98 0000838C */  lw         $3, 0x0($4)
    /* 3BEC9C 004BEC9C 1800628C */  lw         $2, 0x18($3)
    /* 3BECA0 004BECA0 09F84000 */  jalr       $2
    /* 3BECA4 004BECA4 10001226 */   addiu     $18, $16, 0x10
    /* 3BECA8 004BECA8 1000038E */  lw         $3, 0x10($16)
    /* 3BECAC 004BECAC 40FC0524 */  addiu      $5, $0, -0x3C0
    /* 3BECB0 004BECB0 40100300 */  sll        $2, $3, 1
    /* 3BECB4 004BECB4 21104300 */  addu       $2, $2, $3
    /* 3BECB8 004BECB8 80100200 */  sll        $2, $2, 2
    /* 3BECBC 004BECBC 21105200 */  addu       $2, $2, $18
    /* 3BECC0 004BECC0 D8F5120C */  jal        func_004bd760
    /* 3BECC4 004BECC4 1000448C */   lw        $4, 0x10($2)
    /* 3BECC8 004BECC8 5C00028E */  lw         $2, 0x5C($16)
    /* 3BECCC 004BECCC 14004050 */  beql       $2, $0, .L004BED20
    /* 3BECD0 004BECD0 0000B0DF */   ld        $16, 0x0($29)
    /* 3BECD4 004BECD4 1400038E */  lw         $3, 0x14($16)
    /* 3BECD8 004BECD8 40100300 */  sll        $2, $3, 1
    /* 3BECDC 004BECDC 21104300 */  addu       $2, $2, $3
    /* 3BECE0 004BECE0 80100200 */  sll        $2, $2, 2
    /* 3BECE4 004BECE4 21105100 */  addu       $2, $2, $17
    /* 3BECE8 004BECE8 1000448C */  lw         $4, 0x10($2)
    /* 3BECEC 004BECEC 0000838C */  lw         $3, 0x0($4)
    /* 3BECF0 004BECF0 1800628C */  lw         $2, 0x18($3)
    /* 3BECF4 004BECF4 09F84000 */  jalr       $2
    /* 3BECF8 004BECF8 00000000 */   nop
    /* 3BECFC 004BECFC 1400038E */  lw         $3, 0x14($16)
    /* 3BED00 004BED00 40FC0524 */  addiu      $5, $0, -0x3C0
    /* 3BED04 004BED04 40100300 */  sll        $2, $3, 1
    /* 3BED08 004BED08 21104300 */  addu       $2, $2, $3
    /* 3BED0C 004BED0C 80100200 */  sll        $2, $2, 2
    /* 3BED10 004BED10 21105200 */  addu       $2, $2, $18
    /* 3BED14 004BED14 D8F5120C */  jal        func_004bd760
    /* 3BED18 004BED18 1000448C */   lw        $4, 0x10($2)
    /* 3BED1C 004BED1C 0000B0DF */  ld         $16, 0x0($29)
  .L004BED20:
    /* 3BED20 004BED20 0800B1DF */  ld         $17, 0x8($29)
    /* 3BED24 004BED24 1000B2DF */  ld         $18, 0x10($29)
    /* 3BED28 004BED28 1800BFDF */  ld         $31, 0x18($29)
    /* 3BED2C 004BED2C 9CF51208 */  j          func_004bd670
    /* 3BED30 004BED30 2000BD27 */   addiu     $29, $29, 0x20
    /* 3BED34 004BED34 00000000 */  nop
.size func_004bebf0, 0x148
