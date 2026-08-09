.section .text
.set noat
.set noreorder
glabel func_003df3c0
    /* 2DF3C0 003DF3C0 C0FFBD27 */  addiu      $29, $29, -0x40
    /* 2DF3C4 003DF3C4 2000BFFF */  sd         $31, 0x20($29)
    /* 2DF3C8 003DF3C8 3800A627 */  addiu      $6, $29, 0x38
    /* 2DF3CC 003DF3CC 1000B17F */  sq         $17, 0x10($29)
    /* 2DF3D0 003DF3D0 3400A727 */  addiu      $7, $29, 0x34
    /* 2DF3D4 003DF3D4 0000B07F */  sq         $16, 0x0($29)
    /* 2DF3D8 003DF3D8 2D888000 */  daddu      $17, $4, $0
    /* 2DF3DC 003DF3DC 2D80A000 */  daddu      $16, $5, $0
    /* 2DF3E0 003DF3E0 3000A827 */  addiu      $8, $29, 0x30
    /* 2DF3E4 003DF3E4 A87B0F0C */  jal        func_003deea0
    /* 2DF3E8 003DF3E8 3C00A527 */   addiu     $5, $29, 0x3C
    /* 2DF3EC 003DF3EC 03004014 */  bnez       $2, .L003DF3FC
    /* 2DF3F0 003DF3F0 00000000 */   nop
    /* 2DF3F4 003DF3F4 0D000010 */  b          .L003DF42C
    /* 2DF3F8 003DF3F8 2D100000 */   daddu     $2, $0, $0
  .L003DF3FC:
    /* 2DF3FC 003DF3FC 3C00A28F */  lw         $2, 0x3C($29)
    /* 2DF400 003DF400 2D200002 */  daddu      $4, $16, $0
    /* 2DF404 003DF404 000002AE */  sw         $2, 0x0($16)
    /* 2DF408 003DF408 3800A28F */  lw         $2, 0x38($29)
    /* 2DF40C 003DF40C 040002AE */  sw         $2, 0x4($16)
    /* 2DF410 003DF410 3400A28F */  lw         $2, 0x34($29)
    /* 2DF414 003DF414 080002AE */  sw         $2, 0x8($16)
    /* 2DF418 003DF418 3000A28F */  lw         $2, 0x30($29)
    /* 2DF41C 003DF41C 487B0F0C */  jal        func_003ded20
    /* 2DF420 003DF420 0C0002AE */   sw        $2, 0xC($16)
    /* 2DF424 003DF424 100002AE */  sw         $2, 0x10($16)
    /* 2DF428 003DF428 2D102002 */  daddu      $2, $17, $0
  .L003DF42C:
    /* 2DF42C 003DF42C 2000BFDF */  ld         $31, 0x20($29)
    /* 2DF430 003DF430 1000B17B */  lq         $17, 0x10($29)
    /* 2DF434 003DF434 0000B07B */  lq         $16, 0x0($29)
    /* 2DF438 003DF438 0800E003 */  jr         $31
    /* 2DF43C 003DF43C 4000BD27 */   addiu     $29, $29, 0x40
.size func_003df3c0, 0x80
