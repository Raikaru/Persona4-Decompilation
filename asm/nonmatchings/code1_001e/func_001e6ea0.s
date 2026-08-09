.section .text
.set noat
.set noreorder
glabel func_001e6ea0
    /* E6EA0 001E6EA0 D0FFBD27 */  addiu      $29, $29, -0x30
    /* E6EA4 001E6EA4 2000BFFF */  sd         $31, 0x20($29)
    /* E6EA8 001E6EA8 1000B17F */  sq         $17, 0x10($29)
    /* E6EAC 001E6EAC 0000B07F */  sq         $16, 0x0($29)
    /* E6EB0 001E6EB0 14740A0C */  jal        func_0029d050
    /* E6EB4 001E6EB4 00000000 */   nop
    /* E6EB8 001E6EB8 2D884000 */  daddu      $17, $2, $0
    /* E6EBC 001E6EBC 2D200000 */  daddu      $4, $0, $0
    /* E6EC0 001E6EC0 00730A0C */  jal        func_0029cc00
    /* E6EC4 001E6EC4 00000000 */   nop
    /* E6EC8 001E6EC8 2D804000 */  daddu      $16, $2, $0
    /* E6ECC 001E6ECC 2D202002 */  daddu      $4, $17, $0
    /* E6ED0 001E6ED0 2D280002 */  daddu      $5, $16, $0
    /* E6ED4 001E6ED4 2D300000 */  daddu      $6, $0, $0
    /* E6ED8 001E6ED8 2E000724 */  addiu      $7, $0, 0x2E
    /* E6EDC 001E6EDC 2D400000 */  daddu      $8, $0, $0
    /* E6EE0 001E6EE0 1E00093C */  lui        $9, %hi(func_001da2f0)
    /* E6EE4 001E6EE4 F0A22925 */  addiu      $9, $9, %lo(func_001da2f0)
    /* E6EE8 001E6EE8 E86E070C */  jal        func_001dbba0
    /* E6EEC 001E6EEC 00000000 */   nop
    /* E6EF0 001E6EF0 01000324 */  addiu      $3, $0, 0x1
    /* E6EF4 001E6EF4 20004314 */  bne        $2, $3, .L001E6F78
    /* E6EF8 001E6EF8 00000000 */   nop
    /* E6EFC 001E6EFC 6A002496 */  lhu        $4, 0x6A($17)
    /* E6F00 001E6F00 09008314 */  bne        $4, $3, .L001E6F28
    /* E6F04 001E6F04 00000000 */   nop
    /* E6F08 001E6F08 3800228E */  lw         $2, 0x38($17)
    /* E6F0C 001E6F0C 0800438C */  lw         $3, 0x8($2)
    /* E6F10 001E6F10 0080023C */  lui        $2, (0x80000000 >> 16)
    /* E6F14 001E6F14 25206200 */  or         $4, $3, $2
    /* E6F18 001E6F18 D4730A0C */  jal        func_0029cf50
    /* E6F1C 001E6F1C 00000000 */   nop
    /* E6F20 001E6F20 18000010 */  b          .L001E6F84
    /* E6F24 001E6F24 00000000 */   nop
  .L001E6F28:
    /* E6F28 001E6F28 02000232 */  andi       $2, $16, 0x2
    /* E6F2C 001E6F2C 06004010 */  beqz       $2, .L001E6F48
    /* E6F30 001E6F30 00000000 */   nop
    /* E6F34 001E6F34 2D202002 */  daddu      $4, $17, $0
    /* E6F38 001E6F38 DC78070C */  jal        func_001de370
    /* E6F3C 001E6F3C 00000000 */   nop
    /* E6F40 001E6F40 06000010 */  b          .L001E6F5C
    /* E6F44 001E6F44 00000000 */   nop
  .L001E6F48:
    /* E6F48 001E6F48 5CC7080C */  jal        func_00231d70
    /* E6F4C 001E6F4C 00000000 */   nop
    /* E6F50 001E6F50 80100200 */  sll        $2, $2, 2
    /* E6F54 001E6F54 21105100 */  addu       $2, $2, $17
    /* E6F58 001E6F58 3800428C */  lw         $2, 0x38($2)
  .L001E6F5C:
    /* E6F5C 001E6F5C 0800438C */  lw         $3, 0x8($2)
    /* E6F60 001E6F60 0080023C */  lui        $2, (0x80000000 >> 16)
    /* E6F64 001E6F64 25206200 */  or         $4, $3, $2
    /* E6F68 001E6F68 D4730A0C */  jal        func_0029cf50
    /* E6F6C 001E6F6C 00000000 */   nop
    /* E6F70 001E6F70 04000010 */  b          .L001E6F84
    /* E6F74 001E6F74 00000000 */   nop
  .L001E6F78:
    /* E6F78 001E6F78 FFFF0424 */  addiu      $4, $0, -0x1
    /* E6F7C 001E6F7C D4730A0C */  jal        func_0029cf50
    /* E6F80 001E6F80 00000000 */   nop
  .L001E6F84:
    /* E6F84 001E6F84 01000224 */  addiu      $2, $0, 0x1
    /* E6F88 001E6F88 2000BFDF */  ld         $31, 0x20($29)
    /* E6F8C 001E6F8C 1000B17B */  lq         $17, 0x10($29)
    /* E6F90 001E6F90 0000B07B */  lq         $16, 0x0($29)
    /* E6F94 001E6F94 3000BD27 */  addiu      $29, $29, 0x30
    /* E6F98 001E6F98 0800E003 */  jr         $31
    /* E6F9C 001E6F9C 00000000 */   nop
.size func_001e6ea0, 0x100
