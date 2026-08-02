.section .text
.set noat
.set noreorder
glabel func_001e5d90
    /* E5D90 001E5D90 D0FFBD27 */  addiu      $29, $29, -0x30
    /* E5D94 001E5D94 2000BFFF */  sd         $31, 0x20($29)
    /* E5D98 001E5D98 1000B17F */  sq         $17, 0x10($29)
    /* E5D9C 001E5D9C 0000B07F */  sq         $16, 0x0($29)
    /* E5DA0 001E5DA0 14740A0C */  jal        func_0029d050
    /* E5DA4 001E5DA4 00000000 */   nop
    /* E5DA8 001E5DA8 2D884000 */  daddu      $17, $2, $0
    /* E5DAC 001E5DAC 2D200000 */  daddu      $4, $0, $0
    /* E5DB0 001E5DB0 00730A0C */  jal        func_0029cc00
    /* E5DB4 001E5DB4 00000000 */   nop
    /* E5DB8 001E5DB8 FFFF5030 */  andi       $16, $2, 0xFFFF
    /* E5DBC 001E5DBC 3000228E */  lw         $2, 0x30($17)
    /* E5DC0 001E5DC0 640A448C */  lw         $4, 0xA64($2)
    /* E5DC4 001E5DC4 08000524 */  addiu      $5, $0, 0x8
    /* E5DC8 001E5DC8 20CE080C */  jal        func_00233880
    /* E5DCC 001E5DCC 00000000 */   nop
    /* E5DD0 001E5DD0 3000228E */  lw         $2, 0x30($17)
    /* E5DD4 001E5DD4 640A448C */  lw         $4, 0xA64($2)
    /* E5DD8 001E5DD8 09000524 */  addiu      $5, $0, 0x9
    /* E5DDC 001E5DDC 20CE080C */  jal        func_00233880
    /* E5DE0 001E5DE0 00000000 */   nop
    /* E5DE4 001E5DE4 3000228E */  lw         $2, 0x30($17)
    /* E5DE8 001E5DE8 640A448C */  lw         $4, 0xA64($2)
    /* E5DEC 001E5DEC 0A000524 */  addiu      $5, $0, 0xA
    /* E5DF0 001E5DF0 20CE080C */  jal        func_00233880
    /* E5DF4 001E5DF4 00000000 */   nop
    /* E5DF8 001E5DF8 3000228E */  lw         $2, 0x30($17)
    /* E5DFC 001E5DFC 640A448C */  lw         $4, 0xA64($2)
    /* E5E00 001E5E00 0B000524 */  addiu      $5, $0, 0xB
    /* E5E04 001E5E04 20CE080C */  jal        func_00233880
    /* E5E08 001E5E08 00000000 */   nop
    /* E5E0C 001E5E0C 3000228E */  lw         $2, 0x30($17)
    /* E5E10 001E5E10 640A428C */  lw         $2, 0xA64($2)
    /* E5E14 001E5E14 040050A4 */  sh         $16, 0x4($2)
    /* E5E18 001E5E18 01000224 */  addiu      $2, $0, 0x1
    /* E5E1C 001E5E1C 2000BFDF */  ld         $31, 0x20($29)
    /* E5E20 001E5E20 1000B17B */  lq         $17, 0x10($29)
    /* E5E24 001E5E24 0000B07B */  lq         $16, 0x0($29)
    /* E5E28 001E5E28 3000BD27 */  addiu      $29, $29, 0x30
    /* E5E2C 001E5E2C 0800E003 */  jr         $31
    /* E5E30 001E5E30 00000000 */   nop
    /* E5E34 001E5E34 00000000 */  nop
    /* E5E38 001E5E38 00000000 */  nop
    /* E5E3C 001E5E3C 00000000 */  nop
.size func_001e5d90, 0xb0
