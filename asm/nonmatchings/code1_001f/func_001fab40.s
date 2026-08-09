.section .text
.set noat
.set noreorder
glabel func_001fab40
    /* FAB40 001FAB40 F0FFBD27 */  addiu      $29, $29, -0x10
    /* FAB44 001FAB44 0000BFFF */  sd         $31, 0x0($29)
    /* FAB48 001FAB48 ACB3828F */  lw         $2, -0x4C54($28)
    /* FAB4C 001FAB4C 0C00438C */  lw         $3, 0xC($2)
    /* FAB50 001FAB50 2000023C */  lui        $2, (0x200000 >> 16)
    /* FAB54 001FAB54 24106200 */  and        $2, $3, $2
    /* FAB58 001FAB58 06004010 */  beqz       $2, .L001FAB74
    /* FAB5C 001FAB5C 00000000 */   nop
    /* FAB60 001FAB60 01000524 */  addiu      $5, $0, 0x1
    /* FAB64 001FAB64 B4AE080C */  jal        func_0022bad0
    /* FAB68 001FAB68 00000000 */   nop
    /* FAB6C 001FAB6C 02000010 */  b          .L001FAB78
    /* FAB70 001FAB70 00000000 */   nop
  .L001FAB74:
    /* FAB74 001FAB74 2D100000 */  daddu      $2, $0, $0
  .L001FAB78:
    /* FAB78 001FAB78 0000BFDF */  ld         $31, 0x0($29)
    /* FAB7C 001FAB7C 1000BD27 */  addiu      $29, $29, 0x10
    /* FAB80 001FAB80 0800E003 */  jr         $31
    /* FAB84 001FAB84 00000000 */   nop
    /* FAB88 001FAB88 00000000 */  nop
    /* FAB8C 001FAB8C 00000000 */  nop
.size func_001fab40, 0x50
