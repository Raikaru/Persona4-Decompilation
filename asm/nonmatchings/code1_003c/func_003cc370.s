.section .text
.set noat
.set noreorder
glabel func_003cc370
    /* 2CC370 003CC370 A0FFBD27 */  addiu      $29, $29, -0x60
    /* 2CC374 003CC374 5000BFFF */  sd         $31, 0x50($29)
    /* 2CC378 003CC378 4000B47F */  sq         $20, 0x40($29)
    /* 2CC37C 003CC37C 3000B37F */  sq         $19, 0x30($29)
    /* 2CC380 003CC380 2000B27F */  sq         $18, 0x20($29)
    /* 2CC384 003CC384 1000B17F */  sq         $17, 0x10($29)
    /* 2CC388 003CC388 B0300F0C */  jal        func_003cc2c0
    /* 2CC38C 003CC38C 0000B07F */   sq        $16, 0x0($29)
    /* 2CC390 003CC390 2DA04000 */  daddu      $20, $2, $0
    /* 2CC394 003CC394 B86D0E0C */  jal        func_0039b6e0
    /* 2CC398 003CC398 04000424 */   addiu     $4, $0, 0x4
    /* 2CC39C 003CC39C 2D884000 */  daddu      $17, $2, $0
    /* 2CC3A0 003CC3A0 B86D0E0C */  jal        func_0039b6e0
    /* 2CC3A4 003CC3A4 06000424 */   addiu     $4, $0, 0x6
    /* 2CC3A8 003CC3A8 2D984000 */  daddu      $19, $2, $0
    /* 2CC3AC 003CC3AC B86D0E0C */  jal        func_0039b6e0
    /* 2CC3B0 003CC3B0 05000424 */   addiu     $4, $0, 0x5
    /* 2CC3B4 003CC3B4 2D804000 */  daddu      $16, $2, $0
    /* 2CC3B8 003CC3B8 B86D0E0C */  jal        func_0039b6e0
    /* 2CC3BC 003CC3BC 07000424 */   addiu     $4, $0, 0x7
    /* 2CC3C0 003CC3C0 B0B9838F */  lw         $3, -0x4650($28)
    /* 2CC3C4 003CC3C4 2D904000 */  daddu      $18, $2, $0
    /* 2CC3C8 003CC3C8 8800023C */  lui        $2, %hi(D_008872E0)
    /* 2CC3CC 003CC3CC 2D208002 */  daddu      $4, $20, $0
    /* 2CC3D0 003CC3D0 E0724224 */  addiu      $2, $2, %lo(D_008872E0)
    /* 2CC3D4 003CC3D4 21104300 */  addu       $2, $2, $3
    /* 2CC3D8 003CC3D8 1C0054AC */  sw         $20, 0x1C($2)
    /* 2CC3DC 003CC3DC 200053AC */  sw         $19, 0x20($2)
    /* 2CC3E0 003CC3E0 240053AC */  sw         $19, 0x24($2)
    /* 2CC3E4 003CC3E4 280053AC */  sw         $19, 0x28($2)
    /* 2CC3E8 003CC3E8 2C0052AC */  sw         $18, 0x2C($2)
    /* 2CC3EC 003CC3EC 300052AC */  sw         $18, 0x30($2)
    /* 2CC3F0 003CC3F0 380051AC */  sw         $17, 0x38($2)
    /* 2CC3F4 003CC3F4 9042100C */  jal        func_00410a40
    /* 2CC3F8 003CC3F8 3C0050AC */   sw        $16, 0x3C($2)
    /* 2CC3FC 003CC3FC 2D206002 */  daddu      $4, $19, $0
    /* 2CC400 003CC400 AC42100C */  jal        func_00410ab0
    /* 2CC404 003CC404 03000524 */   addiu     $5, $0, 0x3
    /* 2CC408 003CC408 2D206002 */  daddu      $4, $19, $0
    /* 2CC40C 003CC40C AC42100C */  jal        func_00410ab0
    /* 2CC410 003CC410 05000524 */   addiu     $5, $0, 0x5
    /* 2CC414 003CC414 2D206002 */  daddu      $4, $19, $0
    /* 2CC418 003CC418 AC42100C */  jal        func_00410ab0
    /* 2CC41C 003CC41C 04000524 */   addiu     $5, $0, 0x4
    /* 2CC420 003CC420 2D204002 */  daddu      $4, $18, $0
    /* 2CC424 003CC424 AC42100C */  jal        func_00410ab0
    /* 2CC428 003CC428 01000524 */   addiu     $5, $0, 0x1
    /* 2CC42C 003CC42C 2D204002 */  daddu      $4, $18, $0
    /* 2CC430 003CC430 AC42100C */  jal        func_00410ab0
    /* 2CC434 003CC434 02000524 */   addiu     $5, $0, 0x2
    /* 2CC438 003CC438 5000BFDF */  ld         $31, 0x50($29)
    /* 2CC43C 003CC43C 01000224 */  addiu      $2, $0, 0x1
    /* 2CC440 003CC440 4000B47B */  lq         $20, 0x40($29)
    /* 2CC444 003CC444 3000B37B */  lq         $19, 0x30($29)
    /* 2CC448 003CC448 2000B27B */  lq         $18, 0x20($29)
    /* 2CC44C 003CC44C 1000B17B */  lq         $17, 0x10($29)
    /* 2CC450 003CC450 0000B07B */  lq         $16, 0x0($29)
    /* 2CC454 003CC454 0800E003 */  jr         $31
    /* 2CC458 003CC458 6000BD27 */   addiu     $29, $29, 0x60
    /* 2CC45C 003CC45C 00000000 */  nop
.size func_003cc370, 0xf0
