.section .text
.set noat
.set noreorder
glabel func_0036dba0
    /* 26DBA0 0036DBA0 C0FFBD27 */  addiu      $29, $29, -0x40
    /* 26DBA4 0036DBA4 1000BFFF */  sd         $31, 0x10($29)
    /* 26DBA8 0036DBA8 0000B07F */  sq         $16, 0x0($29)
    /* 26DBAC 0036DBAC 2D808000 */  daddu      $16, $4, $0
    /* 26DBB0 0036DBB0 A80F80AC */  sw         $0, 0xFA8($4)
    /* 26DBB4 0036DBB4 2041023C */  lui        $2, (0x41200000 >> 16)
    /* 26DBB8 0036DBB8 3000A2AF */  sw         $2, 0x30($29)
    /* 26DBBC 0036DBBC 3400A2AF */  sw         $2, 0x34($29)
    /* 26DBC0 0036DBC0 3800A2AF */  sw         $2, 0x38($29)
    /* 26DBC4 0036DBC4 3000A527 */  addiu      $5, $29, 0x30
    /* 26DBC8 0036DBC8 70B70D0C */  jal        func_0036ddc0
    /* 26DBCC 0036DBCC 00000000 */   nop
    /* 26DBD0 0036DBD0 00608044 */  mtc1       $0, $f12
    /* 26DBD4 0036DBD4 2000A0AF */  sw         $0, 0x20($29)
    /* 26DBD8 0036DBD8 803F023C */  lui        $2, (0x3F800000 >> 16)
    /* 26DBDC 0036DBDC 2400A2AF */  sw         $2, 0x24($29)
    /* 26DBE0 0036DBE0 2800A0AF */  sw         $0, 0x28($29)
    /* 26DBE4 0036DBE4 2D200002 */  daddu      $4, $16, $0
    /* 26DBE8 0036DBE8 2000A527 */  addiu      $5, $29, 0x20
    /* 26DBEC 0036DBEC 2D300000 */  daddu      $6, $0, $0
    /* 26DBF0 0036DBF0 78B70D0C */  jal        func_0036dde0
    /* 26DBF4 0036DBF4 00000000 */   nop
    /* 26DBF8 0036DBF8 FF000224 */  addiu      $2, $0, 0xFF
    /* 26DBFC 0036DBFC 3C00A2A3 */  sb         $2, 0x3C($29)
    /* 26DC00 0036DC00 3D00A2A3 */  sb         $2, 0x3D($29)
    /* 26DC04 0036DC04 3E00A2A3 */  sb         $2, 0x3E($29)
    /* 26DC08 0036DC08 3F00A2A3 */  sb         $2, 0x3F($29)
    /* 26DC0C 0036DC0C 2D200002 */  daddu      $4, $16, $0
    /* 26DC10 0036DC10 3C00A527 */  addiu      $5, $29, 0x3C
    /* 26DC14 0036DC14 90B70D0C */  jal        func_0036de40
    /* 26DC18 0036DC18 00000000 */   nop
    /* 26DC1C 0036DC1C 485C110C */  jal        func_00457120
    /* 26DC20 0036DC20 00000000 */   nop
    /* 26DC24 0036DC24 2D200002 */  daddu      $4, $16, $0
    /* 26DC28 0036DC28 0400458C */  lw         $5, 0x4($2)
    /* 26DC2C 0036DC2C 3CAA0D0C */  jal        func_0036a8f0
    /* 26DC30 0036DC30 00000000 */   nop
    /* 26DC34 0036DC34 AC0F0396 */  lhu        $3, 0xFAC($16)
    /* 26DC38 0036DC38 01006334 */  ori        $3, $3, 0x1
    /* 26DC3C 0036DC3C AC0F03A6 */  sh         $3, 0xFAC($16)
    /* 26DC40 0036DC40 1000BFDF */  ld         $31, 0x10($29)
    /* 26DC44 0036DC44 0000B07B */  lq         $16, 0x0($29)
    /* 26DC48 0036DC48 4000BD27 */  addiu      $29, $29, 0x40
    /* 26DC4C 0036DC4C 0800E003 */  jr         $31
    /* 26DC50 0036DC50 00000000 */   nop
    /* 26DC54 0036DC54 00000000 */  nop
    /* 26DC58 0036DC58 00000000 */  nop
    /* 26DC5C 0036DC5C 00000000 */  nop
.size func_0036dba0, 0xc0
