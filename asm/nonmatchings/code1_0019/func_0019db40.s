.section .text
.set noat
.set noreorder
glabel func_0019db40
    /* 9DB40 0019DB40 80FFBD27 */  addiu      $29, $29, -0x80
    /* 9DB44 0019DB44 2000BFFF */  sd         $31, 0x20($29)
    /* 9DB48 0019DB48 1000B17F */  sq         $17, 0x10($29)
    /* 9DB4C 0019DB4C 0000B07F */  sq         $16, 0x0($29)
    /* 9DB50 0019DB50 2D808000 */  daddu      $16, $4, $0
    /* 9DB54 0019DB54 9800838C */  lw         $3, 0x98($4)
    /* 9DB58 0019DB58 02006330 */  andi       $3, $3, 0x2
    /* 9DB5C 0019DB5C BD006010 */  beqz       $3, .L0019DE54
    /* 9DB60 0019DB60 00000000 */   nop
    /* 9DB64 0019DB64 04006010 */  beqz       $3, .L0019DB78
    /* 9DB68 0019DB68 00000000 */   nop
    /* 9DB6C 0019DB6C DA090386 */  lh         $3, 0x9DA($16)
    /* 9DB70 0019DB70 02000010 */  b          .L0019DB7C
    /* 9DB74 0019DB74 00000000 */   nop
  .L0019DB78:
    /* 9DB78 0019DB78 2D180000 */  daddu      $3, $0, $0
  .L0019DB7C:
    /* 9DB7C 0019DB7C 3C240300 */  dsll32     $4, $3, 16
    /* 9DB80 0019DB80 3F240400 */  dsra32     $4, $4, 16
    /* 9DB84 0019DB84 11000324 */  addiu      $3, $0, 0x11
    /* 9DB88 0019DB88 05008310 */  beq        $4, $3, .L0019DBA0
    /* 9DB8C 0019DB8C 00000000 */   nop
    /* 9DB90 0019DB90 1A008010 */  beqz       $4, .L0019DBFC
    /* 9DB94 0019DB94 00000000 */   nop
    /* 9DB98 0019DB98 0B000010 */  b          .L0019DBC8
    /* 9DB9C 0019DB9C 00000000 */   nop
  .L0019DBA0:
    /* 9DBA0 0019DBA0 000A048E */  lw         $4, 0xA00($16)
    /* 9DBA4 0019DBA4 74EA110C */  jal        func_0047a9d0
    /* 9DBA8 0019DBA8 00000000 */   nop
    /* 9DBAC 0019DBAC 04004010 */  beqz       $2, .L0019DBC0
    /* 9DBB0 0019DBB0 00000000 */   nop
    /* 9DBB4 0019DBB4 000A048E */  lw         $4, 0xA00($16)
    /* 9DBB8 0019DBB8 64EA110C */  jal        func_0047a990
    /* 9DBBC 0019DBBC 00000000 */   nop
  .L0019DBC0:
    /* 9DBC0 0019DBC0 A4000010 */  b          .L0019DE54
    /* 9DBC4 0019DBC4 00000000 */   nop
  .L0019DBC8:
    /* 9DBC8 0019DBC8 000A048E */  lw         $4, 0xA00($16)
    /* 9DBCC 0019DBCC 74EA110C */  jal        func_0047a9d0
    /* 9DBD0 0019DBD0 00000000 */   nop
    /* 9DBD4 0019DBD4 07004010 */  beqz       $2, .L0019DBF4
    /* 9DBD8 0019DBD8 00000000 */   nop
    /* 9DBDC 0019DBDC 000A048E */  lw         $4, 0xA00($16)
    /* 9DBE0 0019DBE0 6CEA110C */  jal        func_0047a9b0
    /* 9DBE4 0019DBE4 00000000 */   nop
    /* 9DBE8 0019DBE8 000A048E */  lw         $4, 0xA00($16)
    /* 9DBEC 0019DBEC 64EA110C */  jal        func_0047a990
    /* 9DBF0 0019DBF0 00000000 */   nop
  .L0019DBF4:
    /* 9DBF4 0019DBF4 97000010 */  b          .L0019DE54
    /* 9DBF8 0019DBF8 00000000 */   nop
  .L0019DBFC:
    /* 9DBFC 0019DBFC 640A048E */  lw         $4, 0xA64($16)
    /* 9DC00 0019DC00 10008010 */  beqz       $4, .L0019DC44
    /* 9DC04 0019DC04 00000000 */   nop
    /* 9DC08 0019DC08 00010524 */  addiu      $5, $0, 0x100
    /* 9DC0C 0019DC0C C4C9080C */  jal        func_00232710
    /* 9DC10 0019DC10 00000000 */   nop
    /* 9DC14 0019DC14 0B004010 */  beqz       $2, .L0019DC44
    /* 9DC18 0019DC18 00000000 */   nop
    /* 9DC1C 0019DC1C 000A048E */  lw         $4, 0xA00($16)
    /* 9DC20 0019DC20 74EA110C */  jal        func_0047a9d0
    /* 9DC24 0019DC24 00000000 */   nop
    /* 9DC28 0019DC28 04004010 */  beqz       $2, .L0019DC3C
    /* 9DC2C 0019DC2C 00000000 */   nop
    /* 9DC30 0019DC30 000A048E */  lw         $4, 0xA00($16)
    /* 9DC34 0019DC34 64EA110C */  jal        func_0047a990
    /* 9DC38 0019DC38 00000000 */   nop
  .L0019DC3C:
    /* 9DC3C 0019DC3C 85000010 */  b          .L0019DE54
    /* 9DC40 0019DC40 00000000 */   nop
  .L0019DC44:
    /* 9DC44 0019DC44 B0000396 */  lhu        $3, 0xB0($16)
    /* 9DC48 0019DC48 82006010 */  beqz       $3, .L0019DE54
    /* 9DC4C 0019DC4C 00000000 */   nop
    /* 9DC50 0019DC50 000A048E */  lw         $4, 0xA00($16)
    /* 9DC54 0019DC54 080181C4 */  lwc1       $f1, 0x108($4)
    /* 9DC58 0019DC58 803F033C */  lui        $3, (0x3F800000 >> 16)
    /* 9DC5C 0019DC5C 00008344 */  mtc1       $3, $f0
    /* 9DC60 0019DC60 00000000 */  nop
    /* 9DC64 0019DC64 34080046 */  c.lt.s     $f1, $f0
    /* 9DC68 0019DC68 7A000145 */  bc1t       .L0019DE54
    /* 9DC6C 0019DC6C 00000000 */   nop
    /* 9DC70 0019DC70 80EA110C */  jal        func_0047aa00
    /* 9DC74 0019DC74 00000000 */   nop
    /* 9DC78 0019DC78 FFFF4330 */  andi       $3, $2, 0xFFFF
    /* 9DC7C 0019DC7C 00026330 */  andi       $3, $3, 0x200
    /* 9DC80 0019DC80 74006014 */  bnez       $3, .L0019DE54
    /* 9DC84 0019DC84 00000000 */   nop
    /* 9DC88 0019DC88 B0000496 */  lhu        $4, 0xB0($16)
    /* 9DC8C 0019DC8C 02000324 */  addiu      $3, $0, 0x2
    /* 9DC90 0019DC90 0C008310 */  beq        $4, $3, .L0019DCC4
    /* 9DC94 0019DC94 00000000 */   nop
    /* 9DC98 0019DC98 01000324 */  addiu      $3, $0, 0x1
    /* 9DC9C 0019DC9C 03008310 */  beq        $4, $3, .L0019DCAC
    /* 9DCA0 0019DCA0 00000000 */   nop
    /* 9DCA4 0019DCA4 6B000010 */  b          .L0019DE54
    /* 9DCA8 0019DCA8 00000000 */   nop
  .L0019DCAC:
    /* 9DCAC 0019DCAC 000A048E */  lw         $4, 0xA00($16)
    /* 9DCB0 0019DCB0 B8000526 */  addiu      $5, $16, 0xB8
    /* 9DCB4 0019DCB4 2CEA110C */  jal        func_0047a8b0
    /* 9DCB8 0019DCB8 00000000 */   nop
    /* 9DCBC 0019DCBC 65000010 */  b          .L0019DE54
    /* 9DCC0 0019DCC0 00000000 */   nop
  .L0019DCC4:
    /* 9DCC4 0019DCC4 B400038E */  lw         $3, 0xB4($16)
    /* 9DCC8 0019DCC8 62006010 */  beqz       $3, .L0019DE54
    /* 9DCCC 0019DCCC 00000000 */   nop
    /* 9DCD0 0019DCD0 FFFF6430 */  andi       $4, $3, 0xFFFF
    /* 9DCD4 0019DCD4 F87B060C */  jal        func_0019efe0
    /* 9DCD8 0019DCD8 00000000 */   nop
    /* 9DCDC 0019DCDC 2D884000 */  daddu      $17, $2, $0
    /* 9DCE0 0019DCE0 58002012 */  beqz       $17, .L0019DE44
    /* 9DCE4 0019DCE4 00000000 */   nop
    /* 9DCE8 0019DCE8 56003012 */  beq        $17, $16, .L0019DE44
    /* 9DCEC 0019DCEC 00000000 */   nop
    /* 9DCF0 0019DCF0 9800228E */  lw         $2, 0x98($17)
    /* 9DCF4 0019DCF4 02004230 */  andi       $2, $2, 0x2
    /* 9DCF8 0019DCF8 1F004014 */  bnez       $2, .L0019DD78
    /* 9DCFC 0019DCFC 00000000 */   nop
    /* 9DD00 0019DD00 800020C6 */  lwc1       $f0, 0x80($17)
    /* 9DD04 0019DD04 2C0021C6 */  lwc1       $f1, 0x2C($17)
    /* 9DD08 0019DD08 02000146 */  mul.s      $f0, $f0, $f1
    /* 9DD0C 0019DD0C 6000A0E7 */  swc1       $f0, 0x60($29)
    /* 9DD10 0019DD10 840020C6 */  lwc1       $f0, 0x84($17)
    /* 9DD14 0019DD14 02000146 */  mul.s      $f0, $f0, $f1
    /* 9DD18 0019DD18 6400A0E7 */  swc1       $f0, 0x64($29)
    /* 9DD1C 0019DD1C 880020C6 */  lwc1       $f0, 0x88($17)
    /* 9DD20 0019DD20 02000146 */  mul.s      $f0, $f0, $f1
    /* 9DD24 0019DD24 6800A0E7 */  swc1       $f0, 0x68($29)
    /* 9DD28 0019DD28 5000A427 */  addiu      $4, $29, 0x50
    /* 9DD2C 0019DD2C 6000A527 */  addiu      $5, $29, 0x60
    /* 9DD30 0019DD30 01000624 */  addiu      $6, $0, 0x1
    /* 9DD34 0019DD34 1C002726 */  addiu      $7, $17, 0x1C
    /* 9DD38 0019DD38 D0720F0C */  jal        func_003dcb40
    /* 9DD3C 0019DD3C 00000000 */   nop
    /* 9DD40 0019DD40 040021C6 */  lwc1       $f1, 0x4($17)
    /* 9DD44 0019DD44 5000A0C7 */  lwc1       $f0, 0x50($29)
    /* 9DD48 0019DD48 00000146 */  add.s      $f0, $f0, $f1
    /* 9DD4C 0019DD4C 7000A0E7 */  swc1       $f0, 0x70($29)
    /* 9DD50 0019DD50 080021C6 */  lwc1       $f1, 0x8($17)
    /* 9DD54 0019DD54 5400A0C7 */  lwc1       $f0, 0x54($29)
    /* 9DD58 0019DD58 00000146 */  add.s      $f0, $f0, $f1
    /* 9DD5C 0019DD5C 7400A0E7 */  swc1       $f0, 0x74($29)
    /* 9DD60 0019DD60 0C0021C6 */  lwc1       $f1, 0xC($17)
    /* 9DD64 0019DD64 5800A0C7 */  lwc1       $f0, 0x58($29)
    /* 9DD68 0019DD68 00000146 */  add.s      $f0, $f0, $f1
    /* 9DD6C 0019DD6C 7800A0E7 */  swc1       $f0, 0x78($29)
    /* 9DD70 0019DD70 24000010 */  b          .L0019DE04
    /* 9DD74 0019DD74 00000000 */   nop
  .L0019DD78:
    /* 9DD78 0019DD78 000A248E */  lw         $4, 0xA00($17)
    /* 9DD7C 0019DD7C 2D280000 */  daddu      $5, $0, $0
    /* 9DD80 0019DD80 7000A627 */  addiu      $6, $29, 0x70
    /* 9DD84 0019DD84 B4E9110C */  jal        func_0047a6d0
    /* 9DD88 0019DD88 00000000 */   nop
    /* 9DD8C 0019DD8C 1D004014 */  bnez       $2, .L0019DE04
    /* 9DD90 0019DD90 00000000 */   nop
    /* 9DD94 0019DD94 800020C6 */  lwc1       $f0, 0x80($17)
    /* 9DD98 0019DD98 2C0021C6 */  lwc1       $f1, 0x2C($17)
    /* 9DD9C 0019DD9C 02000146 */  mul.s      $f0, $f0, $f1
    /* 9DDA0 0019DDA0 4000A0E7 */  swc1       $f0, 0x40($29)
    /* 9DDA4 0019DDA4 840020C6 */  lwc1       $f0, 0x84($17)
    /* 9DDA8 0019DDA8 02000146 */  mul.s      $f0, $f0, $f1
    /* 9DDAC 0019DDAC 4400A0E7 */  swc1       $f0, 0x44($29)
    /* 9DDB0 0019DDB0 880020C6 */  lwc1       $f0, 0x88($17)
    /* 9DDB4 0019DDB4 02000146 */  mul.s      $f0, $f0, $f1
    /* 9DDB8 0019DDB8 4800A0E7 */  swc1       $f0, 0x48($29)
    /* 9DDBC 0019DDBC 3000A427 */  addiu      $4, $29, 0x30
    /* 9DDC0 0019DDC0 4000A527 */  addiu      $5, $29, 0x40
    /* 9DDC4 0019DDC4 01000624 */  addiu      $6, $0, 0x1
    /* 9DDC8 0019DDC8 1C002726 */  addiu      $7, $17, 0x1C
    /* 9DDCC 0019DDCC D0720F0C */  jal        func_003dcb40
    /* 9DDD0 0019DDD0 00000000 */   nop
    /* 9DDD4 0019DDD4 040021C6 */  lwc1       $f1, 0x4($17)
    /* 9DDD8 0019DDD8 3000A0C7 */  lwc1       $f0, 0x30($29)
    /* 9DDDC 0019DDDC 00000146 */  add.s      $f0, $f0, $f1
    /* 9DDE0 0019DDE0 7000A0E7 */  swc1       $f0, 0x70($29)
    /* 9DDE4 0019DDE4 080021C6 */  lwc1       $f1, 0x8($17)
    /* 9DDE8 0019DDE8 3400A0C7 */  lwc1       $f0, 0x34($29)
    /* 9DDEC 0019DDEC 00000146 */  add.s      $f0, $f0, $f1
    /* 9DDF0 0019DDF0 7400A0E7 */  swc1       $f0, 0x74($29)
    /* 9DDF4 0019DDF4 0C0021C6 */  lwc1       $f1, 0xC($17)
    /* 9DDF8 0019DDF8 3800A0C7 */  lwc1       $f0, 0x38($29)
    /* 9DDFC 0019DDFC 00000146 */  add.s      $f0, $f0, $f1
    /* 9DE00 0019DE00 7800A0E7 */  swc1       $f0, 0x78($29)
  .L0019DE04:
    /* 9DE04 0019DE04 8C0021C6 */  lwc1       $f1, 0x8C($17)
    /* 9DE08 0019DE08 2C0020C6 */  lwc1       $f0, 0x2C($17)
    /* 9DE0C 0019DE0C C2080046 */  mul.s      $f3, $f1, $f0
    /* 9DE10 0019DE10 088382C7 */  lwc1       $f2, -0x7CF8($28)
    /* 9DE14 0019DE14 7400A1C7 */  lwc1       $f1, 0x74($29)
    /* 9DE18 0019DE18 00008044 */  mtc1       $0, $f0
    /* 9DE1C 0019DE1C 00000000 */  nop
    /* 9DE20 0019DE20 18000146 */  adda.s     $f0, $f1
    /* 9DE24 0019DE24 1C100346 */  madd.s     $f0, $f2, $f3
    /* 9DE28 0019DE28 7400A0E7 */  swc1       $f0, 0x74($29)
    /* 9DE2C 0019DE2C 000A048E */  lw         $4, 0xA00($16)
    /* 9DE30 0019DE30 7000A527 */  addiu      $5, $29, 0x70
    /* 9DE34 0019DE34 2CEA110C */  jal        func_0047a8b0
    /* 9DE38 0019DE38 00000000 */   nop
    /* 9DE3C 0019DE3C 05000010 */  b          .L0019DE54
    /* 9DE40 0019DE40 00000000 */   nop
  .L0019DE44:
    /* 9DE44 0019DE44 000A048E */  lw         $4, 0xA00($16)
    /* 9DE48 0019DE48 64EA110C */  jal        func_0047a990
    /* 9DE4C 0019DE4C 00000000 */   nop
    /* 9DE50 0019DE50 B40000AE */  sw         $0, 0xB4($16)
  .L0019DE54:
    /* 9DE54 0019DE54 2000BFDF */  ld         $31, 0x20($29)
    /* 9DE58 0019DE58 1000B17B */  lq         $17, 0x10($29)
    /* 9DE5C 0019DE5C 0000B07B */  lq         $16, 0x0($29)
    /* 9DE60 0019DE60 8000BD27 */  addiu      $29, $29, 0x80
    /* 9DE64 0019DE64 0800E003 */  jr         $31
    /* 9DE68 0019DE68 00000000 */   nop
    /* 9DE6C 0019DE6C 00000000 */  nop
.size func_0019db40, 0x330
