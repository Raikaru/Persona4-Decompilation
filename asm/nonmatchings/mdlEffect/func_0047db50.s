.section .text
.set noat
.set noreorder
glabel func_0047db50
    /* 37DB50 0047DB50 B0FFBD27 */  addiu      $29, $29, -0x50
    /* 37DB54 0047DB54 4000BFFF */  sd         $31, 0x40($29)
    /* 37DB58 0047DB58 3000B37F */  sq         $19, 0x30($29)
    /* 37DB5C 0047DB5C 2000B27F */  sq         $18, 0x20($29)
    /* 37DB60 0047DB60 1000B17F */  sq         $17, 0x10($29)
    /* 37DB64 0047DB64 0000B07F */  sq         $16, 0x0($29)
    /* 37DB68 0047DB68 2D988000 */  daddu      $19, $4, $0
    /* 37DB6C 0047DB6C 2D90A000 */  daddu      $18, $5, $0
    /* 37DB70 0047DB70 7100043C */  lui        $4, %hi(D_007131E8)
    /* 37DB74 0047DB74 E8318424 */  addiu      $4, $4, %lo(D_007131E8)
    /* 37DB78 0047DB78 8A010524 */  addiu      $5, $0, 0x18A
    /* 37DB7C 0047DB7C A43A110C */  jal        func_0044ea90
    /* 37DB80 0047DB80 00000000 */   nop
    /* 37DB84 0047DB84 8800103C */  lui        $16, %hi(jtbl_008873E8)
    /* 37DB88 0047DB88 E8731026 */  addiu      $16, $16, %lo(jtbl_008873E8)
    /* 37DB8C 0047DB8C 10004426 */  addiu      $4, $18, 0x10
    /* 37DB90 0047DB90 0400053C */  lui        $5, (0x40000 >> 16)
    /* 37DB94 0047DB94 0000028E */  lw         $2, 0x0($16)
    /* 37DB98 0047DB98 09F84000 */  jalr       $2
    /* 37DB9C 0047DB9C 00000000 */   nop
    /* 37DBA0 0047DBA0 2D884000 */  daddu      $17, $2, $0
    /* 37DBA4 0047DBA4 10002326 */  addiu      $3, $17, 0x10
    /* 37DBA8 0047DBA8 000043AC */  sw         $3, 0x0($2)
    /* 37DBAC 0047DBAC 01000324 */  addiu      $3, $0, 0x1
    /* 37DBB0 0047DBB0 040043AC */  sw         $3, 0x4($2)
    /* 37DBB4 0047DBB4 0000448C */  lw         $4, 0x0($2)
    /* 37DBB8 0047DBB8 2D286002 */  daddu      $5, $19, $0
    /* 37DBBC 0047DBBC 2D304002 */  daddu      $6, $18, $0
    /* 37DBC0 0047DBC0 04FE100C */  jal        func_0043f810
    /* 37DBC4 0047DBC4 00000000 */   nop
    /* 37DBC8 0047DBC8 7100043C */  lui        $4, %hi(D_007131E8)
    /* 37DBCC 0047DBCC E8318424 */  addiu      $4, $4, %lo(D_007131E8)
    /* 37DBD0 0047DBD0 7C010524 */  addiu      $5, $0, 0x17C
    /* 37DBD4 0047DBD4 A43A110C */  jal        func_0044ea90
    /* 37DBD8 0047DBD8 00000000 */   nop
    /* 37DBDC 0047DBDC 08000424 */  addiu      $4, $0, 0x8
    /* 37DBE0 0047DBE0 0400053C */  lui        $5, (0x40000 >> 16)
    /* 37DBE4 0047DBE4 0000028E */  lw         $2, 0x0($16)
    /* 37DBE8 0047DBE8 09F84000 */  jalr       $2
    /* 37DBEC 0047DBEC 00000000 */   nop
    /* 37DBF0 0047DBF0 2D804000 */  daddu      $16, $2, $0
    /* 37DBF4 0047DBF4 2D200002 */  daddu      $4, $16, $0
    /* 37DBF8 0047DBF8 2D280000 */  daddu      $5, $0, $0
    /* 37DBFC 0047DBFC 08000624 */  addiu      $6, $0, 0x8
    /* 37DC00 0047DC00 72FE100C */  jal        func_0043f9c8
    /* 37DC04 0047DC04 00000000 */   nop
    /* 37DC08 0047DC08 000011AE */  sw         $17, 0x0($16)
    /* 37DC0C 0047DC0C 2D100002 */  daddu      $2, $16, $0
    /* 37DC10 0047DC10 4000BFDF */  ld         $31, 0x40($29)
    /* 37DC14 0047DC14 3000B37B */  lq         $19, 0x30($29)
    /* 37DC18 0047DC18 2000B27B */  lq         $18, 0x20($29)
    /* 37DC1C 0047DC1C 1000B17B */  lq         $17, 0x10($29)
    /* 37DC20 0047DC20 0000B07B */  lq         $16, 0x0($29)
    /* 37DC24 0047DC24 5000BD27 */  addiu      $29, $29, 0x50
    /* 37DC28 0047DC28 0800E003 */  jr         $31
    /* 37DC2C 0047DC2C 00000000 */   nop
.size func_0047db50, 0xe0
