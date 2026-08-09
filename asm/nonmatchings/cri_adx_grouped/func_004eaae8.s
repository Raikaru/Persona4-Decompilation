.section .text
.set noat
.set noreorder
glabel func_004eaae8
    /* 3EAAE8 004EAAE8 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3EAAEC 004EAAEC 2DC08000 */  daddu      $24, $4, $0
    /* 3EAAF0 004EAAF0 0000B0FF */  sd         $16, 0x0($29)
    /* 3EAAF4 004EAAF4 76000D3C */  lui        $13, %hi(D_0075C080)
    /* 3EAAF8 004EAAF8 80C0AD25 */  addiu      $13, $13, %lo(D_0075C080)
    /* 3EAAFC 004EAAFC 002C0500 */  sll        $5, $5, 16
    /* 3EAB00 004EAB00 1C00038F */  lw         $3, 0x1C($24)
    /* 3EAB04 004EAB04 032C0500 */  sra        $5, $5, 16
    /* 3EAB08 004EAB08 2000028F */  lw         $2, 0x20($24)
    /* 3EAB0C 004EAB0C 11F20B24 */  addiu      $11, $0, -0xDEF
    /* 3EAB10 004EAB10 80180300 */  sll        $3, $3, 2
    /* 3EAB14 004EAB14 2AF80F24 */  addiu      $15, $0, -0x7D6
    /* 3EAB18 004EAB18 80100200 */  sll        $2, $2, 2
    /* 3EAB1C 004EAB1C 21186D00 */  addu       $3, $3, $13
    /* 3EAB20 004EAB20 21104D00 */  addu       $2, $2, $13
    /* 3EAB24 004EAB24 0000648C */  lw         $4, 0x0($3)
    /* 3EAB28 004EAB28 0000488C */  lw         $8, 0x0($2)
    /* 3EAB2C 004EAB2C 2800028F */  lw         $2, 0x28($24)
    /* 3EAB30 004EAB30 1820A400 */  mult       $4, $5, $4
    /* 3EAB34 004EAB34 1828A870 */  mult1      $5, $5, $8
    /* 3EAB38 004EAB38 0800088F */  lw         $8, 0x8($24)
    /* 3EAB3C 004EAB3C 80100200 */  sll        $2, $2, 2
    /* 3EAB40 004EAB40 14000A8F */  lw         $10, 0x14($24)
    /* 3EAB44 004EAB44 21104D00 */  addu       $2, $2, $13
    /* 3EAB48 004EAB48 24000C8F */  lw         $12, 0x24($24)
    /* 3EAB4C 004EAB4C 0000438C */  lw         $3, 0x0($2)
    /* 3EAB50 004EAB50 EF0D0224 */  addiu      $2, $0, 0xDEF
    /* 3EAB54 004EAB54 03230400 */  sra        $4, $4, 12
    /* 3EAB58 004EAB58 032B0500 */  sra        $5, $5, 12
    /* 3EAB5C 004EAB5C 1848A300 */  mult       $9, $5, $3
    /* 3EAB60 004EAB60 18188370 */  mult1      $3, $4, $3
    /* 3EAB64 004EAB64 0C00108F */  lw         $16, 0xC($24)
    /* 3EAB68 004EAB68 80700A00 */  sll        $14, $10, 2
    /* 3EAB6C 004EAB6C 2D50C001 */  daddu      $10, $14, $0
    /* 3EAB70 004EAB70 2170C801 */  addu       $14, $14, $8
    /* 3EAB74 004EAB74 80600C00 */  sll        $12, $12, 2
    /* 3EAB78 004EAB78 D6070824 */  addiu      $8, $0, 0x7D6
    /* 3EAB7C 004EAB7C 031B0300 */  sra        $3, $3, 12
    /* 3EAB80 004EAB80 034B0900 */  sra        $9, $9, 12
    /* 3EAB84 004EAB84 18586B00 */  mult       $11, $3, $11
    /* 3EAB88 004EAB88 18186870 */  mult1      $3, $3, $8
    /* 3EAB8C 004EAB8C 18782F71 */  mult1      $15, $9, $15
    /* 3EAB90 004EAB90 18482201 */  mult       $9, $9, $2
    /* 3EAB94 004EAB94 21608D01 */  addu       $12, $12, $13
    /* 3EAB98 004EAB98 21685001 */  addu       $13, $10, $16
    /* 3EAB9C 004EAB9C 2D50C001 */  daddu      $10, $14, $0
    /* 3EABA0 004EABA0 0000828D */  lw         $2, 0x0($12)
    /* 3EABA4 004EABA4 0000A88D */  lw         $8, 0x0($13)
    /* 3EABA8 004EABA8 21586F01 */  addu       $11, $11, $15
    /* 3EABAC 004EABAC 00004C8D */  lw         $12, 0x0($10)
    /* 3EABB0 004EABB0 035B0B00 */  sra        $11, $11, 12
    /* 3EABB4 004EABB4 1828A200 */  mult       $5, $5, $2
    /* 3EABB8 004EABB8 0000CBAD */  sw         $11, 0x0($14)
    /* 3EABBC 004EABBC FF7F0B24 */  addiu      $11, $0, 0x7FFF
    /* 3EABC0 004EABC0 18208270 */  mult1      $4, $4, $2
    /* 3EABC4 004EABC4 21482301 */  addu       $9, $9, $3
    /* 3EABC8 004EABC8 1400028F */  lw         $2, 0x14($24)
    /* 3EABCC 004EABCC 034B0900 */  sra        $9, $9, 12
    /* 3EABD0 004EABD0 032B0500 */  sra        $5, $5, 12
    /* 3EABD4 004EABD4 FF7F0A24 */  addiu      $10, $0, 0x7FFF
    /* 3EABD8 004EABD8 80100200 */  sll        $2, $2, 2
    /* 3EABDC 004EABDC 2128A800 */  addu       $5, $5, $8
    /* 3EABE0 004EABE0 21105000 */  addu       $2, $2, $16
    /* 3EABE4 004EABE4 03230400 */  sra        $4, $4, 12
    /* 3EABE8 004EABE8 000049AC */  sw         $9, 0x0($2)
    /* 3EABEC 004EABEC 00800224 */  addiu      $2, $0, -0x8000
    /* 3EABF0 004EABF0 21208C00 */  addu       $4, $4, $12
    /* 3EABF4 004EABF4 00800C24 */  addiu      $12, $0, -0x8000
    /* 3EABF8 004EABF8 1400088F */  lw         $8, 0x14($24)
    /* 3EABFC 004EABFC 2A504401 */  slt        $10, $10, $4
    /* 3EAC00 004EAC00 2A586501 */  slt        $11, $11, $5
    /* 3EAC04 004EAC04 0080A328 */  slti       $3, $5, -0x8000
    /* 3EAC08 004EAC08 00808D28 */  slti       $13, $4, -0x8000
    /* 3EAC0C 004EAC0C 1800098F */  lw         $9, 0x18($24)
    /* 3EAC10 004EAC10 0B284300 */  movn       $5, $2, $3
    /* 3EAC14 004EAC14 FF7F0224 */  addiu      $2, $0, 0x7FFF
    /* 3EAC18 004EAC18 01000825 */  addiu      $8, $8, 0x1
    /* 3EAC1C 004EAC1C 0B208D01 */  movn       $4, $12, $13
    /* 3EAC20 004EAC20 00004A39 */  xori       $10, $10, 0x0
    /* 3EAC24 004EAC24 00006B39 */  xori       $11, $11, 0x0
    /* 3EAC28 004EAC28 FF7F0324 */  addiu      $3, $0, 0x7FFF
    /* 3EAC2C 004EAC2C 0B204A00 */  movn       $4, $2, $10
    /* 3EAC30 004EAC30 0B286B00 */  movn       $5, $3, $11
    /* 3EAC34 004EAC34 2A480901 */  slt        $9, $8, $9
    /* 3EAC38 004EAC38 0000C4A4 */  sh         $4, 0x0($6)
    /* 3EAC3C 004EAC3C 140008AF */  sw         $8, 0x14($24)
    /* 3EAC40 004EAC40 02002015 */  bnez       $9, .L004EAC4C
    /* 3EAC44 004EAC44 0000E5A4 */   sh        $5, 0x0($7)
    /* 3EAC48 004EAC48 140000AF */  sw         $0, 0x14($24)
  .L004EAC4C:
    /* 3EAC4C 004EAC4C 0000B0DF */  ld         $16, 0x0($29)
    /* 3EAC50 004EAC50 0800E003 */  jr         $31
    /* 3EAC54 004EAC54 1000BD27 */   addiu     $29, $29, 0x10
.size func_004eaae8, 0x170
