.section .text
.set noat
.set noreorder
glabel func_001e6c60
    /* E6C60 001E6C60 E0FFBD27 */  addiu      $29, $29, -0x20
    /* E6C64 001E6C64 1000BFFF */  sd         $31, 0x10($29)
    /* E6C68 001E6C68 0000B07F */  sq         $16, 0x0($29)
    /* E6C6C 001E6C6C 14740A0C */  jal        func_0029d050
    /* E6C70 001E6C70 00000000 */   nop
    /* E6C74 001E6C74 2D804000 */  daddu      $16, $2, $0
    /* E6C78 001E6C78 2D200002 */  daddu      $4, $16, $0
    /* E6C7C 001E6C7C 2D280000 */  daddu      $5, $0, $0
    /* E6C80 001E6C80 6E004694 */  lhu        $6, 0x6E($2)
    /* E6C84 001E6C84 2D380000 */  daddu      $7, $0, $0
    /* E6C88 001E6C88 C45F070C */  jal        func_001d7f10
    /* E6C8C 001E6C8C 00000000 */   nop
    /* E6C90 001E6C90 FFFF4230 */  andi       $2, $2, 0xFFFF
    /* E6C94 001E6C94 0D004014 */  bnez       $2, .L001E6CCC
    /* E6C98 001E6C98 00000000 */   nop
    /* E6C9C 001E6C9C 2D200000 */  daddu      $4, $0, $0
    /* E6CA0 001E6CA0 00730A0C */  jal        func_0029cc00
    /* E6CA4 001E6CA4 00000000 */   nop
    /* E6CA8 001E6CA8 3C210200 */  dsll32     $4, $2, 4
    /* E6CAC 001E6CAC 3E210400 */  dsrl32     $4, $4, 4
    /* E6CB0 001E6CB0 30C3060C */  jal        func_001b0cc0
    /* E6CB4 001E6CB4 00000000 */   nop
    /* E6CB8 001E6CB8 380002AE */  sw         $2, 0x38($16)
    /* E6CBC 001E6CBC 01000224 */  addiu      $2, $0, 0x1
    /* E6CC0 001E6CC0 6A0002A6 */  sh         $2, 0x6A($16)
    /* E6CC4 001E6CC4 0F000010 */  b          .L001E6D04
    /* E6CC8 001E6CC8 00000000 */   nop
  .L001E6CCC:
    /* E6CCC 001E6CCC 2D200002 */  daddu      $4, $16, $0
    /* E6CD0 001E6CD0 2D280000 */  daddu      $5, $0, $0
    /* E6CD4 001E6CD4 6100023C */  lui        $2, %hi(D_00609CE0)
    /* E6CD8 001E6CD8 E09C428C */  lw         $2, %lo(D_00609CE0)($2)
    /* E6CDC 001E6CDC 09F84000 */  jalr       $2
    /* E6CE0 001E6CE0 00000000 */   nop
    /* E6CE4 001E6CE4 07004014 */  bnez       $2, .L001E6D04
    /* E6CE8 001E6CE8 00000000 */   nop
    /* E6CEC 001E6CEC 2D200002 */  daddu      $4, $16, $0
    /* E6CF0 001E6CF0 2D280000 */  daddu      $5, $0, $0
    /* E6CF4 001E6CF4 6100023C */  lui        $2, %hi(D_00609CE0)
    /* E6CF8 001E6CF8 E09C428C */  lw         $2, %lo(D_00609CE0)($2)
    /* E6CFC 001E6CFC 09F84000 */  jalr       $2
    /* E6D00 001E6D00 00000000 */   nop
  .L001E6D04:
    /* E6D04 001E6D04 01000224 */  addiu      $2, $0, 0x1
    /* E6D08 001E6D08 1000BFDF */  ld         $31, 0x10($29)
    /* E6D0C 001E6D0C 0000B07B */  lq         $16, 0x0($29)
    /* E6D10 001E6D10 2000BD27 */  addiu      $29, $29, 0x20
    /* E6D14 001E6D14 0800E003 */  jr         $31
    /* E6D18 001E6D18 00000000 */   nop
    /* E6D1C 001E6D1C 00000000 */  nop
.size func_001e6c60, 0xc0
