.section .text
.set noat
.set noreorder
glabel func_0045da40
    /* 35DA40 0045DA40 A0FFBD27 */  addiu      $29, $29, -0x60
    /* 35DA44 0045DA44 2000BFFF */  sd         $31, 0x20($29)
    /* 35DA48 0045DA48 1000B17F */  sq         $17, 0x10($29)
    /* 35DA4C 0045DA4C 0000B07F */  sq         $16, 0x0($29)
    /* 35DA50 0045DA50 2D80E000 */  daddu      $16, $7, $0
    /* 35DA54 0045DA54 0000A3C4 */  lwc1       $f3, 0x0($5)
    /* 35DA58 0045DA58 0400A2C4 */  lwc1       $f2, 0x4($5)
    /* 35DA5C 0045DA5C 0800A1C4 */  lwc1       $f1, 0x8($5)
    /* 35DA60 0045DA60 0C00A0C4 */  lwc1       $f0, 0xC($5)
    /* 35DA64 0045DA64 5000A3E7 */  swc1       $f3, 0x50($29)
    /* 35DA68 0045DA68 5400A2E7 */  swc1       $f2, 0x54($29)
    /* 35DA6C 0045DA6C 5800A1E7 */  swc1       $f1, 0x58($29)
    /* 35DA70 0045DA70 5C00A0E7 */  swc1       $f0, 0x5C($29)
    /* 35DA74 0045DA74 00008790 */  lbu        $7, 0x0($4)
    /* 35DA78 0045DA78 01008590 */  lbu        $5, 0x1($4)
    /* 35DA7C 0045DA7C 02008390 */  lbu        $3, 0x2($4)
    /* 35DA80 0045DA80 03008290 */  lbu        $2, 0x3($4)
    /* 35DA84 0045DA84 3000A7A3 */  sb         $7, 0x30($29)
    /* 35DA88 0045DA88 3100A5A3 */  sb         $5, 0x31($29)
    /* 35DA8C 0045DA8C 3200A3A3 */  sb         $3, 0x32($29)
    /* 35DA90 0045DA90 3300A2A3 */  sb         $2, 0x33($29)
    /* 35DA94 0045DA94 5000A3C7 */  lwc1       $f3, 0x50($29)
    /* 35DA98 0045DA98 5400A2C7 */  lwc1       $f2, 0x54($29)
    /* 35DA9C 0045DA9C 5800A1C7 */  lwc1       $f1, 0x58($29)
    /* 35DAA0 0045DAA0 5C00A0C7 */  lwc1       $f0, 0x5C($29)
    /* 35DAA4 0045DAA4 3400A3E7 */  swc1       $f3, 0x34($29)
    /* 35DAA8 0045DAA8 3800A2E7 */  swc1       $f2, 0x38($29)
    /* 35DAAC 0045DAAC 3C00A1E7 */  swc1       $f1, 0x3C($29)
    /* 35DAB0 0045DAB0 4000A0E7 */  swc1       $f0, 0x40($29)
    /* 35DAB4 0045DAB4 4400ACE7 */  swc1       $f12, 0x44($29)
    /* 35DAB8 0045DAB8 4800A6AF */  sw         $6, 0x48($29)
    /* 35DABC 0045DABC 7100043C */  lui        $4, %hi(D_007124C0)
    /* 35DAC0 0045DAC0 C0248424 */  addiu      $4, $4, %lo(D_007124C0)
    /* 35DAC4 0045DAC4 01010524 */  addiu      $5, $0, 0x101
    /* 35DAC8 0045DAC8 A43A110C */  jal        func_0044ea90
    /* 35DACC 0045DACC 00000000 */   nop
    /* 35DAD0 0045DAD0 1C000424 */  addiu      $4, $0, 0x1C
    /* 35DAD4 0045DAD4 0400053C */  lui        $5, (0x40000 >> 16)
    /* 35DAD8 0045DAD8 8800023C */  lui        $2, %hi(jtbl_008873E8)
    /* 35DADC 0045DADC E873428C */  lw         $2, %lo(jtbl_008873E8)($2)
    /* 35DAE0 0045DAE0 09F84000 */  jalr       $2
    /* 35DAE4 0045DAE4 00000000 */   nop
    /* 35DAE8 0045DAE8 2D884000 */  daddu      $17, $2, $0
    /* 35DAEC 0045DAEC 2D202002 */  daddu      $4, $17, $0
    /* 35DAF0 0045DAF0 3000A527 */  addiu      $5, $29, 0x30
    /* 35DAF4 0045DAF4 1C000624 */  addiu      $6, $0, 0x1C
    /* 35DAF8 0045DAF8 04FE100C */  jal        func_0043f810
    /* 35DAFC 0045DAFC 00000000 */   nop
    /* 35DB00 0045DB00 6482110C */  jal        func_00460990
    /* 35DB04 0045DB04 00000000 */   nop
    /* 35DB08 0045DB08 2D284000 */  daddu      $5, $2, $0
    /* 35DB0C 0045DB0C 4600033C */  lui        $3, %hi(func_0045d890)
    /* 35DB10 0045DB10 90D86324 */  addiu      $3, $3, %lo(func_0045d890)
    /* 35DB14 0045DB14 080043AC */  sw         $3, 0x8($2)
    /* 35DB18 0045DB18 100051AC */  sw         $17, 0x10($2)
    /* 35DB1C 0045DB1C 2D200002 */  daddu      $4, $16, $0
    /* 35DB20 0045DB20 B082110C */  jal        func_00460ac0
    /* 35DB24 0045DB24 00000000 */   nop
    /* 35DB28 0045DB28 2000BFDF */  ld         $31, 0x20($29)
    /* 35DB2C 0045DB2C 1000B17B */  lq         $17, 0x10($29)
    /* 35DB30 0045DB30 0000B07B */  lq         $16, 0x0($29)
    /* 35DB34 0045DB34 6000BD27 */  addiu      $29, $29, 0x60
    /* 35DB38 0045DB38 0800E003 */  jr         $31
    /* 35DB3C 0045DB3C 00000000 */   nop
.size func_0045da40, 0x100
