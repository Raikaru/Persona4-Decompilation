.section .text
.set noat
.set noreorder
glabel func_004d89d0
    /* 3D89D0 004D89D0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3D89D4 004D89D4 2D108000 */  daddu      $2, $4, $0
    /* 3D89D8 004D89D8 07004010 */  beqz       $2, .L004D89F8
    /* 3D89DC 004D89DC 0000BFFF */   sd        $31, 0x0($29)
    /* 3D89E0 004D89E0 0000BFDF */  ld         $31, 0x0($29)
    /* 3D89E4 004D89E4 2D280000 */  daddu      $5, $0, $0
    /* 3D89E8 004D89E8 3C000624 */  addiu      $6, $0, 0x3C
    /* 3D89EC 004D89EC 000040AC */  sw         $0, 0x0($2)
    /* 3D89F0 004D89F0 72FE1008 */  j          func_0043f9c8
    /* 3D89F4 004D89F4 1000BD27 */   addiu     $29, $29, 0x10
  .L004D89F8:
    /* 3D89F8 004D89F8 0000BFDF */  ld         $31, 0x0($29)
    /* 3D89FC 004D89FC 0800E003 */  jr         $31
    /* 3D8A00 004D8A00 1000BD27 */   addiu     $29, $29, 0x10
    /* 3D8A04 004D8A04 00000000 */  nop
.size func_004d89d0, 0x38
