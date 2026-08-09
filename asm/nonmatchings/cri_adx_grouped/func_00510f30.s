.section .text
.set noat
.set noreorder
glabel func_00510f30
    /* 410F30 00510F30 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 410F34 00510F34 9300023C */  lui        $2, %hi(D_00932C80)
    /* 410F38 00510F38 0000BFFF */  sd         $31, 0x0($29)
    /* 410F3C 00510F3C 2D200000 */  daddu      $4, $0, $0
    /* 410F40 00510F40 802C458C */  lw         $5, %lo(D_00932C80)($2)
    /* 410F44 00510F44 0000BFDF */  ld         $31, 0x0($29)
    /* 410F48 00510F48 E2C21308 */  j          func_004f0b88
    /* 410F4C 00510F4C 1000BD27 */   addiu     $29, $29, 0x10
.size func_00510f30, 0x20
