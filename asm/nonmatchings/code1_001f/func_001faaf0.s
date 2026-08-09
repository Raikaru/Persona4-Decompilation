.section .text
.set noat
.set noreorder
glabel func_001faaf0
    /* FAAF0 001FAAF0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* FAAF4 001FAAF4 0000BFFF */  sd         $31, 0x0($29)
    /* FAAF8 001FAAF8 ACB3828F */  lw         $2, -0x4C54($28)
    /* FAAFC 001FAAFC 0C00438C */  lw         $3, 0xC($2)
    /* FAB00 001FAB00 2000023C */  lui        $2, (0x200000 >> 16)
    /* FAB04 001FAB04 24106200 */  and        $2, $3, $2
    /* FAB08 001FAB08 06004010 */  beqz       $2, .L001FAB24
    /* FAB0C 001FAB0C 00000000 */   nop
    /* FAB10 001FAB10 2D200000 */  daddu      $4, $0, $0
    /* FAB14 001FAB14 20AF080C */  jal        func_0022bc80
    /* FAB18 001FAB18 00000000 */   nop
    /* FAB1C 001FAB1C 02000010 */  b          .L001FAB28
    /* FAB20 001FAB20 00000000 */   nop
  .L001FAB24:
    /* FAB24 001FAB24 2D100000 */  daddu      $2, $0, $0
  .L001FAB28:
    /* FAB28 001FAB28 0000BFDF */  ld         $31, 0x0($29)
    /* FAB2C 001FAB2C 1000BD27 */  addiu      $29, $29, 0x10
    /* FAB30 001FAB30 0800E003 */  jr         $31
    /* FAB34 001FAB34 00000000 */   nop
    /* FAB38 001FAB38 00000000 */  nop
    /* FAB3C 001FAB3C 00000000 */  nop
.size func_001faaf0, 0x50
