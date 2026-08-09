.section .text
.set noat
.set noreorder
glabel func_001fab90
    /* FAB90 001FAB90 F0FFBD27 */  addiu      $29, $29, -0x10
    /* FAB94 001FAB94 0000BFFF */  sd         $31, 0x0($29)
    /* FAB98 001FAB98 ACB3828F */  lw         $2, -0x4C54($28)
    /* FAB9C 001FAB9C 0C00438C */  lw         $3, 0xC($2)
    /* FABA0 001FABA0 2000023C */  lui        $2, (0x200000 >> 16)
    /* FABA4 001FABA4 24106200 */  and        $2, $3, $2
    /* FABA8 001FABA8 06004010 */  beqz       $2, .L001FABC4
    /* FABAC 001FABAC 00000000 */   nop
    /* FABB0 001FABB0 01000424 */  addiu      $4, $0, 0x1
    /* FABB4 001FABB4 20AF080C */  jal        func_0022bc80
    /* FABB8 001FABB8 00000000 */   nop
    /* FABBC 001FABBC 02000010 */  b          .L001FABC8
    /* FABC0 001FABC0 00000000 */   nop
  .L001FABC4:
    /* FABC4 001FABC4 2D100000 */  daddu      $2, $0, $0
  .L001FABC8:
    /* FABC8 001FABC8 0000BFDF */  ld         $31, 0x0($29)
    /* FABCC 001FABCC 1000BD27 */  addiu      $29, $29, 0x10
    /* FABD0 001FABD0 0800E003 */  jr         $31
    /* FABD4 001FABD4 00000000 */   nop
    /* FABD8 001FABD8 00000000 */  nop
    /* FABDC 001FABDC 00000000 */  nop
.size func_001fab90, 0x50
