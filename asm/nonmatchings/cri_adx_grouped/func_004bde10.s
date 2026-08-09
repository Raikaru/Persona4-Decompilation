.section .text
.set noat
.set noreorder
glabel func_004bde10
    /* 3BDE10 004BDE10 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3BDE14 004BDE14 04008010 */  beqz       $4, .L004BDE28
    /* 3BDE18 004BDE18 0000BFFF */   sd        $31, 0x0($29)
    /* 3BDE1C 004BDE1C 0000BFDF */  ld         $31, 0x0($29)
    /* 3BDE20 004BDE20 34F81208 */  j          func_004be0d0
    /* 3BDE24 004BDE24 1000BD27 */   addiu     $29, $29, 0x10
  .L004BDE28:
    /* 3BDE28 004BDE28 0000BFDF */  ld         $31, 0x0($29)
    /* 3BDE2C 004BDE2C 0800E003 */  jr         $31
    /* 3BDE30 004BDE30 1000BD27 */   addiu     $29, $29, 0x10
    /* 3BDE34 004BDE34 00000000 */  nop
.size func_004bde10, 0x28
