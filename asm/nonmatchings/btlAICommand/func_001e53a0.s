.section .text
.set noat
.set noreorder
glabel func_001e53a0
    /* E53A0 001E53A0 E0FFBD27 */  addiu      $29, $29, -0x20
    /* E53A4 001E53A4 1000BFFF */  sd         $31, 0x10($29)
    /* E53A8 001E53A8 0000B07F */  sq         $16, 0x0($29)
    /* E53AC 001E53AC 14740A0C */  jal        func_0029d050
    /* E53B0 001E53B0 00000000 */   nop
    /* E53B4 001E53B4 2D804000 */  daddu      $16, $2, $0
    /* E53B8 001E53B8 2D200002 */  daddu      $4, $16, $0
    /* E53BC 001E53BC 2D280000 */  daddu      $5, $0, $0
    /* E53C0 001E53C0 6100023C */  lui        $2, %hi(D_00609D80)
    /* E53C4 001E53C4 809D428C */  lw         $2, %lo(D_00609D80)($2)
    /* E53C8 001E53C8 09F84000 */  jalr       $2
    /* E53CC 001E53CC 00000000 */   nop
    /* E53D0 001E53D0 07004014 */  bnez       $2, .L001E53F0
    /* E53D4 001E53D4 00000000 */   nop
    /* E53D8 001E53D8 2D200002 */  daddu      $4, $16, $0
    /* E53DC 001E53DC 2D280000 */  daddu      $5, $0, $0
    /* E53E0 001E53E0 6100023C */  lui        $2, %hi(D_00609CE0)
    /* E53E4 001E53E4 E09C428C */  lw         $2, %lo(D_00609CE0)($2)
    /* E53E8 001E53E8 09F84000 */  jalr       $2
    /* E53EC 001E53EC 00000000 */   nop
  .L001E53F0:
    /* E53F0 001E53F0 01000224 */  addiu      $2, $0, 0x1
    /* E53F4 001E53F4 1000BFDF */  ld         $31, 0x10($29)
    /* E53F8 001E53F8 0000B07B */  lq         $16, 0x0($29)
    /* E53FC 001E53FC 2000BD27 */  addiu      $29, $29, 0x20
    /* E5400 001E5400 0800E003 */  jr         $31
    /* E5404 001E5404 00000000 */   nop
    /* E5408 001E5408 00000000 */  nop
    /* E540C 001E540C 00000000 */  nop
.size func_001e53a0, 0x70
