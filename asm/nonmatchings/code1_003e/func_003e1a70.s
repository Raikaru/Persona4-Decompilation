.section .text
.set noat
.set noreorder
glabel func_003e1a70
    /* 2E1A70 003E1A70 C0FFBD27 */  addiu      $29, $29, -0x40
    /* 2E1A74 003E1A74 3000BFFF */  sd         $31, 0x30($29)
    /* 2E1A78 003E1A78 2000B27F */  sq         $18, 0x20($29)
    /* 2E1A7C 003E1A7C 1000B17F */  sq         $17, 0x10($29)
    /* 2E1A80 003E1A80 0000B07F */  sq         $16, 0x0($29)
    /* 2E1A84 003E1A84 78B7918F */  lw         $17, -0x4888($28)
    /* 2E1A88 003E1A88 78B79027 */  addiu      $16, $28, -0x4888
    /* 2E1A8C 003E1A8C 0C003012 */  beq        $17, $16, .L003E1AC0
    /* 2E1A90 003E1A90 2D900000 */   daddu     $18, $0, $0
  .L003E1A94:
    /* 2E1A94 003E1A94 D0850F0C */  jal        func_003e1740
    /* 2E1A98 003E1A98 E4FF2426 */   addiu     $4, $17, -0x1C
    /* 2E1A9C 003E1A9C 2A080200 */  slt        $1, $0, $2
    /* 2E1AA0 003E1AA0 03002010 */  beqz       $1, .L003E1AB0
    /* 2E1AA4 003E1AA4 00000000 */   nop
    /* 2E1AA8 003E1AA8 21904202 */  addu       $18, $18, $2
    /* 2E1AAC 003E1AAC 00000000 */  nop
  .L003E1AB0:
    /* 2E1AB0 003E1AB0 0000318E */  lw         $17, 0x0($17)
    /* 2E1AB4 003E1AB4 F7FF3016 */  bne        $17, $16, .L003E1A94
    /* 2E1AB8 003E1AB8 00000000 */   nop
    /* 2E1ABC 003E1ABC 00000000 */  nop
  .L003E1AC0:
    /* 2E1AC0 003E1AC0 2D104002 */  daddu      $2, $18, $0
    /* 2E1AC4 003E1AC4 3000BFDF */  ld         $31, 0x30($29)
    /* 2E1AC8 003E1AC8 2000B27B */  lq         $18, 0x20($29)
    /* 2E1ACC 003E1ACC 1000B17B */  lq         $17, 0x10($29)
    /* 2E1AD0 003E1AD0 0000B07B */  lq         $16, 0x0($29)
    /* 2E1AD4 003E1AD4 0800E003 */  jr         $31
    /* 2E1AD8 003E1AD8 4000BD27 */   addiu     $29, $29, 0x40
    /* 2E1ADC 003E1ADC 00000000 */  nop
.size func_003e1a70, 0x70
