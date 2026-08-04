.section .text
.set noat
.set noreorder
glabel func_001eaac0
    /* EAAC0 001EAAC0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* EAAC4 001EAAC4 0000BFFF */  sd         $31, 0x0($29)
    /* EAAC8 001EAAC8 18AE070C */  jal        func_001eb860
    /* EAACC 001EAACC 00000000 */   nop
    /* EAAD0 001EAAD0 01000324 */  addiu      $3, $0, 0x1
    /* EAAD4 001EAAD4 08004314 */  bne        $2, $3, .L001EAAF8
    /* EAAD8 001EAAD8 00000000 */   nop
    /* EAADC 001EAADC ACB3848F */  lw         $4, -0x4C54($28)
    /* EAAE0 001EAAE0 0C00838C */  lw         $3, 0xC($4)
    /* EAAE4 001EAAE4 FFDF0224 */  addiu      $2, $0, -0x2001
    /* EAAE8 001EAAE8 24106200 */  and        $2, $3, $2
    /* EAAEC 001EAAEC 0C0082AC */  sw         $2, 0xC($4)
    /* EAAF0 001EAAF0 FCAD070C */  jal        func_001eb7f0
    /* EAAF4 001EAAF4 00000000 */   nop
  .L001EAAF8:
    /* EAAF8 001EAAF8 01000224 */  addiu      $2, $0, 0x1
    /* EAAFC 001EAAFC 0000BFDF */  ld         $31, 0x0($29)
    /* EAB00 001EAB00 1000BD27 */  addiu      $29, $29, 0x10
    /* EAB04 001EAB04 0800E003 */  jr         $31
    /* EAB08 001EAB08 00000000 */   nop
    /* EAB0C 001EAB0C 00000000 */  nop
.size func_001eaac0, 0x50
