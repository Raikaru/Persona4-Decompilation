.section .text
.set noat
.set noreorder
glabel func_001ded30
    /* DED30 001DED30 A0FFBD27 */  addiu      $29, $29, -0x60
    /* DED34 001DED34 5000BFFF */  sd         $31, 0x50($29)
    /* DED38 001DED38 4000B47F */  sq         $20, 0x40($29)
    /* DED3C 001DED3C 3000B37F */  sq         $19, 0x30($29)
    /* DED40 001DED40 2000B27F */  sq         $18, 0x20($29)
    /* DED44 001DED44 1000B17F */  sq         $17, 0x10($29)
    /* DED48 001DED48 0000B07F */  sq         $16, 0x0($29)
    /* DED4C 001DED4C 2DA08000 */  daddu      $20, $4, $0
    /* DED50 001DED50 2D98A000 */  daddu      $19, $5, $0
    /* DED54 001DED54 3000828C */  lw         $2, 0x30($4)
    /* DED58 001DED58 A4005094 */  lhu        $16, 0xA4($2)
    /* DED5C 001DED5C 2D206002 */  daddu      $4, $19, $0
    /* DED60 001DED60 ECAC070C */  jal        func_001eb3b0
    /* DED64 001DED64 00000000 */   nop
    /* DED68 001DED68 3000828E */  lw         $2, 0x30($20)
    /* DED6C 001DED6C A2004390 */  lbu        $3, 0xA2($2)
    /* DED70 001DED70 01000224 */  addiu      $2, $0, 0x1
    /* DED74 001DED74 09006210 */  beq        $3, $2, .L001DED9C
    /* DED78 001DED78 00000000 */   nop
    /* DED7C 001DED7C 03006010 */  beqz       $3, .L001DED8C
    /* DED80 001DED80 00000000 */   nop
    /* DED84 001DED84 0F000010 */  b          .L001DEDC4
    /* DED88 001DED88 00000000 */   nop
  .L001DED8C:
    /* DED8C 001DED8C FFFF1232 */  andi       $18, $16, 0xFFFF
    /* DED90 001DED90 28B4918F */  lw         $17, -0x4BD8($28)
    /* DED94 001DED94 0B000010 */  b          .L001DEDC4
    /* DED98 001DED98 00000000 */   nop
  .L001DED9C:
    /* DED9C 001DED9C D0B3848F */  lw         $4, -0x4C30($28)
    /* DEDA0 001DEDA0 FFFF0332 */  andi       $3, $16, 0xFFFF
    /* DEDA4 001DEDA4 80100300 */  sll        $2, $3, 2
    /* DEDA8 001DEDA8 21104300 */  addu       $2, $2, $3
    /* DEDAC 001DEDAC C0100200 */  sll        $2, $2, 3
    /* DEDB0 001DEDB0 21104300 */  addu       $2, $2, $3
    /* DEDB4 001DEDB4 80100200 */  sll        $2, $2, 2
    /* DEDB8 001DEDB8 21104400 */  addu       $2, $2, $4
    /* DEDBC 001DEDBC 02005294 */  lhu        $18, 0x2($2)
    /* DEDC0 001DEDC0 2CB4918F */  lw         $17, -0x4BD4($28)
  .L001DEDC4:
    /* DEDC4 001DEDC4 FFFF4732 */  andi       $7, $18, 0xFFFF
    /* DEDC8 001DEDC8 0A00E018 */  blez       $7, .L001DEDF4
    /* DEDCC 001DEDCC 00000000 */   nop
    /* DEDD0 001DEDD0 2D208002 */  daddu      $4, $20, $0
    /* DEDD4 001DEDD4 2D286002 */  daddu      $5, $19, $0
    /* DEDD8 001DEDD8 2D302002 */  daddu      $6, $17, $0
    /* DEDDC 001DEDDC EC7A070C */  jal        func_001debb0
    /* DEDE0 001DEDE0 00000000 */   nop
    /* DEDE4 001DEDE4 01000324 */  addiu      $3, $0, 0x1
    /* DEDE8 001DEDE8 300063A2 */  sb         $3, 0x30($19)
    /* DEDEC 001DEDEC 24000010 */  b          .L001DEE80
    /* DEDF0 001DEDF0 00000000 */   nop
  .L001DEDF4:
    /* DEDF4 001DEDF4 2D208002 */  daddu      $4, $20, $0
    /* DEDF8 001DEDF8 007A070C */  jal        func_001de800
    /* DEDFC 001DEDFC 00000000 */   nop
    /* DEE00 001DEE00 FFFF4530 */  andi       $5, $2, 0xFFFF
    /* DEE04 001DEE04 2D208002 */  daddu      $4, $20, $0
    /* DEE08 001DEE08 A47A070C */  jal        func_001dea90
    /* DEE0C 001DEE0C 00000000 */   nop
    /* DEE10 001DEE10 2D804000 */  daddu      $16, $2, $0
    /* DEE14 001DEE14 2D208002 */  daddu      $4, $20, $0
    /* DEE18 001DEE18 2D286002 */  daddu      $5, $19, $0
    /* DEE1C 001DEE1C 02004694 */  lhu        $6, 0x2($2)
    /* DEE20 001DEE20 9079070C */  jal        func_001de640
    /* DEE24 001DEE24 00000000 */   nop
    /* DEE28 001DEE28 0400038E */  lw         $3, 0x4($16)
    /* DEE2C 001DEE2C 3C2A0300 */  dsll32     $5, $3, 8
    /* DEE30 001DEE30 3E2A0500 */  dsrl32     $5, $5, 8
    /* DEE34 001DEE34 2D208002 */  daddu      $4, $20, $0
    /* DEE38 001DEE38 00FF023C */  lui        $2, (0xFF000000 >> 16)
    /* DEE3C 001DEE3C 24106200 */  and        $2, $3, $2
    /* DEE40 001DEE40 02160200 */  srl        $2, $2, 24
    /* DEE44 001DEE44 C0180200 */  sll        $3, $2, 3
    /* DEE48 001DEE48 6100023C */  lui        $2, %hi(D_00609CE0)
    /* DEE4C 001DEE4C E09C4224 */  addiu      $2, $2, %lo(D_00609CE0)
    /* DEE50 001DEE50 21104300 */  addu       $2, $2, $3
    /* DEE54 001DEE54 0000428C */  lw         $2, 0x0($2)
    /* DEE58 001DEE58 09F84000 */  jalr       $2
    /* DEE5C 001DEE5C 00000000 */   nop
    /* DEE60 001DEE60 07004014 */  bnez       $2, .L001DEE80
    /* DEE64 001DEE64 00000000 */   nop
    /* DEE68 001DEE68 2D208002 */  daddu      $4, $20, $0
    /* DEE6C 001DEE6C 2D280000 */  daddu      $5, $0, $0
    /* DEE70 001DEE70 6100023C */  lui        $2, %hi(D_00609CE0)
    /* DEE74 001DEE74 E09C428C */  lw         $2, %lo(D_00609CE0)($2)
    /* DEE78 001DEE78 09F84000 */  jalr       $2
    /* DEE7C 001DEE7C 00000000 */   nop
  .L001DEE80:
    /* DEE80 001DEE80 5000BFDF */  ld         $31, 0x50($29)
    /* DEE84 001DEE84 4000B47B */  lq         $20, 0x40($29)
    /* DEE88 001DEE88 3000B37B */  lq         $19, 0x30($29)
    /* DEE8C 001DEE8C 2000B27B */  lq         $18, 0x20($29)
    /* DEE90 001DEE90 1000B17B */  lq         $17, 0x10($29)
    /* DEE94 001DEE94 0000B07B */  lq         $16, 0x0($29)
    /* DEE98 001DEE98 6000BD27 */  addiu      $29, $29, 0x60
    /* DEE9C 001DEE9C 0800E003 */  jr         $31
    /* DEEA0 001DEEA0 00000000 */   nop
    /* DEEA4 001DEEA4 00000000 */  nop
    /* DEEA8 001DEEA8 00000000 */  nop
    /* DEEAC 001DEEAC 00000000 */  nop
.size func_001ded30, 0x180
