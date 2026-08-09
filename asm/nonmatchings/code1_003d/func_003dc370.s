.section .text
.set noat
.set noreorder
glabel func_003dc370
    /* 2DC370 003DC370 B0FFBD27 */  addiu      $29, $29, -0x50
    /* 2DC374 003DC374 04000624 */  addiu      $6, $0, 0x4
    /* 2DC378 003DC378 3000BFFF */  sd         $31, 0x30($29)
    /* 2DC37C 003DC37C 4800A527 */  addiu      $5, $29, 0x48
    /* 2DC380 003DC380 2000B27F */  sq         $18, 0x20($29)
    /* 2DC384 003DC384 1000B17F */  sq         $17, 0x10($29)
    /* 2DC388 003DC388 0000B07F */  sq         $16, 0x0($29)
    /* 2DC38C 003DC38C 448A0F0C */  jal        func_003e2910
    /* 2DC390 003DC390 2D808000 */   daddu     $16, $4, $0
    /* 2DC394 003DC394 0400412C */  sltiu      $1, $2, 0x4
    /* 2DC398 003DC398 03002010 */  beqz       $1, .L003DC3A8
    /* 2DC39C 003DC39C 00000000 */   nop
    /* 2DC3A0 003DC3A0 33000010 */  b          .L003DC470
    /* 2DC3A4 003DC3A4 2D100000 */   daddu     $2, $0, $0
  .L003DC3A8:
    /* 2DC3A8 003DC3A8 34BC0F0C */  jal        func_003ef0d0
    /* 2DC3AC 003DC3AC 00000000 */   nop
    /* 2DC3B0 003DC3B0 13004010 */  beqz       $2, .L003DC400
    /* 2DC3B4 003DC3B4 4C00A2AF */   sw        $2, 0x4C($29)
    /* 2DC3B8 003DC3B8 4A00A297 */  lhu        $2, 0x4A($29)
    /* 2DC3BC 003DC3BC 1200401C */  bgtz       $2, .L003DC408
    /* 2DC3C0 003DC3C0 00000000 */   nop
    /* 2DC3C4 003DC3C4 4800A297 */  lhu        $2, 0x48($29)
    /* 2DC3C8 003DC3C8 2B080200 */  sltu       $1, $0, $2
    /* 2DC3CC 003DC3CC 0A002010 */  beqz       $1, .L003DC3F8
    /* 2DC3D0 003DC3D0 2D880000 */   daddu     $17, $0, $0
  .L003DC3D4:
    /* 2DC3D4 003DC3D4 2D200002 */  daddu      $4, $16, $0
    /* 2DC3D8 003DC3D8 8C6D0F0C */  jal        func_003db630
    /* 2DC3DC 003DC3DC 4C00A527 */   addiu     $5, $29, 0x4C
    /* 2DC3E0 003DC3E0 4800A297 */  lhu        $2, 0x48($29)
    /* 2DC3E4 003DC3E4 01003126 */  addiu      $17, $17, 0x1
    /* 2DC3E8 003DC3E8 2B102202 */  sltu       $2, $17, $2
    /* 2DC3EC 003DC3EC F9FF4014 */  bnez       $2, .L003DC3D4
    /* 2DC3F0 003DC3F0 00000000 */   nop
    /* 2DC3F4 003DC3F4 00000000 */  nop
  .L003DC3F8:
    /* 2DC3F8 003DC3F8 1D000010 */  b          .L003DC470
    /* 2DC3FC 003DC3FC 4C00A28F */   lw        $2, 0x4C($29)
  .L003DC400:
    /* 2DC400 003DC400 1B000010 */  b          .L003DC470
    /* 2DC404 003DC404 2D100000 */   daddu     $2, $0, $0
  .L003DC408:
    /* 2DC408 003DC408 B4BD0F0C */  jal        func_003ef6d0
    /* 2DC40C 003DC40C 00000000 */   nop
    /* 2DC410 003DC410 4C00A48F */  lw         $4, 0x4C($29)
    /* 2DC414 003DC414 ACBD0F0C */  jal        func_003ef6b0
    /* 2DC418 003DC418 2D904000 */   daddu     $18, $2, $0
    /* 2DC41C 003DC41C 4800A297 */  lhu        $2, 0x48($29)
    /* 2DC420 003DC420 2B080200 */  sltu       $1, $0, $2
    /* 2DC424 003DC424 0E002010 */  beqz       $1, .L003DC460
    /* 2DC428 003DC428 2D880000 */   daddu     $17, $0, $0
  .L003DC42C:
    /* 2DC42C 003DC42C 906F0F0C */  jal        func_003dbe40
    /* 2DC430 003DC430 2D200002 */   daddu     $4, $16, $0
    /* 2DC434 003DC434 05004014 */  bnez       $2, .L003DC44C
    /* 2DC438 003DC438 00000000 */   nop
    /* 2DC43C 003DC43C ACBD0F0C */  jal        func_003ef6b0
    /* 2DC440 003DC440 2D204002 */   daddu     $4, $18, $0
    /* 2DC444 003DC444 0A000010 */  b          .L003DC470
    /* 2DC448 003DC448 2D100000 */   daddu     $2, $0, $0
  .L003DC44C:
    /* 2DC44C 003DC44C 4800A297 */  lhu        $2, 0x48($29)
    /* 2DC450 003DC450 01003126 */  addiu      $17, $17, 0x1
    /* 2DC454 003DC454 2B102202 */  sltu       $2, $17, $2
    /* 2DC458 003DC458 F4FF4014 */  bnez       $2, .L003DC42C
    /* 2DC45C 003DC45C 00000000 */   nop
  .L003DC460:
    /* 2DC460 003DC460 ACBD0F0C */  jal        func_003ef6b0
    /* 2DC464 003DC464 2D204002 */   daddu     $4, $18, $0
    /* 2DC468 003DC468 E3FF0010 */  b          .L003DC3F8
    /* 2DC46C 003DC46C 00000000 */   nop
  .L003DC470:
    /* 2DC470 003DC470 3000BFDF */  ld         $31, 0x30($29)
    /* 2DC474 003DC474 2000B27B */  lq         $18, 0x20($29)
    /* 2DC478 003DC478 1000B17B */  lq         $17, 0x10($29)
    /* 2DC47C 003DC47C 0000B07B */  lq         $16, 0x0($29)
    /* 2DC480 003DC480 0800E003 */  jr         $31
    /* 2DC484 003DC484 5000BD27 */   addiu     $29, $29, 0x50
    /* 2DC488 003DC488 00000000 */  nop
    /* 2DC48C 003DC48C 00000000 */  nop
.size func_003dc370, 0x120
