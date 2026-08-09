.section .text
.set noat
.set noreorder
glabel func_004ca460
    /* 3CA460 004CA460 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 3CA464 004CA464 2D10A000 */  daddu      $2, $5, $0
    /* 3CA468 004CA468 0000B0FF */  sd         $16, 0x0($29)
    /* 3CA46C 004CA46C 2D808000 */  daddu      $16, $4, $0
    /* 3CA470 004CA470 0800B1FF */  sd         $17, 0x8($29)
    /* 3CA474 004CA474 2D88C000 */  daddu      $17, $6, $0
    /* 3CA478 004CA478 1000B2FF */  sd         $18, 0x10($29)
    /* 3CA47C 004CA47C 2D90E000 */  daddu      $18, $7, $0
    /* 3CA480 004CA480 1800BFFF */  sd         $31, 0x18($29)
    /* 3CA484 004CA484 02000426 */  addiu      $4, $16, 0x2
    /* 3CA488 004CA488 20000524 */  addiu      $5, $0, 0x20
    /* 3CA48C 004CA48C 02002012 */  beqz       $17, .L004CA498
    /* 3CA490 004CA490 24004328 */   slti      $3, $2, 0x24
    /* 3CA494 004CA494 000020AE */  sw         $0, 0x0($17)
  .L004CA498:
    /* 3CA498 004CA498 0B006014 */  bnez       $3, .L004CA4C8
    /* 3CA49C 004CA49C FFFF0224 */   addiu     $2, $0, -0x1
    /* 3CA4A0 004CA4A0 80FF0224 */  addiu      $2, $0, -0x80
    /* 3CA4A4 004CA4A4 010000A2 */  sb         $0, 0x1($16)
    /* 3CA4A8 004CA4A8 AC27130C */  jal        func_004c9eb0
    /* 3CA4AC 004CA4AC 000002A2 */   sb        $2, 0x0($16)
    /* 3CA4B0 004CA4B0 04000426 */  addiu      $4, $16, 0x4
    /* 3CA4B4 004CA4B4 DA28130C */  jal        func_004ca368
    /* 3CA4B8 004CA4B8 2D284002 */   daddu     $5, $18, $0
    /* 3CA4BC 004CA4BC 24000224 */  addiu      $2, $0, 0x24
    /* 3CA4C0 004CA4C0 000022AE */  sw         $2, 0x0($17)
    /* 3CA4C4 004CA4C4 2D100000 */  daddu      $2, $0, $0
  .L004CA4C8:
    /* 3CA4C8 004CA4C8 0000B0DF */  ld         $16, 0x0($29)
    /* 3CA4CC 004CA4CC 0800B1DF */  ld         $17, 0x8($29)
    /* 3CA4D0 004CA4D0 1000B2DF */  ld         $18, 0x10($29)
    /* 3CA4D4 004CA4D4 1800BFDF */  ld         $31, 0x18($29)
    /* 3CA4D8 004CA4D8 0800E003 */  jr         $31
    /* 3CA4DC 004CA4DC 2000BD27 */   addiu     $29, $29, 0x20
.size func_004ca460, 0x80
