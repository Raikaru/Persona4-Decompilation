.section .text
.set noat
.set noreorder
glabel func_002aa3f0
    /* 1AA3F0 002AA3F0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 1AA3F4 002AA3F4 0000BFFF */  sd         $31, 0x0($29)
    /* 1AA3F8 002AA3F8 28A88427 */  addiu      $4, $28, -0x57D8
    /* 1AA3FC 002AA3FC E048110C */  jal        func_00452380
    /* 1AA400 002AA400 00000000 */   nop
    /* 1AA404 002AA404 0A004014 */  bnez       $2, .L002AA430
    /* 1AA408 002AA408 00000000 */   nop
    /* 1AA40C 002AA40C 44B5828F */  lw         $2, -0x4ABC($28)
    /* 1AA410 002AA410 04004010 */  beqz       $2, .L002AA424
    /* 1AA414 002AA414 00000000 */   nop
    /* 1AA418 002AA418 01000224 */  addiu      $2, $0, 0x1
    /* 1AA41C 002AA41C 02000010 */  b          .L002AA428
    /* 1AA420 002AA420 00000000 */   nop
  .L002AA424:
    /* 1AA424 002AA424 02000224 */  addiu      $2, $0, 0x2
  .L002AA428:
    /* 1AA428 002AA428 02000010 */  b          .L002AA434
    /* 1AA42C 002AA42C 00000000 */   nop
  .L002AA430:
    /* 1AA430 002AA430 2D100000 */  daddu      $2, $0, $0
  .L002AA434:
    /* 1AA434 002AA434 0000BFDF */  ld         $31, 0x0($29)
    /* 1AA438 002AA438 1000BD27 */  addiu      $29, $29, 0x10
    /* 1AA43C 002AA43C 0800E003 */  jr         $31
    /* 1AA440 002AA440 00000000 */   nop
    /* 1AA444 002AA444 00000000 */  nop
    /* 1AA448 002AA448 00000000 */  nop
    /* 1AA44C 002AA44C 00000000 */  nop
.size func_002aa3f0, 0x60
