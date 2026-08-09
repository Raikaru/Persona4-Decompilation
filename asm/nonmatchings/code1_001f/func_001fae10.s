.section .text
.set noat
.set noreorder
glabel func_001fae10
    /* FAE10 001FAE10 F0FFBD27 */  addiu      $29, $29, -0x10
    /* FAE14 001FAE14 0000BFFF */  sd         $31, 0x0($29)
    /* FAE18 001FAE18 ACB3828F */  lw         $2, -0x4C54($28)
    /* FAE1C 001FAE1C 0C00438C */  lw         $3, 0xC($2)
    /* FAE20 001FAE20 2000023C */  lui        $2, (0x200000 >> 16)
    /* FAE24 001FAE24 24106200 */  and        $2, $3, $2
    /* FAE28 001FAE28 06004010 */  beqz       $2, .L001FAE44
    /* FAE2C 001FAE2C 00000000 */   nop
    /* FAE30 001FAE30 04000424 */  addiu      $4, $0, 0x4
    /* FAE34 001FAE34 20AF080C */  jal        func_0022bc80
    /* FAE38 001FAE38 00000000 */   nop
    /* FAE3C 001FAE3C 02000010 */  b          .L001FAE48
    /* FAE40 001FAE40 00000000 */   nop
  .L001FAE44:
    /* FAE44 001FAE44 2D100000 */  daddu      $2, $0, $0
  .L001FAE48:
    /* FAE48 001FAE48 0000BFDF */  ld         $31, 0x0($29)
    /* FAE4C 001FAE4C 1000BD27 */  addiu      $29, $29, 0x10
    /* FAE50 001FAE50 0800E003 */  jr         $31
    /* FAE54 001FAE54 00000000 */   nop
    /* FAE58 001FAE58 00000000 */  nop
    /* FAE5C 001FAE5C 00000000 */  nop
.size func_001fae10, 0x50
