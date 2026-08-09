.section .text
.set noat
.set noreorder
glabel func_004cb0e8
    /* 3CB0E8 004CB0E8 D0FFBD27 */  addiu      $29, $29, -0x30
    /* 3CB0EC 004CB0EC 0800B1FF */  sd         $17, 0x8($29)
    /* 3CB0F0 004CB0F0 2D888000 */  daddu      $17, $4, $0
    /* 3CB0F4 004CB0F4 1000B2FF */  sd         $18, 0x10($29)
    /* 3CB0F8 004CB0F8 2D90A000 */  daddu      $18, $5, $0
    /* 3CB0FC 004CB0FC 1800B3FF */  sd         $19, 0x18($29)
    /* 3CB100 004CB100 2D98C000 */  daddu      $19, $6, $0
    /* 3CB104 004CB104 0000B0FF */  sd         $16, 0x0($29)
    /* 3CB108 004CB108 07002012 */  beqz       $17, .L004CB128
    /* 3CB10C 004CB10C 2000BFFF */   sd        $31, 0x20($29)
    /* 3CB110 004CB110 0600405E */  bgtzl      $18, .L004CB12C
    /* 3CB114 004CB114 7600043C */   lui       $4, %hi(D_00758850)
    /* 3CB118 004CB118 0100023C */  lui        $2, (0x10000 >> 16)
    /* 3CB11C 004CB11C 2B105300 */  sltu       $2, $2, $19
    /* 3CB120 004CB120 0B004050 */  beql       $2, $0, .L004CB150
    /* 3CB124 004CB124 9400308E */   lw        $16, 0x94($17)
  .L004CB128:
    /* 3CB128 004CB128 7600043C */  lui        $4, %hi(D_00758850)
  .L004CB12C:
    /* 3CB12C 004CB12C 0000B0DF */  ld         $16, 0x0($29)
    /* 3CB130 004CB130 0800B1DF */  ld         $17, 0x8($29)
    /* 3CB134 004CB134 50888424 */  addiu      $4, $4, %lo(D_00758850)
    /* 3CB138 004CB138 1000B2DF */  ld         $18, 0x10($29)
    /* 3CB13C 004CB13C 1800B3DF */  ld         $19, 0x18($29)
    /* 3CB140 004CB140 2000BFDF */  ld         $31, 0x20($29)
    /* 3CB144 004CB144 A61A1308 */  j          func_004c6a98
    /* 3CB148 004CB148 3000BD27 */   addiu     $29, $29, 0x30
    /* 3CB14C 004CB14C 00000000 */  nop
  .L004CB150:
    /* 3CB150 004CB150 BEA4130C */  jal        func_004e92f8
    /* 3CB154 004CB154 2D200002 */   daddu     $4, $16, $0
    /* 3CB158 004CB158 2D202002 */  daddu      $4, $17, $0
    /* 3CB15C 004CB15C 2D306002 */  daddu      $6, $19, $0
    /* 3CB160 004CB160 442B130C */  jal        func_004cad10
    /* 3CB164 004CB164 2D284002 */   daddu     $5, $18, $0
    /* 3CB168 004CB168 2D200002 */  daddu      $4, $16, $0
    /* 3CB16C 004CB16C FAA5130C */  jal        func_004e97e8
    /* 3CB170 004CB170 01000524 */   addiu     $5, $0, 0x1
    /* 3CB174 004CB174 2D202002 */  daddu      $4, $17, $0
    /* 3CB178 004CB178 0000B0DF */  ld         $16, 0x0($29)
    /* 3CB17C 004CB17C 0800B1DF */  ld         $17, 0x8($29)
    /* 3CB180 004CB180 1000B2DF */  ld         $18, 0x10($29)
    /* 3CB184 004CB184 1800B3DF */  ld         $19, 0x18($29)
    /* 3CB188 004CB188 2000BFDF */  ld         $31, 0x20($29)
    /* 3CB18C 004CB18C 822B1308 */  j          func_004cae08
    /* 3CB190 004CB190 3000BD27 */   addiu     $29, $29, 0x30
    /* 3CB194 004CB194 00000000 */  nop
.size func_004cb0e8, 0xb0
