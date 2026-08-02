.section .text
.set noat
.set noreorder
glabel func_002b5db0
    /* 1B5DB0 002B5DB0 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 1B5DB4 002B5DB4 0800A5FF */  sd         $5, 0x8($29)
    /* 1B5DB8 002B5DB8 0000C3C4 */  lwc1       $f3, 0x0($6)
    /* 1B5DBC 002B5DBC 0400C2C4 */  lwc1       $f2, 0x4($6)
    /* 1B5DC0 002B5DC0 0800C1C4 */  lwc1       $f1, 0x8($6)
    /* 1B5DC4 002B5DC4 0C00C0C4 */  lwc1       $f0, 0xC($6)
    /* 1B5DC8 002B5DC8 1000A3E7 */  swc1       $f3, 0x10($29)
    /* 1B5DCC 002B5DCC 1400A2E7 */  swc1       $f2, 0x14($29)
    /* 1B5DD0 002B5DD0 1800A1E7 */  swc1       $f1, 0x18($29)
    /* 1B5DD4 002B5DD4 1C00A0E7 */  swc1       $f0, 0x1C($29)
    /* 1B5DD8 002B5DD8 3800838C */  lw         $3, 0x38($4)
    /* 1B5DDC 002B5DDC 0800A1C7 */  lwc1       $f1, 0x8($29)
    /* 1B5DE0 002B5DE0 0C00A0C7 */  lwc1       $f0, 0xC($29)
    /* 1B5DE4 002B5DE4 340161E4 */  swc1       $f1, 0x134($3)
    /* 1B5DE8 002B5DE8 380160E4 */  swc1       $f0, 0x138($3)
    /* 1B5DEC 002B5DEC 1000A3C7 */  lwc1       $f3, 0x10($29)
    /* 1B5DF0 002B5DF0 1400A2C7 */  lwc1       $f2, 0x14($29)
    /* 1B5DF4 002B5DF4 1800A1C7 */  lwc1       $f1, 0x18($29)
    /* 1B5DF8 002B5DF8 1C00A0C7 */  lwc1       $f0, 0x1C($29)
    /* 1B5DFC 002B5DFC 200163E4 */  swc1       $f3, 0x120($3)
    /* 1B5E00 002B5E00 240162E4 */  swc1       $f2, 0x124($3)
    /* 1B5E04 002B5E04 280161E4 */  swc1       $f1, 0x128($3)
    /* 1B5E08 002B5E08 2C0160E4 */  swc1       $f0, 0x12C($3)
    /* 1B5E0C 002B5E0C 2000BD27 */  addiu      $29, $29, 0x20
    /* 1B5E10 002B5E10 0800E003 */  jr         $31
    /* 1B5E14 002B5E14 00000000 */   nop
    /* 1B5E18 002B5E18 00000000 */  nop
    /* 1B5E1C 002B5E1C 00000000 */  nop
.size func_002b5db0, 0x70
