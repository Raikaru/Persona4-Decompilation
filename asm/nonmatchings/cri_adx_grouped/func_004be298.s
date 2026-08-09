.section .text
.set noat
.set noreorder
glabel func_004be298
    /* 3BE298 004BE298 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3BE29C 004BE29C 7500043C */  lui        $4, %hi(D_00756B38)
    /* 3BE2A0 004BE2A0 0000BFFF */  sd         $31, 0x0($29)
    /* 3BE2A4 004BE2A4 386B8424 */  addiu      $4, $4, %lo(D_00756B38)
    /* 3BE2A8 004BE2A8 0000BFDF */  ld         $31, 0x0($29)
    /* 3BE2AC 004BE2AC A8F51208 */  j          func_004bd6a0
    /* 3BE2B0 004BE2B0 1000BD27 */   addiu     $29, $29, 0x10
    /* 3BE2B4 004BE2B4 00000000 */  nop
.size func_004be298, 0x20
