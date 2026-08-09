.section .text
.set noat
.set noreorder
glabel func_004b1090
    /* 3B1090 004B1090 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3B1094 004B1094 0000BFFF */  sd         $31, 0x0($29)
    /* 3B1098 004B1098 5C00848C */  lw         $4, 0x5C($4)
    /* 3B109C 004B109C 744B120C */  jal        func_00492dd0
    /* 3B10A0 004B10A0 00000000 */   nop
    /* 3B10A4 004B10A4 0000BFDF */  ld         $31, 0x0($29)
    /* 3B10A8 004B10A8 1000BD27 */  addiu      $29, $29, 0x10
    /* 3B10AC 004B10AC 0800E003 */  jr         $31
    /* 3B10B0 004B10B0 00000000 */   nop
    /* 3B10B4 004B10B4 00000000 */  nop
    /* 3B10B8 004B10B8 00000000 */  nop
    /* 3B10BC 004B10BC 00000000 */  nop
.size func_004b1090, 0x30
