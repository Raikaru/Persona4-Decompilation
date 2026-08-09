.section .text
.set noat
.set noreorder
glabel func_0050fc60
    /* 40FC60 0050FC60 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 40FC64 0050FC64 0000BFFF */  sd         $31, 0x0($29)
    /* 40FC68 0050FC68 A800848C */  lw         $4, 0xA8($4)
    /* 40FC6C 0050FC6C 0000BFDF */  ld         $31, 0x0($29)
    /* 40FC70 0050FC70 48AB1408 */  j          func_0052ad20
    /* 40FC74 0050FC74 1000BD27 */   addiu     $29, $29, 0x10
.size func_0050fc60, 0x18
