.section .text
.set noat
.set noreorder
glabel func_0052ba80
    /* 42BA80 0052BA80 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 42BA84 0052BA84 0000B0FF */  sd         $16, 0x0($29)
    /* 42BA88 0052BA88 2D80A000 */  daddu      $16, $5, $0
    /* 42BA8C 0052BA8C 0800B1FF */  sd         $17, 0x8($29)
    /* 42BA90 0052BA90 2D888000 */  daddu      $17, $4, $0
    /* 42BA94 0052BA94 64000524 */  addiu      $5, $0, 0x64
    /* 42BA98 0052BA98 80801000 */  sll        $16, $16, 2
    /* 42BA9C 0052BA9C 1000B2FF */  sd         $18, 0x10($29)
    /* 42BAA0 0052BAA0 1800BFFF */  sd         $31, 0x18($29)
    /* 42BAA4 0052BAA4 B8AE140C */  jal        func_0052bae0
    /* 42BAA8 0052BAA8 2D90C000 */   daddu     $18, $6, $0
    /* 42BAAC 0052BAAC 21801102 */  addu       $16, $16, $17
    /* 42BAB0 0052BAB0 0800B1DF */  ld         $17, 0x8($29)
    /* 42BAB4 0052BAB4 380012AE */  sw         $18, 0x38($16)
    /* 42BAB8 0052BAB8 1800BFDF */  ld         $31, 0x18($29)
    /* 42BABC 0052BABC 0000B0DF */  ld         $16, 0x0($29)
    /* 42BAC0 0052BAC0 1000B2DF */  ld         $18, 0x10($29)
    /* 42BAC4 0052BAC4 0800E003 */  jr         $31
    /* 42BAC8 0052BAC8 2000BD27 */   addiu     $29, $29, 0x20
    /* 42BACC 0052BACC 00000000 */  nop
.size func_0052ba80, 0x50
