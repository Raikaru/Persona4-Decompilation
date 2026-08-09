.section .text
.set noat
.set noreorder
glabel func_004eeab8
    /* 3EEAB8 004EEAB8 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3EEABC 004EEABC 7600043C */  lui        $4, %hi(D_0075CED8)
    /* 3EEAC0 004EEAC0 0000BFFF */  sd         $31, 0x0($29)
    /* 3EEAC4 004EEAC4 D8CE8424 */  addiu      $4, $4, %lo(D_0075CED8)
    /* 3EEAC8 004EEAC8 0000BFDF */  ld         $31, 0x0($29)
    /* 3EEACC 004EEACC 20B51308 */  j          func_004ed480
    /* 3EEAD0 004EEAD0 1000BD27 */   addiu     $29, $29, 0x10
    /* 3EEAD4 004EEAD4 00000000 */  nop
.size func_004eeab8, 0x20
