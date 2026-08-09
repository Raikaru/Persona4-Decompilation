.section .text
.set noat
.set noreorder
glabel func_0051d498
    /* 41D498 0051D498 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 41D49C 0051D49C B4368524 */  addiu      $5, $4, 0x36B4
    /* 41D4A0 0051D4A0 0000BFFF */  sd         $31, 0x0($29)
    /* 41D4A4 0051D4A4 2D100000 */  daddu      $2, $0, $0
    /* 41D4A8 0051D4A8 480E8324 */  addiu      $3, $4, 0xE48
    /* 41D4AC 0051D4AC 0400A68C */  lw         $6, 0x4($5)
    /* 41D4B0 0051D4B0 0A00C004 */  bltz       $6, .L0051D4DC
    /* 41D4B4 0051D4B4 F00D8824 */   addiu     $8, $4, 0xDF0
    /* 41D4B8 0051D4B8 0000638C */  lw         $3, 0x0($3)
    /* 41D4BC 0051D4BC 08006054 */  bnel       $3, $0, .L0051D4E0
    /* 41D4C0 0051D4C0 0000BFDF */   ld        $31, 0x0($29)
    /* 41D4C4 0051D4C4 2D20C000 */  daddu      $4, $6, $0
    /* 41D4C8 0051D4C8 2400068D */  lw         $6, 0x24($8)
    /* 41D4CC 0051D4CC 0800A58C */  lw         $5, 0x8($5)
    /* 41D4D0 0051D4D0 52EC130C */  jal        func_004fb148
    /* 41D4D4 0051D4D4 2800078D */   lw        $7, 0x28($8)
    /* 41D4D8 0051D4D8 0100422C */  sltiu      $2, $2, 0x1
  .L0051D4DC:
    /* 41D4DC 0051D4DC 0000BFDF */  ld         $31, 0x0($29)
  .L0051D4E0:
    /* 41D4E0 0051D4E0 0800E003 */  jr         $31
    /* 41D4E4 0051D4E4 1000BD27 */   addiu     $29, $29, 0x10
.size func_0051d498, 0x50
