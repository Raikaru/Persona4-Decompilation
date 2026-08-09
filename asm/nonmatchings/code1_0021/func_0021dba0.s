.section .text
.set noat
.set noreorder
glabel func_0021dba0
    /* 11DBA0 0021DBA0 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 11DBA4 0021DBA4 1000BFFF */  sd         $31, 0x10($29)
    /* 11DBA8 0021DBA8 0000B07F */  sq         $16, 0x0($29)
    /* 11DBAC 0021DBAC 5849110C */  jal        func_00452560
    /* 11DBB0 0021DBB0 00000000 */   nop
    /* 11DBB4 0021DBB4 2D804000 */  daddu      $16, $2, $0
    /* 11DBB8 0021DBB8 040040AC */  sw         $0, 0x4($2)
    /* 11DBBC 0021DBBC 080040AC */  sw         $0, 0x8($2)
    /* 11DBC0 0021DBC0 7900043C */  lui        $4, %hi(D_00796340)
    /* 11DBC4 0021DBC4 40638424 */  addiu      $4, $4, %lo(D_00796340)
    /* 11DBC8 0021DBC8 04000526 */  addiu      $5, $16, 0x4
    /* 11DBCC 0021DBCC B082110C */  jal        func_00460ac0
    /* 11DBD0 0021DBD0 00000000 */   nop
    /* 11DBD4 0021DBD4 0000028E */  lw         $2, 0x0($16)
    /* 11DBD8 0021DBD8 01004324 */  addiu      $3, $2, 0x1
    /* 11DBDC 0021DBDC 000003AE */  sw         $3, 0x0($16)
    /* 11DBE0 0021DBE0 0C000224 */  addiu      $2, $0, 0xC
    /* 11DBE4 0021DBE4 07006214 */  bne        $3, $2, .L0021DC04
    /* 11DBE8 0021DBE8 00000000 */   nop
    /* 11DBEC 0021DBEC 01000424 */  addiu      $4, $0, 0x1
    /* 11DBF0 0021DBF0 2D288000 */  daddu      $5, $4, $0
    /* 11DBF4 0021DBF4 4889040C */  jal        func_00122520
    /* 11DBF8 0021DBF8 00000000 */   nop
    /* 11DBFC 0021DBFC 0B000010 */  b          .L0021DC2C
    /* 11DC00 0021DC00 00000000 */   nop
  .L0021DC04:
    /* 11DC04 0021DC04 0D006128 */  slti       $1, $3, 0xD
    /* 11DC08 0021DC08 08002014 */  bnez       $1, .L0021DC2C
    /* 11DC0C 0021DC0C 00000000 */   nop
    /* 11DC10 0021DC10 C889040C */  jal        func_00122720
    /* 11DC14 0021DC14 00000000 */   nop
    /* 11DC18 0021DC18 04004010 */  beqz       $2, .L0021DC2C
    /* 11DC1C 0021DC1C 00000000 */   nop
    /* 11DC20 0021DC20 FFFF0224 */  addiu      $2, $0, -0x1
    /* 11DC24 0021DC24 02000010 */  b          .L0021DC30
    /* 11DC28 0021DC28 00000000 */   nop
  .L0021DC2C:
    /* 11DC2C 0021DC2C 2D100000 */  daddu      $2, $0, $0
  .L0021DC30:
    /* 11DC30 0021DC30 1000BFDF */  ld         $31, 0x10($29)
    /* 11DC34 0021DC34 0000B07B */  lq         $16, 0x0($29)
    /* 11DC38 0021DC38 2000BD27 */  addiu      $29, $29, 0x20
    /* 11DC3C 0021DC3C 0800E003 */  jr         $31
    /* 11DC40 0021DC40 00000000 */   nop
    /* 11DC44 0021DC44 00000000 */  nop
    /* 11DC48 0021DC48 00000000 */  nop
    /* 11DC4C 0021DC4C 00000000 */  nop
.size func_0021dba0, 0xb0
