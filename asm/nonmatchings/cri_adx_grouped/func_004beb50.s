.section .text
.set noat
.set noreorder
glabel func_004beb50
    /* 3BEB50 004BEB50 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3BEB54 004BEB54 2D188000 */  daddu      $3, $4, $0
    /* 3BEB58 004BEB58 0000BFFF */  sd         $31, 0x0($29)
    /* 3BEB5C 004BEB5C 2D38A000 */  daddu      $7, $5, $0
    /* 3BEB60 004BEB60 5000628C */  lw         $2, 0x50($3)
    /* 3BEB64 004BEB64 06004014 */  bnez       $2, .L004BEB80
    /* 3BEB68 004BEB68 30006524 */   addiu     $5, $3, 0x30
    /* 3BEB6C 004BEB6C 7500043C */  lui        $4, %hi(D_00756DE8)
    /* 3BEB70 004BEB70 0000BFDF */  ld         $31, 0x0($29)
    /* 3BEB74 004BEB74 E86D8424 */  addiu      $4, $4, %lo(D_00756DE8)
    /* 3BEB78 004BEB78 A8F51208 */  j          func_004bd6a0
    /* 3BEB7C 004BEB7C 1000BD27 */   addiu     $29, $29, 0x10
  .L004BEB80:
    /* 3BEB80 004BEB80 0000BFDF */  ld         $31, 0x0($29)
    /* 3BEB84 004BEB84 02000224 */  addiu      $2, $0, 0x2
    /* 3BEB88 004BEB88 400067AC */  sw         $7, 0x40($3)
    /* 3BEB8C 004BEB8C 440066AC */  sw         $6, 0x44($3)
    /* 3BEB90 004BEB90 300062AC */  sw         $2, 0x30($3)
    /* 3BEB94 004BEB94 28FF1208 */  j          func_004bfca0
    /* 3BEB98 004BEB98 1000BD27 */   addiu     $29, $29, 0x10
    /* 3BEB9C 004BEB9C 00000000 */  nop
.size func_004beb50, 0x50
