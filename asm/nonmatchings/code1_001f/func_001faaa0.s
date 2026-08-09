.section .text
.set noat
.set noreorder
glabel func_001faaa0
    /* FAAA0 001FAAA0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* FAAA4 001FAAA4 0000BFFF */  sd         $31, 0x0($29)
    /* FAAA8 001FAAA8 ACB3828F */  lw         $2, -0x4C54($28)
    /* FAAAC 001FAAAC 0C00438C */  lw         $3, 0xC($2)
    /* FAAB0 001FAAB0 2000023C */  lui        $2, (0x200000 >> 16)
    /* FAAB4 001FAAB4 24106200 */  and        $2, $3, $2
    /* FAAB8 001FAAB8 06004010 */  beqz       $2, .L001FAAD4
    /* FAABC 001FAABC 00000000 */   nop
    /* FAAC0 001FAAC0 2D280000 */  daddu      $5, $0, $0
    /* FAAC4 001FAAC4 B4AE080C */  jal        func_0022bad0
    /* FAAC8 001FAAC8 00000000 */   nop
    /* FAACC 001FAACC 02000010 */  b          .L001FAAD8
    /* FAAD0 001FAAD0 00000000 */   nop
  .L001FAAD4:
    /* FAAD4 001FAAD4 2D100000 */  daddu      $2, $0, $0
  .L001FAAD8:
    /* FAAD8 001FAAD8 0000BFDF */  ld         $31, 0x0($29)
    /* FAADC 001FAADC 1000BD27 */  addiu      $29, $29, 0x10
    /* FAAE0 001FAAE0 0800E003 */  jr         $31
    /* FAAE4 001FAAE4 00000000 */   nop
    /* FAAE8 001FAAE8 00000000 */  nop
    /* FAAEC 001FAAEC 00000000 */  nop
.size func_001faaa0, 0x50
