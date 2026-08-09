.section .text
.set noat
.set noreorder
glabel func_004eb318
    /* 3EB318 004EB318 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3EB31C 004EB31C 2D508000 */  daddu      $10, $4, $0
    /* 3EB320 004EB320 0000BFFF */  sd         $31, 0x0($29)
    /* 3EB324 004EB324 08004105 */  bgez       $10, .L004EB348
    /* 3EB328 004EB328 2D58A000 */   daddu     $11, $5, $0
    /* 3EB32C 004EB32C 7600043C */  lui        $4, %hi(D_0075C6B8)
    /* 3EB330 004EB330 0000BFDF */  ld         $31, 0x0($29)
    /* 3EB334 004EB334 2D284001 */  daddu      $5, $10, $0
    /* 3EB338 004EB338 B8C68424 */  addiu      $4, $4, %lo(D_0075C6B8)
    /* 3EB33C 004EB33C FC341308 */  j          func_004cd3f0
    /* 3EB340 004EB340 1000BD27 */   addiu     $29, $29, 0x10
    /* 3EB344 004EB344 00000000 */  nop
  .L004EB348:
    /* 3EB348 004EB348 07006105 */  bgez       $11, .L004EB368
    /* 3EB34C 004EB34C 40100A00 */   sll       $2, $10, 1
    /* 3EB350 004EB350 7600043C */  lui        $4, %hi(D_0075C6E8)
    /* 3EB354 004EB354 0000BFDF */  ld         $31, 0x0($29)
    /* 3EB358 004EB358 E8C68424 */  addiu      $4, $4, %lo(D_0075C6E8)
    /* 3EB35C 004EB35C FC341308 */  j          func_004cd3f0
    /* 3EB360 004EB360 1000BD27 */   addiu     $29, $29, 0x10
    /* 3EB364 004EB364 00000000 */  nop
  .L004EB368:
    /* 3EB368 004EB368 21484B00 */  addu       $9, $2, $11
    /* 3EB36C 004EB36C 80190900 */  sll        $3, $9, 6
    /* 3EB370 004EB370 21002229 */  slti       $2, $9, 0x21
    /* 3EB374 004EB374 08004014 */  bnez       $2, .L004EB398
    /* 3EB378 004EB378 21186900 */   addu      $3, $3, $9
    /* 3EB37C 004EB37C 7600043C */  lui        $4, %hi(D_0075C718)
    /* 3EB380 004EB380 0000BFDF */  ld         $31, 0x0($29)
    /* 3EB384 004EB384 20000524 */  addiu      $5, $0, 0x20
    /* 3EB388 004EB388 18C78424 */  addiu      $4, $4, %lo(D_0075C718)
    /* 3EB38C 004EB38C FC341308 */  j          func_004cd3f0
    /* 3EB390 004EB390 1000BD27 */   addiu     $29, $29, 0x10
    /* 3EB394 004EB394 00000000 */  nop
  .L004EB398:
    /* 3EB398 004EB398 0000BFDF */  ld         $31, 0x0($29)
    /* 3EB39C 004EB39C 003A0300 */  sll        $7, $3, 8
    /* 3EB3A0 004EB3A0 7400083C */  lui        $8, %hi(D_0073A740)
    /* 3EB3A4 004EB3A4 7400043C */  lui        $4, %hi(D_0073A76C)
    /* 3EB3A8 004EB3A8 7400033C */  lui        $3, %hi(D_0073A768)
    /* 3EB3AC 004EB3AC 7400053C */  lui        $5, %hi(D_0073A744)
    /* 3EB3B0 004EB3B0 7400063C */  lui        $6, %hi(D_0073A748)
    /* 3EB3B4 004EB3B4 01000224 */  addiu      $2, $0, 0x1
    /* 3EB3B8 004EB3B8 68A76AAC */  sw         $10, %lo(D_0073A768)($3)
    /* 3EB3BC 004EB3BC 6CA78BAC */  sw         $11, %lo(D_0073A76C)($4)
    /* 3EB3C0 004EB3C0 44A7A7AC */  sw         $7, %lo(D_0073A744)($5)
    /* 3EB3C4 004EB3C4 48A7C2AC */  sw         $2, %lo(D_0073A748)($6)
    /* 3EB3C8 004EB3C8 40A709AD */  sw         $9, %lo(D_0073A740)($8)
    /* 3EB3CC 004EB3CC 0800E003 */  jr         $31
    /* 3EB3D0 004EB3D0 1000BD27 */   addiu     $29, $29, 0x10
    /* 3EB3D4 004EB3D4 00000000 */  nop
.size func_004eb318, 0xc0
