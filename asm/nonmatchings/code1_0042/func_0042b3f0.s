.section .text
.set noat
.set noreorder
glabel func_0042b3f0
    /* 32B3F0 0042B3F0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 32B3F4 0042B3F4 F3FF8224 */  addiu      $2, $4, -0xD
    /* 32B3F8 0042B3F8 2300422C */  sltiu      $2, $2, 0x23
    /* 32B3FC 0042B3FC 03004014 */  bnez       $2, .L0042B40C
    /* 32B400 0042B400 0000BFFF */   sd        $31, 0x0($29)
    /* 32B404 0042B404 03000010 */  b          .L0042B414
    /* 32B408 0042B408 FFFF0224 */   addiu     $2, $0, -0x1
  .L0042B40C:
    /* 32B40C 0042B40C F8AC100C */  jal        func_0042b3e0
    /* 32B410 0042B410 00000000 */   nop
  .L0042B414:
    /* 32B414 0042B414 0000BFDF */  ld         $31, 0x0($29)
    /* 32B418 0042B418 0800E003 */  jr         $31
    /* 32B41C 0042B41C 1000BD27 */   addiu     $29, $29, 0x10
.size func_0042b3f0, 0x30
