.section .text
.set noat
.set noreorder
glabel func_004f93d0
    /* 3F93D0 004F93D0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3F93D4 004F93D4 7400033C */  lui        $3, %hi(D_00743C3C)
    /* 3F93D8 004F93D8 0000BFFF */  sd         $31, 0x0($29)
    /* 3F93DC 004F93DC 3C3C6324 */  addiu      $3, $3, %lo(D_00743C3C)
    /* 3F93E0 004F93E0 0000628C */  lw         $2, 0x0($3)
    /* 3F93E4 004F93E4 FFFF4224 */  addiu      $2, $2, -0x1
    /* 3F93E8 004F93E8 05004014 */  bnez       $2, .L004F9400
    /* 3F93EC 004F93EC 000062AC */   sw        $2, 0x0($3)
    /* 3F93F0 004F93F0 0000BFDF */  ld         $31, 0x0($29)
    /* 3F93F4 004F93F4 BEE21308 */  j          func_004f8af8
    /* 3F93F8 004F93F8 1000BD27 */   addiu     $29, $29, 0x10
    /* 3F93FC 004F93FC 00000000 */  nop
  .L004F9400:
    /* 3F9400 004F9400 0000BFDF */  ld         $31, 0x0($29)
    /* 3F9404 004F9404 0800E003 */  jr         $31
    /* 3F9408 004F9408 1000BD27 */   addiu     $29, $29, 0x10
    /* 3F940C 004F940C 00000000 */  nop
.size func_004f93d0, 0x40
