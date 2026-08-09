.section .text
.set noat
.set noreorder
glabel func_0052bc58
    /* 42BC58 0052BC58 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 42BC5C 0052BC5C FF00A530 */  andi       $5, $5, 0xFF
    /* 42BC60 0052BC60 0000B0FF */  sd         $16, 0x0($29)
    /* 42BC64 0052BC64 2D808000 */  daddu      $16, $4, $0
    /* 42BC68 0052BC68 0800BFFF */  sd         $31, 0x8($29)
    /* 42BC6C 0052BC6C FF00C630 */  andi       $6, $6, 0xFF
    /* 42BC70 0052BC70 FF00E730 */  andi       $7, $7, 0xFF
    /* 42BC74 0052BC74 AAA9140C */  jal        func_0052a6a8
    /* 42BC78 0052BC78 3000048E */   lw        $4, 0x30($16)
    /* 42BC7C 0052BC7C 2D200002 */  daddu      $4, $16, $0
    /* 42BC80 0052BC80 0800BFDF */  ld         $31, 0x8($29)
    /* 42BC84 0052BC84 2D280000 */  daddu      $5, $0, $0
    /* 42BC88 0052BC88 0000B0DF */  ld         $16, 0x0($29)
    /* 42BC8C 0052BC8C B8AE1408 */  j          func_0052bae0
    /* 42BC90 0052BC90 1000BD27 */   addiu     $29, $29, 0x10
    /* 42BC94 0052BC94 00000000 */  nop
.size func_0052bc58, 0x40
