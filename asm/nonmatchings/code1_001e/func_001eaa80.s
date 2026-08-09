.section .text
.set noat
.set noreorder
glabel func_001eaa80
    /* EAA80 001EAA80 F0FFBD27 */  addiu      $29, $29, -0x10
    /* EAA84 001EAA84 0000BFFF */  sd         $31, 0x0($29)
    /* EAA88 001EAA88 18AE070C */  jal        func_001eb860
    /* EAA8C 001EAA8C 00000000 */   nop
    /* EAA90 001EAA90 01000324 */  addiu      $3, $0, 0x1
    /* EAA94 001EAA94 05004314 */  bne        $2, $3, .L001EAAAC
    /* EAA98 001EAA98 00000000 */   nop
    /* EAA9C 001EAA9C ACB3838F */  lw         $3, -0x4C54($28)
    /* EAAA0 001EAAA0 0C00628C */  lw         $2, 0xC($3)
    /* EAAA4 001EAAA4 00204234 */  ori        $2, $2, 0x2000
    /* EAAA8 001EAAA8 0C0062AC */  sw         $2, 0xC($3)
  .L001EAAAC:
    /* EAAAC 001EAAAC 01000224 */  addiu      $2, $0, 0x1
    /* EAAB0 001EAAB0 0000BFDF */  ld         $31, 0x0($29)
    /* EAAB4 001EAAB4 1000BD27 */  addiu      $29, $29, 0x10
    /* EAAB8 001EAAB8 0800E003 */  jr         $31
    /* EAABC 001EAABC 00000000 */   nop
.size func_001eaa80, 0x40
