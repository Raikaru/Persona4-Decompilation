.section .text
.set noat
.set noreorder
glabel func_001e6d20
    /* E6D20 001E6D20 E0FFBD27 */  addiu      $29, $29, -0x20
    /* E6D24 001E6D24 1000BFFF */  sd         $31, 0x10($29)
    /* E6D28 001E6D28 0000B07F */  sq         $16, 0x0($29)
    /* E6D2C 001E6D2C 2D200000 */  daddu      $4, $0, $0
    /* E6D30 001E6D30 00730A0C */  jal        func_0029cc00
    /* E6D34 001E6D34 00000000 */   nop
    /* E6D38 001E6D38 FFFF5030 */  andi       $16, $2, 0xFFFF
    /* E6D3C 001E6D3C 01000424 */  addiu      $4, $0, 0x1
    /* E6D40 001E6D40 00730A0C */  jal        func_0029cc00
    /* E6D44 001E6D44 00000000 */   nop
    /* E6D48 001E6D48 FFFF4430 */  andi       $4, $2, 0xFFFF
    /* E6D4C 001E6D4C 2D100000 */  daddu      $2, $0, $0
    /* E6D50 001E6D50 FFFF0332 */  andi       $3, $16, 0xFFFF
    /* E6D54 001E6D54 01000524 */  addiu      $5, $0, 0x1
    /* E6D58 001E6D58 0A006510 */  beq        $3, $5, .L001E6D84
    /* E6D5C 001E6D5C 00000000 */   nop
    /* E6D60 001E6D60 03006010 */  beqz       $3, .L001E6D70
    /* E6D64 001E6D64 00000000 */   nop
    /* E6D68 001E6D68 0A000010 */  b          .L001E6D94
    /* E6D6C 001E6D6C 00000000 */   nop
  .L001E6D70:
    /* E6D70 001E6D70 2D300000 */  daddu      $6, $0, $0
    /* E6D74 001E6D74 A064070C */  jal        func_001d9280
    /* E6D78 001E6D78 00000000 */   nop
    /* E6D7C 001E6D7C 05000010 */  b          .L001E6D94
    /* E6D80 001E6D80 00000000 */   nop
  .L001E6D84:
    /* E6D84 001E6D84 02000524 */  addiu      $5, $0, 0x2
    /* E6D88 001E6D88 0800063C */  lui        $6, (0x80000 >> 16)
    /* E6D8C 001E6D8C A064070C */  jal        func_001d9280
    /* E6D90 001E6D90 00000000 */   nop
  .L001E6D94:
    /* E6D94 001E6D94 0800438C */  lw         $3, 0x8($2)
    /* E6D98 001E6D98 0080023C */  lui        $2, (0x80000000 >> 16)
    /* E6D9C 001E6D9C 25206200 */  or         $4, $3, $2
    /* E6DA0 001E6DA0 D4730A0C */  jal        func_0029cf50
    /* E6DA4 001E6DA4 00000000 */   nop
    /* E6DA8 001E6DA8 01000224 */  addiu      $2, $0, 0x1
    /* E6DAC 001E6DAC 1000BFDF */  ld         $31, 0x10($29)
    /* E6DB0 001E6DB0 0000B07B */  lq         $16, 0x0($29)
    /* E6DB4 001E6DB4 2000BD27 */  addiu      $29, $29, 0x20
    /* E6DB8 001E6DB8 0800E003 */  jr         $31
    /* E6DBC 001E6DBC 00000000 */   nop
.size func_001e6d20, 0xa0
