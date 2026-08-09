.section .text
.set noat
.set noreorder
glabel func_0042b480
    /* 32B480 0042B480 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 32B484 0042B484 0000BFFF */  sd         $31, 0x0($29)
    /* 32B488 0042B488 1087100C */  jal        func_00421c40
    /* 32B48C 0042B48C 00000000 */   nop
    /* 32B490 0042B490 0002033C */  lui        $3, (0x2000000 >> 16)
    /* 32B494 0042B494 05004314 */  bne        $2, $3, .L0042B4AC
    /* 32B498 0042B498 00000000 */   nop
    /* 32B49C 0042B49C 30AD100C */  jal        func_0042b4c0
    /* 32B4A0 0042B4A0 00000000 */   nop
    /* 32B4A4 0042B4A4 04000010 */  b          .L0042B4B8
    /* 32B4A8 0042B4A8 0000BFDF */   ld        $31, 0x0($29)
  .L0042B4AC:
    /* 32B4AC 0042B4AC 1487100C */  jal        func_00421c50
    /* 32B4B0 0042B4B0 00000000 */   nop
    /* 32B4B4 0042B4B4 0000BFDF */  ld         $31, 0x0($29)
  .L0042B4B8:
    /* 32B4B8 0042B4B8 0800E003 */  jr         $31
    /* 32B4BC 0042B4BC 1000BD27 */   addiu     $29, $29, 0x10
.size func_0042b480, 0x40
