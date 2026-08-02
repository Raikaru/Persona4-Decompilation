.section .text
.set noat
.set noreorder
glabel func_002b6da0
    /* 1B6DA0 002B6DA0 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 1B6DA4 002B6DA4 1000BFFF */  sd         $31, 0x10($29)
    /* 1B6DA8 002B6DA8 0000B07F */  sq         $16, 0x0($29)
    /* 1B6DAC 002B6DAC 8800103C */  lui        $16, %hi(D_00887300)
    /* 1B6DB0 002B6DB0 00731026 */  addiu      $16, $16, %lo(D_00887300)
    /* 1B6DB4 002B6DB4 06000424 */  addiu      $4, $0, 0x6
    /* 1B6DB8 002B6DB8 01000524 */  addiu      $5, $0, 0x1
    /* 1B6DBC 002B6DBC 0000028E */  lw         $2, 0x0($16)
    /* 1B6DC0 002B6DC0 09F84000 */  jalr       $2
    /* 1B6DC4 002B6DC4 00000000 */   nop
    /* 1B6DC8 002B6DC8 07000424 */  addiu      $4, $0, 0x7
    /* 1B6DCC 002B6DCC 02000524 */  addiu      $5, $0, 0x2
    /* 1B6DD0 002B6DD0 0000028E */  lw         $2, 0x0($16)
    /* 1B6DD4 002B6DD4 09F84000 */  jalr       $2
    /* 1B6DD8 002B6DD8 00000000 */   nop
    /* 1B6DDC 002B6DDC 08000424 */  addiu      $4, $0, 0x8
    /* 1B6DE0 002B6DE0 01000524 */  addiu      $5, $0, 0x1
    /* 1B6DE4 002B6DE4 0000028E */  lw         $2, 0x0($16)
    /* 1B6DE8 002B6DE8 09F84000 */  jalr       $2
    /* 1B6DEC 002B6DEC 00000000 */   nop
    /* 1B6DF0 002B6DF0 0A000424 */  addiu      $4, $0, 0xA
    /* 1B6DF4 002B6DF4 05000524 */  addiu      $5, $0, 0x5
    /* 1B6DF8 002B6DF8 0000028E */  lw         $2, 0x0($16)
    /* 1B6DFC 002B6DFC 09F84000 */  jalr       $2
    /* 1B6E00 002B6E00 00000000 */   nop
    /* 1B6E04 002B6E04 0B000424 */  addiu      $4, $0, 0xB
    /* 1B6E08 002B6E08 06000524 */  addiu      $5, $0, 0x6
    /* 1B6E0C 002B6E0C 0000028E */  lw         $2, 0x0($16)
    /* 1B6E10 002B6E10 09F84000 */  jalr       $2
    /* 1B6E14 002B6E14 00000000 */   nop
    /* 1B6E18 002B6E18 09000424 */  addiu      $4, $0, 0x9
    /* 1B6E1C 002B6E1C 02000524 */  addiu      $5, $0, 0x2
    /* 1B6E20 002B6E20 0000028E */  lw         $2, 0x0($16)
    /* 1B6E24 002B6E24 09F84000 */  jalr       $2
    /* 1B6E28 002B6E28 00000000 */   nop
    /* 1B6E2C 002B6E2C 0C000424 */  addiu      $4, $0, 0xC
    /* 1B6E30 002B6E30 01000524 */  addiu      $5, $0, 0x1
    /* 1B6E34 002B6E34 0000028E */  lw         $2, 0x0($16)
    /* 1B6E38 002B6E38 09F84000 */  jalr       $2
    /* 1B6E3C 002B6E3C 00000000 */   nop
    /* 1B6E40 002B6E40 01000424 */  addiu      $4, $0, 0x1
    /* 1B6E44 002B6E44 2D280000 */  daddu      $5, $0, $0
    /* 1B6E48 002B6E48 0000028E */  lw         $2, 0x0($16)
    /* 1B6E4C 002B6E4C 09F84000 */  jalr       $2
    /* 1B6E50 002B6E50 00000000 */   nop
    /* 1B6E54 002B6E54 03000424 */  addiu      $4, $0, 0x3
    /* 1B6E58 002B6E58 0700023C */  lui        $2, (0x717FB >> 16)
    /* 1B6E5C 002B6E5C FB174534 */  ori        $5, $2, (0x717FB & 0xFFFF)
    /* 1B6E60 002B6E60 10D90F0C */  jal        func_003f6440
    /* 1B6E64 002B6E64 00000000 */   nop
    /* 1B6E68 002B6E68 02000424 */  addiu      $4, $0, 0x2
    /* 1B6E6C 002B6E6C 44000524 */  addiu      $5, $0, 0x44
    /* 1B6E70 002B6E70 10D90F0C */  jal        func_003f6440
    /* 1B6E74 002B6E74 00000000 */   nop
    /* 1B6E78 002B6E78 E027120C */  jal        func_00489f80
    /* 1B6E7C 002B6E7C 00000000 */   nop
    /* 1B6E80 002B6E80 1000BFDF */  ld         $31, 0x10($29)
    /* 1B6E84 002B6E84 0000B07B */  lq         $16, 0x0($29)
    /* 1B6E88 002B6E88 2000BD27 */  addiu      $29, $29, 0x20
    /* 1B6E8C 002B6E8C 0800E003 */  jr         $31
    /* 1B6E90 002B6E90 00000000 */   nop
    /* 1B6E94 002B6E94 00000000 */  nop
    /* 1B6E98 002B6E98 00000000 */  nop
    /* 1B6E9C 002B6E9C 00000000 */  nop
.size func_002b6da0, 0x100
