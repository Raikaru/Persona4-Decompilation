.section .text
.set noat
.set noreorder
glabel func_0025cbc0
    /* 15CBC0 0025CBC0 C0FFBD27 */  addiu      $29, $29, -0x40
    /* 15CBC4 0025CBC4 3000BFFF */  sd         $31, 0x30($29)
    /* 15CBC8 0025CBC8 2000B27F */  sq         $18, 0x20($29)
    /* 15CBCC 0025CBCC 1000B17F */  sq         $17, 0x10($29)
    /* 15CBD0 0025CBD0 0000B07F */  sq         $16, 0x0($29)
    /* 15CBD4 0025CBD4 2D908000 */  daddu      $18, $4, $0
    /* 15CBD8 0025CBD8 2D88A000 */  daddu      $17, $5, $0
    /* 15CBDC 0025CBDC 2D80C000 */  daddu      $16, $6, $0
    /* 15CBE0 0025CBE0 6300043C */  lui        $4, %hi(D_00636838)
    /* 15CBE4 0025CBE4 38688424 */  addiu      $4, $4, %lo(D_00636838)
    /* 15CBE8 0025CBE8 13010524 */  addiu      $5, $0, 0x113
    /* 15CBEC 0025CBEC A43A110C */  jal        func_0044ea90
    /* 15CBF0 0025CBF0 00000000 */   nop
    /* 15CBF4 0025CBF4 01000424 */  addiu      $4, $0, 0x1
    /* 15CBF8 0025CBF8 10000524 */  addiu      $5, $0, 0x10
    /* 15CBFC 0025CBFC 0400063C */  lui        $6, (0x40000 >> 16)
    /* 15CC00 0025CC00 8800023C */  lui        $2, %hi(D_008873F4)
    /* 15CC04 0025CC04 F473428C */  lw         $2, %lo(D_008873F4)($2)
    /* 15CC08 0025CC08 09F84000 */  jalr       $2
    /* 15CC0C 0025CC0C 00000000 */   nop
    /* 15CC10 0025CC10 2D584000 */  daddu      $11, $2, $0
    /* 15CC14 0025CC14 040051AC */  sw         $17, 0x4($2)
    /* 15CC18 0025CC18 080050AC */  sw         $16, 0x8($2)
    /* 15CC1C 0025CC1C FFFF0324 */  addiu      $3, $0, -0x1
    /* 15CC20 0025CC20 0C0043AC */  sw         $3, 0xC($2)
    /* 15CC24 0025CC24 2D204002 */  daddu      $4, $18, $0
    /* 15CC28 0025CC28 6300053C */  lui        $5, %hi(D_00636A30)
    /* 15CC2C 0025CC2C 306AA524 */  addiu      $5, $5, %lo(D_00636A30)
    /* 15CC30 0025CC30 0F000624 */  addiu      $6, $0, 0xF
    /* 15CC34 0025CC34 2D380000 */  daddu      $7, $0, $0
    /* 15CC38 0025CC38 2D400000 */  daddu      $8, $0, $0
    /* 15CC3C 0025CC3C 2600093C */  lui        $9, %hi(func_0025c790)
    /* 15CC40 0025CC40 90C72925 */  addiu      $9, $9, %lo(func_0025c790)
    /* 15CC44 0025CC44 26000A3C */  lui        $10, %hi(func_0025cb80)
    /* 15CC48 0025CC48 80CB4A25 */  addiu      $10, $10, %lo(func_0025cb80)
    /* 15CC4C 0025CC4C F047110C */  jal        func_00451fc0
    /* 15CC50 0025CC50 00000000 */   nop
    /* 15CC54 0025CC54 3000BFDF */  ld         $31, 0x30($29)
    /* 15CC58 0025CC58 2000B27B */  lq         $18, 0x20($29)
    /* 15CC5C 0025CC5C 1000B17B */  lq         $17, 0x10($29)
    /* 15CC60 0025CC60 0000B07B */  lq         $16, 0x0($29)
    /* 15CC64 0025CC64 4000BD27 */  addiu      $29, $29, 0x40
    /* 15CC68 0025CC68 0800E003 */  jr         $31
    /* 15CC6C 0025CC6C 00000000 */   nop
.size func_0025cbc0, 0xb0
