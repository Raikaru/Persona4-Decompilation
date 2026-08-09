.section .text
.set noat
.set noreorder
glabel func_0040afb0
    /* 30AFB0 0040AFB0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 30AFB4 0040AFB4 0000BFFF */  sd         $31, 0x0($29)
    /* 30AFB8 0040AFB8 84B98293 */  lbu        $2, -0x467C($28)
    /* 30AFBC 0040AFBC 01004230 */  andi       $2, $2, 0x1
    /* 30AFC0 0040AFC0 04004010 */  beqz       $2, .L0040AFD4
    /* 30AFC4 0040AFC4 00000000 */   nop
    /* 30AFC8 0040AFC8 7500053C */  lui        $5, %hi(D_00753340)
    /* 30AFCC 0040AFCC 03000010 */  b          .L0040AFDC
    /* 30AFD0 0040AFD0 4033A524 */   addiu     $5, $5, %lo(D_00753340)
  .L0040AFD4:
    /* 30AFD4 0040AFD4 7500053C */  lui        $5, %hi(D_00753330)
    /* 30AFD8 0040AFD8 3033A524 */  addiu      $5, $5, %lo(D_00753330)
  .L0040AFDC:
    /* 30AFDC 0040AFDC 80190600 */  sll        $3, $6, 6
    /* 30AFE0 0040AFE0 80110700 */  sll        $2, $7, 6
    /* 30AFE4 0040AFE4 21308300 */  addu       $6, $4, $3
    /* 30AFE8 0040AFE8 21388200 */  addu       $7, $4, $2
    /* 30AFEC 0040AFEC 2D20A000 */  daddu      $4, $5, $0
    /* 30AFF0 0040AFF0 7C2B100C */  jal        func_0040adf0
    /* 30AFF4 0040AFF4 2D280000 */   daddu     $5, $0, $0
    /* 30AFF8 0040AFF8 0000BFDF */  ld         $31, 0x0($29)
    /* 30AFFC 0040AFFC 01000224 */  addiu      $2, $0, 0x1
    /* 30B000 0040B000 0800E003 */  jr         $31
    /* 30B004 0040B004 1000BD27 */   addiu     $29, $29, 0x10
    /* 30B008 0040B008 00000000 */  nop
    /* 30B00C 0040B00C 00000000 */  nop
.size func_0040afb0, 0x60
