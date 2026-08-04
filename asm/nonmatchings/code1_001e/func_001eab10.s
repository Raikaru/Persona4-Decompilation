.section .text
.set noat
.set noreorder
glabel func_001eab10
    /* EAB10 001EAB10 F0FFBD27 */  addiu      $29, $29, -0x10
    /* EAB14 001EAB14 0000BFFF */  sd         $31, 0x0($29)
    /* EAB18 001EAB18 ACB3828F */  lw         $2, -0x4C54($28)
    /* EAB1C 001EAB1C D40D448C */  lw         $4, 0xDD4($2)
    /* EAB20 001EAB20 D44E080C */  jal        func_00213b50
    /* EAB24 001EAB24 00000000 */   nop
    /* EAB28 001EAB28 18AE070C */  jal        func_001eb860
    /* EAB2C 001EAB2C 00000000 */   nop
    /* EAB30 001EAB30 01000524 */  addiu      $5, $0, 0x1
    /* EAB34 001EAB34 05004514 */  bne        $2, $5, .L001EAB4C
    /* EAB38 001EAB38 00000000 */   nop
    /* EAB3C 001EAB3C ACB3828F */  lw         $2, -0x4C54($28)
    /* EAB40 001EAB40 D40D448C */  lw         $4, 0xDD4($2)
    /* EAB44 001EAB44 9048080C */  jal        func_00212240
    /* EAB48 001EAB48 00000000 */   nop
  .L001EAB4C:
    /* EAB4C 001EAB4C 01000224 */  addiu      $2, $0, 0x1
    /* EAB50 001EAB50 0000BFDF */  ld         $31, 0x0($29)
    /* EAB54 001EAB54 1000BD27 */  addiu      $29, $29, 0x10
    /* EAB58 001EAB58 0800E003 */  jr         $31
    /* EAB5C 001EAB5C 00000000 */   nop
.size func_001eab10, 0x50
