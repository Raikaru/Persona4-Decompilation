.section .text
.set noat
.set noreorder
glabel func_004cd250
    /* 3CD250 004CD250 7200023C */  lui        $2, %hi(D_007212CC)
    /* 3CD254 004CD254 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3CD258 004CD258 CC12438C */  lw         $3, %lo(D_007212CC)($2)
    /* 3CD25C 004CD25C 0000B0FF */  sd         $16, 0x0($29)
    /* 3CD260 004CD260 01001024 */  addiu      $16, $0, 0x1
    /* 3CD264 004CD264 07007010 */  beq        $3, $16, .L004CD284
    /* 3CD268 004CD268 0800BFFF */   sd        $31, 0x8($29)
    /* 3CD26C 004CD26C 03006010 */  beqz       $3, .L004CD27C
    /* 3CD270 004CD270 02000224 */   addiu     $2, $0, 0x2
    /* 3CD274 004CD274 03006254 */  bnel       $3, $2, .L004CD284
    /* 3CD278 004CD278 2D800000 */   daddu     $16, $0, $0
  .L004CD27C:
    /* 3CD27C 004CD27C FE30130C */  jal        func_004cc3f8
    /* 3CD280 004CD280 00000000 */   nop
  .L004CD284:
    /* 3CD284 004CD284 B02C130C */  jal        func_004cb2c0
    /* 3CD288 004CD288 FFFF0424 */   addiu     $4, $0, -0x1
    /* 3CD28C 004CD28C 2D100002 */  daddu      $2, $16, $0
    /* 3CD290 004CD290 0800BFDF */  ld         $31, 0x8($29)
    /* 3CD294 004CD294 0000B0DF */  ld         $16, 0x0($29)
    /* 3CD298 004CD298 0800E003 */  jr         $31
    /* 3CD29C 004CD29C 1000BD27 */   addiu     $29, $29, 0x10
.size func_004cd250, 0x50
