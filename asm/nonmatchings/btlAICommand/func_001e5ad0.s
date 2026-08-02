.section .text
.set noat
.set noreorder
glabel func_001e5ad0
    /* E5AD0 001E5AD0 E0FFBD27 */  addiu      $29, $29, -0x20
    /* E5AD4 001E5AD4 1000BFFF */  sd         $31, 0x10($29)
    /* E5AD8 001E5AD8 0000B07F */  sq         $16, 0x0($29)
    /* E5ADC 001E5ADC 14740A0C */  jal        func_0029d050
    /* E5AE0 001E5AE0 00000000 */   nop
    /* E5AE4 001E5AE4 2D804000 */  daddu      $16, $2, $0
    /* E5AE8 001E5AE8 2D200002 */  daddu      $4, $16, $0
    /* E5AEC 001E5AEC 2D280000 */  daddu      $5, $0, $0
    /* E5AF0 001E5AF0 6100023C */  lui        $2, %hi(D_00609DF0)
    /* E5AF4 001E5AF4 F09D428C */  lw         $2, %lo(D_00609DF0)($2)
    /* E5AF8 001E5AF8 09F84000 */  jalr       $2
    /* E5AFC 001E5AFC 00000000 */   nop
    /* E5B00 001E5B00 07004014 */  bnez       $2, .L001E5B20
    /* E5B04 001E5B04 00000000 */   nop
    /* E5B08 001E5B08 2D200002 */  daddu      $4, $16, $0
    /* E5B0C 001E5B0C 2D280000 */  daddu      $5, $0, $0
    /* E5B10 001E5B10 6100023C */  lui        $2, %hi(D_00609CE0)
    /* E5B14 001E5B14 E09C428C */  lw         $2, %lo(D_00609CE0)($2)
    /* E5B18 001E5B18 09F84000 */  jalr       $2
    /* E5B1C 001E5B1C 00000000 */   nop
  .L001E5B20:
    /* E5B20 001E5B20 01000224 */  addiu      $2, $0, 0x1
    /* E5B24 001E5B24 1000BFDF */  ld         $31, 0x10($29)
    /* E5B28 001E5B28 0000B07B */  lq         $16, 0x0($29)
    /* E5B2C 001E5B2C 2000BD27 */  addiu      $29, $29, 0x20
    /* E5B30 001E5B30 0800E003 */  jr         $31
    /* E5B34 001E5B34 00000000 */   nop
    /* E5B38 001E5B38 00000000 */  nop
    /* E5B3C 001E5B3C 00000000 */  nop
.size func_001e5ad0, 0x70
