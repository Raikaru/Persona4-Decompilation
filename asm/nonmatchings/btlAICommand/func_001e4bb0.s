.section .text
.set noat
.set noreorder
glabel func_001e4bb0
    /* E4BB0 001E4BB0 D0FFBD27 */  addiu      $29, $29, -0x30
    /* E4BB4 001E4BB4 2000BFFF */  sd         $31, 0x20($29)
    /* E4BB8 001E4BB8 1000B17F */  sq         $17, 0x10($29)
    /* E4BBC 001E4BBC 0000B07F */  sq         $16, 0x0($29)
    /* E4BC0 001E4BC0 2D200000 */  daddu      $4, $0, $0
    /* E4BC4 001E4BC4 00730A0C */  jal        func_0029cc00
    /* E4BC8 001E4BC8 00000000 */   nop
    /* E4BCC 001E4BCC 3C1A0200 */  dsll32     $3, $2, 8
    /* E4BD0 001E4BD0 3E1A0300 */  dsrl32     $3, $3, 8
    /* E4BD4 001E4BD4 0006023C */  lui        $2, (0x6000000 >> 16)
    /* E4BD8 001E4BD8 25886200 */  or         $17, $3, $2
    /* E4BDC 001E4BDC 14740A0C */  jal        func_0029d050
    /* E4BE0 001E4BE0 00000000 */   nop
    /* E4BE4 001E4BE4 2D804000 */  daddu      $16, $2, $0
    /* E4BE8 001E4BE8 3C2A1100 */  dsll32     $5, $17, 8
    /* E4BEC 001E4BEC 3E2A0500 */  dsrl32     $5, $5, 8
    /* E4BF0 001E4BF0 2D200002 */  daddu      $4, $16, $0
    /* E4BF4 001E4BF4 00FF023C */  lui        $2, (0xFF000000 >> 16)
    /* E4BF8 001E4BF8 24102202 */  and        $2, $17, $2
    /* E4BFC 001E4BFC 02160200 */  srl        $2, $2, 24
    /* E4C00 001E4C00 C0180200 */  sll        $3, $2, 3
    /* E4C04 001E4C04 6100023C */  lui        $2, %hi(D_00609CE0)
    /* E4C08 001E4C08 E09C4224 */  addiu      $2, $2, %lo(D_00609CE0)
    /* E4C0C 001E4C0C 21104300 */  addu       $2, $2, $3
    /* E4C10 001E4C10 0000428C */  lw         $2, 0x0($2)
    /* E4C14 001E4C14 09F84000 */  jalr       $2
    /* E4C18 001E4C18 00000000 */   nop
    /* E4C1C 001E4C1C 07004014 */  bnez       $2, .L001E4C3C
    /* E4C20 001E4C20 00000000 */   nop
    /* E4C24 001E4C24 2D200002 */  daddu      $4, $16, $0
    /* E4C28 001E4C28 2D280000 */  daddu      $5, $0, $0
    /* E4C2C 001E4C2C 6100023C */  lui        $2, %hi(D_00609CE0)
    /* E4C30 001E4C30 E09C428C */  lw         $2, %lo(D_00609CE0)($2)
    /* E4C34 001E4C34 09F84000 */  jalr       $2
    /* E4C38 001E4C38 00000000 */   nop
  .L001E4C3C:
    /* E4C3C 001E4C3C 01000224 */  addiu      $2, $0, 0x1
    /* E4C40 001E4C40 2000BFDF */  ld         $31, 0x20($29)
    /* E4C44 001E4C44 1000B17B */  lq         $17, 0x10($29)
    /* E4C48 001E4C48 0000B07B */  lq         $16, 0x0($29)
    /* E4C4C 001E4C4C 3000BD27 */  addiu      $29, $29, 0x30
    /* E4C50 001E4C50 0800E003 */  jr         $31
    /* E4C54 001E4C54 00000000 */   nop
    /* E4C58 001E4C58 00000000 */  nop
    /* E4C5C 001E4C5C 00000000 */  nop
.size func_001e4bb0, 0xb0
