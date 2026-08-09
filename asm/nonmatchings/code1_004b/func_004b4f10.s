.section .text
.set noat
.set noreorder
glabel func_004b4f10
    /* 3B4F10 004B4F10 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3B4F14 004B4F14 0000BFFF */  sd         $31, 0x0($29)
    /* 3B4F18 004B4F18 2D108000 */  daddu      $2, $4, $0
    /* 3B4F1C 004B4F1C 18008494 */  lhu        $4, 0x18($4)
    /* 3B4F20 004B4F20 2400458C */  lw         $5, 0x24($2)
    /* 3B4F24 004B4F24 2CD3120C */  jal        func_004b4cb0
    /* 3B4F28 004B4F28 00000000 */   nop
    /* 3B4F2C 004B4F2C 0000BFDF */  ld         $31, 0x0($29)
    /* 3B4F30 004B4F30 1000BD27 */  addiu      $29, $29, 0x10
    /* 3B4F34 004B4F34 0800E003 */  jr         $31
    /* 3B4F38 004B4F38 00000000 */   nop
    /* 3B4F3C 004B4F3C 00000000 */  nop
.size func_004b4f10, 0x30
