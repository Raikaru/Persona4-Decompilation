.section .text
.set noat
.set noreorder
glabel func_003b7ca0
    /* 2B7CA0 003B7CA0 B0FFBD27 */  addiu      $29, $29, -0x50
    /* 2B7CA4 003B7CA4 8800023C */  lui        $2, %hi(D_00886498)
    /* 2B7CA8 003B7CA8 3000BFFF */  sd         $31, 0x30($29)
    /* 2B7CAC 003B7CAC 2000B27F */  sq         $18, 0x20($29)
    /* 2B7CB0 003B7CB0 1000B17F */  sq         $17, 0x10($29)
    /* 2B7CB4 003B7CB4 0000B07F */  sq         $16, 0x0($29)
    /* 2B7CB8 003B7CB8 9864428C */  lw         $2, %lo(D_00886498)($2)
    /* 2B7CBC 003B7CBC 2110C200 */  addu       $2, $6, $2
    /* 2B7CC0 003B7CC0 0000518C */  lw         $17, 0x0($2)
    /* 2B7CC4 003B7CC4 47002012 */  beqz       $17, .L003B7DE4
    /* 2B7CC8 003B7CC8 2D908000 */   daddu     $18, $4, $0
    /* 2B7CCC 003B7CCC 0800C38C */  lw         $3, 0x8($6)
    /* 2B7CD0 003B7CD0 0001023C */  lui        $2, (0x1000000 >> 16)
    /* 2B7CD4 003B7CD4 24106200 */  and        $2, $3, $2
    /* 2B7CD8 003B7CD8 07004010 */  beqz       $2, .L003B7CF8
    /* 2B7CDC 003B7CDC 00000000 */   nop
    /* 2B7CE0 003B7CE0 4CE20E0C */  jal        func_003b8930
    /* 2B7CE4 003B7CE4 2D28C000 */   daddu     $5, $6, $0
    /* 2B7CE8 003B7CE8 3E004014 */  bnez       $2, .L003B7DE4
    /* 2B7CEC 003B7CEC 00000000 */   nop
    /* 2B7CF0 003B7CF0 3D000010 */  b          .L003B7DE8
    /* 2B7CF4 003B7CF4 2D100000 */   daddu     $2, $0, $0
  .L003B7CF8:
    /* 2B7CF8 003B7CF8 1000288E */  lw         $8, 0x10($17)
    /* 2B7CFC 003B7CFC FF00073C */  lui        $7, (0xFF0000 >> 16)
    /* 2B7D00 003B7D00 0400238E */  lw         $3, 0x4($17)
    /* 2B7D04 003B7D04 4C00A527 */  addiu      $5, $29, 0x4C
    /* 2B7D08 003B7D08 1400D08C */  lw         $16, 0x14($6)
    /* 2B7D0C 003B7D0C 00002292 */  lbu        $2, 0x0($17)
    /* 2B7D10 003B7D10 00440800 */  sll        $8, $8, 16
    /* 2B7D14 003B7D14 001A0300 */  sll        $3, $3, 8
    /* 2B7D18 003B7D18 24380701 */  and        $7, $8, $7
    /* 2B7D1C 003B7D1C 00FF6330 */  andi       $3, $3, 0xFF00
    /* 2B7D20 003B7D20 04000624 */  addiu      $6, $0, 0x4
    /* 2B7D24 003B7D24 2518E300 */  or         $3, $7, $3
    /* 2B7D28 003B7D28 25104300 */  or         $2, $2, $3
    /* 2B7D2C 003B7D2C 907C0F0C */  jal        func_003df240
    /* 2B7D30 003B7D30 4C00A2AF */   sw        $2, 0x4C($29)
    /* 2B7D34 003B7D34 21004010 */  beqz       $2, .L003B7DBC
    /* 2B7D38 003B7D38 00000000 */   nop
    /* 2B7D3C 003B7D3C 0800258E */  lw         $5, 0x8($17)
    /* 2B7D40 003B7D40 0400268E */  lw         $6, 0x4($17)
    /* 2B7D44 003B7D44 AC8A0F0C */  jal        func_003e2ab0
    /* 2B7D48 003B7D48 2D204002 */   daddu     $4, $18, $0
    /* 2B7D4C 003B7D4C 1D004010 */  beqz       $2, .L003B7DC4
    /* 2B7D50 003B7D50 00000000 */   nop
    /* 2B7D54 003B7D54 1400258E */  lw         $5, 0x14($17)
    /* 2B7D58 003B7D58 80301000 */  sll        $6, $16, 2
    /* 2B7D5C 003B7D5C 907C0F0C */  jal        func_003df240
    /* 2B7D60 003B7D60 2D204002 */   daddu     $4, $18, $0
    /* 2B7D64 003B7D64 19004010 */  beqz       $2, .L003B7DCC
    /* 2B7D68 003B7D68 00000000 */   nop
    /* 2B7D6C 003B7D6C 1800258E */  lw         $5, 0x18($17)
    /* 2B7D70 003B7D70 00311000 */  sll        $6, $16, 4
    /* 2B7D74 003B7D74 687C0F0C */  jal        func_003df1a0
    /* 2B7D78 003B7D78 2D204002 */   daddu     $4, $18, $0
    /* 2B7D7C 003B7D7C 15004010 */  beqz       $2, .L003B7DD4
    /* 2B7D80 003B7D80 00000000 */   nop
    /* 2B7D84 003B7D84 0000228E */  lw         $2, 0x0($17)
    /* 2B7D88 003B7D88 2D204002 */  daddu      $4, $18, $0
    /* 2B7D8C 003B7D8C 0C00258E */  lw         $5, 0xC($17)
    /* 2B7D90 003B7D90 687C0F0C */  jal        func_003df1a0
    /* 2B7D94 003B7D94 80310200 */   sll       $6, $2, 6
    /* 2B7D98 003B7D98 10004010 */  beqz       $2, .L003B7DDC
    /* 2B7D9C 003B7D9C 00000000 */   nop
    /* 2B7DA0 003B7DA0 2D282002 */  daddu      $5, $17, $0
    /* 2B7DA4 003B7DA4 6CDC0E0C */  jal        func_003b71b0
    /* 2B7DA8 003B7DA8 2D204002 */   daddu     $4, $18, $0
    /* 2B7DAC 003B7DAC 0D004014 */  bnez       $2, .L003B7DE4
    /* 2B7DB0 003B7DB0 00000000 */   nop
    /* 2B7DB4 003B7DB4 0C000010 */  b          .L003B7DE8
    /* 2B7DB8 003B7DB8 2D100000 */   daddu     $2, $0, $0
  .L003B7DBC:
    /* 2B7DBC 003B7DBC 0A000010 */  b          .L003B7DE8
    /* 2B7DC0 003B7DC0 2D100000 */   daddu     $2, $0, $0
  .L003B7DC4:
    /* 2B7DC4 003B7DC4 08000010 */  b          .L003B7DE8
    /* 2B7DC8 003B7DC8 2D100000 */   daddu     $2, $0, $0
  .L003B7DCC:
    /* 2B7DCC 003B7DCC 06000010 */  b          .L003B7DE8
    /* 2B7DD0 003B7DD0 2D100000 */   daddu     $2, $0, $0
  .L003B7DD4:
    /* 2B7DD4 003B7DD4 04000010 */  b          .L003B7DE8
    /* 2B7DD8 003B7DD8 2D100000 */   daddu     $2, $0, $0
  .L003B7DDC:
    /* 2B7DDC 003B7DDC 02000010 */  b          .L003B7DE8
    /* 2B7DE0 003B7DE0 2D100000 */   daddu     $2, $0, $0
  .L003B7DE4:
    /* 2B7DE4 003B7DE4 2D104002 */  daddu      $2, $18, $0
  .L003B7DE8:
    /* 2B7DE8 003B7DE8 3000BFDF */  ld         $31, 0x30($29)
    /* 2B7DEC 003B7DEC 2000B27B */  lq         $18, 0x20($29)
    /* 2B7DF0 003B7DF0 1000B17B */  lq         $17, 0x10($29)
    /* 2B7DF4 003B7DF4 0000B07B */  lq         $16, 0x0($29)
    /* 2B7DF8 003B7DF8 0800E003 */  jr         $31
    /* 2B7DFC 003B7DFC 5000BD27 */   addiu     $29, $29, 0x50
.size func_003b7ca0, 0x160
