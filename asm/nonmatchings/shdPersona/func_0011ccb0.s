.section .text
.set noat
.set noreorder
glabel func_0011ccb0
    /* 1CCB0 0011CCB0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 1CCB4 0011CCB4 0000BFFF */  sd         $31, 0x0($29)
    /* 1CCB8 0011CCB8 3405838C */  lw         $3, 0x534($4)
    /* 1CCBC 0011CCBC 00206230 */  andi       $2, $3, 0x2000
    /* 1CCC0 0011CCC0 04004010 */  beqz       $2, .L0011CCD4
    /* 1CCC4 0011CCC4 00000000 */   nop
    /* 1CCC8 0011CCC8 2D100000 */  daddu      $2, $0, $0
    /* 1CCCC 0011CCCC 0F000010 */  b          .L0011CD0C
    /* 1CCD0 0011CCD0 00000000 */   nop
  .L0011CCD4:
    /* 1CCD4 0011CCD4 1000023C */  lui        $2, (0x100000 >> 16)
    /* 1CCD8 0011CCD8 24106200 */  and        $2, $3, $2
    /* 1CCDC 0011CCDC 08004010 */  beqz       $2, .L0011CD00
    /* 1CCE0 0011CCE0 00000000 */   nop
    /* 1CCE4 0011CCE4 88008380 */  lb         $3, 0x88($4)
    /* 1CCE8 0011CCE8 08000224 */  addiu      $2, $0, 0x8
    /* 1CCEC 0011CCEC 04006214 */  bne        $3, $2, .L0011CD00
    /* 1CCF0 0011CCF0 00000000 */   nop
    /* 1CCF4 0011CCF4 F4048294 */  lhu        $2, 0x4F4($4)
    /* 1CCF8 0011CCF8 04000010 */  b          .L0011CD0C
    /* 1CCFC 0011CCFC 00000000 */   nop
  .L0011CD00:
    /* 1CD00 0011CD00 84008424 */  addiu      $4, $4, 0x84
    /* 1CD04 0011CD04 AC54040C */  jal        func_001152b0
    /* 1CD08 0011CD08 00000000 */   nop
  .L0011CD0C:
    /* 1CD0C 0011CD0C 0000BFDF */  ld         $31, 0x0($29)
    /* 1CD10 0011CD10 1000BD27 */  addiu      $29, $29, 0x10
    /* 1CD14 0011CD14 0800E003 */  jr         $31
    /* 1CD18 0011CD18 00000000 */   nop
    /* 1CD1C 0011CD1C 00000000 */  nop
.size func_0011ccb0, 0x70
