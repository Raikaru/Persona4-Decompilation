.section .text
.set noat
.set noreorder
glabel func_004c3d70
    /* 3C3D70 004C3D70 D0FFBD27 */  addiu      $29, $29, -0x30
    /* 3C3D74 004C3D74 1000B0FF */  sd         $16, 0x10($29)
    /* 3C3D78 004C3D78 2D80A000 */  daddu      $16, $5, $0
    /* 3C3D7C 004C3D7C 1800B1FF */  sd         $17, 0x18($29)
    /* 3C3D80 004C3D80 2D888000 */  daddu      $17, $4, $0
    /* 3C3D84 004C3D84 2000BFFF */  sd         $31, 0x20($29)
    /* 3C3D88 004C3D88 520A110C */  jal        func_00442948
    /* 3C3D8C 004C3D8C 2D200002 */   daddu     $4, $16, $0
    /* 3C3D90 004C3D90 2D200002 */  daddu      $4, $16, $0
    /* 3C3D94 004C3D94 2D284000 */  daddu      $5, $2, $0
    /* 3C3D98 004C3D98 2D30A003 */  daddu      $6, $29, $0
    /* 3C3D9C 004C3D9C 0200A727 */  addiu      $7, $29, 0x2
    /* 3C3DA0 004C3DA0 6E0C130C */  jal        func_004c31b8
    /* 3C3DA4 004C3DA4 0400A827 */   addiu     $8, $29, 0x4
    /* 3C3DA8 004C3DA8 0000A397 */  lhu        $3, 0x0($29)
    /* 3C3DAC 004C3DAC 0200A497 */  lhu        $4, 0x2($29)
    /* 3C3DB0 004C3DB0 0400A297 */  lhu        $2, 0x4($29)
    /* 3C3DB4 004C3DB4 1000B0DF */  ld         $16, 0x10($29)
    /* 3C3DB8 004C3DB8 A00023A6 */  sh         $3, 0xA0($17)
    /* 3C3DBC 004C3DBC A40022A6 */  sh         $2, 0xA4($17)
    /* 3C3DC0 004C3DC0 A20024A6 */  sh         $4, 0xA2($17)
    /* 3C3DC4 004C3DC4 2000BFDF */  ld         $31, 0x20($29)
    /* 3C3DC8 004C3DC8 1800B1DF */  ld         $17, 0x18($29)
    /* 3C3DCC 004C3DCC 0800E003 */  jr         $31
    /* 3C3DD0 004C3DD0 3000BD27 */   addiu     $29, $29, 0x30
    /* 3C3DD4 004C3DD4 00000000 */  nop
.size func_004c3d70, 0x68
