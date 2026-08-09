.section .text
.set noat
.set noreorder
glabel func_003ef3a0
    /* 2EF3A0 003EF3A0 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 2EF3A4 003EF3A4 01000224 */  addiu      $2, $0, 0x1
    /* 2EF3A8 003EF3A8 1000BFFF */  sd         $31, 0x10($29)
    /* 2EF3AC 003EF3AC 0000B07F */  sq         $16, 0x0($29)
    /* 2EF3B0 003EF3B0 5400838C */  lw         $3, 0x54($4)
    /* 2EF3B4 003EF3B4 FFFF6324 */  addiu      $3, $3, -0x1
    /* 2EF3B8 003EF3B8 540083AC */  sw         $3, 0x54($4)
    /* 2EF3BC 003EF3BC 5400838C */  lw         $3, 0x54($4)
    /* 2EF3C0 003EF3C0 03006018 */  blez       $3, .L003EF3D0
    /* 2EF3C4 003EF3C4 2D808000 */   daddu     $16, $4, $0
  .L003EF3C8:
    /* 2EF3C8 003EF3C8 25000010 */  b          .L003EF460
    /* 2EF3CC 003EF3CC 1000BFDF */   ld        $31, 0x10($29)
  .L003EF3D0:
    /* 2EF3D0 003EF3D0 01006224 */  addiu      $2, $3, 0x1
    /* 2EF3D4 003EF3D4 7100043C */  lui        $4, %hi(D_0070B800)
    /* 2EF3D8 003EF3D8 00B88424 */  addiu      $4, $4, %lo(D_0070B800)
    /* 2EF3DC 003EF3DC 540002AE */  sw         $2, 0x54($16)
    /* 2EF3E0 003EF3E0 088F0F0C */  jal        func_003e3c20
    /* 2EF3E4 003EF3E4 2D280002 */   daddu     $5, $16, $0
    /* 2EF3E8 003EF3E8 0400028E */  lw         $2, 0x4($16)
    /* 2EF3EC 003EF3EC 15004014 */  bnez       $2, .L003EF444
    /* 2EF3F0 003EF3F0 00000000 */   nop
  .L003EF3F4:
    /* 2EF3F4 003EF3F4 0000048E */  lw         $4, 0x0($16)
    /* 2EF3F8 003EF3F8 04008010 */  beqz       $4, .L003EF40C
    /* 2EF3FC 003EF3FC 00000000 */   nop
    /* 2EF400 003EF400 CCB00F0C */  jal        func_003ec330
    /* 2EF404 003EF404 00000000 */   nop
    /* 2EF408 003EF408 000000AE */  sw         $0, 0x0($16)
  .L003EF40C:
    /* 2EF40C 003EF40C 5400048E */  lw         $4, 0x54($16)
    /* 2EF410 003EF410 8800033C */  lui        $3, %hi(D_008872E0)
    /* 2EF414 003EF414 E0726324 */  addiu      $3, $3, %lo(D_008872E0)
    /* 2EF418 003EF418 8800023C */  lui        $2, %hi(jtbl_008873FC)
    /* 2EF41C 003EF41C FFFF8424 */  addiu      $4, $4, -0x1
    /* 2EF420 003EF420 540004AE */  sw         $4, 0x54($16)
    /* 2EF424 003EF424 E0B7848F */  lw         $4, -0x4820($28)
    /* 2EF428 003EF428 FC73428C */  lw         $2, %lo(jtbl_008873FC)($2)
    /* 2EF42C 003EF42C 21186400 */  addu       $3, $3, $4
    /* 2EF430 003EF430 0800648C */  lw         $4, 0x8($3)
    /* 2EF434 003EF434 09F84000 */  jalr       $2
    /* 2EF438 003EF438 2D280002 */   daddu     $5, $16, $0
    /* 2EF43C 003EF43C E2FF0010 */  b          .L003EF3C8
    /* 2EF440 003EF440 01000224 */   addiu     $2, $0, 0x1
  .L003EF444:
    /* 2EF444 003EF444 0800038E */  lw         $3, 0x8($16)
    /* 2EF448 003EF448 0C00028E */  lw         $2, 0xC($16)
    /* 2EF44C 003EF44C 000043AC */  sw         $3, 0x0($2)
    /* 2EF450 003EF450 0C00038E */  lw         $3, 0xC($16)
    /* 2EF454 003EF454 0800028E */  lw         $2, 0x8($16)
    /* 2EF458 003EF458 E6FF0010 */  b          .L003EF3F4
    /* 2EF45C 003EF45C 040043AC */   sw        $3, 0x4($2)
  .L003EF460:
    /* 2EF460 003EF460 0000B07B */  lq         $16, 0x0($29)
    /* 2EF464 003EF464 0800E003 */  jr         $31
    /* 2EF468 003EF468 2000BD27 */   addiu     $29, $29, 0x20
    /* 2EF46C 003EF46C 00000000 */  nop
.size func_003ef3a0, 0xd0
