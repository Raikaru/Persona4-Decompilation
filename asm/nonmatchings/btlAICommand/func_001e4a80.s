.section .text
.set noat
.set noreorder
glabel func_001e4a80
    /* E4A80 001E4A80 D0FFBD27 */  addiu      $29, $29, -0x30
    /* E4A84 001E4A84 2000BFFF */  sd         $31, 0x20($29)
    /* E4A88 001E4A88 1000B17F */  sq         $17, 0x10($29)
    /* E4A8C 001E4A8C 0000B07F */  sq         $16, 0x0($29)
    /* E4A90 001E4A90 2D200000 */  daddu      $4, $0, $0
    /* E4A94 001E4A94 00730A0C */  jal        func_0029cc00
    /* E4A98 001E4A98 00000000 */   nop
    /* E4A9C 001E4A9C 3C1A0200 */  dsll32     $3, $2, 8
    /* E4AA0 001E4AA0 3E1A0300 */  dsrl32     $3, $3, 8
    /* E4AA4 001E4AA4 0005023C */  lui        $2, (0x5000000 >> 16)
    /* E4AA8 001E4AA8 25886200 */  or         $17, $3, $2
    /* E4AAC 001E4AAC 14740A0C */  jal        func_0029d050
    /* E4AB0 001E4AB0 00000000 */   nop
    /* E4AB4 001E4AB4 2D804000 */  daddu      $16, $2, $0
    /* E4AB8 001E4AB8 3C2A1100 */  dsll32     $5, $17, 8
    /* E4ABC 001E4ABC 3E2A0500 */  dsrl32     $5, $5, 8
    /* E4AC0 001E4AC0 2D200002 */  daddu      $4, $16, $0
    /* E4AC4 001E4AC4 00FF023C */  lui        $2, (0xFF000000 >> 16)
    /* E4AC8 001E4AC8 24102202 */  and        $2, $17, $2
    /* E4ACC 001E4ACC 02160200 */  srl        $2, $2, 24
    /* E4AD0 001E4AD0 C0180200 */  sll        $3, $2, 3
    /* E4AD4 001E4AD4 6100023C */  lui        $2, %hi(D_00609CE0)
    /* E4AD8 001E4AD8 E09C4224 */  addiu      $2, $2, %lo(D_00609CE0)
    /* E4ADC 001E4ADC 21104300 */  addu       $2, $2, $3
    /* E4AE0 001E4AE0 0000428C */  lw         $2, 0x0($2)
    /* E4AE4 001E4AE4 09F84000 */  jalr       $2
    /* E4AE8 001E4AE8 00000000 */   nop
    /* E4AEC 001E4AEC 07004014 */  bnez       $2, .L001E4B0C
    /* E4AF0 001E4AF0 00000000 */   nop
    /* E4AF4 001E4AF4 2D200002 */  daddu      $4, $16, $0
    /* E4AF8 001E4AF8 2D280000 */  daddu      $5, $0, $0
    /* E4AFC 001E4AFC 6100023C */  lui        $2, %hi(D_00609CE0)
    /* E4B00 001E4B00 E09C428C */  lw         $2, %lo(D_00609CE0)($2)
    /* E4B04 001E4B04 09F84000 */  jalr       $2
    /* E4B08 001E4B08 00000000 */   nop
  .L001E4B0C:
    /* E4B0C 001E4B0C 01000224 */  addiu      $2, $0, 0x1
    /* E4B10 001E4B10 2000BFDF */  ld         $31, 0x20($29)
    /* E4B14 001E4B14 1000B17B */  lq         $17, 0x10($29)
    /* E4B18 001E4B18 0000B07B */  lq         $16, 0x0($29)
    /* E4B1C 001E4B1C 3000BD27 */  addiu      $29, $29, 0x30
    /* E4B20 001E4B20 0800E003 */  jr         $31
    /* E4B24 001E4B24 00000000 */   nop
    /* E4B28 001E4B28 00000000 */  nop
    /* E4B2C 001E4B2C 00000000 */  nop
.size func_001e4a80, 0xb0
