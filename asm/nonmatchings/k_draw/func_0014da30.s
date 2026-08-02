.section .text
.set noat
.set noreorder
glabel func_0014da30
    /* 4DA30 0014DA30 D0FFBD27 */  addiu      $29, $29, -0x30
    /* 4DA34 0014DA34 2000BFFF */  sd         $31, 0x20($29)
    /* 4DA38 0014DA38 1000B17F */  sq         $17, 0x10($29)
    /* 4DA3C 0014DA3C 0000B07F */  sq         $16, 0x0($29)
    /* 4DA40 0014DA40 2D80A000 */  daddu      $16, $5, $0
    /* 4DA44 0014DA44 8800113C */  lui        $17, %hi(D_00887300)
    /* 4DA48 0014DA48 00733126 */  addiu      $17, $17, %lo(D_00887300)
    /* 4DA4C 0014DA4C 07000424 */  addiu      $4, $0, 0x7
    /* 4DA50 0014DA50 02000524 */  addiu      $5, $0, 0x2
    /* 4DA54 0014DA54 0000228E */  lw         $2, 0x0($17)
    /* 4DA58 0014DA58 09F84000 */  jalr       $2
    /* 4DA5C 0014DA5C 00000000 */   nop
    /* 4DA60 0014DA60 06000424 */  addiu      $4, $0, 0x6
    /* 4DA64 0014DA64 01000524 */  addiu      $5, $0, 0x1
    /* 4DA68 0014DA68 0000228E */  lw         $2, 0x0($17)
    /* 4DA6C 0014DA6C 09F84000 */  jalr       $2
    /* 4DA70 0014DA70 00000000 */   nop
    /* 4DA74 0014DA74 08000424 */  addiu      $4, $0, 0x8
    /* 4DA78 0014DA78 2D280000 */  daddu      $5, $0, $0
    /* 4DA7C 0014DA7C 0000228E */  lw         $2, 0x0($17)
    /* 4DA80 0014DA80 09F84000 */  jalr       $2
    /* 4DA84 0014DA84 00000000 */   nop
    /* 4DA88 0014DA88 0C000424 */  addiu      $4, $0, 0xC
    /* 4DA8C 0014DA8C 01000524 */  addiu      $5, $0, 0x1
    /* 4DA90 0014DA90 0000228E */  lw         $2, 0x0($17)
    /* 4DA94 0014DA94 09F84000 */  jalr       $2
    /* 4DA98 0014DA98 00000000 */   nop
    /* 4DA9C 0014DA9C 02000424 */  addiu      $4, $0, 0x2
    /* 4DAA0 0014DAA0 44000524 */  addiu      $5, $0, 0x44
    /* 4DAA4 0014DAA4 10D90F0C */  jal        func_003f6440
    /* 4DAA8 0014DAA8 00000000 */   nop
    /* 4DAAC 0014DAAC 03000424 */  addiu      $4, $0, 0x3
    /* 4DAB0 0014DAB0 0700023C */  lui        $2, (0x717FB >> 16)
    /* 4DAB4 0014DAB4 FB174534 */  ori        $5, $2, (0x717FB & 0xFFFF)
    /* 4DAB8 0014DAB8 10D90F0C */  jal        func_003f6440
    /* 4DABC 0014DABC 00000000 */   nop
    /* 4DAC0 0014DAC0 7042023C */  lui        $2, (0x42700000 >> 16)
    /* 4DAC4 0014DAC4 00608244 */  mtc1       $2, $f12
    /* 4DAC8 0014DAC8 2D200002 */  daddu      $4, $16, $0
    /* 4DACC 0014DACC 01000524 */  addiu      $5, $0, 0x1
    /* 4DAD0 0014DAD0 807E110C */  jal        func_0045fa00
    /* 4DAD4 0014DAD4 00000000 */   nop
    /* 4DAD8 0014DAD8 A041023C */  lui        $2, (0x41A00000 >> 16)
    /* 4DADC 0014DADC 00608244 */  mtc1       $2, $f12
    /* 4DAE0 0014DAE0 30000426 */  addiu      $4, $16, 0x30
    /* 4DAE4 0014DAE4 48000526 */  addiu      $5, $16, 0x48
    /* 4DAE8 0014DAE8 01000624 */  addiu      $6, $0, 0x1
    /* 4DAEC 0014DAEC 7080110C */  jal        func_004601c0
    /* 4DAF0 0014DAF0 00000000 */   nop
    /* 4DAF4 0014DAF4 2000BFDF */  ld         $31, 0x20($29)
    /* 4DAF8 0014DAF8 1000B17B */  lq         $17, 0x10($29)
    /* 4DAFC 0014DAFC 0000B07B */  lq         $16, 0x0($29)
    /* 4DB00 0014DB00 3000BD27 */  addiu      $29, $29, 0x30
    /* 4DB04 0014DB04 0800E003 */  jr         $31
    /* 4DB08 0014DB08 00000000 */   nop
    /* 4DB0C 0014DB0C 00000000 */  nop
.size func_0014da30, 0xe0
