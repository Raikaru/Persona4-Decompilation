.section .text
.set noat
.set noreorder
glabel func_0026db60
    /* 16DB60 0026DB60 D0FFBD27 */  addiu      $29, $29, -0x30
    /* 16DB64 0026DB64 2000BFFF */  sd         $31, 0x20($29)
    /* 16DB68 0026DB68 1000B17F */  sq         $17, 0x10($29)
    /* 16DB6C 0026DB6C 0000B07F */  sq         $16, 0x0($29)
    /* 16DB70 0026DB70 10B5090C */  jal        func_0026d440
    /* 16DB74 0026DB74 00000000 */   nop
    /* 16DB78 0026DB78 01001124 */  addiu      $17, $0, 0x1
    /* 16DB7C 0026DB7C 10000010 */  b          .L0026DBC0
    /* 16DB80 0026DB80 00000000 */   nop
  .L0026DB84:
    /* 16DB84 0026DB84 2D202002 */  daddu      $4, $17, $0
    /* 16DB88 0026DB88 AC14050C */  jal        func_001452b0
    /* 16DB8C 0026DB8C 00000000 */   nop
    /* 16DB90 0026DB90 2D804000 */  daddu      $16, $2, $0
    /* 16DB94 0026DB94 05000010 */  b          .L0026DBAC
    /* 16DB98 0026DB98 00000000 */   nop
  .L0026DB9C:
    /* 16DB9C 0026DB9C 2D200002 */  daddu      $4, $16, $0
    /* 16DBA0 0026DBA0 08A8090C */  jal        func_0026a020
    /* 16DBA4 0026DBA4 00000000 */   nop
    /* 16DBA8 0026DBA8 3801108E */  lw         $16, 0x138($16)
  .L0026DBAC:
    /* 16DBAC 0026DBAC 00000000 */  nop
    /* 16DBB0 0026DBB0 00000000 */  nop
    /* 16DBB4 0026DBB4 F9FF0016 */  bnez       $16, .L0026DB9C
    /* 16DBB8 0026DBB8 00000000 */   nop
    /* 16DBBC 0026DBBC 01003126 */  addiu      $17, $17, 0x1
  .L0026DBC0:
    /* 16DBC0 0026DBC0 1600222A */  slti       $2, $17, 0x16
    /* 16DBC4 0026DBC4 EFFF4014 */  bnez       $2, .L0026DB84
    /* 16DBC8 0026DBC8 00000000 */   nop
    /* 16DBCC 0026DBCC 07000424 */  addiu      $4, $0, 0x7
    /* 16DBD0 0026DBD0 AC14050C */  jal        func_001452b0
    /* 16DBD4 0026DBD4 00000000 */   nop
    /* 16DBD8 0026DBD8 01000324 */  addiu      $3, $0, 0x1
    /* 16DBDC 0026DBDC 0A000010 */  b          .L0026DC08
    /* 16DBE0 0026DBE0 00000000 */   nop
  .L0026DBE4:
    /* 16DBE4 0026DBE4 4801448C */  lw         $4, 0x148($2)
    /* 16DBE8 0026DBE8 06008314 */  bne        $4, $3, .L0026DC04
    /* 16DBEC 0026DBEC 00000000 */   nop
    /* 16DBF0 0026DBF0 2D204000 */  daddu      $4, $2, $0
    /* 16DBF4 0026DBF4 C4B0090C */  jal        func_0026c310
    /* 16DBF8 0026DBF8 00000000 */   nop
    /* 16DBFC 0026DBFC 04000010 */  b          .L0026DC10
    /* 16DC00 0026DC00 00000000 */   nop
  .L0026DC04:
    /* 16DC04 0026DC04 3801428C */  lw         $2, 0x138($2)
  .L0026DC08:
    /* 16DC08 0026DC08 F6FF4014 */  bnez       $2, .L0026DBE4
    /* 16DC0C 0026DC0C 00000000 */   nop
  .L0026DC10:
    /* 16DC10 0026DC10 2D100000 */  daddu      $2, $0, $0
    /* 16DC14 0026DC14 2000BFDF */  ld         $31, 0x20($29)
    /* 16DC18 0026DC18 1000B17B */  lq         $17, 0x10($29)
    /* 16DC1C 0026DC1C 0000B07B */  lq         $16, 0x0($29)
    /* 16DC20 0026DC20 3000BD27 */  addiu      $29, $29, 0x30
    /* 16DC24 0026DC24 0800E003 */  jr         $31
    /* 16DC28 0026DC28 00000000 */   nop
    /* 16DC2C 0026DC2C 00000000 */  nop
.size func_0026db60, 0xd0
