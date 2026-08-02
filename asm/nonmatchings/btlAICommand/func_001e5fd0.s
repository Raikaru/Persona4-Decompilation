.section .text
.set noat
.set noreorder
glabel func_001e5fd0
    /* E5FD0 001E5FD0 E0FFBD27 */  addiu      $29, $29, -0x20
    /* E5FD4 001E5FD4 1000BFFF */  sd         $31, 0x10($29)
    /* E5FD8 001E5FD8 0000B07F */  sq         $16, 0x0($29)
    /* E5FDC 001E5FDC 14740A0C */  jal        func_0029d050
    /* E5FE0 001E5FE0 00000000 */   nop
    /* E5FE4 001E5FE4 2D804000 */  daddu      $16, $2, $0
    /* E5FE8 001E5FE8 2D200000 */  daddu      $4, $0, $0
    /* E5FEC 001E5FEC 00730A0C */  jal        func_0029cc00
    /* E5FF0 001E5FF0 00000000 */   nop
    /* E5FF4 001E5FF4 FFFF4430 */  andi       $4, $2, 0xFFFF
    /* E5FF8 001E5FF8 3000028E */  lw         $2, 0x30($16)
    /* E5FFC 001E5FFC A2004390 */  lbu        $3, 0xA2($2)
    /* E6000 001E6000 01000224 */  addiu      $2, $0, 0x1
    /* E6004 001E6004 04106200 */  sllv       $2, $2, $3
    /* E6008 001E6008 FFFF4530 */  andi       $5, $2, 0xFFFF
    /* E600C 001E600C 0800063C */  lui        $6, (0x80000 >> 16)
    /* E6010 001E6010 A064070C */  jal        func_001d9280
    /* E6014 001E6014 00000000 */   nop
    /* E6018 001E6018 04004010 */  beqz       $2, .L001E602C
    /* E601C 001E601C 00000000 */   nop
    /* E6020 001E6020 2000448C */  lw         $4, 0x20($2)
    /* E6024 001E6024 02000010 */  b          .L001E6030
    /* E6028 001E6028 00000000 */   nop
  .L001E602C:
    /* E602C 001E602C 2D200000 */  daddu      $4, $0, $0
  .L001E6030:
    /* E6030 001E6030 D4730A0C */  jal        func_0029cf50
    /* E6034 001E6034 00000000 */   nop
    /* E6038 001E6038 01000224 */  addiu      $2, $0, 0x1
    /* E603C 001E603C 1000BFDF */  ld         $31, 0x10($29)
    /* E6040 001E6040 0000B07B */  lq         $16, 0x0($29)
    /* E6044 001E6044 2000BD27 */  addiu      $29, $29, 0x20
    /* E6048 001E6048 0800E003 */  jr         $31
    /* E604C 001E604C 00000000 */   nop
.size func_001e5fd0, 0x80
