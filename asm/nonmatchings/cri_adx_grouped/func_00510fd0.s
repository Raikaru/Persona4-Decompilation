.section .text
.set noat
.set noreorder
glabel func_00510fd0
    /* 410FD0 00510FD0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 410FD4 00510FD4 9300023C */  lui        $2, %hi(D_00932C84)
    /* 410FD8 00510FD8 0000BFFF */  sd         $31, 0x0($29)
    /* 410FDC 00510FDC 02000424 */  addiu      $4, $0, 0x2
    /* 410FE0 00510FE0 842C458C */  lw         $5, %lo(D_00932C84)($2)
    /* 410FE4 00510FE4 0000BFDF */  ld         $31, 0x0($29)
    /* 410FE8 00510FE8 E2C21308 */  j          func_004f0b88
    /* 410FEC 00510FEC 1000BD27 */   addiu     $29, $29, 0x10
.size func_00510fd0, 0x20
