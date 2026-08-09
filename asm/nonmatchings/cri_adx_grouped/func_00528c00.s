.section .text
.set noat
.set noreorder
glabel func_00528c00
    /* 428C00 00528C00 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 428C04 00528C04 2D10A000 */  daddu      $2, $5, $0
    /* 428C08 00528C08 0000BFFF */  sd         $31, 0x0($29)
    /* 428C0C 00528C0C 2D38C000 */  daddu      $7, $6, $0
    /* 428C10 00528C10 2D304000 */  daddu      $6, $2, $0
    /* 428C14 00528C14 D820858C */  lw         $5, 0x20D8($4)
    /* 428C18 00528C18 0000BFDF */  ld         $31, 0x0($29)
    /* 428C1C 00528C1C 34561408 */  j          func_005158d0
    /* 428C20 00528C20 1000BD27 */   addiu     $29, $29, 0x10
    /* 428C24 00528C24 00000000 */  nop
.size func_00528c00, 0x28
