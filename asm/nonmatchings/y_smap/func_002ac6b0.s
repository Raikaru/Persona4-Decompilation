.section .text
.set noat
.set noreorder
glabel func_002ac6b0
    /* 1AC6B0 002AC6B0 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 1AC6B4 002AC6B4 1000BFFF */  sd         $31, 0x10($29)
    /* 1AC6B8 002AC6B8 0000B07F */  sq         $16, 0x0($29)
    /* 1AC6BC 002AC6BC 6400043C */  lui        $4, %hi(D_0063EF60)
    /* 1AC6C0 002AC6C0 60EF8424 */  addiu      $4, $4, %lo(D_0063EF60)
    /* 1AC6C4 002AC6C4 D5000524 */  addiu      $5, $0, 0xD5
    /* 1AC6C8 002AC6C8 A43A110C */  jal        func_0044ea90
    /* 1AC6CC 002AC6CC 00000000 */   nop
    /* 1AC6D0 002AC6D0 01000424 */  addiu      $4, $0, 0x1
    /* 1AC6D4 002AC6D4 0C000524 */  addiu      $5, $0, 0xC
    /* 1AC6D8 002AC6D8 0400063C */  lui        $6, (0x40000 >> 16)
    /* 1AC6DC 002AC6DC 8800023C */  lui        $2, %hi(D_008873F4)
    /* 1AC6E0 002AC6E0 F473428C */  lw         $2, %lo(D_008873F4)($2)
    /* 1AC6E4 002AC6E4 09F84000 */  jalr       $2
    /* 1AC6E8 002AC6E8 00000000 */   nop
    /* 1AC6EC 002AC6EC 2D804000 */  daddu      $16, $2, $0
    /* 1AC6F0 002AC6F0 6400043C */  lui        $4, %hi(D_0063EFC8)
    /* 1AC6F4 002AC6F4 C8EF8424 */  addiu      $4, $4, %lo(D_0063EFC8)
    /* 1AC6F8 002AC6F8 0F000524 */  addiu      $5, $0, 0xF
    /* 1AC6FC 002AC6FC 2D300000 */  daddu      $6, $0, $0
    /* 1AC700 002AC700 2D380000 */  daddu      $7, $0, $0
    /* 1AC704 002AC704 2B00083C */  lui        $8, %hi(func_002ac400)
    /* 1AC708 002AC708 00C40825 */  addiu      $8, $8, %lo(func_002ac400)
    /* 1AC70C 002AC70C 2B00093C */  lui        $9, %hi(func_002ac600)
    /* 1AC710 002AC710 00C62925 */  addiu      $9, $9, %lo(func_002ac600)
    /* 1AC714 002AC714 2D500002 */  daddu      $10, $16, $0
    /* 1AC718 002AC718 7847110C */  jal        func_00451de0
    /* 1AC71C 002AC71C 00000000 */   nop
    /* 1AC720 002AC720 60B582AF */  sw         $2, -0x4AA0($28)
    /* 1AC724 002AC724 040000A2 */  sb         $0, 0x4($16)
    /* 1AC728 002AC728 1000BFDF */  ld         $31, 0x10($29)
    /* 1AC72C 002AC72C 0000B07B */  lq         $16, 0x0($29)
    /* 1AC730 002AC730 2000BD27 */  addiu      $29, $29, 0x20
    /* 1AC734 002AC734 0800E003 */  jr         $31
    /* 1AC738 002AC738 00000000 */   nop
    /* 1AC73C 002AC73C 00000000 */  nop
.size func_002ac6b0, 0x90
