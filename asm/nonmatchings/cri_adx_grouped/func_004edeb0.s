.section .text
.set noat
.set noreorder
glabel func_004edeb0
    /* 3EDEB0 004EDEB0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3EDEB4 004EDEB4 7600043C */  lui        $4, %hi(D_0075CD80)
    /* 3EDEB8 004EDEB8 0000BFFF */  sd         $31, 0x0($29)
    /* 3EDEBC 004EDEBC 80CD8424 */  addiu      $4, $4, %lo(D_0075CD80)
    /* 3EDEC0 004EDEC0 0000BFDF */  ld         $31, 0x0($29)
    /* 3EDEC4 004EDEC4 20B51308 */  j          func_004ed480
    /* 3EDEC8 004EDEC8 1000BD27 */   addiu     $29, $29, 0x10
    /* 3EDECC 004EDECC 00000000 */  nop
.size func_004edeb0, 0x20
