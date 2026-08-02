.section .text
.set noat
.set noreorder
glabel func_0036daa0
    /* 26DAA0 0036DAA0 C0FFBD27 */  addiu      $29, $29, -0x40
    /* 26DAA4 0036DAA4 3000BFFF */  sd         $31, 0x30($29)
    /* 26DAA8 0036DAA8 2000B27F */  sq         $18, 0x20($29)
    /* 26DAAC 0036DAAC 1000B17F */  sq         $17, 0x10($29)
    /* 26DAB0 0036DAB0 0000B07F */  sq         $16, 0x0($29)
    /* 26DAB4 0036DAB4 2D908000 */  daddu      $18, $4, $0
    /* 26DAB8 0036DAB8 2D80A000 */  daddu      $16, $5, $0
    /* 26DABC 0036DABC 2D88C000 */  daddu      $17, $6, $0
    /* 26DAC0 0036DAC0 2CA20D0C */  jal        func_003688b0
    /* 26DAC4 0036DAC4 00000000 */   nop
    /* 26DAC8 0036DAC8 FFFF1032 */  andi       $16, $16, 0xFFFF
    /* 26DACC 0036DACC 2D204002 */  daddu      $4, $18, $0
    /* 26DAD0 0036DAD0 2D280002 */  daddu      $5, $16, $0
    /* 26DAD4 0036DAD4 2D302002 */  daddu      $6, $17, $0
    /* 26DAD8 0036DAD8 20AA0D0C */  jal        func_0036a880
    /* 26DADC 0036DADC 00000000 */   nop
    /* 26DAE0 0036DAE0 2D200002 */  daddu      $4, $16, $0
    /* 26DAE4 0036DAE4 2D282002 */  daddu      $5, $17, $0
    /* 26DAE8 0036DAE8 5CB10D0C */  jal        func_0036c570
    /* 26DAEC 0036DAEC 00000000 */   nop
    /* 26DAF0 0036DAF0 2D204002 */  daddu      $4, $18, $0
    /* 26DAF4 0036DAF4 E8B60D0C */  jal        func_0036dba0
    /* 26DAF8 0036DAF8 00000000 */   nop
    /* 26DAFC 0036DAFC 3000BFDF */  ld         $31, 0x30($29)
    /* 26DB00 0036DB00 2000B27B */  lq         $18, 0x20($29)
    /* 26DB04 0036DB04 1000B17B */  lq         $17, 0x10($29)
    /* 26DB08 0036DB08 0000B07B */  lq         $16, 0x0($29)
    /* 26DB0C 0036DB0C 4000BD27 */  addiu      $29, $29, 0x40
    /* 26DB10 0036DB10 0800E003 */  jr         $31
    /* 26DB14 0036DB14 00000000 */   nop
    /* 26DB18 0036DB18 00000000 */  nop
    /* 26DB1C 0036DB1C 00000000 */  nop
.size func_0036daa0, 0x80
