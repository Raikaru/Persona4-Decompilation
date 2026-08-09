.section .text
.set noat
.set noreorder
glabel func_004c6de8
    /* 3C6DE8 004C6DE8 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3C6DEC 004C6DEC 7100033C */  lui        $3, %hi(D_00715DA8)
    /* 3C6DF0 004C6DF0 0000BFFF */  sd         $31, 0x0($29)
    /* 3C6DF4 004C6DF4 A85D6324 */  addiu      $3, $3, %lo(D_00715DA8)
    /* 3C6DF8 004C6DF8 0000628C */  lw         $2, 0x0($3)
    /* 3C6DFC 004C6DFC FFFF4224 */  addiu      $2, $2, -0x1
    /* 3C6E00 004C6E00 27004014 */  bnez       $2, .L004C6EA0
    /* 3C6E04 004C6E04 000062AC */   sw        $2, 0x0($3)
    /* 3C6E08 004C6E08 D222130C */  jal        func_004c8b48
    /* 3C6E0C 004C6E0C 00000000 */   nop
    /* 3C6E10 004C6E10 71000C3C */  lui        $12, %hi(D_00716728)
    /* 3C6E14 004C6E14 7100043C */  lui        $4, %hi(D_007166F8)
    /* 3C6E18 004C6E18 01000A24 */  addiu      $10, $0, 0x1
    /* 3C6E1C 004C6E1C 71000B3C */  lui        $11, %hi(D_00716724)
    /* 3C6E20 004C6E20 7100033C */  lui        $3, %hi(D_00716720)
    /* 3C6E24 004C6E24 7100073C */  lui        $7, %hi(D_0071671C)
    /* 3C6E28 004C6E28 7100083C */  lui        $8, %hi(D_007165F0)
    /* 3C6E2C 004C6E2C 7100093C */  lui        $9, %hi(D_00716718)
    /* 3C6E30 004C6E30 2D280000 */  daddu      $5, $0, $0
    /* 3C6E34 004C6E34 F8668424 */  addiu      $4, $4, %lo(D_007166F8)
    /* 3C6E38 004C6E38 20000624 */  addiu      $6, $0, 0x20
    /* 3C6E3C 004C6E3C FFFF0224 */  addiu      $2, $0, -0x1
    /* 3C6E40 004C6E40 28678AAD */  sw         $10, %lo(D_00716728)($12)
    /* 3C6E44 004C6E44 246762AD */  sw         $2, %lo(D_00716724)($11)
    /* 3C6E48 004C6E48 206760AC */  sw         $0, %lo(D_00716720)($3)
    /* 3C6E4C 004C6E4C 1C67E0AC */  sw         $0, %lo(D_0071671C)($7)
    /* 3C6E50 004C6E50 F06500AD */  sw         $0, %lo(D_007165F0)($8)
    /* 3C6E54 004C6E54 72FE100C */  jal        func_0043f9c8
    /* 3C6E58 004C6E58 186720AD */   sw        $0, %lo(D_00716718)($9)
    /* 3C6E5C 004C6E5C 7100043C */  lui        $4, %hi(D_007165F8)
    /* 3C6E60 004C6E60 FF000524 */  addiu      $5, $0, 0xFF
    /* 3C6E64 004C6E64 F8658424 */  addiu      $4, $4, %lo(D_007165F8)
    /* 3C6E68 004C6E68 72FE100C */  jal        func_0043f9c8
    /* 3C6E6C 004C6E6C 00010624 */   addiu     $6, $0, 0x100
    /* 3C6E70 004C6E70 7100043C */  lui        $4, %hi(D_007161F0)
    /* 3C6E74 004C6E74 F0618424 */  addiu      $4, $4, %lo(D_007161F0)
    /* 3C6E78 004C6E78 2D280000 */  daddu      $5, $0, $0
    /* 3C6E7C 004C6E7C 72FE100C */  jal        func_0043f9c8
    /* 3C6E80 004C6E80 00040624 */   addiu     $6, $0, 0x400
    /* 3C6E84 004C6E84 7100043C */  lui        $4, %hi(D_00715DB0)
    /* 3C6E88 004C6E88 0000BFDF */  ld         $31, 0x0($29)
    /* 3C6E8C 004C6E8C B05D8424 */  addiu      $4, $4, %lo(D_00715DB0)
    /* 3C6E90 004C6E90 2D280000 */  daddu      $5, $0, $0
    /* 3C6E94 004C6E94 40040624 */  addiu      $6, $0, 0x440
    /* 3C6E98 004C6E98 72FE1008 */  j          func_0043f9c8
    /* 3C6E9C 004C6E9C 1000BD27 */   addiu     $29, $29, 0x10
  .L004C6EA0:
    /* 3C6EA0 004C6EA0 0000BFDF */  ld         $31, 0x0($29)
    /* 3C6EA4 004C6EA4 0800E003 */  jr         $31
    /* 3C6EA8 004C6EA8 1000BD27 */   addiu     $29, $29, 0x10
    /* 3C6EAC 004C6EAC 00000000 */  nop
.size func_004c6de8, 0xc8
