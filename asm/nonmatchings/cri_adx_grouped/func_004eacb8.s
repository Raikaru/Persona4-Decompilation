.section .text
.set noat
.set noreorder
glabel func_004eacb8
    /* 3EACB8 004EACB8 B0FFBD27 */  addiu      $29, $29, -0x50
    /* 3EACBC 004EACBC 2D788000 */  daddu      $15, $4, $0
    /* 3EACC0 004EACC0 0000B0FF */  sd         $16, 0x0($29)
    /* 3EACC4 004EACC4 2D800000 */  daddu      $16, $0, $0
    /* 3EACC8 004EACC8 0800B1FF */  sd         $17, 0x8($29)
    /* 3EACCC 004EACCC 7600023C */  lui        $2, %hi(D_0075C080)
    /* 3EACD0 004EACD0 1000B2FF */  sd         $18, 0x10($29)
    /* 3EACD4 004EACD4 00801224 */  addiu      $18, $0, -0x8000
    /* 3EACD8 004EACD8 1800B3FF */  sd         $19, 0x18($29)
    /* 3EACDC 004EACDC FF7F1324 */  addiu      $19, $0, 0x7FFF
    /* 3EACE0 004EACE0 2000B4FF */  sd         $20, 0x20($29)
    /* 3EACE4 004EACE4 2DA0E000 */  daddu      $20, $7, $0
    /* 3EACE8 004EACE8 2800B5FF */  sd         $21, 0x28($29)
    /* 3EACEC 004EACEC 2DA8C000 */  daddu      $21, $6, $0
    /* 3EACF0 004EACF0 3000B6FF */  sd         $22, 0x30($29)
    /* 3EACF4 004EACF4 2DB0A000 */  daddu      $22, $5, $0
    /* 3EACF8 004EACF8 3800B7FF */  sd         $23, 0x38($29)
    /* 3EACFC 004EACFC D6071724 */  addiu      $23, $0, 0x7D6
    /* 3EAD00 004EAD00 4000BEFF */  sd         $30, 0x40($29)
    /* 3EAD04 004EAD04 EF0D1E24 */  addiu      $30, $0, 0xDEF
    /* 3EAD08 004EAD08 80C05124 */  addiu      $17, $2, %lo(D_0075C080)
    /* 3EAD0C 004EAD0C 0C00F98D */  lw         $25, 0xC($15)
    /* 3EAD10 004EAD10 0800F88D */  lw         $24, 0x8($15)
    /* 3EAD14 004EAD14 00000000 */  nop
  .L004EAD18:
    /* 3EAD18 004EAD18 1C00E38D */  lw         $3, 0x1C($15)
    /* 3EAD1C 004EAD1C 40601000 */  sll        $12, $16, 1
    /* 3EAD20 004EAD20 2000E28D */  lw         $2, 0x20($15)
    /* 3EAD24 004EAD24 21209601 */  addu       $4, $12, $22
    /* 3EAD28 004EAD28 80180300 */  sll        $3, $3, 2
    /* 3EAD2C 004EAD2C 00008584 */  lh         $5, 0x0($4)
    /* 3EAD30 004EAD30 80100200 */  sll        $2, $2, 2
    /* 3EAD34 004EAD34 21187100 */  addu       $3, $3, $17
    /* 3EAD38 004EAD38 21105100 */  addu       $2, $2, $17
    /* 3EAD3C 004EAD3C 0000648C */  lw         $4, 0x0($3)
    /* 3EAD40 004EAD40 0000468C */  lw         $6, 0x0($2)
    /* 3EAD44 004EAD44 FF7F0E24 */  addiu      $14, $0, 0x7FFF
    /* 3EAD48 004EAD48 2800E28D */  lw         $2, 0x28($15)
    /* 3EAD4C 004EAD4C 1820A400 */  mult       $4, $5, $4
    /* 3EAD50 004EAD50 1828A670 */  mult1      $5, $5, $6
    /* 3EAD54 004EAD54 2400E38D */  lw         $3, 0x24($15)
    /* 3EAD58 004EAD58 80100200 */  sll        $2, $2, 2
    /* 3EAD5C 004EAD5C 0000078F */  lw         $7, 0x0($24)
    /* 3EAD60 004EAD60 21105100 */  addu       $2, $2, $17
    /* 3EAD64 004EAD64 80180300 */  sll        $3, $3, 2
    /* 3EAD68 004EAD68 0000468C */  lw         $6, 0x0($2)
    /* 3EAD6C 004EAD6C 03230400 */  sra        $4, $4, 12
    /* 3EAD70 004EAD70 032B0500 */  sra        $5, $5, 12
    /* 3EAD74 004EAD74 21187100 */  addu       $3, $3, $17
    /* 3EAD78 004EAD78 1840A600 */  mult       $8, $5, $6
    /* 3EAD7C 004EAD7C 18308670 */  mult1      $6, $4, $6
    /* 3EAD80 004EAD80 0000628C */  lw         $2, 0x0($3)
    /* 3EAD84 004EAD84 FF7F0D24 */  addiu      $13, $0, 0x7FFF
    /* 3EAD88 004EAD88 0000238F */  lw         $3, 0x0($25)
    /* 3EAD8C 004EAD8C 01001026 */  addiu      $16, $16, 0x1
    /* 3EAD90 004EAD90 1828A200 */  mult       $5, $5, $2
    /* 3EAD94 004EAD94 18208270 */  mult1      $4, $4, $2
    /* 3EAD98 004EAD98 03330600 */  sra        $6, $6, 12
    /* 3EAD9C 004EAD9C 11F20224 */  addiu      $2, $0, -0xDEF
    /* 3EADA0 004EADA0 03430800 */  sra        $8, $8, 12
    /* 3EADA4 004EADA4 1858D770 */  mult1      $11, $6, $23
    /* 3EADA8 004EADA8 1830C200 */  mult       $6, $6, $2
    /* 3EADAC 004EADAC 2AF80224 */  addiu      $2, $0, -0x7D6
    /* 3EADB0 004EADB0 18501E01 */  mult       $10, $8, $30
    /* 3EADB4 004EADB4 18400271 */  mult1      $8, $8, $2
    /* 3EADB8 004EADB8 03230400 */  sra        $4, $4, 12
    /* 3EADBC 004EADBC 032B0500 */  sra        $5, $5, 12
    /* 3EADC0 004EADC0 21208700 */  addu       $4, $4, $7
    /* 3EADC4 004EADC4 2128A300 */  addu       $5, $5, $3
    /* 3EADC8 004EADC8 2A106402 */  slt        $2, $19, $4
    /* 3EADCC 004EADCC 2A186502 */  slt        $3, $19, $5
    /* 3EADD0 004EADD0 00808728 */  slti       $7, $4, -0x8000
    /* 3EADD4 004EADD4 0080A928 */  slti       $9, $5, -0x8000
    /* 3EADD8 004EADD8 00004238 */  xori       $2, $2, 0x0
    /* 3EADDC 004EADDC 00006338 */  xori       $3, $3, 0x0
    /* 3EADE0 004EADE0 2130C800 */  addu       $6, $6, $8
    /* 3EADE4 004EADE4 21504B01 */  addu       $10, $10, $11
    /* 3EADE8 004EADE8 0B204702 */  movn       $4, $18, $7
    /* 3EADEC 004EADEC 0B284902 */  movn       $5, $18, $9
    /* 3EADF0 004EADF0 0B20C201 */  movn       $4, $14, $2
    /* 3EADF4 004EADF4 21109401 */  addu       $2, $12, $20
    /* 3EADF8 004EADF8 0B28A301 */  movn       $5, $13, $3
    /* 3EADFC 004EADFC 2000032A */  slti       $3, $16, 0x20
    /* 3EAE00 004EAE00 03330600 */  sra        $6, $6, 12
    /* 3EAE04 004EAE04 03530A00 */  sra        $10, $10, 12
    /* 3EAE08 004EAE08 21609501 */  addu       $12, $12, $21
    /* 3EAE0C 004EAE0C 000006AF */  sw         $6, 0x0($24)
    /* 3EAE10 004EAE10 000084A5 */  sh         $4, 0x0($12)
    /* 3EAE14 004EAE14 04001827 */  addiu      $24, $24, 0x4
    /* 3EAE18 004EAE18 00002AAF */  sw         $10, 0x0($25)
    /* 3EAE1C 004EAE1C 04003927 */  addiu      $25, $25, 0x4
    /* 3EAE20 004EAE20 BDFF6014 */  bnez       $3, .L004EAD18
    /* 3EAE24 004EAE24 000045A4 */   sh        $5, 0x0($2)
    /* 3EAE28 004EAE28 0000B0DF */  ld         $16, 0x0($29)
    /* 3EAE2C 004EAE2C 0800B1DF */  ld         $17, 0x8($29)
    /* 3EAE30 004EAE30 1000B2DF */  ld         $18, 0x10($29)
    /* 3EAE34 004EAE34 1800B3DF */  ld         $19, 0x18($29)
    /* 3EAE38 004EAE38 2000B4DF */  ld         $20, 0x20($29)
    /* 3EAE3C 004EAE3C 2800B5DF */  ld         $21, 0x28($29)
    /* 3EAE40 004EAE40 3000B6DF */  ld         $22, 0x30($29)
    /* 3EAE44 004EAE44 3800B7DF */  ld         $23, 0x38($29)
    /* 3EAE48 004EAE48 4000BEDF */  ld         $30, 0x40($29)
    /* 3EAE4C 004EAE4C 0800E003 */  jr         $31
    /* 3EAE50 004EAE50 5000BD27 */   addiu     $29, $29, 0x50
    /* 3EAE54 004EAE54 00000000 */  nop
.size func_004eacb8, 0x1a0
