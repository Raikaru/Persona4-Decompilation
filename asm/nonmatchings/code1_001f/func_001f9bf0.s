.section .text
.set noat
.set noreorder
glabel func_001f9bf0
    /* F9BF0 001F9BF0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* F9BF4 001F9BF4 0000BFFF */  sd         $31, 0x0($29)
    /* F9BF8 001F9BF8 ACB3828F */  lw         $2, -0x4C54($28)
    /* F9BFC 001F9BFC 2C0B4424 */  addiu      $4, $2, 0xB2C
    /* F9C00 001F9C00 2D280000 */  daddu      $5, $0, $0
    /* F9C04 001F9C04 14000624 */  addiu      $6, $0, 0x14
    /* F9C08 001F9C08 72FE100C */  jal        func_0043f9c8
    /* F9C0C 001F9C0C 00000000 */   nop
    /* F9C10 001F9C10 03000424 */  addiu      $4, $0, 0x3
    /* F9C14 001F9C14 ACB3838F */  lw         $3, -0x4C54($28)
    /* F9C18 001F9C18 300B64A4 */  sh         $4, 0xB30($3)
    /* F9C1C 001F9C1C ACB3838F */  lw         $3, -0x4C54($28)
    /* F9C20 001F9C20 3A0B60A4 */  sh         $0, 0xB3A($3)
    /* F9C24 001F9C24 0000BFDF */  ld         $31, 0x0($29)
    /* F9C28 001F9C28 1000BD27 */  addiu      $29, $29, 0x10
    /* F9C2C 001F9C2C 0800E003 */  jr         $31
    /* F9C30 001F9C30 00000000 */   nop
    /* F9C34 001F9C34 00000000 */  nop
    /* F9C38 001F9C38 00000000 */  nop
    /* F9C3C 001F9C3C 00000000 */  nop
.size func_001f9bf0, 0x50
