.section .text
.set noat
.set noreorder
glabel func_002bb420
    /* 1BB420 002BB420 D0FFBD27 */  addiu      $29, $29, -0x30
    /* 1BB424 002BB424 2000BFFF */  sd         $31, 0x20($29)
    /* 1BB428 002BB428 1000B17F */  sq         $17, 0x10($29)
    /* 1BB42C 002BB42C 0000B07F */  sq         $16, 0x0($29)
    /* 1BB430 002BB430 2D808000 */  daddu      $16, $4, $0
    /* 1BB434 002BB434 3C161000 */  dsll32     $2, $16, 24
    /* 1BB438 002BB438 3F160200 */  dsra32     $2, $2, 24
    /* 1BB43C 002BB43C 80180200 */  sll        $3, $2, 2
    /* 1BB440 002BB440 8800023C */  lui        $2, %hi(D_00882F40)
    /* 1BB444 002BB444 402F4224 */  addiu      $2, $2, %lo(D_00882F40)
    /* 1BB448 002BB448 21884300 */  addu       $17, $2, $3
    /* 1BB44C 002BB44C 0000228E */  lw         $2, 0x0($17)
    /* 1BB450 002BB450 04004014 */  bnez       $2, .L002BB464
    /* 1BB454 002BB454 00000000 */   nop
    /* 1BB458 002BB458 2D100000 */  daddu      $2, $0, $0
    /* 1BB45C 002BB45C 1A000010 */  b          .L002BB4C8
    /* 1BB460 002BB460 00000000 */   nop
  .L002BB464:
    /* 1BB464 002BB464 0000448C */  lw         $4, 0x0($2)
    /* 1BB468 002BB468 04008104 */  bgez       $4, .L002BB47C
    /* 1BB46C 002BB46C 00000000 */   nop
    /* 1BB470 002BB470 2D100000 */  daddu      $2, $0, $0
    /* 1BB474 002BB474 14000010 */  b          .L002BB4C8
    /* 1BB478 002BB478 00000000 */   nop
  .L002BB47C:
    /* 1BB47C 002BB47C 2D280000 */  daddu      $5, $0, $0
    /* 1BB480 002BB480 9CDB090C */  jal        func_00276e70
    /* 1BB484 002BB484 00000000 */   nop
    /* 1BB488 002BB488 0000228E */  lw         $2, 0x0($17)
    /* 1BB48C 002BB48C 0000448C */  lw         $4, 0x0($2)
    /* 1BB490 002BB490 94DC090C */  jal        func_00277250
    /* 1BB494 002BB494 00000000 */   nop
    /* 1BB498 002BB498 0000228E */  lw         $2, 0x0($17)
    /* 1BB49C 002BB49C 0000448C */  lw         $4, 0x0($2)
    /* 1BB4A0 002BB4A0 2D280000 */  daddu      $5, $0, $0
    /* 1BB4A4 002BB4A4 B4DE090C */  jal        func_00277ad0
    /* 1BB4A8 002BB4A8 00000000 */   nop
    /* 1BB4AC 002BB4AC 2D200002 */  daddu      $4, $16, $0
    /* 1BB4B0 002BB4B0 01000524 */  addiu      $5, $0, 0x1
    /* 1BB4B4 002BB4B4 A4EF0A0C */  jal        func_002bbe90
    /* 1BB4B8 002BB4B8 00000000 */   nop
    /* 1BB4BC 002BB4BC 0000228E */  lw         $2, 0x0($17)
    /* 1BB4C0 002BB4C0 040040A0 */  sb         $0, 0x4($2)
    /* 1BB4C4 002BB4C4 01000224 */  addiu      $2, $0, 0x1
  .L002BB4C8:
    /* 1BB4C8 002BB4C8 2000BFDF */  ld         $31, 0x20($29)
    /* 1BB4CC 002BB4CC 1000B17B */  lq         $17, 0x10($29)
    /* 1BB4D0 002BB4D0 0000B07B */  lq         $16, 0x0($29)
    /* 1BB4D4 002BB4D4 3000BD27 */  addiu      $29, $29, 0x30
    /* 1BB4D8 002BB4D8 0800E003 */  jr         $31
    /* 1BB4DC 002BB4DC 00000000 */   nop
.size func_002bb420, 0xc0
