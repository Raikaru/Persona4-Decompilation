.section .text
.set noat
.set noreorder
glabel func_003eea90
    /* 2EEA90 003EEA90 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 2EEA94 003EEA94 8800023C */  lui        $2, %hi(D_008872E0)
    /* 2EEA98 003EEA98 0000BFFF */  sd         $31, 0x0($29)
    /* 2EEA9C 003EEA9C E0724224 */  addiu      $2, $2, %lo(D_008872E0)
    /* 2EEAA0 003EEAA0 E0B7838F */  lw         $3, -0x4820($28)
    /* 2EEAA4 003EEAA4 21104300 */  addu       $2, $2, $3
    /* 2EEAA8 003EEAA8 1C00428C */  lw         $2, 0x1C($2)
    /* 2EEAAC 003EEAAC 05004010 */  beqz       $2, .L003EEAC4
    /* 2EEAB0 003EEAB0 00000000 */   nop
    /* 2EEAB4 003EEAB4 1CB90F0C */  jal        func_003ee470
    /* 2EEAB8 003EEAB8 00000000 */   nop
    /* 2EEABC 003EEABC 04000010 */  b          .L003EEAD0
    /* 2EEAC0 003EEAC0 0000BFDF */   ld        $31, 0x0($29)
  .L003EEAC4:
    /* 2EEAC4 003EEAC4 74B80F0C */  jal        func_003ee1d0
    /* 2EEAC8 003EEAC8 00000000 */   nop
    /* 2EEACC 003EEACC 0000BFDF */  ld         $31, 0x0($29)
  .L003EEAD0:
    /* 2EEAD0 003EEAD0 0800E003 */  jr         $31
    /* 2EEAD4 003EEAD4 1000BD27 */   addiu     $29, $29, 0x10
    /* 2EEAD8 003EEAD8 00000000 */  nop
    /* 2EEADC 003EEADC 00000000 */  nop
.size func_003eea90, 0x50
