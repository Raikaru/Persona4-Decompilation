.section .text
.set noat
.set noreorder
glabel func_004cb360
    /* 3CB360 004CB360 7200023C */  lui        $2, %hi(D_00719980)
    /* 3CB364 004CB364 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3CB368 004CB368 8099448C */  lw         $4, %lo(D_00719980)($2)
    /* 3CB36C 004CB36C 0000BFFF */  sd         $31, 0x0($29)
    /* 3CB370 004CB370 442D130C */  jal        func_004cb510
    /* 3CB374 004CB374 00000000 */   nop
    /* 3CB378 004CB378 2D184000 */  daddu      $3, $2, $0
    /* 3CB37C 004CB37C 01000224 */  addiu      $2, $0, 0x1
    /* 3CB380 004CB380 19006210 */  beq        $3, $2, .L004CB3E8
    /* 3CB384 004CB384 02006428 */   slti      $4, $3, 0x2
    /* 3CB388 004CB388 18008014 */  bnez       $4, .L004CB3EC
    /* 3CB38C 004CB38C 0000BFDF */   ld        $31, 0x0($29)
    /* 3CB390 004CB390 02000224 */  addiu      $2, $0, 0x2
    /* 3CB394 004CB394 06006210 */  beq        $3, $2, .L004CB3B0
    /* 3CB398 004CB398 03000224 */   addiu     $2, $0, 0x3
    /* 3CB39C 004CB39C 08006210 */  beq        $3, $2, .L004CB3C0
    /* 3CB3A0 004CB3A0 2D100000 */   daddu     $2, $0, $0
    /* 3CB3A4 004CB3A4 12000010 */  b          .L004CB3F0
    /* 3CB3A8 004CB3A8 00000000 */   nop
    /* 3CB3AC 004CB3AC 00000000 */  nop
  .L004CB3B0:
    /* 3CB3B0 004CB3B0 14C4130C */  jal        func_004f1050
    /* 3CB3B4 004CB3B4 00000000 */   nop
    /* 3CB3B8 004CB3B8 0C000010 */  b          .L004CB3EC
    /* 3CB3BC 004CB3BC 0000BFDF */   ld        $31, 0x0($29)
  .L004CB3C0:
    /* 3CB3C0 004CB3C0 14C4130C */  jal        func_004f1050
    /* 3CB3C4 004CB3C4 00000000 */   nop
    /* 3CB3C8 004CB3C8 1AC4130C */  jal        func_004f1068
    /* 3CB3CC 004CB3CC 00000000 */   nop
    /* 3CB3D0 004CB3D0 20C4130C */  jal        func_004f1080
    /* 3CB3D4 004CB3D4 00000000 */   nop
    /* 3CB3D8 004CB3D8 26C4130C */  jal        func_004f1098
    /* 3CB3DC 004CB3DC 00000000 */   nop
    /* 3CB3E0 004CB3E0 32C4130C */  jal        func_004f10c8
    /* 3CB3E4 004CB3E4 00000000 */   nop
  .L004CB3E8:
    /* 3CB3E8 004CB3E8 0000BFDF */  ld         $31, 0x0($29)
  .L004CB3EC:
    /* 3CB3EC 004CB3EC 2D100000 */  daddu      $2, $0, $0
  .L004CB3F0:
    /* 3CB3F0 004CB3F0 0800E003 */  jr         $31
    /* 3CB3F4 004CB3F4 1000BD27 */   addiu     $29, $29, 0x10
.size func_004cb360, 0x98
