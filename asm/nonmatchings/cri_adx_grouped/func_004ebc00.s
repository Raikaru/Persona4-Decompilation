.section .text
.set noat
.set noreorder
glabel func_004ebc00
    /* 3EBC00 004EBC00 A0FFBD27 */  addiu      $29, $29, -0x60
    /* 3EBC04 004EBC04 7400033C */  lui        $3, %hi(D_0073A748)
    /* 3EBC08 004EBC08 1000B0FF */  sd         $16, 0x10($29)
    /* 3EBC0C 004EBC0C 7400023C */  lui        $2, %hi(D_00739798)
    /* 3EBC10 004EBC10 1800B1FF */  sd         $17, 0x18($29)
    /* 3EBC14 004EBC14 98974224 */  addiu      $2, $2, %lo(D_00739798)
    /* 3EBC18 004EBC18 2000B2FF */  sd         $18, 0x20($29)
    /* 3EBC1C 004EBC1C 2800B3FF */  sd         $19, 0x28($29)
    /* 3EBC20 004EBC20 3000B4FF */  sd         $20, 0x30($29)
    /* 3EBC24 004EBC24 3800B5FF */  sd         $21, 0x38($29)
    /* 3EBC28 004EBC28 4000B6FF */  sd         $22, 0x40($29)
    /* 3EBC2C 004EBC2C 4800B7FF */  sd         $23, 0x48($29)
    /* 3EBC30 004EBC30 5000BFFF */  sd         $31, 0x50($29)
    /* 3EBC34 004EBC34 48A7648C */  lw         $4, %lo(D_0073A748)($3)
    /* 3EBC38 004EBC38 01000324 */  addiu      $3, $0, 0x1
    /* 3EBC3C 004EBC3C 0000458C */  lw         $5, 0x0($2)
    /* 3EBC40 004EBC40 06008314 */  bne        $4, $3, .L004EBC5C
    /* 3EBC44 004EBC44 7400173C */   lui       $23, %hi(D_0073A78C)
    /* 3EBC48 004EBC48 7400023C */  lui        $2, %hi(D_0073A740)
    /* 3EBC4C 004EBC4C 40A7438C */  lw         $3, %lo(D_0073A740)($2)
    /* 3EBC50 004EBC50 94006018 */  blez       $3, .L004EBEA4
    /* 3EBC54 004EBC54 1000B0DF */   ld        $16, 0x10($29)
    /* 3EBC58 004EBC58 7400173C */  lui        $23, %hi(D_0073A78C)
  .L004EBC5C:
    /* 3EBC5C 004EBC5C 8CA7E28E */  lw         $2, %lo(D_0073A78C)($23)
    /* 3EBC60 004EBC60 8C004014 */  bnez       $2, .L004EBE94
    /* 3EBC64 004EBC64 8CA7E326 */   addiu     $3, $23, %lo(D_0073A78C)
    /* 3EBC68 004EBC68 7400103C */  lui        $16, %hi(D_0073D1E8)
    /* 3EBC6C 004EBC6C 7400133C */  lui        $19, %hi(D_0073A794)
    /* 3EBC70 004EBC70 D8BF130C */  jal        func_004eff60
    /* 3EBC74 004EBC74 E8D11026 */   addiu     $16, $16, %lo(D_0073D1E8)
    /* 3EBC78 004EBC78 6EC0130C */  jal        func_004f01b8
    /* 3EBC7C 004EBC7C 94A77126 */   addiu     $17, $19, %lo(D_0073A794)
    /* 3EBC80 004EBC80 CE95130C */  jal        func_004e5738
    /* 3EBC84 004EBC84 7400143C */   lui       $20, %hi(D_0073D1E4)
    /* 3EBC88 004EBC88 CAAF130C */  jal        func_004ebf28
    /* 3EBC8C 004EBC8C 7400123C */   lui       $18, %hi(D_0073A790)
    /* 3EBC90 004EBC90 F6AC130C */  jal        func_004eb3d8
    /* 3EBC94 004EBC94 00000000 */   nop
    /* 3EBC98 004EBC98 2D200002 */  daddu      $4, $16, $0
    /* 3EBC9C 004EBC9C 2D280000 */  daddu      $5, $0, $0
    /* 3EBCA0 004EBCA0 72FE100C */  jal        func_0043f9c8
    /* 3EBCA4 004EBCA4 D0080624 */   addiu     $6, $0, 0x8D0
    /* 3EBCA8 004EBCA8 80080424 */  addiu      $4, $0, 0x880
    /* 3EBCAC 004EBCAC 0000238E */  lw         $3, 0x0($17)
    /* 3EBCB0 004EBCB0 40001026 */  addiu      $16, $16, 0x40
    /* 3EBCB4 004EBCB4 C0FF0224 */  addiu      $2, $0, -0x40
    /* 3EBCB8 004EBCB8 24800202 */  and        $16, $16, $2
    /* 3EBCBC 004EBCBC E4D184AE */  sw         $4, %lo(D_0073D1E4)($20)
    /* 3EBCC0 004EBCC0 11006014 */  bnez       $3, .L004EBD08
    /* 3EBCC4 004EBCC4 90A750AE */   sw        $16, %lo(D_0073A790)($18)
    /* 3EBCC8 004EBCC8 28A7100C */  jal        func_00429ca0
    /* 3EBCCC 004EBCCC D0080424 */   addiu     $4, $0, 0x8D0
    /* 3EBCD0 004EBCD0 0D004014 */  bnez       $2, .L004EBD08
    /* 3EBCD4 004EBCD4 000022AE */   sw        $2, 0x0($17)
    /* 3EBCD8 004EBCD8 7600043C */  lui        $4, %hi(D_0075C8D8)
    /* 3EBCDC 004EBCDC D0080524 */  addiu      $5, $0, 0x8D0
    /* 3EBCE0 004EBCE0 FC34130C */  jal        func_004cd3f0
    /* 3EBCE4 004EBCE4 D8C88424 */   addiu     $4, $4, %lo(D_0075C8D8)
  .L004EBCE8:
    /* 3EBCE8 004EBCE8 00000000 */  nop
    /* 3EBCEC 004EBCEC 00000000 */  nop
    /* 3EBCF0 004EBCF0 00000000 */  nop
    /* 3EBCF4 004EBCF4 00000000 */  nop
    /* 3EBCF8 004EBCF8 00000000 */  nop
    /* 3EBCFC 004EBCFC FAFF0010 */  b          .L004EBCE8
    /* 3EBD00 004EBD00 00000000 */   nop
    /* 3EBD04 004EBD04 00000000 */  nop
  .L004EBD08:
    /* 3EBD08 004EBD08 94A77026 */  addiu      $16, $19, %lo(D_0073A794)
    /* 3EBD0C 004EBD0C 7600163C */  lui        $22, %hi(D_0075C7A0)
    /* 3EBD10 004EBD10 0000068E */  lw         $6, 0x0($16)
    /* 3EBD14 004EBD14 A0C7C426 */  addiu      $4, $22, %lo(D_0075C7A0)
    /* 3EBD18 004EBD18 FC34130C */  jal        func_004cd3f0
    /* 3EBD1C 004EBD1C D0080524 */   addiu     $5, $0, 0x8D0
    /* 3EBD20 004EBD20 7400083C */  lui        $8, %hi(D_0073A798)
    /* 3EBD24 004EBD24 0000028E */  lw         $2, 0x0($16)
    /* 3EBD28 004EBD28 7400103C */  lui        $16, %hi(D_0073D1E0)
    /* 3EBD2C 004EBD2C C0FF0324 */  addiu      $3, $0, -0x40
    /* 3EBD30 004EBD30 90A7458E */  lw         $5, %lo(D_0073A790)($18)
    /* 3EBD34 004EBD34 40004224 */  addiu      $2, $2, 0x40
    /* 3EBD38 004EBD38 E4D1878E */  lw         $7, %lo(D_0073D1E4)($20)
    /* 3EBD3C 004EBD3C 24104300 */  and        $2, $2, $3
    /* 3EBD40 004EBD40 01000424 */  addiu      $4, $0, 0x1
    /* 3EBD44 004EBD44 2D304000 */  daddu      $6, $2, $0
    /* 3EBD48 004EBD48 EA94130C */  jal        func_004e53a8
    /* 3EBD4C 004EBD4C 98A702AD */   sw        $2, %lo(D_0073A798)($8)
    /* 3EBD50 004EBD50 0D004014 */  bnez       $2, .L004EBD88
    /* 3EBD54 004EBD54 E0D102AE */   sw        $2, %lo(D_0073D1E0)($16)
    /* 3EBD58 004EBD58 7600043C */  lui        $4, %hi(D_0075C920)
    /* 3EBD5C 004EBD5C FC34130C */  jal        func_004cd3f0
    /* 3EBD60 004EBD60 20C98424 */   addiu     $4, $4, %lo(D_0075C920)
    /* 3EBD64 004EBD64 00000000 */  nop
  .L004EBD68:
    /* 3EBD68 004EBD68 00000000 */  nop
    /* 3EBD6C 004EBD6C 00000000 */  nop
    /* 3EBD70 004EBD70 00000000 */  nop
    /* 3EBD74 004EBD74 00000000 */  nop
    /* 3EBD78 004EBD78 00000000 */  nop
    /* 3EBD7C 004EBD7C FAFF0010 */  b          .L004EBD68
    /* 3EBD80 004EBD80 00000000 */   nop
    /* 3EBD84 004EBD84 00000000 */  nop
  .L004EBD88:
    /* 3EBD88 004EBD88 E0D11026 */  addiu      $16, $16, %lo(D_0073D1E0)
    /* 3EBD8C 004EBD8C 4F00053C */  lui        $5, %hi(func_004eb830)
    /* 3EBD90 004EBD90 0000048E */  lw         $4, 0x0($16)
    /* 3EBD94 004EBD94 30B8A524 */  addiu      $5, $5, %lo(func_004eb830)
    /* 3EBD98 004EBD98 2D300000 */  daddu      $6, $0, $0
    /* 3EBD9C 004EBD9C 6A95130C */  jal        func_004e55a8
    /* 3EBDA0 004EBDA0 7400113C */   lui       $17, %hi(D_0073A75C)
    /* 3EBDA4 004EBDA4 4F00053C */  lui        $5, %hi(func_004eb890)
    /* 3EBDA8 004EBDA8 0000048E */  lw         $4, 0x0($16)
    /* 3EBDAC 004EBDAC 90B8A524 */  addiu      $5, $5, %lo(func_004eb890)
    /* 3EBDB0 004EBDB0 2D300000 */  daddu      $6, $0, $0
    /* 3EBDB4 004EBDB4 6E95130C */  jal        func_004e55b8
    /* 3EBDB8 004EBDB8 5CA73426 */   addiu     $20, $17, %lo(D_0073A75C)
    /* 3EBDBC 004EBDBC 0000828E */  lw         $2, 0x0($20)
    /* 3EBDC0 004EBDC0 21004014 */  bnez       $2, .L004EBE48
    /* 3EBDC4 004EBDC4 7400133C */   lui       $19, %hi(D_0073A764)
    /* 3EBDC8 004EBDC8 7400023C */  lui        $2, %hi(D_0073A740)
    /* 3EBDCC 004EBDCC 7400153C */  lui        $21, %hi(D_0073A758)
    /* 3EBDD0 004EBDD0 40A7438C */  lw         $3, %lo(D_0073A740)($2)
    /* 3EBDD4 004EBDD4 58A7B026 */  addiu      $16, $21, %lo(D_0073A758)
    /* 3EBDD8 004EBDD8 2D90A002 */  daddu      $18, $21, $0
    /* 3EBDDC 004EBDDC 80120300 */  sll        $2, $3, 10
    /* 3EBDE0 004EBDE0 64A763AE */  sw         $3, %lo(D_0073A764)($19)
    /* 3EBDE4 004EBDE4 40004224 */  addiu      $2, $2, 0x40
    /* 3EBDE8 004EBDE8 000002AE */  sw         $2, 0x0($16)
    /* 3EBDEC 004EBDEC 28A7100C */  jal        func_00429ca0
    /* 3EBDF0 004EBDF0 2D204000 */   daddu     $4, $2, $0
    /* 3EBDF4 004EBDF4 0E004014 */  bnez       $2, .L004EBE30
    /* 3EBDF8 004EBDF8 000082AE */   sw        $2, 0x0($20)
    /* 3EBDFC 004EBDFC 7600043C */  lui        $4, %hi(D_0075C948)
    /* 3EBE00 004EBE00 0000058E */  lw         $5, 0x0($16)
    /* 3EBE04 004EBE04 FC34130C */  jal        func_004cd3f0
    /* 3EBE08 004EBE08 48C98424 */   addiu     $4, $4, %lo(D_0075C948)
    /* 3EBE0C 004EBE0C 00000000 */  nop
  .L004EBE10:
    /* 3EBE10 004EBE10 00000000 */  nop
    /* 3EBE14 004EBE14 00000000 */  nop
    /* 3EBE18 004EBE18 00000000 */  nop
    /* 3EBE1C 004EBE1C 00000000 */  nop
    /* 3EBE20 004EBE20 00000000 */  nop
    /* 3EBE24 004EBE24 FAFF0010 */  b          .L004EBE10
    /* 3EBE28 004EBE28 00000000 */   nop
    /* 3EBE2C 004EBE2C 00000000 */  nop
  .L004EBE30:
    /* 3EBE30 004EBE30 58A7458E */  lw         $5, %lo(D_0073A758)($18)
    /* 3EBE34 004EBE34 A0C7C426 */  addiu      $4, $22, %lo(D_0075C7A0)
    /* 3EBE38 004EBE38 FC34130C */  jal        func_004cd3f0
    /* 3EBE3C 004EBE3C 5CA7268E */   lw        $6, %lo(D_0073A75C)($17)
    /* 3EBE40 004EBE40 03000010 */  b          .L004EBE50
    /* 3EBE44 004EBE44 5CA7228E */   lw        $2, %lo(D_0073A75C)($17)
  .L004EBE48:
    /* 3EBE48 004EBE48 7400153C */  lui        $21, %hi(D_0073A758)
    /* 3EBE4C 004EBE4C 5CA7228E */  lw         $2, %lo(D_0073A75C)($17)
  .L004EBE50:
    /* 3EBE50 004EBE50 C0FF0324 */  addiu      $3, $0, -0x40
    /* 3EBE54 004EBE54 64A7658E */  lw         $5, %lo(D_0073A764)($19)
    /* 3EBE58 004EBE58 7400093C */  lui        $9, %hi(D_0073A760)
    /* 3EBE5C 004EBE5C 3F004224 */  addiu      $2, $2, 0x3F
    /* 3EBE60 004EBE60 0A000424 */  addiu      $4, $0, 0xA
    /* 3EBE64 004EBE64 24104300 */  and        $2, $2, $3
    /* 3EBE68 004EBE68 58A7A38E */  lw         $3, %lo(D_0073A758)($21)
    /* 3EBE6C 004EBE6C 0000A5AF */  sw         $5, 0x0($29)
    /* 3EBE70 004EBE70 2D28A003 */  daddu      $5, $29, $0
    /* 3EBE74 004EBE74 03000624 */  addiu      $6, $0, 0x3
    /* 3EBE78 004EBE78 2D380000 */  daddu      $7, $0, $0
    /* 3EBE7C 004EBE7C 2D400000 */  daddu      $8, $0, $0
    /* 3EBE80 004EBE80 0400A2AF */  sw         $2, 0x4($29)
    /* 3EBE84 004EBE84 60A722AD */  sw         $2, %lo(D_0073A760)($9)
    /* 3EBE88 004EBE88 2896130C */  jal        func_004e58a0
    /* 3EBE8C 004EBE8C 0800A3AF */   sw        $3, 0x8($29)
    /* 3EBE90 004EBE90 8CA7E326 */  addiu      $3, $23, %lo(D_0073A78C)
  .L004EBE94:
    /* 3EBE94 004EBE94 0000628C */  lw         $2, 0x0($3)
    /* 3EBE98 004EBE98 01004224 */  addiu      $2, $2, 0x1
    /* 3EBE9C 004EBE9C 000062AC */  sw         $2, 0x0($3)
    /* 3EBEA0 004EBEA0 1000B0DF */  ld         $16, 0x10($29)
  .L004EBEA4:
    /* 3EBEA4 004EBEA4 1800B1DF */  ld         $17, 0x18($29)
    /* 3EBEA8 004EBEA8 2000B2DF */  ld         $18, 0x20($29)
    /* 3EBEAC 004EBEAC 2800B3DF */  ld         $19, 0x28($29)
    /* 3EBEB0 004EBEB0 3000B4DF */  ld         $20, 0x30($29)
    /* 3EBEB4 004EBEB4 3800B5DF */  ld         $21, 0x38($29)
    /* 3EBEB8 004EBEB8 4000B6DF */  ld         $22, 0x40($29)
    /* 3EBEBC 004EBEBC 4800B7DF */  ld         $23, 0x48($29)
    /* 3EBEC0 004EBEC0 5000BFDF */  ld         $31, 0x50($29)
    /* 3EBEC4 004EBEC4 0800E003 */  jr         $31
    /* 3EBEC8 004EBEC8 6000BD27 */   addiu     $29, $29, 0x60
    /* 3EBECC 004EBECC 00000000 */  nop
.size func_004ebc00, 0x2d0
