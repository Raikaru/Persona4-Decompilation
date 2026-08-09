.section .text
.set noat
.set noreorder
glabel func_00458cb0
    /* 358CB0 00458CB0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 358CB4 00458CB4 0000BFFF */  sd         $31, 0x0($29)
    /* 358CB8 00458CB8 2D30A000 */  daddu      $6, $5, $0
    /* 358CBC 00458CBC 4600053C */  lui        $5, %hi(func_004587d0)
    /* 358CC0 00458CC0 D087A524 */  addiu      $5, $5, %lo(func_004587d0)
    /* 358CC4 00458CC4 9C280F0C */  jal        func_003ca270
    /* 358CC8 00458CC8 00000000 */   nop
    /* 358CCC 00458CCC 0000BFDF */  ld         $31, 0x0($29)
    /* 358CD0 00458CD0 1000BD27 */  addiu      $29, $29, 0x10
    /* 358CD4 00458CD4 0800E003 */  jr         $31
    /* 358CD8 00458CD8 00000000 */   nop
    /* 358CDC 00458CDC 00000000 */  nop
.size func_00458cb0, 0x30
