.section .text
.set noat
.set noreorder
glabel func_0025cdd0
    /* 15CDD0 0025CDD0 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 15CDD4 0025CDD4 1000BFFF */  sd         $31, 0x10($29)
    /* 15CDD8 0025CDD8 0000B07F */  sq         $16, 0x0($29)
    /* 15CDDC 0025CDDC 2D200000 */  daddu      $4, $0, $0
    /* 15CDE0 0025CDE0 00730A0C */  jal        func_0029cc00
    /* 15CDE4 0025CDE4 00000000 */   nop
    /* 15CDE8 0025CDE8 2D804000 */  daddu      $16, $2, $0
    /* 15CDEC 0025CDEC 01000424 */  addiu      $4, $0, 0x1
    /* 15CDF0 0025CDF0 54730A0C */  jal        func_0029cd50
    /* 15CDF4 0025CDF4 00000000 */   nop
    /* 15CDF8 0025CDF8 3C241000 */  dsll32     $4, $16, 16
    /* 15CDFC 0025CDFC 3F240400 */  dsra32     $4, $4, 16
    /* 15CE00 0025CE00 06030046 */  mov.s      $f12, $f0
    /* 15CE04 0025CE04 0414040C */  jal        func_00105010
    /* 15CE08 0025CE08 00000000 */   nop
    /* 15CE0C 0025CE0C 3C240200 */  dsll32     $4, $2, 16
    /* 15CE10 0025CE10 3F240400 */  dsra32     $4, $4, 16
    /* 15CE14 0025CE14 D4730A0C */  jal        func_0029cf50
    /* 15CE18 0025CE18 00000000 */   nop
    /* 15CE1C 0025CE1C 01000224 */  addiu      $2, $0, 0x1
    /* 15CE20 0025CE20 1000BFDF */  ld         $31, 0x10($29)
    /* 15CE24 0025CE24 0000B07B */  lq         $16, 0x0($29)
    /* 15CE28 0025CE28 2000BD27 */  addiu      $29, $29, 0x20
    /* 15CE2C 0025CE2C 0800E003 */  jr         $31
    /* 15CE30 0025CE30 00000000 */   nop
    /* 15CE34 0025CE34 00000000 */  nop
    /* 15CE38 0025CE38 00000000 */  nop
    /* 15CE3C 0025CE3C 00000000 */  nop
.size func_0025cdd0, 0x70
