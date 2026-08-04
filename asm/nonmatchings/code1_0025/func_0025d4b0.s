.section .text
.set noat
.set noreorder
glabel func_0025d4b0
    /* 15D4B0 0025D4B0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 15D4B4 0025D4B4 0000BFFF */  sd         $31, 0x0($29)
    /* 15D4B8 0025D4B8 08740A0C */  jal        func_0029d020
    /* 15D4BC 0025D4BC 00000000 */   nop
    /* 15D4C0 0025D4C0 07004014 */  bnez       $2, .L0025D4E0
    /* 15D4C4 0025D4C4 00000000 */   nop
    /* 15D4C8 0025D4C8 2D200000 */  daddu      $4, $0, $0
    /* 15D4CC 0025D4CC 2D280000 */  daddu      $5, $0, $0
    /* 15D4D0 0025D4D0 C0A80A0C */  jal        func_002aa300
    /* 15D4D4 0025D4D4 00000000 */   nop
    /* 15D4D8 0025D4D8 0B000010 */  b          .L0025D508
    /* 15D4DC 0025D4DC 00000000 */   nop
  .L0025D4E0:
    /* 15D4E0 0025D4E0 FCA80A0C */  jal        func_002aa3f0
    /* 15D4E4 0025D4E4 00000000 */   nop
    /* 15D4E8 0025D4E8 07004010 */  beqz       $2, .L0025D508
    /* 15D4EC 0025D4EC 00000000 */   nop
    /* 15D4F0 0025D4F0 2D204000 */  daddu      $4, $2, $0
    /* 15D4F4 0025D4F4 D4730A0C */  jal        func_0029cf50
    /* 15D4F8 0025D4F8 00000000 */   nop
    /* 15D4FC 0025D4FC 01000224 */  addiu      $2, $0, 0x1
    /* 15D500 0025D500 02000010 */  b          .L0025D50C
    /* 15D504 0025D504 00000000 */   nop
  .L0025D508:
    /* 15D508 0025D508 2D100000 */  daddu      $2, $0, $0
  .L0025D50C:
    /* 15D50C 0025D50C 0000BFDF */  ld         $31, 0x0($29)
    /* 15D510 0025D510 1000BD27 */  addiu      $29, $29, 0x10
    /* 15D514 0025D514 0800E003 */  jr         $31
    /* 15D518 0025D518 00000000 */   nop
    /* 15D51C 0025D51C 00000000 */  nop
.size func_0025d4b0, 0x70
