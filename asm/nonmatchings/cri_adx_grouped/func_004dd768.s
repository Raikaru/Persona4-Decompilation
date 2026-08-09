.section .text
.set noat
.set noreorder
glabel func_004dd768
    /* 3DD768 004DD768 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 3DD76C 004DD76C 0000B0FF */  sd         $16, 0x0($29)
    /* 3DD770 004DD770 2D800000 */  daddu      $16, $0, $0
    /* 3DD774 004DD774 0800B1FF */  sd         $17, 0x8($29)
    /* 3DD778 004DD778 1000B2FF */  sd         $18, 0x10($29)
    /* 3DD77C 004DD77C 7300123C */  lui        $18, %hi(D_00729998)
    /* 3DD780 004DD780 1800BFFF */  sd         $31, 0x18($29)
    /* 3DD784 004DD784 98994226 */  addiu      $2, $18, %lo(D_00729998)
    /* 3DD788 004DD788 0000488C */  lw         $8, 0x0($2)
    /* 3DD78C 004DD78C 0D000011 */  beqz       $8, .L004DD7C4
    /* 3DD790 004DD790 2D888000 */   daddu     $17, $4, $0
    /* 3DD794 004DD794 2D184000 */  daddu      $3, $2, $0
    /* 3DD798 004DD798 01001026 */  addiu      $16, $16, 0x1
    /* 3DD79C 004DD79C 00000000 */  nop
  .L004DD7A0:
    /* 3DD7A0 004DD7A0 1000022A */  slti       $2, $16, 0x10
    /* 3DD7A4 004DD7A4 07004010 */  beqz       $2, .L004DD7C4
    /* 3DD7A8 004DD7A8 04006324 */   addiu     $3, $3, 0x4
    /* 3DD7AC 004DD7AC 0000688C */  lw         $8, 0x0($3)
    /* 3DD7B0 004DD7B0 00000000 */  nop
    /* 3DD7B4 004DD7B4 00000000 */  nop
    /* 3DD7B8 004DD7B8 00000000 */  nop
    /* 3DD7BC 004DD7BC F8FF0055 */  bnel       $8, $0, .L004DD7A0
    /* 3DD7C0 004DD7C0 01001026 */   addiu     $16, $16, 0x1
  .L004DD7C4:
    /* 3DD7C4 004DD7C4 10000324 */  addiu      $3, $0, 0x10
    /* 3DD7C8 004DD7C8 17000312 */  beq        $16, $3, .L004DD828
    /* 3DD7CC 004DD7CC 2D100000 */   daddu     $2, $0, $0
    /* 3DD7D0 004DD7D0 2D30A000 */  daddu      $6, $5, $0
    /* 3DD7D4 004DD7D4 2D280000 */  daddu      $5, $0, $0
    /* 3DD7D8 004DD7D8 72FE100C */  jal        func_0043f9c8
    /* 3DD7DC 004DD7DC 2D202002 */   daddu     $4, $17, $0
    /* 3DD7E0 004DD7E0 98994326 */  addiu      $3, $18, %lo(D_00729998)
    /* 3DD7E4 004DD7E4 80101000 */  sll        $2, $16, 2
    /* 3DD7E8 004DD7E8 2D402002 */  daddu      $8, $17, $0
    /* 3DD7EC 004DD7EC 21104300 */  addu       $2, $2, $3
    /* 3DD7F0 004DD7F0 40000424 */  addiu      $4, $0, 0x40
    /* 3DD7F4 004DD7F4 000051AC */  sw         $17, 0x0($2)
    /* 3DD7F8 004DD7F8 2D100001 */  daddu      $2, $8, $0
    /* 3DD7FC 004DD7FC 010010A1 */  sb         $16, 0x1($8)
    /* 3DD800 004DD800 7300063C */  lui        $6, %hi(D_007299DC)
    /* 3DD804 004DD804 040004AD */  sw         $4, 0x4($8)
    /* 3DD808 004DD808 7300073C */  lui        $7, %hi(D_007299D8)
    /* 3DD80C 004DD80C 080004AD */  sw         $4, 0x8($8)
    /* 3DD810 004DD810 01000524 */  addiu      $5, $0, 0x1
    /* 3DD814 004DD814 DC99C38C */  lw         $3, %lo(D_007299DC)($6)
    /* 3DD818 004DD818 100003AD */  sw         $3, 0x10($8)
    /* 3DD81C 004DD81C D899E48C */  lw         $4, %lo(D_007299D8)($7)
    /* 3DD820 004DD820 000005A1 */  sb         $5, 0x0($8)
    /* 3DD824 004DD824 0C0004AD */  sw         $4, 0xC($8)
  .L004DD828:
    /* 3DD828 004DD828 0000B0DF */  ld         $16, 0x0($29)
    /* 3DD82C 004DD82C 0800B1DF */  ld         $17, 0x8($29)
    /* 3DD830 004DD830 1000B2DF */  ld         $18, 0x10($29)
    /* 3DD834 004DD834 1800BFDF */  ld         $31, 0x18($29)
    /* 3DD838 004DD838 0800E003 */  jr         $31
    /* 3DD83C 004DD83C 2000BD27 */   addiu     $29, $29, 0x20
.size func_004dd768, 0xd8
