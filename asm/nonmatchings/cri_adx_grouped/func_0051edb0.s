.section .text
.set noat
.set noreorder
glabel func_0051edb0
    /* 41EDB0 0051EDB0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 41EDB4 0051EDB4 00FF053C */  lui        $5, (0xFF000F0D >> 16)
    /* 41EDB8 0051EDB8 0000BFFF */  sd         $31, 0x0($29)
    /* 41EDBC 0051EDBC 0D0FA534 */  ori        $5, $5, (0xFF000F0D & 0xFFFF)
    /* 41EDC0 0051EDC0 0000BFDF */  ld         $31, 0x0($29)
    /* 41EDC4 0051EDC4 B45E1408 */  j          func_00517ad0
    /* 41EDC8 0051EDC8 1000BD27 */   addiu     $29, $29, 0x10
    /* 41EDCC 0051EDCC 00000000 */  nop
.size func_0051edb0, 0x20
