.section .text
.set noat
.set noreorder
glabel func_004b6e40
    /* 3B6E40 004B6E40 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3B6E44 004B6E44 0000BFFF */  sd         $31, 0x0($29)
    /* 3B6E48 004B6E48 9200023C */  lui        $2, %hi(D_00922DB0)
    /* 3B6E4C 004B6E4C B02D40AC */  sw         $0, %lo(D_00922DB0)($2)
    /* 3B6E50 004B6E50 9200023C */  lui        $2, %hi(D_00922DB4)
    /* 3B6E54 004B6E54 B42D40AC */  sw         $0, %lo(D_00922DB4)($2)
    /* 3B6E58 004B6E58 A8BB848F */  lw         $4, -0x4458($28)
    /* 3B6E5C 004B6E5C 9200053C */  lui        $5, %hi(D_00922DB0)
    /* 3B6E60 004B6E60 B02DA524 */  addiu      $5, $5, %lo(D_00922DB0)
    /* 3B6E64 004B6E64 B082110C */  jal        func_00460ac0
    /* 3B6E68 004B6E68 00000000 */   nop
    /* 3B6E6C 004B6E6C 2D100000 */  daddu      $2, $0, $0
    /* 3B6E70 004B6E70 0000BFDF */  ld         $31, 0x0($29)
    /* 3B6E74 004B6E74 1000BD27 */  addiu      $29, $29, 0x10
    /* 3B6E78 004B6E78 0800E003 */  jr         $31
    /* 3B6E7C 004B6E7C 00000000 */   nop
.size func_004b6e40, 0x40
