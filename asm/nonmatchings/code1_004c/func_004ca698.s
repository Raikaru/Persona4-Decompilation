.section .text
.set noat
.set noreorder
glabel func_004ca698
    /* 3CA698 004CA698 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3CA69C 004CA69C 7200033C */  lui        $3, %hi(D_007188B8)
    /* 3CA6A0 004CA6A0 0000BFFF */  sd         $31, 0x0($29)
    /* 3CA6A4 004CA6A4 B8886324 */  addiu      $3, $3, %lo(D_007188B8)
    /* 3CA6A8 004CA6A8 0000628C */  lw         $2, 0x0($3)
    /* 3CA6AC 004CA6AC 0000BFDF */  ld         $31, 0x0($29)
    /* 3CA6B0 004CA6B0 01004224 */  addiu      $2, $2, 0x1
    /* 3CA6B4 004CA6B4 000062AC */  sw         $2, 0x0($3)
    /* 3CA6B8 004CA6B8 CC561308 */  j          func_004d5b30
    /* 3CA6BC 004CA6BC 1000BD27 */   addiu     $29, $29, 0x10
.size func_004ca698, 0x28
