.section .text
.set noat
.set noreorder
glabel func_0042a870
    /* 32A870 0042A870 C0FFBD27 */  addiu      $29, $29, -0x40
    /* 32A874 0042A874 2000B1FF */  sd         $17, 0x20($29)
    /* 32A878 0042A878 3000BFFF */  sd         $31, 0x30($29)
    /* 32A87C 0042A87C 2D888000 */  daddu      $17, $4, $0
    /* 32A880 0042A880 5AA8100C */  jal        func_0042a168
    /* 32A884 0042A884 1000B0FF */   sd        $16, 0x10($29)
    /* 32A888 0042A888 18004004 */  bltz       $2, .L0042A8EC
    /* 32A88C 0042A88C FFFF023C */   lui       $2, (0xFFFF0000 >> 16)
    /* 32A890 0042A890 9AA8100C */  jal        func_0042a268
    /* 32A894 0042A894 00000000 */   nop
    /* 32A898 0042A898 04004010 */  beqz       $2, .L0042A8AC
    /* 32A89C 0042A89C 8900103C */   lui       $16, %hi(D_00891140)
    /* 32A8A0 0042A8A0 FEFF023C */  lui        $2, (0xFFFEFFFC >> 16)
    /* 32A8A4 0042A8A4 11000010 */  b          .L0042A8EC
    /* 32A8A8 0042A8A8 FCFF4234 */   ori       $2, $2, (0xFFFEFFFC & 0xFFFF)
  .L0042A8AC:
    /* 32A8AC 0042A8AC 8900043C */  lui        $4, %hi(D_00891340)
    /* 32A8B0 0042A8B0 40110726 */  addiu      $7, $16, %lo(D_00891140)
    /* 32A8B4 0042A8B4 401111AE */  sw         $17, %lo(D_00891140)($16)
    /* 32A8B8 0042A8B8 40138424 */  addiu      $4, $4, %lo(D_00891340)
    /* 32A8BC 0042A8BC 0000A0AF */  sw         $0, 0x0($29)
    /* 32A8C0 0042A8C0 0A000524 */  addiu      $5, $0, 0xA
    /* 32A8C4 0042A8C4 2D300000 */  daddu      $6, $0, $0
    /* 32A8C8 0042A8C8 04000824 */  addiu      $8, $0, 0x4
    /* 32A8CC 0042A8CC 2D48E000 */  daddu      $9, $7, $0
    /* 32A8D0 0042A8D0 04000A24 */  addiu      $10, $0, 0x4
    /* 32A8D4 0042A8D4 2C96100C */  jal        func_004258b0
    /* 32A8D8 0042A8D8 2D580000 */   daddu     $11, $0, $0
    /* 32A8DC 0042A8DC 03004304 */  bgezl      $2, .L0042A8EC
    /* 32A8E0 0042A8E0 4011028E */   lw        $2, %lo(D_00891140)($16)
    /* 32A8E4 0042A8E4 FEFF023C */  lui        $2, (0xFFFEFFFF >> 16)
    /* 32A8E8 0042A8E8 FFFF4234 */  ori        $2, $2, (0xFFFEFFFF & 0xFFFF)
  .L0042A8EC:
    /* 32A8EC 0042A8EC 3000BFDF */  ld         $31, 0x30($29)
    /* 32A8F0 0042A8F0 2000B1DF */  ld         $17, 0x20($29)
    /* 32A8F4 0042A8F4 1000B0DF */  ld         $16, 0x10($29)
    /* 32A8F8 0042A8F8 0800E003 */  jr         $31
    /* 32A8FC 0042A8FC 4000BD27 */   addiu     $29, $29, 0x40
.size func_0042a870, 0x90
