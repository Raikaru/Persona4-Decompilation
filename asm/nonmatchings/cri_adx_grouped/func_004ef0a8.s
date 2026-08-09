.section .text
.set noat
.set noreorder
glabel func_004ef0a8
    /* 3EF0A8 004EF0A8 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3EF0AC 004EF0AC 06008014 */  bnez       $4, .L004EF0C8
    /* 3EF0B0 004EF0B0 0000BFFF */   sd        $31, 0x0($29)
    /* 3EF0B4 004EF0B4 7600043C */  lui        $4, %hi(D_0075CFA8)
    /* 3EF0B8 004EF0B8 7600053C */  lui        $5, %hi(D_0075CEF8)
    /* 3EF0BC 004EF0BC A8CF8424 */  addiu      $4, $4, %lo(D_0075CFA8)
    /* 3EF0C0 004EF0C0 08000010 */  b          .L004EF0E4
    /* 3EF0C4 004EF0C4 F8CEA524 */   addiu     $5, $5, %lo(D_0075CEF8)
  .L004EF0C8:
    /* 3EF0C8 004EF0C8 04008280 */  lb         $2, 0x4($4)
    /* 3EF0CC 004EF0CC 0A004054 */  bnel       $2, $0, .L004EF0F8
    /* 3EF0D0 004EF0D0 0400A22C */   sltiu     $2, $5, 0x4
    /* 3EF0D4 004EF0D4 7600043C */  lui        $4, %hi(D_0075CFB8)
    /* 3EF0D8 004EF0D8 7600053C */  lui        $5, %hi(D_0075CF28)
    /* 3EF0DC 004EF0DC B8CF8424 */  addiu      $4, $4, %lo(D_0075CFB8)
    /* 3EF0E0 004EF0E0 28CFA524 */  addiu      $5, $5, %lo(D_0075CF28)
  .L004EF0E4:
    /* 3EF0E4 004EF0E4 B6BA130C */  jal        func_004eead8
    /* 3EF0E8 004EF0E8 00000000 */   nop
    /* 3EF0EC 004EF0EC 18000010 */  b          .L004EF150
    /* 3EF0F0 004EF0F0 2D100000 */   daddu     $2, $0, $0
    /* 3EF0F4 004EF0F4 00000000 */  nop
  .L004EF0F8:
    /* 3EF0F8 004EF0F8 09004014 */  bnez       $2, .L004EF120
    /* 3EF0FC 004EF0FC 80100500 */   sll       $2, $5, 2
    /* 3EF100 004EF100 2800828C */  lw         $2, 0x28($4)
    /* 3EF104 004EF104 12004050 */  beql       $2, $0, .L004EF150
    /* 3EF108 004EF108 2D100000 */   daddu     $2, $0, $0
    /* 3EF10C 004EF10C 2C00848C */  lw         $4, 0x2C($4)
    /* 3EF110 004EF110 09F84000 */  jalr       $2
    /* 3EF114 004EF114 FDFF0524 */   addiu     $5, $0, -0x3
    /* 3EF118 004EF118 0D000010 */  b          .L004EF150
    /* 3EF11C 004EF11C 2D100000 */   daddu     $2, $0, $0
  .L004EF120:
    /* 3EF120 004EF120 21104400 */  addu       $2, $2, $4
    /* 3EF124 004EF124 1800448C */  lw         $4, 0x18($2)
    /* 3EF128 004EF128 08008010 */  beqz       $4, .L004EF14C
    /* 3EF12C 004EF12C 2D180000 */   daddu     $3, $0, $0
  .L004EF130:
    /* 3EF130 004EF130 0C00828C */  lw         $2, 0xC($4)
    /* 3EF134 004EF134 0000848C */  lw         $4, 0x0($4)
    /* 3EF138 004EF138 00000000 */  nop
    /* 3EF13C 004EF13C 00000000 */  nop
    /* 3EF140 004EF140 00000000 */  nop
    /* 3EF144 004EF144 FAFF8014 */  bnez       $4, .L004EF130
    /* 3EF148 004EF148 21186200 */   addu      $3, $3, $2
  .L004EF14C:
    /* 3EF14C 004EF14C 2D106000 */  daddu      $2, $3, $0
  .L004EF150:
    /* 3EF150 004EF150 0000BFDF */  ld         $31, 0x0($29)
    /* 3EF154 004EF154 0800E003 */  jr         $31
    /* 3EF158 004EF158 1000BD27 */   addiu     $29, $29, 0x10
    /* 3EF15C 004EF15C 00000000 */  nop
.size func_004ef0a8, 0xb8
