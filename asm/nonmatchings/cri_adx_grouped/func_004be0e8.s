.section .text
.set noat
.set noreorder
glabel func_004be0e8
    /* 3BE0E8 004BE0E8 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3BE0EC 004BE0EC 1000A52C */  sltiu      $5, $5, 0x10
    /* 3BE0F0 004BE0F0 0000B0FF */  sd         $16, 0x0($29)
    /* 3BE0F4 004BE0F4 2D808000 */  daddu      $16, $4, $0
    /* 3BE0F8 004BE0F8 05000016 */  bnez       $16, .L004BE110
    /* 3BE0FC 004BE0FC 0800BFFF */   sd        $31, 0x8($29)
    /* 3BE100 004BE100 7500043C */  lui        $4, %hi(D_00756A90)
    /* 3BE104 004BE104 06000010 */  b          .L004BE120
    /* 3BE108 004BE108 906A8424 */   addiu     $4, $4, %lo(D_00756A90)
    /* 3BE10C 004BE10C 00000000 */  nop
  .L004BE110:
    /* 3BE110 004BE110 0700A010 */  beqz       $5, .L004BE130
    /* 3BE114 004BE114 00000000 */   nop
    /* 3BE118 004BE118 7500043C */  lui        $4, %hi(D_00756AC8)
    /* 3BE11C 004BE11C C86A8424 */  addiu      $4, $4, %lo(D_00756AC8)
  .L004BE120:
    /* 3BE120 004BE120 A8F5120C */  jal        func_004bd6a0
    /* 3BE124 004BE124 00000000 */   nop
    /* 3BE128 004BE128 04000010 */  b          .L004BE13C
    /* 3BE12C 004BE12C 2D100000 */   daddu     $2, $0, $0
  .L004BE130:
    /* 3BE130 004BE130 FEF8120C */  jal        func_004be3f8
    /* 3BE134 004BE134 00000000 */   nop
    /* 3BE138 004BE138 2D100002 */  daddu      $2, $16, $0
  .L004BE13C:
    /* 3BE13C 004BE13C 0000B0DF */  ld         $16, 0x0($29)
    /* 3BE140 004BE140 0800BFDF */  ld         $31, 0x8($29)
    /* 3BE144 004BE144 0800E003 */  jr         $31
    /* 3BE148 004BE148 1000BD27 */   addiu     $29, $29, 0x10
    /* 3BE14C 004BE14C 00000000 */  nop
.size func_004be0e8, 0x68
