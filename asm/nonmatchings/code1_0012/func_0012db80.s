.section .text
.set noat
.set noreorder
glabel func_0012db80
    /* 2DB80 0012DB80 D0FFBD27 */  addiu      $29, $29, -0x30
    /* 2DB84 0012DB84 2000BFFF */  sd         $31, 0x20($29)
    /* 2DB88 0012DB88 1000B17F */  sq         $17, 0x10($29)
    /* 2DB8C 0012DB8C 0000B07F */  sq         $16, 0x0($29)
    /* 2DB90 0012DB90 2D888000 */  daddu      $17, $4, $0
    /* 2DB94 0012DB94 2D80A000 */  daddu      $16, $5, $0
    /* 2DB98 0012DB98 1000828C */  lw         $2, 0x10($4)
    /* 2DB9C 0012DB9C 10000212 */  beq        $16, $2, .L0012DBE0
    /* 2DBA0 0012DBA0 00000000 */   nop
    /* 2DBA4 0012DBA4 2D200000 */  daddu      $4, $0, $0
    /* 2DBA8 0012DBA8 01000524 */  addiu      $5, $0, 0x1
    /* 2DBAC 0012DBAC 2D300000 */  daddu      $6, $0, $0
    /* 2DBB0 0012DBB0 2D380000 */  daddu      $7, $0, $0
    /* 2DBB4 0012DBB4 D86B110C */  jal        func_0045af60
    /* 2DBB8 0012DBB8 00000000 */   nop
    /* 2DBBC 0012DBBC 1000228E */  lw         $2, 0x10($17)
    /* 2DBC0 0012DBC0 140022AE */  sw         $2, 0x14($17)
    /* 2DBC4 0012DBC4 100030AE */  sw         $16, 0x10($17)
    /* 2DBC8 0012DBC8 FFFF0224 */  addiu      $2, $0, -0x1
    /* 2DBCC 0012DBCC 180022AE */  sw         $2, 0x18($17)
    /* 2DBD0 0012DBD0 2D202002 */  daddu      $4, $17, $0
    /* 2DBD4 0012DBD4 02000524 */  addiu      $5, $0, 0x2
    /* 2DBD8 0012DBD8 A8B7040C */  jal        func_0012dea0
    /* 2DBDC 0012DBDC 00000000 */   nop
  .L0012DBE0:
    /* 2DBE0 0012DBE0 01000224 */  addiu      $2, $0, 0x1
    /* 2DBE4 0012DBE4 2000BFDF */  ld         $31, 0x20($29)
    /* 2DBE8 0012DBE8 1000B17B */  lq         $17, 0x10($29)
    /* 2DBEC 0012DBEC 0000B07B */  lq         $16, 0x0($29)
    /* 2DBF0 0012DBF0 3000BD27 */  addiu      $29, $29, 0x30
    /* 2DBF4 0012DBF4 0800E003 */  jr         $31
    /* 2DBF8 0012DBF8 00000000 */   nop
    /* 2DBFC 0012DBFC 00000000 */  nop
.size func_0012db80, 0x80
