.section .text
.set noat
.set noreorder
glabel func_0029db50
    /* 19DB50 0029DB50 A0FFBD27 */  addiu      $29, $29, -0x60
    /* 19DB54 0029DB54 5000BFFF */  sd         $31, 0x50($29)
    /* 19DB58 0029DB58 4000B47F */  sq         $20, 0x40($29)
    /* 19DB5C 0029DB5C 3000B37F */  sq         $19, 0x30($29)
    /* 19DB60 0029DB60 2000B27F */  sq         $18, 0x20($29)
    /* 19DB64 0029DB64 1000B17F */  sq         $17, 0x10($29)
    /* 19DB68 0029DB68 0000B07F */  sq         $16, 0x0($29)
    /* 19DB6C 0029DB6C 2D888000 */  daddu      $17, $4, $0
    /* 19DB70 0029DB70 2DA0A000 */  daddu      $20, $5, $0
    /* 19DB74 0029DB74 2D98C000 */  daddu      $19, $6, $0
    /* 19DB78 0029DB78 2D80E000 */  daddu      $16, $7, $0
    /* 19DB7C 0029DB7C 6400043C */  lui        $4, %hi(D_0063E3D0)
    /* 19DB80 0029DB80 D0E38424 */  addiu      $4, $4, %lo(D_0063E3D0)
    /* 19DB84 0029DB84 75020524 */  addiu      $5, $0, 0x275
    /* 19DB88 0029DB88 B4A8110C */  jal        func_0046a2d0
    /* 19DB8C 0029DB8C 00000000 */   nop
    /* 19DB90 0029DB90 2D206002 */  daddu      $4, $19, $0
    /* 19DB94 0029DB94 0CA9110C */  jal        func_0046a430
    /* 19DB98 0029DB98 00000000 */   nop
    /* 19DB9C 0029DB9C 2D904000 */  daddu      $18, $2, $0
    /* 19DBA0 0029DBA0 2D204002 */  daddu      $4, $18, $0
    /* 19DBA4 0029DBA4 2D280000 */  daddu      $5, $0, $0
    /* 19DBA8 0029DBA8 2D306002 */  daddu      $6, $19, $0
    /* 19DBAC 0029DBAC 72FE100C */  jal        func_0043f9c8
    /* 19DBB0 0029DBB0 00000000 */   nop
    /* 19DBB4 0029DBB4 2D204002 */  daddu      $4, $18, $0
    /* 19DBB8 0029DBB8 2D288002 */  daddu      $5, $20, $0
    /* 19DBBC 0029DBBC 2D306002 */  daddu      $6, $19, $0
    /* 19DBC0 0029DBC0 04FE100C */  jal        func_0043f810
    /* 19DBC4 0029DBC4 00000000 */   nop
    /* 19DBC8 0029DBC8 2D204002 */  daddu      $4, $18, $0
    /* 19DBCC 0029DBCC 2D280002 */  daddu      $5, $16, $0
    /* 19DBD0 0029DBD0 98750A0C */  jal        func_0029d660
    /* 19DBD4 0029DBD4 00000000 */   nop
    /* 19DBD8 0029DBD8 2D804000 */  daddu      $16, $2, $0
    /* 19DBDC 0029DBDC 06000016 */  bnez       $16, .L0029DBF8
    /* 19DBE0 0029DBE0 00000000 */   nop
    /* 19DBE4 0029DBE4 6400043C */  lui        $4, %hi(D_0063E3D0)
    /* 19DBE8 0029DBE8 D0E38424 */  addiu      $4, $4, %lo(D_0063E3D0)
    /* 19DBEC 0029DBEC 7C020524 */  addiu      $5, $0, 0x27C
    /* 19DBF0 0029DBF0 CCB5110C */  jal        func_0046d730
    /* 19DBF4 0029DBF4 00000000 */   nop
  .L0029DBF8:
    /* 19DBF8 0029DBF8 3C0112AE */  sw         $18, 0x13C($16)
    /* 19DBFC 0029DBFC 2C01028E */  lw         $2, 0x12C($16)
    /* 19DC00 0029DC00 40190200 */  sll        $3, $2, 5
    /* 19DC04 0029DC04 1801028E */  lw         $2, 0x118($16)
    /* 19DC08 0029DC08 21204300 */  addu       $4, $2, $3
    /* 19DC0C 0029DC0C 2D282002 */  daddu      $5, $17, $0
    /* 19DC10 0029DC10 01000624 */  addiu      $6, $0, 0x1
    /* 19DC14 0029DC14 2D38C000 */  daddu      $7, $6, $0
    /* 19DC18 0029DC18 2A00083C */  lui        $8, %hi(func_0029d870)
    /* 19DC1C 0029DC1C 70D80825 */  addiu      $8, $8, %lo(func_0029d870)
    /* 19DC20 0029DC20 2A00093C */  lui        $9, %hi(func_0029d900)
    /* 19DC24 0029DC24 00D92925 */  addiu      $9, $9, %lo(func_0029d900)
    /* 19DC28 0029DC28 2D500002 */  daddu      $10, $16, $0
    /* 19DC2C 0029DC2C 7847110C */  jal        func_00451de0
    /* 19DC30 0029DC30 00000000 */   nop
    /* 19DC34 0029DC34 2D884000 */  daddu      $17, $2, $0
    /* 19DC38 0029DC38 06002016 */  bnez       $17, .L0029DC54
    /* 19DC3C 0029DC3C 00000000 */   nop
    /* 19DC40 0029DC40 6400043C */  lui        $4, %hi(D_0063E3D0)
    /* 19DC44 0029DC44 D0E38424 */  addiu      $4, $4, %lo(D_0063E3D0)
    /* 19DC48 0029DC48 F4010524 */  addiu      $5, $0, 0x1F4
    /* 19DC4C 0029DC4C CCB5110C */  jal        func_0046d730
    /* 19DC50 0029DC50 00000000 */   nop
  .L0029DC54:
    /* 19DC54 0029DC54 480111AE */  sw         $17, 0x148($16)
    /* 19DC58 0029DC58 2D102002 */  daddu      $2, $17, $0
    /* 19DC5C 0029DC5C 5000BFDF */  ld         $31, 0x50($29)
    /* 19DC60 0029DC60 4000B47B */  lq         $20, 0x40($29)
    /* 19DC64 0029DC64 3000B37B */  lq         $19, 0x30($29)
    /* 19DC68 0029DC68 2000B27B */  lq         $18, 0x20($29)
    /* 19DC6C 0029DC6C 1000B17B */  lq         $17, 0x10($29)
    /* 19DC70 0029DC70 0000B07B */  lq         $16, 0x0($29)
    /* 19DC74 0029DC74 6000BD27 */  addiu      $29, $29, 0x60
    /* 19DC78 0029DC78 0800E003 */  jr         $31
    /* 19DC7C 0029DC7C 00000000 */   nop
.size func_0029db50, 0x130
