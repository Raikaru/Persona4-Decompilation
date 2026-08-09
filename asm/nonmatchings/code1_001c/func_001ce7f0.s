.section .text
.set noat
.set noreorder
glabel func_001ce7f0
    /* CE7F0 001CE7F0 E0FFBD27 */  addiu      $29, $29, -0x20
    /* CE7F4 001CE7F4 1000BFFF */  sd         $31, 0x10($29)
    /* CE7F8 001CE7F8 0000B07F */  sq         $16, 0x0($29)
    /* CE7FC 001CE7FC 2D808000 */  daddu      $16, $4, $0
    /* CE800 001CE800 68010424 */  addiu      $4, $0, 0x168
    /* CE804 001CE804 5CC7080C */  jal        func_00231d70
    /* CE808 001CE808 00000000 */   nop
    /* CE80C 001CE80C 06004004 */  bltz       $2, .L001CE828
    /* CE810 001CE810 00000000 */   nop
    /* CE814 001CE814 00008244 */  mtc1       $2, $f0
    /* CE818 001CE818 00000000 */  nop
    /* CE81C 001CE81C 20008046 */  cvt.s.w    $f0, $f0
    /* CE820 001CE820 08000010 */  b          .L001CE844
    /* CE824 001CE824 00000000 */   nop
  .L001CE828:
    /* CE828 001CE828 42180200 */  srl        $3, $2, 1
    /* CE82C 001CE82C 01004230 */  andi       $2, $2, 0x1
    /* CE830 001CE830 25186200 */  or         $3, $3, $2
    /* CE834 001CE834 00008344 */  mtc1       $3, $f0
    /* CE838 001CE838 00000000 */  nop
    /* CE83C 001CE83C 20008046 */  cvt.s.w    $f0, $f0
    /* CE840 001CE840 00000046 */  add.s      $f0, $f0, $f0
  .L001CE844:
    /* CE844 001CE844 000100E6 */  swc1       $f0, 0x100($16)
    /* CE848 001CE848 01000224 */  addiu      $2, $0, 0x1
    /* CE84C 001CE84C 200102AE */  sw         $2, 0x120($16)
    /* CE850 001CE850 00608044 */  mtc1       $0, $f12
    /* CE854 001CE854 E000048E */  lw         $4, 0xE0($16)
    /* CE858 001CE858 2D280000 */  daddu      $5, $0, $0
    /* CE85C 001CE85C 2D300000 */  daddu      $6, $0, $0
    /* CE860 001CE860 00010724 */  addiu      $7, $0, 0x100
    /* CE864 001CE864 50F3060C */  jal        func_001bcd40
    /* CE868 001CE868 00000000 */   nop
    /* CE86C 001CE86C 1000BFDF */  ld         $31, 0x10($29)
    /* CE870 001CE870 0000B07B */  lq         $16, 0x0($29)
    /* CE874 001CE874 2000BD27 */  addiu      $29, $29, 0x20
    /* CE878 001CE878 0800E003 */  jr         $31
    /* CE87C 001CE87C 00000000 */   nop
.size func_001ce7f0, 0x90
