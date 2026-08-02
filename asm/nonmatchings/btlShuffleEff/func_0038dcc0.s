.section .text
.set noat
.set noreorder
glabel func_0038dcc0
    /* 28DCC0 0038DCC0 C0FFBD27 */  addiu      $29, $29, -0x40
    /* 28DCC4 0038DCC4 3000BFFF */  sd         $31, 0x30($29)
    /* 28DCC8 0038DCC8 2000B27F */  sq         $18, 0x20($29)
    /* 28DCCC 0038DCCC 1000B17F */  sq         $17, 0x10($29)
    /* 28DCD0 0038DCD0 0000B07F */  sq         $16, 0x0($29)
    /* 28DCD4 0038DCD4 2D88A000 */  daddu      $17, $5, $0
    /* 28DCD8 0038DCD8 3800908C */  lw         $16, 0x38($4)
    /* 28DCDC 0038DCDC 04002006 */  bltz       $17, .L0038DCF0
    /* 28DCE0 0038DCE0 00000000 */   nop
    /* 28DCE4 0038DCE4 0900232A */  slti       $3, $17, 0x9
    /* 28DCE8 0038DCE8 06006014 */  bnez       $3, .L0038DD04
    /* 28DCEC 0038DCEC 00000000 */   nop
  .L0038DCF0:
    /* 28DCF0 0038DCF0 6500043C */  lui        $4, %hi(D_0064F210)
    /* 28DCF4 0038DCF4 10F28424 */  addiu      $4, $4, %lo(D_0064F210)
    /* 28DCF8 0038DCF8 55000524 */  addiu      $5, $0, 0x55
    /* 28DCFC 0038DCFC CCB5110C */  jal        func_0046d730
    /* 28DD00 0038DD00 00000000 */   nop
  .L0038DD04:
    /* 28DD04 0038DD04 C0181100 */  sll        $3, $17, 3
    /* 28DD08 0038DD08 21187000 */  addu       $3, $3, $16
    /* 28DD0C 0038DD0C 0C007224 */  addiu      $18, $3, 0xC
    /* 28DD10 0038DD10 0C00648C */  lw         $4, 0xC($3)
    /* 28DD14 0038DD14 04008010 */  beqz       $4, .L0038DD28
    /* 28DD18 0038DD18 00000000 */   nop
    /* 28DD1C 0038DD1C 54C4120C */  jal        func_004b1150
    /* 28DD20 0038DD20 00000000 */   nop
    /* 28DD24 0038DD24 000040AE */  sw         $0, 0x0($18)
  .L0038DD28:
    /* 28DD28 0038DD28 01000324 */  addiu      $3, $0, 0x1
    /* 28DD2C 0038DD2C 04182302 */  sllv       $3, $3, $17
    /* 28DD30 0038DD30 27186000 */  not        $3, $3
    /* 28DD34 0038DD34 FFFF6430 */  andi       $4, $3, 0xFFFF
    /* 28DD38 0038DD38 04000396 */  lhu        $3, 0x4($16)
    /* 28DD3C 0038DD3C 24186400 */  and        $3, $3, $4
    /* 28DD40 0038DD40 040003A6 */  sh         $3, 0x4($16)
    /* 28DD44 0038DD44 3000BFDF */  ld         $31, 0x30($29)
    /* 28DD48 0038DD48 2000B27B */  lq         $18, 0x20($29)
    /* 28DD4C 0038DD4C 1000B17B */  lq         $17, 0x10($29)
    /* 28DD50 0038DD50 0000B07B */  lq         $16, 0x0($29)
    /* 28DD54 0038DD54 4000BD27 */  addiu      $29, $29, 0x40
    /* 28DD58 0038DD58 0800E003 */  jr         $31
    /* 28DD5C 0038DD5C 00000000 */   nop
    /* 28DD60 0038DD60 0800E003 */  jr         $31
    /* 28DD64 0038DD64 00000000 */   nop
    /* 28DD68 0038DD68 00000000 */  nop
    /* 28DD6C 0038DD6C 00000000 */  nop
.size func_0038dcc0, 0xb0
