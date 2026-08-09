.section .text
.set noat
.set noreorder
glabel func_004eaa88
    /* 3EAA88 004EAA88 D0FFBD27 */  addiu      $29, $29, -0x30
    /* 3EAA8C 004EAA8C 0000B0FF */  sd         $16, 0x0($29)
    /* 3EAA90 004EAA90 00840500 */  sll        $16, $5, 16
    /* 3EAA94 004EAA94 0800B1FF */  sd         $17, 0x8($29)
    /* 3EAA98 004EAA98 2D888000 */  daddu      $17, $4, $0
    /* 3EAA9C 004EAA9C 1000B2FF */  sd         $18, 0x10($29)
    /* 3EAAA0 004EAAA0 2D90C000 */  daddu      $18, $6, $0
    /* 3EAAA4 004EAAA4 1800B3FF */  sd         $19, 0x18($29)
    /* 3EAAA8 004EAAA8 2D98E000 */  daddu      $19, $7, $0
    /* 3EAAAC 004EAAAC 2000BFFF */  sd         $31, 0x20($29)
    /* 3EAAB0 004EAAB0 C4A9130C */  jal        func_004ea710
    /* 3EAAB4 004EAAB4 03841000 */   sra       $16, $16, 16
    /* 3EAAB8 004EAAB8 2D202002 */  daddu      $4, $17, $0
    /* 3EAABC 004EAABC 2D280002 */  daddu      $5, $16, $0
    /* 3EAAC0 004EAAC0 2D304002 */  daddu      $6, $18, $0
    /* 3EAAC4 004EAAC4 BAAA130C */  jal        func_004eaae8
    /* 3EAAC8 004EAAC8 2D386002 */   daddu     $7, $19, $0
    /* 3EAACC 004EAACC 0000B0DF */  ld         $16, 0x0($29)
    /* 3EAAD0 004EAAD0 0800B1DF */  ld         $17, 0x8($29)
    /* 3EAAD4 004EAAD4 1000B2DF */  ld         $18, 0x10($29)
    /* 3EAAD8 004EAAD8 1800B3DF */  ld         $19, 0x18($29)
    /* 3EAADC 004EAADC 2000BFDF */  ld         $31, 0x20($29)
    /* 3EAAE0 004EAAE0 CAA91308 */  j          func_004ea728
    /* 3EAAE4 004EAAE4 3000BD27 */   addiu     $29, $29, 0x30
.size func_004eaa88, 0x60
