.section .text
.set noat
.set noreorder
glabel func_004db460
    /* 3DB460 004DB460 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 3DB464 004DB464 0000B0FF */  sd         $16, 0x0($29)
    /* 3DB468 004DB468 1000B2FF */  sd         $18, 0x10($29)
    /* 3DB46C 004DB46C 0800B1FF */  sd         $17, 0x8($29)
    /* 3DB470 004DB470 1800BFFF */  sd         $31, 0x18($29)
    /* 3DB474 004DB474 7432130C */  jal        func_004cc9d0
    /* 3DB478 004DB478 2D808000 */   daddu     $16, $4, $0
    /* 3DB47C 004DB47C B400128E */  lw         $18, 0xB4($16)
    /* 3DB480 004DB480 2277130C */  jal        func_004ddc88
    /* 3DB484 004DB484 2D204002 */   daddu     $4, $18, $0
    /* 3DB488 004DB488 06004054 */  bnel       $2, $0, .L004DB4A4
    /* 3DB48C 004DB48C 0400038E */   lw        $3, 0x4($16)
    /* 3DB490 004DB490 900000AE */  sw         $0, 0x90($16)
    /* 3DB494 004DB494 2D204002 */  daddu      $4, $18, $0
    /* 3DB498 004DB498 4477130C */  jal        func_004ddd10
    /* 3DB49C 004DB49C 880000AE */   sw        $0, 0x88($16)
    /* 3DB4A0 004DB4A0 0400038E */  lw         $3, 0x4($16)
  .L004DB4A4:
    /* 3DB4A4 004DB4A4 01000224 */  addiu      $2, $0, 0x1
    /* 3DB4A8 004DB4A8 07006254 */  bnel       $3, $2, .L004DB4C8
    /* 3DB4AC 004DB4AC 02000224 */   addiu     $2, $0, 0x2
    /* 3DB4B0 004DB4B0 880000AE */  sw         $0, 0x88($16)
    /* 3DB4B4 004DB4B4 2E77130C */  jal        func_004ddcb8
    /* 3DB4B8 004DB4B8 2D204002 */   daddu     $4, $18, $0
    /* 3DB4BC 004DB4BC 02000224 */  addiu      $2, $0, 0x2
    /* 3DB4C0 004DB4C0 1F000010 */  b          .L004DB540
    /* 3DB4C4 004DB4C4 040002AE */   sw        $2, 0x4($16)
  .L004DB4C8:
    /* 3DB4C8 004DB4C8 1E006254 */  bnel       $3, $2, .L004DB544
    /* 3DB4CC 004DB4CC 0000B0DF */   ld        $16, 0x0($29)
    /* 3DB4D0 004DB4D0 BC00028E */  lw         $2, 0xBC($16)
    /* 3DB4D4 004DB4D4 08004018 */  blez       $2, .L004DB4F8
    /* 3DB4D8 004DB4D8 2D880000 */   daddu     $17, $0, $0
    /* 3DB4DC 004DB4DC 2D204002 */  daddu      $4, $18, $0
  .L004DB4E0:
    /* 3DB4E0 004DB4E0 1278130C */  jal        func_004de048
    /* 3DB4E4 004DB4E4 01003126 */   addiu     $17, $17, 0x1
    /* 3DB4E8 004DB4E8 BC00028E */  lw         $2, 0xBC($16)
    /* 3DB4EC 004DB4EC 2A102202 */  slt        $2, $17, $2
    /* 3DB4F0 004DB4F0 FBFF4054 */  bnel       $2, $0, .L004DB4E0
    /* 3DB4F4 004DB4F4 2D204002 */   daddu     $4, $18, $0
  .L004DB4F8:
    /* 3DB4F8 004DB4F8 3E78130C */  jal        func_004de0f8
    /* 3DB4FC 004DB4FC 2D204002 */   daddu     $4, $18, $0
    /* 3DB500 004DB500 8800038E */  lw         $3, 0x88($16)
    /* 3DB504 004DB504 2D204002 */  daddu      $4, $18, $0
    /* 3DB508 004DB508 23104300 */  subu       $2, $2, $3
    /* 3DB50C 004DB50C 21186200 */  addu       $3, $3, $2
    /* 3DB510 004DB510 900002AE */  sw         $2, 0x90($16)
    /* 3DB514 004DB514 3C78130C */  jal        func_004de0f0
    /* 3DB518 004DB518 880003AE */   sw        $3, 0x88($16)
    /* 3DB51C 004DB51C 2D204002 */  daddu      $4, $18, $0
    /* 3DB520 004DB520 2277130C */  jal        func_004ddc88
    /* 3DB524 004DB524 940002AE */   sw        $2, 0x94($16)
    /* 3DB528 004DB528 03000324 */  addiu      $3, $0, 0x3
    /* 3DB52C 004DB52C 05004354 */  bnel       $2, $3, .L004DB544
    /* 3DB530 004DB530 0000B0DF */   ld        $16, 0x0($29)
    /* 3DB534 004DB534 4477130C */  jal        func_004ddd10
    /* 3DB538 004DB538 2D204002 */   daddu     $4, $18, $0
    /* 3DB53C 004DB53C 040000AE */  sw         $0, 0x4($16)
  .L004DB540:
    /* 3DB540 004DB540 0000B0DF */  ld         $16, 0x0($29)
  .L004DB544:
    /* 3DB544 004DB544 0800B1DF */  ld         $17, 0x8($29)
    /* 3DB548 004DB548 1000B2DF */  ld         $18, 0x10($29)
    /* 3DB54C 004DB54C 1800BFDF */  ld         $31, 0x18($29)
    /* 3DB550 004DB550 7A321308 */  j          func_004cc9e8
    /* 3DB554 004DB554 2000BD27 */   addiu     $29, $29, 0x20
.size func_004db460, 0xf8
