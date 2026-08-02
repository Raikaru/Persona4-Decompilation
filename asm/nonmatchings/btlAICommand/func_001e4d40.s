.section .text
.set noat
.set noreorder
glabel func_001e4d40
    /* E4D40 001E4D40 D0FFBD27 */  addiu      $29, $29, -0x30
    /* E4D44 001E4D44 2000BFFF */  sd         $31, 0x20($29)
    /* E4D48 001E4D48 1000B17F */  sq         $17, 0x10($29)
    /* E4D4C 001E4D4C 0000B07F */  sq         $16, 0x0($29)
    /* E4D50 001E4D50 2D200000 */  daddu      $4, $0, $0
    /* E4D54 001E4D54 00730A0C */  jal        func_0029cc00
    /* E4D58 001E4D58 00000000 */   nop
    /* E4D5C 001E4D5C 3C1A0200 */  dsll32     $3, $2, 8
    /* E4D60 001E4D60 3E1A0300 */  dsrl32     $3, $3, 8
    /* E4D64 001E4D64 0009023C */  lui        $2, (0x9000000 >> 16)
    /* E4D68 001E4D68 25886200 */  or         $17, $3, $2
    /* E4D6C 001E4D6C 14740A0C */  jal        func_0029d050
    /* E4D70 001E4D70 00000000 */   nop
    /* E4D74 001E4D74 2D804000 */  daddu      $16, $2, $0
    /* E4D78 001E4D78 3C2A1100 */  dsll32     $5, $17, 8
    /* E4D7C 001E4D7C 3E2A0500 */  dsrl32     $5, $5, 8
    /* E4D80 001E4D80 2D200002 */  daddu      $4, $16, $0
    /* E4D84 001E4D84 00FF023C */  lui        $2, (0xFF000000 >> 16)
    /* E4D88 001E4D88 24102202 */  and        $2, $17, $2
    /* E4D8C 001E4D8C 02160200 */  srl        $2, $2, 24
    /* E4D90 001E4D90 C0180200 */  sll        $3, $2, 3
    /* E4D94 001E4D94 6100023C */  lui        $2, %hi(D_00609CE0)
    /* E4D98 001E4D98 E09C4224 */  addiu      $2, $2, %lo(D_00609CE0)
    /* E4D9C 001E4D9C 21104300 */  addu       $2, $2, $3
    /* E4DA0 001E4DA0 0000428C */  lw         $2, 0x0($2)
    /* E4DA4 001E4DA4 09F84000 */  jalr       $2
    /* E4DA8 001E4DA8 00000000 */   nop
    /* E4DAC 001E4DAC 07004014 */  bnez       $2, .L001E4DCC
    /* E4DB0 001E4DB0 00000000 */   nop
    /* E4DB4 001E4DB4 2D200002 */  daddu      $4, $16, $0
    /* E4DB8 001E4DB8 2D280000 */  daddu      $5, $0, $0
    /* E4DBC 001E4DBC 6100023C */  lui        $2, %hi(D_00609CE0)
    /* E4DC0 001E4DC0 E09C428C */  lw         $2, %lo(D_00609CE0)($2)
    /* E4DC4 001E4DC4 09F84000 */  jalr       $2
    /* E4DC8 001E4DC8 00000000 */   nop
  .L001E4DCC:
    /* E4DCC 001E4DCC 01000224 */  addiu      $2, $0, 0x1
    /* E4DD0 001E4DD0 2000BFDF */  ld         $31, 0x20($29)
    /* E4DD4 001E4DD4 1000B17B */  lq         $17, 0x10($29)
    /* E4DD8 001E4DD8 0000B07B */  lq         $16, 0x0($29)
    /* E4DDC 001E4DDC 3000BD27 */  addiu      $29, $29, 0x30
    /* E4DE0 001E4DE0 0800E003 */  jr         $31
    /* E4DE4 001E4DE4 00000000 */   nop
    /* E4DE8 001E4DE8 00000000 */  nop
    /* E4DEC 001E4DEC 00000000 */  nop
.size func_001e4d40, 0xb0
