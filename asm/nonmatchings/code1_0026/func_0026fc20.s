.section .text
.set noat
.set noreorder
glabel func_0026fc20
    /* 16FC20 0026FC20 C0FFBD27 */  addiu      $29, $29, -0x40
    /* 16FC24 0026FC24 1000BFFF */  sd         $31, 0x10($29)
    /* 16FC28 0026FC28 0000B07F */  sq         $16, 0x0($29)
    /* 16FC2C 0026FC2C 2D80A000 */  daddu      $16, $5, $0
    /* 16FC30 0026FC30 A8D1090C */  jal        func_002746a0
    /* 16FC34 0026FC34 00000000 */   nop
    /* 16FC38 0026FC38 04004010 */  beqz       $2, .L0026FC4C
    /* 16FC3C 0026FC3C 00000000 */   nop
    /* 16FC40 0026FC40 2D100000 */  daddu      $2, $0, $0
    /* 16FC44 0026FC44 11000010 */  b          .L0026FC8C
    /* 16FC48 0026FC48 00000000 */   nop
  .L0026FC4C:
    /* 16FC4C 0026FC4C 01000424 */  addiu      $4, $0, 0x1
    /* 16FC50 0026FC50 B435040C */  jal        func_0010d6d0
    /* 16FC54 0026FC54 00000000 */   nop
    /* 16FC58 0026FC58 2000A427 */  addiu      $4, $29, 0x20
    /* 16FC5C 0026FC5C 34A78527 */  addiu      $5, $28, -0x58CC
    /* 16FC60 0026FC60 2D304000 */  daddu      $6, $2, $0
    /* 16FC64 0026FC64 2208110C */  jal        func_00442088
    /* 16FC68 0026FC68 00000000 */   nop
    /* 16FC6C 0026FC6C 2D200002 */  daddu      $4, $16, $0
    /* 16FC70 0026FC70 DCCF090C */  jal        func_00273f70
    /* 16FC74 0026FC74 00000000 */   nop
    /* 16FC78 0026FC78 2000A427 */  addiu      $4, $29, 0x20
    /* 16FC7C 0026FC7C 2D280002 */  daddu      $5, $16, $0
    /* 16FC80 0026FC80 30CF090C */  jal        func_00273cc0
    /* 16FC84 0026FC84 00000000 */   nop
    /* 16FC88 0026FC88 2D100000 */  daddu      $2, $0, $0
  .L0026FC8C:
    /* 16FC8C 0026FC8C 1000BFDF */  ld         $31, 0x10($29)
    /* 16FC90 0026FC90 0000B07B */  lq         $16, 0x0($29)
    /* 16FC94 0026FC94 4000BD27 */  addiu      $29, $29, 0x40
    /* 16FC98 0026FC98 0800E003 */  jr         $31
    /* 16FC9C 0026FC9C 00000000 */   nop
.size func_0026fc20, 0x80
