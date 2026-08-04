.section .text
.set noat
.set noreorder
glabel func_0019e9f0
    /* 9E9F0 0019E9F0 D0FFBD27 */  addiu      $29, $29, -0x30
    /* 9E9F4 0019E9F4 2000BFFF */  sd         $31, 0x20($29)
    /* 9E9F8 0019E9F8 1000B17F */  sq         $17, 0x10($29)
    /* 9E9FC 0019E9FC 0000B07F */  sq         $16, 0x0($29)
    /* 9EA00 0019EA00 2D888000 */  daddu      $17, $4, $0
    /* 9EA04 0019EA04 2D80A000 */  daddu      $16, $5, $0
    /* 9EA08 0019EA08 1A010424 */  addiu      $4, $0, 0x11A
    /* 9EA0C 0019EA0C 08000524 */  addiu      $5, $0, 0x8
    /* 9EA10 0019EA10 1C51060C */  jal        func_00194470
    /* 9EA14 0019EA14 00000000 */   nop
    /* 9EA18 0019EA18 1A00033C */  lui        $3, %hi(func_0019e830)
    /* 9EA1C 0019EA1C 30E86324 */  addiu      $3, $3, %lo(func_0019e830)
    /* 9EA20 0019EA20 680043AC */  sw         $3, 0x68($2)
    /* 9EA24 0019EA24 1A00033C */  lui        $3, %hi(func_0019e850)
    /* 9EA28 0019EA28 50E86324 */  addiu      $3, $3, %lo(func_0019e850)
    /* 9EA2C 0019EA2C 6C0043AC */  sw         $3, 0x6C($2)
    /* 9EA30 0019EA30 1A00033C */  lui        $3, %hi(func_0019e9d0)
    /* 9EA34 0019EA34 D0E96324 */  addiu      $3, $3, %lo(func_0019e9d0)
    /* 9EA38 0019EA38 700043AC */  sw         $3, 0x70($2)
    /* 9EA3C 0019EA3C 7800438C */  lw         $3, 0x78($2)
    /* 9EA40 0019EA40 000071AC */  sw         $17, 0x0($3)
    /* 9EA44 0019EA44 040070A4 */  sh         $16, 0x4($3)
    /* 9EA48 0019EA48 2000BFDF */  ld         $31, 0x20($29)
    /* 9EA4C 0019EA4C 1000B17B */  lq         $17, 0x10($29)
    /* 9EA50 0019EA50 0000B07B */  lq         $16, 0x0($29)
    /* 9EA54 0019EA54 3000BD27 */  addiu      $29, $29, 0x30
    /* 9EA58 0019EA58 0800E003 */  jr         $31
    /* 9EA5C 0019EA5C 00000000 */   nop
.size func_0019e9f0, 0x70
