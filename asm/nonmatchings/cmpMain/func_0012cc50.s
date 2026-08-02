.section .text
.set noat
.set noreorder
glabel func_0012cc50
    /* 2CC50 0012CC50 E0FFBD27 */  addiu      $29, $29, -0x20
    /* 2CC54 0012CC54 1000BFFF */  sd         $31, 0x10($29)
    /* 2CC58 0012CC58 0000B07F */  sq         $16, 0x0($29)
    /* 2CC5C 0012CC5C 3800908C */  lw         $16, 0x38($4)
    /* 2CC60 0012CC60 2D200000 */  daddu      $4, $0, $0
    /* 2CC64 0012CC64 C82E0D0C */  jal        func_0034bb20
    /* 2CC68 0012CC68 00000000 */   nop
    /* 2CC6C 0012CC6C 2D200000 */  daddu      $4, $0, $0
    /* 2CC70 0012CC70 98300D0C */  jal        func_0034c260
    /* 2CC74 0012CC74 00000000 */   nop
    /* 2CC78 0012CC78 0000028E */  lw         $2, 0x0($16)
    /* 2CC7C 0012CC7C 0E00412C */  sltiu      $1, $2, 0xE
    /* 2CC80 0012CC80 31002010 */  beqz       $1, .L0012CD48
    /* 2CC84 0012CC84 00000000 */   nop
    /* 2CC88 0012CC88 7400033C */  lui        $3, %hi(jtbl_00746890)
    /* 2CC8C 0012CC8C 90686324 */  addiu      $3, $3, %lo(jtbl_00746890)
    /* 2CC90 0012CC90 80100200 */  sll        $2, $2, 2
    /* 2CC94 0012CC94 21104300 */  addu       $2, $2, $3
    /* 2CC98 0012CC98 0000428C */  lw         $2, 0x0($2)
    /* 2CC9C 0012CC9C 08004000 */  jr         $2
    /* 2CCA0 0012CCA0 00000000 */   nop
    /* 2CCA4 0012CCA4 18000426 */  addiu      $4, $16, 0x18
    /* 2CCA8 0012CCA8 54B8040C */  jal        func_0012e150
    /* 2CCAC 0012CCAC 00000000 */   nop
    /* 2CCB0 0012CCB0 2A000010 */  b          .L0012CD5C
    /* 2CCB4 0012CCB4 00000000 */   nop
    /* 2CCB8 0012CCB8 BC020426 */  addiu      $4, $16, 0x2BC
    /* 2CCBC 0012CCBC 60C1040C */  jal        func_00130580
    /* 2CCC0 0012CCC0 00000000 */   nop
    /* 2CCC4 0012CCC4 25000010 */  b          .L0012CD5C
    /* 2CCC8 0012CCC8 00000000 */   nop
    /* 2CCCC 0012CCCC A41E0426 */  addiu      $4, $16, 0x1EA4
    /* 2CCD0 0012CCD0 CCEA040C */  jal        func_0013ab30
    /* 2CCD4 0012CCD4 00000000 */   nop
    /* 2CCD8 0012CCD8 20000010 */  b          .L0012CD5C
    /* 2CCDC 0012CCDC 00000000 */   nop
    /* 2CCE0 0012CCE0 DC310426 */  addiu      $4, $16, 0x31DC
    /* 2CCE4 0012CCE4 ACD2040C */  jal        func_00134ab0
    /* 2CCE8 0012CCE8 00000000 */   nop
    /* 2CCEC 0012CCEC 1B000010 */  b          .L0012CD5C
    /* 2CCF0 0012CCF0 00000000 */   nop
    /* 2CCF4 0012CCF4 8C5A0426 */  addiu      $4, $16, 0x5A8C
    /* 2CCF8 0012CCF8 F8DD040C */  jal        func_001377e0
    /* 2CCFC 0012CCFC 00000000 */   nop
    /* 2CD00 0012CD00 16000010 */  b          .L0012CD5C
    /* 2CD04 0012CD04 00000000 */   nop
    /* 2CD08 0012CD08 50770426 */  addiu      $4, $16, 0x7750
    /* 2CD0C 0012CD0C AC08050C */  jal        func_001422b0
    /* 2CD10 0012CD10 00000000 */   nop
    /* 2CD14 0012CD14 11000010 */  b          .L0012CD5C
    /* 2CD18 0012CD18 00000000 */   nop
    /* 2CD1C 0012CD1C 00900134 */  ori        $1, $0, 0x9000
    /* 2CD20 0012CD20 21200102 */  addu       $4, $16, $1
    /* 2CD24 0012CD24 8C860D0C */  jal        func_00361a30
    /* 2CD28 0012CD28 00000000 */   nop
    /* 2CD2C 0012CD2C 0B000010 */  b          .L0012CD5C
    /* 2CD30 0012CD30 00000000 */   nop
    /* 2CD34 0012CD34 74470426 */  addiu      $4, $16, 0x4774
    /* 2CD38 0012CD38 C8650D0C */  jal        func_00359720
    /* 2CD3C 0012CD3C 00000000 */   nop
    /* 2CD40 0012CD40 06000010 */  b          .L0012CD5C
    /* 2CD44 0012CD44 00000000 */   nop
  .L0012CD48:
    /* 2CD48 0012CD48 5E00043C */  lui        $4, %hi(D_005E5890)
    /* 2CD4C 0012CD4C 90588424 */  addiu      $4, $4, %lo(D_005E5890)
    /* 2CD50 0012CD50 23020524 */  addiu      $5, $0, 0x223
    /* 2CD54 0012CD54 CCB5110C */  jal        func_0046d730
    /* 2CD58 0012CD58 00000000 */   nop
  .L0012CD5C:
    /* 2CD5C 0012CD5C EC4F0D0C */  jal        func_00353fb0
    /* 2CD60 0012CD60 00000000 */   nop
    /* 2CD64 0012CD64 2D200002 */  daddu      $4, $16, $0
    /* 2CD68 0012CD68 8800023C */  lui        $2, %hi(jtbl_008873EC)
    /* 2CD6C 0012CD6C EC73428C */  lw         $2, %lo(jtbl_008873EC)($2)
    /* 2CD70 0012CD70 09F84000 */  jalr       $2
    /* 2CD74 0012CD74 00000000 */   nop
    /* 2CD78 0012CD78 ECB180AF */  sw         $0, -0x4E14($28)
    /* 2CD7C 0012CD7C 1000BFDF */  ld         $31, 0x10($29)
    /* 2CD80 0012CD80 0000B07B */  lq         $16, 0x0($29)
    /* 2CD84 0012CD84 2000BD27 */  addiu      $29, $29, 0x20
    /* 2CD88 0012CD88 0800E003 */  jr         $31
    /* 2CD8C 0012CD8C 00000000 */   nop
.size func_0012cc50, 0x140
