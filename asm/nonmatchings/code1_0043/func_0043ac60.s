.section .text
.set noat
.set noreorder
glabel func_0043ac60
    /* 33AC60 0043AC60 D0FFBD27 */  addiu      $29, $29, -0x30
    /* 33AC64 0043AC64 8C00023C */  lui        $2, %hi(D_008BDAC0)
    /* 33AC68 0043AC68 1000B0FF */  sd         $16, 0x10($29)
    /* 33AC6C 0043AC6C 8C00043C */  lui        $4, %hi(D_008BD9C0)
    /* 33AC70 0043AC70 C0DA5024 */  addiu      $16, $2, %lo(D_008BDAC0)
    /* 33AC74 0043AC74 0080053C */  lui        $5, (0x80001305 >> 16)
    /* 33AC78 0043AC78 2000BFFF */  sd         $31, 0x20($29)
    /* 33AC7C 0043AC7C C0D98424 */  addiu      $4, $4, %lo(D_008BD9C0)
    /* 33AC80 0043AC80 0000A0AF */  sw         $0, 0x0($29)
    /* 33AC84 0043AC84 0513A534 */  ori        $5, $5, (0x80001305 & 0xFFFF)
    /* 33AC88 0043AC88 2D300000 */  daddu      $6, $0, $0
    /* 33AC8C 0043AC8C 2D380002 */  daddu      $7, $16, $0
    /* 33AC90 0043AC90 90000824 */  addiu      $8, $0, 0x90
    /* 33AC94 0043AC94 2D480002 */  daddu      $9, $16, $0
    /* 33AC98 0043AC98 90000A24 */  addiu      $10, $0, 0x90
    /* 33AC9C 0043AC9C 2C96100C */  jal        func_004258b0
    /* 33ACA0 0043ACA0 2D580000 */   daddu     $11, $0, $0
    /* 33ACA4 0043ACA4 02004304 */  bgezl      $2, .L0043ACB0
    /* 33ACA8 0043ACA8 0400028E */   lw        $2, 0x4($16)
    /* 33ACAC 0043ACAC 2D100000 */  daddu      $2, $0, $0
  .L0043ACB0:
    /* 33ACB0 0043ACB0 2000BFDF */  ld         $31, 0x20($29)
    /* 33ACB4 0043ACB4 1000B0DF */  ld         $16, 0x10($29)
    /* 33ACB8 0043ACB8 0800E003 */  jr         $31
    /* 33ACBC 0043ACBC 3000BD27 */   addiu     $29, $29, 0x30
.size func_0043ac60, 0x60
