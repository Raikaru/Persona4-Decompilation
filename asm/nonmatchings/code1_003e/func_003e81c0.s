.section .text
.set noat
.set noreorder
glabel func_003e81c0
    /* 2E81C0 003E81C0 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 2E81C4 003E81C4 1000BFFF */  sd         $31, 0x10($29)
    /* 2E81C8 003E81C8 0000B07F */  sq         $16, 0x0($29)
    /* 2E81CC 003E81CC 2D808000 */  daddu      $16, $4, $0
    /* 2E81D0 003E81D0 6C9B0F0C */  jal        func_003e6db0
    /* 2E81D4 003E81D4 84008CE4 */   swc1      $f12, 0x84($4)
    /* 2E81D8 003E81D8 0400048E */  lw         $4, 0x4($16)
    /* 2E81DC 003E81DC 03008010 */  beqz       $4, .L003E81EC
    /* 2E81E0 003E81E0 00000000 */   nop
    /* 2E81E4 003E81E4 A0A50F0C */  jal        func_003e9680
    /* 2E81E8 003E81E8 00000000 */   nop
  .L003E81EC:
    /* 2E81EC 003E81EC 2D100002 */  daddu      $2, $16, $0
    /* 2E81F0 003E81F0 1000BFDF */  ld         $31, 0x10($29)
    /* 2E81F4 003E81F4 0000B07B */  lq         $16, 0x0($29)
    /* 2E81F8 003E81F8 0800E003 */  jr         $31
    /* 2E81FC 003E81FC 2000BD27 */   addiu     $29, $29, 0x20
.size func_003e81c0, 0x40
