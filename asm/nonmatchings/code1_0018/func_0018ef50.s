.section .text
.set noat
.set noreorder
glabel func_0018ef50
    /* 8EF50 0018EF50 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 8EF54 0018EF54 1000BFFF */  sd         $31, 0x10($29)
    /* 8EF58 0018EF58 0000B07F */  sq         $16, 0x0($29)
    /* 8EF5C 0018EF5C 2D808000 */  daddu      $16, $4, $0
    /* 8EF60 0018EF60 5F00043C */  lui        $4, %hi(D_005F57B0)
    /* 8EF64 0018EF64 B0578424 */  addiu      $4, $4, %lo(D_005F57B0)
    /* 8EF68 0018EF68 01010524 */  addiu      $5, $0, 0x101
    /* 8EF6C 0018EF6C A43A110C */  jal        func_0044ea90
    /* 8EF70 0018EF70 00000000 */   nop
    /* 8EF74 0018EF74 01000424 */  addiu      $4, $0, 0x1
    /* 8EF78 0018EF78 0100023C */  lui        $2, (0x1B440 >> 16)
    /* 8EF7C 0018EF7C 40B44534 */  ori        $5, $2, (0x1B440 & 0xFFFF)
    /* 8EF80 0018EF80 0400063C */  lui        $6, (0x40000 >> 16)
    /* 8EF84 0018EF84 8800023C */  lui        $2, %hi(D_008873F4)
    /* 8EF88 0018EF88 F473428C */  lw         $2, %lo(D_008873F4)($2)
    /* 8EF8C 0018EF8C 09F84000 */  jalr       $2
    /* 8EF90 0018EF90 00000000 */   nop
    /* 8EF94 0018EF94 2D200002 */  daddu      $4, $16, $0
    /* 8EF98 0018EF98 5F00053C */  lui        $5, %hi(D_005F57C0)
    /* 8EF9C 0018EF9C C057A524 */  addiu      $5, $5, %lo(D_005F57C0)
    /* 8EFA0 0018EFA0 0F000624 */  addiu      $6, $0, 0xF
    /* 8EFA4 0018EFA4 2D380000 */  daddu      $7, $0, $0
    /* 8EFA8 0018EFA8 2D400000 */  daddu      $8, $0, $0
    /* 8EFAC 0018EFAC 1900093C */  lui        $9, %hi(func_0018e810)
    /* 8EFB0 0018EFB0 10E82925 */  addiu      $9, $9, %lo(func_0018e810)
    /* 8EFB4 0018EFB4 19000A3C */  lui        $10, %hi(func_0018ef20)
    /* 8EFB8 0018EFB8 20EF4A25 */  addiu      $10, $10, %lo(func_0018ef20)
    /* 8EFBC 0018EFBC 2D584000 */  daddu      $11, $2, $0
    /* 8EFC0 0018EFC0 F047110C */  jal        func_00451fc0
    /* 8EFC4 0018EFC4 00000000 */   nop
    /* 8EFC8 0018EFC8 1000BFDF */  ld         $31, 0x10($29)
    /* 8EFCC 0018EFCC 0000B07B */  lq         $16, 0x0($29)
    /* 8EFD0 0018EFD0 2000BD27 */  addiu      $29, $29, 0x20
    /* 8EFD4 0018EFD4 0800E003 */  jr         $31
    /* 8EFD8 0018EFD8 00000000 */   nop
    /* 8EFDC 0018EFDC 00000000 */  nop
.size func_0018ef50, 0x90
