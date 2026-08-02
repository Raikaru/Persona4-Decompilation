.section .text
.set noat
.set noreorder
glabel func_0029da90
    /* 19DA90 0029DA90 D0FFBD27 */  addiu      $29, $29, -0x30
    /* 19DA94 0029DA94 2000BFFF */  sd         $31, 0x20($29)
    /* 19DA98 0029DA98 1000B17F */  sq         $17, 0x10($29)
    /* 19DA9C 0029DA9C 0000B07F */  sq         $16, 0x0($29)
    /* 19DAA0 0029DAA0 2D808000 */  daddu      $16, $4, $0
    /* 19DAA4 0029DAA4 2D20A000 */  daddu      $4, $5, $0
    /* 19DAA8 0029DAA8 2D28C000 */  daddu      $5, $6, $0
    /* 19DAAC 0029DAAC 98750A0C */  jal        func_0029d660
    /* 19DAB0 0029DAB0 00000000 */   nop
    /* 19DAB4 0029DAB4 2D884000 */  daddu      $17, $2, $0
    /* 19DAB8 0029DAB8 06002016 */  bnez       $17, .L0029DAD4
    /* 19DABC 0029DABC 00000000 */   nop
    /* 19DAC0 0029DAC0 6400043C */  lui        $4, %hi(D_0063E3D0)
    /* 19DAC4 0029DAC4 D0E38424 */  addiu      $4, $4, %lo(D_0063E3D0)
    /* 19DAC8 0029DAC8 59020524 */  addiu      $5, $0, 0x259
    /* 19DACC 0029DACC CCB5110C */  jal        func_0046d730
    /* 19DAD0 0029DAD0 00000000 */   nop
  .L0029DAD4:
    /* 19DAD4 0029DAD4 2C01228E */  lw         $2, 0x12C($17)
    /* 19DAD8 0029DAD8 40190200 */  sll        $3, $2, 5
    /* 19DADC 0029DADC 1801228E */  lw         $2, 0x118($17)
    /* 19DAE0 0029DAE0 21204300 */  addu       $4, $2, $3
    /* 19DAE4 0029DAE4 2D280002 */  daddu      $5, $16, $0
    /* 19DAE8 0029DAE8 01000624 */  addiu      $6, $0, 0x1
    /* 19DAEC 0029DAEC 2D38C000 */  daddu      $7, $6, $0
    /* 19DAF0 0029DAF0 2A00083C */  lui        $8, %hi(func_0029d870)
    /* 19DAF4 0029DAF4 70D80825 */  addiu      $8, $8, %lo(func_0029d870)
    /* 19DAF8 0029DAF8 2A00093C */  lui        $9, %hi(func_0029d900)
    /* 19DAFC 0029DAFC 00D92925 */  addiu      $9, $9, %lo(func_0029d900)
    /* 19DB00 0029DB00 2D502002 */  daddu      $10, $17, $0
    /* 19DB04 0029DB04 7847110C */  jal        func_00451de0
    /* 19DB08 0029DB08 00000000 */   nop
    /* 19DB0C 0029DB0C 2D804000 */  daddu      $16, $2, $0
    /* 19DB10 0029DB10 06000016 */  bnez       $16, .L0029DB2C
    /* 19DB14 0029DB14 00000000 */   nop
    /* 19DB18 0029DB18 6400043C */  lui        $4, %hi(D_0063E3D0)
    /* 19DB1C 0029DB1C D0E38424 */  addiu      $4, $4, %lo(D_0063E3D0)
    /* 19DB20 0029DB20 F4010524 */  addiu      $5, $0, 0x1F4
    /* 19DB24 0029DB24 CCB5110C */  jal        func_0046d730
    /* 19DB28 0029DB28 00000000 */   nop
  .L0029DB2C:
    /* 19DB2C 0029DB2C 480130AE */  sw         $16, 0x148($17)
    /* 19DB30 0029DB30 2D100002 */  daddu      $2, $16, $0
    /* 19DB34 0029DB34 2000BFDF */  ld         $31, 0x20($29)
    /* 19DB38 0029DB38 1000B17B */  lq         $17, 0x10($29)
    /* 19DB3C 0029DB3C 0000B07B */  lq         $16, 0x0($29)
    /* 19DB40 0029DB40 3000BD27 */  addiu      $29, $29, 0x30
    /* 19DB44 0029DB44 0800E003 */  jr         $31
    /* 19DB48 0029DB48 00000000 */   nop
    /* 19DB4C 0029DB4C 00000000 */  nop
.size func_0029da90, 0xc0
