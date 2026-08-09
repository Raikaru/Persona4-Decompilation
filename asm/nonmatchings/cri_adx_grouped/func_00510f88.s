.section .text
.set noat
.set noreorder
glabel func_00510f88
    /* 410F88 00510F88 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 410F8C 00510F8C 2D10A000 */  daddu      $2, $5, $0
    /* 410F90 00510F90 2D18C000 */  daddu      $3, $6, $0
    /* 410F94 00510F94 2D304000 */  daddu      $6, $2, $0
    /* 410F98 00510F98 0000B0FF */  sd         $16, 0x0($29)
    /* 410F9C 00510F9C 2D808000 */  daddu      $16, $4, $0
    /* 410FA0 00510FA0 2D280002 */  daddu      $5, $16, $0
    /* 410FA4 00510FA4 2D40E000 */  daddu      $8, $7, $0
    /* 410FA8 00510FA8 02000424 */  addiu      $4, $0, 0x2
    /* 410FAC 00510FAC 0800BFFF */  sd         $31, 0x8($29)
    /* 410FB0 00510FB0 1EC3130C */  jal        func_004f0c78
    /* 410FB4 00510FB4 2D386000 */   daddu     $7, $3, $0
    /* 410FB8 00510FB8 9300023C */  lui        $2, %hi(D_00932C84)
    /* 410FBC 00510FBC 0800BFDF */  ld         $31, 0x8($29)
    /* 410FC0 00510FC0 842C50AC */  sw         $16, %lo(D_00932C84)($2)
    /* 410FC4 00510FC4 0000B0DF */  ld         $16, 0x0($29)
    /* 410FC8 00510FC8 0800E003 */  jr         $31
    /* 410FCC 00510FCC 1000BD27 */   addiu     $29, $29, 0x10
.size func_00510f88, 0x48
