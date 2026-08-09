.section .text
.set noat
.set noreorder
glabel func_0021dda0
    /* 11DDA0 0021DDA0 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 11DDA4 0021DDA4 1000BFFF */  sd         $31, 0x10($29)
    /* 11DDA8 0021DDA8 0000B07F */  sq         $16, 0x0($29)
    /* 11DDAC 0021DDAC 6300043C */  lui        $4, %hi(D_006290E0)
    /* 11DDB0 0021DDB0 E0908424 */  addiu      $4, $4, %lo(D_006290E0)
    /* 11DDB4 0021DDB4 E048110C */  jal        func_00452380
    /* 11DDB8 0021DDB8 00000000 */   nop
    /* 11DDBC 0021DDBC 22004014 */  bnez       $2, .L0021DE48
    /* 11DDC0 0021DDC0 00000000 */   nop
    /* 11DDC4 0021DDC4 6300043C */  lui        $4, %hi(D_006290D0)
    /* 11DDC8 0021DDC8 D0908424 */  addiu      $4, $4, %lo(D_006290D0)
    /* 11DDCC 0021DDCC 3A000524 */  addiu      $5, $0, 0x3A
    /* 11DDD0 0021DDD0 A43A110C */  jal        func_0044ea90
    /* 11DDD4 0021DDD4 00000000 */   nop
    /* 11DDD8 0021DDD8 34000424 */  addiu      $4, $0, 0x34
    /* 11DDDC 0021DDDC 0400053C */  lui        $5, (0x40000 >> 16)
    /* 11DDE0 0021DDE0 8800023C */  lui        $2, %hi(jtbl_008873E8)
    /* 11DDE4 0021DDE4 E873428C */  lw         $2, %lo(jtbl_008873E8)($2)
    /* 11DDE8 0021DDE8 09F84000 */  jalr       $2
    /* 11DDEC 0021DDEC 00000000 */   nop
    /* 11DDF0 0021DDF0 2D804000 */  daddu      $16, $2, $0
    /* 11DDF4 0021DDF4 2D200002 */  daddu      $4, $16, $0
    /* 11DDF8 0021DDF8 2D280000 */  daddu      $5, $0, $0
    /* 11DDFC 0021DDFC 34000624 */  addiu      $6, $0, 0x34
    /* 11DE00 0021DE00 72FE100C */  jal        func_0043f9c8
    /* 11DE04 0021DE04 00000000 */   nop
    /* 11DE08 0021DE08 6300043C */  lui        $4, %hi(D_006290E0)
    /* 11DE0C 0021DE0C E0908424 */  addiu      $4, $4, %lo(D_006290E0)
    /* 11DE10 0021DE10 10000524 */  addiu      $5, $0, 0x10
    /* 11DE14 0021DE14 2D300000 */  daddu      $6, $0, $0
    /* 11DE18 0021DE18 2D380000 */  daddu      $7, $0, $0
    /* 11DE1C 0021DE1C 2200083C */  lui        $8, %hi(func_0021dba0)
    /* 11DE20 0021DE20 A0DB0825 */  addiu      $8, $8, %lo(func_0021dba0)
    /* 11DE24 0021DE24 2200093C */  lui        $9, %hi(func_0021dd60)
    /* 11DE28 0021DE28 60DD2925 */  addiu      $9, $9, %lo(func_0021dd60)
    /* 11DE2C 0021DE2C 2D500002 */  daddu      $10, $16, $0
    /* 11DE30 0021DE30 7847110C */  jal        func_00451de0
    /* 11DE34 0021DE34 00000000 */   nop
    /* 11DE38 0021DE38 2200033C */  lui        $3, %hi(func_0021dc50)
    /* 11DE3C 0021DE3C 50DC6324 */  addiu      $3, $3, %lo(func_0021dc50)
    /* 11DE40 0021DE40 0C0003AE */  sw         $3, 0xC($16)
    /* 11DE44 0021DE44 140010AE */  sw         $16, 0x14($16)
  .L0021DE48:
    /* 11DE48 0021DE48 1000BFDF */  ld         $31, 0x10($29)
    /* 11DE4C 0021DE4C 0000B07B */  lq         $16, 0x0($29)
    /* 11DE50 0021DE50 2000BD27 */  addiu      $29, $29, 0x20
    /* 11DE54 0021DE54 0800E003 */  jr         $31
    /* 11DE58 0021DE58 00000000 */   nop
    /* 11DE5C 0021DE5C 00000000 */  nop
.size func_0021dda0, 0xc0
