.section .text
.set noat
.set noreorder
glabel func_004de340
    /* 3DE340 004DE340 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3DE344 004DE344 7300023C */  lui        $2, %hi(D_0072ACB4)
    /* 3DE348 004DE348 0000B0FF */  sd         $16, 0x0($29)
    /* 3DE34C 004DE34C B4AC5024 */  addiu      $16, $2, %lo(D_0072ACB4)
    /* 3DE350 004DE350 0800BFFF */  sd         $31, 0x8($29)
    /* 3DE354 004DE354 7300033C */  lui        $3, %hi(D_0072ACB0)
    /* 3DE358 004DE358 0000048E */  lw         $4, 0x0($16)
    /* 3DE35C 004DE35C B0AC6324 */  addiu      $3, $3, %lo(D_0072ACB0)
    /* 3DE360 004DE360 0000628C */  lw         $2, 0x0($3)
    /* 3DE364 004DE364 1D008014 */  bnez       $4, .L004DE3DC
    /* 3DE368 004DE368 01008224 */   addiu     $2, $4, 0x1
    /* 3DE36C 004DE36C C829130C */  jal        func_004ca720
    /* 3DE370 004DE370 00000000 */   nop
    /* 3DE374 004DE374 EC80130C */  jal        func_004e03b0
    /* 3DE378 004DE378 00000000 */   nop
    /* 3DE37C 004DE37C 7300043C */  lui        $4, %hi(D_0072ACC8)
    /* 3DE380 004DE380 2D280000 */  daddu      $5, $0, $0
    /* 3DE384 004DE384 C8AC8424 */  addiu      $4, $4, %lo(D_0072ACC8)
    /* 3DE388 004DE388 72FE100C */  jal        func_0043f9c8
    /* 3DE38C 004DE38C B0090624 */   addiu     $6, $0, 0x9B0
    /* 3DE390 004DE390 4E00063C */  lui        $6, %hi(func_004de2e8)
    /* 3DE394 004DE394 7600083C */  lui        $8, %hi(D_007595F8)
    /* 3DE398 004DE398 E8E2C624 */  addiu      $6, $6, %lo(func_004de2e8)
    /* 3DE39C 004DE39C F8950825 */  addiu      $8, $8, %lo(D_007595F8)
    /* 3DE3A0 004DE3A0 02000424 */  addiu      $4, $0, 0x2
    /* 3DE3A4 004DE3A4 2D280000 */  daddu      $5, $0, $0
    /* 3DE3A8 004DE3A8 1EC3130C */  jal        func_004f0c78
    /* 3DE3AC 004DE3AC 2D380000 */   daddu     $7, $0, $0
    /* 3DE3B0 004DE3B0 4E00053C */  lui        $5, %hi(func_004de310)
    /* 3DE3B4 004DE3B4 7600073C */  lui        $7, %hi(D_00759608)
    /* 3DE3B8 004DE3B8 05000424 */  addiu      $4, $0, 0x5
    /* 3DE3BC 004DE3BC 10E3A524 */  addiu      $5, $5, %lo(func_004de310)
    /* 3DE3C0 004DE3C0 0896E724 */  addiu      $7, $7, %lo(D_00759608)
    /* 3DE3C4 004DE3C4 98C2130C */  jal        func_004f0a60
    /* 3DE3C8 004DE3C8 2D300000 */   daddu     $6, $0, $0
    /* 3DE3CC 004DE3CC 7300033C */  lui        $3, %hi(D_0072ACB8)
    /* 3DE3D0 004DE3D0 B8AC62AC */  sw         $2, %lo(D_0072ACB8)($3)
    /* 3DE3D4 004DE3D4 0000048E */  lw         $4, 0x0($16)
    /* 3DE3D8 004DE3D8 01008224 */  addiu      $2, $4, 0x1
  .L004DE3DC:
    /* 3DE3DC 004DE3DC 0800BFDF */  ld         $31, 0x8($29)
    /* 3DE3E0 004DE3E0 000002AE */  sw         $2, 0x0($16)
    /* 3DE3E4 004DE3E4 0000B0DF */  ld         $16, 0x0($29)
    /* 3DE3E8 004DE3E8 0800E003 */  jr         $31
    /* 3DE3EC 004DE3EC 1000BD27 */   addiu     $29, $29, 0x10
.size func_004de340, 0xb0
