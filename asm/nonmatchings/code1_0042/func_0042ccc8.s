.section .text
.set noat
.set noreorder
glabel func_0042ccc8
    /* 32CCC8 0042CCC8 D0FFBD27 */  addiu      $29, $29, -0x30
    /* 32CCCC 0042CCCC 1000B1FF */  sd         $17, 0x10($29)
    /* 32CCD0 0042CCD0 0000B0FF */  sd         $16, 0x0($29)
    /* 32CCD4 0042CCD4 2000BFFF */  sd         $31, 0x20($29)
    /* 32CCD8 0042CCD8 88AE100C */  jal        func_0042ba20
    /* 32CCDC 0042CCDC 00000000 */   nop
    /* 32CCE0 0042CCE0 16B3100C */  jal        func_0042cc58
    /* 32CCE4 0042CCE4 2D804000 */   daddu     $16, $2, $0
    /* 32CCE8 0042CCE8 03000012 */  beqz       $16, .L0042CCF8
    /* 32CCEC 0042CCEC 2D884000 */   daddu     $17, $2, $0
    /* 32CCF0 0042CCF0 9CAE100C */  jal        func_0042ba70
    /* 32CCF4 0042CCF4 00000000 */   nop
  .L0042CCF8:
    /* 32CCF8 0042CCF8 2D102002 */  daddu      $2, $17, $0
    /* 32CCFC 0042CCFC 2000BFDF */  ld         $31, 0x20($29)
    /* 32CD00 0042CD00 1000B1DF */  ld         $17, 0x10($29)
    /* 32CD04 0042CD04 0000B0DF */  ld         $16, 0x0($29)
    /* 32CD08 0042CD08 0800E003 */  jr         $31
    /* 32CD0C 0042CD0C 3000BD27 */   addiu     $29, $29, 0x30
.size func_0042ccc8, 0x48
