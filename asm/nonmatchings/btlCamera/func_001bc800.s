.section .text
.set noat
.set noreorder
glabel func_001bc800
    /* BC800 001BC800 ACB3838F */  lw         $3, -0x4C54($28)
    /* BC804 001BC804 04016624 */  addiu      $6, $3, 0x104
    /* BC808 001BC808 0401638C */  lw         $3, 0x104($3)
    /* BC80C 001BC80C 30006010 */  beqz       $3, .L001BC8D0
    /* BC810 001BC810 00000000 */   nop
    /* BC814 001BC814 0800658C */  lw         $5, 0x8($3)
    /* BC818 001BC818 0800838C */  lw         $3, 0x8($4)
    /* BC81C 001BC81C 0200A314 */  bne        $5, $3, .L001BC828
    /* BC820 001BC820 00000000 */   nop
    /* BC824 001BC824 0000C0AC */  sw         $0, 0x0($6)
  .L001BC828:
    /* BC828 001BC828 ACB3878F */  lw         $7, -0x4C54($28)
    /* BC82C 001BC82C F400E594 */  lhu        $5, 0xF4($7)
    /* BC830 001BC830 2A000324 */  addiu      $3, $0, 0x2A
    /* BC834 001BC834 1D00A310 */  beq        $5, $3, .L001BC8AC
    /* BC838 001BC838 00000000 */   nop
    /* BC83C 001BC83C 13000324 */  addiu      $3, $0, 0x13
    /* BC840 001BC840 1A00A310 */  beq        $5, $3, .L001BC8AC
    /* BC844 001BC844 00000000 */   nop
    /* BC848 001BC848 12000324 */  addiu      $3, $0, 0x12
    /* BC84C 001BC84C 1700A310 */  beq        $5, $3, .L001BC8AC
    /* BC850 001BC850 00000000 */   nop
    /* BC854 001BC854 10000324 */  addiu      $3, $0, 0x10
    /* BC858 001BC858 1400A310 */  beq        $5, $3, .L001BC8AC
    /* BC85C 001BC85C 00000000 */   nop
    /* BC860 001BC860 14000324 */  addiu      $3, $0, 0x14
    /* BC864 001BC864 1100A310 */  beq        $5, $3, .L001BC8AC
    /* BC868 001BC868 00000000 */   nop
    /* BC86C 001BC86C 0D000324 */  addiu      $3, $0, 0xD
    /* BC870 001BC870 0300A310 */  beq        $5, $3, .L001BC880
    /* BC874 001BC874 00000000 */   nop
    /* BC878 001BC878 15000010 */  b          .L001BC8D0
    /* BC87C 001BC87C 00000000 */   nop
  .L001BC880:
    /* BC880 001BC880 2401E624 */  addiu      $6, $7, 0x124
    /* BC884 001BC884 2401E38C */  lw         $3, 0x124($7)
    /* BC888 001BC888 11006010 */  beqz       $3, .L001BC8D0
    /* BC88C 001BC88C 00000000 */   nop
    /* BC890 001BC890 0800658C */  lw         $5, 0x8($3)
    /* BC894 001BC894 0800838C */  lw         $3, 0x8($4)
    /* BC898 001BC898 0D00A314 */  bne        $5, $3, .L001BC8D0
    /* BC89C 001BC89C 00000000 */   nop
    /* BC8A0 001BC8A0 0000C0AC */  sw         $0, 0x0($6)
    /* BC8A4 001BC8A4 0A000010 */  b          .L001BC8D0
    /* BC8A8 001BC8A8 00000000 */   nop
  .L001BC8AC:
    /* BC8AC 001BC8AC 5801E624 */  addiu      $6, $7, 0x158
    /* BC8B0 001BC8B0 5801E38C */  lw         $3, 0x158($7)
    /* BC8B4 001BC8B4 06006010 */  beqz       $3, .L001BC8D0
    /* BC8B8 001BC8B8 00000000 */   nop
    /* BC8BC 001BC8BC 0800658C */  lw         $5, 0x8($3)
    /* BC8C0 001BC8C0 0800838C */  lw         $3, 0x8($4)
    /* BC8C4 001BC8C4 0200A314 */  bne        $5, $3, .L001BC8D0
    /* BC8C8 001BC8C8 00000000 */   nop
    /* BC8CC 001BC8CC 0000C0AC */  sw         $0, 0x0($6)
  .L001BC8D0:
    /* BC8D0 001BC8D0 0800E003 */  jr         $31
    /* BC8D4 001BC8D4 00000000 */   nop
    /* BC8D8 001BC8D8 00000000 */  nop
    /* BC8DC 001BC8DC 00000000 */  nop
.size func_001bc800, 0xe0
