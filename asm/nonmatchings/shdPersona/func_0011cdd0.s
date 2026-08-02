.section .text
.set noat
.set noreorder
glabel func_0011cdd0
    /* 1CDD0 0011CDD0 D0FFBD27 */  addiu      $29, $29, -0x30
    /* 1CDD4 0011CDD4 2000BFFF */  sd         $31, 0x20($29)
    /* 1CDD8 0011CDD8 1000B17F */  sq         $17, 0x10($29)
    /* 1CDDC 0011CDDC 0000B07F */  sq         $16, 0x0($29)
    /* 1CDE0 0011CDE0 2D88A000 */  daddu      $17, $5, $0
    /* 1CDE4 0011CDE4 3800908C */  lw         $16, 0x38($4)
    /* 1CDE8 0011CDE8 3405038E */  lw         $3, 0x534($16)
    /* 1CDEC 0011CDEC 1000023C */  lui        $2, (0x100000 >> 16)
    /* 1CDF0 0011CDF0 25106200 */  or         $2, $3, $2
    /* 1CDF4 0011CDF4 340502AE */  sw         $2, 0x534($16)
    /* 1CDF8 0011CDF8 F0040426 */  addiu      $4, $16, 0x4F0
    /* 1CDFC 0011CDFC 2D280000 */  daddu      $5, $0, $0
    /* 1CE00 0011CE00 06000624 */  addiu      $6, $0, 0x6
    /* 1CE04 0011CE04 72FE100C */  jal        func_0043f9c8
    /* 1CE08 0011CE08 00000000 */   nop
    /* 1CE0C 0011CE0C F40411A6 */  sh         $17, 0x4F4($16)
    /* 1CE10 0011CE10 2000BFDF */  ld         $31, 0x20($29)
    /* 1CE14 0011CE14 1000B17B */  lq         $17, 0x10($29)
    /* 1CE18 0011CE18 0000B07B */  lq         $16, 0x0($29)
    /* 1CE1C 0011CE1C 3000BD27 */  addiu      $29, $29, 0x30
    /* 1CE20 0011CE20 0800E003 */  jr         $31
    /* 1CE24 0011CE24 00000000 */   nop
    /* 1CE28 0011CE28 00000000 */  nop
    /* 1CE2C 0011CE2C 00000000 */  nop
.size func_0011cdd0, 0x60
