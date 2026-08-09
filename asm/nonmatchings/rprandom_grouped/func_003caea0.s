.section .text
.set noat
.set noreorder
glabel func_003caea0
    /* 2CAEA0 003CAEA0 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 2CAEA4 003CAEA4 1000BFFF */  sd         $31, 0x10($29)
    /* 2CAEA8 003CAEA8 0000B07F */  sq         $16, 0x0($29)
    /* 2CAEAC 003CAEAC 10B7828F */  lw         $2, -0x48F0($28)
    /* 2CAEB0 003CAEB0 2D808000 */  daddu      $16, $4, $0
    /* 2CAEB4 003CAEB4 2110A200 */  addu       $2, $5, $2
    /* 2CAEB8 003CAEB8 0000448C */  lw         $4, 0x0($2)
    /* 2CAEBC 003CAEBC 03008010 */  beqz       $4, .L003CAECC
    /* 2CAEC0 003CAEC0 00000000 */   nop
    /* 2CAEC4 003CAEC4 3C2F0F0C */  jal        func_003cbcf0
    /* 2CAEC8 003CAEC8 2D280002 */   daddu     $5, $16, $0
  .L003CAECC:
    /* 2CAECC 003CAECC 2D100002 */  daddu      $2, $16, $0
    /* 2CAED0 003CAED0 1000BFDF */  ld         $31, 0x10($29)
    /* 2CAED4 003CAED4 0000B07B */  lq         $16, 0x0($29)
    /* 2CAED8 003CAED8 0800E003 */  jr         $31
    /* 2CAEDC 003CAEDC 2000BD27 */   addiu     $29, $29, 0x20
.size func_003caea0, 0x40
