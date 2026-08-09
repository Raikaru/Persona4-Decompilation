.section .text
.set noat
.set noreorder
glabel func_001fabe0
    /* FABE0 001FABE0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* FABE4 001FABE4 0000BFFF */  sd         $31, 0x0($29)
    /* FABE8 001FABE8 ACB3828F */  lw         $2, -0x4C54($28)
    /* FABEC 001FABEC 0C00438C */  lw         $3, 0xC($2)
    /* FABF0 001FABF0 2000023C */  lui        $2, (0x200000 >> 16)
    /* FABF4 001FABF4 24106200 */  and        $2, $3, $2
    /* FABF8 001FABF8 06004010 */  beqz       $2, .L001FAC14
    /* FABFC 001FABFC 00000000 */   nop
    /* FAC00 001FAC00 02000524 */  addiu      $5, $0, 0x2
    /* FAC04 001FAC04 B4AE080C */  jal        func_0022bad0
    /* FAC08 001FAC08 00000000 */   nop
    /* FAC0C 001FAC0C 02000010 */  b          .L001FAC18
    /* FAC10 001FAC10 00000000 */   nop
  .L001FAC14:
    /* FAC14 001FAC14 2D100000 */  daddu      $2, $0, $0
  .L001FAC18:
    /* FAC18 001FAC18 0000BFDF */  ld         $31, 0x0($29)
    /* FAC1C 001FAC1C 1000BD27 */  addiu      $29, $29, 0x10
    /* FAC20 001FAC20 0800E003 */  jr         $31
    /* FAC24 001FAC24 00000000 */   nop
    /* FAC28 001FAC28 00000000 */  nop
    /* FAC2C 001FAC2C 00000000 */  nop
.size func_001fabe0, 0x50
