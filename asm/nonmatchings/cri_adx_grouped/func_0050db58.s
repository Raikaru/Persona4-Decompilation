.section .text
.set noat
.set noreorder
glabel func_0050db58
    /* 40DB58 0050DB58 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 40DB5C 0050DB5C 0000B0FF */  sd         $16, 0x0($29)
    /* 40DB60 0050DB60 2D808000 */  daddu      $16, $4, $0
    /* 40DB64 0050DB64 0800B1FF */  sd         $17, 0x8($29)
    /* 40DB68 0050DB68 1000BFFF */  sd         $31, 0x10($29)
    /* 40DB6C 0050DB6C 0A35140C */  jal        func_0050d428
    /* 40DB70 0050DB70 2D88A000 */   daddu     $17, $5, $0
    /* 40DB74 0050DB74 7600043C */  lui        $4, %hi(D_0075F4E8)
    /* 40DB78 0050DB78 01000324 */  addiu      $3, $0, 0x1
    /* 40DB7C 0050DB7C 06004310 */  beq        $2, $3, .L0050DB98
    /* 40DB80 0050DB80 E8F48424 */   addiu     $4, $4, %lo(D_0075F4E8)
    /* 40DB84 0050DB84 8844140C */  jal        func_00511220
    /* 40DB88 0050DB88 00000000 */   nop
    /* 40DB8C 0050DB8C 0C000010 */  b          .L0050DBC0
    /* 40DB90 0050DB90 2D100000 */   daddu     $2, $0, $0
    /* 40DB94 0050DB94 00000000 */  nop
  .L0050DB98:
    /* 40DB98 0050DB98 3C00038E */  lw         $3, 0x3C($16)
    /* 40DB9C 0050DB9C 08006010 */  beqz       $3, .L0050DBC0
    /* 40DBA0 0050DBA0 2D100000 */   daddu     $2, $0, $0
    /* 40DBA4 0050DBA4 2D200002 */  daddu      $4, $16, $0
    /* 40DBA8 0050DBA8 0000B0DF */  ld         $16, 0x0($29)
    /* 40DBAC 0050DBAC 2D282002 */  daddu      $5, $17, $0
    /* 40DBB0 0050DBB0 0800B1DF */  ld         $17, 0x8($29)
    /* 40DBB4 0050DBB4 1000BFDF */  ld         $31, 0x10($29)
    /* 40DBB8 0050DBB8 3E321408 */  j          func_0050c8f8
    /* 40DBBC 0050DBBC 2000BD27 */   addiu     $29, $29, 0x20
  .L0050DBC0:
    /* 40DBC0 0050DBC0 0000B0DF */  ld         $16, 0x0($29)
    /* 40DBC4 0050DBC4 0800B1DF */  ld         $17, 0x8($29)
    /* 40DBC8 0050DBC8 1000BFDF */  ld         $31, 0x10($29)
    /* 40DBCC 0050DBCC 0800E003 */  jr         $31
    /* 40DBD0 0050DBD0 2000BD27 */   addiu     $29, $29, 0x20
    /* 40DBD4 0050DBD4 00000000 */  nop
.size func_0050db58, 0x80
