.section .text
.set noat
.set noreorder
glabel func_0026fca0
    /* 16FCA0 0026FCA0 B0FFBD27 */  addiu      $29, $29, -0x50
    /* 16FCA4 0026FCA4 1000BFFF */  sd         $31, 0x10($29)
    /* 16FCA8 0026FCA8 0000B07F */  sq         $16, 0x0($29)
    /* 16FCAC 0026FCAC 2D80A000 */  daddu      $16, $5, $0
    /* 16FCB0 0026FCB0 A8D1090C */  jal        func_002746a0
    /* 16FCB4 0026FCB4 00000000 */   nop
    /* 16FCB8 0026FCB8 04004010 */  beqz       $2, .L0026FCCC
    /* 16FCBC 0026FCBC 00000000 */   nop
    /* 16FCC0 0026FCC0 2D100000 */  daddu      $2, $0, $0
    /* 16FCC4 0026FCC4 2C000010 */  b          .L0026FD78
    /* 16FCC8 0026FCC8 00000000 */   nop
  .L0026FCCC:
    /* 16FCCC 0026FCCC 01000424 */  addiu      $4, $0, 0x1
    /* 16FCD0 0026FCD0 B435040C */  jal        func_0010d6d0
    /* 16FCD4 0026FCD4 00000000 */   nop
    /* 16FCD8 0026FCD8 2000A427 */  addiu      $4, $29, 0x20
    /* 16FCDC 0026FCDC 34A78527 */  addiu      $5, $28, -0x58CC
    /* 16FCE0 0026FCE0 2D304000 */  daddu      $6, $2, $0
    /* 16FCE4 0026FCE4 2208110C */  jal        func_00442088
    /* 16FCE8 0026FCE8 00000000 */   nop
    /* 16FCEC 0026FCEC 2D200002 */  daddu      $4, $16, $0
    /* 16FCF0 0026FCF0 DCCF090C */  jal        func_00273f70
    /* 16FCF4 0026FCF4 00000000 */   nop
    /* 16FCF8 0026FCF8 2000A427 */  addiu      $4, $29, 0x20
    /* 16FCFC 0026FCFC 2D280002 */  daddu      $5, $16, $0
    /* 16FD00 0026FD00 30CF090C */  jal        func_00273cc0
    /* 16FD04 0026FD04 00000000 */   nop
    /* 16FD08 0026FD08 83FF0224 */  addiu      $2, $0, -0x7D
    /* 16FD0C 0026FD0C 2000A2A3 */  sb         $2, 0x20($29)
    /* 16FD10 0026FD10 F6FF0224 */  addiu      $2, $0, -0xA
    /* 16FD14 0026FD14 2100A2A3 */  sb         $2, 0x21($29)
    /* 16FD18 0026FD18 2200A0A3 */  sb         $0, 0x22($29)
    /* 16FD1C 0026FD1C 2D200002 */  daddu      $4, $16, $0
    /* 16FD20 0026FD20 DCCF090C */  jal        func_00273f70
    /* 16FD24 0026FD24 00000000 */   nop
    /* 16FD28 0026FD28 2000A427 */  addiu      $4, $29, 0x20
    /* 16FD2C 0026FD2C 2D280002 */  daddu      $5, $16, $0
    /* 16FD30 0026FD30 30CF090C */  jal        func_00273cc0
    /* 16FD34 0026FD34 00000000 */   nop
    /* 16FD38 0026FD38 01000424 */  addiu      $4, $0, 0x1
    /* 16FD3C 0026FD3C 9835040C */  jal        func_0010d660
    /* 16FD40 0026FD40 00000000 */   nop
    /* 16FD44 0026FD44 2000A427 */  addiu      $4, $29, 0x20
    /* 16FD48 0026FD48 34A78527 */  addiu      $5, $28, -0x58CC
    /* 16FD4C 0026FD4C 2D304000 */  daddu      $6, $2, $0
    /* 16FD50 0026FD50 2208110C */  jal        func_00442088
    /* 16FD54 0026FD54 00000000 */   nop
    /* 16FD58 0026FD58 2D200002 */  daddu      $4, $16, $0
    /* 16FD5C 0026FD5C DCCF090C */  jal        func_00273f70
    /* 16FD60 0026FD60 00000000 */   nop
    /* 16FD64 0026FD64 2000A427 */  addiu      $4, $29, 0x20
    /* 16FD68 0026FD68 2D280002 */  daddu      $5, $16, $0
    /* 16FD6C 0026FD6C 30CF090C */  jal        func_00273cc0
    /* 16FD70 0026FD70 00000000 */   nop
    /* 16FD74 0026FD74 2D100000 */  daddu      $2, $0, $0
  .L0026FD78:
    /* 16FD78 0026FD78 1000BFDF */  ld         $31, 0x10($29)
    /* 16FD7C 0026FD7C 0000B07B */  lq         $16, 0x0($29)
    /* 16FD80 0026FD80 5000BD27 */  addiu      $29, $29, 0x50
    /* 16FD84 0026FD84 0800E003 */  jr         $31
    /* 16FD88 0026FD88 00000000 */   nop
    /* 16FD8C 0026FD8C 00000000 */  nop
.size func_0026fca0, 0xf0
