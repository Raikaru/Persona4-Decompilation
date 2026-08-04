.section .text
.set noat
.set noreorder
glabel func_002bb4e0
    /* 1BB4E0 002BB4E0 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 1BB4E4 002BB4E4 1000BFFF */  sd         $31, 0x10($29)
    /* 1BB4E8 002BB4E8 0000B07F */  sq         $16, 0x0($29)
    /* 1BB4EC 002BB4EC DCEF0A0C */  jal        func_002bbf70
    /* 1BB4F0 002BB4F0 00000000 */   nop
    /* 1BB4F4 002BB4F4 2D804000 */  daddu      $16, $2, $0
    /* 1BB4F8 002BB4F8 04000016 */  bnez       $16, .L002BB50C
    /* 1BB4FC 002BB4FC 00000000 */   nop
    /* 1BB500 002BB500 2D100000 */  daddu      $2, $0, $0
    /* 1BB504 002BB504 0D000010 */  b          .L002BB53C
    /* 1BB508 002BB508 00000000 */   nop
  .L002BB50C:
    /* 1BB50C 002BB50C 0000048E */  lw         $4, 0x0($16)
    /* 1BB510 002BB510 07008004 */  bltz       $4, .L002BB530
    /* 1BB514 002BB514 00000000 */   nop
    /* 1BB518 002BB518 FCDD090C */  jal        func_002777f0
    /* 1BB51C 002BB51C 00000000 */   nop
    /* 1BB520 002BB520 FFFF0224 */  addiu      $2, $0, -0x1
    /* 1BB524 002BB524 000002AE */  sw         $2, 0x0($16)
    /* 1BB528 002BB528 040000A2 */  sb         $0, 0x4($16)
    /* 1BB52C 002BB52C 050000A2 */  sb         $0, 0x5($16)
  .L002BB530:
    /* 1BB530 002BB530 74830B0C */  jal        func_002e0dd0
    /* 1BB534 002BB534 00000000 */   nop
    /* 1BB538 002BB538 01000224 */  addiu      $2, $0, 0x1
  .L002BB53C:
    /* 1BB53C 002BB53C 1000BFDF */  ld         $31, 0x10($29)
    /* 1BB540 002BB540 0000B07B */  lq         $16, 0x0($29)
    /* 1BB544 002BB544 2000BD27 */  addiu      $29, $29, 0x20
    /* 1BB548 002BB548 0800E003 */  jr         $31
    /* 1BB54C 002BB54C 00000000 */   nop
.size func_002bb4e0, 0x70
