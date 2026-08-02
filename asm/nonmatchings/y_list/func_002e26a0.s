.section .text
.set noat
.set noreorder
glabel func_002e26a0
    /* 1E26A0 002E26A0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 1E26A4 002E26A4 0000BFFF */  sd         $31, 0x0($29)
    /* 1E26A8 002E26A8 8CB5828F */  lw         $2, -0x4A74($28)
    /* 1E26AC 002E26AC 04004014 */  bnez       $2, .L002E26C0
    /* 1E26B0 002E26B0 00000000 */   nop
    /* 1E26B4 002E26B4 FFFF0224 */  addiu      $2, $0, -0x1
    /* 1E26B8 002E26B8 09000010 */  b          .L002E26E0
    /* 1E26BC 002E26BC 00000000 */   nop
  .L002E26C0:
    /* 1E26C0 002E26C0 3800428C */  lw         $2, 0x38($2)
    /* 1E26C4 002E26C4 02004484 */  lh         $4, 0x2($2)
    /* 1E26C8 002E26C8 01000524 */  addiu      $5, $0, 0x1
    /* 1E26CC 002E26CC 2D300000 */  daddu      $6, $0, $0
    /* 1E26D0 002E26D0 2D380000 */  daddu      $7, $0, $0
    /* 1E26D4 002E26D4 2D40A000 */  daddu      $8, $5, $0
    /* 1E26D8 002E26D8 40CB0A0C */  jal        func_002b2d00
    /* 1E26DC 002E26DC 00000000 */   nop
  .L002E26E0:
    /* 1E26E0 002E26E0 0000BFDF */  ld         $31, 0x0($29)
    /* 1E26E4 002E26E4 1000BD27 */  addiu      $29, $29, 0x10
    /* 1E26E8 002E26E8 0800E003 */  jr         $31
    /* 1E26EC 002E26EC 00000000 */   nop
.size func_002e26a0, 0x50
