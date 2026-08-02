.section .text
.set noat
.set noreorder
glabel func_0025ccb0
    /* 15CCB0 0025CCB0 D0FFBD27 */  addiu      $29, $29, -0x30
    /* 15CCB4 0025CCB4 2000BFFF */  sd         $31, 0x20($29)
    /* 15CCB8 0025CCB8 1000B17F */  sq         $17, 0x10($29)
    /* 15CCBC 0025CCBC 0000B07F */  sq         $16, 0x0($29)
    /* 15CCC0 0025CCC0 08740A0C */  jal        func_0029d020
    /* 15CCC4 0025CCC4 00000000 */   nop
    /* 15CCC8 0025CCC8 28004014 */  bnez       $2, .L0025CD6C
    /* 15CCCC 0025CCCC 00000000 */   nop
    /* 15CCD0 0025CCD0 2D200000 */  daddu      $4, $0, $0
    /* 15CCD4 0025CCD4 00730A0C */  jal        func_0029cc00
    /* 15CCD8 0025CCD8 00000000 */   nop
    /* 15CCDC 0025CCDC 2D884000 */  daddu      $17, $2, $0
    /* 15CCE0 0025CCE0 01000424 */  addiu      $4, $0, 0x1
    /* 15CCE4 0025CCE4 00730A0C */  jal        func_0029cc00
    /* 15CCE8 0025CCE8 00000000 */   nop
    /* 15CCEC 0025CCEC 2D804000 */  daddu      $16, $2, $0
    /* 15CCF0 0025CCF0 6300043C */  lui        $4, %hi(D_00636838)
    /* 15CCF4 0025CCF4 38688424 */  addiu      $4, $4, %lo(D_00636838)
    /* 15CCF8 0025CCF8 13010524 */  addiu      $5, $0, 0x113
    /* 15CCFC 0025CCFC A43A110C */  jal        func_0044ea90
    /* 15CD00 0025CD00 00000000 */   nop
    /* 15CD04 0025CD04 01000424 */  addiu      $4, $0, 0x1
    /* 15CD08 0025CD08 10000524 */  addiu      $5, $0, 0x10
    /* 15CD0C 0025CD0C 0400063C */  lui        $6, (0x40000 >> 16)
    /* 15CD10 0025CD10 8800023C */  lui        $2, %hi(D_008873F4)
    /* 15CD14 0025CD14 F473428C */  lw         $2, %lo(D_008873F4)($2)
    /* 15CD18 0025CD18 09F84000 */  jalr       $2
    /* 15CD1C 0025CD1C 00000000 */   nop
    /* 15CD20 0025CD20 2D584000 */  daddu      $11, $2, $0
    /* 15CD24 0025CD24 040051AC */  sw         $17, 0x4($2)
    /* 15CD28 0025CD28 080050AC */  sw         $16, 0x8($2)
    /* 15CD2C 0025CD2C FFFF0324 */  addiu      $3, $0, -0x1
    /* 15CD30 0025CD30 0C0043AC */  sw         $3, 0xC($2)
    /* 15CD34 0025CD34 2D200000 */  daddu      $4, $0, $0
    /* 15CD38 0025CD38 6300053C */  lui        $5, %hi(D_00636A30)
    /* 15CD3C 0025CD3C 306AA524 */  addiu      $5, $5, %lo(D_00636A30)
    /* 15CD40 0025CD40 0F000624 */  addiu      $6, $0, 0xF
    /* 15CD44 0025CD44 2D380000 */  daddu      $7, $0, $0
    /* 15CD48 0025CD48 2D400000 */  daddu      $8, $0, $0
    /* 15CD4C 0025CD4C 2600093C */  lui        $9, %hi(func_0025c790)
    /* 15CD50 0025CD50 90C72925 */  addiu      $9, $9, %lo(func_0025c790)
    /* 15CD54 0025CD54 26000A3C */  lui        $10, %hi(func_0025cb80)
    /* 15CD58 0025CD58 80CB4A25 */  addiu      $10, $10, %lo(func_0025cb80)
    /* 15CD5C 0025CD5C F047110C */  jal        func_00451fc0
    /* 15CD60 0025CD60 00000000 */   nop
    /* 15CD64 0025CD64 11000010 */  b          .L0025CDAC
    /* 15CD68 0025CD68 00000000 */   nop
  .L0025CD6C:
    /* 15CD6C 0025CD6C 6300043C */  lui        $4, %hi(D_00636A30)
    /* 15CD70 0025CD70 306A8424 */  addiu      $4, $4, %lo(D_00636A30)
    /* 15CD74 0025CD74 E048110C */  jal        func_00452380
    /* 15CD78 0025CD78 00000000 */   nop
    /* 15CD7C 0025CD7C 2D204000 */  daddu      $4, $2, $0
    /* 15CD80 0025CD80 2449110C */  jal        func_00452490
    /* 15CD84 0025CD84 00000000 */   nop
    /* 15CD88 0025CD88 2B100200 */  sltu       $2, $0, $2
    /* 15CD8C 0025CD8C 07004014 */  bnez       $2, .L0025CDAC
    /* 15CD90 0025CD90 00000000 */   nop
    /* 15CD94 0025CD94 2D200000 */  daddu      $4, $0, $0
    /* 15CD98 0025CD98 D4730A0C */  jal        func_0029cf50
    /* 15CD9C 0025CD9C 00000000 */   nop
    /* 15CDA0 0025CDA0 01000224 */  addiu      $2, $0, 0x1
    /* 15CDA4 0025CDA4 02000010 */  b          .L0025CDB0
    /* 15CDA8 0025CDA8 00000000 */   nop
  .L0025CDAC:
    /* 15CDAC 0025CDAC 2D100000 */  daddu      $2, $0, $0
  .L0025CDB0:
    /* 15CDB0 0025CDB0 2000BFDF */  ld         $31, 0x20($29)
    /* 15CDB4 0025CDB4 1000B17B */  lq         $17, 0x10($29)
    /* 15CDB8 0025CDB8 0000B07B */  lq         $16, 0x0($29)
    /* 15CDBC 0025CDBC 3000BD27 */  addiu      $29, $29, 0x30
    /* 15CDC0 0025CDC0 0800E003 */  jr         $31
    /* 15CDC4 0025CDC4 00000000 */   nop
    /* 15CDC8 0025CDC8 00000000 */  nop
    /* 15CDCC 0025CDCC 00000000 */  nop
.size func_0025ccb0, 0x120
