.section .text
.set noat
.set noreorder
glabel func_004d8fe8
    /* 3D8FE8 004D8FE8 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3D8FEC 004D8FEC 002E0500 */  sll        $5, $5, 24
    /* 3D8FF0 004D8FF0 0000BFFF */  sd         $31, 0x0($29)
    /* 3D8FF4 004D8FF4 032E0500 */  sra        $5, $5, 24
    /* 3D8FF8 004D8FF8 0000BFDF */  ld         $31, 0x0($29)
    /* 3D8FFC 004D8FFC CAFE1208 */  j          func_004bfb28
    /* 3D9000 004D9000 1000BD27 */   addiu     $29, $29, 0x10
    /* 3D9004 004D9004 00000000 */  nop
.size func_004d8fe8, 0x20
