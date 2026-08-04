.section .text
.set noat
.set noreorder
glabel func_001b60a0
    /* B60A0 001B60A0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* B60A4 001B60A4 0000BFFF */  sd         $31, 0x0($29)
    /* B60A8 001B60A8 01000324 */  addiu      $3, $0, 0x1
    /* B60AC 001B60AC ACB3828F */  lw         $2, -0x4C54($28)
    /* B60B0 001B60B0 FC0243AC */  sw         $3, 0x2FC($2)
    /* B60B4 001B60B4 ACB3828F */  lw         $2, -0x4C54($28)
    /* B60B8 001B60B8 040340AC */  sw         $0, 0x304($2)
    /* B60BC 001B60BC ACB3828F */  lw         $2, -0x4C54($28)
    /* B60C0 001B60C0 FC024424 */  addiu      $4, $2, 0x2FC
    /* B60C4 001B60C4 FC02438C */  lw         $3, 0x2FC($2)
    /* B60C8 001B60C8 40100300 */  sll        $2, $3, 1
    /* B60CC 001B60CC 21104300 */  addu       $2, $2, $3
    /* B60D0 001B60D0 80180200 */  sll        $3, $2, 2
    /* B60D4 001B60D4 5F00023C */  lui        $2, %hi(D_005F7180)
    /* B60D8 001B60D8 80714224 */  addiu      $2, $2, %lo(D_005F7180)
    /* B60DC 001B60DC 21104300 */  addu       $2, $2, $3
    /* B60E0 001B60E0 0000428C */  lw         $2, 0x0($2)
    /* B60E4 001B60E4 09F84000 */  jalr       $2
    /* B60E8 001B60E8 00000000 */   nop
    /* B60EC 001B60EC ACB3838F */  lw         $3, -0x4C54($28)
    /* B60F0 001B60F0 000360AC */  sw         $0, 0x300($3)
    /* B60F4 001B60F4 0000BFDF */  ld         $31, 0x0($29)
    /* B60F8 001B60F8 1000BD27 */  addiu      $29, $29, 0x10
    /* B60FC 001B60FC 0800E003 */  jr         $31
    /* B6100 001B6100 00000000 */   nop
    /* B6104 001B6104 00000000 */  nop
    /* B6108 001B6108 00000000 */  nop
    /* B610C 001B610C 00000000 */  nop
.size func_001b60a0, 0x70
