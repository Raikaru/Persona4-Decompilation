.section .text
.set noat
.set noreorder
glabel func_0050e428
    /* 40E428 0050E428 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 40E42C 0050E42C 0000BFFF */  sd         $31, 0x0($29)
    /* 40E430 0050E430 80AD140C */  jal        func_0052b600
    /* 40E434 0050E434 00000000 */   nop
    /* 40E438 0050E438 0000BFDF */  ld         $31, 0x0($29)
    /* 40E43C 0050E43C 5100043C */  lui        $4, %hi(func_0050e450)
    /* 40E440 0050E440 50E48424 */  addiu      $4, $4, %lo(func_0050e450)
    /* 40E444 0050E444 2D280000 */  daddu      $5, $0, $0
    /* 40E448 0050E448 C8AD1408 */  j          func_0052b720
    /* 40E44C 0050E44C 1000BD27 */   addiu     $29, $29, 0x10
.size func_0050e428, 0x28
