.section .text
.set noat
.set noreorder
glabel func_004dfe38
    /* 3DFE38 004DFE38 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3DFE3C 004DFE3C 80100500 */  sll        $2, $5, 2
    /* 3DFE40 004DFE40 0000BFFF */  sd         $31, 0x0($29)
    /* 3DFE44 004DFE44 21208200 */  addu       $4, $4, $2
    /* 3DFE48 004DFE48 2D28C000 */  daddu      $5, $6, $0
    /* 3DFE4C 004DFE4C 0C00848C */  lw         $4, 0xC($4)
    /* 3DFE50 004DFE50 0000BFDF */  ld         $31, 0x0($29)
    /* 3DFE54 004DFE54 44541308 */  j          func_004d5110
    /* 3DFE58 004DFE58 1000BD27 */   addiu     $29, $29, 0x10
    /* 3DFE5C 004DFE5C 00000000 */  nop
.size func_004dfe38, 0x28
