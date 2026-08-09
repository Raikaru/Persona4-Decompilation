.section .text
.set noat
.set noreorder
glabel func_004c6d10
    /* 3C6D10 004C6D10 F0FFBD27 */  addiu      $29, $29, -0x10
    /* 3C6D14 004C6D14 7100043C */  lui        $4, %hi(D_00715DA8)
    /* 3C6D18 004C6D18 0000B0FF */  sd         $16, 0x0($29)
    /* 3C6D1C 004C6D1C A85D9024 */  addiu      $16, $4, %lo(D_00715DA8)
    /* 3C6D20 004C6D20 9200033C */  lui        $3, %hi(D_00922E10)
    /* 3C6D24 004C6D24 7500023C */  lui        $2, %hi(D_00757EA8)
    /* 3C6D28 004C6D28 0000048E */  lw         $4, 0x0($16)
    /* 3C6D2C 004C6D2C 102E6324 */  addiu      $3, $3, %lo(D_00922E10)
    /* 3C6D30 004C6D30 A87E4224 */  addiu      $2, $2, %lo(D_00757EA8)
    /* 3C6D34 004C6D34 0800BFFF */  sd         $31, 0x8($29)
    /* 3C6D38 004C6D38 000062AC */  sw         $2, 0x0($3)
    /* 3C6D3C 004C6D3C 25008054 */  bnel       $4, $0, .L004C6DD4
    /* 3C6D40 004C6D40 01008224 */   addiu     $2, $4, 0x1
    /* 3C6D44 004C6D44 7100043C */  lui        $4, %hi(D_00715DB0)
    /* 3C6D48 004C6D48 2D280000 */  daddu      $5, $0, $0
    /* 3C6D4C 004C6D4C B05D8424 */  addiu      $4, $4, %lo(D_00715DB0)
    /* 3C6D50 004C6D50 72FE100C */  jal        func_0043f9c8
    /* 3C6D54 004C6D54 40040624 */   addiu     $6, $0, 0x440
    /* 3C6D58 004C6D58 7100043C */  lui        $4, %hi(D_007161F0)
    /* 3C6D5C 004C6D5C F0618424 */  addiu      $4, $4, %lo(D_007161F0)
    /* 3C6D60 004C6D60 2D280000 */  daddu      $5, $0, $0
    /* 3C6D64 004C6D64 72FE100C */  jal        func_0043f9c8
    /* 3C6D68 004C6D68 00040624 */   addiu     $6, $0, 0x400
    /* 3C6D6C 004C6D6C 7100043C */  lui        $4, %hi(D_007165F8)
    /* 3C6D70 004C6D70 F8658424 */  addiu      $4, $4, %lo(D_007165F8)
    /* 3C6D74 004C6D74 FF000524 */  addiu      $5, $0, 0xFF
    /* 3C6D78 004C6D78 72FE100C */  jal        func_0043f9c8
    /* 3C6D7C 004C6D7C 00010624 */   addiu     $6, $0, 0x100
    /* 3C6D80 004C6D80 7100043C */  lui        $4, %hi(D_007166F8)
    /* 3C6D84 004C6D84 F8668424 */  addiu      $4, $4, %lo(D_007166F8)
    /* 3C6D88 004C6D88 2D280000 */  daddu      $5, $0, $0
    /* 3C6D8C 004C6D8C 72FE100C */  jal        func_0043f9c8
    /* 3C6D90 004C6D90 20000624 */   addiu     $6, $0, 0x20
    /* 3C6D94 004C6D94 7100063C */  lui        $6, %hi(D_00716718)
    /* 3C6D98 004C6D98 7100043C */  lui        $4, %hi(D_00716728)
    /* 3C6D9C 004C6D9C 7100073C */  lui        $7, %hi(D_007165F0)
    /* 3C6DA0 004C6DA0 7100083C */  lui        $8, %hi(D_0071671C)
    /* 3C6DA4 004C6DA4 7100093C */  lui        $9, %hi(D_00716720)
    /* 3C6DA8 004C6DA8 7100053C */  lui        $5, %hi(D_00716724)
    /* 3C6DAC 004C6DAC FFFF0324 */  addiu      $3, $0, -0x1
    /* 3C6DB0 004C6DB0 01000224 */  addiu      $2, $0, 0x1
    /* 3C6DB4 004C6DB4 2467A3AC */  sw         $3, %lo(D_00716724)($5)
    /* 3C6DB8 004C6DB8 286782AC */  sw         $2, %lo(D_00716728)($4)
    /* 3C6DBC 004C6DBC 1867C0AC */  sw         $0, %lo(D_00716718)($6)
    /* 3C6DC0 004C6DC0 F065E0AC */  sw         $0, %lo(D_007165F0)($7)
    /* 3C6DC4 004C6DC4 1C6700AD */  sw         $0, %lo(D_0071671C)($8)
    /* 3C6DC8 004C6DC8 206720AD */  sw         $0, %lo(D_00716720)($9)
    /* 3C6DCC 004C6DCC 0000048E */  lw         $4, 0x0($16)
    /* 3C6DD0 004C6DD0 01008224 */  addiu      $2, $4, 0x1
  .L004C6DD4:
    /* 3C6DD4 004C6DD4 0800BFDF */  ld         $31, 0x8($29)
    /* 3C6DD8 004C6DD8 000002AE */  sw         $2, 0x0($16)
    /* 3C6DDC 004C6DDC 0000B0DF */  ld         $16, 0x0($29)
    /* 3C6DE0 004C6DE0 0800E003 */  jr         $31
    /* 3C6DE4 004C6DE4 1000BD27 */   addiu     $29, $29, 0x10
.size func_004c6d10, 0xd8
