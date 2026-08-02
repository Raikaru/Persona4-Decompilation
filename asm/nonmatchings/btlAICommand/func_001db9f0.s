.section .text
.set noat
.set noreorder
glabel func_001db9f0
    /* DB9F0 001DB9F0 D0FFBD27 */  addiu      $29, $29, -0x30
    /* DB9F4 001DB9F4 2000BFFF */  sd         $31, 0x20($29)
    /* DB9F8 001DB9F8 1000B17F */  sq         $17, 0x10($29)
    /* DB9FC 001DB9FC 0000B07F */  sq         $16, 0x0($29)
    /* DBA00 001DBA00 2D88A000 */  daddu      $17, $5, $0
    /* DBA04 001DBA04 3000908C */  lw         $16, 0x30($4)
    /* DBA08 001DBA08 A2000392 */  lbu        $3, 0xA2($16)
    /* DBA0C 001DBA0C 01000224 */  addiu      $2, $0, 0x1
    /* DBA10 001DBA10 10006214 */  bne        $3, $2, .L001DBA54
    /* DBA14 001DBA14 00000000 */   nop
    /* DBA18 001DBA18 3C2C1100 */  dsll32     $5, $17, 16
    /* DBA1C 001DBA1C 3F2C0500 */  dsra32     $5, $5, 16
    /* DBA20 001DBA20 38E7070C */  jal        func_001f9ce0
    /* DBA24 001DBA24 00000000 */   nop
    /* DBA28 001DBA28 0A004014 */  bnez       $2, .L001DBA54
    /* DBA2C 001DBA2C 00000000 */   nop
    /* DBA30 001DBA30 FFFF2532 */  andi       $5, $17, 0xFFFF
    /* DBA34 001DBA34 A4000496 */  lhu        $4, 0xA4($16)
    /* DBA38 001DBA38 083D040C */  jal        func_0010f420
    /* DBA3C 001DBA3C 00000000 */   nop
    /* DBA40 001DBA40 04004014 */  bnez       $2, .L001DBA54
    /* DBA44 001DBA44 00000000 */   nop
    /* DBA48 001DBA48 2D100000 */  daddu      $2, $0, $0
    /* DBA4C 001DBA4C 09000010 */  b          .L001DBA74
    /* DBA50 001DBA50 00000000 */   nop
  .L001DBA54:
    /* DBA54 001DBA54 3C2C1100 */  dsll32     $5, $17, 16
    /* DBA58 001DBA58 3F2C0500 */  dsra32     $5, $5, 16
    /* DBA5C 001DBA5C 640A048E */  lw         $4, 0xA64($16)
    /* DBA60 001DBA60 000A090C */  jal        func_00242800
    /* DBA64 001DBA64 00000000 */   nop
    /* DBA68 001DBA68 0007033C */  lui        $3, (0x7000000 >> 16)
    /* DBA6C 001DBA6C 24104300 */  and        $2, $2, $3
    /* DBA70 001DBA70 2B100200 */  sltu       $2, $0, $2
  .L001DBA74:
    /* DBA74 001DBA74 2000BFDF */  ld         $31, 0x20($29)
    /* DBA78 001DBA78 1000B17B */  lq         $17, 0x10($29)
    /* DBA7C 001DBA7C 0000B07B */  lq         $16, 0x0($29)
    /* DBA80 001DBA80 3000BD27 */  addiu      $29, $29, 0x30
    /* DBA84 001DBA84 0800E003 */  jr         $31
    /* DBA88 001DBA88 00000000 */   nop
    /* DBA8C 001DBA8C 00000000 */  nop
.size func_001db9f0, 0xa0
