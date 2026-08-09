.section .text
.set noat
.set noreorder
glabel func_0051ed90
    /* 41ED90 0051ED90 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 41ED94 0051ED94 00FF053C */  lui        $5, (0xFF000F0D >> 16)
    /* 41ED98 0051ED98 0000BFFF */  sd         $31, 0x0($29)
    /* 41ED9C 0051ED9C 0D0FA534 */  ori        $5, $5, (0xFF000F0D & 0xFFFF)
    /* 41EDA0 0051EDA0 0000BFDF */  ld         $31, 0x0($29)
    /* 41EDA4 0051EDA4 B45E1408 */  j          func_00517ad0
    /* 41EDA8 0051EDA8 1000BD27 */   addiu     $29, $29, 0x10
    /* 41EDAC 0051EDAC 00000000 */  nop
.size func_0051ed90, 0x20
