.section .text
.set noat
.set noreorder
glabel func_002a2e10
    /* 1A2E10 002A2E10 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 1A2E14 002A2E14 0000BFFF */  sd         $31, 0x0($29)
    /* 1A2E18 002A2E18 2110C700 */  addu       $2, $6, $7
    /* 1A2E1C 002A2E1C 00004680 */  lb         $6, 0x0($2)
    /* 1A2E20 002A2E20 0200C014 */  bnez       $6, .L002A2E2C
    /* 1A2E24 002A2E24 00000000 */   nop
    /* 1A2E28 002A2E28 0A000624 */  addiu      $6, $0, 0xA
  .L002A2E2C:
    /* 1A2E2C 002A2E2C 2D380000 */  daddu      $7, $0, $0
    /* 1A2E30 002A2E30 2D402001 */  daddu      $8, $9, $0
    /* 1A2E34 002A2E34 01000924 */  addiu      $9, $0, 0x1
    /* 1A2E38 002A2E38 FC7C090C */  jal        func_0025f3f0
    /* 1A2E3C 002A2E3C 00000000 */   nop
    /* 1A2E40 002A2E40 0000BFDF */  ld         $31, 0x0($29)
    /* 1A2E44 002A2E44 1000BD27 */  addiu      $29, $29, 0x10
    /* 1A2E48 002A2E48 0800E003 */  jr         $31
    /* 1A2E4C 002A2E4C 00000000 */   nop
.size func_002a2e10, 0x40
