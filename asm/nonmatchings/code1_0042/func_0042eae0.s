.section .text
.set noat
.set noreorder
glabel func_0042eae0
    /* 32EAE0 0042EAE0 50FFBD27 */  addiu      $29, $29, -0xB0
    /* 32EAE4 0042EAE4 4000B3FF */  sd         $19, 0x40($29)
    /* 32EAE8 0042EAE8 2D988000 */  daddu      $19, $4, $0
    /* 32EAEC 0042EAEC A000BFFF */  sd         $31, 0xA0($29)
    /* 32EAF0 0042EAF0 9000BEFF */  sd         $30, 0x90($29)
    /* 32EAF4 0042EAF4 01000424 */  addiu      $4, $0, 0x1
    /* 32EAF8 0042EAF8 8000B7FF */  sd         $23, 0x80($29)
    /* 32EAFC 0042EAFC 7000B6FF */  sd         $22, 0x70($29)
    /* 32EB00 0042EB00 6000B5FF */  sd         $21, 0x60($29)
    /* 32EB04 0042EB04 5000B4FF */  sd         $20, 0x50($29)
    /* 32EB08 0042EB08 3000B2FF */  sd         $18, 0x30($29)
    /* 32EB0C 0042EB0C 2000B1FF */  sd         $17, 0x20($29)
    /* 32EB10 0042EB10 1ABA100C */  jal        func_0042e868
    /* 32EB14 0042EB14 1000B0FF */   sd        $16, 0x10($29)
    /* 32EB18 0042EB18 9F004014 */  bnez       $2, .L0042ED98
    /* 32EB1C 0042EB1C 2D100000 */   daddu     $2, $0, $0
    /* 32EB20 0042EB20 2D200000 */  daddu      $4, $0, $0
    /* 32EB24 0042EB24 CA93100C */  jal        func_00424f28
    /* 32EB28 0042EB28 7100153C */   lui       $21, %hi(D_0070DD1C)
    /* 32EB2C 0042EB2C 7100143C */  lui        $20, %hi(D_0070DD18)
    /* 32EB30 0042EB30 01000224 */  addiu      $2, $0, 0x1
    /* 32EB34 0042EB34 7100033C */  lui        $3, %hi(D_0070DCE4)
    /* 32EB38 0042EB38 E4DC62AC */  sw         $2, %lo(D_0070DCE4)($3)
    /* 32EB3C 0042EB3C 7100053C */  lui        $5, %hi(D_0070DD0C)
    /* 32EB40 0042EB40 1CDDA48E */  lw         $4, %lo(D_0070DD1C)($21)
    /* 32EB44 0042EB44 FFFF0324 */  addiu      $3, $0, -0x1
    /* 32EB48 0042EB48 7100023C */  lui        $2, %hi(D_0070DD08)
    /* 32EB4C 0042EB4C 7100063C */  lui        $6, %hi(D_0070DCFC)
    /* 32EB50 0042EB50 01008424 */  addiu      $4, $4, 0x1
    /* 32EB54 0042EB54 7100073C */  lui        $7, %hi(D_0070DD14)
    /* 32EB58 0042EB58 7100093C */  lui        $9, %hi(D_0070DD10)
    /* 32EB5C 0042EB5C 7100083C */  lui        $8, %hi(D_0070DCF8)
    /* 32EB60 0042EB60 08DD43AC */  sw         $3, %lo(D_0070DD08)($2)
    /* 32EB64 0042EB64 8900103C */  lui        $16, %hi(D_00894F00)
    /* 32EB68 0042EB68 8900023C */  lui        $2, %hi(D_00894EA8)
    /* 32EB6C 0042EB6C 0CDDA3AC */  sw         $3, %lo(D_0070DD0C)($5)
    /* 32EB70 0042EB70 FCDCC3AC */  sw         $3, %lo(D_0070DCFC)($6)
    /* 32EB74 0042EB74 A84E5124 */  addiu      $17, $2, %lo(D_00894EA8)
    /* 32EB78 0042EB78 14DDE3AC */  sw         $3, %lo(D_0070DD14)($7)
    /* 32EB7C 0042EB7C 004F1226 */  addiu      $18, $16, %lo(D_00894F00)
    /* 32EB80 0042EB80 10DD23AD */  sw         $3, %lo(D_0070DD10)($9)
    /* 32EB84 0042EB84 71001E3C */  lui        $30, %hi(D_0070EEC0)
    /* 32EB88 0042EB88 F8DC00AD */  sw         $0, %lo(D_0070DCF8)($8)
    /* 32EB8C 0042EB8C 7100173C */  lui        $23, %hi(D_0070DCD0)
    /* 32EB90 0042EB90 1CDDA4AE */  sw         $4, %lo(D_0070DD1C)($21)
    /* 32EB94 0042EB94 7500163C */  lui        $22, %hi(D_00754630)
    /* 32EB98 0042EB98 18DD83AE */  sw         $3, %lo(D_0070DD18)($20)
    /* 32EB9C 0042EB9C 00000000 */  nop
  .L0042EBA0:
    /* 32EBA0 0042EBA0 0080053C */  lui        $5, (0x80000592 >> 16)
    /* 32EBA4 0042EBA4 2D202002 */  daddu      $4, $17, $0
    /* 32EBA8 0042EBA8 9205A534 */  ori        $5, $5, (0x80000592 & 0xFFFF)
    /* 32EBAC 0042EBAC B495100C */  jal        func_004256d0
    /* 32EBB0 0042EBB0 2D300000 */   daddu     $6, $0, $0
    /* 32EBB4 0042EBB4 2D284000 */  daddu      $5, $2, $0
    /* 32EBB8 0042EBB8 1200A304 */  bgezl      $5, .L0042EC04
    /* 32EBBC 0042EBBC 2400228E */   lw        $2, 0x24($17)
    /* 32EBC0 0042EBC0 D0DCE28E */  lw         $2, %lo(D_0070DCD0)($23)
    /* 32EBC4 0042EBC4 03004018 */  blez       $2, .L0042EBD4
    /* 32EBC8 0042EBC8 1CDDA68E */   lw        $6, %lo(D_0070DD1C)($21)
    /* 32EBCC 0042EBCC 3291100C */  jal        func_004244c8
    /* 32EBD0 0042EBD0 3046C426 */   addiu     $4, $22, %lo(D_00754630)
  .L0042EBD4:
    /* 32EBD4 0042EBD4 1000023C */  lui        $2, %hi(D_FFFFF)
    /* 32EBD8 0042EBD8 FFFF0324 */  addiu      $3, $0, -0x1
    /* 32EBDC 0042EBDC 00000000 */  nop
  .L0042EBE0:
    /* 32EBE0 0042EBE0 FFFF4224 */  addiu      $2, $2, %lo(D_FFFFF)
    /* 32EBE4 0042EBE4 00000000 */  nop
    /* 32EBE8 0042EBE8 00000000 */  nop
    /* 32EBEC 0042EBEC 00000000 */  nop
    /* 32EBF0 0042EBF0 00000000 */  nop
    /* 32EBF4 0042EBF4 FAFF4314 */  bne        $2, $3, .L0042EBE0
    /* 32EBF8 0042EBF8 00000000 */   nop
    /* 32EBFC 0042EBFC E8FF0010 */  b          .L0042EBA0
    /* 32EC00 0042EC00 00000000 */   nop
  .L0042EC04:
    /* 32EC04 0042EC04 15004010 */  beqz       $2, .L0042EC5C
    /* 32EC08 0042EC08 2D204002 */   daddu     $4, $18, $0
    /* 32EC0C 0042EC0C 004F13AE */  sw         $19, %lo(D_00894F00)($16)
    /* 32EC10 0042EC10 18DD80AE */  sw         $0, %lo(D_0070DD18)($20)
    /* 32EC14 0042EC14 9E93100C */  jal        func_00424e78
    /* 32EC18 0042EC18 04000524 */   addiu     $5, $0, 0x4
    /* 32EC1C 0042EC1C C0EED027 */  addiu      $16, $30, %lo(D_0070EEC0)
    /* 32EC20 0042EC20 2D202002 */  daddu      $4, $17, $0
    /* 32EC24 0042EC24 2D384002 */  daddu      $7, $18, $0
    /* 32EC28 0042EC28 0000A0AF */  sw         $0, 0x0($29)
    /* 32EC2C 0042EC2C 2D280000 */  daddu      $5, $0, $0
    /* 32EC30 0042EC30 2D300000 */  daddu      $6, $0, $0
    /* 32EC34 0042EC34 04000824 */  addiu      $8, $0, 0x4
    /* 32EC38 0042EC38 2D480002 */  daddu      $9, $16, $0
    /* 32EC3C 0042EC3C 10000A24 */  addiu      $10, $0, 0x10
    /* 32EC40 0042EC40 2C96100C */  jal        func_004258b0
    /* 32EC44 0042EC44 2D580000 */   daddu     $11, $0, $0
    /* 32EC48 0042EC48 10004104 */  bgez       $2, .L0042EC8C
    /* 32EC4C 0042EC4C 7100023C */   lui       $2, %hi(D_0070DCE4)
    /* 32EC50 0042EC50 E4DC40AC */  sw         $0, %lo(D_0070DCE4)($2)
    /* 32EC54 0042EC54 50000010 */  b          .L0042ED98
    /* 32EC58 0042EC58 2D100000 */   daddu     $2, $0, $0
  .L0042EC5C:
    /* 32EC5C 0042EC5C 1000023C */  lui        $2, %hi(D_FFFFF)
    /* 32EC60 0042EC60 FFFF0324 */  addiu      $3, $0, -0x1
    /* 32EC64 0042EC64 00000000 */  nop
  .L0042EC68:
    /* 32EC68 0042EC68 FFFF4224 */  addiu      $2, $2, %lo(D_FFFFF)
    /* 32EC6C 0042EC6C 00000000 */  nop
    /* 32EC70 0042EC70 00000000 */  nop
    /* 32EC74 0042EC74 00000000 */  nop
    /* 32EC78 0042EC78 00000000 */  nop
    /* 32EC7C 0042EC7C FAFF4314 */  bne        $2, $3, .L0042EC68
    /* 32EC80 0042EC80 00000000 */   nop
    /* 32EC84 0042EC84 C6FF0010 */  b          .L0042EBA0
    /* 32EC88 0042EC88 00000000 */   nop
  .L0042EC8C:
    /* 32EC8C 0042EC8C 0020053C */  lui        $5, (0x20000000 >> 16)
    /* 32EC90 0042EC90 0C000226 */  addiu      $2, $16, 0xC
    /* 32EC94 0042EC94 25104500 */  or         $2, $2, $5
    /* 32EC98 0042EC98 04000326 */  addiu      $3, $16, 0x4
    /* 32EC9C 0042EC9C 08000426 */  addiu      $4, $16, 0x8
    /* 32ECA0 0042ECA0 0000468C */  lw         $6, (0x20000000 & 0xFFFF)($2)
    /* 32ECA4 0042ECA4 25208500 */  or         $4, $4, $5
    /* 32ECA8 0042ECA8 25186500 */  or         $3, $3, $5
    /* 32ECAC 0042ECAC 0000658C */  lw         $5, (0x20000000 & 0xFFFF)($3)
    /* 32ECB0 0042ECB0 01001024 */  addiu      $16, $0, 0x1
    /* 32ECB4 0042ECB4 FF000224 */  addiu      $2, $0, 0xFF
    /* 32ECB8 0042ECB8 1600C210 */  beq        $6, $2, .L0042ED14
    /* 32ECBC 0042ECBC 0000848C */   lw        $4, (0x20000000 & 0xFFFF)($4)
    /* 32ECC0 0042ECC0 FE000224 */  addiu      $2, $0, 0xFE
    /* 32ECC4 0042ECC4 0400C214 */  bne        $6, $2, .L0042ECD8
    /* 32ECC8 0042ECC8 FFFF0624 */   addiu     $6, $0, -0x1
    /* 32ECCC 0042ECCC 7100023C */  lui        $2, %hi(D_0070DCD0)
    /* 32ECD0 0042ECD0 10000010 */  b          .L0042ED14
    /* 32ECD4 0042ECD4 D0DC50AC */   sw        $16, %lo(D_0070DCD0)($2)
  .L0042ECD8:
    /* 32ECD8 0042ECD8 FF00A224 */  addiu      $2, $5, 0xFF
    /* 32ECDC 0042ECDC 2A18C500 */  slt        $3, $6, $5
    /* 32ECE0 0042ECE0 0B10A300 */  movn       $2, $5, $3
    /* 32ECE4 0042ECE4 03120200 */  sra        $2, $2, 8
    /* 32ECE8 0042ECE8 02004228 */  slti       $2, $2, 0x2
    /* 32ECEC 0042ECEC 09004054 */  bnel       $2, $0, .L0042ED14
    /* 32ECF0 0042ECF0 02001024 */   addiu     $16, $0, 0x2
    /* 32ECF4 0042ECF4 2A18C400 */  slt        $3, $6, $4
    /* 32ECF8 0042ECF8 FF008224 */  addiu      $2, $4, 0xFF
    /* 32ECFC 0042ECFC 0B108300 */  movn       $2, $4, $3
    /* 32ED00 0042ED00 03120200 */  sra        $2, $2, 8
    /* 32ED04 0042ED04 02004228 */  slti       $2, $2, 0x2
    /* 32ED08 0042ED08 03004010 */  beqz       $2, .L0042ED18
    /* 32ED0C 0042ED0C 7100033C */   lui       $3, %hi(D_0070DCE4)
    /* 32ED10 0042ED10 02001024 */  addiu      $16, $0, 0x2
  .L0042ED14:
    /* 32ED14 0042ED14 7100033C */  lui        $3, %hi(D_0070DCE4)
  .L0042ED18:
    /* 32ED18 0042ED18 E4DC60AC */  sw         $0, %lo(D_0070DCE4)($3)
    /* 32ED1C 0042ED1C 16006006 */  bltz       $19, .L0042ED78
    /* 32ED20 0042ED20 0200622A */   slti      $2, $19, 0x2
    /* 32ED24 0042ED24 14004014 */  bnez       $2, .L0042ED78
    /* 32ED28 0042ED28 05000224 */   addiu     $2, $0, 0x5
    /* 32ED2C 0042ED2C 12006216 */  bne        $19, $2, .L0042ED78
    /* 32ED30 0042ED30 7100023C */   lui       $2, %hi(D_0070DCD0)
    /* 32ED34 0042ED34 D0DC438C */  lw         $3, %lo(D_0070DCD0)($2)
    /* 32ED38 0042ED38 03006018 */  blez       $3, .L0042ED48
    /* 32ED3C 0042ED3C 7500043C */   lui       $4, %hi(D_00754650)
    /* 32ED40 0042ED40 3291100C */  jal        func_004244c8
    /* 32ED44 0042ED44 50468424 */   addiu     $4, $4, %lo(D_00754650)
  .L0042ED48:
    /* 32ED48 0042ED48 32B8100C */  jal        func_0042e0c8
    /* 32ED4C 0042ED4C 00000000 */   nop
    /* 32ED50 0042ED50 FFFF0424 */  addiu      $4, $0, -0x1
    /* 32ED54 0042ED54 7100023C */  lui        $2, %hi(D_0070DCE8)
    /* 32ED58 0042ED58 E8DC44AC */  sw         $4, %lo(D_0070DCE8)($2)
    /* 32ED5C 0042ED5C 7100033C */  lui        $3, %hi(D_0070DCEC)
    /* 32ED60 0042ED60 ECDC64AC */  sw         $4, %lo(D_0070DCEC)($3)
    /* 32ED64 0042ED64 7100023C */  lui        $2, %hi(D_0070DCE0)
    /* 32ED68 0042ED68 7100033C */  lui        $3, %hi(D_0070DD04)
    /* 32ED6C 0042ED6C E0DC44AC */  sw         $4, %lo(D_0070DCE0)($2)
    /* 32ED70 0042ED70 08000010 */  b          .L0042ED94
    /* 32ED74 0042ED74 04DD60AC */   sw        $0, %lo(D_0070DD04)($3)
  .L0042ED78:
    /* 32ED78 0042ED78 F8B7100C */  jal        func_0042dfe0
    /* 32ED7C 0042ED7C 00000000 */   nop
    /* 32ED80 0042ED80 90B8100C */  jal        func_0042e240
    /* 32ED84 0042ED84 00000000 */   nop
    /* 32ED88 0042ED88 7100033C */  lui        $3, %hi(D_0070DD04)
    /* 32ED8C 0042ED8C 01000224 */  addiu      $2, $0, 0x1
    /* 32ED90 0042ED90 04DD62AC */  sw         $2, %lo(D_0070DD04)($3)
  .L0042ED94:
    /* 32ED94 0042ED94 2D100002 */  daddu      $2, $16, $0
  .L0042ED98:
    /* 32ED98 0042ED98 A000BFDF */  ld         $31, 0xA0($29)
    /* 32ED9C 0042ED9C 9000BEDF */  ld         $30, 0x90($29)
    /* 32EDA0 0042EDA0 8000B7DF */  ld         $23, 0x80($29)
    /* 32EDA4 0042EDA4 7000B6DF */  ld         $22, 0x70($29)
    /* 32EDA8 0042EDA8 6000B5DF */  ld         $21, 0x60($29)
    /* 32EDAC 0042EDAC 5000B4DF */  ld         $20, 0x50($29)
    /* 32EDB0 0042EDB0 4000B3DF */  ld         $19, 0x40($29)
    /* 32EDB4 0042EDB4 3000B2DF */  ld         $18, 0x30($29)
    /* 32EDB8 0042EDB8 2000B1DF */  ld         $17, 0x20($29)
    /* 32EDBC 0042EDBC 1000B0DF */  ld         $16, 0x10($29)
    /* 32EDC0 0042EDC0 0800E003 */  jr         $31
    /* 32EDC4 0042EDC4 B000BD27 */   addiu     $29, $29, 0xB0
.size func_0042eae0, 0x2e8
