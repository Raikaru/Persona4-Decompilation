.section .text
.set noat
.set noreorder
glabel func_004d9dc0
    /* 3D9DC0 004D9DC0 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3D9DC4 004D9DC4 7300033C */  lui        $3, %hi(D_007288B8)
    /* 3D9DC8 004D9DC8 0000BFFF */  sd         $31, 0x0($29)
    /* 3D9DCC 004D9DCC B8886324 */  addiu      $3, $3, %lo(D_007288B8)
    /* 3D9DD0 004D9DD0 0000628C */  lw         $2, 0x0($3)
    /* 3D9DD4 004D9DD4 FFFF4224 */  addiu      $2, $2, -0x1
    /* 3D9DD8 004D9DD8 09004014 */  bnez       $2, .L004D9E00
    /* 3D9DDC 004D9DDC 000062AC */   sw        $2, 0x0($3)
    /* 3D9DE0 004D9DE0 7300043C */  lui        $4, %hi(D_007288E8)
    /* 3D9DE4 004D9DE4 2D280000 */  daddu      $5, $0, $0
    /* 3D9DE8 004D9DE8 E8888424 */  addiu      $4, $4, %lo(D_007288E8)
    /* 3D9DEC 004D9DEC 72FE100C */  jal        func_0043f9c8
    /* 3D9DF0 004D9DF0 40000624 */   addiu     $6, $0, 0x40
    /* 3D9DF4 004D9DF4 0000BFDF */  ld         $31, 0x0($29)
    /* 3D9DF8 004D9DF8 C6751308 */  j          func_004dd718
    /* 3D9DFC 004D9DFC 1000BD27 */   addiu     $29, $29, 0x10
  .L004D9E00:
    /* 3D9E00 004D9E00 0000BFDF */  ld         $31, 0x0($29)
    /* 3D9E04 004D9E04 0800E003 */  jr         $31
    /* 3D9E08 004D9E08 1000BD27 */   addiu     $29, $29, 0x10
    /* 3D9E0C 004D9E0C 00000000 */  nop
.size func_004d9dc0, 0x50
