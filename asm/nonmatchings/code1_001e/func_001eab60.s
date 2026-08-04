.section .text
.set noat
.set noreorder
glabel func_001eab60
    /* EAB60 001EAB60 F0FFBD27 */  addiu      $29, $29, -0x10
    /* EAB64 001EAB64 0000BFFF */  sd         $31, 0x0($29)
    /* EAB68 001EAB68 ACB3828F */  lw         $2, -0x4C54($28)
    /* EAB6C 001EAB6C D40D448C */  lw         $4, 0xDD4($2)
    /* EAB70 001EAB70 E04E080C */  jal        func_00213b80
    /* EAB74 001EAB74 00000000 */   nop
    /* EAB78 001EAB78 18AE070C */  jal        func_001eb860
    /* EAB7C 001EAB7C 00000000 */   nop
    /* EAB80 001EAB80 01000324 */  addiu      $3, $0, 0x1
    /* EAB84 001EAB84 06004314 */  bne        $2, $3, .L001EABA0
    /* EAB88 001EAB88 00000000 */   nop
    /* EAB8C 001EAB8C ACB3828F */  lw         $2, -0x4C54($28)
    /* EAB90 001EAB90 D40D448C */  lw         $4, 0xDD4($2)
    /* EAB94 001EAB94 2D280000 */  daddu      $5, $0, $0
    /* EAB98 001EAB98 9048080C */  jal        func_00212240
    /* EAB9C 001EAB9C 00000000 */   nop
  .L001EABA0:
    /* EABA0 001EABA0 01000224 */  addiu      $2, $0, 0x1
    /* EABA4 001EABA4 0000BFDF */  ld         $31, 0x0($29)
    /* EABA8 001EABA8 1000BD27 */  addiu      $29, $29, 0x10
    /* EABAC 001EABAC 0800E003 */  jr         $31
    /* EABB0 001EABB0 00000000 */   nop
    /* EABB4 001EABB4 00000000 */  nop
    /* EABB8 001EABB8 00000000 */  nop
    /* EABBC 001EABBC 00000000 */  nop
.size func_001eab60, 0x60
