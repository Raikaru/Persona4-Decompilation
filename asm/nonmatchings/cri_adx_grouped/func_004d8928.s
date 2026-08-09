.section .text
.set noat
.set noreorder
glabel func_004d8928
    /* 3D8928 004D8928 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3D892C 004D892C 2D108000 */  daddu      $2, $4, $0
    /* 3D8930 004D8930 0000BFFF */  sd         $31, 0x0($29)
    /* 3D8934 004D8934 32004724 */  addiu      $7, $2, 0x32
    /* 3D8938 004D8938 2D20C000 */  daddu      $4, $6, $0
    /* 3D893C 004D893C 30004624 */  addiu      $6, $2, 0x30
    /* 3D8940 004D8940 0000BFDF */  ld         $31, 0x0($29)
    /* 3D8944 004D8944 3A151308 */  j          func_004c54e8
    /* 3D8948 004D8948 1000BD27 */   addiu     $29, $29, 0x10
    /* 3D894C 004D894C 00000000 */  nop
.size func_004d8928, 0x28
