.section .text
.set noat
.set noreorder
glabel func_004d9478
    /* 3D9478 004D9478 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3D947C 004D947C 06008010 */  beqz       $4, .L004D9498
    /* 3D9480 004D9480 0000BFFF */   sd        $31, 0x0($29)
    /* 3D9484 004D9484 0000BFDF */  ld         $31, 0x0($29)
    /* 3D9488 004D9488 2D280000 */  daddu      $5, $0, $0
    /* 3D948C 004D948C 2C000624 */  addiu      $6, $0, 0x2C
    /* 3D9490 004D9490 72FE1008 */  j          func_0043f9c8
    /* 3D9494 004D9494 1000BD27 */   addiu     $29, $29, 0x10
  .L004D9498:
    /* 3D9498 004D9498 0000BFDF */  ld         $31, 0x0($29)
    /* 3D949C 004D949C 0800E003 */  jr         $31
    /* 3D94A0 004D94A0 1000BD27 */   addiu     $29, $29, 0x10
    /* 3D94A4 004D94A4 00000000 */  nop
.size func_004d9478, 0x30
