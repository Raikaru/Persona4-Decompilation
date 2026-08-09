.section .text
.set noat
.set noreorder
glabel func_0022db90
    /* 12DB90 0022DB90 ACB3868F */  lw         $6, -0x4C54($28)
    /* 12DB94 0022DB94 0C00C58C */  lw         $5, 0xC($6)
    /* 12DB98 0022DB98 2000033C */  lui        $3, (0x200000 >> 16)
    /* 12DB9C 0022DB9C 2418A300 */  and        $3, $5, $3
    /* 12DBA0 0022DBA0 2F006010 */  beqz       $3, .L0022DC60
    /* 12DBA4 0022DBA4 00000000 */   nop
    /* 12DBA8 0022DBA8 3000858C */  lw         $5, 0x30($4)
    /* 12DBAC 0022DBAC A200A490 */  lbu        $4, 0xA2($5)
    /* 12DBB0 0022DBB0 01000324 */  addiu      $3, $0, 0x1
    /* 12DBB4 0022DBB4 2A008314 */  bne        $4, $3, .L0022DC60
    /* 12DBB8 0022DBB8 00000000 */   nop
    /* 12DBBC 0022DBBC A400A494 */  lhu        $4, 0xA4($5)
    /* 12DBC0 0022DBC0 11010324 */  addiu      $3, $0, 0x111
    /* 12DBC4 0022DBC4 23008310 */  beq        $4, $3, .L0022DC54
    /* 12DBC8 0022DBC8 00000000 */   nop
    /* 12DBCC 0022DBCC 10010324 */  addiu      $3, $0, 0x110
    /* 12DBD0 0022DBD0 1B008310 */  beq        $4, $3, .L0022DC40
    /* 12DBD4 0022DBD4 00000000 */   nop
    /* 12DBD8 0022DBD8 03010324 */  addiu      $3, $0, 0x103
    /* 12DBDC 0022DBDC 13008310 */  beq        $4, $3, .L0022DC2C
    /* 12DBE0 0022DBE0 00000000 */   nop
    /* 12DBE4 0022DBE4 0D010324 */  addiu      $3, $0, 0x10D
    /* 12DBE8 0022DBE8 0B008310 */  beq        $4, $3, .L0022DC18
    /* 12DBEC 0022DBEC 00000000 */   nop
    /* 12DBF0 0022DBF0 02010324 */  addiu      $3, $0, 0x102
    /* 12DBF4 0022DBF4 03008310 */  beq        $4, $3, .L0022DC04
    /* 12DBF8 0022DBF8 00000000 */   nop
    /* 12DBFC 0022DBFC 18000010 */  b          .L0022DC60
    /* 12DC00 0022DC00 00000000 */   nop
  .L0022DC04:
    /* 12DC04 0022DC04 6300033C */  lui        $3, %hi(D_0062A5F0)
    /* 12DC08 0022DC08 F0A56324 */  addiu      $3, $3, %lo(D_0062A5F0)
    /* 12DC0C 0022DC0C 980BC3AC */  sw         $3, 0xB98($6)
    /* 12DC10 0022DC10 13000010 */  b          .L0022DC60
    /* 12DC14 0022DC14 00000000 */   nop
  .L0022DC18:
    /* 12DC18 0022DC18 6300033C */  lui        $3, %hi(D_0062AD40)
    /* 12DC1C 0022DC1C 40AD6324 */  addiu      $3, $3, %lo(D_0062AD40)
    /* 12DC20 0022DC20 980BC3AC */  sw         $3, 0xB98($6)
    /* 12DC24 0022DC24 0E000010 */  b          .L0022DC60
    /* 12DC28 0022DC28 00000000 */   nop
  .L0022DC2C:
    /* 12DC2C 0022DC2C 6300033C */  lui        $3, %hi(D_0062B490)
    /* 12DC30 0022DC30 90B46324 */  addiu      $3, $3, %lo(D_0062B490)
    /* 12DC34 0022DC34 980BC3AC */  sw         $3, 0xB98($6)
    /* 12DC38 0022DC38 09000010 */  b          .L0022DC60
    /* 12DC3C 0022DC3C 00000000 */   nop
  .L0022DC40:
    /* 12DC40 0022DC40 6300033C */  lui        $3, %hi(D_0062BBE0)
    /* 12DC44 0022DC44 E0BB6324 */  addiu      $3, $3, %lo(D_0062BBE0)
    /* 12DC48 0022DC48 980BC3AC */  sw         $3, 0xB98($6)
    /* 12DC4C 0022DC4C 04000010 */  b          .L0022DC60
    /* 12DC50 0022DC50 00000000 */   nop
  .L0022DC54:
    /* 12DC54 0022DC54 6300033C */  lui        $3, %hi(D_0062C330)
    /* 12DC58 0022DC58 30C36324 */  addiu      $3, $3, %lo(D_0062C330)
    /* 12DC5C 0022DC5C 980BC3AC */  sw         $3, 0xB98($6)
  .L0022DC60:
    /* 12DC60 0022DC60 0800E003 */  jr         $31
    /* 12DC64 0022DC64 00000000 */   nop
    /* 12DC68 0022DC68 00000000 */  nop
    /* 12DC6C 0022DC6C 00000000 */  nop
.size func_0022db90, 0xe0
