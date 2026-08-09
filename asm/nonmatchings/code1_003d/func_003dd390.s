.section .text
.set noat
.set noreorder
glabel func_003dd390
    /* 2DD390 003DD390 C0FFBD27 */  addiu      $29, $29, -0x40
    /* 2DD394 003DD394 3000BFFF */  sd         $31, 0x30($29)
    /* 2DD398 003DD398 2000B27F */  sq         $18, 0x20($29)
    /* 2DD39C 003DD39C 1000B17F */  sq         $17, 0x10($29)
    /* 2DD3A0 003DD3A0 2D908000 */  daddu      $18, $4, $0
    /* 2DD3A4 003DD3A4 0000B07F */  sq         $16, 0x0($29)
    /* 2DD3A8 003DD3A8 8800103C */  lui        $16, %hi(D_008873D4)
    /* 2DD3AC 003DD3AC D4731026 */  addiu      $16, $16, %lo(D_008873D4)
    /* 2DD3B0 003DD3B0 0000028E */  lw         $2, 0x0($16)
    /* 2DD3B4 003DD3B4 09F84000 */  jalr       $2
    /* 2DD3B8 003DD3B8 2D880000 */   daddu     $17, $0, $0
    /* 2DD3BC 003DD3BC 2A080200 */  slt        $1, $0, $2
    /* 2DD3C0 003DD3C0 11002010 */  beqz       $1, .L003DD408
    /* 2DD3C4 003DD3C4 00000000 */   nop
  .L003DD3C8:
    /* 2DD3C8 003DD3C8 21185102 */  addu       $3, $18, $17
    /* 2DD3CC 003DD3CC 3A000224 */  addiu      $2, $0, 0x3A
    /* 2DD3D0 003DD3D0 00006380 */  lb         $3, 0x0($3)
    /* 2DD3D4 003DD3D4 04006214 */  bne        $3, $2, .L003DD3E8
    /* 2DD3D8 003DD3D8 00000000 */   nop
    /* 2DD3DC 003DD3DC 01002226 */  addiu      $2, $17, 0x1
    /* 2DD3E0 003DD3E0 09000010 */  b          .L003DD408
    /* 2DD3E4 003DD3E4 21904202 */   addu      $18, $18, $2
  .L003DD3E8:
    /* 2DD3E8 003DD3E8 0000028E */  lw         $2, 0x0($16)
    /* 2DD3EC 003DD3EC 2D204002 */  daddu      $4, $18, $0
    /* 2DD3F0 003DD3F0 09F84000 */  jalr       $2
    /* 2DD3F4 003DD3F4 01003126 */   addiu     $17, $17, 0x1
    /* 2DD3F8 003DD3F8 2A102202 */  slt        $2, $17, $2
    /* 2DD3FC 003DD3FC F2FF4014 */  bnez       $2, .L003DD3C8
    /* 2DD400 003DD400 00000000 */   nop
    /* 2DD404 003DD404 00000000 */  nop
  .L003DD408:
    /* 2DD408 003DD408 2D104002 */  daddu      $2, $18, $0
    /* 2DD40C 003DD40C 3000BFDF */  ld         $31, 0x30($29)
    /* 2DD410 003DD410 2000B27B */  lq         $18, 0x20($29)
    /* 2DD414 003DD414 1000B17B */  lq         $17, 0x10($29)
    /* 2DD418 003DD418 0000B07B */  lq         $16, 0x0($29)
    /* 2DD41C 003DD41C 0800E003 */  jr         $31
    /* 2DD420 003DD420 4000BD27 */   addiu     $29, $29, 0x40
    /* 2DD424 003DD424 00000000 */  nop
    /* 2DD428 003DD428 00000000 */  nop
    /* 2DD42C 003DD42C 00000000 */  nop
.size func_003dd390, 0xa0
