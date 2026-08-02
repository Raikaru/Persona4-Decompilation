.section .text
.set noat
.set noreorder
glabel func_0049ee30
    /* 39EE30 0049EE30 C0FFBD27 */  addiu      $29, $29, -0x40
    /* 39EE34 0049EE34 3000BFFF */  sd         $31, 0x30($29)
    /* 39EE38 0049EE38 2000B27F */  sq         $18, 0x20($29)
    /* 39EE3C 0049EE3C 1000B17F */  sq         $17, 0x10($29)
    /* 39EE40 0049EE40 0000B07F */  sq         $16, 0x0($29)
    /* 39EE44 0049EE44 3C00908C */  lw         $16, 0x3C($4)
    /* 39EE48 0049EE48 4000918C */  lw         $17, 0x40($4)
    /* 39EE4C 0049EE4C 3800238E */  lw         $3, 0x38($17)
    /* 39EE50 0049EE50 80100300 */  sll        $2, $3, 2
    /* 39EE54 0049EE54 21104300 */  addu       $2, $2, $3
    /* 39EE58 0049EE58 C0900200 */  sll        $18, $2, 3
    /* 39EE5C 0049EE5C 7100043C */  lui        $4, %hi(D_00713FF0)
    /* 39EE60 0049EE60 F03F8424 */  addiu      $4, $4, %lo(D_00713FF0)
    /* 39EE64 0049EE64 EC070524 */  addiu      $5, $0, 0x7EC
    /* 39EE68 0049EE68 A43A110C */  jal        func_0044ea90
    /* 39EE6C 0049EE6C 00000000 */   nop
    /* 39EE70 0049EE70 10004426 */  addiu      $4, $18, 0x10
    /* 39EE74 0049EE74 0400053C */  lui        $5, (0x40000 >> 16)
    /* 39EE78 0049EE78 8800023C */  lui        $2, %hi(jtbl_008873E8)
    /* 39EE7C 0049EE7C E873428C */  lw         $2, %lo(jtbl_008873E8)($2)
    /* 39EE80 0049EE80 09F84000 */  jalr       $2
    /* 39EE84 0049EE84 00000000 */   nop
    /* 39EE88 0049EE88 2D904000 */  daddu      $18, $2, $0
    /* 39EE8C 0049EE8C 06004016 */  bnez       $18, .L0049EEA8
    /* 39EE90 0049EE90 00000000 */   nop
    /* 39EE94 0049EE94 7100043C */  lui        $4, %hi(D_00713FF0)
    /* 39EE98 0049EE98 F03F8424 */  addiu      $4, $4, %lo(D_00713FF0)
    /* 39EE9C 0049EE9C ED070524 */  addiu      $5, $0, 0x7ED
    /* 39EEA0 0049EEA0 CCB5110C */  jal        func_0046d730
    /* 39EEA4 0049EEA4 00000000 */   nop
  .L0049EEA8:
    /* 39EEA8 0049EEA8 10004226 */  addiu      $2, $18, 0x10
    /* 39EEAC 0049EEAC 000042AE */  sw         $2, 0x0($18)
    /* 39EEB0 0049EEB0 080052AE */  sw         $18, 0x8($18)
    /* 39EEB4 0049EEB4 0400048E */  lw         $4, 0x4($16)
    /* 39EEB8 0049EEB8 9C0C120C */  jal        func_00483270
    /* 39EEBC 0049EEBC 00000000 */   nop
    /* 39EEC0 0049EEC0 040042AE */  sw         $2, 0x4($18)
    /* 39EEC4 0049EEC4 2D204002 */  daddu      $4, $18, $0
    /* 39EEC8 0049EEC8 2D282002 */  daddu      $5, $17, $0
    /* 39EECC 0049EECC F47A120C */  jal        func_0049ebd0
    /* 39EED0 0049EED0 00000000 */   nop
    /* 39EED4 0049EED4 2D104002 */  daddu      $2, $18, $0
    /* 39EED8 0049EED8 3000BFDF */  ld         $31, 0x30($29)
    /* 39EEDC 0049EEDC 2000B27B */  lq         $18, 0x20($29)
    /* 39EEE0 0049EEE0 1000B17B */  lq         $17, 0x10($29)
    /* 39EEE4 0049EEE4 0000B07B */  lq         $16, 0x0($29)
    /* 39EEE8 0049EEE8 4000BD27 */  addiu      $29, $29, 0x40
    /* 39EEEC 0049EEEC 0800E003 */  jr         $31
    /* 39EEF0 0049EEF0 00000000 */   nop
    /* 39EEF4 0049EEF4 00000000 */  nop
    /* 39EEF8 0049EEF8 00000000 */  nop
    /* 39EEFC 0049EEFC 00000000 */  nop
.size func_0049ee30, 0xd0
