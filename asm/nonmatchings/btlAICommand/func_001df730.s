.section .text
.set noat
.set noreorder
glabel func_001df730
    /* DF730 001DF730 E0FFBD27 */  addiu      $29, $29, -0x20
    /* DF734 001DF734 1000BFFF */  sd         $31, 0x10($29)
    /* DF738 001DF738 0000B07F */  sq         $16, 0x0($29)
    /* DF73C 001DF73C 2D200000 */  daddu      $4, $0, $0
    /* DF740 001DF740 00730A0C */  jal        func_0029cc00
    /* DF744 001DF744 00000000 */   nop
    /* DF748 001DF748 3C1A0200 */  dsll32     $3, $2, 8
    /* DF74C 001DF74C 3E1A0300 */  dsrl32     $3, $3, 8
    /* DF750 001DF750 0007023C */  lui        $2, (0x7000000 >> 16)
    /* DF754 001DF754 25806200 */  or         $16, $3, $2
    /* DF758 001DF758 14740A0C */  jal        func_0029d050
    /* DF75C 001DF75C 00000000 */   nop
    /* DF760 001DF760 00FF033C */  lui        $3, (0xFF000000 >> 16)
    /* DF764 001DF764 24180302 */  and        $3, $16, $3
    /* DF768 001DF768 021E0300 */  srl        $3, $3, 24
    /* DF76C 001DF76C 3C2A1000 */  dsll32     $5, $16, 8
    /* DF770 001DF770 3E2A0500 */  dsrl32     $5, $5, 8
    /* DF774 001DF774 04006014 */  bnez       $3, .L001DF788
    /* DF778 001DF778 00000000 */   nop
    /* DF77C 001DF77C 2D100000 */  daddu      $2, $0, $0
    /* DF780 001DF780 0B000010 */  b          .L001DF7B0
    /* DF784 001DF784 00000000 */   nop
  .L001DF788:
    /* DF788 001DF788 2D204000 */  daddu      $4, $2, $0
    /* DF78C 001DF78C 40100300 */  sll        $2, $3, 1
    /* DF790 001DF790 21104300 */  addu       $2, $2, $3
    /* DF794 001DF794 80180200 */  sll        $3, $2, 2
    /* DF798 001DF798 6100023C */  lui        $2, %hi(D_00609850)
    /* DF79C 001DF79C 50984224 */  addiu      $2, $2, %lo(D_00609850)
    /* DF7A0 001DF7A0 21104300 */  addu       $2, $2, $3
    /* DF7A4 001DF7A4 0000428C */  lw         $2, 0x0($2)
    /* DF7A8 001DF7A8 09F84000 */  jalr       $2
    /* DF7AC 001DF7AC 00000000 */   nop
  .L001DF7B0:
    /* DF7B0 001DF7B0 2B200200 */  sltu       $4, $0, $2
    /* DF7B4 001DF7B4 D4730A0C */  jal        func_0029cf50
    /* DF7B8 001DF7B8 00000000 */   nop
    /* DF7BC 001DF7BC 01000224 */  addiu      $2, $0, 0x1
    /* DF7C0 001DF7C0 1000BFDF */  ld         $31, 0x10($29)
    /* DF7C4 001DF7C4 0000B07B */  lq         $16, 0x0($29)
    /* DF7C8 001DF7C8 2000BD27 */  addiu      $29, $29, 0x20
    /* DF7CC 001DF7CC 0800E003 */  jr         $31
    /* DF7D0 001DF7D0 00000000 */   nop
    /* DF7D4 001DF7D4 00000000 */  nop
    /* DF7D8 001DF7D8 00000000 */  nop
    /* DF7DC 001DF7DC 00000000 */  nop
.size func_001df730, 0xb0
