.section .text
.set noat
.set noreorder
glabel func_001eb7f0
    /* EB7F0 001EB7F0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* EB7F4 001EB7F4 0000BFFF */  sd         $31, 0x0($29)
    /* EB7F8 001EB7F8 ACB3838F */  lw         $3, -0x4C54($28)
    /* EB7FC 001EB7FC 0C006524 */  addiu      $5, $3, 0xC
    /* EB800 001EB800 0C00648C */  lw         $4, 0xC($3)
    /* EB804 001EB804 00108330 */  andi       $3, $4, 0x1000
    /* EB808 001EB808 0E006010 */  beqz       $3, .L001EB844
    /* EB80C 001EB80C 00000000 */   nop
    /* EB810 001EB810 FFEF0224 */  addiu      $2, $0, -0x1001
    /* EB814 001EB814 24108200 */  and        $2, $4, $2
    /* EB818 001EB818 0000A2AC */  sw         $2, 0x0($5)
    /* EB81C 001EB81C ACB3828F */  lw         $2, -0x4C54($28)
    /* EB820 001EB820 D40D448C */  lw         $4, 0xDD4($2)
    /* EB824 001EB824 8448080C */  jal        func_00212210
    /* EB828 001EB828 00000000 */   nop
    /* EB82C 001EB82C 01000424 */  addiu      $4, $0, 0x1
    /* EB830 001EB830 0F000524 */  addiu      $5, $0, 0xF
    /* EB834 001EB834 02000624 */  addiu      $6, $0, 0x2
    /* EB838 001EB838 13000724 */  addiu      $7, $0, 0x13
    /* EB83C 001EB83C D86B110C */  jal        func_0045af60
    /* EB840 001EB840 00000000 */   nop
  .L001EB844:
    /* EB844 001EB844 0000BFDF */  ld         $31, 0x0($29)
    /* EB848 001EB848 1000BD27 */  addiu      $29, $29, 0x10
    /* EB84C 001EB84C 0800E003 */  jr         $31
    /* EB850 001EB850 00000000 */   nop
    /* EB854 001EB854 00000000 */  nop
    /* EB858 001EB858 00000000 */  nop
    /* EB85C 001EB85C 00000000 */  nop
.size func_001eb7f0, 0x70
