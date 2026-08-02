.section .text
.set noat
.set noreorder
glabel func_001df1a0
    /* DF1A0 001DF1A0 E0FFBD27 */  addiu      $29, $29, -0x20
    /* DF1A4 001DF1A4 1000BFFF */  sd         $31, 0x10($29)
    /* DF1A8 001DF1A8 0000B07F */  sq         $16, 0x0($29)
    /* DF1AC 001DF1AC 14740A0C */  jal        func_0029d050
    /* DF1B0 001DF1B0 00000000 */   nop
    /* DF1B4 001DF1B4 2D804000 */  daddu      $16, $2, $0
    /* DF1B8 001DF1B8 09000324 */  addiu      $3, $0, 0x9
    /* DF1BC 001DF1BC 6C0043A4 */  sh         $3, 0x6C($2)
    /* DF1C0 001DF1C0 11010324 */  addiu      $3, $0, 0x111
    /* DF1C4 001DF1C4 6E0043A4 */  sh         $3, 0x6E($2)
    /* DF1C8 001DF1C8 2D200000 */  daddu      $4, $0, $0
    /* DF1CC 001DF1CC 00730A0C */  jal        func_0029cc00
    /* DF1D0 001DF1D0 00000000 */   nop
    /* DF1D4 001DF1D4 760002A6 */  sh         $2, 0x76($16)
    /* DF1D8 001DF1D8 2D200002 */  daddu      $4, $16, $0
    /* DF1DC 001DF1DC 2D280000 */  daddu      $5, $0, $0
    /* DF1E0 001DF1E0 6100023C */  lui        $2, %hi(D_00609D20)
    /* DF1E4 001DF1E4 209D428C */  lw         $2, %lo(D_00609D20)($2)
    /* DF1E8 001DF1E8 09F84000 */  jalr       $2
    /* DF1EC 001DF1EC 00000000 */   nop
    /* DF1F0 001DF1F0 07004014 */  bnez       $2, .L001DF210
    /* DF1F4 001DF1F4 00000000 */   nop
    /* DF1F8 001DF1F8 2D200002 */  daddu      $4, $16, $0
    /* DF1FC 001DF1FC 2D280000 */  daddu      $5, $0, $0
    /* DF200 001DF200 6100023C */  lui        $2, %hi(D_00609CE0)
    /* DF204 001DF204 E09C428C */  lw         $2, %lo(D_00609CE0)($2)
    /* DF208 001DF208 09F84000 */  jalr       $2
    /* DF20C 001DF20C 00000000 */   nop
  .L001DF210:
    /* DF210 001DF210 01000224 */  addiu      $2, $0, 0x1
    /* DF214 001DF214 1000BFDF */  ld         $31, 0x10($29)
    /* DF218 001DF218 0000B07B */  lq         $16, 0x0($29)
    /* DF21C 001DF21C 2000BD27 */  addiu      $29, $29, 0x20
    /* DF220 001DF220 0800E003 */  jr         $31
    /* DF224 001DF224 00000000 */   nop
    /* DF228 001DF228 00000000 */  nop
    /* DF22C 001DF22C 00000000 */  nop
.size func_001df1a0, 0x90
