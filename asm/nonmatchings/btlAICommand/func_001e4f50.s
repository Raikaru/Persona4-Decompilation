.section .text
.set noat
.set noreorder
glabel func_001e4f50
    /* E4F50 001E4F50 D0FFBD27 */  addiu      $29, $29, -0x30
    /* E4F54 001E4F54 2000BFFF */  sd         $31, 0x20($29)
    /* E4F58 001E4F58 1000B17F */  sq         $17, 0x10($29)
    /* E4F5C 001E4F5C 0000B07F */  sq         $16, 0x0($29)
    /* E4F60 001E4F60 2D200000 */  daddu      $4, $0, $0
    /* E4F64 001E4F64 00730A0C */  jal        func_0029cc00
    /* E4F68 001E4F68 00000000 */   nop
    /* E4F6C 001E4F6C 3C1A0200 */  dsll32     $3, $2, 8
    /* E4F70 001E4F70 3E1A0300 */  dsrl32     $3, $3, 8
    /* E4F74 001E4F74 000C023C */  lui        $2, (0xC000000 >> 16)
    /* E4F78 001E4F78 25886200 */  or         $17, $3, $2
    /* E4F7C 001E4F7C 14740A0C */  jal        func_0029d050
    /* E4F80 001E4F80 00000000 */   nop
    /* E4F84 001E4F84 2D804000 */  daddu      $16, $2, $0
    /* E4F88 001E4F88 3C2A1100 */  dsll32     $5, $17, 8
    /* E4F8C 001E4F8C 3E2A0500 */  dsrl32     $5, $5, 8
    /* E4F90 001E4F90 2D200002 */  daddu      $4, $16, $0
    /* E4F94 001E4F94 00FF023C */  lui        $2, (0xFF000000 >> 16)
    /* E4F98 001E4F98 24102202 */  and        $2, $17, $2
    /* E4F9C 001E4F9C 02160200 */  srl        $2, $2, 24
    /* E4FA0 001E4FA0 C0180200 */  sll        $3, $2, 3
    /* E4FA4 001E4FA4 6100023C */  lui        $2, %hi(D_00609CE0)
    /* E4FA8 001E4FA8 E09C4224 */  addiu      $2, $2, %lo(D_00609CE0)
    /* E4FAC 001E4FAC 21104300 */  addu       $2, $2, $3
    /* E4FB0 001E4FB0 0000428C */  lw         $2, 0x0($2)
    /* E4FB4 001E4FB4 09F84000 */  jalr       $2
    /* E4FB8 001E4FB8 00000000 */   nop
    /* E4FBC 001E4FBC 07004014 */  bnez       $2, .L001E4FDC
    /* E4FC0 001E4FC0 00000000 */   nop
    /* E4FC4 001E4FC4 2D200002 */  daddu      $4, $16, $0
    /* E4FC8 001E4FC8 2D280000 */  daddu      $5, $0, $0
    /* E4FCC 001E4FCC 6100023C */  lui        $2, %hi(D_00609CE0)
    /* E4FD0 001E4FD0 E09C428C */  lw         $2, %lo(D_00609CE0)($2)
    /* E4FD4 001E4FD4 09F84000 */  jalr       $2
    /* E4FD8 001E4FD8 00000000 */   nop
  .L001E4FDC:
    /* E4FDC 001E4FDC 01000224 */  addiu      $2, $0, 0x1
    /* E4FE0 001E4FE0 2000BFDF */  ld         $31, 0x20($29)
    /* E4FE4 001E4FE4 1000B17B */  lq         $17, 0x10($29)
    /* E4FE8 001E4FE8 0000B07B */  lq         $16, 0x0($29)
    /* E4FEC 001E4FEC 3000BD27 */  addiu      $29, $29, 0x30
    /* E4FF0 001E4FF0 0800E003 */  jr         $31
    /* E4FF4 001E4FF4 00000000 */   nop
    /* E4FF8 001E4FF8 00000000 */  nop
    /* E4FFC 001E4FFC 00000000 */  nop
.size func_001e4f50, 0xb0
