.section .text
.set noat
.set noreorder
glabel func_0051bb58
    /* 41BB58 0051BB58 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 41BB5C 0051BB5C 0000B0FF */  sd         $16, 0x0($29)
    /* 41BB60 0051BB60 2D808000 */  daddu      $16, $4, $0
    /* 41BB64 0051BB64 0800B1FF */  sd         $17, 0x8($29)
    /* 41BB68 0051BB68 2D88A000 */  daddu      $17, $5, $0
    /* 41BB6C 0051BB6C 1000BFFF */  sd         $31, 0x10($29)
    /* 41BB70 0051BB70 2D302002 */  daddu      $6, $17, $0
    /* 41BB74 0051BB74 B854140C */  jal        func_005152e0
    /* 41BB78 0051BB78 C81F058E */   lw        $5, 0x1FC8($16)
    /* 41BB7C 0051BB7C A80902DE */  ld         $2, 0x9A8($16)
    /* 41BB80 0051BB80 1000BFDF */  ld         $31, 0x10($29)
    /* 41BB84 0051BB84 2D102202 */  daddu      $2, $17, $2
    /* 41BB88 0051BB88 0800B1DF */  ld         $17, 0x8($29)
    /* 41BB8C 0051BB8C A80902FE */  sd         $2, 0x9A8($16)
    /* 41BB90 0051BB90 0000B0DF */  ld         $16, 0x0($29)
    /* 41BB94 0051BB94 0800E003 */  jr         $31
    /* 41BB98 0051BB98 2000BD27 */   addiu     $29, $29, 0x20
    /* 41BB9C 0051BB9C 00000000 */  nop
.size func_0051bb58, 0x48
