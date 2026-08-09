.section .text
.set noat
.set noreorder
glabel func_004be050
    /* 3BE050 004BE050 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3BE054 004BE054 0600A014 */  bnez       $5, .L004BE070
    /* 3BE058 004BE058 0000BFFF */   sd        $31, 0x0($29)
    /* 3BE05C 004BE05C 0400848C */  lw         $4, 0x4($4)
    /* 3BE060 004BE060 2D28C000 */  daddu      $5, $6, $0
    /* 3BE064 004BE064 0000BFDF */  ld         $31, 0x0($29)
    /* 3BE068 004BE068 44541308 */  j          func_004d5110
    /* 3BE06C 004BE06C 1000BD27 */   addiu     $29, $29, 0x10
  .L004BE070:
    /* 3BE070 004BE070 0000BFDF */  ld         $31, 0x0($29)
    /* 3BE074 004BE074 0800E003 */  jr         $31
    /* 3BE078 004BE078 1000BD27 */   addiu     $29, $29, 0x10
    /* 3BE07C 004BE07C 00000000 */  nop
.size func_004be050, 0x30
