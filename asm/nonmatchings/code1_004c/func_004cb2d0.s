.section .text
.set noat
.set noreorder
glabel func_004cb2d0
    /* 3CB2D0 004CB2D0 7200023C */  lui        $2, %hi(D_00719980)
    /* 3CB2D4 004CB2D4 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3CB2D8 004CB2D8 8099448C */  lw         $4, %lo(D_00719980)($2)
    /* 3CB2DC 004CB2DC 0000BFFF */  sd         $31, 0x0($29)
    /* 3CB2E0 004CB2E0 442D130C */  jal        func_004cb510
    /* 3CB2E4 004CB2E4 00000000 */   nop
    /* 3CB2E8 004CB2E8 2D184000 */  daddu      $3, $2, $0
    /* 3CB2EC 004CB2EC 01000224 */  addiu      $2, $0, 0x1
    /* 3CB2F0 004CB2F0 0B006210 */  beq        $3, $2, .L004CB320
    /* 3CB2F4 004CB2F4 02006428 */   slti      $4, $3, 0x2
    /* 3CB2F8 004CB2F8 16008014 */  bnez       $4, .L004CB354
    /* 3CB2FC 004CB2FC 0000BFDF */   ld        $31, 0x0($29)
    /* 3CB300 004CB300 02000224 */  addiu      $2, $0, 0x2
    /* 3CB304 004CB304 0A006210 */  beq        $3, $2, .L004CB330
    /* 3CB308 004CB308 03000224 */   addiu     $2, $0, 0x3
    /* 3CB30C 004CB30C 0C006210 */  beq        $3, $2, .L004CB340
    /* 3CB310 004CB310 2D100000 */   daddu     $2, $0, $0
    /* 3CB314 004CB314 10000010 */  b          .L004CB358
    /* 3CB318 004CB318 00000000 */   nop
    /* 3CB31C 004CB31C 00000000 */  nop
  .L004CB320:
    /* 3CB320 004CB320 FE2C130C */  jal        func_004cb3f8
    /* 3CB324 004CB324 00000000 */   nop
    /* 3CB328 004CB328 0A000010 */  b          .L004CB354
    /* 3CB32C 004CB32C 0000BFDF */   ld        $31, 0x0($29)
  .L004CB330:
    /* 3CB330 004CB330 32C4130C */  jal        func_004f10c8
    /* 3CB334 004CB334 00000000 */   nop
    /* 3CB338 004CB338 06000010 */  b          .L004CB354
    /* 3CB33C 004CB33C 0000BFDF */   ld        $31, 0x0($29)
  .L004CB340:
    /* 3CB340 004CB340 38C4130C */  jal        func_004f10e0
    /* 3CB344 004CB344 00000000 */   nop
    /* 3CB348 004CB348 3EC4130C */  jal        func_004f10f8
    /* 3CB34C 004CB34C 00000000 */   nop
    /* 3CB350 004CB350 0000BFDF */  ld         $31, 0x0($29)
  .L004CB354:
    /* 3CB354 004CB354 2D100000 */  daddu      $2, $0, $0
  .L004CB358:
    /* 3CB358 004CB358 0800E003 */  jr         $31
    /* 3CB35C 004CB35C 1000BD27 */   addiu     $29, $29, 0x10
.size func_004cb2d0, 0x90
