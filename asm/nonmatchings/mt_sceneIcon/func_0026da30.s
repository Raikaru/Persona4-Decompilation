.section .text
.set noat
.set noreorder
glabel func_0026da30
    /* 16DA30 0026DA30 D0FFBD27 */  addiu      $29, $29, -0x30
    /* 16DA34 0026DA34 2000BFFF */  sd         $31, 0x20($29)
    /* 16DA38 0026DA38 1000B17F */  sq         $17, 0x10($29)
    /* 16DA3C 0026DA3C 0000B07F */  sq         $16, 0x0($29)
    /* 16DA40 0026DA40 2D888000 */  daddu      $17, $4, $0
    /* 16DA44 0026DA44 2D80A000 */  daddu      $16, $5, $0
    /* 16DA48 0026DA48 0A000224 */  addiu      $2, $0, 0xA
    /* 16DA4C 0026DA4C 23000216 */  bne        $16, $2, .L0026DADC
    /* 16DA50 0026DA50 00000000 */   nop
    /* 16DA54 0026DA54 9C14050C */  jal        func_00145270
    /* 16DA58 0026DA58 00000000 */   nop
    /* 16DA5C 0026DA5C 1C004010 */  beqz       $2, .L0026DAD0
    /* 16DA60 0026DA60 00000000 */   nop
    /* 16DA64 0026DA64 00004494 */  lhu        $4, 0x0($2)
    /* 16DA68 0026DA68 0F00033C */  lui        $3, (0xFFC00 >> 16)
    /* 16DA6C 0026DA6C 00FC6334 */  ori        $3, $3, (0xFFC00 & 0xFFFF)
    /* 16DA70 0026DA70 24188300 */  and        $3, $4, $3
    /* 16DA74 0026DA74 83220300 */  sra        $4, $3, 10
    /* 16DA78 0026DA78 01000324 */  addiu      $3, $0, 0x1
    /* 16DA7C 0026DA7C 09008314 */  bne        $4, $3, .L0026DAA4
    /* 16DA80 0026DA80 00000000 */   nop
    /* 16DA84 0026DA84 4401448C */  lw         $4, 0x144($2)
    /* 16DA88 0026DA88 14008010 */  beqz       $4, .L0026DADC
    /* 16DA8C 0026DA8C 00000000 */   nop
    /* 16DA90 0026DA90 5CC4120C */  jal        func_004b1170
    /* 16DA94 0026DA94 00000000 */   nop
    /* 16DA98 0026DA98 2D100000 */  daddu      $2, $0, $0
    /* 16DA9C 0026DA9C 28000010 */  b          .L0026DB40
    /* 16DAA0 0026DAA0 00000000 */   nop
  .L0026DAA4:
    /* 16DAA4 0026DAA4 03000324 */  addiu      $3, $0, 0x3
    /* 16DAA8 0026DAA8 0C008314 */  bne        $4, $3, .L0026DADC
    /* 16DAAC 0026DAAC 00000000 */   nop
    /* 16DAB0 0026DAB0 4401448C */  lw         $4, 0x144($2)
    /* 16DAB4 0026DAB4 09008010 */  beqz       $4, .L0026DADC
    /* 16DAB8 0026DAB8 00000000 */   nop
    /* 16DABC 0026DABC 5CC4120C */  jal        func_004b1170
    /* 16DAC0 0026DAC0 00000000 */   nop
    /* 16DAC4 0026DAC4 2D100000 */  daddu      $2, $0, $0
    /* 16DAC8 0026DAC8 1D000010 */  b          .L0026DB40
    /* 16DACC 0026DACC 00000000 */   nop
  .L0026DAD0:
    /* 16DAD0 0026DAD0 2D100000 */  daddu      $2, $0, $0
    /* 16DAD4 0026DAD4 1A000010 */  b          .L0026DB40
    /* 16DAD8 0026DAD8 00000000 */   nop
  .L0026DADC:
    /* 16DADC 0026DADC 6400043C */  lui        $4, %hi(D_0063B558)
    /* 16DAE0 0026DAE0 58B58424 */  addiu      $4, $4, %lo(D_0063B558)
    /* 16DAE4 0026DAE4 C1000524 */  addiu      $5, $0, 0xC1
    /* 16DAE8 0026DAE8 A43A110C */  jal        func_0044ea90
    /* 16DAEC 0026DAEC 00000000 */   nop
    /* 16DAF0 0026DAF0 01000424 */  addiu      $4, $0, 0x1
    /* 16DAF4 0026DAF4 10000524 */  addiu      $5, $0, 0x10
    /* 16DAF8 0026DAF8 0400063C */  lui        $6, (0x40000 >> 16)
    /* 16DAFC 0026DAFC 8800023C */  lui        $2, %hi(D_008873F4)
    /* 16DB00 0026DB00 F473428C */  lw         $2, %lo(D_008873F4)($2)
    /* 16DB04 0026DB04 09F84000 */  jalr       $2
    /* 16DB08 0026DB08 00000000 */   nop
    /* 16DB0C 0026DB0C 2D504000 */  daddu      $10, $2, $0
    /* 16DB10 0026DB10 040051A4 */  sh         $17, 0x4($2)
    /* 16DB14 0026DB14 080050AC */  sw         $16, 0x8($2)
    /* 16DB18 0026DB18 00A78427 */  addiu      $4, $28, -0x5900
    /* 16DB1C 0026DB1C 0F000524 */  addiu      $5, $0, 0xF
    /* 16DB20 0026DB20 2D300000 */  daddu      $6, $0, $0
    /* 16DB24 0026DB24 2D380000 */  daddu      $7, $0, $0
    /* 16DB28 0026DB28 2700083C */  lui        $8, %hi(func_0026d890)
    /* 16DB2C 0026DB2C 90D80825 */  addiu      $8, $8, %lo(func_0026d890)
    /* 16DB30 0026DB30 2700093C */  lui        $9, %hi(func_0026d9f0)
    /* 16DB34 0026DB34 F0D92925 */  addiu      $9, $9, %lo(func_0026d9f0)
    /* 16DB38 0026DB38 7847110C */  jal        func_00451de0
    /* 16DB3C 0026DB3C 00000000 */   nop
  .L0026DB40:
    /* 16DB40 0026DB40 2000BFDF */  ld         $31, 0x20($29)
    /* 16DB44 0026DB44 1000B17B */  lq         $17, 0x10($29)
    /* 16DB48 0026DB48 0000B07B */  lq         $16, 0x0($29)
    /* 16DB4C 0026DB4C 3000BD27 */  addiu      $29, $29, 0x30
    /* 16DB50 0026DB50 0800E003 */  jr         $31
    /* 16DB54 0026DB54 00000000 */   nop
    /* 16DB58 0026DB58 00000000 */  nop
    /* 16DB5C 0026DB5C 00000000 */  nop
.size func_0026da30, 0x130
