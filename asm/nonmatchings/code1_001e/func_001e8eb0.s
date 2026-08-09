.section .text
.set noat
.set noreorder
glabel func_001e8eb0
    /* E8EB0 001E8EB0 A0FFBD27 */  addiu      $29, $29, -0x60
    /* E8EB4 001E8EB4 5000BFFF */  sd         $31, 0x50($29)
    /* E8EB8 001E8EB8 4000B47F */  sq         $20, 0x40($29)
    /* E8EBC 001E8EBC 3000B37F */  sq         $19, 0x30($29)
    /* E8EC0 001E8EC0 2000B27F */  sq         $18, 0x20($29)
    /* E8EC4 001E8EC4 1000B17F */  sq         $17, 0x10($29)
    /* E8EC8 001E8EC8 0000B07F */  sq         $16, 0x0($29)
    /* E8ECC 001E8ECC 14740A0C */  jal        func_0029d050
    /* E8ED0 001E8ED0 00000000 */   nop
    /* E8ED4 001E8ED4 2DA04000 */  daddu      $20, $2, $0
    /* E8ED8 001E8ED8 2D200000 */  daddu      $4, $0, $0
    /* E8EDC 001E8EDC 00730A0C */  jal        func_0029cc00
    /* E8EE0 001E8EE0 00000000 */   nop
    /* E8EE4 001E8EE4 2D208002 */  daddu      $4, $20, $0
    /* E8EE8 001E8EE8 2D284000 */  daddu      $5, $2, $0
    /* E8EEC 001E8EEC 2D300000 */  daddu      $6, $0, $0
    /* E8EF0 001E8EF0 2C000724 */  addiu      $7, $0, 0x2C
    /* E8EF4 001E8EF4 2D400000 */  daddu      $8, $0, $0
    /* E8EF8 001E8EF8 1E00093C */  lui        $9, %hi(func_001db580)
    /* E8EFC 001E8EFC 80B52925 */  addiu      $9, $9, %lo(func_001db580)
    /* E8F00 001E8F00 E86E070C */  jal        func_001dbba0
    /* E8F04 001E8F04 00000000 */   nop
    /* E8F08 001E8F08 01000324 */  addiu      $3, $0, 0x1
    /* E8F0C 001E8F0C 26004314 */  bne        $2, $3, .L001E8FA8
    /* E8F10 001E8F10 00000000 */   nop
    /* E8F14 001E8F14 6A008296 */  lhu        $2, 0x6A($20)
    /* E8F18 001E8F18 04004314 */  bne        $2, $3, .L001E8F2C
    /* E8F1C 001E8F1C 00000000 */   nop
    /* E8F20 001E8F20 3800938E */  lw         $19, 0x38($20)
    /* E8F24 001E8F24 19000010 */  b          .L001E8F8C
    /* E8F28 001E8F28 00000000 */   nop
  .L001E8F2C:
    /* E8F2C 001E8F2C 2D980000 */  daddu      $19, $0, $0
    /* E8F30 001E8F30 FF0F023C */  lui        $2, (0xFFFFFFF >> 16)
    /* E8F34 001E8F34 FFFF5034 */  ori        $16, $2, (0xFFFFFFF & 0xFFFF)
    /* E8F38 001E8F38 2D880000 */  daddu      $17, $0, $0
    /* E8F3C 001E8F3C 0F000010 */  b          .L001E8F7C
    /* E8F40 001E8F40 00000000 */   nop
  .L001E8F44:
    /* E8F44 001E8F44 80101100 */  sll        $2, $17, 2
    /* E8F48 001E8F48 21108202 */  addu       $2, $20, $2
    /* E8F4C 001E8F4C 3800528C */  lw         $18, 0x38($2)
    /* E8F50 001E8F50 3000428E */  lw         $2, 0x30($18)
    /* E8F54 001E8F54 640A448C */  lw         $4, 0xA64($2)
    /* E8F58 001E8F58 B4C7080C */  jal        func_00231ed0
    /* E8F5C 001E8F5C 00000000 */   nop
    /* E8F60 001E8F60 FFFF4230 */  andi       $2, $2, 0xFFFF
    /* E8F64 001E8F64 2B085000 */  sltu       $1, $2, $16
    /* E8F68 001E8F68 03002010 */  beqz       $1, .L001E8F78
    /* E8F6C 001E8F6C 00000000 */   nop
    /* E8F70 001E8F70 2D984002 */  daddu      $19, $18, $0
    /* E8F74 001E8F74 2D804000 */  daddu      $16, $2, $0
  .L001E8F78:
    /* E8F78 001E8F78 01003126 */  addiu      $17, $17, 0x1
  .L001E8F7C:
    /* E8F7C 001E8F7C 6A008296 */  lhu        $2, 0x6A($20)
    /* E8F80 001E8F80 2B102202 */  sltu       $2, $17, $2
    /* E8F84 001E8F84 EFFF4014 */  bnez       $2, .L001E8F44
    /* E8F88 001E8F88 00000000 */   nop
  .L001E8F8C:
    /* E8F8C 001E8F8C 0800638E */  lw         $3, 0x8($19)
    /* E8F90 001E8F90 0080023C */  lui        $2, (0x80000000 >> 16)
    /* E8F94 001E8F94 25206200 */  or         $4, $3, $2
    /* E8F98 001E8F98 D4730A0C */  jal        func_0029cf50
    /* E8F9C 001E8F9C 00000000 */   nop
    /* E8FA0 001E8FA0 04000010 */  b          .L001E8FB4
    /* E8FA4 001E8FA4 00000000 */   nop
  .L001E8FA8:
    /* E8FA8 001E8FA8 FFFF0424 */  addiu      $4, $0, -0x1
    /* E8FAC 001E8FAC D4730A0C */  jal        func_0029cf50
    /* E8FB0 001E8FB0 00000000 */   nop
  .L001E8FB4:
    /* E8FB4 001E8FB4 01000224 */  addiu      $2, $0, 0x1
    /* E8FB8 001E8FB8 5000BFDF */  ld         $31, 0x50($29)
    /* E8FBC 001E8FBC 4000B47B */  lq         $20, 0x40($29)
    /* E8FC0 001E8FC0 3000B37B */  lq         $19, 0x30($29)
    /* E8FC4 001E8FC4 2000B27B */  lq         $18, 0x20($29)
    /* E8FC8 001E8FC8 1000B17B */  lq         $17, 0x10($29)
    /* E8FCC 001E8FCC 0000B07B */  lq         $16, 0x0($29)
    /* E8FD0 001E8FD0 6000BD27 */  addiu      $29, $29, 0x60
    /* E8FD4 001E8FD4 0800E003 */  jr         $31
    /* E8FD8 001E8FD8 00000000 */   nop
    /* E8FDC 001E8FDC 00000000 */  nop
.size func_001e8eb0, 0x130
