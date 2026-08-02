.section .text
.set noat
.set noreorder
glabel func_001e3f10
    /* E3F10 001E3F10 E0FFBD27 */  addiu      $29, $29, -0x20
    /* E3F14 001E3F14 1000BFFF */  sd         $31, 0x10($29)
    /* E3F18 001E3F18 0000B07F */  sq         $16, 0x0($29)
    /* E3F1C 001E3F1C 2D200000 */  daddu      $4, $0, $0
    /* E3F20 001E3F20 00730A0C */  jal        func_0029cc00
    /* E3F24 001E3F24 00000000 */   nop
    /* E3F28 001E3F28 FFFF5030 */  andi       $16, $2, 0xFFFF
    /* E3F2C 001E3F2C 01000424 */  addiu      $4, $0, 0x1
    /* E3F30 001E3F30 00730A0C */  jal        func_0029cc00
    /* E3F34 001E3F34 00000000 */   nop
    /* E3F38 001E3F38 FFFF4430 */  andi       $4, $2, 0xFFFF
    /* E3F3C 001E3F3C 2D100000 */  daddu      $2, $0, $0
    /* E3F40 001E3F40 FFFF0332 */  andi       $3, $16, 0xFFFF
    /* E3F44 001E3F44 01000524 */  addiu      $5, $0, 0x1
    /* E3F48 001E3F48 0A006510 */  beq        $3, $5, .L001E3F74
    /* E3F4C 001E3F4C 00000000 */   nop
    /* E3F50 001E3F50 03006010 */  beqz       $3, .L001E3F60
    /* E3F54 001E3F54 00000000 */   nop
    /* E3F58 001E3F58 0A000010 */  b          .L001E3F84
    /* E3F5C 001E3F5C 00000000 */   nop
  .L001E3F60:
    /* E3F60 001E3F60 0800063C */  lui        $6, (0x80000 >> 16)
    /* E3F64 001E3F64 A064070C */  jal        func_001d9280
    /* E3F68 001E3F68 00000000 */   nop
    /* E3F6C 001E3F6C 05000010 */  b          .L001E3F84
    /* E3F70 001E3F70 00000000 */   nop
  .L001E3F74:
    /* E3F74 001E3F74 02000524 */  addiu      $5, $0, 0x2
    /* E3F78 001E3F78 0800063C */  lui        $6, (0x80000 >> 16)
    /* E3F7C 001E3F7C A064070C */  jal        func_001d9280
    /* E3F80 001E3F80 00000000 */   nop
  .L001E3F84:
    /* E3F84 001E3F84 06004010 */  beqz       $2, .L001E3FA0
    /* E3F88 001E3F88 00000000 */   nop
    /* E3F8C 001E3F8C 18004294 */  lhu        $2, 0x18($2)
    /* E3F90 001E3F90 00184230 */  andi       $2, $2, 0x1800
    /* E3F94 001E3F94 2B100200 */  sltu       $2, $0, $2
    /* E3F98 001E3F98 02000010 */  b          .L001E3FA4
    /* E3F9C 001E3F9C 00000000 */   nop
  .L001E3FA0:
    /* E3FA0 001E3FA0 2D100000 */  daddu      $2, $0, $0
  .L001E3FA4:
    /* E3FA4 001E3FA4 2B200200 */  sltu       $4, $0, $2
    /* E3FA8 001E3FA8 D4730A0C */  jal        func_0029cf50
    /* E3FAC 001E3FAC 00000000 */   nop
    /* E3FB0 001E3FB0 01000224 */  addiu      $2, $0, 0x1
    /* E3FB4 001E3FB4 1000BFDF */  ld         $31, 0x10($29)
    /* E3FB8 001E3FB8 0000B07B */  lq         $16, 0x0($29)
    /* E3FBC 001E3FBC 2000BD27 */  addiu      $29, $29, 0x20
    /* E3FC0 001E3FC0 0800E003 */  jr         $31
    /* E3FC4 001E3FC4 00000000 */   nop
    /* E3FC8 001E3FC8 00000000 */  nop
    /* E3FCC 001E3FCC 00000000 */  nop
.size func_001e3f10, 0xc0
