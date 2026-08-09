.section .text
.set noat
.set noreorder
glabel func_00522f18
    /* 422F18 00522F18 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 422F1C 00522F1C 2D108000 */  daddu      $2, $4, $0
    /* 422F20 00522F20 0000BFFF */  sd         $31, 0x0($29)
    /* 422F24 00522F24 04000524 */  addiu      $5, $0, 0x4
    /* 422F28 00522F28 4C0040AC */  sw         $0, 0x4C($2)
    /* 422F2C 00522F2C 0000BFDF */  ld         $31, 0x0($29)
    /* 422F30 00522F30 480040AC */  sw         $0, 0x48($2)
    /* 422F34 00522F34 069E1408 */  j          func_00527818
    /* 422F38 00522F38 1000BD27 */   addiu     $29, $29, 0x10
    /* 422F3C 00522F3C 00000000 */  nop
.size func_00522f18, 0x28
