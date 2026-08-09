.section .text
.set noat
.set noreorder
glabel func_001eb860
    /* EB860 001EB860 F0FFBD27 */  addiu      $29, $29, -0x10
    /* EB864 001EB864 0000BFFF */  sd         $31, 0x0($29)
    /* EB868 001EB868 ACB3838F */  lw         $3, -0x4C54($28)
    /* EB86C 001EB86C 0C00628C */  lw         $2, 0xC($3)
    /* EB870 001EB870 80004230 */  andi       $2, $2, 0x80
    /* EB874 001EB874 04004010 */  beqz       $2, .L001EB888
    /* EB878 001EB878 00000000 */   nop
    /* EB87C 001EB87C 2D100000 */  daddu      $2, $0, $0
    /* EB880 001EB880 0D000010 */  b          .L001EB8B8
    /* EB884 001EB884 00000000 */   nop
  .L001EB888:
    /* EB888 001EB888 680C628C */  lw         $2, 0xC68($3)
    /* EB88C 001EB88C 09004010 */  beqz       $2, .L001EB8B4
    /* EB890 001EB890 00000000 */   nop
    /* EB894 001EB894 68BE070C */  jal        func_001ef9a0
    /* EB898 001EB898 00000000 */   nop
    /* EB89C 001EB89C 15020324 */  addiu      $3, $0, 0x215
    /* EB8A0 001EB8A0 04004314 */  bne        $2, $3, .L001EB8B4
    /* EB8A4 001EB8A4 00000000 */   nop
    /* EB8A8 001EB8A8 2D100000 */  daddu      $2, $0, $0
    /* EB8AC 001EB8AC 02000010 */  b          .L001EB8B8
    /* EB8B0 001EB8B0 00000000 */   nop
  .L001EB8B4:
    /* EB8B4 001EB8B4 01000224 */  addiu      $2, $0, 0x1
  .L001EB8B8:
    /* EB8B8 001EB8B8 0000BFDF */  ld         $31, 0x0($29)
    /* EB8BC 001EB8BC 1000BD27 */  addiu      $29, $29, 0x10
    /* EB8C0 001EB8C0 0800E003 */  jr         $31
    /* EB8C4 001EB8C4 00000000 */   nop
    /* EB8C8 001EB8C8 00000000 */  nop
    /* EB8CC 001EB8CC 00000000 */  nop
.size func_001eb860, 0x70
