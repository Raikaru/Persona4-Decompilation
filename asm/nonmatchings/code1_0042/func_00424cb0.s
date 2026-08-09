.section .text
.set noat
.set noreorder
glabel func_00424cb0
    /* 324CB0 00424CB0 2D10C000 */  daddu      $2, $6, $0
    /* 324CB4 00424CB4 2D18E000 */  daddu      $3, $7, $0
    /* 324CB8 00424CB8 2D580001 */  daddu      $11, $8, $0
    /* 324CBC 00424CBC F0FFBD27 */  addiu      $29, $29, -0x10
    /* 324CC0 00424CC0 2D502001 */  daddu      $10, $9, $0
    /* 324CC4 00424CC4 2D30A000 */  daddu      $6, $5, $0
    /* 324CC8 00424CC8 0000BFFF */  sd         $31, 0x0($29)
    /* 324CCC 00424CCC 2D384000 */  daddu      $7, $2, $0
    /* 324CD0 00424CD0 2D406000 */  daddu      $8, $3, $0
    /* 324CD4 00424CD4 2D486001 */  daddu      $9, $11, $0
    /* 324CD8 00424CD8 DE92100C */  jal        func_00424b78
    /* 324CDC 00424CDC 2D280000 */   daddu     $5, $0, $0
    /* 324CE0 00424CE0 0000BFDF */  ld         $31, 0x0($29)
    /* 324CE4 00424CE4 0800E003 */  jr         $31
    /* 324CE8 00424CE8 1000BD27 */   addiu     $29, $29, 0x10
    /* 324CEC 00424CEC 00000000 */  nop
.size func_00424cb0, 0x40
