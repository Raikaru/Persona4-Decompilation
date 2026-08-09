.section .text
.set noat
.set noreorder
glabel func_004bf350
    /* 3BF350 004BF350 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 3BF354 004BF354 0000B0FF */  sd         $16, 0x0($29)
    /* 3BF358 004BF358 2D808000 */  daddu      $16, $4, $0
    /* 3BF35C 004BF35C 0800B1FF */  sd         $17, 0x8($29)
    /* 3BF360 004BF360 1000B2FF */  sd         $18, 0x10($29)
    /* 3BF364 004BF364 1800BFFF */  sd         $31, 0x18($29)
    /* 3BF368 004BF368 5000028E */  lw         $2, 0x50($16)
    /* 3BF36C 004BF36C 0A004054 */  bnel       $2, $0, .L004BF398
    /* 3BF370 004BF370 9800028E */   lw        $2, 0x98($16)
    /* 3BF374 004BF374 7500043C */  lui        $4, %hi(D_00757040)
    /* 3BF378 004BF378 0000B0DF */  ld         $16, 0x0($29)
    /* 3BF37C 004BF37C 0800B1DF */  ld         $17, 0x8($29)
    /* 3BF380 004BF380 40708424 */  addiu      $4, $4, %lo(D_00757040)
    /* 3BF384 004BF384 1000B2DF */  ld         $18, 0x10($29)
    /* 3BF388 004BF388 1800BFDF */  ld         $31, 0x18($29)
    /* 3BF38C 004BF38C A8F51208 */  j          func_004bd6a0
    /* 3BF390 004BF390 2000BD27 */   addiu     $29, $29, 0x20
    /* 3BF394 004BF394 00000000 */  nop
  .L004BF398:
    /* 3BF398 004BF398 09004054 */  bnel       $2, $0, .L004BF3C0
    /* 3BF39C 004BF39C A000028E */   lw        $2, 0xA0($16)
    /* 3BF3A0 004BF3A0 7500043C */  lui        $4, %hi(D_00757070)
    /* 3BF3A4 004BF3A4 0000B0DF */  ld         $16, 0x0($29)
    /* 3BF3A8 004BF3A8 0800B1DF */  ld         $17, 0x8($29)
    /* 3BF3AC 004BF3AC 70708424 */  addiu      $4, $4, %lo(D_00757070)
    /* 3BF3B0 004BF3B0 1000B2DF */  ld         $18, 0x10($29)
    /* 3BF3B4 004BF3B4 1800BFDF */  ld         $31, 0x18($29)
    /* 3BF3B8 004BF3B8 A8F51208 */  j          func_004bd6a0
    /* 3BF3BC 004BF3BC 2000BD27 */   addiu     $29, $29, 0x20
  .L004BF3C0:
    /* 3BF3C0 004BF3C0 16004018 */  blez       $2, .L004BF41C
    /* 3BF3C4 004BF3C4 2D880000 */   daddu     $17, $0, $0
    /* 3BF3C8 004BF3C8 01001224 */  addiu      $18, $0, 0x1
    /* 3BF3CC 004BF3CC 9400028E */  lw         $2, 0x94($16)
  .L004BF3D0:
    /* 3BF3D0 004BF3D0 09005254 */  bnel       $2, $18, .L004BF3F8
    /* 3BF3D4 004BF3D4 2D200002 */   daddu     $4, $16, $0
    /* 3BF3D8 004BF3D8 2D282002 */  daddu      $5, $17, $0
    /* 3BF3DC 004BF3DC AAFD120C */  jal        func_004bf6a8
    /* 3BF3E0 004BF3E0 2D200002 */   daddu     $4, $16, $0
    /* 3BF3E4 004BF3E4 2D280000 */  daddu      $5, $0, $0
    /* 3BF3E8 004BF3E8 B07B130C */  jal        func_004deec0
    /* 3BF3EC 004BF3EC 2D204000 */   daddu     $4, $2, $0
    /* 3BF3F0 004BF3F0 04000010 */  b          .L004BF404
    /* 3BF3F4 004BF3F4 2D204000 */   daddu     $4, $2, $0
  .L004BF3F8:
    /* 3BF3F8 004BF3F8 44FD120C */  jal        func_004bf510
    /* 3BF3FC 004BF3FC 2D282002 */   daddu     $5, $17, $0
    /* 3BF400 004BF400 2D204000 */  daddu      $4, $2, $0
  .L004BF404:
    /* 3BF404 004BF404 E66C130C */  jal        func_004db398
    /* 3BF408 004BF408 01003126 */   addiu     $17, $17, 0x1
    /* 3BF40C 004BF40C A000028E */  lw         $2, 0xA0($16)
    /* 3BF410 004BF410 2A102202 */  slt        $2, $17, $2
    /* 3BF414 004BF414 EEFF4054 */  bnel       $2, $0, .L004BF3D0
    /* 3BF418 004BF418 9400028E */   lw        $2, 0x94($16)
  .L004BF41C:
    /* 3BF41C 004BF41C 0000B0DF */  ld         $16, 0x0($29)
    /* 3BF420 004BF420 0800B1DF */  ld         $17, 0x8($29)
    /* 3BF424 004BF424 1000B2DF */  ld         $18, 0x10($29)
    /* 3BF428 004BF428 1800BFDF */  ld         $31, 0x18($29)
    /* 3BF42C 004BF42C 0800E003 */  jr         $31
    /* 3BF430 004BF430 2000BD27 */   addiu     $29, $29, 0x20
    /* 3BF434 004BF434 00000000 */  nop
.size func_004bf350, 0xe8
