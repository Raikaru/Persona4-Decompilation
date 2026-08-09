.section .text
.set noat
.set noreorder
glabel func_002e0690
    /* 1E0690 002E0690 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 1E0694 002E0694 0000BFFF */  sd         $31, 0x0($29)
    /* 1E0698 002E0698 3800828C */  lw         $2, 0x38($4)
    /* 1E069C 002E069C 3C3C0700 */  dsll32     $7, $7, 16
    /* 1E06A0 002E06A0 3F3C0700 */  dsra32     $7, $7, 16
    /* 1E06A4 002E06A4 04004424 */  addiu      $4, $2, 0x4
    /* 1E06A8 002E06A8 86630046 */  mov.s      $f14, $f12
    /* 1E06AC 002E06AC C66B0046 */  mov.s      $f15, $f13
    /* 1E06B0 002E06B0 C0E00A0C */  jal        func_002b8300
    /* 1E06B4 002E06B4 00000000 */   nop
    /* 1E06B8 002E06B8 0000BFDF */  ld         $31, 0x0($29)
    /* 1E06BC 002E06BC 1000BD27 */  addiu      $29, $29, 0x10
    /* 1E06C0 002E06C0 0800E003 */  jr         $31
    /* 1E06C4 002E06C4 00000000 */   nop
    /* 1E06C8 002E06C8 00000000 */  nop
    /* 1E06CC 002E06CC 00000000 */  nop
.size func_002e0690, 0x40
