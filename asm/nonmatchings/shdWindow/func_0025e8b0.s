.section .text
.set noat
.set noreorder
glabel func_0025e8b0
    /* 15E8B0 0025E8B0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 15E8B4 0025E8B4 0000BFFF */  sd         $31, 0x0($29)
    /* 15E8B8 0025E8B8 5849110C */  jal        func_00452560
    /* 15E8BC 0025E8BC 00000000 */   nop
    /* 15E8C0 0025E8C0 0400448C */  lw         $4, 0x4($2)
    /* 15E8C4 0025E8C4 04008330 */  andi       $3, $4, 0x4
    /* 15E8C8 0025E8C8 03006014 */  bnez       $3, .L0025E8D8
    /* 15E8CC 0025E8CC 00000000 */   nop
    /* 15E8D0 0025E8D0 04008334 */  ori        $3, $4, 0x4
    /* 15E8D4 0025E8D4 040043AC */  sw         $3, 0x4($2)
  .L0025E8D8:
    /* 15E8D8 0025E8D8 0000BFDF */  ld         $31, 0x0($29)
    /* 15E8DC 0025E8DC 1000BD27 */  addiu      $29, $29, 0x10
    /* 15E8E0 0025E8E0 0800E003 */  jr         $31
    /* 15E8E4 0025E8E4 00000000 */   nop
    /* 15E8E8 0025E8E8 00000000 */  nop
    /* 15E8EC 0025E8EC 00000000 */  nop
.size func_0025e8b0, 0x40
