.section .text
.set noat
.set noreorder
glabel func_004f5d38
    /* 3F5D38 004F5D38 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 3F5D3C 004F5D3C 9200023C */  lui        $2, %hi(D_00925FA8)
    /* 3F5D40 004F5D40 0000B0FF */  sd         $16, 0x0($29)
    /* 3F5D44 004F5D44 7400103C */  lui        $16, %hi(D_00743A60)
    /* 3F5D48 004F5D48 603A1026 */  addiu      $16, $16, %lo(D_00743A60)
    /* 3F5D4C 004F5D4C 0800B1FF */  sd         $17, 0x8($29)
    /* 3F5D50 004F5D50 A85F45AC */  sw         $5, %lo(D_00925FA8)($2)
    /* 3F5D54 004F5D54 2D280002 */  daddu      $5, $16, $0
    /* 3F5D58 004F5D58 2D888000 */  daddu      $17, $4, $0
    /* 3F5D5C 004F5D5C 1000BFFF */  sd         $31, 0x10($29)
    /* 3F5D60 004F5D60 62D8130C */  jal        func_004f6188
    /* 3F5D64 004F5D64 2D300000 */   daddu     $6, $0, $0
    /* 3F5D68 004F5D68 01002426 */  addiu      $4, $17, 0x1
    /* 3F5D6C 004F5D6C 2D280002 */  daddu      $5, $16, $0
    /* 3F5D70 004F5D70 62D8130C */  jal        func_004f6188
    /* 3F5D74 004F5D74 01000624 */   addiu     $6, $0, 0x1
    /* 3F5D78 004F5D78 06002426 */  addiu      $4, $17, 0x6
    /* 3F5D7C 004F5D7C 2D280002 */  daddu      $5, $16, $0
    /* 3F5D80 004F5D80 62D8130C */  jal        func_004f6188
    /* 3F5D84 004F5D84 02000624 */   addiu     $6, $0, 0x2
    /* 3F5D88 004F5D88 07002426 */  addiu      $4, $17, 0x7
    /* 3F5D8C 004F5D8C 2D280002 */  daddu      $5, $16, $0
    /* 3F5D90 004F5D90 62D8130C */  jal        func_004f6188
    /* 3F5D94 004F5D94 03000624 */   addiu     $6, $0, 0x3
    /* 3F5D98 004F5D98 08002426 */  addiu      $4, $17, 0x8
    /* 3F5D9C 004F5D9C 2D280002 */  daddu      $5, $16, $0
    /* 3F5DA0 004F5DA0 62D8130C */  jal        func_004f6188
    /* 3F5DA4 004F5DA4 04000624 */   addiu     $6, $0, 0x4
    /* 3F5DA8 004F5DA8 28002426 */  addiu      $4, $17, 0x28
    /* 3F5DAC 004F5DAC 2D280002 */  daddu      $5, $16, $0
    /* 3F5DB0 004F5DB0 62D8130C */  jal        func_004f6188
    /* 3F5DB4 004F5DB4 05000624 */   addiu     $6, $0, 0x5
    /* 3F5DB8 004F5DB8 48002426 */  addiu      $4, $17, 0x48
    /* 3F5DBC 004F5DBC 2D280002 */  daddu      $5, $16, $0
    /* 3F5DC0 004F5DC0 62D8130C */  jal        func_004f6188
    /* 3F5DC4 004F5DC4 06000624 */   addiu     $6, $0, 0x6
    /* 3F5DC8 004F5DC8 50002426 */  addiu      $4, $17, 0x50
    /* 3F5DCC 004F5DCC 2D280002 */  daddu      $5, $16, $0
    /* 3F5DD0 004F5DD0 62D8130C */  jal        func_004f6188
    /* 3F5DD4 004F5DD4 07000624 */   addiu     $6, $0, 0x7
    /* 3F5DD8 004F5DD8 54002426 */  addiu      $4, $17, 0x54
    /* 3F5DDC 004F5DDC 2D280002 */  daddu      $5, $16, $0
    /* 3F5DE0 004F5DE0 62D8130C */  jal        func_004f6188
    /* 3F5DE4 004F5DE4 08000624 */   addiu     $6, $0, 0x8
    /* 3F5DE8 004F5DE8 58002426 */  addiu      $4, $17, 0x58
    /* 3F5DEC 004F5DEC 2D280002 */  daddu      $5, $16, $0
    /* 3F5DF0 004F5DF0 62D8130C */  jal        func_004f6188
    /* 3F5DF4 004F5DF4 09000624 */   addiu     $6, $0, 0x9
    /* 3F5DF8 004F5DF8 5C002426 */  addiu      $4, $17, 0x5C
    /* 3F5DFC 004F5DFC 2D280002 */  daddu      $5, $16, $0
    /* 3F5E00 004F5E00 62D8130C */  jal        func_004f6188
    /* 3F5E04 004F5E04 0A000624 */   addiu     $6, $0, 0xA
    /* 3F5E08 004F5E08 78002426 */  addiu      $4, $17, 0x78
    /* 3F5E0C 004F5E0C 2D280002 */  daddu      $5, $16, $0
    /* 3F5E10 004F5E10 62D8130C */  jal        func_004f6188
    /* 3F5E14 004F5E14 0B000624 */   addiu     $6, $0, 0xB
    /* 3F5E18 004F5E18 7A002426 */  addiu      $4, $17, 0x7A
    /* 3F5E1C 004F5E1C 2D280002 */  daddu      $5, $16, $0
    /* 3F5E20 004F5E20 62D8130C */  jal        func_004f6188
    /* 3F5E24 004F5E24 0C000624 */   addiu     $6, $0, 0xC
    /* 3F5E28 004F5E28 7C002426 */  addiu      $4, $17, 0x7C
    /* 3F5E2C 004F5E2C 2D280002 */  daddu      $5, $16, $0
    /* 3F5E30 004F5E30 62D8130C */  jal        func_004f6188
    /* 3F5E34 004F5E34 0D000624 */   addiu     $6, $0, 0xD
    /* 3F5E38 004F5E38 7E002426 */  addiu      $4, $17, 0x7E
    /* 3F5E3C 004F5E3C 2D280002 */  daddu      $5, $16, $0
    /* 3F5E40 004F5E40 62D8130C */  jal        func_004f6188
    /* 3F5E44 004F5E44 0E000624 */   addiu     $6, $0, 0xE
    /* 3F5E48 004F5E48 80002426 */  addiu      $4, $17, 0x80
    /* 3F5E4C 004F5E4C 2D280002 */  daddu      $5, $16, $0
    /* 3F5E50 004F5E50 62D8130C */  jal        func_004f6188
    /* 3F5E54 004F5E54 0F000624 */   addiu     $6, $0, 0xF
    /* 3F5E58 004F5E58 82002426 */  addiu      $4, $17, 0x82
    /* 3F5E5C 004F5E5C 2D280002 */  daddu      $5, $16, $0
    /* 3F5E60 004F5E60 62D8130C */  jal        func_004f6188
    /* 3F5E64 004F5E64 10000624 */   addiu     $6, $0, 0x10
    /* 3F5E68 004F5E68 84002426 */  addiu      $4, $17, 0x84
    /* 3F5E6C 004F5E6C 2D280002 */  daddu      $5, $16, $0
    /* 3F5E70 004F5E70 62D8130C */  jal        func_004f6188
    /* 3F5E74 004F5E74 11000624 */   addiu     $6, $0, 0x11
    /* 3F5E78 004F5E78 88002426 */  addiu      $4, $17, 0x88
    /* 3F5E7C 004F5E7C 2D280002 */  daddu      $5, $16, $0
    /* 3F5E80 004F5E80 62D8130C */  jal        func_004f6188
    /* 3F5E84 004F5E84 12000624 */   addiu     $6, $0, 0x12
    /* 3F5E88 004F5E88 8C002426 */  addiu      $4, $17, 0x8C
    /* 3F5E8C 004F5E8C 2D280002 */  daddu      $5, $16, $0
    /* 3F5E90 004F5E90 62D8130C */  jal        func_004f6188
    /* 3F5E94 004F5E94 13000624 */   addiu     $6, $0, 0x13
    /* 3F5E98 004F5E98 90002426 */  addiu      $4, $17, 0x90
    /* 3F5E9C 004F5E9C 2D280002 */  daddu      $5, $16, $0
    /* 3F5EA0 004F5EA0 62D8130C */  jal        func_004f6188
    /* 3F5EA4 004F5EA4 14000624 */   addiu     $6, $0, 0x14
    /* 3F5EA8 004F5EA8 94002426 */  addiu      $4, $17, 0x94
    /* 3F5EAC 004F5EAC 2D280002 */  daddu      $5, $16, $0
    /* 3F5EB0 004F5EB0 62D8130C */  jal        func_004f6188
    /* 3F5EB4 004F5EB4 15000624 */   addiu     $6, $0, 0x15
    /* 3F5EB8 004F5EB8 98002426 */  addiu      $4, $17, 0x98
    /* 3F5EBC 004F5EBC 2D280002 */  daddu      $5, $16, $0
    /* 3F5EC0 004F5EC0 62D8130C */  jal        func_004f6188
    /* 3F5EC4 004F5EC4 16000624 */   addiu     $6, $0, 0x16
    /* 3F5EC8 004F5EC8 9C002426 */  addiu      $4, $17, 0x9C
    /* 3F5ECC 004F5ECC 2D280002 */  daddu      $5, $16, $0
    /* 3F5ED0 004F5ED0 62D8130C */  jal        func_004f6188
    /* 3F5ED4 004F5ED4 17000624 */   addiu     $6, $0, 0x17
    /* 3F5ED8 004F5ED8 BE002426 */  addiu      $4, $17, 0xBE
    /* 3F5EDC 004F5EDC 2D280002 */  daddu      $5, $16, $0
    /* 3F5EE0 004F5EE0 62D8130C */  jal        func_004f6188
    /* 3F5EE4 004F5EE4 18000624 */   addiu     $6, $0, 0x18
    /* 3F5EE8 004F5EE8 3E012426 */  addiu      $4, $17, 0x13E
    /* 3F5EEC 004F5EEC 2D280002 */  daddu      $5, $16, $0
    /* 3F5EF0 004F5EF0 62D8130C */  jal        func_004f6188
    /* 3F5EF4 004F5EF4 19000624 */   addiu     $6, $0, 0x19
    /* 3F5EF8 004F5EF8 BE012426 */  addiu      $4, $17, 0x1BE
    /* 3F5EFC 004F5EFC 2D280002 */  daddu      $5, $16, $0
    /* 3F5F00 004F5F00 62D8130C */  jal        func_004f6188
    /* 3F5F04 004F5F04 1A000624 */   addiu     $6, $0, 0x1A
    /* 3F5F08 004F5F08 3E022426 */  addiu      $4, $17, 0x23E
    /* 3F5F0C 004F5F0C 2D280002 */  daddu      $5, $16, $0
    /* 3F5F10 004F5F10 62D8130C */  jal        func_004f6188
    /* 3F5F14 004F5F14 1B000624 */   addiu     $6, $0, 0x1B
    /* 3F5F18 004F5F18 BE022426 */  addiu      $4, $17, 0x2BE
    /* 3F5F1C 004F5F1C 2D280002 */  daddu      $5, $16, $0
    /* 3F5F20 004F5F20 62D8130C */  jal        func_004f6188
    /* 3F5F24 004F5F24 1C000624 */   addiu     $6, $0, 0x1C
    /* 3F5F28 004F5F28 E3022426 */  addiu      $4, $17, 0x2E3
    /* 3F5F2C 004F5F2C 2D280002 */  daddu      $5, $16, $0
    /* 3F5F30 004F5F30 62D8130C */  jal        func_004f6188
    /* 3F5F34 004F5F34 1D000624 */   addiu     $6, $0, 0x1D
    /* 3F5F38 004F5F38 08032426 */  addiu      $4, $17, 0x308
    /* 3F5F3C 004F5F3C 2D280002 */  daddu      $5, $16, $0
    /* 3F5F40 004F5F40 62D8130C */  jal        func_004f6188
    /* 3F5F44 004F5F44 1E000624 */   addiu     $6, $0, 0x1E
    /* 3F5F48 004F5F48 2D032426 */  addiu      $4, $17, 0x32D
    /* 3F5F4C 004F5F4C 2D280002 */  daddu      $5, $16, $0
    /* 3F5F50 004F5F50 62D8130C */  jal        func_004f6188
    /* 3F5F54 004F5F54 1F000624 */   addiu     $6, $0, 0x1F
    /* 3F5F58 004F5F58 3E032426 */  addiu      $4, $17, 0x33E
    /* 3F5F5C 004F5F5C 2D280002 */  daddu      $5, $16, $0
    /* 3F5F60 004F5F60 62D8130C */  jal        func_004f6188
    /* 3F5F64 004F5F64 20000624 */   addiu     $6, $0, 0x20
    /* 3F5F68 004F5F68 4F032426 */  addiu      $4, $17, 0x34F
    /* 3F5F6C 004F5F6C 2D280002 */  daddu      $5, $16, $0
    /* 3F5F70 004F5F70 62D8130C */  jal        func_004f6188
    /* 3F5F74 004F5F74 21000624 */   addiu     $6, $0, 0x21
    /* 3F5F78 004F5F78 60032426 */  addiu      $4, $17, 0x360
    /* 3F5F7C 004F5F7C 2D280002 */  daddu      $5, $16, $0
    /* 3F5F80 004F5F80 62D8130C */  jal        func_004f6188
    /* 3F5F84 004F5F84 22000624 */   addiu     $6, $0, 0x22
    /* 3F5F88 004F5F88 71032426 */  addiu      $4, $17, 0x371
    /* 3F5F8C 004F5F8C 2D280002 */  daddu      $5, $16, $0
    /* 3F5F90 004F5F90 62D8130C */  jal        func_004f6188
    /* 3F5F94 004F5F94 23000624 */   addiu     $6, $0, 0x23
    /* 3F5F98 004F5F98 72032426 */  addiu      $4, $17, 0x372
    /* 3F5F9C 004F5F9C 2D280002 */  daddu      $5, $16, $0
    /* 3F5FA0 004F5FA0 62D8130C */  jal        func_004f6188
    /* 3F5FA4 004F5FA4 24000624 */   addiu     $6, $0, 0x24
    /* 3F5FA8 004F5FA8 73032426 */  addiu      $4, $17, 0x373
    /* 3F5FAC 004F5FAC 2D280002 */  daddu      $5, $16, $0
    /* 3F5FB0 004F5FB0 62D8130C */  jal        func_004f6188
    /* 3F5FB4 004F5FB4 25000624 */   addiu     $6, $0, 0x25
    /* 3F5FB8 004F5FB8 73052426 */  addiu      $4, $17, 0x573
    /* 3F5FBC 004F5FBC 2D280002 */  daddu      $5, $16, $0
    /* 3F5FC0 004F5FC0 0000B0DF */  ld         $16, 0x0($29)
    /* 3F5FC4 004F5FC4 0800B1DF */  ld         $17, 0x8($29)
    /* 3F5FC8 004F5FC8 26000624 */  addiu      $6, $0, 0x26
    /* 3F5FCC 004F5FCC 1000BFDF */  ld         $31, 0x10($29)
    /* 3F5FD0 004F5FD0 62D81308 */  j          func_004f6188
    /* 3F5FD4 004F5FD4 2000BD27 */   addiu     $29, $29, 0x20
.size func_004f5d38, 0x2a0
