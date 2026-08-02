.section .text
.set noat
.set noreorder
glabel func_001e4ea0
    /* E4EA0 001E4EA0 D0FFBD27 */  addiu      $29, $29, -0x30
    /* E4EA4 001E4EA4 2000BFFF */  sd         $31, 0x20($29)
    /* E4EA8 001E4EA8 1000B17F */  sq         $17, 0x10($29)
    /* E4EAC 001E4EAC 0000B07F */  sq         $16, 0x0($29)
    /* E4EB0 001E4EB0 2D200000 */  daddu      $4, $0, $0
    /* E4EB4 001E4EB4 00730A0C */  jal        func_0029cc00
    /* E4EB8 001E4EB8 00000000 */   nop
    /* E4EBC 001E4EBC 3C1A0200 */  dsll32     $3, $2, 8
    /* E4EC0 001E4EC0 3E1A0300 */  dsrl32     $3, $3, 8
    /* E4EC4 001E4EC4 000B023C */  lui        $2, (0xB000000 >> 16)
    /* E4EC8 001E4EC8 25886200 */  or         $17, $3, $2
    /* E4ECC 001E4ECC 14740A0C */  jal        func_0029d050
    /* E4ED0 001E4ED0 00000000 */   nop
    /* E4ED4 001E4ED4 2D804000 */  daddu      $16, $2, $0
    /* E4ED8 001E4ED8 3C2A1100 */  dsll32     $5, $17, 8
    /* E4EDC 001E4EDC 3E2A0500 */  dsrl32     $5, $5, 8
    /* E4EE0 001E4EE0 2D200002 */  daddu      $4, $16, $0
    /* E4EE4 001E4EE4 00FF023C */  lui        $2, (0xFF000000 >> 16)
    /* E4EE8 001E4EE8 24102202 */  and        $2, $17, $2
    /* E4EEC 001E4EEC 02160200 */  srl        $2, $2, 24
    /* E4EF0 001E4EF0 C0180200 */  sll        $3, $2, 3
    /* E4EF4 001E4EF4 6100023C */  lui        $2, %hi(D_00609CE0)
    /* E4EF8 001E4EF8 E09C4224 */  addiu      $2, $2, %lo(D_00609CE0)
    /* E4EFC 001E4EFC 21104300 */  addu       $2, $2, $3
    /* E4F00 001E4F00 0000428C */  lw         $2, 0x0($2)
    /* E4F04 001E4F04 09F84000 */  jalr       $2
    /* E4F08 001E4F08 00000000 */   nop
    /* E4F0C 001E4F0C 07004014 */  bnez       $2, .L001E4F2C
    /* E4F10 001E4F10 00000000 */   nop
    /* E4F14 001E4F14 2D200002 */  daddu      $4, $16, $0
    /* E4F18 001E4F18 2D280000 */  daddu      $5, $0, $0
    /* E4F1C 001E4F1C 6100023C */  lui        $2, %hi(D_00609CE0)
    /* E4F20 001E4F20 E09C428C */  lw         $2, %lo(D_00609CE0)($2)
    /* E4F24 001E4F24 09F84000 */  jalr       $2
    /* E4F28 001E4F28 00000000 */   nop
  .L001E4F2C:
    /* E4F2C 001E4F2C 01000224 */  addiu      $2, $0, 0x1
    /* E4F30 001E4F30 2000BFDF */  ld         $31, 0x20($29)
    /* E4F34 001E4F34 1000B17B */  lq         $17, 0x10($29)
    /* E4F38 001E4F38 0000B07B */  lq         $16, 0x0($29)
    /* E4F3C 001E4F3C 3000BD27 */  addiu      $29, $29, 0x30
    /* E4F40 001E4F40 0800E003 */  jr         $31
    /* E4F44 001E4F44 00000000 */   nop
    /* E4F48 001E4F48 00000000 */  nop
    /* E4F4C 001E4F4C 00000000 */  nop
.size func_001e4ea0, 0xb0
