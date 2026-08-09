.section .text
.set noat
.set noreorder
glabel func_0050ea28
    /* 40EA28 0050EA28 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 40EA2C 0050EA2C 0000BFFF */  sd         $31, 0x0($29)
    /* 40EA30 0050EA30 A800848C */  lw         $4, 0xA8($4)
    /* 40EA34 0050EA34 0000BFDF */  ld         $31, 0x0($29)
    /* 40EA38 0050EA38 A0AE1408 */  j          func_0052ba80
    /* 40EA3C 0050EA3C 1000BD27 */   addiu     $29, $29, 0x10
.size func_0050ea28, 0x18
