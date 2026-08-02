.section .text
.set noat
.set noreorder
glabel func_001e1f90
    /* E1F90 001E1F90 E0FFBD27 */  addiu      $29, $29, -0x20
    /* E1F94 001E1F94 1000BFFF */  sd         $31, 0x10($29)
    /* E1F98 001E1F98 0000B07F */  sq         $16, 0x0($29)
    /* E1F9C 001E1F9C 14740A0C */  jal        func_0029d050
    /* E1FA0 001E1FA0 00000000 */   nop
    /* E1FA4 001E1FA4 2D804000 */  daddu      $16, $2, $0
    /* E1FA8 001E1FA8 2D200000 */  daddu      $4, $0, $0
    /* E1FAC 001E1FAC 00730A0C */  jal        func_0029cc00
    /* E1FB0 001E1FB0 00000000 */   nop
    /* E1FB4 001E1FB4 FFFF4430 */  andi       $4, $2, 0xFFFF
    /* E1FB8 001E1FB8 3000028E */  lw         $2, 0x30($16)
    /* E1FBC 001E1FBC A2004390 */  lbu        $3, 0xA2($2)
    /* E1FC0 001E1FC0 01000224 */  addiu      $2, $0, 0x1
    /* E1FC4 001E1FC4 04106200 */  sllv       $2, $2, $3
    /* E1FC8 001E1FC8 FFFF4530 */  andi       $5, $2, 0xFFFF
    /* E1FCC 001E1FCC 0800063C */  lui        $6, (0x80000 >> 16)
    /* E1FD0 001E1FD0 A064070C */  jal        func_001d9280
    /* E1FD4 001E1FD4 00000000 */   nop
    /* E1FD8 001E1FD8 09004010 */  beqz       $2, .L001E2000
    /* E1FDC 001E1FDC 00000000 */   nop
    /* E1FE0 001E1FE0 2D204000 */  daddu      $4, $2, $0
    /* E1FE4 001E1FE4 2D280000 */  daddu      $5, $0, $0
    /* E1FE8 001E1FE8 6100023C */  lui        $2, %hi(D_00609A30)
    /* E1FEC 001E1FEC 309A428C */  lw         $2, %lo(D_00609A30)($2)
    /* E1FF0 001E1FF0 09F84000 */  jalr       $2
    /* E1FF4 001E1FF4 00000000 */   nop
    /* E1FF8 001E1FF8 02000010 */  b          .L001E2004
    /* E1FFC 001E1FFC 00000000 */   nop
  .L001E2000:
    /* E2000 001E2000 2D100000 */  daddu      $2, $0, $0
  .L001E2004:
    /* E2004 001E2004 2B200200 */  sltu       $4, $0, $2
    /* E2008 001E2008 D4730A0C */  jal        func_0029cf50
    /* E200C 001E200C 00000000 */   nop
    /* E2010 001E2010 01000224 */  addiu      $2, $0, 0x1
    /* E2014 001E2014 1000BFDF */  ld         $31, 0x10($29)
    /* E2018 001E2018 0000B07B */  lq         $16, 0x0($29)
    /* E201C 001E201C 2000BD27 */  addiu      $29, $29, 0x20
    /* E2020 001E2020 0800E003 */  jr         $31
    /* E2024 001E2024 00000000 */   nop
    /* E2028 001E2028 00000000 */  nop
    /* E202C 001E202C 00000000 */  nop
.size func_001e1f90, 0xa0
