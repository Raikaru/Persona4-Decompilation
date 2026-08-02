.section .text
.set noat
.set noreorder
glabel func_0049db20
    /* 39DB20 0049DB20 B0FFBD27 */  addiu      $29, $29, -0x50
    /* 39DB24 0049DB24 3000BFFF */  sd         $31, 0x30($29)
    /* 39DB28 0049DB28 2000B27F */  sq         $18, 0x20($29)
    /* 39DB2C 0049DB2C 1000B17F */  sq         $17, 0x10($29)
    /* 39DB30 0049DB30 0000B07F */  sq         $16, 0x0($29)
    /* 39DB34 0049DB34 2D908000 */  daddu      $18, $4, $0
    /* 39DB38 0049DB38 3C00838C */  lw         $3, 0x3C($4)
    /* 39DB3C 0049DB3C 4000918C */  lw         $17, 0x40($4)
    /* 39DB40 0049DB40 0400708C */  lw         $16, 0x4($3)
    /* 39DB44 0049DB44 3400868C */  lw         $6, 0x34($4)
    /* 39DB48 0049DB48 3400278E */  lw         $7, 0x34($17)
    /* 39DB4C 0049DB4C 2B08E600 */  sltu       $1, $7, $6
    /* 39DB50 0049DB50 03002010 */  beqz       $1, .L0049DB60
    /* 39DB54 0049DB54 00000000 */   nop
    /* 39DB58 0049DB58 5A00E014 */  bnez       $7, .L0049DCC4
    /* 39DB5C 0049DB5C 00000000 */   nop
  .L0049DB60:
    /* 39DB60 0049DB60 2D202002 */  daddu      $4, $17, $0
    /* 39DB64 0049DB64 24002526 */  addiu      $5, $17, 0x24
    /* 39DB68 0049DB68 F42A120C */  jal        func_0048abd0
    /* 39DB6C 0049DB6C 00000000 */   nop
    /* 39DB70 0049DB70 2D184000 */  daddu      $3, $2, $0
    /* 39DB74 0049DB74 3000428E */  lw         $2, 0x30($18)
    /* 39DB78 0049DB78 4800A2AF */  sw         $2, 0x48($29)
    /* 39DB7C 0049DB7C 4800A227 */  addiu      $2, $29, 0x48
    /* 39DB80 0049DB80 448080C7 */  lwc1       $f0, -0x7FBC($28)
    /* 39DB84 0049DB84 0000428C */  lw         $2, 0x0($2)
    /* 39DB88 0049DB88 88160270 */  pextlb     $2, $0, $2
    /* 39DB8C 0049DB8C 88150270 */  pextlh     $2, $0, $2
    /* 39DB90 0049DB90 0050A248 */  qmtc2.ni   $2, $vf10
    /* 39DB94 0049DB94 3C51EA4B */  vitof0.xyzw $vf10, $vf10
    /* 39DB98 0049DB98 00000244 */  mfc1       $2, $f0
    /* 39DB9C 0049DB9C 00000000 */  nop
    /* 39DBA0 0049DBA0 0010A248 */  qmtc2.ni   $2, $vf2
    /* 39DBA4 0049DBA4 9852E24B */  vmulx.xyzw $vf10, $vf10, $vf2x
    /* 39DBA8 0049DBA8 3C53EB4B */  vmove.xyzw $vf11, $vf10
    /* 39DBAC 0049DBAC 4400A3AF */  sw         $3, 0x44($29)
    /* 39DBB0 0049DBB0 4400A227 */  addiu      $2, $29, 0x44
    /* 39DBB4 0049DBB4 0000428C */  lw         $2, 0x0($2)
    /* 39DBB8 0049DBB8 88160270 */  pextlb     $2, $0, $2
    /* 39DBBC 0049DBBC 88150270 */  pextlh     $2, $0, $2
    /* 39DBC0 0049DBC0 0050A248 */  qmtc2.ni   $2, $vf10
    /* 39DBC4 0049DBC4 3C51EA4B */  vitof0.xyzw $vf10, $vf10
    /* 39DBC8 0049DBC8 00000244 */  mfc1       $2, $f0
    /* 39DBCC 0049DBCC 00000000 */  nop
    /* 39DBD0 0049DBD0 0010A248 */  qmtc2.ni   $2, $vf2
    /* 39DBD4 0049DBD4 9852E24B */  vmulx.xyzw $vf10, $vf10, $vf2x
    /* 39DBD8 0049DBD8 AA52EB4B */  vmul.xyzw  $vf10, $vf10, $vf11
    /* 39DBDC 0049DBDC 7F43023C */  lui        $2, (0x437F0000 >> 16)
    /* 39DBE0 0049DBE0 0010A248 */  qmtc2.ni   $2, $vf2
    /* 39DBE4 0049DBE4 9852E24B */  vmulx.xyzw $vf10, $vf10, $vf2x
    /* 39DBE8 0049DBE8 7C51EA4B */  vftoi0.xyzw $vf10, $vf10
    /* 39DBEC 0049DBEC 00502248 */  qmfc2.ni   $2, $vf10
    /* 39DBF0 0049DBF0 C8150270 */  ppach      $2, $0, $2
    /* 39DBF4 0049DBF4 C8160270 */  ppacb      $2, $0, $2
    /* 39DBF8 0049DBF8 4000A2AF */  sw         $2, 0x40($29)
    /* 39DBFC 0049DBFC 4000A28F */  lw         $2, 0x40($29)
    /* 39DC00 0049DC00 4C00A2AF */  sw         $2, 0x4C($29)
    /* 39DC04 0049DC04 4F00A293 */  lbu        $2, 0x4F($29)
    /* 39DC08 0049DC08 FF000724 */  addiu      $7, $0, 0xFF
    /* 39DC0C 0049DC0C 0C004710 */  beq        $2, $7, .L0049DC40
    /* 39DC10 0049DC10 00000000 */   nop
    /* 39DC14 0049DC14 1400068E */  lw         $6, 0x14($16)
    /* 39DC18 0049DC18 4C00A593 */  lbu        $5, 0x4C($29)
    /* 39DC1C 0049DC1C 4D00A493 */  lbu        $4, 0x4D($29)
    /* 39DC20 0049DC20 4E00A393 */  lbu        $3, 0x4E($29)
    /* 39DC24 0049DC24 4F00A293 */  lbu        $2, 0x4F($29)
    /* 39DC28 0049DC28 0400C5A0 */  sb         $5, 0x4($6)
    /* 39DC2C 0049DC2C 0500C4A0 */  sb         $4, 0x5($6)
    /* 39DC30 0049DC30 0600C3A0 */  sb         $3, 0x6($6)
    /* 39DC34 0049DC34 0700C2A0 */  sb         $2, 0x7($6)
    /* 39DC38 0049DC38 0D000010 */  b          .L0049DC70
    /* 39DC3C 0049DC3C 00000000 */   nop
  .L0049DC40:
    /* 39DC40 0049DC40 FE000224 */  addiu      $2, $0, 0xFE
    /* 39DC44 0049DC44 4F00A2A3 */  sb         $2, 0x4F($29)
    /* 39DC48 0049DC48 1400068E */  lw         $6, 0x14($16)
    /* 39DC4C 0049DC4C 4C00A593 */  lbu        $5, 0x4C($29)
    /* 39DC50 0049DC50 4D00A493 */  lbu        $4, 0x4D($29)
    /* 39DC54 0049DC54 4E00A393 */  lbu        $3, 0x4E($29)
    /* 39DC58 0049DC58 4F00A293 */  lbu        $2, 0x4F($29)
    /* 39DC5C 0049DC5C 0400C5A0 */  sb         $5, 0x4($6)
    /* 39DC60 0049DC60 0500C4A0 */  sb         $4, 0x5($6)
    /* 39DC64 0049DC64 0600C3A0 */  sb         $3, 0x6($6)
    /* 39DC68 0049DC68 0700C2A0 */  sb         $2, 0x7($6)
    /* 39DC6C 0049DC6C 4F00A7A3 */  sb         $7, 0x4F($29)
  .L0049DC70:
    /* 39DC70 0049DC70 2D200002 */  daddu      $4, $16, $0
    /* 39DC74 0049DC74 2D284002 */  daddu      $5, $18, $0
    /* 39DC78 0049DC78 10004626 */  addiu      $6, $18, 0x10
    /* 39DC7C 0049DC7C 20004726 */  addiu      $7, $18, 0x20
    /* 39DC80 0049DC80 AC0D120C */  jal        func_004836b0
    /* 39DC84 0049DC84 00000000 */   nop
    /* 39DC88 0049DC88 56002292 */  lbu        $2, 0x56($17)
    /* 39DC8C 0049DC8C 06004010 */  beqz       $2, .L0049DCA8
    /* 39DC90 0049DC90 00000000 */   nop
    /* 39DC94 0049DC94 00000296 */  lhu        $2, 0x0($16)
    /* 39DC98 0049DC98 01004234 */  ori        $2, $2, 0x1
    /* 39DC9C 0049DC9C 000002A6 */  sh         $2, 0x0($16)
    /* 39DCA0 0049DCA0 04000010 */  b          .L0049DCB4
    /* 39DCA4 0049DCA4 00000000 */   nop
  .L0049DCA8:
    /* 39DCA8 0049DCA8 00000296 */  lhu        $2, 0x0($16)
    /* 39DCAC 0049DCAC FEFF4230 */  andi       $2, $2, 0xFFFE
    /* 39DCB0 0049DCB0 000002A6 */  sh         $2, 0x0($16)
  .L0049DCB4:
    /* 39DCB4 0049DCB4 28002596 */  lhu        $5, 0x28($17)
    /* 39DCB8 0049DCB8 2D200002 */  daddu      $4, $16, $0
    /* 39DCBC 0049DCBC 240D120C */  jal        func_00483490
    /* 39DCC0 0049DCC0 00000000 */   nop
  .L0049DCC4:
    /* 39DCC4 0049DCC4 3000BFDF */  ld         $31, 0x30($29)
    /* 39DCC8 0049DCC8 2000B27B */  lq         $18, 0x20($29)
    /* 39DCCC 0049DCCC 1000B17B */  lq         $17, 0x10($29)
    /* 39DCD0 0049DCD0 0000B07B */  lq         $16, 0x0($29)
    /* 39DCD4 0049DCD4 5000BD27 */  addiu      $29, $29, 0x50
    /* 39DCD8 0049DCD8 0800E003 */  jr         $31
    /* 39DCDC 0049DCDC 00000000 */   nop
.size func_0049db20, 0x1c0
