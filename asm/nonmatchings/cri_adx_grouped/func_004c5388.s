.section .text
.set noat
.set noreorder
glabel func_004c5388
    /* 3C5388 004C5388 7500053C */  lui        $5, %hi(D_00757E48)
    /* 3C538C 004C538C F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3C5390 004C5390 04000624 */  addiu      $6, $0, 0x4
    /* 3C5394 004C5394 487EA524 */  addiu      $5, $5, %lo(D_00757E48)
    /* 3C5398 004C5398 0000B0FF */  sd         $16, 0x0($29)
    /* 3C539C 004C539C 0800BFFF */  sd         $31, 0x8($29)
    /* 3C53A0 004C53A0 DEFD100C */  jal        func_0043f778
    /* 3C53A4 004C53A4 2D808000 */   daddu     $16, $4, $0
    /* 3C53A8 004C53A8 7500053C */  lui        $5, %hi(D_00757E50)
    /* 3C53AC 004C53AC 08000426 */  addiu      $4, $16, 0x8
    /* 3C53B0 004C53B0 507EA524 */  addiu      $5, $5, %lo(D_00757E50)
    /* 3C53B4 004C53B4 08004014 */  bnez       $2, .L004C53D8
    /* 3C53B8 004C53B8 04000624 */   addiu     $6, $0, 0x4
    /* 3C53BC 004C53BC DEFD100C */  jal        func_0043f778
    /* 3C53C0 004C53C0 00000000 */   nop
    /* 3C53C4 004C53C4 05004054 */  bnel       $2, $0, .L004C53DC
    /* 3C53C8 004C53C8 2D100000 */   daddu     $2, $0, $0
    /* 3C53CC 004C53CC 03000010 */  b          .L004C53DC
    /* 3C53D0 004C53D0 01000224 */   addiu     $2, $0, 0x1
    /* 3C53D4 004C53D4 00000000 */  nop
  .L004C53D8:
    /* 3C53D8 004C53D8 2D100000 */  daddu      $2, $0, $0
  .L004C53DC:
    /* 3C53DC 004C53DC 0000B0DF */  ld         $16, 0x0($29)
    /* 3C53E0 004C53E0 0800BFDF */  ld         $31, 0x8($29)
    /* 3C53E4 004C53E4 0800E003 */  jr         $31
    /* 3C53E8 004C53E8 1000BD27 */   addiu     $29, $29, 0x10
    /* 3C53EC 004C53EC 00000000 */  nop
.size func_004c5388, 0x68
