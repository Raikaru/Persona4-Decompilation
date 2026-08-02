.section .text
.set noat
.set noreorder
glabel func_00277ad0
    /* 177AD0 00277AD0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 177AD4 00277AD4 0000BFFF */  sd         $31, 0x0($29)
    /* 177AD8 00277AD8 08008004 */  bltz       $4, .L00277AFC
    /* 177ADC 00277ADC 00000000 */   nop
    /* 177AE0 00277AE0 40190400 */  sll        $3, $4, 5
    /* 177AE4 00277AE4 8800023C */  lui        $2, %hi(D_00881808)
    /* 177AE8 00277AE8 08184224 */  addiu      $2, $2, %lo(D_00881808)
    /* 177AEC 00277AEC 21104300 */  addu       $2, $2, $3
    /* 177AF0 00277AF0 0000448C */  lw         $4, 0x0($2)
    /* 177AF4 00277AF4 C4DE090C */  jal        func_00277b10
    /* 177AF8 00277AF8 00000000 */   nop
  .L00277AFC:
    /* 177AFC 00277AFC 0000BFDF */  ld         $31, 0x0($29)
    /* 177B00 00277B00 1000BD27 */  addiu      $29, $29, 0x10
    /* 177B04 00277B04 0800E003 */  jr         $31
    /* 177B08 00277B08 00000000 */   nop
    /* 177B0C 00277B0C 00000000 */  nop
.size func_00277ad0, 0x40
