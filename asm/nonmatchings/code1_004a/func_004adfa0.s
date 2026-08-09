.section .text
.set noat
.set noreorder
glabel func_004adfa0
    /* 3ADFA0 004ADFA0 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 3ADFA4 004ADFA4 1000BFFF */  sd         $31, 0x10($29)
    /* 3ADFA8 004ADFA8 0000B07F */  sq         $16, 0x0($29)
    /* 3ADFAC 004ADFAC 2D808000 */  daddu      $16, $4, $0
    /* 3ADFB0 004ADFB0 D4B6120C */  jal        func_004adb50
    /* 3ADFB4 004ADFB4 00000000 */   nop
    /* 3ADFB8 004ADFB8 2D200002 */  daddu      $4, $16, $0
    /* 3ADFBC 004ADFBC A0B7120C */  jal        func_004ade80
    /* 3ADFC0 004ADFC0 00000000 */   nop
    /* 3ADFC4 004ADFC4 1000BFDF */  ld         $31, 0x10($29)
    /* 3ADFC8 004ADFC8 0000B07B */  lq         $16, 0x0($29)
    /* 3ADFCC 004ADFCC 2000BD27 */  addiu      $29, $29, 0x20
    /* 3ADFD0 004ADFD0 0800E003 */  jr         $31
    /* 3ADFD4 004ADFD4 00000000 */   nop
    /* 3ADFD8 004ADFD8 00000000 */  nop
    /* 3ADFDC 004ADFDC 00000000 */  nop
.size func_004adfa0, 0x40
