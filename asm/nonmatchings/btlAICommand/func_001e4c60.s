.section .text
.set noat
.set noreorder
glabel func_001e4c60
    /* E4C60 001E4C60 E0FFBD27 */  addiu      $29, $29, -0x20
    /* E4C64 001E4C64 1000BFFF */  sd         $31, 0x10($29)
    /* E4C68 001E4C68 0000B07F */  sq         $16, 0x0($29)
    /* E4C6C 001E4C6C 14740A0C */  jal        func_0029d050
    /* E4C70 001E4C70 00000000 */   nop
    /* E4C74 001E4C74 2D804000 */  daddu      $16, $2, $0
    /* E4C78 001E4C78 2D200002 */  daddu      $4, $16, $0
    /* E4C7C 001E4C7C 2D280000 */  daddu      $5, $0, $0
    /* E4C80 001E4C80 6100023C */  lui        $2, %hi(D_00609D18)
    /* E4C84 001E4C84 189D428C */  lw         $2, %lo(D_00609D18)($2)
    /* E4C88 001E4C88 09F84000 */  jalr       $2
    /* E4C8C 001E4C8C 00000000 */   nop
    /* E4C90 001E4C90 07004014 */  bnez       $2, .L001E4CB0
    /* E4C94 001E4C94 00000000 */   nop
    /* E4C98 001E4C98 2D200002 */  daddu      $4, $16, $0
    /* E4C9C 001E4C9C 2D280000 */  daddu      $5, $0, $0
    /* E4CA0 001E4CA0 6100023C */  lui        $2, %hi(D_00609CE0)
    /* E4CA4 001E4CA4 E09C428C */  lw         $2, %lo(D_00609CE0)($2)
    /* E4CA8 001E4CA8 09F84000 */  jalr       $2
    /* E4CAC 001E4CAC 00000000 */   nop
  .L001E4CB0:
    /* E4CB0 001E4CB0 01000224 */  addiu      $2, $0, 0x1
    /* E4CB4 001E4CB4 1000BFDF */  ld         $31, 0x10($29)
    /* E4CB8 001E4CB8 0000B07B */  lq         $16, 0x0($29)
    /* E4CBC 001E4CBC 2000BD27 */  addiu      $29, $29, 0x20
    /* E4CC0 001E4CC0 0800E003 */  jr         $31
    /* E4CC4 001E4CC4 00000000 */   nop
    /* E4CC8 001E4CC8 00000000 */  nop
    /* E4CCC 001E4CCC 00000000 */  nop
.size func_001e4c60, 0x70
