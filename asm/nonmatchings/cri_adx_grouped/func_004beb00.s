.section .text
.set noat
.set noreorder
glabel func_004beb00
    /* 3BEB00 004BEB00 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3BEB04 004BEB04 2D188000 */  daddu      $3, $4, $0
    /* 3BEB08 004BEB08 0000BFFF */  sd         $31, 0x0($29)
    /* 3BEB0C 004BEB0C 2D38A000 */  daddu      $7, $5, $0
    /* 3BEB10 004BEB10 5000628C */  lw         $2, 0x50($3)
    /* 3BEB14 004BEB14 06004014 */  bnez       $2, .L004BEB30
    /* 3BEB18 004BEB18 30006524 */   addiu     $5, $3, 0x30
    /* 3BEB1C 004BEB1C 7500043C */  lui        $4, %hi(D_00756DB8)
    /* 3BEB20 004BEB20 0000BFDF */  ld         $31, 0x0($29)
    /* 3BEB24 004BEB24 B86D8424 */  addiu      $4, $4, %lo(D_00756DB8)
    /* 3BEB28 004BEB28 A8F51208 */  j          func_004bd6a0
    /* 3BEB2C 004BEB2C 1000BD27 */   addiu     $29, $29, 0x10
  .L004BEB30:
    /* 3BEB30 004BEB30 0000BFDF */  ld         $31, 0x0($29)
    /* 3BEB34 004BEB34 01000224 */  addiu      $2, $0, 0x1
    /* 3BEB38 004BEB38 380067AC */  sw         $7, 0x38($3)
    /* 3BEB3C 004BEB3C 3C0066AC */  sw         $6, 0x3C($3)
    /* 3BEB40 004BEB40 300062AC */  sw         $2, 0x30($3)
    /* 3BEB44 004BEB44 28FF1208 */  j          func_004bfca0
    /* 3BEB48 004BEB48 1000BD27 */   addiu     $29, $29, 0x10
    /* 3BEB4C 004BEB4C 00000000 */  nop
.size func_004beb00, 0x50
