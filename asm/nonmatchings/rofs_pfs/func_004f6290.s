.section .text
.set noat
.set noreorder
glabel func_004f6290
    /* 3F6290 004F6290 7400023C */  lui        $2, %hi(D_00743B58)
    /* 3F6294 004F6294 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3F6298 004F6298 583B428C */  lw         $2, %lo(D_00743B58)($2)
    /* 3F629C 004F629C 0A004010 */  beqz       $2, .L004F62C8
    /* 3F62A0 004F62A0 0000BFFF */   sd        $31, 0x0($29)
    /* 3F62A4 004F62A4 2000428C */  lw         $2, 0x20($2)
    /* 3F62A8 004F62A8 08004050 */  beql       $2, $0, .L004F62CC
    /* 3F62AC 004F62AC 7600043C */   lui       $4, %hi(D_0075DA28)
    /* 3F62B0 004F62B0 09F84000 */  jalr       $2
    /* 3F62B4 004F62B4 00000000 */   nop
    /* 3F62B8 004F62B8 0000BFDF */  ld         $31, 0x0($29)
    /* 3F62BC 004F62BC 0800E003 */  jr         $31
    /* 3F62C0 004F62C0 1000BD27 */   addiu     $29, $29, 0x10
    /* 3F62C4 004F62C4 00000000 */  nop
  .L004F62C8:
    /* 3F62C8 004F62C8 7600043C */  lui        $4, %hi(D_0075DA28)
  .L004F62CC:
    /* 3F62CC 004F62CC 7600063C */  lui        $6, %hi(D_0075DA50)
    /* 3F62D0 004F62D0 0000BFDF */  ld         $31, 0x0($29)
    /* 3F62D4 004F62D4 28DA8424 */  addiu      $4, $4, %lo(D_0075DA28)
    /* 3F62D8 004F62D8 50DAC624 */  addiu      $6, $6, %lo(D_0075DA50)
    /* 3F62DC 004F62DC B8000524 */  addiu      $5, $0, 0xB8
    /* 3F62E0 004F62E0 2D380000 */  daddu      $7, $0, $0
    /* 3F62E4 004F62E4 35FF0824 */  addiu      $8, $0, -0xCB
    /* 3F62E8 004F62E8 F0D41308 */  j          func_004f53c0
    /* 3F62EC 004F62EC 1000BD27 */   addiu     $29, $29, 0x10
.size func_004f6290, 0x60
