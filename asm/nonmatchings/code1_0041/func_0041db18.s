.section .text
.set noat
.set noreorder
glabel func_0041db18
    /* 31DB18 0041DB18 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 31DB1C 0041DB1C 01000524 */  addiu      $5, $0, 0x1
    /* 31DB20 0041DB20 0000B0FF */  sd         $16, 0x0($29)
    /* 31DB24 0041DB24 1000BFFF */  sd         $31, 0x10($29)
    /* 31DB28 0041DB28 2E6F100C */  jal        func_0041bcb8
    /* 31DB2C 0041DB2C 2D808000 */   daddu     $16, $4, $0
    /* 31DB30 0041DB30 0C004010 */  beqz       $2, .L0041DB64
    /* 31DB34 0041DB34 500802AE */   sw        $2, 0x850($16)
    /* 31DB38 0041DB38 FE77100C */  jal        func_0041dff8
    /* 31DB3C 0041DB3C 2D200002 */   daddu     $4, $16, $0
    /* 31DB40 0041DB40 0010023C */  lui        $2, (0x10002000 >> 16)
    /* 31DB44 0041DB44 0050033C */  lui        $3, (0x50000000 >> 16)
    /* 31DB48 0041DB48 00204234 */  ori        $2, $2, (0x10002000 & 0xFFFF)
    /* 31DB4C 0041DB4C 01000524 */  addiu      $5, $0, 0x1
    /* 31DB50 0041DB50 000043AC */  sw         $3, 0x0($2)
    /* 31DB54 0041DB54 2D200002 */  daddu      $4, $16, $0
    /* 31DB58 0041DB58 2C0803AE */  sw         $3, 0x82C($16)
    /* 31DB5C 0041DB5C FE77100C */  jal        func_0041dff8
    /* 31DB60 0041DB60 280805AE */   sw        $5, 0x828($16)
  .L0041DB64:
    /* 31DB64 0041DB64 2D200002 */  daddu      $4, $16, $0
    /* 31DB68 0041DB68 2E6F100C */  jal        func_0041bcb8
    /* 31DB6C 0041DB6C 01000524 */   addiu     $5, $0, 0x1
    /* 31DB70 0041DB70 0D004010 */  beqz       $2, .L0041DBA8
    /* 31DB74 0041DB74 540802AE */   sw        $2, 0x854($16)
    /* 31DB78 0041DB78 FE77100C */  jal        func_0041dff8
    /* 31DB7C 0041DB7C 2D200002 */   daddu     $4, $16, $0
    /* 31DB80 0041DB80 0010023C */  lui        $2, (0x10002000 >> 16)
    /* 31DB84 0041DB84 0058033C */  lui        $3, (0x58000000 >> 16)
    /* 31DB88 0041DB88 00204234 */  ori        $2, $2, (0x10002000 & 0xFFFF)
    /* 31DB8C 0041DB8C 0050043C */  lui        $4, (0x50000000 >> 16)
    /* 31DB90 0041DB90 000043AC */  sw         $3, 0x0($2)
    /* 31DB94 0041DB94 01000524 */  addiu      $5, $0, 0x1
    /* 31DB98 0041DB98 2C0804AE */  sw         $4, 0x82C($16)
    /* 31DB9C 0041DB9C 2D200002 */  daddu      $4, $16, $0
    /* 31DBA0 0041DBA0 FE77100C */  jal        func_0041dff8
    /* 31DBA4 0041DBA4 280805AE */   sw        $5, 0x828($16)
  .L0041DBA8:
    /* 31DBA8 0041DBA8 2D200002 */  daddu      $4, $16, $0
    /* 31DBAC 0041DBAC 2E6F100C */  jal        func_0041bcb8
    /* 31DBB0 0041DBB0 01000524 */   addiu     $5, $0, 0x1
    /* 31DBB4 0041DBB4 04004010 */  beqz       $2, .L0041DBC8
    /* 31DBB8 0041DBB8 7500053C */   lui       $5, %hi(D_00753A98)
    /* 31DBBC 0041DBBC 2D200002 */  daddu      $4, $16, $0
    /* 31DBC0 0041DBC0 3283100C */  jal        func_00420cc8
    /* 31DBC4 0041DBC4 983AA524 */   addiu     $5, $5, %lo(D_00753A98)
  .L0041DBC8:
    /* 31DBC8 0041DBC8 2D200002 */  daddu      $4, $16, $0
    /* 31DBCC 0041DBCC 2E6F100C */  jal        func_0041bcb8
    /* 31DBD0 0041DBD0 01000524 */   addiu     $5, $0, 0x1
    /* 31DBD4 0041DBD4 07004010 */  beqz       $2, .L0041DBF4
    /* 31DBD8 0041DBD8 1000BFDF */   ld        $31, 0x10($29)
    /* 31DBDC 0041DBDC 2D200002 */  daddu      $4, $16, $0
    /* 31DBE0 0041DBE0 7500053C */  lui        $5, %hi(D_00753AC0)
    /* 31DBE4 0041DBE4 C03AA524 */  addiu      $5, $5, %lo(D_00753AC0)
    /* 31DBE8 0041DBE8 0000B0DF */  ld         $16, 0x0($29)
    /* 31DBEC 0041DBEC 32831008 */  j          func_00420cc8
    /* 31DBF0 0041DBF0 2000BD27 */   addiu     $29, $29, 0x20
  .L0041DBF4:
    /* 31DBF4 0041DBF4 0000B0DF */  ld         $16, 0x0($29)
    /* 31DBF8 0041DBF8 0800E003 */  jr         $31
    /* 31DBFC 0041DBFC 2000BD27 */   addiu     $29, $29, 0x20
.size func_0041db18, 0xe8
