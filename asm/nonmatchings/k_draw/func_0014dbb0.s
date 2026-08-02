.section .text
.set noat
.set noreorder
glabel func_0014dbb0
    /* 4DBB0 0014DBB0 C0FFBD27 */  addiu      $29, $29, -0x40
    /* 4DBB4 0014DBB4 3000BFFF */  sd         $31, 0x30($29)
    /* 4DBB8 0014DBB8 2000B27F */  sq         $18, 0x20($29)
    /* 4DBBC 0014DBBC 1000B17F */  sq         $17, 0x10($29)
    /* 4DBC0 0014DBC0 0000B07F */  sq         $16, 0x0($29)
    /* 4DBC4 0014DBC4 2D908000 */  daddu      $18, $4, $0
    /* 4DBC8 0014DBC8 2D88A000 */  daddu      $17, $5, $0
    /* 4DBCC 0014DBCC 5F00043C */  lui        $4, %hi(D_005EFBC8)
    /* 4DBD0 0014DBD0 C8FB8424 */  addiu      $4, $4, %lo(D_005EFBC8)
    /* 4DBD4 0014DBD4 0E030524 */  addiu      $5, $0, 0x30E
    /* 4DBD8 0014DBD8 A43A110C */  jal        func_0044ea90
    /* 4DBDC 0014DBDC 00000000 */   nop
    /* 4DBE0 0014DBE0 01000424 */  addiu      $4, $0, 0x1
    /* 4DBE4 0014DBE4 50000524 */  addiu      $5, $0, 0x50
    /* 4DBE8 0014DBE8 0400063C */  lui        $6, (0x40000 >> 16)
    /* 4DBEC 0014DBEC 8800023C */  lui        $2, %hi(D_008873F4)
    /* 4DBF0 0014DBF0 F473428C */  lw         $2, %lo(D_008873F4)($2)
    /* 4DBF4 0014DBF4 09F84000 */  jalr       $2
    /* 4DBF8 0014DBF8 00000000 */   nop
    /* 4DBFC 0014DBFC 2D804000 */  daddu      $16, $2, $0
    /* 4DC00 0014DC00 04000016 */  bnez       $16, .L0014DC14
    /* 4DC04 0014DC04 00000000 */   nop
    /* 4DC08 0014DC08 2D100000 */  daddu      $2, $0, $0
    /* 4DC0C 0014DC0C 28000010 */  b          .L0014DCB0
    /* 4DC10 0014DC10 00000000 */   nop
  .L0014DC14:
    /* 4DC14 0014DC14 2D204002 */  daddu      $4, $18, $0
    /* 4DC18 0014DC18 5F00053C */  lui        $5, %hi(D_005EFC08)
    /* 4DC1C 0014DC1C 08FCA524 */  addiu      $5, $5, %lo(D_005EFC08)
    /* 4DC20 0014DC20 0F000624 */  addiu      $6, $0, 0xF
    /* 4DC24 0014DC24 2D380000 */  daddu      $7, $0, $0
    /* 4DC28 0014DC28 2D400000 */  daddu      $8, $0, $0
    /* 4DC2C 0014DC2C 1500093C */  lui        $9, %hi(func_0014db10)
    /* 4DC30 0014DC30 10DB2925 */  addiu      $9, $9, %lo(func_0014db10)
    /* 4DC34 0014DC34 15000A3C */  lui        $10, %hi(func_0014db80)
    /* 4DC38 0014DC38 80DB4A25 */  addiu      $10, $10, %lo(func_0014db80)
    /* 4DC3C 0014DC3C 2D580002 */  daddu      $11, $16, $0
    /* 4DC40 0014DC40 F047110C */  jal        func_00451fc0
    /* 4DC44 0014DC44 00000000 */   nop
    /* 4DC48 0014DC48 803F033C */  lui        $3, (0x3F800000 >> 16)
    /* 4DC4C 0014DC4C 280003AE */  sw         $3, 0x28($16)
    /* 4DC50 0014DC50 140003AE */  sw         $3, 0x14($16)
    /* 4DC54 0014DC54 000003AE */  sw         $3, 0x0($16)
    /* 4DC58 0014DC58 100000AE */  sw         $0, 0x10($16)
    /* 4DC5C 0014DC5C 080000AE */  sw         $0, 0x8($16)
    /* 4DC60 0014DC60 040000AE */  sw         $0, 0x4($16)
    /* 4DC64 0014DC64 240000AE */  sw         $0, 0x24($16)
    /* 4DC68 0014DC68 200000AE */  sw         $0, 0x20($16)
    /* 4DC6C 0014DC6C 180000AE */  sw         $0, 0x18($16)
    /* 4DC70 0014DC70 380000AE */  sw         $0, 0x38($16)
    /* 4DC74 0014DC74 340000AE */  sw         $0, 0x34($16)
    /* 4DC78 0014DC78 300000AE */  sw         $0, 0x30($16)
    /* 4DC7C 0014DC7C 0C00048E */  lw         $4, 0xC($16)
    /* 4DC80 0014DC80 0200033C */  lui        $3, (0x20003 >> 16)
    /* 4DC84 0014DC84 03006334 */  ori        $3, $3, (0x20003 & 0xFFFF)
    /* 4DC88 0014DC88 25188300 */  or         $3, $4, $3
    /* 4DC8C 0014DC8C 0C0003AE */  sw         $3, 0xC($16)
    /* 4DC90 0014DC90 FF000324 */  addiu      $3, $0, 0xFF
    /* 4DC94 0014DC94 480003A2 */  sb         $3, 0x48($16)
    /* 4DC98 0014DC98 490000A2 */  sb         $0, 0x49($16)
    /* 4DC9C 0014DC9C 4A0000A2 */  sb         $0, 0x4A($16)
    /* 4DCA0 0014DCA0 4B0003A2 */  sb         $3, 0x4B($16)
    /* 4DCA4 0014DCA4 4C0011AE */  sw         $17, 0x4C($16)
    /* 4DCA8 0014DCA8 01000324 */  addiu      $3, $0, 0x1
    /* 4DCAC 0014DCAC 440003AE */  sw         $3, 0x44($16)
  .L0014DCB0:
    /* 4DCB0 0014DCB0 3000BFDF */  ld         $31, 0x30($29)
    /* 4DCB4 0014DCB4 2000B27B */  lq         $18, 0x20($29)
    /* 4DCB8 0014DCB8 1000B17B */  lq         $17, 0x10($29)
    /* 4DCBC 0014DCBC 0000B07B */  lq         $16, 0x0($29)
    /* 4DCC0 0014DCC0 4000BD27 */  addiu      $29, $29, 0x40
    /* 4DCC4 0014DCC4 0800E003 */  jr         $31
    /* 4DCC8 0014DCC8 00000000 */   nop
    /* 4DCCC 0014DCCC 00000000 */  nop
.size func_0014dbb0, 0x120
