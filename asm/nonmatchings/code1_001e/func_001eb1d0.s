.section .text
.set noat
.set noreorder
glabel func_001eb1d0
    /* EB1D0 001EB1D0 D0FFBD27 */  addiu      $29, $29, -0x30
    /* EB1D4 001EB1D4 2000BFFF */  sd         $31, 0x20($29)
    /* EB1D8 001EB1D8 1000B17F */  sq         $17, 0x10($29)
    /* EB1DC 001EB1DC 0000B07F */  sq         $16, 0x0($29)
    /* EB1E0 001EB1E0 14740A0C */  jal        func_0029d050
    /* EB1E4 001EB1E4 00000000 */   nop
    /* EB1E8 001EB1E8 2D804000 */  daddu      $16, $2, $0
    /* EB1EC 001EB1EC 2D200002 */  daddu      $4, $16, $0
    /* EB1F0 001EB1F0 007A070C */  jal        func_001de800
    /* EB1F4 001EB1F4 00000000 */   nop
    /* EB1F8 001EB1F8 FFFF4530 */  andi       $5, $2, 0xFFFF
    /* EB1FC 001EB1FC 2D200002 */  daddu      $4, $16, $0
    /* EB200 001EB200 A47A070C */  jal        func_001dea90
    /* EB204 001EB204 00000000 */   nop
    /* EB208 001EB208 2D884000 */  daddu      $17, $2, $0
    /* EB20C 001EB20C 2D200002 */  daddu      $4, $16, $0
    /* EB210 001EB210 38000526 */  addiu      $5, $16, 0x38
    /* EB214 001EB214 02004694 */  lhu        $6, 0x2($2)
    /* EB218 001EB218 9079070C */  jal        func_001de640
    /* EB21C 001EB21C 00000000 */   nop
    /* EB220 001EB220 0400238E */  lw         $3, 0x4($17)
    /* EB224 001EB224 3C2A0300 */  dsll32     $5, $3, 8
    /* EB228 001EB228 3E2A0500 */  dsrl32     $5, $5, 8
    /* EB22C 001EB22C 2D200002 */  daddu      $4, $16, $0
    /* EB230 001EB230 00FF023C */  lui        $2, (0xFF000000 >> 16)
    /* EB234 001EB234 24106200 */  and        $2, $3, $2
    /* EB238 001EB238 02160200 */  srl        $2, $2, 24
    /* EB23C 001EB23C C0180200 */  sll        $3, $2, 3
    /* EB240 001EB240 6100023C */  lui        $2, %hi(D_00609CE0)
    /* EB244 001EB244 E09C4224 */  addiu      $2, $2, %lo(D_00609CE0)
    /* EB248 001EB248 21104300 */  addu       $2, $2, $3
    /* EB24C 001EB24C 0000428C */  lw         $2, 0x0($2)
    /* EB250 001EB250 09F84000 */  jalr       $2
    /* EB254 001EB254 00000000 */   nop
    /* EB258 001EB258 07004014 */  bnez       $2, .L001EB278
    /* EB25C 001EB25C 00000000 */   nop
    /* EB260 001EB260 2D200002 */  daddu      $4, $16, $0
    /* EB264 001EB264 2D280000 */  daddu      $5, $0, $0
    /* EB268 001EB268 6100023C */  lui        $2, %hi(D_00609CE0)
    /* EB26C 001EB26C E09C428C */  lw         $2, %lo(D_00609CE0)($2)
    /* EB270 001EB270 09F84000 */  jalr       $2
    /* EB274 001EB274 00000000 */   nop
  .L001EB278:
    /* EB278 001EB278 01000224 */  addiu      $2, $0, 0x1
    /* EB27C 001EB27C 2000BFDF */  ld         $31, 0x20($29)
    /* EB280 001EB280 1000B17B */  lq         $17, 0x10($29)
    /* EB284 001EB284 0000B07B */  lq         $16, 0x0($29)
    /* EB288 001EB288 3000BD27 */  addiu      $29, $29, 0x30
    /* EB28C 001EB28C 0800E003 */  jr         $31
    /* EB290 001EB290 00000000 */   nop
    /* EB294 001EB294 00000000 */  nop
    /* EB298 001EB298 00000000 */  nop
    /* EB29C 001EB29C 00000000 */  nop
.size func_001eb1d0, 0xd0
