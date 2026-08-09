.section .text
.set noat
.set noreorder
glabel func_0021dab0
    /* 11DAB0 0021DAB0 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 11DAB4 0021DAB4 1000BFFF */  sd         $31, 0x10($29)
    /* 11DAB8 0021DAB8 0000B07F */  sq         $16, 0x0($29)
    /* 11DABC 0021DABC 5849110C */  jal        func_00452560
    /* 11DAC0 0021DAC0 00000000 */   nop
    /* 11DAC4 0021DAC4 2D804000 */  daddu      $16, $2, $0
    /* 11DAC8 0021DAC8 6000428C */  lw         $2, 0x60($2)
    /* 11DACC 0021DACC 01004230 */  andi       $2, $2, 0x1
    /* 11DAD0 0021DAD0 04004010 */  beqz       $2, .L0021DAE4
    /* 11DAD4 0021DAD4 00000000 */   nop
    /* 11DAD8 0021DAD8 3809048E */  lw         $4, 0x938($16)
    /* 11DADC 0021DADC 1CBA0D0C */  jal        func_0036e870
    /* 11DAE0 0021DAE0 00000000 */   nop
  .L0021DAE4:
    /* 11DAE4 0021DAE4 3C09048E */  lw         $4, 0x93C($16)
    /* 11DAE8 0021DAE8 DC85080C */  jal        func_00221770
    /* 11DAEC 0021DAEC 00000000 */   nop
    /* 11DAF0 0021DAF0 0000038E */  lw         $3, 0x0($16)
    /* 11DAF4 0021DAF4 02006334 */  ori        $3, $3, 0x2
    /* 11DAF8 0021DAF8 000003AE */  sw         $3, 0x0($16)
    /* 11DAFC 0021DAFC 1000BFDF */  ld         $31, 0x10($29)
    /* 11DB00 0021DB00 0000B07B */  lq         $16, 0x0($29)
    /* 11DB04 0021DB04 2000BD27 */  addiu      $29, $29, 0x20
    /* 11DB08 0021DB08 0800E003 */  jr         $31
    /* 11DB0C 0021DB0C 00000000 */   nop
.size func_0021dab0, 0x60
