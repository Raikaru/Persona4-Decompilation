.section .text
.set noat
.set noreorder
glabel func_004d6fb8
    /* 3D6FB8 004D6FB8 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3D6FBC 004D6FBC 0F00073C */  lui        $7, (0xFFFFF >> 16)
    /* 3D6FC0 004D6FC0 0000BFFF */  sd         $31, 0x0($29)
    /* 3D6FC4 004D6FC4 2D300000 */  daddu      $6, $0, $0
    /* 3D6FC8 004D6FC8 FFFFE734 */  ori        $7, $7, (0xFFFFF & 0xFFFF)
    /* 3D6FCC 004D6FCC 0000BFDF */  ld         $31, 0x0($29)
    /* 3D6FD0 004D6FD0 B05B1308 */  j          func_004d6ec0
    /* 3D6FD4 004D6FD4 1000BD27 */   addiu     $29, $29, 0x10
.size func_004d6fb8, 0x20
