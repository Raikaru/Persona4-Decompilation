.section .text
.set noat
.set noreorder
glabel func_001b5db0
    /* B5DB0 001B5DB0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* B5DB4 001B5DB4 0000BFFF */  sd         $31, 0x0($29)
    /* B5DB8 001B5DB8 ACB3828F */  lw         $2, -0x4C54($28)
    /* B5DBC 001B5DBC D00D448C */  lw         $4, 0xDD0($2)
    /* B5DC0 001B5DC0 5849110C */  jal        func_00452560
    /* B5DC4 001B5DC4 00000000 */   nop
    /* B5DC8 001B5DC8 0400428C */  lw         $2, 0x4($2)
    /* B5DCC 001B5DCC 04004010 */  beqz       $2, .L001B5DE0
    /* B5DD0 001B5DD0 00000000 */   nop
    /* B5DD4 001B5DD4 2D100000 */  daddu      $2, $0, $0
    /* B5DD8 001B5DD8 14000010 */  b          .L001B5E2C
    /* B5DDC 001B5DDC 00000000 */   nop
  .L001B5DE0:
    /* B5DE0 001B5DE0 ACB3828F */  lw         $2, -0x4C54($28)
    /* B5DE4 001B5DE4 D00D448C */  lw         $4, 0xDD0($2)
    /* B5DE8 001B5DE8 2048110C */  jal        func_00452080
    /* B5DEC 001B5DEC 00000000 */   nop
    /* B5DF0 001B5DF0 ACB3828F */  lw         $2, -0x4C54($28)
    /* B5DF4 001B5DF4 D00D40AC */  sw         $0, 0xDD0($2)
    /* B5DF8 001B5DF8 ACB3838F */  lw         $3, -0x4C54($28)
    /* B5DFC 001B5DFC 650C6290 */  lbu        $2, 0xC65($3)
    /* B5E00 001B5E00 01000424 */  addiu      $4, $0, 0x1
    /* B5E04 001B5E04 08004414 */  bne        $2, $4, .L001B5E28
    /* B5E08 001B5E08 00000000 */   nop
    /* B5E0C 001B5E0C 0C00628C */  lw         $2, 0xC($3)
    /* B5E10 001B5E10 00044230 */  andi       $2, $2, 0x400
    /* B5E14 001B5E14 04004010 */  beqz       $2, .L001B5E28
    /* B5E18 001B5E18 00000000 */   nop
    /* B5E1C 001B5E1C 0C000524 */  addiu      $5, $0, 0xC
    /* B5E20 001B5E20 9089040C */  jal        func_00122640
    /* B5E24 001B5E24 00000000 */   nop
  .L001B5E28:
    /* B5E28 001B5E28 11000224 */  addiu      $2, $0, 0x11
  .L001B5E2C:
    /* B5E2C 001B5E2C 0000BFDF */  ld         $31, 0x0($29)
    /* B5E30 001B5E30 1000BD27 */  addiu      $29, $29, 0x10
    /* B5E34 001B5E34 0800E003 */  jr         $31
    /* B5E38 001B5E38 00000000 */   nop
    /* B5E3C 001B5E3C 00000000 */  nop
.size func_001b5db0, 0x90
