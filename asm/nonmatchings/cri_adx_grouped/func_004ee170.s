.section .text
.set noat
.set noreorder
glabel func_004ee170
    /* 3EE170 004EE170 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3EE174 004EE174 0000B0FF */  sd         $16, 0x0($29)
    /* 3EE178 004EE178 2D808000 */  daddu      $16, $4, $0
    /* 3EE17C 004EE17C 0A000016 */  bnez       $16, .L004EE1A8
    /* 3EE180 004EE180 0800BFFF */   sd        $31, 0x8($29)
    /* 3EE184 004EE184 7600043C */  lui        $4, %hi(D_0075CD90)
    /* 3EE188 004EE188 7600053C */  lui        $5, %hi(D_0075CDA0)
    /* 3EE18C 004EE18C 0000B0DF */  ld         $16, 0x0($29)
    /* 3EE190 004EE190 90CD8424 */  addiu      $4, $4, %lo(D_0075CD90)
    /* 3EE194 004EE194 0800BFDF */  ld         $31, 0x8($29)
    /* 3EE198 004EE198 A0CDA524 */  addiu      $5, $5, %lo(D_0075CDA0)
    /* 3EE19C 004EE19C B4B71308 */  j          func_004eded0
    /* 3EE1A0 004EE1A0 1000BD27 */   addiu     $29, $29, 0x10
    /* 3EE1A4 004EE1A4 00000000 */  nop
  .L004EE1A8:
    /* 3EE1A8 004EE1A8 0400028E */  lw         $2, 0x4($16)
    /* 3EE1AC 004EE1AC 0A004014 */  bnez       $2, .L004EE1D8
    /* 3EE1B0 004EE1B0 2D280000 */   daddu     $5, $0, $0
    /* 3EE1B4 004EE1B4 7600043C */  lui        $4, %hi(D_0075CDC0)
    /* 3EE1B8 004EE1B8 7600053C */  lui        $5, %hi(D_0075CDD0)
    /* 3EE1BC 004EE1BC 0000B0DF */  ld         $16, 0x0($29)
    /* 3EE1C0 004EE1C0 C0CD8424 */  addiu      $4, $4, %lo(D_0075CDC0)
    /* 3EE1C4 004EE1C4 0800BFDF */  ld         $31, 0x8($29)
    /* 3EE1C8 004EE1C8 D0CDA524 */  addiu      $5, $5, %lo(D_0075CDD0)
    /* 3EE1CC 004EE1CC B4B71308 */  j          func_004eded0
    /* 3EE1D0 004EE1D0 1000BD27 */   addiu     $29, $29, 0x10
    /* 3EE1D4 004EE1D4 00000000 */  nop
  .L004EE1D8:
    /* 3EE1D8 004EE1D8 72FE100C */  jal        func_0043f9c8
    /* 3EE1DC 004EE1DC 40000624 */   addiu     $6, $0, 0x40
    /* 3EE1E0 004EE1E0 040000AE */  sw         $0, 0x4($16)
    /* 3EE1E4 004EE1E4 0800BFDF */  ld         $31, 0x8($29)
    /* 3EE1E8 004EE1E8 0000B0DF */  ld         $16, 0x0($29)
    /* 3EE1EC 004EE1EC 0800E003 */  jr         $31
    /* 3EE1F0 004EE1F0 1000BD27 */   addiu     $29, $29, 0x10
    /* 3EE1F4 004EE1F4 00000000 */  nop
.size func_004ee170, 0x88
