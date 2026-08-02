.section .text
.set noat
.set noreorder
glabel func_001e5a20
    /* E5A20 001E5A20 D0FFBD27 */  addiu      $29, $29, -0x30
    /* E5A24 001E5A24 2000BFFF */  sd         $31, 0x20($29)
    /* E5A28 001E5A28 1000B17F */  sq         $17, 0x10($29)
    /* E5A2C 001E5A2C 0000B07F */  sq         $16, 0x0($29)
    /* E5A30 001E5A30 2D200000 */  daddu      $4, $0, $0
    /* E5A34 001E5A34 00730A0C */  jal        func_0029cc00
    /* E5A38 001E5A38 00000000 */   nop
    /* E5A3C 001E5A3C 3C1A0200 */  dsll32     $3, $2, 8
    /* E5A40 001E5A40 3E1A0300 */  dsrl32     $3, $3, 8
    /* E5A44 001E5A44 0021023C */  lui        $2, (0x21000000 >> 16)
    /* E5A48 001E5A48 25886200 */  or         $17, $3, $2
    /* E5A4C 001E5A4C 14740A0C */  jal        func_0029d050
    /* E5A50 001E5A50 00000000 */   nop
    /* E5A54 001E5A54 2D804000 */  daddu      $16, $2, $0
    /* E5A58 001E5A58 3C2A1100 */  dsll32     $5, $17, 8
    /* E5A5C 001E5A5C 3E2A0500 */  dsrl32     $5, $5, 8
    /* E5A60 001E5A60 2D200002 */  daddu      $4, $16, $0
    /* E5A64 001E5A64 00FF023C */  lui        $2, (0xFF000000 >> 16)
    /* E5A68 001E5A68 24102202 */  and        $2, $17, $2
    /* E5A6C 001E5A6C 02160200 */  srl        $2, $2, 24
    /* E5A70 001E5A70 C0180200 */  sll        $3, $2, 3
    /* E5A74 001E5A74 6100023C */  lui        $2, %hi(D_00609CE0)
    /* E5A78 001E5A78 E09C4224 */  addiu      $2, $2, %lo(D_00609CE0)
    /* E5A7C 001E5A7C 21104300 */  addu       $2, $2, $3
    /* E5A80 001E5A80 0000428C */  lw         $2, 0x0($2)
    /* E5A84 001E5A84 09F84000 */  jalr       $2
    /* E5A88 001E5A88 00000000 */   nop
    /* E5A8C 001E5A8C 07004014 */  bnez       $2, .L001E5AAC
    /* E5A90 001E5A90 00000000 */   nop
    /* E5A94 001E5A94 2D200002 */  daddu      $4, $16, $0
    /* E5A98 001E5A98 2D280000 */  daddu      $5, $0, $0
    /* E5A9C 001E5A9C 6100023C */  lui        $2, %hi(D_00609CE0)
    /* E5AA0 001E5AA0 E09C428C */  lw         $2, %lo(D_00609CE0)($2)
    /* E5AA4 001E5AA4 09F84000 */  jalr       $2
    /* E5AA8 001E5AA8 00000000 */   nop
  .L001E5AAC:
    /* E5AAC 001E5AAC 01000224 */  addiu      $2, $0, 0x1
    /* E5AB0 001E5AB0 2000BFDF */  ld         $31, 0x20($29)
    /* E5AB4 001E5AB4 1000B17B */  lq         $17, 0x10($29)
    /* E5AB8 001E5AB8 0000B07B */  lq         $16, 0x0($29)
    /* E5ABC 001E5ABC 3000BD27 */  addiu      $29, $29, 0x30
    /* E5AC0 001E5AC0 0800E003 */  jr         $31
    /* E5AC4 001E5AC4 00000000 */   nop
    /* E5AC8 001E5AC8 00000000 */  nop
    /* E5ACC 001E5ACC 00000000 */  nop
.size func_001e5a20, 0xb0
